#ifndef CELL_OCCUPIER_HPP
#define CELL_OCCUPIER_HPP
#include "Coord.hpp"
#include "SnakeDirection.hpp"
//#include "Board.hpp"
#include <boost/shared_ptr.hpp>
using boost::shared_ptr;
class Board;
class Snake;
class Rules;

// TODO: Change this to implement dynamic cast.
class CellOccupier{
public:
    enum TYPE {EMPTY, SNAKE, FOOD, WALL};
    virtual TYPE get_type() const = 0;
    virtual bool handle_move(Coord coord, Vector::Direction direction, CoordinateSpace space, shared_ptr<Board> board, Snake* snake, Rules* rules) const = 0;
protected:
    void move_snake(Coord front, shared_ptr<Board> board, Snake* snake) const;
};

class EmptyOccupier : public CellOccupier{
public:
    virtual TYPE get_type() const { return EMPTY; }
    virtual bool handle_move(Coord coord, Vector::Direction, CoordinateSpace, shared_ptr<Board> board, Snake* snake, Rules*) const{
        move_snake(coord, board, snake);
        return true;
    }
};

class FoodOccupier : public CellOccupier{
public:
    virtual TYPE get_type() const { return FOOD; }
    virtual bool handle_move(Coord coord, Vector::Direction direction, CoordinateSpace, shared_ptr<Board> board, Snake* snake, Rules* rules) const;
};

class WallOccupier : public CellOccupier{
public:
    virtual TYPE get_type() const { return WALL; }
    virtual bool handle_move(Coord, Vector::Direction, CoordinateSpace, shared_ptr<Board>, Snake* snake, Rules*) const;
};

class TeleportOccupier : public CellOccupier{
public:
    virtual TYPE get_type() const { return WALL; }
    virtual bool handle_move(Coord coord, Vector::Direction direction, CoordinateSpace space, shared_ptr<Board> board, Snake* snake, Rules* rules) const;
};

class IterableSnake{
    friend class SnakeIterator;
    virtual const IterableSnake* next() const = 0;
    virtual const CellOccupier* get_cell_occupier() const = 0;
};

class SnakeTail : public CellOccupier, public IterableSnake {
public:
    friend class Snake;
    SnakeTail() : CellOccupier() {};
    virtual TYPE get_type() const { return SNAKE; }
    SnakeTail* get_next(){
        return m_next;
    }
    virtual bool handle_move(Coord, Vector::Direction, CoordinateSpace space, shared_ptr<Board>, Snake* snake, Rules*) const;
    
private:
    SnakeTail* m_next;
    virtual const IterableSnake* next() const{
        return m_next;
    }
    virtual const CellOccupier* get_cell_occupier() const{
        return this;
    }
};


class SnakeIterator{
public:
    SnakeIterator(const IterableSnake* current, IterableSnake* last){
        m_current = current;
        m_last = last;
    }
    
    ~SnakeIterator(){};
    
    SnakeIterator& operator++(){
        m_last = m_current;
        m_current = m_current->next();
        return *this;
    }
    void operator++(int){
        operator++();
    }
    
    bool operator==(SnakeIterator iter){
        return (m_current == iter.m_current && m_last == iter.m_last);
    }
    
    bool operator!=(SnakeIterator iter){
        return !(operator==(iter));
    }
    
    const CellOccupier * operator*(){
        return m_current->get_cell_occupier();
    }
    
private:
    const IterableSnake* m_current;
    const IterableSnake* m_last;
};

class Snake : public CellOccupier, public IterableSnake {
public:
    enum Speed { FAST = 1, MEDIUM, SLOW };
    Snake(int size, Vector::Direction d);
    ~Snake();
    virtual TYPE get_type() const { return SNAKE; }
    virtual bool handle_move(Coord, Vector::Direction, CoordinateSpace space, shared_ptr<Board>, Snake* snake, Rules*) const;
    Vector::Direction get_direction() const;
    void set_direction(Vector::Direction d);
    void build_tail(shared_ptr<Board> board, CoordinateSpace space);

    SnakeTail* find_tail() const;
    int get_size() const;
    int get_speed() const;
    void move_tail();
    void grow(shared_ptr<Board> board, Coord new_front);
    void set_alive(bool alive);
    bool is_alive() const;
    
    //Iterator methods:
    SnakeIterator begin() const;
    SnakeIterator end() const;
    
private:
    int m_size;
    bool m_alive;
    Speed m_speed;
    Vector::Direction m_direction;
    SnakeTail* m_next;
    SnakeTail* find_prev(SnakeTail* tail) const;
    virtual const IterableSnake * next() const;
    virtual const CellOccupier * get_cell_occupier() const;
};
#endif
