TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .
CONFIG += qt debug

# Input
HEADERS += Board.hpp \
           Cell.hpp \
           CellObject.hpp \
           CellOccupier.hpp \
           Coord.hpp \
           Rules.hpp \
           Scene.hpp \
           SnakeDirection.hpp \
           SnakeException.hpp \
           TextualBoardVisualiser.hpp
SOURCES += Board.cpp \
           Cell.cpp \
           CellOccupier.cpp \
           Coord.cpp \
           main.cpp \
           Rules.cpp \
           Scene.cpp \
           TextualBoardVisualiser.cpp \
