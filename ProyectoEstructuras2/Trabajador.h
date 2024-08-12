#pragma once

#include <fstream>
#include <iostream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "Nomina.h"

using namespace std;

struct Trabajador {

    string nombre;
    string cedula ;
    vector<Nomina>  nominas;
};