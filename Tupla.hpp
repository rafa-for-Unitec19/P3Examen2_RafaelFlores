#ifndef TUPLA_H
#define TUPLA_H
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using std::vector;
using std::string;
using std::stringstream;

class Tupla{
    int id;
    vector<string> attrib;
    public:
        Tupla(){};
        void setId(int ident){
            this->id = ident;
        };
        void setOrigId(){
            id = randomId();
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
        int randomId(){
            srand(time(NULL));
            return (rand() % ((9999 - 1000) + 1)) + 1000;
        }
};

#endif