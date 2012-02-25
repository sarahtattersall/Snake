#include "CellOccupier.hpp"
#include "Board.hpp"
Snake::Snake(int size, Coord::Direction d) : CellOccupier(){
    m_size = size;
    m_alive = true;
    m_direction = d;
    m_next = NULL;
    m_speed = FAST;
}

Snake::~Snake(){
    if( m_next != NULL ){
        SnakeTail* front = m_next;
        SnakeTail* next_tail = m_next->get_next();
        front->m_next = NULL; // Break the loop.
        while( next_tail != NULL ){
            SnakeTail* current = next_tail;
            next_tail = current->get_next();
            delete current;
        }
    }
}

Coord::Direction Snake::get_direction() const{
    return m_direction;    
}
void Snake::set_direction(Coord::Direction d){
    m_direction = d;
}
void Snake::build_tail(shared_ptr<Board> board){
    if( m_size > 1 ){
        //Is it better to declare it out here rather than in the for?
        Coord front;
        for (int i = 0; i < m_size - 1; ++i){
            front = board->find(this);
            grow(board, front.move(m_direction));
        }
    }
}

SnakeTail* Snake::find_tail() const{
    if( m_next != NULL ){
        return find_prev(m_next);
    }
    return NULL;
}

int Snake::get_size() const{
    return m_size;    
}


void Snake::move_tail(){
    SnakeTail* tail = find_tail();
    m_next = tail;
}

SnakeTail* Snake::find_prev(SnakeTail* tail) const{
    SnakeTail* next = m_next;
    while(next->m_next != tail ){
        next = next->m_next;
    }
    return next;
}

void Snake::grow(shared_ptr<Board> board, Coord new_front){
    Coord old_front = board->find(this);
    if (m_next != NULL){
        SnakeTail* new_tail = new SnakeTail();
        SnakeTail* end_of_tail = find_prev(m_next);
        end_of_tail->m_next = new_tail;
        new_tail->m_next = m_next;
        m_next =  new_tail;
        board->move(this, new_front);
        board->insert(new_tail, old_front);
    } else {
        m_next = new SnakeTail();
        m_next->m_next = m_next;
        board->move(this, new_front);
        board->insert(m_next, old_front);
    }
}

int Snake::get_speed() const{
    return m_speed;
}

void Snake::set_alive(bool alive){
    m_alive = alive;
}

bool Snake::is_alive() const{
    return m_alive;
}

SnakeIterator Snake::begin() const{
    return SnakeIterator(this, find_tail());
}
SnakeIterator Snake::end() const{
    return SnakeIterator(NULL, find_tail());
}

const IterableSnake * Snake::next() const{
    return m_next;
}

const CellOccupier * Snake::get_cell_occupier() const{
    return this;
}