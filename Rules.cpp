#include "Rules.hpp"
#include "SnakeException.hpp"
#include "EmptyOccupier.hpp"
#include "WallOccupier.hpp"
#include "Snake.hpp"
#include <string.h>
#include <iostream>
using namespace std;
Rules::Rules(shared_ptr<Board> board, vector<Snake> snakes){
	m_board = board;
	m_snakes = snakes;
	// Initialised board with snakes
	// for(vector<Snake>::iterator itr = m_snakes.begin(); itr != m_snakes.end(); ++itr){
	// 		update_board(*itr);
	// 	}
}

Rules::~Rules(){
	// delete m_board;
}

shared_ptr<Board> Rules::get_board(){
	return m_board;
}

bool Rules::coord_out_of_bounds(Coord coord){
	//bool x_out_of_bounds = coord.get_x() < 0 || coord.get_x() >= m_board->get_width();
	//bool y_out_of_bounds = coord.get_y() < 0 || coord.get_y() >= m_board->get_height();
	//return (x_out_of_bounds || y_out_of_bounds);
    return (m_board->get(coord).get_occupier()->get_type() == CellOccupier::WALL);
}

// TODO: CHANGE Coord to ENUM UP, DOWN, LEFT, RIGHT.
// TODO: CHANGE THE BOARD TO HAVE WALL OCCUPIERS?!?
bool Rules::move_snake(int index, SnakeDirection::Direction direction){
	//Coord back = m_snakes[index].back();
	Coord direction_coord = SnakeDirection::to_coord(direction);
	Coord new_front = m_board->get_snake_head()->get_coord() + direction_coord;
	if (coord_out_of_bounds(new_front)){
		return false;
	}
	if (m_board->get(new_front).get_occupier()->get_type() == CellOccupier::SNAKE){
		return false;
	}
	//shared_ptr<CellOccupier> snake_back = m_board->get(back).get_occupier();
	//m_board->insert(shared_ptr<CellOccupier> (new SnakeOccupier()), new_front);
	//m_board->insert(shared_ptr<CellOccupier> (new EmptyOccupier()), back);
	//m_snakes[index].remove_back();
	//m_snakes[index].push_front(new_front);
    
    m_board->move_snake(direction);
	return true;
}
// void Rules::update_board(Snake snake){
	// vector<shared_ptr<SnakeOccupier> > occupiers = snake.get_occupiers();
	// for( vector<shared_ptr<SnakeOccupier> >::iterator itr = occupiers.begin(); itr != occupiers.end(); ++itr ){
	// 	m_board->insert(*itr, (*itr)->get_coord());
	// }
//}

RuleBuilder::RuleBuilder(){
	m_player_count = 0;
	m_snake_size = 0;
}

RuleBuilder& RuleBuilder::set_board(shared_ptr<Board> board){
	m_board = board;
	return *this;
}

// Snakes start in the middle of the board and duplicate snakes branch right from this
// Not the best implementation. Decide a better way later.
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
        m_board->insert(shared_ptr<WallOccupier> (new WallOccupier()), Coord(x, 0));
        m_board->insert(shared_ptr<WallOccupier> (new WallOccupier()), Coord(x, height-1));
    }
    for( int y = 0; y < height; ++y ){
        m_board->insert(shared_ptr<WallOccupier> (new WallOccupier()), Coord(0, y));
        m_board->insert(shared_ptr<WallOccupier> (new WallOccupier()), Coord(width-1, y));
    }
}

shared_ptr<Rules> RuleBuilder::create(){
	BoardBuilder board_builder;
	if (m_board.get() == NULL || m_player_count == 0){
		throw RuleBuilderException();
	}
    //Subtract two for board perimiter
	if (m_snake_size >= (m_board->get_width()/2 - 2)){
		throw SnakeTooBigException();
	}
    
    set_perimiter();
    
	vector<Snake> snakes;
	Coord board_middle(m_board->get_width()/2, m_board->get_height()/2);
	for( int player = 0; player < m_player_count; ++player){
		Coord snake_start(board_middle.get_x() - player, board_middle.get_y());
		if( m_snake_size != 0){
			snakes.push_back(Snake(m_snake_size));
		}else{
			snakes.push_back(Snake());
		}
		int x = snake_start.get_x();
		int y = snake_start.get_y();
        m_board->insert(shared_ptr<SnakeHeadOccupier> (new SnakeHeadOccupier(SnakeDirection::DOWN, Coord(x, y))), Coord(x, y));
		for( int i = 1; i < snakes.back().get_size(); ++i){
			m_board->insert(shared_ptr<SnakeOccupier> (new SnakeOccupier()), Coord(x, y - i));
			//snakes.back().push_back(Coord(x, y - i));
		}
	}
	return shared_ptr<Rules> (new Rules(m_board, snakes));
}
