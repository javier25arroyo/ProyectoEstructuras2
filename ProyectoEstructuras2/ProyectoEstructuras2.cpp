// ProyectoEstructuras2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "Archivos.h"

#include "Nomina.h"
int main()
{
    Trabajador trabajador;

    // ingrese la data del trabajador
    cout << "Ingrese el nombre del trabajador: ";
    getline(cin, trabajador.nombre);

    cout << "Ingrese la cédula del trabajador: ";
    getline(cin, trabajador.cedula);

    size_t numNominas;
    cout << "Ingrese el número de nóminas: ";
    cin >> numNominas;
    trabajador.nominas.resize(numNominas);

    //Ciclo para cada nomina a agregar // lo ideal es agregarla 1 por 1 cuando ya haya interfaz grafica
    for (size_t i = 0; i < numNominas; ++i) {
        cout << "\nIngrese los datos para la nómina " << i + 1 << ":\n";

        cout << "Horas trabajadas: ";
        cin >> trabajador.nominas[i].horasTrabajados;

        cout << "Horas extras: ";
        cin >> trabajador.nominas[i].horasExtras;

        cout << "Monto a pagar: ";
        cin >> trabajador.nominas[i].montoPagar;

        cout << "Deducciones: ";
        cin >> trabajador.nominas[i].deducciones;
    }
    //a

    string filename = trabajador.nombre+".txt";
    //escribir el archivo
    escribirArchivo(trabajador, filename);

    //Leer archivo
    Trabajador trabajadorLeido;
    leerArchivo(trabajadorLeido, filename);

    //Imprimir Datos
    cout << "Nombre: " << trabajadorLeido.nombre << endl;
    cout << "Cédula: " << trabajadorLeido.cedula << endl;
    for (const auto& nomina : trabajadorLeido.nominas) {
        cout <<"------Nomina------" << endl;
        cout << "Horas Trabajadas: " << nomina.horasTrabajados << endl;
        cout << "Horas Extras: " << nomina.horasExtras << endl;
        cout << "Monto a Pagar: " << nomina.montoPagar << endl;
        cout << "Deducciones: " << nomina.deducciones << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
