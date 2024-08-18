#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Trabajador.h"

void escribirArchivo(const Trabajador& trabajador, const std::string& filename);
void leerArchivo(Trabajador& trabajador, const std::string& filename);