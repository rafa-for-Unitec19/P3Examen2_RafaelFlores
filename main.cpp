#include <iostream>
#include <vector>
#include <fstream>
#include "Relacion.hpp"
#include "Tupla.hpp"
#include <iomanip>

using namespace std;

vector<Relacion> relaciones;
const string boxLayer[2] = {"+----", "+---------------"};

int menu(){
    int op;
    cout << "Ingrese la opcion que mas desee:"
        << "\n\t1. Crear Relacion"
        << "\n\t2. Ver Relaciones"
        << "\n\t3. Insertar Tupla"
        << "\n\t4. Salir\n";
    cin >> op;
    cin.get();
    return op;
}

int menuRelacion(){
    int op;
    while (true){
        cout << "Ingrese la Relacion que desee:";
        for (size_t i = 0; i < relaciones.size(); i++){
            cout << "\n\t" << i << "." << relaciones[i].getNombre();
        }
        cout << "\n";
        cin >> op;
        if (op >= 0 && op < relaciones.size()){
            break;
        }else{
            cout << "No es una opcion valida!!" << endl;
        }
    }
    cin.get();
    return op;
}

void crearRelacion(){
    cout << "Ingrese el nombre de la Relacion" << endl;
    string nombre, datos;
    getline(cin, nombre);
    if (nombre != ""){
        Relacion temp(nombre);
        datos = "Id";
        temp.setEncabezado(datos);
        while(true){
            cout << "Ingrese los encabezados de su relacion, excepto -ID-" << endl;
            cout << "Escriba BREAK para terminar" << endl;
            getline(cin, datos);
            if (datos != ""){
                if (datos == "BREAK"){
                    break;
                }else{
                    if (datos == "ID" || datos == "id" || datos == "Id" || datos == "iD"){
                        cout << "No puede crear 2 encabezados con nombre ID" << endl;
                    }else{
                        temp.setEncabezado(datos);
                    }
                }
            }else{
                cout << "No puede tener Encabezados con nombres vacios" << endl;
            }
        }
        relaciones.push_back(temp);
    }else{
        cout << "No puede tener Relaciones con nombres vacios" << endl;
    } 
}

void crearTupla(int pos){
    relaciones[pos].initTupla(true);
    for (size_t i = 1; i < relaciones[pos].getEncabezado().size(); i++)
    {
        string entrada;
        cout << "Ingrese el atributo para:" << relaciones[pos].getEncabezado()[i] << endl;
        getline(cin, entrada);
        if (entrada != "")
        {
            relaciones[pos].setTuplaAtt(entrada);
        }else
        {
            cout << "No puede tener Atributos vacios" << endl;
        }
    }
}

void listarRelacion(int pos){
    for (size_t i = 0; i < relaciones[pos].getEncabezado().size(); i++){
        if (!i){
            cout << relaciones[pos].getNombre() << endl;
            cout << setfill(' ') << setw(6) << relaciones[pos].getEncabezado()[i] << " -> ";
        }else{
            cout << setfill(' ') << setw(15) << relaciones[pos].getEncabezado()[i] << " -> ";
        } 
    }
    cout << "|\n";
    if (relaciones[pos].getTupla().empty())
    {
        cout << "Esta Relacion no tiene Tuplas" << endl;
    }else{
        for (size_t i = 0; i < relaciones[pos].getTupla().size(); i++)
        {
            cout << "| " << setfill(' ') << setw(6) << relaciones[pos].getTupla()[i].getid() << " | ";
            for (size_t j = 0; j < relaciones[pos].getTupla()[i].getAttrib().size(); j++)
            {
                cout << setfill(' ') << setw(15) << relaciones[pos].getTupla()[i].getAttrib()[j] << " | ";
            }
            cout << endl;
        }
    }
}

void cargarRelaciones(){
    ifstream archivo("Relacion.txt");
    char linea[256];
    string nombre;
    int cont = 1;
    if(archivo.fail())
        cout << "Error al abrir el archivo Relacion.txt" << endl;
    else{
        while (!archivo.eof())
        {
            if ((cont % 2) != 0)
            {
                archivo.getline(linea, sizeof(linea), '\n');
                nombre = linea;
            }
            else
            {
                Relacion temp(nombre);
                archivo.getline(linea, sizeof(linea), '\n');
                string entrada(linea);

                std::istringstream tokenStream(entrada);
                while (getline(tokenStream, entrada, '+'))
                {
                    temp.setEncabezado(entrada);
                }

                relaciones.push_back(temp);
            }
            cont++;
        }
    }
    archivo.close();
}

void cargarTuplas(){
    for (size_t i = 0; i < relaciones.size(); i++)
    {        
        int cont = 0;
        ifstream archivo(relaciones[i].getNombre() + ".txt");
        char linea[256];
        if (archivo.fail())
            cout << "Error al abrir el archivo .txt" << endl;
        else
        {
            string entrada;
            while (!archivo.eof())
            {
                
                archivo.getline(linea, sizeof(linea), '\n');
                entrada = linea;
                std::istringstream tokenStream(entrada);
                while (getline(tokenStream, entrada, '+'))
                {
                    if (cont == 0)
                    {
                        int id = stoi(entrada);
                        relaciones[i].initTupla();
                        relaciones[i].setTuplaId(id);
                        cont++;
                    }else{
                        relaciones[i].setTuplaAtt(entrada);
                    }
                }
                cont = 0;
            }
        }
        archivo.close();
    }
}

void guardarRelaciones(){
    ofstream archivo("Relacion.txt");

    if(archivo.fail())
        cout << "Error al abrir el archivo Relacion.txt" << endl;
    else{    
        for (size_t i = 0; i < relaciones.size(); i++)
        {
            archivo << relaciones[i].getNombre() << "\n";
            for (size_t j = 0; j < relaciones[i].getEncabezado().size(); j++)
            {
                if (!j)
                {
                    archivo << relaciones[i].getEncabezado()[j];
                }else
                {
                    archivo << "+" << relaciones[i].getEncabezado()[j];
                }
            }
            archivo << "\n";
        }
    }
    archivo.close();
}

void guardarTuplas(){
    for (size_t i = 0; i < relaciones.size(); i++)
    {
        ofstream archivo(relaciones[i].getNombre() + ".txt");

        if (archivo.fail())
            cout << "Error al abrir el archivo Relacion.txt" << endl;
        else
        {
            for (size_t j = 0; j < relaciones[i].getTupla().size(); j++)
            {
                archivo << relaciones[i].getTupla()[j].getid();
                for (size_t k = 0; k < relaciones[i].getTupla()[j].getAttrib().size(); k++)
                {
                    archivo << "+" << relaciones[i].getTupla()[j].getAttrib()[k];
                }
                archivo << "\n";
            }
        }
        archivo.close();
    }
}

void selector(){
    bool salida = false;
    int pos;
    while(!salida){
        switch (menu())
        {
        case 1:
            cout << "Opcion: Crear Relacion" << endl;
            crearRelacion();
            break;
        case 2:
            if (!relaciones.empty()){
                cout << "Opcion: Listar Relacion" << endl;
                pos = menuRelacion();
                listarRelacion(pos);
            }else{
                cout << "No hay nada que listar" << endl;
            }
            break;
        case 3:
            if (!relaciones.empty()){
                cout << "Opcion: Insertar Tupla" << endl;
                pos = menuRelacion();
                crearTupla(pos);
            }else{
                cout << "No hay relaciones para insertar una Tupla" << endl;
            }
            break;
        case 4:
            salida = true;
            guardarRelaciones();
            guardarTuplas();
            break;
        default:
            cout << "Opcion INvalida!!!!!" << endl;
            break;
        }
    }
}

int main(){
    cargarRelaciones();
    cargarTuplas();
    selector();
    return EXIT_SUCCESS;
}