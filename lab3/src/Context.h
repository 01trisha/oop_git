#pragma once
#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;


class Context {
public:
  Context () {};
  typedef std::vector<pair<string, vector<string>>> ConverterContext;
  typedef vector<string> Strings;
  bool ParseConfig(const string &filename);
  ConverterContext getContext();

private:
  ConverterContext _context;
};
