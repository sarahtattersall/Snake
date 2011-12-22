#ifndef TEXTUAL_BOARD_VISUALISER_HPP
#define TEXTUAL_BOARD_VISUALISER_HPP
#include "BoardVisualiser.hpp"
#include "CellOccupier.hpp"
#include <string>
using std::string;

class TextualBoardVisualiser : public BoardVisualiser {
public:
	TextualBoardVisualiser(Board* board);
	// Displays a textual representation of the board
	void display();
private:
	// Returns a string displaying a textual representation
	// of the cell occupiers type.
	string textual_display(CellOccupier::TYPE type);
};
#endif