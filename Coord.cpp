#ifndef COORD_HPP
#define COORD_HPP

class Coord{
public:
	Coord(int x, int y);
	int get_x();
	int get_y();
private:
	int m_x;
	int m_y;
};

#endif