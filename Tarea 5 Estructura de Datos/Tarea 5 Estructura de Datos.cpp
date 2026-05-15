#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "Matriz.h"

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::string;
using std::stoi;
using std::to_string;
using std::runtime_error;
using std::srand;
using std::time;
using std::rand;

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
    srand(time(0));
    bool corriendo = true;
    bool primeraVez = true;
    Matriz<int>* matriz = new Matriz<int>(1, 1);
    string opcion, datos;
    int filas, columnas, value;
    while (corriendo) {
        try {
            if (primeraVez) { //Intente usar ASCII art pero se veia horrible
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
            cout << endl;
            if (opcion == "1") {
                cout << "Escriba la posicion del valor en las filas: ";
                getline(cin, datos);
                filas = regresarOpcionInt(datos);
                cout << "Escriba la posicion del valor en las columnas: ";
                getline(cin, datos);
                columnas = regresarOpcionInt(datos);
                cout << "El valor es: " << matriz->getValue(filas, columnas) << "." << endl;
            }
            else if (opcion == "2") {
                cout << "Escriba la posicion a escribir en las filas: ";
                getline(cin, datos);
                filas = regresarOpcionInt(datos);
                cout << "Escriba la posicion a escribir en las columnas: ";
                getline(cin, datos);
                columnas = regresarOpcionInt(datos);
                cout << "Escriba el valor a escribir: ";
                getline(cin, datos);
                value = regresarOpcionInt(datos);
                matriz->setValue(filas, columnas, value);
            }
            else if (opcion == "3") {
                cout << "El numero de filas es igual a: " << matriz->getRows() << "." << endl;
            }
            else if (opcion == "4") {
                cout << "El numero de columnas es igual a: " << matriz->getColumns() << "." << endl;
            }
            else if (opcion == "5") {
                cout << "Escriba el valor a escribir: ";
                getline(cin, datos);
                value = regresarOpcionInt(datos);
                matriz->setAll(value);
            }
            else if (opcion == "6") {
                matriz->transpose();
                cout << "La matriz ha sido transpuesta." << endl;
            }
            else if (opcion == "7") {
                cout << "Escriba el valor a escribir en la nueva fila: ";
                getline(cin, datos);
                value = regresarOpcionInt(datos);
                matriz->addRow(value);
            }
            else if (opcion == "8") {
                cout << "Escriba el valor a escribir en la nueva columna: ";
                getline(cin, datos);
                value = regresarOpcionInt(datos);
                matriz->addColumn(value);
            }
            else if (opcion == "9") {
                cout << "Escriba la posicion de la fila a borrar: ";
                getline(cin, datos);
                value = regresarOpcionInt(datos);
                matriz->removeRow(value);
            }
            else if (opcion == "10") {
                cout << "Escriba la posicion de la columna a borrar: ";
                getline(cin, datos);
                value = regresarOpcionInt(datos);
                matriz->removeColumn(value);
            }
            else if (opcion == "11") {
                int ranNum, maximo;
                cout << "Escriba el numero maximo a aleatorizar: ";
                getline(cin, datos);
                maximo = regresarOpcionInt(datos);
                for (int i = 0; i < matriz->getRows(); i++)
                    for (int j = 0; j < matriz->getColumns(); j++) {
                        ranNum = rand() % (maximo + 1);
                        matriz->setValue(i, j, ranNum);
                    }
                cout << "La matriz ha sido randomizada." << endl;
            }
            else if (opcion == "12") {
                cout << "Nos vemos.";
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
