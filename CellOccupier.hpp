#ifndef CELL_OCCUPIER_HPP
#define CELL_OCCUPIER_HPP

//IAN: There are so many ways to implement this, but none of them are really
// all that good.
// I have changed this to a slightly nicer way to use the enum approach.
// It's better because you are trusting the vtable of the object, rather than a
// field that you can change. There are times when the other approach is better,
// notably if you have expensive to construct items that want to change their
// type dynamically.
// You can actually not use the enum and rely on dynamic_cast to get what you
// want.
class CellOccupier{
public:
	enum TYPE {EMPTY, SNAKE, FOOD};
	CellOccupier();
	virtual TYPE get_type() = 0;
};

#endif
