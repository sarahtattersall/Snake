#include "TextualBoardVisualiser.hpp"
#include "Board.hpp"
#include <iostream>
using namespace std;

TextualBoardVisualiser::TextualBoardVisualiser(Board* board) {
	m_board = board;
}

// Not sure yet of a better way to do this...is a bit ugly
// Could grow into some massive if, but if move into
// Cells then it's taking the visulisation out of this class?
//IAN: For now I would leave this and move on, it's enough to get you started.
// when it comes time to fix this, you might want to look into MVC and friends
// (Model View Controller).
string TextualBoardVisualiser::textual_display(CellOccupier::TYPE type){
	if( type == CellOccupier::EMPTY){
		return string(" ");
	} else if (type == CellOccupier::SNAKE){
		return string("S");
	} else if (type == CellOccupier::FOOD){
		return string("F");
	}
	// else Error
}

void TextualBoardVisualiser::display(){
	// Not assuming it's a square
	for( int i = 0; i < m_board->get_height(); ++i){
		for( int j = 0; j < m_board->get_width(); ++j){
			Cell current = m_board->get(i, j);
			CellOccupier* occupier = current.get_occupier();
			CellOccupier::TYPE type = occupier->get_type();
			cout << textual_display(type) << ", ";
		}
		cout << endl;
	}
}
