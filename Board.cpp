#include "Board.hpp"
#include "Cell.hpp"

BoardBuilder::BoardBuilder(){
    m_size = 0;
}

BoardBuilder& BoardBuilder::set_size(const int size){
    m_size = size;
    return *this;
}

Board* BoardBuilder::create(){
// Error case needed
    return new Board(m_size);
}

Cell Board::get(int x, int y){
	return m_cells[x][y];
}

int Board::get_height(){
	return m_size;
}

int Board::get_width(){
	return m_size;
}

Board::Board(const int size){
    m_size = size;
    initialize_board();
}


void Board::initialize_board(){
	m_cells.resize(m_size);
    for (int i = 0; i < m_size; ++i){
		m_cells[i].resize(m_size);
        for( int j = 0; j < m_size; ++j){
            m_cells[i][j] = Cell();
        }
    }
}