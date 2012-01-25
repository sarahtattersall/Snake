#include "Board.hpp"
#include "Cell.hpp"
#include "SnakeException.hpp"
#include <iostream>
#include "EmptyOccupier.hpp"
//IAN: This is the only current implementation of Board
class SquareBoard : public Board {
public:
    SquareBoard(const int size);
    virtual Cell& get(Coord coord);
	virtual Cell& get(int x, int y);
    virtual int get_height();
    virtual int get_width();
	virtual void insert(shared_ptr<CellOccupier> occupier, Coord coord);
    virtual shared_ptr<SnakeHeadOccupier> get_snake_head();
    virtual void move_snake(SnakeDirection::Direction direction);
	// virtual void remove(Coord coord);
private:
    int m_size;
    // Initializes the board with empty cells.
    void initialize_board();
    Coord next_coord(SnakeDirection::Direction direction, Coord coord);
    vector<vector<Cell> > m_cells;
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

Cell& SquareBoard::get(Coord coord){
	return m_cells[coord.get_y()][coord.get_x()];
}

Cell& SquareBoard::get(int x, int y){
	return m_cells[y][x];
}

int SquareBoard::get_height(){
	return m_size;
}

int SquareBoard::get_width(){
	return m_size;
}

SquareBoard::SquareBoard(const int size){
    m_size = size;
    initialize_board();
}

void SquareBoard::insert(shared_ptr<CellOccupier> occupier, Coord coord){
	m_cells[coord.get_y()][coord.get_x()].set_cell(occupier);
	// This will only work for 1 player game! Else which list do you add it to?!? 
	if( occupier->get_type() == CellOccupier::SNAKE ){
        m_snake_occupiers.push_back(&(m_cells[coord.get_y()][coord.get_x()]));
    }
}


void SquareBoard::initialize_board(){
	m_cells.resize(m_size);
    for (int i = 0; i < m_size; ++i){
        for( int j = 0; j < m_size; ++j){
            m_cells[i].push_back(Cell());
        }
    }
}


Coord SquareBoard::next_coord(SnakeDirection::Direction direction, Coord coord){
    Coord direction_coord = SnakeDirection::to_coord(direction);
    return direction_coord + coord;
        
}

shared_ptr<SnakeHeadOccupier> SquareBoard::get_snake_head(){
    return boost::static_pointer_cast<SnakeHeadOccupier>((m_snake_occupiers.front())->get_occupier());
}

void SquareBoard::move_snake(SnakeDirection::Direction direction){
    Cell* front_cell = m_snake_occupiers.front();
    Cell* cell = m_snake_occupiers.back();

    m_snake_occupiers.pop_back();
    
    shared_ptr<SnakeHeadOccupier> head = boost::static_pointer_cast<SnakeHeadOccupier>(front_cell->get_occupier());
    shared_ptr<CellOccupier> tail_snake_occupier = cell->get_occupier();
    
    cell->set_cell(shared_ptr<CellOccupier> (new EmptyOccupier()));
    front_cell->set_cell(tail_snake_occupier);
    
    Coord new_front = next_coord(head->get_direction(), head->get_coord());
    Cell* new_front_cell = &m_cells[new_front.get_y()][new_front.get_x()];
    head->set_direction(direction);
    head->set_coord(new_front);
    new_front_cell->set_cell(head);
    m_snake_occupiers.push_front(new_front_cell);
}
