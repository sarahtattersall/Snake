#ifndef TEXTUAL_BOARD_VISUALISER_HPP
#define TEXTUAL_BOARD_VISUALISER_HPP
#include "CellOccupier.hpp"
#include <boost/shared_ptr.hpp>
#include <string>
class Board;
using std::string;
using boost::shared_ptr;

class TextualBoardVisualiser {
public:
    TextualBoardVisualiser(shared_ptr<Board> board);
    // Displays a textual representation of the board
    void display();
private:
    // Returns a string displaying a textual representation
    // of the cell occupiers type.
    string textual_display(CellOccupier::TYPE type);
    shared_ptr<Board> m_board;
};

class TextualBoardVisualiserBuilder {
public:
    TextualBoardVisualiserBuilder() : m_board(){};
    TextualBoardVisualiserBuilder& set_board(shared_ptr<Board> board);
    virtual shared_ptr<TextualBoardVisualiser> create();
protected:
    shared_ptr<Board> m_board;
};

#endif
