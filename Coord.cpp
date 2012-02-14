#include "Coord.hpp"
Coord::Coord(int x, int y){
    m_x = x;
    m_y = y;
}

int Coord::get_x() const{
    return m_x;
}

int Coord::get_y() const{
    return m_y;
}

Coord Coord::operator+(const Coord& coord) const{
    Coord result(m_x + coord.m_x, m_y + coord.m_y);
    return result;
}

Coord Coord::operator-(const Coord& coord) const{
    Coord result(m_x + coord.m_x, m_y + coord.m_y);
    return result;
}

Coord Coord::operator=(const Coord& coord){
    m_x = coord.m_x;
    m_y = coord.m_y;
    return *this;
}

Coord Coord::move(Direction direction){
    switch(direction){
        case UP:
          return Coord(m_x, m_y-1);
        case DOWN:
          return Coord(m_x, m_y+1);
        case LEFT:
          return Coord(m_x-1, m_y);
        case RIGHT:
          return Coord(m_x+1, m_y);
    }
    return *this;
}
