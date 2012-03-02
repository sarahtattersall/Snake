#ifndef TESTS_HPP
#define TESTS_HPP
#include "Rules.hpp"
#include "Coord.hpp"
#include <cppunit/extensions/HelperMacros.h>
#include "cppunit/TestCase.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"


class RulesTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( RulesTest );
    CPPUNIT_TEST( noBoardTest );
    CPPUNIT_TEST( noPlayerCountTest );
    CPPUNIT_TEST( noSnakeSizeTest );
    CPPUNIT_TEST( correctMove );
    CPPUNIT_TEST( snakeBottomWallCrash );
    CPPUNIT_TEST( snakeLeftWallCrash );
    CPPUNIT_TEST( snakeRightWallCrash );
    CPPUNIT_TEST( snakeTopWallCrash );
    CPPUNIT_TEST( snakeOnSnakeCrash );
    CPPUNIT_TEST( rulesReset );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();
protected:
    void noBoardTest();
    void noPlayerCountTest();
    void noSnakeSizeTest();
    void noVisualiserTest();
    void correctMove();
    void snakeBottomWallCrash();
    void snakeRightWallCrash();
    void snakeLeftWallCrash();
    void snakeTopWallCrash();
    // Snakes are lined up next to each other
    // Rightmost snake crashes into snake next to it.
    void snakeOnSnakeCrash();
    void rulesReset();
private:
    shared_ptr<Board> make_board();
    RuleBuilder* m_builder1;
    RuleBuilder* m_builder2;
    RuleBuilder* m_builder3;
    RuleBuilder* m_builder4;
    RuleBuilder* m_builder5;
    RuleBuilder* m_builder6;
    RuleBuilder* m_builder7;
    RuleBuilder* m_builder8;
    RuleBuilder* m_builder9;
    RuleBuilder* m_builder10;
    RuleBuilder* m_builder11;
    shared_ptr<Board> m_test_board2;
    shared_ptr<Board> m_test_board3;
    shared_ptr<Board> m_test_board4;
    shared_ptr<Board> m_test_board5;
    shared_ptr<Board> m_test_board6;
    shared_ptr<Board> m_test_board7;
    shared_ptr<Board> m_test_board8;
    shared_ptr<Board> m_test_board9;
    shared_ptr<Board> m_test_board10;
    shared_ptr<Board> m_test_board11;
    int m_test_board_size;
    int m_test_player_count;
    int m_test_snake_size;
};

class BoardTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( BoardTest );
    CPPUNIT_TEST( sizeTest );
    CPPUNIT_TEST( builderFailsTest );
    CPPUNIT_TEST( createdEmpty );
    CPPUNIT_TEST( insertInRightCell );
    CPPUNIT_TEST( correctMove );
    CPPUNIT_TEST( correctFind );
    CPPUNIT_TEST( correctLookup );
    CPPUNIT_TEST( clear );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();
protected:
    void sizeTest();
    void builderFailsTest();
    void createdEmpty();
    void insertInRightCell();
    void correctMove();
    void correctFind();
    void correctLookup();
    void clear();
private:
    BoardBuilder* m_builder1;
    BoardBuilder* m_builder2;
    BoardBuilder* m_builder3;
    BoardBuilder* m_builder4;
    BoardBuilder* m_builder5;
    BoardBuilder* m_builder6;
    BoardBuilder* m_builder7;
    BoardBuilder* m_builder8;
    CellOccupier* m_snake_occupier;
    int m_test_size;
};

class SnakeTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( SnakeTest );
    CPPUNIT_TEST( iterator );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();
protected:
    void iterator();
private:
    shared_ptr<Rules> m_rules;
    shared_ptr<Board> m_board;
    int m_board_size;
    int m_player_count;
};

class CoordTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( CoordTest );
    CPPUNIT_TEST( createTest );
    CPPUNIT_TEST( wrapAroundXTest );
    CPPUNIT_TEST( wrapAroundYTest );
    CPPUNIT_TEST( moveTestVector );
    CPPUNIT_TEST( moveTestDirection );
    CPPUNIT_TEST( wrapAroundYMoveTest );
    CPPUNIT_TEST( wrapAroundXMoveTest );
    CPPUNIT_TEST_SUITE_END();

public:
    CoordTest() : m_width(10), m_height(10), m_space(m_width, m_height){};
    void setUp();
    void tearDown();
protected:
    void createTest();
    void moveTestVector();
    void moveTestDirection();
    void wrapAroundXTest();
    void wrapAroundYTest();
    void wrapAroundYMoveTest();
    void wrapAroundXMoveTest();
private:
    const int m_width;
    const int m_height;
    const CoordinateSpace m_space;
};
#endif 