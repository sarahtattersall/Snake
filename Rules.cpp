#include "Rules.hpp"
#include "SnakeException.hpp"
#include "CellOccupier.hpp"
#include <iostream>
#include <string.h>
#include <stdio.h>

Rules::Rules(shared_ptr<Board> board, bool through_walls){
    m_board = board;
    m_prev_snake_size = 0;
    m_wall = new WallOccupier();
    m_teleport = new TeleportOccupier();
    m_food = new FoodOccupier();
    m_through_walls = through_walls;
    srand(time(NULL));
}

Rules::~Rules(){
    delete m_wall;
    delete m_food;
    delete m_teleport;
}

shared_ptr<Board> Rules::get_board(){
    return m_board;
}

int Rules::snake_count(){
    return m_snakes.size();
}

const Snake* Rules::get_snake(int index){
    const Snake* snake = &m_snakes[index];
    return snake;
}

void Rules::place_food(){
    int x = rand() % m_board->get_width();
    int y = rand() % m_board->get_height();
    if (m_board->lookup(Coord(x,y))->get_type() == CellOccupier::EMPTY){
        m_board->insert(m_food, Coord(x,y));
    } else {
        place_food();
    }
}

bool Rules::coord_out_of_bounds(Coord coord){
    return (m_board->lookup(coord)->get_type() == CellOccupier::WALL);
}

bool Rules::move_snake(int index, Coord::Direction direction){
    Snake& snake = m_snakes[index];
    if (Coord::inverse(direction) == snake.get_direction()){
        return compute_move(snake, snake.get_direction());
    }
    return compute_move(snake, direction);
}

bool Rules::move_snake(int index){
    Snake& snake = m_snakes[index];
    return compute_move(snake, snake.get_direction());
}

bool Rules::snake_dead(){
    for (ptr_vector<Snake>::iterator itr = m_snakes.begin(); itr != m_snakes.end(); ++itr){
        if (!(*itr).is_alive()){
            return true;
        }
    }
    return false;
}

bool Rules::compute_move(Snake& snake, Coord::Direction direction){
    Coord old_front = m_board->find(&snake);
    Coord new_front = old_front.move(direction);
    snake.set_direction(direction); // Need to set this here so grow moves snake in right direction
    return m_board->lookup(new_front)->handle_move(new_front, direction, m_board, &snake, this);
}

void Rules::build_wall(){
    CellOccupier* wall;
    if (m_through_walls){
        wall = m_teleport;
    } else{
        wall = m_wall;
    }
    int width = m_board->get_width();
    int height = m_board->get_height();
    for (int x = 0; x < width; ++x){
        m_board->insert(wall, Coord(x, 0));
        m_board->insert(wall, Coord(x, height-1));
    }
    for (int y = 0; y < height; ++y){
        m_board->insert(wall, Coord(0, y));
        m_board->insert(wall, Coord(width-1, y));
    }
}

void Rules::set_snakes(int players){
    set_snakes(players, m_prev_snake_size);
}
void Rules::set_snakes(int players, int snake_size){
    m_prev_snake_size = snake_size;
    Coord board_middle(m_board->get_width()/2, m_board->get_height()/2);
    for (int player = 0; player < players; ++player){
        Coord snake_start(board_middle.get_x() - player, board_middle.get_y());
        Snake* snake = new Snake(snake_size, Coord::DOWN);
        m_snakes.push_back(snake);
        m_board->insert(snake, snake_start);
        snake->build_tail(m_board);
    }
}

void Rules::reset(){
    m_board->clear();
    build_wall();
    int players = m_snakes.size();
    m_snakes.clear();
    set_snakes(players);
    place_food();
}

CellOccupier* Rules::get_food(){
    return m_food;
}

vector<CellOccupier*> Rules::get_walls(){
    vector<CellOccupier*> walls;
    walls.push_back(m_wall);
    if (m_through_walls){
        walls.push_back(m_teleport);
    }
    return walls;
}


RuleBuilder::RuleBuilder(){
    m_through_walls = false;
    m_player_count = 0;
    m_snake_size = 0;
}

RuleBuilder& RuleBuilder::set_board(shared_ptr<Board> board){
    m_board = board;
    return *this;
}

RuleBuilder& RuleBuilder::set_snake_size(int size){
    m_snake_size = size;
    return *this;
}

RuleBuilder& RuleBuilder::set_player_count(int count){
    m_player_count = count;
    return *this;
}

RuleBuilder& RuleBuilder::set_through_walls(bool through_walls){
    m_through_walls = through_walls;
    return *this;
}

shared_ptr<Rules> RuleBuilder::create(){
    BoardBuilder board_builder;
    if (m_board.get() == NULL || m_player_count == 0){
        throw RuleBuilderException();
    }
    //DEFAULT
    if (m_snake_size == 0){
        m_snake_size = 3;
    }
    //Subtract two for board perimiter
    if (m_snake_size >= (m_board->get_width()/2 - 2)){
        throw SnakeTooBigException();
    }
    // Hand in initialiser object that can build wall and snakes.
    shared_ptr<Rules> rules = shared_ptr<Rules> (new Rules(m_board, m_through_walls));
    rules->build_wall();
    rules->set_snakes(m_player_count, m_snake_size);
    rules->place_food();
    return rules;
}

int Rules::get_player_count(){
    return m_snakes.size();
}