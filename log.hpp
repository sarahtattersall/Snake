#ifndef LOG_HPP
#define LOG_HPP
#include <fstream>
#include <string>
using std::string;

using namespace std;

class Log {
  public:
    Log(char* filename);
    ~Log();
    void Write(char* logline);
    void Write(const char* logline, ...);
  private:
    ofstream m_stream;
};

#endif