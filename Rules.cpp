#include "Rules.hpp"
#include "SnakeException.hpp"
#include "EmptyOccupier.hpp"
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
	bool x_out_of_bounds = coord.get_x() < 0 || coord.get_x() >= m_board->get_width();
	bool y_out_of_bounds = coord.get_y() < 0 || coord.get_y() >= m_board->get_height();
	return (x_out_of_bounds || y_out_of_bounds);
}

// SARAH: should Rules do this or should Board have move method??
// TODO: CHANGE Coord to ENUM UP, DOWN, LEFT, RIGHT.
// TODO: CHANGE THE BOARD TO HAVE WALL OCCUPIERS?!?
bool Rules::move_snake(int index, Direction direction){
	Coord back = m_snakes[index].back();
	// IS THIS THE RIGHT WAY TO DO THIS?
	Coord* direction_coord;
	switch(direction){
		case UP:
			direction_coord = new Coord(0, -1);
			break;
		case DOWN:
			direction_coord = new Coord(0, 1);
			break;
		case LEFT:
			direction_coord = new Coord(-1, 0);
			break;
		case RIGHT:
			direction_coord = new Coord(1, 0);
			break;
	}
	Coord new_front = m_snakes[index].front() + *direction_coord;
	delete direction_coord;
	if (coord_out_of_bounds(new_front)){
		return false;
	}
	if (m_board->get(new_front).get_occupier()->get_type() == CellOccupier::SNAKE){
		return false;
	}
	shared_ptr<CellOccupier> snake_back = m_board->get(back).get_occupier();
	m_board->insert(shared_ptr<CellOccupier> (new SnakeOccupier()), new_front);
	m_board->insert(shared_ptr<CellOccupier> (new EmptyOccupier()), back);
	m_snakes[index].remove_back();
	m_snakes[index].push_front(new_front);
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

shared_ptr<Rules> RuleBuilder::create(){
	BoardBuilder board_builder;
	if (m_board.get() == NULL || m_player_count == 0){
		throw RuleBuilderException();
	}
	if (m_snake_size >= (m_board->get_width()/2)){
		throw SnakeTooBigException();
	}
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
		for( int i = 0; i < snakes.back().get_size(); ++i){
			m_board->insert(shared_ptr<SnakeOccupier> (new SnakeOccupier()), Coord(x, y - i));
			snakes.back().push_back(Coord(x, y - i));
		}
	}
	return shared_ptr<Rules> (new Rules(m_board, snakes));
}
