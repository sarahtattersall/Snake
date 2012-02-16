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
           CellOccupier.hpp \
           Coord.hpp \
           CoordTest.hpp \
           Rules.hpp \
		   RulesTest.hpp \
           Scene.hpp \
           SnakeDirection.hpp \
           SnakeException.hpp \
           TextualBoardVisualiser.hpp 
SOURCES += Board.cpp \
		   BoardTest.cpp \
           BoardVisualiser.cpp \
           Cell.cpp \
		   CellObject.cpp \
           CellOccupier.cpp \
           Coord.cpp \
           CoordTest.cpp \
           Rules.cpp \
		   RulesTest.cpp \
           Scene.cpp \
           test.cpp \
           TextualBoardVisualiser.cpp 
