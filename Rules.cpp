#include "Rules.hpp"
#include "SnakeException.hpp"
#include "EmptyOccupier.hpp"
#include "WallOccupier.hpp"
#include "Snake.hpp"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Rules::Rules(shared_ptr<Board> board, vector<Snake*> snakes, WallOccupier* wall){
    m_board = board;
    m_snake_start_size = snakes[0]->get_size();
    for(vector<Snake*>::iterator itr = snakes.begin(); itr != snakes.end(); ++itr){
        m_snakes.push_back(*itr);
    }
    m_wall = wall;
    m_food = new FoodOccupier();
    srand(time(NULL));
    place_food();
}

Rules::~Rules(){
    delete m_wall;
}

shared_ptr<Board> Rules::get_board(){
    return m_board;
}

int Rules::snake_count(){
    return m_snakes.size();
}

const Snake& Rules::get_snake(int index){
    const Snake& snake = m_snakes[index];
    return snake;
}

void Rules::place_food(){
    int x = rand() % m_board->get_width();
    int y = rand() % m_board->get_height();
    if( m_board->lookup(Coord(x,y))->get_type() == CellOccupier::EMPTY ){
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
    return compute_move(snake, direction);
}

bool Rules::move_snake(int index){
    Snake& snake = m_snakes[index];
    return compute_move(snake, snake.get_direction());
}

bool Rules::snake_dead(){
    for(ptr_vector<Snake>::iterator itr = m_snakes.begin(); itr != m_snakes.end(); ++itr){
        if(!(*itr).is_alive()){
            return true;
        }
    }
    return false;
}

bool Rules::compute_move(Snake& snake, Coord::Direction direction){
    Coord old_front = m_board->find(&snake);
    Coord new_front = old_front.move(direction);
    bool set_food = false;
    snake.set_direction(direction); // Need to set this here so grow moves snake in right direction

    if (coord_out_of_bounds(new_front)){
        snake.set_alive(false);
        return false;
    }
    // Is it better to just do one lookup?
    if (m_board->lookup(new_front)->get_type() == CellOccupier::SNAKE){
        snake.set_alive(false);
        return false;
    } else if (m_board->lookup(new_front)->get_type() == CellOccupier::FOOD){
        m_board->remove(m_food);
        //Should grow move the head? Current it does.
        snake.grow(m_board);
        set_food = true;
        place_food();
    } else {
        m_board->move(&snake, new_front);
        if(snake.get_size() > 1){
            SnakeTail* tail = snake.find_tail();
            m_board->move(tail, old_front);
            // Not entirely sure if this should be in snake?
            snake.move_tail();         
        }
    }

    return true;
}


RuleBuilder::RuleBuilder(){
    m_player_count = 0;
    m_snake_size = 0;
    m_wall = new WallOccupier();
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

void RuleBuilder::set_perimiter(){
    int width = m_board->get_width();
    int height = m_board->get_height();
    for( int x = 0; x < width; ++x ){
        m_board->insert(m_wall, Coord(x, 0));
        m_board->insert(m_wall, Coord(x, height-1));
    }
    for( int y = 0; y < height; ++y ){
        m_board->insert(m_wall, Coord(0, y));
        m_board->insert(m_wall, Coord(width-1, y));
    }
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

// Build rules with board and then 
    set_perimiter();

    // Has to be vector else ptr_vector is deleted when copied to Rules
    vector<Snake*> snakes;
    Coord board_middle(m_board->get_width()/2, m_board->get_height()/2);
    for( int player = 0; player < m_player_count; ++player){
        Coord snake_start(board_middle.get_x() - player, board_middle.get_y());
        Snake* snake = new Snake(m_snake_size, Coord::DOWN);
        snakes.push_back(snake);
        m_board->insert(snake, snake_start);
        snake->build_tail(m_board);
    }
    // Hand in initialiser object that can build wall and snakes.
    return shared_ptr<Rules> (new Rules(m_board, snakes, m_wall));
}
