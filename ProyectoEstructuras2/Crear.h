#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Archivos.h"
#include "Trabajador.h"

using namespace std;

void crearTrabajador(vector<Trabajador>& trabajadores) {
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
	//a

	string filename = trabajador.nombre + ".txt";
	//escribir el archivo
	escribirArchivo(trabajador, filename);

	//Leer archivo
	Trabajador trabajadorLeido;
	leerArchivo(trabajadorLeido, filename);

	//Imprimir Datos
	cout << "Nombre: " << trabajadorLeido.nombre << endl;
	cout << "Cedula: " << trabajadorLeido.cedula << endl;
	for (const auto& nomina : trabajadorLeido.nominas) {
		cout << "------Nomina------" << endl;
		cout << "Horas Trabajadas: " << nomina.horasTrabajados << endl;
		cout << "Horas Extras: " << nomina.horasExtras << endl;
		cout << "Monto a Pagar: " << nomina.montoPagar << endl;
		cout << "Deducciones: " << nomina.deducciones << endl;
	}
}

