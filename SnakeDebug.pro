TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .
CONFIG += qt debug

# Input
HEADERS += Board.hpp \
           Cell.hpp \
           CellOccupier.hpp \
           Coord.hpp \
           EmptyOccupier.hpp \
		   Log.hpp \
           Rules.hpp \
           Scene.hpp \
           Snake.hpp \
           SnakeDirection.hpp \
           SnakeException.hpp \
           SnakeObject.hpp \
           TextualBoardVisualiser.hpp
SOURCES += Board.cpp \
           Cell.cpp \
           CellOccupier.cpp \
           Coord.cpp \
           EmptyOccupier.cpp \
		   Log.cpp \
           main.cpp \
           Rules.cpp \
           Scene.cpp \
           Snake.cpp \
           SnakeObject.cpp \
           TextualBoardVisualiser.cpp
