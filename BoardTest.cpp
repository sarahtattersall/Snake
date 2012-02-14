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
    m_builder4 = new BoardBuilder();
    m_builder5 = new BoardBuilder();
    m_builder6 = new BoardBuilder();
    m_builder7 = new BoardBuilder();
    m_builder8 = new BoardBuilder();
    m_snake_occupier = new SnakeTail();
    m_test_size = 10;
}

void BoardTest::tearDown(){
    delete m_builder1;
    delete m_builder2;
    delete m_builder3;
    delete m_builder4;
    delete m_builder5;
    delete m_builder6;
    delete m_builder7;
    delete m_builder8;
    delete m_snake_occupier;
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
    for(int i = 0; i < board3->get_height(); ++i){
        for(int j = 0; j < board3->get_width(); ++j){
            CPPUNIT_ASSERT_EQUAL(board3->lookup(Coord(j,i))->get_type(),  CellOccupier::EMPTY);
        }
    }
}

void BoardTest::insertInRightCell(){
    m_builder4->set_size(m_test_size);
    shared_ptr<Board> board4 = m_builder4->create();
    Coord coord(3,3);
    board4->insert(m_snake_occupier, coord);
    CPPUNIT_ASSERT_EQUAL(board4->lookup(coord)->get_type(), CellOccupier::SNAKE);
}

void BoardTest::correctMove(){
    m_builder5->set_size(m_test_size);
    shared_ptr<Board> board5 = m_builder5->create();
    board5->insert(m_snake_occupier, Coord(0,0));
    board5->move(m_snake_occupier, Coord(1,0));
    Coord coord = board5->find(m_snake_occupier);
    CPPUNIT_ASSERT_EQUAL( coord.get_x(), 1 );
    CPPUNIT_ASSERT_EQUAL( coord.get_y(), 0 );
}

void BoardTest::correctFind(){
    m_builder6->set_size(m_test_size);
    shared_ptr<Board> board6 = m_builder6->create();
    board6->insert(m_snake_occupier, Coord(0,0));
    Coord coord = board6->find(m_snake_occupier);
    CPPUNIT_ASSERT_EQUAL( coord.get_x(), 0 );
    CPPUNIT_ASSERT_EQUAL( coord.get_y(), 0 );
}

void BoardTest::correctLookup(){
    m_builder7->set_size(m_test_size);
    shared_ptr<Board> board7 = m_builder7->create();
    board7->insert(m_snake_occupier, Coord(0,0));
    CPPUNIT_ASSERT_EQUAL( board7->lookup(Coord(0,0)), m_snake_occupier );
}

void BoardTest::clear(){
    m_builder8->set_size(m_test_size);
    shared_ptr<Board> board8 = m_builder8->create();
    board8->clear();
    for( int i = 0; i < board8->get_height(); ++i){
        for( int j = 0; j < board8->get_width(); ++j){
            CPPUNIT_ASSERT_EQUAL(board8->lookup(Coord(j,i))->get_type(), CellOccupier::EMPTY);
        }
    }
}
