#ifndef SNAKE_DIRECTION_HPP
#define SNAKE_DIRECTION_HPP
#include "Coord.hpp"
class SnakeDirection{
public:
    enum Direction { UP, DOWN, RIGHT, LEFT };
private:
    static Coord to_coord(Direction direction){
        switch(direction){
            case SnakeDirection::UP:
                return Coord(0, -1);
            case SnakeDirection::DOWN:
                return Coord(0, 1);
            case SnakeDirection::LEFT:
                return Coord(-1, 0);
            case SnakeDirection::RIGHT:
                return Coord(1, 0);
        }
    //FATAL("Invalid enum constant");
        return Coord(0,0);
    }
};

#endif
