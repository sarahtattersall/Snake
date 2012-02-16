#ifndef RULES_HPP
#define RULES_HPP
#include "Board.hpp"
#include "SnakeDirection.hpp"
#include "BoardVisualiser.hpp"
#include "CellOccupier.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
using std::vector;
using boost::shared_ptr;
using boost::ptr_vector;

class BoardVisualiser;

class Rules{
public:
    Rules(shared_ptr<Board> board, bool through_walls);
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
    bool snake_dead();
    void build_wall();
    void set_snakes(int players, int snake_size);
    // Uses m_prev_snake_size to determine snake start size
    // then calls set_snakes(players, snake_size)
    void set_snakes(int players);
    void reset();
private:
    ptr_vector<Snake> m_snakes;
    shared_ptr<Board> m_board;
    WallOccupier* m_wall;
    FoodOccupier* m_food;
    // Determines if a Coord is out of bounds for the board
    bool coord_out_of_bounds(Coord coord);
    bool compute_move(Snake& snake, Coord::Direction direction);
    void place_food();
    int m_prev_snake_size;
    //Bool determining if the snake can pass through walls.
    bool m_through_walls;
    
};


class RuleBuilder{
public:
    RuleBuilder();
    RuleBuilder& set_board(shared_ptr<Board> board);
    // Don't have to set snake size will go to default if not.
    RuleBuilder& set_snake_size(int size);
    RuleBuilder& set_player_count(int count);
    RuleBuilder& set_through_walls(bool through_walls);
    // Creates rules, adds a perimiter around the board,
    // adds snakes to the board.
    shared_ptr<Rules> create();
private:
    shared_ptr<Board> m_board;
    int m_snake_size;
    int m_player_count;
    bool m_through_walls;
};

#endif
