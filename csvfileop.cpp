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

std::string readFile(fs::path path)
{
    // Open the stream to 'lock' the file.
    std::ifstream f(path, std::ios::in | std::ios::binary);

    // Obtain the size of the file.
    const auto sz = fs::file_size(path);

    // Create a buffer.
    std::string result(sz, '\0');

    // Read the whole file into the buffer.
    f.read(result.data(), sz);

    return result;
}

list<string> read_noun()
{
   string line_str;
    fs::path p = "knowledge-db/noun.csv";
     string result = readFile(p);
    stringstream X(result);
     list<string> var_array;
     while(getline(X,line_str))
       {
           var_array.push_front(line_str);

       }


   return var_array;
}

vector<string> vec_strtokenizer(string str, char delim){
    vector<string> tokens;
    string temp = "";
    for(long unsigned i = 0; i < str.length(); i++){
        if(str[i] == delim || str[i] == '\n'){
            tokens.push_back(temp);
            temp = "";
        }
        else
            temp += str[i];           
    }
    tokens.push_back(temp);
    return tokens;
}


vector < vector<string> > read_verb()
{

 // std::cout <<"read_verb" <<std::endl;

   string line_str;
    fs::path p = "knowledge-db/verb.csv";
     string result = readFile(p);
    stringstream X(result);
     vector< vector<string> > final_vec;

 // std::cout <<"read_verb" <<std::endl;
     while(getline(X,line_str))
       {

         vector<string> vec; 

         vec = vec_strtokenizer(line_str, ','); 

         final_vec.push_back(vec);

       }


//  std::cout <<"read_varb" <<std::endl;

 return final_vec;
}

int tokenize_pos(string line_str,char delim)
{

      for(long unsigned int  i= 0; i<= line_str.length(); i++)
      {
          if(line_str[i] == delim)
            return i;
             
      }

  return 0;
}

list< tuple<string,string> >  read_predefined_dataset()
{
    string line_str;
    fs::path p = "knowledge-db/predefined_dataset.csv";
     string result = readFile(p);
    stringstream X(result);
    list< tuple<string,string> > tp_list;
 
    while(getline(X,line_str))
    {
       tuple<string,string> tp;
        int k=tokenize_pos(line_str, ',');
        string first=line_str.substr(0,k-1);
        string second= line_str.substr(k+1,line_str.length() - 1);
       tp = make_tuple(first,second);
       tp_list.push_front(tp);
    }  

  return tp_list;
}





