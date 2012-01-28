#ifndef SNAKE_HPP
#define SNAKE_HPP
#include "Coord.hpp"
#include "CellOccupier.hpp"
#include "SnakeDirection.hpp"
#include "Board.hpp"
#include <deque>
#include <boost/shared_ptr.hpp>
using std::deque;
using boost::shared_ptr;

class SnakeTail : public CellOccupier{
public:
    friend class Snake;
	SnakeTail() : CellOccupier() {};
  	virtual TYPE get_type() { return SNAKE; }
    SnakeTail* get_next(){
        return m_next;
    }
private:
    SnakeTail* m_next;
};

class Snake : public CellOccupier{
public:
	Snake(int size, Coord::Direction d);
    ~Snake();
  	virtual TYPE get_type() { return SNAKE; }
    
    Coord::Direction get_direction();
    void set_direction(Coord::Direction d);
    void build_tail(shared_ptr<Board> board);

    SnakeTail* find_tail();
    int get_size();
    void move_tail();

private:
    int m_size;
    Coord::Direction m_direction;
    SnakeTail* m_tail;
    // Would it have been better to be doubly linked?
    // Although I know Ian said not...?!?
    SnakeTail* find_prev(SnakeTail* tail);
};
#endif
