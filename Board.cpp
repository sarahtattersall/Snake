#include "Board.hpp"
#include "Cell.hpp"
#include "SnakeException.hpp"
#include "EmptyOccupier.hpp"
#include <map>
#include <vector>
using std::multimap;
using std::vector;
using std::pair;

//IAN: This is the only current implementation of Board
class SquareBoard : public Board {
public:
    SquareBoard(const int size);
    ~SquareBoard();
    virtual int get_height();
    virtual int get_width();
    virtual void insert(CellOccupier* occupier, Coord coord);
    virtual void move(CellOccupier* occupier, Coord coord);
    virtual void remove(CellOccupier* occupier);
    virtual Coord find(CellOccupier* occupier);
    virtual CellOccupier* lookup(Coord coord);
private:
    int m_size;
    vector<vector<Cell> > m_cells;
    // Stores occupiers to coordinates
    multimap<CellOccupier*, Coord> m_occupiers;
    // Initializes the board with empty cells.
    void initialize_board();
    //Coord next_coord(SnakeDirection::Direction direction, Coord coord);
    EmptyOccupier* m_empty;
};

BoardBuilder::BoardBuilder(){
    m_size = 0;
}

BoardBuilder& BoardBuilder::set_size(const int size){
    m_size = size;
    return *this;
}
shared_ptr<Board> BoardBuilder::create(){
	if(m_size == 0){
		throw BoardBuilderException();
	}
    return shared_ptr<Board> (new SquareBoard(m_size));
}

SquareBoard::SquareBoard(const int size){
    m_size = size;
    m_empty = new EmptyOccupier();
    initialize_board();
}

SquareBoard::~SquareBoard(){
    delete m_empty;
}

int SquareBoard::get_height(){
	return m_size;
}

int SquareBoard::get_width(){
	return m_size;
}

void SquareBoard::insert(CellOccupier* occupier, const Coord coord){
	m_cells[coord.get_y()][coord.get_x()].set_occupier(occupier);
    if( m_occupiers.find(occupier) != m_occupiers.end() ){
        m_occupiers.erase(m_occupiers.find(occupier));
    }
    m_occupiers.insert(pair<CellOccupier*,Coord>(occupier, coord));
}

void SquareBoard::move(CellOccupier* occupier, const Coord coord){
    Coord old_coord = m_occupiers.find(occupier)->second;
    m_cells[old_coord.get_y()][old_coord.get_x()].set_occupier(m_empty);
    m_cells[coord.get_y()][coord.get_x()].set_occupier(occupier);
    if( m_occupiers.find(occupier) != m_occupiers.end() ){
        m_occupiers.erase(m_occupiers.find(occupier));
    }
    m_occupiers.insert(pair<CellOccupier*,Coord>(occupier, coord));
}

void SquareBoard::remove(CellOccupier* occupier){
    Coord coord = m_occupiers.find(occupier)->second;
    m_cells[coord.get_y()][coord.get_x()].set_occupier(m_empty);
    m_occupiers.erase(m_occupiers.find(occupier));
}

Coord SquareBoard::find(CellOccupier* occupier){
    return m_occupiers.find(occupier)->second;
}

CellOccupier* SquareBoard::lookup(Coord coord){
    return m_cells[coord.get_y()][coord.get_x()].get_occupier();
}

void SquareBoard::initialize_board(){
	m_cells.resize(m_size);
    for (int i = 0; i < m_size; ++i){
        for( int j = 0; j < m_size; ++j){
            m_cells[i].push_back(Cell(m_empty));
            m_occupiers.insert(pair<CellOccupier*,Coord>(m_empty, Coord(j,i)));
        }
    }
}
