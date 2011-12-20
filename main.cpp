#include "Board.hpp"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    BoardBuilder board_builder;
    board_builder.set_size(10);
    Board* board = board_builder.create();
}