TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .
CONFIG += qt debug

# Input
HEADERS += Board.hpp \
           BoardVisualiser.hpp \
           Cell.hpp \
		   CellObject.hpp \
           CellOccupier.hpp \
           Coord.hpp \
		   FoodObject.hpp \
           Rules.hpp \
           Scene.hpp \
           SnakeDirection.hpp \
           SnakeException.hpp \
           SnakeObject.hpp \
           TextualBoardVisualiser.hpp \
		   WallObject.hpp
SOURCES += Board.cpp \
           BoardVisualiser.cpp \
           Cell.cpp \
		   CellObject.cpp \
           CellOccupier.cpp \
           Coord.cpp \
		   FoodObject.cpp \
           main.cpp \
           Rules.cpp \
           Scene.cpp \
           SnakeObject.cpp \
           TextualBoardVisualiser.cpp \
		   WallObject.cpp
