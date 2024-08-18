#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Trabajador.h"

using namespace std;

void buscarTrabajador(const Trabajador& trabajador) {
	cout << "Nombre: " << trabajador.nombre << endl;
	cout << "Cedula: " << trabajador.cedula << endl;
	for (const auto& nomina : trabajador.nominas) {
		cout << "------Nomina------" << endl;
		cout << "Horas Trabajadas: " << nomina.horasTrabajados << endl;
		cout << "Horas Extras: " << nomina.horasExtras << endl;
		cout << "Monto a Pagar: " << nomina.montoPagar << endl;
		cout << "Deducciones: " << nomina.deducciones << endl;
	}
}