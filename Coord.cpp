#include "Coord.hpp"
#include "assert.h"
Coord::Coord(){
    m_x = 0;
    m_y = 0;
}

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

Vector::Direction Vector::inverse(Direction direction){
    switch(direction){
        case UP:
            return DOWN;
        case DOWN:
            return UP;
        case LEFT:
            return RIGHT;
        case RIGHT:
            return LEFT;
    }
    return direction;
}

int CoordinateSpace::mod(int number, const int mod_value) const{
    number %= mod_value;
    return number < 0 ? number + mod_value : number;
}

Coord CoordinateSpace::move(Coord coord, Vector vec) const{
    int x = mod(coord.get_x() + vec.get_i(), m_width);
    int y = mod(coord.get_y() + vec.get_j(), m_height);
    return Coord(x,y);
}

Coord CoordinateSpace::move(Coord coord, Vector::Direction direction) const{
    switch (direction){
        case(Vector::UP):
            return move(coord, Vector(0,-1));
            break;
        case(Vector::DOWN):
            return move(coord, Vector(0,1));
            break;
        case(Vector::LEFT):
            return move(coord, Vector(-1,0));
            break;
        case(Vector::RIGHT):
            return move(coord, Vector(1,0));
            break;
        default:
            return coord;
    }
    return coord;
}