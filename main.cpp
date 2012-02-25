#include <QtGui/QApplication>
#include <boost/shared_ptr.hpp>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Rules.hpp"
#include "Scene.hpp"
#include "SnakeException.hpp"
//#include "TextualBoardVisualiser.hpp"
//#include "Coord.hpp"
using namespace std;
using boost::shared_ptr;

int main(int argc, char *argv[])
{
    int players = 1;
    bool through_walls = false;
    if (argc > 1){
        players = atoi(argv[1]);  
        if (argc > 2){
            through_walls = (atoi(argv[2]) == 1 || strcmp(argv[2], "t") > 0 || strcmp(argv[2], "true") > 0);
        }
    }
    try{
        BoardBuilder board_builder;
        board_builder.set_size(20);
        shared_ptr<Board> board =  board_builder.create();
        RuleBuilder rule_builder;
        rule_builder.set_board(board);
        rule_builder.set_player_count(players);
        rule_builder.set_through_walls(through_walls);
        shared_ptr<Rules> rules = rule_builder.create();
        QApplication app(argc, argv);    
        Scene scene(board, rules);
        return app.exec();
        return 0;
    }catch (SnakeException& e){
        cout << e.what() << endl;
    }
}
