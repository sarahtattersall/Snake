#include "Rules.hpp"
#include "SnakeException.hpp"
#include <string.h>
#include <iostream>
using namespace std;
Rules::Rules(shared_ptr<Board> board, vector<Snake> snakes, shared_ptr<BoardVisualiser> visualiser){
	m_board = board;
	m_snakes = snakes;
	m_visualiser = visualiser;
	// Initialised board with snakes
	for(vector<Snake>::iterator itr = m_snakes.begin(); itr != m_snakes.end(); ++itr){
		update_board(*itr);
	}
}

Rules::~Rules(){
	// delete m_board;
}

shared_ptr<Board> Rules::get_board(){
	return m_board;
}

void Rules::update_board(Snake snake){
	// vector<shared_ptr<SnakeOccupier> > occupiers = snake.get_occupiers();
	// for( vector<shared_ptr<SnakeOccupier> >::iterator itr = occupiers.begin(); itr != occupiers.end(); ++itr ){
	// 	m_board->insert(*itr, (*itr)->get_coord());
	// }
}

void Rules::play(){
	m_visualiser->display();
}

RuleBuilder::RuleBuilder() : m_visualiser_builder(){
	// m_visualiser_builder = NULL;
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
	if (m_snake_size >= (m_board_size/2)){
		throw SnakeTooBigException();
	}
	vector<Snake> snakes;
	Coord board_middle(m_board->get_width()/2, m_board->get_height()/2);
	for( int i = 0; i < m_player_count; ++i){
		Coord snake_start(board_middle.get_x() - i, board_middle.get_y());
		if( m_snake_size != 0){
			snakes.push_back(Snake(m_snake_size));
		}else{
			snakes.push_back(Snake());
		}
		int x = snake_start.get_x();
		int y = snake_start.get_y();
		for( int i = 0; i < snakes.back().get_size(); ++i){
			m_board->insert(shared_ptr<SnakeOccupier> (new SnakeOccupier()), Coord(x, y - i));
		}
	}
	return shared_ptr<Rules> (new Rules(m_board, snakes));
}
