#include "CoordTest.hpp"
// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( CoordTest );

void CoordTest::setUp(){
    Coord::set_board_dimensions(10,10);
}

void CoordTest::tearDown(){
}

void CoordTest::createTest(){
    Coord coord(1,1);
    CPPUNIT_ASSERT_EQUAL(1, coord.get_x());
    CPPUNIT_ASSERT_EQUAL(1, coord.get_y());
}

void CoordTest::addTest(){
    Coord coord1(0,1);
    Coord coord2(0,1);
    Coord new_coord = coord1 + coord2;
    CPPUNIT_ASSERT_EQUAL(0, new_coord.get_x());
    CPPUNIT_ASSERT_EQUAL(2, new_coord.get_y());
}

void CoordTest::subtractTest(){
    Coord coord1(0,1);
    Coord coord2(0,1);
    Coord new_coord = coord1 - coord2;
    CPPUNIT_ASSERT_EQUAL(0, new_coord.get_x());
    CPPUNIT_ASSERT_EQUAL(0, new_coord.get_y());
}

void CoordTest::wrapAroundXTest(){
    Coord coord1(0,0);
    Coord coord2(1,0);
    Coord new_coord = coord1 - coord2;
    CPPUNIT_ASSERT_EQUAL(9, new_coord.get_x());
    CPPUNIT_ASSERT_EQUAL(0, new_coord.get_y());
}

void CoordTest::wrapAroundYTest(){
    Coord coord1(9,9);
    Coord coord2(0,1);
    Coord new_coord = coord1 + coord2;
    CPPUNIT_ASSERT_EQUAL(9, new_coord.get_x());
    CPPUNIT_ASSERT_EQUAL(0, new_coord.get_y());
}

void CoordTest::moveTest(){
    Coord coord1(9,9);
    Coord new_coord = coord1.move(Coord::UP);
    CPPUNIT_ASSERT_EQUAL(9, new_coord.get_x());
    CPPUNIT_ASSERT_EQUAL(8, new_coord.get_y());
}

void CoordTest::wrapAroundYMoveTest(){
    Coord coord1(9,9);
    Coord new_coord = coord1.move(Coord::DOWN);
    CPPUNIT_ASSERT_EQUAL(9, new_coord.get_x());
    CPPUNIT_ASSERT_EQUAL(0, new_coord.get_y());
}

void CoordTest::wrapAroundXMoveTest(){
    Coord coord1(0,0);
    Coord new_coord = coord1.move(Coord::LEFT);
    CPPUNIT_ASSERT_EQUAL(9, new_coord.get_x());
    CPPUNIT_ASSERT_EQUAL(0, new_coord.get_y());
}
