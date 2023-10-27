#ifndef CLASES_H
#define CLASES_H

#include <iostream>
#include <ctime>
#include "libreria.h"

using namespace std;

struct clase
{
    u_int horario, idClase; //hora de la clase
    string nombre; //yoga, streching, etc.
    u_int cupo,   cupo_maximo; //cantidad de personas anotadas
    u_int* reservados;
};
typedef clase Clase;

bool hayCupo(idClase, Gimnasio gym);

#endif // LIBRERIA_GLOBAL_H
