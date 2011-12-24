#ifndef BOARD_VISUALISER_HPP
#define BOARD_VISUALISER_HPP
#include <Boost/shared_ptr.hpp>
#include "Board.hpp"
using boost::shared_ptr;

//IAN: No need to include Board.hpp, you only use a pointer to Board in here,
// so a forward declaration of the type will suffice.
// class Board;

//IAN: Why do you think you need this interface?
// Is there a time where you are going to want to refer to a visualiser
// without knowing it's full type?
class BoardVisualiser{
public:
	BoardVisualiser(shared_ptr<Board> board);
	// Displays a textual representation of the board
	virtual void display() = 0;
protected:
	shared_ptr<Board> m_board;
};

// Need a builder because you want to set the board after you've declared you're
// using a visualiser
class BoardVisualiserBuilder{
public:
    BoardVisualiserBuilder();
    BoardVisualiserBuilder& set_board(shared_ptr<Board> board);
    virtual BoardVisualiser* create() = 0;
protected:
	shared_ptr<Board> m_board;
};

#endif
