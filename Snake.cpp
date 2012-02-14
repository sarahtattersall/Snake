#include "Snake.hpp"
Snake::Snake(int size, Coord::Direction d) : CellOccupier(){
    m_size = size;
		m_alive = true;
    m_direction = d;
		m_tail = NULL;
		m_speed = FAST;
}

Snake::~Snake(){
    if( m_tail != NULL ){
        SnakeTail* front = m_tail;
        SnakeTail* next_tail = m_tail->get_next();
        front->m_next = NULL; // Break the loop.
        while( next_tail != NULL ){
            SnakeTail* current = next_tail;
            next_tail = current->get_next();
            delete current;
        }
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
			for(int i = 0; i < m_size - 1; ++i){
				grow(board);
			}
    }
}

SnakeTail* Snake::find_tail(){
    if( m_tail != NULL ){
        return find_prev(m_tail);
    }
    return NULL;
}

int Snake::get_size() const{
    return m_size;    
}


void Snake::move_tail(){
    SnakeTail* tail = find_tail();
    m_tail = tail;
}

SnakeTail* Snake::find_prev(SnakeTail* tail){
    SnakeTail* next = m_tail;
    while(next->m_next != tail ){
        next = next->m_next;
    }
    return next;
}

void Snake::grow(shared_ptr<Board> board){
	Coord front = board->find(this);
	if( m_tail != NULL ){
		SnakeTail* new_tail = new SnakeTail();
		SnakeTail* end_of_tail = find_prev(m_tail);
		end_of_tail->m_next = new_tail;
		new_tail->m_next = m_tail;
		m_tail =  new_tail;
		board->move(this, front.move(m_direction));
		board->insert(new_tail, front);
	} else {
		m_tail = new SnakeTail();
		m_tail->m_next = m_tail;
		board->move(this, front.move(m_direction));
		board->insert(m_tail, front);
	}
}

int Snake::get_speed() const{
	return m_speed;
}

void Snake::set_alive(bool alive){
	m_alive = alive;
}

bool Snake::is_alive(){
	return m_alive;
}
