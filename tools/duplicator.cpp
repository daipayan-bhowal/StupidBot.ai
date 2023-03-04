#include <iostream>

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



int main()
{
   string line_str;
    fs::path p = "../knowledge-db/noun.csv"; 
     string result = readFile(p);
    stringstream X(result);
     string var_array[1435];
     int i=0;
     while(getline(X,line_str))
       {  
           var_array[i++] = line_str;

           for(int j=0;j <i-1; j++)
           {
              if( var_array[j] == line_str)
               {
                  cout  << line_str << endl;
                   cout <<" "<< i <<" " << j <<std::endl;
               }

           }
       }



}
