TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .
CONFIG += link_pkgconfig
PKGCONFIG += cppunit

# Input
HEADERS += Board.hpp \
           Cell.hpp \
           CellOccupier.hpp \
           Coord.hpp \
           CoordTest.hpp \
           Rules.hpp \
           Scene.hpp \
           SnakeDirection.hpp \
           SnakeException.hpp \
           Tests.hpp \
           TextualBoardVisualiser.hpp 
SOURCES += Board.cpp \
           Cell.cpp \
		   CellObject.cpp \
           CellOccupier.cpp \
           Coord.cpp \
           CoordTest.cpp \
           Rules.cpp \
           Scene.cpp \
           test.cpp \
           Tests.cpp \
           TextualBoardVisualiser.cpp 
