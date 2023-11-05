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
    u_int* reservados; // reservar el dato de la cantidad del array en el main sabiendo que clase es
};
typedef clase Clase;


#endif // LIBRERIA_GLOBAL_H
