#ifndef COORD_TEST_HPP
#define COORD_TEST_HPP
#include "Coord.hpp"
#include <cppunit/extensions/HelperMacros.h>
#include "cppunit/TestCase.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"


class CoordTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( CoordTest );
    CPPUNIT_TEST( createTest );
    CPPUNIT_TEST( addTest );
    CPPUNIT_TEST( subtractTest );
    CPPUNIT_TEST( wrapAroundXTest );
    CPPUNIT_TEST( wrapAroundYTest );
    CPPUNIT_TEST( moveTest );
    CPPUNIT_TEST( wrapAroundYMoveTest );
    CPPUNIT_TEST( wrapAroundXMoveTest );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();
protected:
    void createTest();
    void addTest();
    void subtractTest();
    void wrapAroundXTest();
    void wrapAroundYTest();
    void moveTest();
    void wrapAroundYMoveTest();
    void wrapAroundXMoveTest();
//private:

};

#endif 
