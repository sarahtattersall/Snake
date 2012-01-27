#ifndef BOARD_TEST_HPP
#define BOARD_TEST_HPP
#include "Board.hpp"
#include <cppunit/extensions/HelperMacros.h>
#include "cppunit/TestCase.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"


class BoardTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE( BoardTest );
	CPPUNIT_TEST( sizeTest );
	CPPUNIT_TEST( builderFailsTest );
	CPPUNIT_TEST( createdEmpty );
	CPPUNIT_TEST( insertInRightCell );
	CPPUNIT_TEST( correctMove );
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
private:
	BoardBuilder* m_builder1;
	BoardBuilder* m_builder2;
	BoardBuilder* m_builder3;
	BoardBuilder* m_builder4;
    BoardBuilder* m_builder5;
    CellOccupier* m_snake_occupier;
	int m_test_size;
};

#endif 
