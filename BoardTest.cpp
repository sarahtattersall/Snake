#include "BoardTest.hpp"
#include "Boost/shared_ptr.hpp"
#include "SnakeException.hpp"
using boost::shared_ptr;
// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( BoardTest );


void BoardTest::setUp(){
	m_builder1 = new BoardBuilder();
	m_builder2 = new BoardBuilder();
}


void BoardTest::tearDown(){
	delete m_builder1;
	delete m_builder2;
}


void BoardTest::sizeTest(){
	int board_size = 10;
	m_builder1->set_size(board_size);
	shared_ptr<Board> board1 = m_builder1->create();
	CPPUNIT_ASSERT_EQUAL(board1->get_width(), board_size);
	CPPUNIT_ASSERT_EQUAL(board1->get_height(), board_size);
}

void BoardTest::builderFailsTest(){
	CPPUNIT_ASSERT_THROW(m_builder1->create(), BoardBuilderException);
}

