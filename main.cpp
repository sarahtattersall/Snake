#include "Board.hpp"
#include "TextualBoardVisualiser.hpp"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    BoardBuilder board_builder;
    board_builder.set_size(10);
	TextualBoardVisualiser visualiser(board_builder.create());
	visualiser.display();
}