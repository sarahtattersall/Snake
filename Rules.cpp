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

RuleBuilder& RuleBuilder::set_board_size(int size){
	m_board_size = size;
	return *this;
}

RuleBuilder& RuleBuilder::set_player_count(int count){
	m_player_count = count;
	return *this;
}

Rules* RuleBuilder::create(){
	BoardBuilder board_builder;
    board_builder.set_size(m_board_size);
	vector<Snake> snakes;
	for( int i = 0; i < m_player_count; ++i){
		snakes.push_back(Snake());
	}
	return new Rules(board_builder.create(), snakes);
}