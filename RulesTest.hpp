#ifndef RULES_TEST_HPP
#define RULES_TEST_HPP
#include "Rules.hpp"
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
    shared_ptr<Board> m_test_board2;
    shared_ptr<Board> m_test_board3;
    shared_ptr<Board> m_test_board4;
    shared_ptr<Board> m_test_board5;
    shared_ptr<Board> m_test_board6;
    shared_ptr<Board> m_test_board7;
    shared_ptr<Board> m_test_board8;
    shared_ptr<Board> m_test_board9;
    int m_test_board_size;
    int m_test_player_count;
    int m_test_snake_size;
};

#endif 