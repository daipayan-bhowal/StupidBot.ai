#pragma once

#include <iostream>
#include <tuple>
#include <list>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
namespace fs = std::filesystem;

std::string readFile(fs::path path);

list <string> read_noun();

  vector <vector<string> >  read_verb();
  
list < tuple<string,string> >  read_predefined_dataset();

