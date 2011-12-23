#include "BoardVisualiser.hpp"
#include <string.h>
using namespace std;

BoardVisualiser::BoardVisualiser(Board* board){
	m_board = board;
}

BoardVisualiserBuilder::BoardVisualiserBuilder(){
	m_board = NULL;
}

BoardVisualiserBuilder& BoardVisualiserBuilder::set_board(Board* board){
	m_board = board;
}