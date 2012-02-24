#ifndef CELL_OCCUPIER_HPP
#define CELL_OCCUPIER_HPP
#include "Coord.hpp"
#include "SnakeDirection.hpp"
//#include "Board.hpp"
#include <boost/shared_ptr.hpp>
using boost::shared_ptr;
class Board;

//IAN: There are so many ways to implement this, but none of them are really
// all that good.
// I have changed this to a slightly nicer way to use the enum approach.
// It's better because you are trusting the vtable of the object, rather than a
// field that you can change. There are times when the other approach is better,
// notably if you have expensive to construct items that want to change their
// type dynamically.
// You can actually not use the enum and rely on dynamic_cast to get what you
// want.
class CellOccupier{
public:
    enum TYPE {EMPTY, SNAKE, FOOD, WALL};
    virtual TYPE get_type() const = 0;
};

class EmptyOccupier : public CellOccupier{
public:
    virtual TYPE get_type() const { return EMPTY; }
};

class FoodOccupier : public CellOccupier{
public:
    virtual TYPE get_type() const { return FOOD; }
};

class WallOccupier : public CellOccupier{
public:
    virtual TYPE get_type() const { return WALL; }
};

class IterableSnake{
    //CellOccupier * get_occupier();
    friend class SnakeIterator;
    virtual IterableSnake * next() = 0;
    virtual CellOccupier * get_cell_occupier() = 0;
};

class SnakeTail : public CellOccupier, public IterableSnake {
public:
    friend class Snake;
    SnakeTail() : CellOccupier() {};
    virtual TYPE get_type() const { return SNAKE; }
    SnakeTail* get_next(){
        return m_next;
    }
    
private:
    SnakeTail* m_next;
    virtual IterableSnake * next(){
        return m_next;
    }
    virtual CellOccupier * get_cell_occupier(){
        return this;
    }
};


//TODO: ARGGGHHH Cant make this work for both Snake head and snake tail? :(
class SnakeIterator{
public:
    SnakeIterator(IterableSnake* current){
        m_current = current;
    }
    
    ~SnakeIterator(){};
    
    SnakeIterator& operator++(){
        m_current = m_current->next();
        return *this;
    }
    void operator++(int){
        operator++();
    }
    
    bool operator==(SnakeIterator iter){
        return (m_current == iter.m_current);
    }
    
    bool operator!=(SnakeIterator iter){
        return !(operator==(iter));
    }
    
    CellOccupier * operator*(){
        return m_current->get_cell_occupier();
    }
    
private:
    IterableSnake* m_current;
    IterableSnake* m_tail;
};

class Snake : public CellOccupier, public IterableSnake {
public:
    enum Speed { FAST = 1, MEDIUM, SLOW };
    Snake(int size, Coord::Direction d);
    ~Snake();
    virtual TYPE get_type() const { return SNAKE; }
    
    Coord::Direction get_direction();
    void set_direction(Coord::Direction d);
    void build_tail(shared_ptr<Board> board);

    SnakeTail* find_tail() const;
    int get_size() const;
    int get_speed() const;
    void move_tail();
    void grow(shared_ptr<Board> board, Coord new_front);
    void set_alive(bool alive);
    bool is_alive();
    
    //Iterator methods:
    SnakeIterator begin() const;
    SnakeIterator end() const;

private:
    int m_size;
    bool m_alive;
    Speed m_speed;
    Coord::Direction m_direction;
    SnakeTail* m_next;
    SnakeTail* find_prev(SnakeTail* tail) const;
    virtual IterableSnake * next();
    virtual CellOccupier * get_cell_occupier();
};
#endif
