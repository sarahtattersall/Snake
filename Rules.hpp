#ifndef RULES_HPP
#define RULES_HPP
#include "Snake.hpp"
#include "Board.hpp"
#include "SnakeDirection.hpp"
#include "BoardVisualiser.hpp"
#include "WallOccupier.hpp"
#include "FoodOccupier.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
using std::vector;
using boost::shared_ptr;
using boost::ptr_vector;

class BoardVisualiser;

class Rules{
public:
	Rules(shared_ptr<Board> board, vector<Snake*> snakes, WallOccupier* wall);
    ~Rules();
	shared_ptr<Board> get_board();
	// Returns bool for if the move succeeds. If false
	// end of game (i.e. hit wall or snake)
	bool move_snake(int index, Coord::Direction direction);
    // Overloaded method. If no direction is given moves in the current 
    // snakes direction
    bool move_snake(int index);
	int snake_count();
	const Snake& get_snake(int index);
private:
	ptr_vector<Snake> m_snakes;
	shared_ptr<Board> m_board;
    WallOccupier* m_wall;
	FoodOccupier* m_food;
	// Determines if a Coord is out of bounds for the board
	bool coord_out_of_bounds(Coord coord);
    bool compute_move(Snake& snake, Coord::Direction direction);
	void place_food();
	
};


class RuleBuilder{
public:
	RuleBuilder();
	RuleBuilder& set_board(shared_ptr<Board> board);
	// Don't have to set snake size will go to default if not.
	RuleBuilder& set_snake_size(int size);
	RuleBuilder& set_player_count(int count);
    // Creates rules, adds a perimiter around the board,
    // adds snakes to the board.
	shared_ptr<Rules> create();
private:
	shared_ptr<Board> m_board;
	int m_snake_size;
	int m_player_count;
    // Adds wall occupiers around the board perimiter.
    void set_perimiter();
    WallOccupier* m_wall;
};

#endif
