#ifndef COORD_HPP
#define COORD_HPP

class Coord{
public:
  enum Direction { UP, DOWN, RIGHT, LEFT };
  Coord(int x, int y);
  int get_x();
  int get_y();
  // Overrides + operator
  Coord operator+(const Coord& coord) const;
  // Overrides - operator
  // type of this is const
  Coord operator-(const Coord& coord) const;
  // Overrides = operator
  Coord operator=(const Coord& coord);

  Coord move(Direction direction) {
    switch(direction){
    case SnakeDirection::UP:
      return Coord(m_x, m_y-1);
    case SnakeDirection::DOWN:
      return Coord(m_x, m_y+1);
    case SnakeDirection::LEFT:
      return Coord(m_x-1, m_y);
    case SnakeDirection::RIGHT:
      return Coord(m_x+1, m_y);
    }
    return *this;
  }
private:
	int m_x;
	int m_y;
};

#endif
