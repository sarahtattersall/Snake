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
  Coord operator-(const Coord& coord) const;
  // Overrides = operator
  Coord operator=(const Coord& coord);

  Coord move(Direction direction);

private:
    int m_x;
    int m_y;
};

#endif
