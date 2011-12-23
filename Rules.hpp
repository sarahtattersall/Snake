#ifndef RULES_HPP
#define RULES_CPP
#include "Snake.hpp"
#include "Board.hpp"
using std::vector;

class Rules{
public:
	Rules(Board* board, vector<Snake> snakes);
	~Rules();
	Board* get_board();
private:
	vector<Snake> m_snakes;
	Board* m_board;
	// Updates board with snakes coordinates.
	void update_board(Snake snake);
};


class RuleBuilder{
public:
	RuleBuilder& set_board_size(int size);
	// Don't have to set snake size will go to default if not.
	RuleBuilder& set_snake_size(int size);
	RuleBuilder& set_player_count(int count);
	Rules* create();
private:
	int m_board_size;
	int m_snake_size;
	int m_player_count;	
};

#endif