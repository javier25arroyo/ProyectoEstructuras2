#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Trabajador.h"
 
using namespace std;

void escribirArchivo(const Trabajador& trabajador, const string& filename) {
    ofstream archivo(filename);

    if (!archivo) {
        cerr << "Error al abrir el archivo para escribir." << endl;
        return;
    }

    archivo << "Nombre: " << trabajador.nombre << endl;
    archivo << "Cedula: " << trabajador.cedula << endl;
    archivo << "Numero de nominas: " << trabajador.nominas.size() << endl; //anhade la cantidad de nominas al archivo

    for (const auto& nomina : trabajador.nominas) {
        archivo << "Horas Trabajadas: " << nomina.horasTrabajados << endl;
        archivo << "Horas Extras: " << nomina.horasExtras << endl;
        archivo << "Monto a Pagar: " << nomina.montoPagar << endl;
        archivo << "Deducciones: " << nomina.deducciones << endl;
    }

    archivo.close();
    cout << "Datos guardados en el archivo." << endl;
}

void leerArchivo(Trabajador& trabajador, const string& filename) {
    ifstream archivo(filename);

    if (!archivo) {
        cerr << "Error al abrir el archivo para leer." << endl;
        return;
    }

    string temp;

    getline(archivo, temp);  //lee la linea y al terminar brinca a la siguiente

    trabajador.nombre = temp.substr(temp.find(": ") + 2);    //busca el formato de : mas dos espacios

    getline(archivo, temp); 
    trabajador.cedula = temp.substr(temp.find(": ") + 2);

    getline(archivo, temp); 
    size_t numNominas = stoi(temp.substr(temp.find(": ") + 2));
    trabajador.nominas.resize(numNominas);

    for (auto& nomina : trabajador.nominas) {
        getline(archivo, temp); // Skip "Horas Trabajadas: "
        nomina.horasTrabajados = stoi(temp.substr(temp.find(": ") + 2));

        getline(archivo, temp); // Skip "Horas Extras: "
        nomina.horasExtras = stoi(temp.substr(temp.find(": ") + 2));

        getline(archivo, temp); // Skip "Monto a Pagar: "
        nomina.montoPagar = stod(temp.substr(temp.find(": ") + 2));

        getline(archivo, temp); // Skip "Deducciones: "
        nomina.deducciones = stod(temp.substr(temp.find(": ") + 2));
    }

    archivo.close();
    cout << "Datos leidos del archivo." << endl;
}