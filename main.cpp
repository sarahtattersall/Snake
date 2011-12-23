#include "Rules.hpp"
#include "TextualBoardVisualiser.hpp"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    RuleBuilder rule_builder;
    rule_builder.set_board_size(10);
	rule_builder.set_player_count(1);
	rule_builder.set_visualiser_builder(new TextualBoardVisualiserBuilder());
	// TextualBoardVisualiser visualiser(board_builder.create());
	// visualiser.display();
}