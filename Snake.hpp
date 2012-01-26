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
    friend class Snake;
	SnakeTail() : CellOccupier() {};
  	virtual TYPE get_type() { return SNAKE; }
    SnakeTail* get_next(){
        return m_next;
    }
private:
    SnakeTail* m_next;
};


//TODO: Move into CPP
//TODO: Made Snake a SnakeTail for quick fix to make linked list circular. Fix.
class Snake : public SnakeTail{
public:
	Snake(int size, Coord::Direction d) : SnakeTail(){
        m_size = size;
        m_direction = d;
    }
    
    ~Snake(){
        if( m_tail != NULL ){
            /*(SnakeTail* front = m_tail;
            SnakeTail* next_tail = m_tail->get_next();
            front->m_next = NULL; // Break the loop.
            while( next_tail != NULL ){
                SnakeTail* current = next_tail;
                next_tail = current->get_next();
                delete current;
            }*/
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

    SnakeTail* find_tail(){
        if( m_tail != NULL ){
            // Is this dangerous? Don't want to be able to alter it? Make it const?
            find_prev(this);
        } else{
            // Not sure about this.
            return m_tail;        
        }
        return NULL;
    }

    int get_size(){
        return m_size;    
    }

    // TODO: TEST THIS LOGIC
    void move_tail(){
        SnakeTail* tail = find_tail();
        SnakeTail* new_tail = find_prev(tail);
        new_tail->m_next = tail->m_next;
        tail->m_next = m_tail;
        m_tail = tail;
    }

private:
    int m_size;
    Coord::Direction m_direction;
    SnakeTail* m_tail;
    // Would it have been better to be doubly linked?
    // Although I know Ian said not...?!?
    SnakeTail* find_prev(SnakeTail* tail){
        SnakeTail* next = m_tail;
        while(next->m_next != tail ){
            next = next->m_next;
        }
        return next;
    }
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
