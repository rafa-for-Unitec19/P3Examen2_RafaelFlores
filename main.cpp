#include <iostream>
#include <vector>
#include "Relacion.hpp"
#include "Tupla.hpp"

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
    }else{
        cout << "No puede tener Relaciones con nombres vacios" << endl;
    } 
}

void listarRelacion(){

}

void selector(){
    bool salida = false;
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
            }else{
                cout << "No hay nada que listar" << endl;
            }
            break;
        case 3:
            if (!relaciones.empty()){
                cout << "Opcion: Insertar Tupla" << endl;
            }else{
                cout << "No hay relaciones para insertar una Tupla" << endl;
            }
            break;
        case 4:
            salida = true;
            break;
        default:
            cout << "Opcion INvalida!!!!!" << endl;
            break;
        }
    }
}

int main(){
    selector();
    return EXIT_SUCCESS;
}