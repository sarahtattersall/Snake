#ifndef COORD_HPP
#define COORD_HPP

class Coord{
public:
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
private:
	int m_x;
	int m_y;
};

#endif