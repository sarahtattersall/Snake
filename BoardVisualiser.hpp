#ifndef BOARD_VISUALISER_HPP
#define BOARD_VISUALISER_HPP
#include "Board.hpp"
#include "CellOccupier.hpp"
#include <string>
using std::string;

class BoardVisualiser{
public:
	BoardVisualiser(Board* board);
	// Displays a textual representation of the board
	void display();
private:
	Board* m_board;
	// Returns a string displaying a textual representation
	// of the cell occupiers type.
	string textual_display(CellOccupier::TYPE type);
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