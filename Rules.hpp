#ifndef RULES_HPP
#define RULES_CPP
#include "Snake.hpp"
#include "Board.hpp"
#include "BoardVisualiser.hpp"
#include <boost/shared_ptr.hpp>
using std::vector;
using boost::shared_ptr;

class BoardVisualiser;

class Rules{
public:
	Rules(shared_ptr<Board> board, vector<Snake> snakes);
	~Rules();
	shared_ptr<Board> get_board();
	// Currently just displays the board;
	// void play();
private:
	vector<Snake> m_snakes;
	shared_ptr<Board> m_board;
	// shared_ptr<BoardVisualiser> m_visualiser;
	bool move_snake(Coord coord);
	// Updates board with snakes coordinates.
	// void update_board(Snake snake);
};


class RuleBuilder{
public:
	RuleBuilder();
	RuleBuilder& set_board(shared_ptr<Board> board);
	// Don't have to set snake size will go to default if not.
	RuleBuilder& set_snake_size(int size);
	RuleBuilder& set_player_count(int count);
	// RuleBuilder& set_visualiser_builder(shared_ptr<BoardVisualiserBuilder> visualiser_builder);
	shared_ptr<Rules> create();
private:
	shared_ptr<Board> m_board;
	int m_snake_size;
	int m_player_count;
};

#endif
