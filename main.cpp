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
	    RuleBuilder rule_builder;
	    rule_builder.set_board_size(10);
		rule_builder.set_player_count(1);
		rule_builder.set_visualiser_builder(shared_ptr<BoardVisualiserBuilder> (new TextualBoardVisualiserBuilder()));
		shared_ptr<Rules> rules = rule_builder.create();
		rules->play();
	}catch (SnakeException& e){
		cout << e.what() << endl;
	}
	// TextualBoardVisualiser visualiser(board_builder.create());
	// visualiser.display();
}