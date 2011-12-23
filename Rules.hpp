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
};


class RuleBuilder{
public:
	RuleBuilder& set_board_size(int size);
	RuleBuilder& set_player_count(int count);
	Rules* create();
private:
	int m_board_size;
	int m_player_count;	
};

#endif