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
	CPPUNIT_TEST_SUITE_END();

public:
  	void setUp();
  	void tearDown();
protected:
  	void sizeTest();
	void builderFailsTest();
private:
	BoardBuilder* m_builder1;
	BoardBuilder* m_builder2;
};

#endif 