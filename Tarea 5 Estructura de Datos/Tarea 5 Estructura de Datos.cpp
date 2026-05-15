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

bool revisarOpcion(string opcion, int cantidad) {
    for (int i = 1; i <= cantidad; i++)
        if (opcion == to_string(i))
            return true;
    return false;
}

int regresarOpcionInt(string opcion) {
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
    Matriz<int>* matriz = new Matriz<int>(1, 1);
    string opcion, datos;
    while (corriendo) {
        try {
            if (primeraVez) { //Intente usar ASCII art pero se veia horrible
                int filas, columnas;
                cout << "Crea tu matriz:" << endl;
                cout << "Escriba la cantidad de filas: ";
                getline(cin, datos);
                filas = regresarOpcionInt(datos);
                cout << "Escriba la cantidad de columnas: ";
                getline(cin, datos);
                columnas = regresarOpcionInt(datos);
                delete matriz;
                matriz = new Matriz<int>(filas, columnas);
                matriz->setAll(0);
                primeraVez = false;
            }
            opcion = "0";
            matriz->print();
            cout << endl << "Escoja una opcion:" << endl;
            cout << "\t1. Obtener un valor (getValue())." << endl;
            cout << "\t2. Escribir un valor (setValue())." << endl;
            cout << "\t3. Obtener el numero de filas (getRows())." << endl;
            cout << "\t4. Obtener el numero de columnas (getColumns())." << endl;
            cout << "\t5. Escribir sobre todo (setAll())." << endl;
            cout << "\t6. Transponer (transpose())." << endl;
            cout << "\t7. Agregar fila (addRow())." << endl;
            cout << "\t8. Agregar columna (addColumn())." << endl;
            cout << "\t9. Borrar una fila (removeRow())." << endl;
            cout << "\t10. Borrar una columna (removeColumn())." << endl;
            cout << "\t11. Cargar la matriz con numeros aleatorios." << endl;
            cout << "\t12. Salir." << endl;
            cout << "Opcion: ";
            getline(cin, opcion);
            while (!revisarOpcion(opcion, 12)) {
                cout << "Escriba una opcion valida: ";
                getline(cin, opcion);
            }
            if (opcion == "1") {
                int filas, columnas;
                cout << "Escriba la posicion del valor en las filas: ";
                getline(cin, datos);
                filas = regresarOpcionInt(datos);
                cout << "Escriba la posicion del valor en las columnas: ";
                getline(cin, datos);
                columnas = regresarOpcionInt(datos);
                cout << "El valor es: " << matriz->getValue(filas, columnas) << endl;
            }
            else if (opcion == "2") {

            }
            else if (opcion == "12") {
                delete matriz;
                corriendo = false;
            }
            cout << endl;
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }
	return 0;
}
