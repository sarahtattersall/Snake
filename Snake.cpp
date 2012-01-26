#include "Snake.hpp"
Snake::Snake(int size, Coord::Direction d) : CellOccupier(){
    m_size = size;
    m_direction = d;
}

Snake::~Snake(){
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

Coord::Direction Snake::get_direction(){
    return m_direction;    
}
void Snake::set_direction(Coord::Direction d){
    m_direction = d;
}
void Snake::build_tail(shared_ptr<Board> board){
    if( m_size > 1 ){
        Coord coord = board->find(this);
        Coord::Direction direction = Coord::inverse(m_direction);
        coord = coord.move(direction);
        SnakeTail* tail = new SnakeTail();
        board->insert(tail, coord);
        m_tail = tail;
        SnakeTail* next;
        for(int i = 0; i < m_size - 2; ++i){
            coord = coord.move(direction);
            next = new SnakeTail();
            board->insert(next, coord);
            tail->m_next = next;
            tail = next;
        }
        // TODO: Fix cast
        tail->m_next = (SnakeTail*) this;
    }
}

SnakeTail* Snake::find_tail(){
    if( m_tail != NULL ){
        // Is this dangerous? Don't want to be able to alter it? Make it const?
        //return find_prev(this);
    } else{
        // Not sure about this.
        return m_tail;        
    }
    return NULL;
}

int Snake::get_size(){
    return m_size;    
}

// TODO: TEST THIS LOGIC
void Snake::move_tail(){
    SnakeTail* tail = find_tail();
    SnakeTail* new_tail = find_prev(tail);
    new_tail->m_next = tail->m_next;
    tail->m_next = m_tail;
    m_tail = tail;
}

SnakeTail* Snake::find_prev(SnakeTail* tail){
    SnakeTail* next = m_tail;
    while(next->m_next != tail ){
        next = next->m_next;
    }
    return next;
}
