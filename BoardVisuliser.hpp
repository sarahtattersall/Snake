#ifndef BOARD_VISULISER_HPP
#define BOARD_VISULISER_HPP
#include "Board.hpp"
#include "CellOccupier.hpp"
#include <string>
using std::string;

class BoardVisuliser{
public:
	BoardVisuliser(Board* board);
	// Displays a textual representation of the board
	void display();
private:
	Board* m_board;
	// Returns a string displaying a textual representation
	// of the cell occupiers type.
	string textual_display(CellOccupier::TYPE type);
};

// class BoardVisuliserBuilder(){
// public:
//     BoardVisuliserBuilder();
//     BoardVisuliserBuilder& set_board(Board* board);
//     BoardVisuliser* create();
// private:
// 	Board* m_board;
// }

#endif