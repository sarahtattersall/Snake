#include "Coord.hpp"
#include "assert.h"
// int Coord::s_board_height = 0;
// int Coord::s_board_width = 0;
Coord::Coord(){
    m_x = 0;
    m_y = 0;
}

Coord::Coord(int x, int y){
    // assert(s_board_height != 0);
    // assert(s_board_width != 0);
    m_x = x;
    m_y = y;
}

int Coord::get_x() const{
    return m_x;
}

int Coord::get_y() const{
    return m_y;
}

// Coord Coord::operator+(const Coord& coord) const{
//     int x = (m_x + coord.m_x) % s_board_width;
//     if (x < 0){
//         x += s_board_width;  
//     }
//     int y = (m_y + coord.m_y) % s_board_height;
//     if (y < 0){
//         y += s_board_height;  
//     }
//     Coord result(x,y);
//     return result;
// }
// 
// Coord Coord::operator-(const Coord& coord) const{
//     int x = (m_x - coord.m_x) % s_board_width;
//     if (x < 0){
//         x += s_board_width;  
//     }
//     int y = (m_y - coord.m_y) % s_board_height;
//     if (y < 0){
//         y += s_board_height;   
//     }
//     Coord result(x,y);
//     return result;
// }
// 
// Coord Coord::operator=(const Coord& coord){
//     m_x = coord.m_x;
//     m_y = coord.m_y;
//     return *this;
// }

// Coord Coord::move(Direction direction){
//     switch(direction){
//         case UP:
//             return Coord(m_x, m_y) - Coord(0, 1);
//         case DOWN:
//             return Coord(m_x, m_y) + Coord(0, 1);
//         case LEFT:
//             return Coord(m_x, m_y) - Coord(1, 0);
//         case RIGHT:
//             return Coord(m_x, m_y) + Coord(1, 0);
//     }
//     return *this;
// }


// void Coord::set_board_dimensions(int height, int width){
//     s_board_height = height;
//     s_board_width = width;
// }


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