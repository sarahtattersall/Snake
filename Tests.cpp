#include "Tests.hpp"
#include "boost/shared_ptr.hpp"
#include "SnakeException.hpp"
#include "CellOccupier.hpp"
#include "TextualBoardVisualiser.hpp"
#include <iostream>
using namespace std;
using boost::shared_ptr;
// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( RulesTest );
CPPUNIT_TEST_SUITE_REGISTRATION( BoardTest );
CPPUNIT_TEST_SUITE_REGISTRATION( SnakeTest );
CPPUNIT_TEST_SUITE_REGISTRATION( CoordTest );

RulesTest::RulesTest() : m_builder1(new RuleBuilder()), m_builder2(new RuleBuilder()), 
  m_builder3(new RuleBuilder()), m_builder4(new RuleBuilder()), m_builder5(new RuleBuilder()), 
  m_builder6(new RuleBuilder()), m_builder7(new RuleBuilder()), m_builder8(new RuleBuilder()),
  m_builder9(new RuleBuilder()), m_builder10(new RuleBuilder()), m_builder11(new RuleBuilder()) 
  {}

void RulesTest::setUp(){
    m_test_board_size = 20;
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
    m_test_board10 = make_board();
    m_test_board11 = make_board();
}

shared_ptr<Board> RulesTest::make_board(){
    BoardBuilder board_builder;
    board_builder.set_size(m_test_board_size);
    return board_builder.create();
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
    bool result = rules->move_snake(1, Vector::DOWN);
    CPPUNIT_ASSERT_EQUAL(result, true);
    //SARAH: How can assure board has moved snake without access to board??
}

void RulesTest::snakeBottomWallCrash(){
    m_builder5->set_board(m_test_board5);
    m_builder5->set_player_count(m_test_player_count);
    m_builder5->set_snake_size(m_test_snake_size);
    shared_ptr<Rules> rules = m_builder5->create();
    bool result;
    // -2 as perimeter is around outside of board and still want a space 
    // to move down
    for(int i = 0; i < ((m_test_board_size/2) - m_test_snake_size - 1 ); ++i){
        result = rules->move_snake(0, Vector::DOWN);
        CPPUNIT_ASSERT_EQUAL(result, true);
    }
    result = rules->move_snake(0, Vector::DOWN);
    CPPUNIT_ASSERT_EQUAL(result, false);
}

void RulesTest::snakeRightWallCrash(){
    m_builder6->set_board(m_test_board6);
    m_builder6->set_player_count(m_test_player_count);
    m_builder6->set_snake_size(m_test_snake_size);
    shared_ptr<Rules> rules = m_builder6->create();
    bool result;
    for(int i = 0; i < ((m_test_board_size/2) - 2); ++i){
        result = rules->move_snake(0, Vector::RIGHT);
        CPPUNIT_ASSERT_EQUAL(result, true);
    }
    result = rules->move_snake(0, Vector::RIGHT);
    CPPUNIT_ASSERT_EQUAL(result, false);
}

void RulesTest::snakeLeftWallCrash(){
    m_builder7->set_board(m_test_board7);
    // Other snake gets in way and know 2 snakes works.
    m_builder7->set_player_count(1);
    m_builder7->set_snake_size(m_test_snake_size);
    shared_ptr<Rules> rules = m_builder7->create();
    bool result;
    for(int i = 0; i < ((m_test_board_size/2) - 1); ++i){
        result = rules->move_snake(0, Vector::LEFT);
        CPPUNIT_ASSERT_EQUAL(result, true);
    }
    result = rules->move_snake(0, Vector::LEFT);
    CPPUNIT_ASSERT_EQUAL(result, false);
}

void RulesTest::snakeTopWallCrash(){
    m_builder8->set_board(m_test_board8);
    m_builder8->set_player_count(m_test_player_count);
    m_builder8->set_snake_size(m_test_snake_size);
    shared_ptr<Rules> rules = m_builder8->create();
    bool result;
    result = rules->move_snake(0, Vector::RIGHT);
    for(int i = 0; i < ((m_test_board_size/2) + m_test_snake_size -2); ++i){
        result = rules->move_snake(0, Vector::UP);
        CPPUNIT_ASSERT_EQUAL(result, true);
    }
    result = rules->move_snake(0, Vector::UP);
    CPPUNIT_ASSERT_EQUAL(result, false);
}

void RulesTest::snakeOnSnakeCrash(){
    m_builder9->set_board(m_test_board9);
    m_builder9->set_player_count(m_test_player_count);
    m_builder9->set_snake_size(m_test_snake_size);
    shared_ptr<Rules> rules = m_builder9->create();
    bool result;
    result = rules->move_snake(0, Vector::LEFT);
    CPPUNIT_ASSERT_EQUAL(result, false);
}

void RulesTest::rulesReset(){
    m_builder10->set_board(m_test_board10);
    m_builder10->set_player_count(m_test_player_count);
    m_builder10->set_snake_size(m_test_snake_size);
    shared_ptr<Rules> rules_10 = m_builder10->create();
    m_builder11->set_board(m_test_board11);
    m_builder11->set_player_count(m_test_player_count);
    m_builder11->set_snake_size(m_test_snake_size);
    shared_ptr<Rules> rules_11 = m_builder11->create();
    
    
    
    Coord board_middle(m_test_board10->get_width()/2, m_test_board10->get_height()/2);
    CPPUNIT_ASSERT_EQUAL(CellOccupier::SNAKE,m_test_board10->lookup(Coord(board_middle.get_x(),board_middle.get_y() + 1))->get_type());
    CPPUNIT_ASSERT_EQUAL(CellOccupier::SNAKE,m_test_board10->lookup(Coord(board_middle.get_x(),board_middle.get_y()))->get_type());
    
    
    bool result;
    result = rules_10->move_snake(0, Vector::RIGHT);
    for(int i = 0; i < ((m_test_board_size/2) + m_test_snake_size -2); ++i){
        result = rules_10->move_snake(0, Vector::UP);
        CPPUNIT_ASSERT_EQUAL(result, true);
    }
    result = rules_10->move_snake(0, Vector::UP);
    CPPUNIT_ASSERT_EQUAL(result, false);
    rules_10->reset();
    CPPUNIT_ASSERT_EQUAL(CellOccupier::SNAKE,m_test_board10->lookup(Coord(board_middle.get_x(),board_middle.get_y() + 1))->get_type());
    CPPUNIT_ASSERT_EQUAL(CellOccupier::SNAKE,m_test_board10->lookup(Coord(board_middle.get_x(),board_middle.get_y()))->get_type());
    
    for(int i = 0; i < m_test_board10->get_height(); ++i){
        for(int j = 0; j < m_test_board10->get_width(); ++j){
            Coord coord(j,i);
            if(m_test_board10->lookup(coord)->get_type() == CellOccupier::SNAKE){
                CPPUNIT_ASSERT_EQUAL( m_test_board11->lookup(coord)->get_type(),
                m_test_board10->lookup(coord)->get_type());
            }
        }
    }
}

BoardTest::BoardTest() : m_builder1(new BoardBuilder()), m_builder2(new BoardBuilder()), 
  m_builder3(new BoardBuilder()), m_builder4(new BoardBuilder()), m_builder5(new BoardBuilder()), 
  m_builder6(new BoardBuilder()), m_builder7(new BoardBuilder()), m_builder8(new BoardBuilder()),
  m_snake_occupier(new SnakeTail()) {};

void BoardTest::setUp(){
    m_test_size = 10;
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
    board4->insert(m_snake_occupier.get(), coord);
    CPPUNIT_ASSERT_EQUAL(board4->lookup(coord)->get_type(), CellOccupier::SNAKE);
}

void BoardTest::correctMove(){
    m_builder5->set_size(m_test_size);
    shared_ptr<Board> board5 = m_builder5->create();
    board5->insert(m_snake_occupier.get(), Coord(0,0));
    board5->move(m_snake_occupier.get(), Coord(1,0));
    Coord coord = board5->find(m_snake_occupier.get());
    CPPUNIT_ASSERT_EQUAL( coord.get_x(), 1 );
    CPPUNIT_ASSERT_EQUAL( coord.get_y(), 0 );
}

void BoardTest::correctFind(){
    m_builder6->set_size(m_test_size);
    shared_ptr<Board> board6 = m_builder6->create();
    board6->insert(m_snake_occupier.get(), Coord(0,0));
    Coord coord = board6->find(m_snake_occupier.get());
    CPPUNIT_ASSERT_EQUAL(coord.get_x(), 0);
    CPPUNIT_ASSERT_EQUAL(coord.get_y(), 0);
}

void BoardTest::correctLookup(){
    m_builder7->set_size(m_test_size);
    shared_ptr<Board> board7 = m_builder7->create();
    board7->insert(m_snake_occupier.get(), Coord(0,0));
    const CellOccupier* occupier = m_snake_occupier.get();
    CPPUNIT_ASSERT_EQUAL(board7->lookup(Coord(0,0)), occupier);
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

void SnakeTest::setUp(){
    m_board_size = 20;
    m_player_count = 1;
    BoardBuilder board_builder;
    board_builder.set_size(m_board_size);
    m_board =  board_builder.create();
    RuleBuilder rule_builder;
    rule_builder.set_board(m_board);
    rule_builder.set_player_count(m_player_count);
    m_rules = rule_builder.create();
}


void SnakeTest::iterator(){
    const Snake* snake_head = m_rules->get_snake(0);
    SnakeIterator itr = snake_head->begin();
    const CellOccupier* res = *itr;
    const CellOccupier* head = snake_head;
    CPPUNIT_ASSERT_EQUAL(head, res);
}

void CoordTest::setUp(){
}

void CoordTest::createTest(){
    Coord coord(1,1);
    CPPUNIT_ASSERT_EQUAL(1, coord.get_x());
    CPPUNIT_ASSERT_EQUAL(1, coord.get_y());
}

void CoordTest::wrapAroundXTest(){
    Coord coord(0,0);
    Vector vec(-1,0);
    Coord new_coord = m_space.move(coord, vec);
    CPPUNIT_ASSERT_EQUAL(9, new_coord.get_x());
    CPPUNIT_ASSERT_EQUAL(0, new_coord.get_y());
}

void CoordTest::wrapAroundYTest(){
    Coord coord(9,9);
    Vector vec(0,1);
    Coord new_coord = m_space.move(coord, vec);
    CPPUNIT_ASSERT_EQUAL(9, new_coord.get_x());
    CPPUNIT_ASSERT_EQUAL(0, new_coord.get_y());
}

void CoordTest::moveTestVector(){
    Coord coord(0,1);
    Vector vec(0,1);
    Coord new_coord = m_space.move(coord, vec);
    CPPUNIT_ASSERT_EQUAL(0, new_coord.get_x());
    CPPUNIT_ASSERT_EQUAL(2, new_coord.get_y());
    new_coord = m_space.move(vec, coord);
    CPPUNIT_ASSERT_EQUAL(0, new_coord.get_x());
    CPPUNIT_ASSERT_EQUAL(2, new_coord.get_y());
}

void CoordTest::moveTestDirection(){
    Coord coord(9,9);
    Coord new_coord = m_space.move(coord, Vector::UP);
    CPPUNIT_ASSERT_EQUAL(9, new_coord.get_x());
    CPPUNIT_ASSERT_EQUAL(8, new_coord.get_y());
    new_coord = m_space.move(Vector::UP, coord);
    CPPUNIT_ASSERT_EQUAL(9, new_coord.get_x());
    CPPUNIT_ASSERT_EQUAL(8, new_coord.get_y());
}

void CoordTest::wrapAroundYMoveTest(){
    Coord coord(9,9);
    Coord new_coord = m_space.move(coord, Vector::DOWN);
    CPPUNIT_ASSERT_EQUAL(9, new_coord.get_x());
    CPPUNIT_ASSERT_EQUAL(0, new_coord.get_y());
}

void CoordTest::wrapAroundXMoveTest(){
    Coord coord(0,0);
    Coord new_coord = m_space.move(coord, Vector::LEFT);
    CPPUNIT_ASSERT_EQUAL(9, new_coord.get_x());
    CPPUNIT_ASSERT_EQUAL(0, new_coord.get_y());
}