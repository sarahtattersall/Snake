#include "Rules.hpp"
using namespace std;
Rules::Rules(Board* board, vector<Snake> snakes){
	m_board = board;
	m_snakes = snakes;
}

Rules::~Rules(){
	delete m_board;
}

Board* Rules::get_board(){
	return m_board;
}

void Rules::update_board(Snake snake){
	vector<SnakeOccupier*> occupiers = snake.get_occupiers();
	for( vector<SnakeOccupier*>::iterator itr = occupiers.begin(); itr != occupiers.end(); ++itr ){
		m_board->insert(*itr, (*itr)->get_coord());
	}
}


RuleBuilder& RuleBuilder::set_board_size(int size){
	m_board_size = size;
	return *this;
}

RuleBuilder& RuleBuilder::set_snake_size(int size){
	if (size >= m_board_size){
		// proper error later.
		throw -1;
	}
	m_snake_size = size;
	return *this;
}

RuleBuilder& RuleBuilder::set_player_count(int count){
	m_player_count = count;
	return *this;
}

Rules* RuleBuilder::create(){
	BoardBuilder board_builder;
	board_builder.set_size(m_board_size);
	Board* board = board_builder.create();
	vector<Snake> snakes;
	// SARAH: Could have just used m_board_size instead?
	Coord board_middle = Coord(board->get_width()/2, board->get_height()/2);
	for( int i = 0; i < m_player_count; ++i){
		if( m_snake_size != 0){
			snakes.push_back(Snake(board_middle, m_snake_size));
		}else{
			snakes.push_back(Snake(board_middle));
		}
	}
	return new Rules(board, snakes);
}