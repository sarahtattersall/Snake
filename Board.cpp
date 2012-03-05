#include "Board.hpp"
#include "Cell.hpp"
#include "SnakeException.hpp"
#include <map>
#include <vector>

// #include <boost/scoped_ptr.hpp>
using std::multimap;
using std::vector;
using std::pair;
// using boost::scoped_ptr;

class CellOccupier;
//This is the only current implementation of Board
class SquareBoard : public Board {
public:
    SquareBoard(const int size);
    virtual int get_height();
    virtual int get_width();
    virtual void insert(CellOccupier* occupier, Coord coord);
    virtual void move(const CellOccupier* occupier, Coord coord);
    virtual void remove(const CellOccupier* occupier);
    virtual Coord find(const CellOccupier* occupier);
    virtual vector<Coord> find_all(const CellOccupier* occupier);
    virtual const CellOccupier* lookup(const Coord coord);
    virtual void clear();
private:
    int m_size;
    vector<vector<Cell> > m_cells;
    shared_ptr<EmptyOccupier> m_empty;
    // Stores occupiers to coordinates
    multimap<const CellOccupier*, Coord> m_occupiers;
    // Initializes the board with empty cells.
    void initialize_board();
};

BoardBuilder::BoardBuilder(){
    m_size = 0;
}

BoardBuilder& BoardBuilder::set_size(int size){
    m_size = size;
    return *this;
}
shared_ptr<Board> BoardBuilder::create(){
    if(m_size == 0){
        throw BoardBuilderException();
    }
    return shared_ptr<Board> (new SquareBoard(m_size));
}

SquareBoard::SquareBoard(const int size) : m_empty(shared_ptr<EmptyOccupier> (new EmptyOccupier())){
    m_size = size;
    initialize_board();
}

int SquareBoard::get_height(){
    return m_size;
}

int SquareBoard::get_width(){
    return m_size;
}

void SquareBoard::insert(CellOccupier* occupier, const Coord coord){
    m_cells[coord.get_y()][coord.get_x()].set_occupier(occupier);
    m_occupiers.insert(pair<CellOccupier*,Coord>(occupier, coord));
}

void SquareBoard::move(const CellOccupier* occupier, const Coord coord){
    Coord old_coord = m_occupiers.find(occupier)->second;
    m_cells[old_coord.get_y()][old_coord.get_x()].set_occupier(m_empty.get());
    m_cells[coord.get_y()][coord.get_x()].set_occupier(occupier);
    if( m_occupiers.find(occupier) != m_occupiers.end() ){
        m_occupiers.erase(m_occupiers.find(occupier));
    }
    m_occupiers.insert(pair<const CellOccupier*,Coord>(occupier, coord));
}

void SquareBoard::remove(const CellOccupier* occupier){
    Coord coord = m_occupiers.find(occupier)->second;
    m_cells[coord.get_y()][coord.get_x()].set_occupier(m_empty.get());
    m_occupiers.erase(m_occupiers.find(occupier));
}

Coord SquareBoard::find(const CellOccupier* occupier){
    return m_occupiers.find(occupier)->second;
}

// TODO would it have been better to return a pointer and delete when finished?
vector<Coord> SquareBoard::find_all(const CellOccupier* occupier){
    vector<Coord> coords;
    pair<multimap<const CellOccupier*, Coord>::iterator,multimap<const CellOccupier*, Coord>::iterator> ret;
    ret = m_occupiers.equal_range(occupier);
    for (multimap<const CellOccupier*, Coord>::iterator itr = ret.first; itr != ret.second; ++itr){
        coords.push_back((*itr).second);
    }
    return coords;
}

const CellOccupier* SquareBoard::lookup(const Coord coord){
    return m_cells[coord.get_y()][coord.get_x()].get_occupier();
}

void SquareBoard::initialize_board(){
    m_cells.resize(m_size);
    for (int i = 0; i < m_size; ++i){
        for( int j = 0; j < m_size; ++j){
            m_cells[i].push_back(Cell(m_empty.get()));
            m_occupiers.insert(pair<CellOccupier*,Coord>(m_empty.get(), Coord(j,i)));
        }
    }
}

void SquareBoard::clear(){    
    for(multimap<const CellOccupier*, Coord>::iterator itr = m_occupiers.begin();
        itr != m_occupiers.end(); ++itr ){
            m_occupiers.erase(itr);
    }
    for (int i = 0; i < m_size; ++i){
        for( int j = 0; j < m_size; ++j){
            Coord coord = Coord(j,i);
            m_cells[coord.get_y()][coord.get_x()].set_occupier(m_empty.get());
            m_occupiers.insert(pair<CellOccupier*,Coord>(m_empty.get(), coord));
        }
    }
}
