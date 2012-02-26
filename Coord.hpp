#ifndef COORD_HPP
#define COORD_HPP

class Coord{
public:
  enum Direction { UP, DOWN, RIGHT, LEFT };
  Coord();
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
  static void set_board_dimensions(int height, int width);
  // static Direction invert_direction(Direction direction);
  
private:
    static int s_board_height;
    static int s_board_width;
    int m_x;
    int m_y;
    int mod (int number, int mod_value);
};

#endif
