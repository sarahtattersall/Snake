#include "Board.hpp"
#include "Cell.hpp"
#include <iostream>
//IAN: This is the only current implementation of Board
class SquareBoard : public Board {
public:
    SquareBoard(const int size);
    virtual Cell& get(Coord coord);
	virtual Cell& get(int x, int y);
    virtual int get_height();
    virtual int get_width();
	void insert(shared_ptr<CellOccupier> occupier, Coord coord);
private:
    int m_size;
    // Initializes the board with empty cells.
    void initialize_board();
    vector<vector<Cell> > m_cells;
};

BoardBuilder::BoardBuilder(){
    m_size = 0;
}

BoardBuilder& BoardBuilder::set_size(const int size){
    m_size = size;
    return *this;
}
shared_ptr<Board> BoardBuilder::create(){
	// Error case needed
    return shared_ptr<Board> (new SquareBoard(m_size));
}

Cell& SquareBoard::get(Coord coord){
	return m_cells[coord.get_y()][coord.get_x()];
}

Cell& SquareBoard::get(int x, int y){
	return m_cells[y][x];
}

int SquareBoard::get_height(){
	return m_size;
}

int SquareBoard::get_width(){
	return m_size;
}

SquareBoard::SquareBoard(const int size){
    m_size = size;
    initialize_board();
}

void SquareBoard::insert(shared_ptr<CellOccupier> occupier, Coord coord){
	m_cells[coord.get_x()][coord.get_y()].set_cell(occupier);
}

void SquareBoard::initialize_board(){
	m_cells.resize(m_size);
    for (int i = 0; i < m_size; ++i){
        for( int j = 0; j < m_size; ++j){
            m_cells[i].push_back(Cell(Coord(i, j)));
        }
    }
}
