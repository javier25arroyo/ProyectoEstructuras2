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

    cout << "Ingrese la cedula del trabajador: ";
    getline(cin, trabajador.cedula);

    size_t numNominas;
    cout << "Ingrese el numero de nominas: ";
    cin >> numNominas;
    trabajador.nominas.resize(numNominas);

    //Ciclo para cada nomina a agregar // lo ideal es agregarla 1 por 1 cuando ya haya interfaz grafica
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
    //a

    string filename = trabajador.nombre+".txt";
    //escribir el archivo
    escribirArchivo(trabajador, filename);

    //Leer archivo
    Trabajador trabajadorLeido;
    leerArchivo(trabajadorLeido, filename);

    //Imprimir Datos
    cout << "Nombre: " << trabajadorLeido.nombre << endl;
    cout << "Cedula: " << trabajadorLeido.cedula << endl;
    for (const auto& nomina : trabajadorLeido.nominas) {
        cout <<"------Nomina------" << endl;
        cout << "Horas Trabajadas: " << nomina.horasTrabajados << endl;
        cout << "Horas Extras: " << nomina.horasExtras << endl;
        cout << "Monto a Pagar: " << nomina.montoPagar << endl;
        cout << "Deducciones: " << nomina.deducciones << endl;
    }
}
