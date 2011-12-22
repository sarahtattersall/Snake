#include "BoardVisuliser.hpp"

BoardVisuliser::BoardVisuliser(Board* board){
	m_board = board;
}

void BoardVisuliser::display(){
	// Not assuming it's a square
	for( int i = 0; i < m_board->get_height(); ++i){
		for( int j = 0; j < m_board->get_width(); ++j){
			Cell current = m_board->get(i, j);
		}
	}
}