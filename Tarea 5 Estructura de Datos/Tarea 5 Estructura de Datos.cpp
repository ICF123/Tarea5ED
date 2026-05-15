#include <iostream>
#include <string>
#include <stdexcept>
#include "Matriz.h"

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::string;
using std::stoi;
using std::to_string;
using std::runtime_error;

//bool revisarOpcion(string opcion, int cantidad) {
//    for (int i = 1; i <= cantidad; i++)
//        if (opcion == to_string(i))
//            return true;
//    return false;
//}

int revisarOpcion(string opcion) {
    if (opcion == "")
        opcion = "N";
    for (int i = 0; i < opcion.length(); i++) {
        if (!isdigit(opcion[i])) {
            i = -1;
            cout << "Escriba una opcion valida: ";
            getline(cin, opcion);
            if (opcion == "")
                opcion = "N";
        }
    }
    return stoi(opcion);
}

int main(){
    bool corriendo = true;
    bool primeraVez = true;
    Matriz<int>* matriz;
    while (corriendo) {
        try {
            if (primeraVez) {
                string opcion;
                cout << "Escriba la cantidad de filas: ";
                getline(cin, opcion);
                int filas, columnas;
                filas = revisarOpcion(opcion);
                cout << "Escriba la cantidad de columnas: ";
                getline(cin, opcion);
                columnas = revisarOpcion(opcion);
            }
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }
    delete matriz;
	return 0;
}
