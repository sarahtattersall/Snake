#include "Rules.hpp"
#include "TextualBoardVisualiser.hpp"
#include "SnakeException.hpp"
#include <Boost/shared_ptr.hpp>
#include <iostream>
using namespace std;
using boost::shared_ptr;

int main(int argc, char *argv[])
{
	try{
		BoardBuilder board_builder;
		board_builder.set_size(10);
		shared_ptr<Board> board =  board_builder.create();
	    RuleBuilder rule_builder;
	    rule_builder.set_board(board);
		rule_builder.set_player_count(1);
		// rule_builder.set_visualiser_builder(shared_ptr<BoardVisualiserBuilder> (new TextualBoardVisualiserBuilder()));
		shared_ptr<Rules> rules = rule_builder.create();
		// rules->play();
		TextualBoardVisualiserBuilder visualiser_builder;
		visualiser_builder.set_board(board);
		shared_ptr<BoardVisualiser> visualiser = visualiser_builder.create();
		visualiser->display();
		cout << endl;
		rules->move_snake(0, Coord(1,0));
		visualiser->display();
	}catch (SnakeException& e){
		cout << e.what() << endl;
	}
	// TextualBoardVisualiser visualiser(board_builder.create());
	// visualiser.display();
}