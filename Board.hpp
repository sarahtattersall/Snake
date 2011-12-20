#ifndef BOARD_BUILDER_HPP
#define BOARD_BUILDER_HPP

class Board{
public:
    Board(const int size);
private:
    int m_size;
    
};

class BoardBuilder {
public:
    BoardBuilder();
    BoardBuilder& set_size(const int size);
    // if haven't set size create should refuse.
    Board* create();
private:
    int m_size;
};


#endif