#ifndef TEXTUAL_BOARD_VISUALISER_HPP
#define TEXTUAL_BOARD_VISUALISER_HPP
#include "CellOccupier.hpp"
#include "BoardVisualiser.hpp"
#include <Boost/shared_ptr.hpp>
#include <string>
class Board;
using std::string;
using boost::shared_ptr;

class TextualBoardVisualiser : public BoardVisualiser {
public:
	TextualBoardVisualiser(shared_ptr<Board> board);
	// Displays a textual representation of the board
	void display();
private:
	// Returns a string displaying a textual representation
	// of the cell occupiers type.
	string textual_display(CellOccupier::TYPE type);
};

class TextualBoardVisualiserBuilder : public BoardVisualiserBuilder {
public:
    shared_ptr<BoardVisualiser> create();
};

#endif