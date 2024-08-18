#pragma once
#include <string>
#include <vector>
#include "Nomina.h"

struct Trabajador {
    std::string nombre;
    std::string cedula;
    std::vector<Nomina> nominas;
};

void agregarTrabajador(std::vector<Trabajador>& trabajadores);
void buscarTrabajador(const std::vector<Trabajador>& trabajadores);
void eliminarTrabajador(std::vector<Trabajador>& trabajadores);