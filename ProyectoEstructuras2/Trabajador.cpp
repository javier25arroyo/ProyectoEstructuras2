#include "Trabajador.h"
#include "Archivos.h"
#include <iostream>

void agregarTrabajador(std::vector<Trabajador>& trabajadores) {
    Trabajador trabajador;

    std::cout << "Ingrese el nombre del trabajador: ";
    std::getline(std::cin, trabajador.nombre);

    std::cout << "Ingrese la cedula del trabajador: ";
    std::getline(std::cin, trabajador.cedula);

    size_t numNominas;
    std::cout << "Ingrese el numero de nominas: ";
    std::cin >> numNominas;
    trabajador.nominas.resize(numNominas);

    for (size_t i = 0; i < numNominas; ++i) {
        std::cout << "\nIngrese los datos para la nomina " << i + 1 << ":\n";
        std::cout << "Horas trabajadas: ";
        std::cin >> trabajador.nominas[i].horasTrabajados;

        std::cout << "Horas extras: ";
        std::cin >> trabajador.nominas[i].horasExtras;

        std::cout << "Monto a pagar: ";
        std::cin >> trabajador.nominas[i].montoPagar;

        std::cout << "Deducciones: ";
        std::cin >> trabajador.nominas[i].deducciones;
    }

    trabajadores.push_back(trabajador);
    std::string filename = trabajador.nombre + ".txt";
    escribirArchivo(trabajador, filename);

    std::cout << "Trabajador agregado exitosamente.\n";
}

void buscarTrabajador(const std::vector<Trabajador>& trabajadores) {
    std::string cedula;
    std::cout << "Ingrese la cedula del trabajador a buscar: ";
    std::getline(std::cin, cedula);

    for (const auto& trabajador : trabajadores) {
        if (trabajador.cedula == cedula) {
            std::cout << "Trabajador encontrado:\n";
            std::cout << "Nombre: " << trabajador.nombre << std::endl;
            std::cout << "Cedula: " << trabajador.cedula << std::endl;

            int contador = 1; // Inicializamos un contador para enumerar las nóminas

            for (const auto& nomina : trabajador.nominas) {
                std::cout << "Nomina " << contador << ":\n"; // Imprimimos el número de la nómina
                std::cout << "Horas Trabajadas: " << nomina.horasTrabajados << std::endl;
                std::cout << "Horas Extras: " << nomina.horasExtras << std::endl;
                std::cout << "Monto a Pagar: " << nomina.montoPagar << std::endl;
                std::cout << "Deducciones: " << nomina.deducciones << std::endl;
                contador++; // Incrementamos el contador para la siguiente nómina
            }
            return;
        }
    }
    std::cout << "Trabajador no encontrado.\n";
}


void eliminarTrabajador(std::vector<Trabajador>& trabajadores) {
    std::string cedula;
    std::cout << "Ingrese la cedula del trabajador a eliminar: ";
    std::getline(std::cin, cedula);

    for (auto it = trabajadores.begin(); it != trabajadores.end(); ++it) {
        if (it->cedula == cedula) {
            trabajadores.erase(it);
            std::cout << "Trabajador eliminado exitosamente.\n";
            return;
        }
    }
    std::cout << "Trabajador no encontrado.\n";
}