#include "RulesTest.hpp"
#include "Boost/shared_ptr.hpp"
#include "SnakeException.hpp"
#include "TextualBoardVisualiser.hpp"
using boost::shared_ptr;
// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( RulesTest );


void RulesTest::setUp(){
	m_builder1 = new RuleBuilder();
	m_builder2 = new RuleBuilder();
	m_builder3 = new RuleBuilder();
	m_builder4 = new RuleBuilder();
	m_builder5 = new RuleBuilder();
	m_test_board_size = 10;
	m_test_player_count = 2;
	m_test_snake_size = 2;
	BoardBuilder board_builder;
	board_builder.set_size(m_test_board_size);
	m_test_board = board_builder.create();
}


void RulesTest::tearDown(){
	delete m_builder1;
	delete m_builder2;
	delete m_builder3;
	delete m_builder4;
	delete m_builder5;
}


void RulesTest::noBoardTest(){
	m_builder1->set_player_count(m_test_player_count);
	m_builder1->set_snake_size(m_test_snake_size);
	CPPUNIT_ASSERT_THROW(m_builder1->create(), RuleBuilderException);
}

void RulesTest::noPlayerCountTest(){
	m_builder2->set_board(m_test_board);
	m_builder2->set_snake_size(m_test_snake_size);
	CPPUNIT_ASSERT_THROW(m_builder2->create(), RuleBuilderException);
}

void RulesTest::noSnakeSizeTest(){
	m_builder3->set_board(m_test_board);
	m_builder3->set_player_count(m_test_player_count);
	CPPUNIT_ASSERT_NO_THROW(m_builder3->create());
	// Should really check that the output is expected here.
}

void RulesTest::correctMove(){
	m_builder4->set_board(m_test_board);
	m_builder4->set_player_count(m_test_player_count);
	m_builder4->set_snake_size(m_test_snake_size);
	shared_ptr<Rules> rules = m_builder4->create();
	bool result = rules->move_snake(1, Coord(1,1));
	CPPUNIT_ASSERT_EQUAL(result, true);
	//SARAH: How can assure board has moved snake without access to board??
}

void RulesTest::snakeCrashesIntoWall(){
	m_builder5->set_board(m_test_board);
	m_builder5->set_player_count(m_test_player_count);
	m_builder5->set_snake_size(m_test_snake_size);
	shared_ptr<Rules> rules = m_builder5->create();
	bool result;
	for(int i = 0; i < 4; ++i){
		result = rules->move_snake(0, Coord(0,1));
		CPPUNIT_ASSERT_EQUAL(result, true);
	}
	result = rules->move_snake(0, Coord(0,1));
	CPPUNIT_ASSERT_EQUAL(result, false);
}