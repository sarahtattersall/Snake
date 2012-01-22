#include <QtGui/QApplication>
#include <Boost/shared_ptr.hpp>
#include <iostream>
#include "Rules.hpp"
#include "SnakeGUI.hpp"
#include "SnakeException.hpp"
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
		shared_ptr<Rules> rules = rule_builder.create();
		QApplication app(argc, argv);    
		SnakeGUI gui(board, rules);
    	return app.exec();
	}catch (SnakeException& e){
		cout << e.what() << endl;
	}
}