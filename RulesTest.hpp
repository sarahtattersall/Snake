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
	CPPUNIT_TEST( noBoardSizeTest );
	CPPUNIT_TEST( noPlayerCountTest );
	CPPUNIT_TEST( noSnakeSizeTest );
	CPPUNIT_TEST( noVisualiserTest );
	CPPUNIT_TEST_SUITE_END();

public:
  	void setUp();
  	void tearDown();
protected:
	void noBoardSizeTest();
	void noPlayerCountTest();
	void noSnakeSizeTest();
	void noVisualiserTest();
private:
	RuleBuilder* m_builder1;
	RuleBuilder* m_builder2;
	RuleBuilder* m_builder3;
	RuleBuilder* m_builder4;
	int m_test_board_size;
	int m_test_player_count;
	int m_test_snake_size;
	shared_ptr<BoardVisualiserBuilder> m_test_visualiser;
};

#endif 