#ifndef SNAKE_HPP
#define SNAKE_HPP
#include "Coord.hpp"
#include "CellOccupier.hpp"
#include "SnakeDirection.hpp"
#include <deque>
#include <boost/shared_ptr.hpp>
class Board;
using std::deque;
using boost::shared_ptr;

class SnakeTail : public CellOccupier{
public:
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
	Snake(int size, Coord::Direction d) : CellOccupier(){
        m_size = size;
        m_direction = d;
    }
    
    ~Snake(){
        if( m_tail != NULL ){
            SnakeTail front = m_tail;
            SnakeTail next_tail = m_tail->get_next();
            front->m_next = NULL; // Break the loop.
            while( next_tail != NULL ){
                SnakeTail* current = next_tail;
                SnakeTail* next_tail = current->get_next();
                delete current;
            }
            //delete front; don't need this, will be done by last loop
        }
    }
    
  	virtual TYPE get_type() { return SNAKE; }
    
    Coord::Direction get_direction(){
        return m_direction;    
    }
    void set_direction(Coord::Direction d){
        m_direction = d;
    }
    void build_tail(shared_ptr<Board> board){
    //TODO: Fill in later
    }
private:
    int m_size;
    Coord::Direction m_direction;
    SnakeTail m_tail;
};


// TODO: SNAKE DOESNT NEED TO HOLD COORDINATES JUST MAKE SNAKE OCCUPIERS
// IN BOARD A LINKED LIST, MOVE THE HEAD AND REINSERT TAIL NEXT TO HEAD.
// TRY AND MAKE IT CIRCULAR
/*class Snake{
public:
	Snake(int size = 3);
	int get_size();
	// Adds coord at head of snake
	void push_front(Coord coord);
	// Adds coord at back of snake
	void push_back(Coord coord);
	void remove_back();
	Coord back();
	Coord front();
	
private:
	int m_size;
	deque<Coord> m_coords;
};
*/
#endif
