#ifndef TUPLA_H
#define TUPLA_H
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using std::vector;
using std::string;
using std::stringstream;

class Tupla{
    int id;
    vector<string> attrib;
    public:
        Tupla(){

        };
        void setAttrib(string str){
            attrib.push_back(str);
        };
        int getid(){
            return id;
        }
        vector<string> getAttrib(){
            return attrib;
        }
};

#endif