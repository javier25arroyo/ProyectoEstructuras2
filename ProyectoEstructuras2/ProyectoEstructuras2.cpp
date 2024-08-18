// ProyectoEstructuras2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// 
// Este es el trabajo del Grupo conformado por Sebastian Chinchilla, Javier Arroyo y Daniel Echeverria
// 
// 
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <filesystem> 

#include "Archivos.h"
#include "Nomina.h"
#include "Trabajador.h"

using namespace std;
namespace fs = std::filesystem; 

// Función para cargar trabajadores desde los archivos al iniciar el programa
void cargarTrabajadores(vector<Trabajador>& trabajadores) {
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.path().extension() == ".txt") {
            Trabajador trabajador;
            leerArchivo(trabajador, entry.path().string());
            trabajadores.push_back(trabajador);
        }
    }
    cout << trabajadores.size() << " trabajadores cargados desde archivos.\n";
}

// Función para guardar todos los trabajadores en un archivo único al salir del programa
void guardarTodosLosTrabajadores(const vector<Trabajador>& trabajadores) {
    for (const auto& trabajador : trabajadores) {
        string filename = trabajador.nombre + ".txt";
        escribirArchivo(trabajador, filename);
    }
    cout << "Todos los trabajadores han sido guardados en archivos.\n";
}

int main() {
    vector<Trabajador> trabajadores;  // Vector que almacena todos los trabajadores

    cargarTrabajadores(trabajadores); // Cargar trabajadores desde archivos al iniciar

    int opcion;

    do {
        cout << "\nMenu:\n";
        cout << "1. Agregar trabajador\n";
        cout << "2. Buscar trabajador\n";
        cout << "3. Eliminar trabajador\n";
        cout << "4. Salir\n";
        cout << "-----------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Para limpiar el buffer de entrada

        switch (opcion) {
        case 1:
            agregarTrabajador(trabajadores);
            break;
        case 2:
            buscarTrabajador(trabajadores);
            break;
        case 3:
            eliminarTrabajador(trabajadores);
            break;
        case 4:
            cout << "Guardando todos los trabajadores y saliendo del programa.\n";
            guardarTodosLosTrabajadores(trabajadores);
            break;
        default:
            cout << "Opcion no valida, intente nuevamente.\n";
            break;
        }
    } while (opcion != 4);

    return 0;
}
