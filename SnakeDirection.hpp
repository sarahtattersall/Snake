#ifndef SNAKE_DIRECTION_HPP
#define SNAKE_DIRECTION_HPP
#include "Coord.hpp"
class SnakeDirection{
public:
    enum Direction { UP, DOWN, RIGHT, LEFT };
	// IS THIS THE RIGHT WAY TO DO THIS? 
    // ALSO DO YOU HAVE TO CHECK MEMORY ALLOCATION FAILURE?
    static Coord to_coord(Direction direction){
        Coord* direction_coord;
        switch(direction){
            case SnakeDirection::UP:
                direction_coord = new Coord(0, -1);
                break;
            case SnakeDirection::DOWN:
                direction_coord = new Coord(0, 1);
                break;
            case SnakeDirection::LEFT:
                direction_coord = new Coord(-1, 0);
                break;
            case SnakeDirection::RIGHT:
                direction_coord = new Coord(1, 0);
                break;
        }
        Coord coord = *direction_coord;
        delete direction_coord;
        return coord;
    }
};

#endif
