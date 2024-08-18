#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Trabajador.h"

using namespace std;

void buscarTrabajador(const Trabajador& trabajador) {
	cout << "Nombre del trabajador: " << trabajador.nombre << endl;
	cout << "Cedula del trabajador: " << trabajador.cedula << endl;

	for (const auto& nomina : trabajador.nominas) {
		cout << "Horas trabajadas: " << nomina.horasTrabajados << endl;
		cout << "Horas extra: " << nomina.horasExtras << endl;
		cout << "Monto a pagar: " << nomina.montoPagar << endl;
		cout << "Deducciones: " << nomina.deducciones << endl;
	}
}


