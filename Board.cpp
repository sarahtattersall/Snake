#include "Board.hpp"

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

Board::Board(const int size){
    m_size = size;
}