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
	m_test_board_size = 10;
	m_test_player_count = 2;
	m_test_snake_size = 2;
	m_test_visualiser = shared_ptr<BoardVisualiserBuilder> (new TextualBoardVisualiserBuilder());
}


void RulesTest::tearDown(){
	delete m_builder1;
	delete m_builder2;
	delete m_builder3;
	delete m_builder4;
}


void RulesTest::noBoardSizeTest(){
	m_builder1->set_player_count(m_test_player_count);
	m_builder1->set_snake_size(m_test_snake_size);
	m_builder1->set_visualiser_builder(m_test_visualiser);
	CPPUNIT_ASSERT_THROW(m_builder1->create(), RuleBuilderException);
}

void RulesTest::noPlayerCountTest(){
	m_builder2->set_board_size(m_test_board_size);
	m_builder2->set_snake_size(m_test_snake_size);
	m_builder2->set_visualiser_builder(m_test_visualiser);
	CPPUNIT_ASSERT_THROW(m_builder2->create(), RuleBuilderException);
}

void RulesTest::noSnakeSizeTest(){
	m_builder3->set_board_size(m_test_board_size);
	m_builder3->set_player_count(m_test_player_count);
	m_builder3->set_visualiser_builder(m_test_visualiser);
	// CPPUNIT_ASSERT_THROW(m_builder3->create(), RuleBuilderException);
}

void RulesTest::noVisualiserTest(){
	m_builder4->set_board_size(m_test_board_size);
	m_builder4->set_player_count(m_test_player_count);
	m_builder4->set_snake_size(m_test_snake_size);
	CPPUNIT_ASSERT_THROW(m_builder4->create(), RuleBuilderException);
}