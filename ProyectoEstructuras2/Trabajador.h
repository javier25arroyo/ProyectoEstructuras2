#pragma once

#include <fstream>
#include <iostream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "Nomina.h"
#include "Archivos.h" 

using namespace std;

struct Trabajador {

    string nombre;
    string cedula;
    vector<Nomina> nominas;
};

// Método para crear un nuevo trabajador
void agregarTrabajador(vector<Trabajador>& trabajadores) {
    Trabajador trabajador;

    cout << "Ingrese el nombre del trabajador: ";
    getline(cin, trabajador.nombre);

    cout << "Ingrese la cedula del trabajador: ";
    getline(cin, trabajador.cedula);

    size_t numNominas;
    cout << "Ingrese el numero de nominas: ";
    cin >> numNominas;
    trabajador.nominas.resize(numNominas);

    for (size_t i = 0; i < numNominas; ++i) {
        cout << "\nIngrese los datos para la nomina " << i + 1 << ":\n";
        cout << "Horas trabajadas: ";
        cin >> trabajador.nominas[i].horasTrabajados;

        cout << "Horas extras: ";
        cin >> trabajador.nominas[i].horasExtras;

        cout << "Monto a pagar: ";
        cin >> trabajador.nominas[i].montoPagar;

        cout << "Deducciones: ";
        cin >> trabajador.nominas[i].deducciones;
    }

    trabajadores.push_back(trabajador);
    string filename = trabajador.nombre + ".txt";
    escribirArchivo(trabajador, filename);

    cout << "Trabajador agregado exitosamente.\n";
}

// Método para buscar un trabajador por cédula
void buscarTrabajador(const vector<Trabajador>& trabajadores) {
    string cedula;
    cout << "Ingrese la cedula del trabajador a buscar: ";
    getline(cin, cedula);

    for (const auto& trabajador : trabajadores) {
        if (trabajador.cedula == cedula) {
            cout << "Trabajador encontrado:\n";
            cout << "Nombre: " << trabajador.nombre << endl;
            cout << "Cedula: " << trabajador.cedula << endl;
            for (const auto& nomina : trabajador.nominas) {
                cout << "Horas Trabajadas: " << nomina.horasTrabajados << endl;
                cout << "Horas Extras: " << nomina.horasExtras << endl;
                cout << "Monto a Pagar: " << nomina.montoPagar << endl;
                cout << "Deducciones: " << nomina.deducciones << endl;
            }
            return;
        }
    }
    cout << "Trabajador no encontrado.\n";
}

// Método para eliminar un trabajador por cédula
void eliminarTrabajador(vector<Trabajador>& trabajadores) {
    string cedula;
    cout << "Ingrese la cedula del trabajador a eliminar: ";
    getline(cin, cedula);

    for (auto it = trabajadores.begin(); it != trabajadores.end(); ++it) {
        if (it->cedula == cedula) {
            trabajadores.erase(it);
            cout << "Trabajador eliminado exitosamente.\n";
            return;
        }
    }
    cout << "Trabajador no encontrado.\n";
}