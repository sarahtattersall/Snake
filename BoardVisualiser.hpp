#ifndef BOARD_VISUALISER_HPP
#define BOARD_VISUALISER_HPP
#include "Board.hpp"

class BoardVisualiser{
public:
	BoardVisualiser(Board* board);
	// Displays a textual representation of the board
	virtual void display() = 0;
protected:
	Board* m_board;
};

// class BoardVisualiserBuilder(){
// public:
//     BoardVisualiserBuilder();
//     BoardVisualiserBuilder& set_board(Board* board);
//     BoardVisualiser* create();
// private:
// 	Board* m_board;
// }

#endif