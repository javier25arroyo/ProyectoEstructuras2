#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Trabajador.h"

using namespace std;

void crearTrabajador(Trabajador& trabajador, const string& filename) {
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

