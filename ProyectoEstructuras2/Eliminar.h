#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Trabajador.h"

using namespace std;

void eliminarTrabajador(Trabajador& trabajador) {
	trabajador.nombre = "";
	trabajador.cedula = "";
	trabajador.nominas.clear();
}