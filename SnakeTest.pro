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
           EmptyOccupier.hpp \
           Rules.hpp \
           RulesTest.hpp \
           Scene.hpp \
           Snake.hpp \
           SnakeException.hpp \
           SnakeObject.hpp \
           TextualBoardVisualiser.hpp
SOURCES += Board.cpp \
           BoardTest.cpp \
           BoardVisualiser.cpp \
           Cell.cpp \
           CellOccupier.cpp \
           Coord.cpp \
           EmptyOccupier.cpp \
           Rules.cpp \
           RulesTest.cpp \
           Scene.cpp \
           Snake.cpp \
           SnakeObject.cpp \
           test.cpp \
           TextualBoardVisualiser.cpp
