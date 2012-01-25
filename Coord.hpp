#ifndef COORD_HPP
#define COORD_HPP

class Coord{
public:
  enum Direction { UP, DOWN, RIGHT, LEFT };
  Coord(int x, int y);
  int get_x() const;
  int get_y() const;
  // Overrides + operator
  Coord operator+(const Coord& coord) const;
  // Overrides - operator
  // type of this is const
  Coord operator-(const Coord& coord) const;
  // Overrides = operator
  Coord operator=(const Coord& coord);

  Coord move(Direction direction) {
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
private:
	int m_x;
	int m_y;
};

#endif
