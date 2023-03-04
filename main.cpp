#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include "header/csvfileop.h"
using namespace std;

typedef enum GRE
{
  NOT_GRE,
  VERB,
  ADVERB,
  NOUN,
  ADJECTIVE
}GrammerEnum ;

typedef enum Time
{
  PAST,
  PRESENT,
  FUTURE
}Timeenum ;


std::string DecodeGrammer(GrammerEnum g)
{
  string ret="";
  switch(g)
  {
    case VERB:
      ret = "verb";
    break;

    case ADVERB:
      ret = "adverb";
    break;

    case NOUN:
      ret = "noun";
    break;

    case ADJECTIVE:
      ret = "adjective";
   break;

    case NOT_GRE:
       ret= "NOT Grammer";
    break;


  }
 return ret;
}

GrammerEnum SearchGrammerElements(std::string str)
{
   list<string> l = read_noun();

//   std::cout << "SearchGrammerElements" <<std::endl;
   GrammerEnum g = NOT_GRE;
  for (auto it = l.begin(); it != l.end(); ++it)
  {
    // cout << *it  << std::endl;
       if((*it).compare(0,(*it).length() -1 ,str) == 0)
       {
          
          //   cout <<"noun is:" << *it  << std::endl;
          //   cout <<"input word is:" << str  << std::endl;
            g = NOUN;
            return g;
       }

  }


   vector < vector<string> > vec = read_verb();

   for( auto it = vec.begin(); it != vec.end(); ++it)
   {
      for(auto it2 = (*it).begin(); it2 != (*it).end(); ++it2)
      {
          if((*it2).compare(0,(*it2).length() - 1 ,str) == 0)
          {
                  g = VERB;
                  return g;
          } 
      }
   }


  return g;
}

class PriorityList
{
 GrammerEnum pr;  
 string words;
 public:
  PriorityList(GrammerEnum p, string str) : pr(p), words(str) 
  {}
  bool operator <(const PriorityList & pl) const
  {
     return pr < pl.pr;
  }

};

class LPParser
{
   bool Pos_or_Neg_Arg;
   Timeenum t;
   bool ref;
   std::string action;
   std::string task;
   std::string properties;
   bool task_status;
   std::string extra_info;
public:
   bool search_dataset( std::string str, std::string &out) 
   {
       list< tuple<string,string> > tp_list = read_predefined_dataset();

       // std::cout << "   str is:" << str <<std::endl;
     for(auto l: tp_list)
     {
        auto [row1,row2] = l;
       
           // std::cout <<"Row1: "<< row1 << "   str is:" << str <<std::endl;
          if(row1.compare(0,str.length() ,str) == 0)
          {
         //  std::cout << "string in dataset is matching:" << row2 <<std::endl;
                  out = row2; 
                  return true;
          }
        
     }
      return false;
   }
   bool GenerateResponse(string input_str, list<PriorityList> ll)
   {
       std::string out;

        //   std::cout << "GenerateResponse: input_str is: " << input_str <<std::endl;
         if(search_dataset(input_str,out ) == true)
         {
              std::cout << out <<std::endl;
               return true;
         }
         else 
         {

              std::cout << "i don't know, please could you share?" <<std::endl;
              return false;
         }
        return false;
   }

};  


list<PriorityList> sentences_into_words(string input_str)
{
  stringstream ss(input_str);
  list<PriorityList> ll;
  string line_str = "";

   // std::cout << "sentences_into_words" <<std::endl;
  while(getline(ss, line_str, ' '))
   {
     //  std::cout << "getLine is: "<<std::endl ; 
       GrammerEnum g=SearchGrammerElements(line_str );
       ll.push_back(PriorityList(g,line_str));
     //  std::cout << "Line is: "<<line_str << " Grammer is:" << DecodeGrammer(g); 
   }
   ll.sort();

  return ll;
}

typedef enum Type
{
  EXCLAMATION,
  QUESTION,
  FULL_STOP
} type_str;

type_str ignore_str(std::string input_str, std::string &process_str)
{
  long unsigned i=0;
  int k=0;
  type_str t=QUESTION;
  
  while(i< input_str.length() -1)
  {
     if(input_str[i] != '?' || input_str[i] != '!' || input_str[i] != '.')
        process_str[k++] += tolower(input_str[i]);
     else if(input_str[i] == '?' ) 
       t= QUESTION;
     else if(input_str[i] == '!' )
       t= EXCLAMATION;
     else if(input_str[i] == '.' )
       t= FULL_STOP;

 
  }
 return t;
}

int main()
{
  
  std::cout << "       Welcome to StupidBot.ai       " <<std::endl;
  std::cout << "                                     " <<std::endl;
  std::cout << "             O         O             " <<std::endl;
  std::cout << "              \\       /             " <<std::endl;
  std::cout << "               \\     /              " <<std::endl;
  std::cout << "             ___\\___/___            " <<std::endl;
  std::cout << "            /-----------\\           " <<std::endl;
  std::cout << "           |  _________  |           " <<std::endl;
  std::cout << "           | |         | |           " <<std::endl;
  std::cout << "           | |  0   0  | |           " <<std::endl;
  std::cout << "           | |         | |           " <<std::endl;
  std::cout << "           | |_________| |           " <<std::endl;
  std::cout << "           |_____________|           " <<std::endl;
  std::cout << "              /       \\             " <<std::endl;
  std::cout << "             |         |             " <<std::endl;
  std::cout << "             |         |             " <<std::endl;
  std::cout << "             |         |             " <<std::endl;
  std::cout << "             \\        /             " <<std::endl;
  std::cout << "              \\______/              " <<std::endl;
  std::cout << " Hello, How are you ? What can i do for you?" <<std::endl;
  string input_str;
  string output_str;  
  while(1)
  {
    cout << "?>";
     getline(cin, input_str);;
    if(input_str == "exit")
      return 0;
    

    std::string raw_string;
   
       raw_string =input_str;
   //  std::string processes_str = "";
  //   ignore_str(input_str,processes_str);
   // std::cout << "raw_string is:" << raw_string <<std::endl;    

     list<PriorityList> l= sentences_into_words(input_str);
    LPParser *lp = new LPParser;
    if(true == lp->GenerateResponse(raw_string,l))
        continue;
 //    cout << output_str;
  }

 return 0;
}
