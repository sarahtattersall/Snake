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
	Rules(shared_ptr<Board> board, vector<Snake> snakes, BoardVisualiser* visualiser);
	~Rules();
	shared_ptr<Board> get_board();
	// Currently just displays the board;
	void play();
private:
	vector<Snake> m_snakes;
	shared_ptr<Board> m_board;
	BoardVisualiser* m_visualiser;
	// Updates board with snakes coordinates.
	void update_board(Snake snake);
};


class RuleBuilder{
public:
	RuleBuilder();
	RuleBuilder& set_board_size(int size);
	// Don't have to set snake size will go to default if not.
	RuleBuilder& set_snake_size(int size);
	RuleBuilder& set_player_count(int count);
	RuleBuilder& set_visualiser_builder(BoardVisualiserBuilder* visualiser_builder);
	Rules* create();
private:
	int m_board_size;
	int m_snake_size;
	int m_player_count;
	BoardVisualiserBuilder* m_visualiser_builder;
};

#endif