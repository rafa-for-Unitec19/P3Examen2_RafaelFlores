#include <iostream>
#include <vector>
#include "Relacion.hpp"

using namespace std;

vector<Relacion> relaciones;

int menu(){
    int op;
    cout << "Ingrese la opcion que mas desee:"
        << "\n\t1. Crear Relacion"
        << "\n\t2. Ver Relaciones"
        << "\n\t3. Insertar Tupla"
        << "\n\t4. Salir\n";
    cin >> op;
    return op;
}

void selector(){
    bool salida = false;
    while(!salida){
        switch (menu())
        {
        case 1:
            /* code */
            break;
        case 2:
            if (!relaciones.empty()){
                /* code */
            }else{
                cout << "No hay nada que listar" << endl;
            }
            break;
        case 3:
            if (!relaciones.empty()){
                /* code */
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