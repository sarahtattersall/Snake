#ifndef COORD_HPP
#define COORD_HPP

// CoordinateSpace class that handles mod not coord and all the move stuff.
// space.add(point, vector)
// Seperation!!!
class Coord{
public:
  // enum Direction { UP, DOWN, RIGHT, LEFT };
  Coord();
  Coord(int x, int y);
  int get_x() const;
  int get_y() const;
  // Overrides + operator
  // Coord operator+(const Coord& coord) const;
  // Overrides - operator
  // Coord operator-(const Coord& coord) const;
  // Overrides = operator
  // Coord operator=(const Coord& coord);
  // Coord move(Direction direction);
  // static void set_board_dimensions(int height, int width);
  // static Direction inverse(Direction direction);
private:
    // static int s_board_height;
    // static int s_board_width;
    int m_x;
    int m_y;
};

// 2D Vector
class Vector{
public:
    enum Direction { UP, DOWN, RIGHT, LEFT };
    Vector(int i, int j){
        m_i = i;
        m_j = j;
    };
    int get_i(){
        return m_i;
    }
    int get_j(){
        return m_j;
    }
    static Direction inverse(Direction direction);
    
private:
    int m_i;
    int m_j;
};

class CoordinateSpace{
public:
  CoordinateSpace(int width, int height) : m_width(width), m_height(height) {};
  Coord move(Vector vec, Coord coord) const{
      return move(coord, vec);
  };
  Coord move(Vector::Direction direction, Coord coord) const{
      return move(coord, direction);
  }
  Coord move(Coord coord, Vector vec) const;
  Coord move(Coord coord, Vector::Direction direction) const;
  
private:
    const int m_width;
    const int m_height;
    int mod (int number, const int mod_value) const;
};

#endif
