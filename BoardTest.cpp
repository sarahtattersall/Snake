#include "BoardTest.hpp"
#include "boost/shared_ptr.hpp"
#include "SnakeException.hpp"
#include "CellOccupier.hpp"
#include "Snake.hpp"
#include <iostream>
using namespace std;
// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( BoardTest );

void BoardTest::setUp(){
	m_builder1 = new BoardBuilder();
	m_builder2 = new BoardBuilder();
	m_builder3 = new BoardBuilder();
	m_builder4= new BoardBuilder();
	m_test_size = 10;
}

void BoardTest::tearDown(){
	delete m_builder1;
	delete m_builder2;
	delete m_builder3;
	delete m_builder4;
}

void BoardTest::sizeTest(){
	m_builder1->set_size(m_test_size);
	shared_ptr<Board> board1 = m_builder1->create();
	CPPUNIT_ASSERT_EQUAL(board1->get_width(), m_test_size);
	CPPUNIT_ASSERT_EQUAL(board1->get_height(), m_test_size);
}

void BoardTest::builderFailsTest(){
	CPPUNIT_ASSERT_THROW(m_builder2->create(), BoardBuilderException);
}

void BoardTest::createdEmpty(){
	m_builder3->set_size(m_test_size);
	shared_ptr<Board> board3 = m_builder3->create();
	for(int i = 0; i < board3->get_width(); ++i){
		for(int j = 0; j < board3->get_height(); ++j){
			CPPUNIT_ASSERT_EQUAL(board3->get(i,j).get_occupier()->get_type(),  CellOccupier::EMPTY );
		}
	}
}

void BoardTest::insertInRightCell(){
	m_builder4->set_size(m_test_size);
	shared_ptr<Board> board4 = m_builder4->create();
	Coord coord(3,3);
	shared_ptr<CellOccupier> cell_occupier(new SnakeOccupier());
	board4->insert(cell_occupier, coord);
	CPPUNIT_ASSERT_EQUAL(board4->get(coord).get_occupier(), cell_occupier);
}
