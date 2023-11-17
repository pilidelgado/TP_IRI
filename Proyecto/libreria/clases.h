#ifndef CLASES_H
#define CLASES_H

#include <iostream>
#include <ctime>
#include "libreria.h"

using namespace std;

struct clase
{
    u_int horario, cupo,   cupo_maximo; //cantidad de personas anotadas
    int idClase; //hora de la clase
    string nombre; //yoga, streching, etc.

    int* reservados; // reservar el dato de la cantidad del array en el main sabiendo que clase es
};//array reservados: esta inicializado en 0, y se va guartdando el idCliente segun las inscrip
typedef clase Clase;


#endif // LIBRERIA_GLOBAL_H
