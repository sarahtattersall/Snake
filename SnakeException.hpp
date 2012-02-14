// standard exceptions
#include <iostream>
#include <exception>
using std::exception;

// All inherit from SnakeException so can catch known exceptions in main
class SnakeException: public exception{
};

class RuleBuilderException : public SnakeException{
    virtual const char* what() const throw(){
        return "Error have not set all conditions of RuleBuilder.";
    }
};

class BoardBuilderException : public SnakeException{
    virtual const char* what() const throw(){
        return "Error have not set board size in BoardBuilder.";
    }
};

class SnakeTooBigException : public SnakeException{
    virtual const char* what() const throw(){
        return "Snake size is bigger than half the board.";
    }
};

class TextualBoardVisualiserBuilderException : public SnakeException{
    virtual const char* what() const throw(){
        return "Error havent sent board in textual board visualiser.";
    } 
};

class TextualRepresentationError : public SnakeException{
    virtual const char* what() const throw(){
        return "Cannot represent unknown type on board.";
    } 
};