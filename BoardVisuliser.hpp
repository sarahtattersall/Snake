#ifndef BOARD_VISULISER_HPP
#define BOARD_VISULISER_HPP
#include "Board.hpp"

class BoardVisuliser{
public:
	BoardVisuliser(Board* board);
	void display();
private:
	Board* m_board;
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