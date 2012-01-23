class WallOccupier : public CellOccupier{
public:
  	virtual TYPE get_type() { return WALL; }
};

