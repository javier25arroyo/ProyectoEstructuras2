#include "Archivos.h"

void escribirArchivo(const Trabajador& trabajador, const std::string& filename) {
    std::ofstream archivo(filename);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo para escribir." << std::endl;
        return;
    }

    archivo << "Nombre: " << trabajador.nombre << std::endl;
    archivo << "Cedula: " << trabajador.cedula << std::endl;
    archivo << "Numero de nominas: " << trabajador.nominas.size() << std::endl;

    for (const auto& nomina : trabajador.nominas) {
        archivo << "Horas Trabajadas: " << nomina.horasTrabajados << std::endl;
        archivo << "Horas Extras: " << nomina.horasExtras << std::endl;
        archivo << "Monto a Pagar: " << nomina.montoPagar << std::endl;
        archivo << "Deducciones: " << nomina.deducciones << std::endl;
    }

    archivo.close();
    std::cout << "Datos guardados en el archivo." << std::endl;
}

void leerArchivo(Trabajador& trabajador, const std::string& filename) {
    std::ifstream archivo(filename);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo para leer." << std::endl;
        return;
    }

    std::string temp;
    getline(archivo, temp);
    trabajador.nombre = temp.substr(temp.find(": ") + 2);

    getline(archivo, temp);
    trabajador.cedula = temp.substr(temp.find(": ") + 2);

    getline(archivo, temp);
    size_t numNominas = std::stoi(temp.substr(temp.find(": ") + 2));
    trabajador.nominas.resize(numNominas);

    for (auto& nomina : trabajador.nominas) {
        getline(archivo, temp);
        nomina.horasTrabajados = std::stoi(temp.substr(temp.find(": ") + 2));

        getline(archivo, temp);
        nomina.horasExtras = std::stoi(temp.substr(temp.find(": ") + 2));

        getline(archivo, temp);
        nomina.montoPagar = std::stod(temp.substr(temp.find(": ") + 2));

        getline(archivo, temp);
        nomina.deducciones = std::stod(temp.substr(temp.find(": ") + 2));
    }

    archivo.close();
    std::cout << "Datos leidos del archivo." << std::endl;
}