#ifndef COORD_HPP
#define COORD_HPP

class Coord{
public:
  // enum Direction { UP, DOWN, RIGHT, LEFT };
  Coord();
  Coord(int x, int y);
  int get_x() const;
  int get_y() const;
private:
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
