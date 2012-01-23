#include "RulesTest.hpp"
#include "boost/shared_ptr.hpp"
#include "SnakeException.hpp"
#include "TextualBoardVisualiser.hpp"
#include <iostream>
using namespace std;
using boost::shared_ptr;
// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( RulesTest );


void RulesTest::setUp(){
	m_builder1 = new RuleBuilder();
	m_builder2 = new RuleBuilder();
	m_builder3 = new RuleBuilder();
	m_builder4 = new RuleBuilder();
	m_builder5 = new RuleBuilder();
	m_builder6 = new RuleBuilder();
	m_builder7 = new RuleBuilder();
	m_builder8 = new RuleBuilder();
	m_builder9 = new RuleBuilder();
	m_test_board_size = 10;
	m_test_player_count = 2;
	m_test_snake_size = 2;
	m_test_board2 = make_board();
	m_test_board3 = make_board();
	m_test_board4 = make_board();
	m_test_board5 = make_board();
	m_test_board6 = make_board();
	m_test_board7 = make_board();
	m_test_board8 = make_board();
	m_test_board9 = make_board();
	
}

shared_ptr<Board> RulesTest::make_board(){
	BoardBuilder board_builder;
	board_builder.set_size(m_test_board_size);
	return board_builder.create();
}

void RulesTest::tearDown(){
	delete m_builder1;
	delete m_builder2;
	delete m_builder3;
	delete m_builder4;
	delete m_builder5;
	delete m_builder6;
	delete m_builder7;
	delete m_builder8;
	delete m_builder9;
}


void RulesTest::noBoardTest(){
	m_builder1->set_player_count(m_test_player_count);
	m_builder1->set_snake_size(m_test_snake_size);
	CPPUNIT_ASSERT_THROW(m_builder1->create(), RuleBuilderException);
}

void RulesTest::noPlayerCountTest(){
	m_builder2->set_board(m_test_board2);
	m_builder2->set_snake_size(m_test_snake_size);
	CPPUNIT_ASSERT_THROW(m_builder2->create(), RuleBuilderException);
}

void RulesTest::noSnakeSizeTest(){
	m_builder3->set_board(m_test_board3);
	m_builder3->set_player_count(m_test_player_count);
	CPPUNIT_ASSERT_NO_THROW(m_builder3->create());
	// Should really check that the output is expected here.
}

void RulesTest::correctMove(){
	m_builder4->set_board(m_test_board4);
	m_builder4->set_player_count(m_test_player_count);
	m_builder4->set_snake_size(m_test_snake_size);
	shared_ptr<Rules> rules = m_builder4->create();
	bool result = rules->move_snake(1, Rules::DOWN);
	CPPUNIT_ASSERT_EQUAL(result, true);
	//SARAH: How can assure board has moved snake without access to board??
}

void RulesTest::snakeBottomWallCrash(){
	m_builder5->set_board(m_test_board5);
	m_builder5->set_player_count(m_test_player_count);
	m_builder5->set_snake_size(m_test_snake_size);
	shared_ptr<Rules> rules = m_builder5->create();
	bool result;
	for(int i = 0; i < 3; ++i){
		result = rules->move_snake(0, Rules::DOWN);
		CPPUNIT_ASSERT_EQUAL(result, true);
	}
	result = rules->move_snake(0, Rules::DOWN);
	CPPUNIT_ASSERT_EQUAL(result, false);
}

void RulesTest::snakeRightWallCrash(){
	m_builder6->set_board(m_test_board6);
	m_builder6->set_player_count(m_test_player_count);
	m_builder6->set_snake_size(m_test_snake_size);
	shared_ptr<Rules> rules = m_builder6->create();
	bool result;
	for(int i = 0; i < 3; ++i){
		result = rules->move_snake(0, Rules::RIGHT);
		CPPUNIT_ASSERT_EQUAL(result, true);
	}
	result = rules->move_snake(0, Rules::RIGHT);
	CPPUNIT_ASSERT_EQUAL(result, false);
}

void RulesTest::snakeLeftWallCrash(){
	m_builder7->set_board(m_test_board7);
	// Other snake gets in way and know 2 snakes works.
	m_builder7->set_player_count(1);
	m_builder7->set_snake_size(m_test_snake_size);
	shared_ptr<Rules> rules = m_builder7->create();
	bool result;
	for(int i = 0; i < 4; ++i){
		result = rules->move_snake(0, Rules::LEFT);
		CPPUNIT_ASSERT_EQUAL(result, true);
	}
	result = rules->move_snake(0, Rules::LEFT);
	CPPUNIT_ASSERT_EQUAL(result, false);
}

void RulesTest::snakeTopWallCrash(){
	m_builder8->set_board(m_test_board8);
	m_builder8->set_player_count(m_test_player_count);
	m_builder8->set_snake_size(m_test_snake_size);
	shared_ptr<Rules> rules = m_builder8->create();
	bool result;
	result = rules->move_snake(0, Rules::RIGHT);
	for(int i = 0; i < 4; ++i){
		result = rules->move_snake(0, Rules::UP);
		CPPUNIT_ASSERT_EQUAL(result, true);
	}
	result = rules->move_snake(0, Rules::UP);
	CPPUNIT_ASSERT_EQUAL(result, false);
}

void RulesTest::snakeOnSnakeCrash(){
	m_builder9->set_board(m_test_board9);
	m_builder9->set_player_count(m_test_player_count);
	m_builder9->set_snake_size(m_test_snake_size);
	shared_ptr<Rules> rules = m_builder9->create();
	bool result;
	result = rules->move_snake(0, Rules::LEFT);
	CPPUNIT_ASSERT_EQUAL(result, false);
}
