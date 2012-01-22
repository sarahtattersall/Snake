#include "BoardVisualiser.hpp"
#include <string.h>
using namespace std;

BoardVisualiser::BoardVisualiser(shared_ptr<Board> board){
	m_board = board;
}

BoardVisualiserBuilder::BoardVisualiserBuilder() : m_board(){
	// m_board = NULL;
}

BoardVisualiserBuilder& BoardVisualiserBuilder::set_board(shared_ptr<Board> board){
	m_board = board;
	return *this;
}