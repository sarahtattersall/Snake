TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += Board.hpp \
           BoardVisualiser.hpp \
           Cell.hpp \
           CellOccupier.hpp \
           Coord.hpp \
           EmptyOccupier.hpp \
           Rules.hpp \
           Scene.hpp \
           Snake.hpp \
           SnakeException.hpp \
           SnakeObject.hpp \
           TextualBoardVisualiser.hpp
SOURCES += Board.cpp \
           BoardVisualiser.cpp \
           Cell.cpp \
           CellOccupier.cpp \
           Coord.cpp \
           EmptyOccupier.cpp \
           main.cpp \
           Rules.cpp \
           Scene.cpp \
           Snake.cpp \
           SnakeObject.cpp \
           TextualBoardVisualiser.cpp