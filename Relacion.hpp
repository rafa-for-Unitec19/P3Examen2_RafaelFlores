#ifndef RELACION_H
#define RELACION_H
#include <string>
#include <vector>
#include "Tupla.hpp"

using std::string;
using std::vector;

class Relacion{
    string nombre;
    vector<string> encabezado;
    vector<Tupla> atributos;
    public:
        Relacion(string n): nombre(n){};
        void setEncabezado(string enc){
            this->encabezado.push_back(enc);
        };
        void initTupla(bool tipo = false){
            Tupla temp;
            if(tipo){
                temp.setOrigId();
            }
            this->atributos.push_back(temp);
        };
        void setTuplaAtt(string att){
            this->atributos[atributos.size() - 1].setAttrib(att);
        };
        void setTuplaId(int id){
            this->atributos[atributos.size() - 1].setId(id);
        };
        vector<string> getEncabezado(){
            return encabezado;
        };
        vector<Tupla> getTupla(){
            return atributos;
        };
        string getNombre(){
            return nombre;
        }
};

#endif