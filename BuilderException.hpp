// standard exceptions
#include <iostream>
#include <exception>
using std::exception;

class BuilderException: public exception{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
};