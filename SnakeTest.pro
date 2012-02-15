TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .
CONFIG += link_pkgconfig
PKGCONFIG += cppunit

# Input
HEADERS += Board.hpp \
		   BoardTest.hpp \
           BoardVisualiser.hpp \
           Cell.hpp \
		   CellObject.hpp \
           CellOccupier.hpp \
           Coord.hpp \
		   FoodObject.hpp \
           Rules.hpp \
		   RulesTest.hpp \
           Scene.hpp \
           SnakeDirection.hpp \
           SnakeException.hpp \
           SnakeObject.hpp \
           TextualBoardVisualiser.hpp \
		   WallObject.hpp
SOURCES += Board.cpp \
		   BoardTest.cpp \
           BoardVisualiser.cpp \
           Cell.cpp \
		   CellObject.cpp \
           CellOccupier.cpp \
           Coord.cpp \
		   FoodObject.cpp \
           Rules.cpp \
		   RulesTest.cpp \
           Scene.cpp \
           SnakeObject.cpp \
           test.cpp \
           TextualBoardVisualiser.cpp \
		   WallObject.cpp
