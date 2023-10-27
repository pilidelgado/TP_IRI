#ifndef GIMNASIO_H
#define GIMNASIO_H

#include <iostream>
#include <ctime>

using namespace std;
typedef unsigned int u_int;

struct clase
{
    u_int horario, idClase; //hora de la clase
    string nombre; //yoga, streching, etc.
    u_int cupo,   cupo_maximo; //cantidad de personas anotadas
    u_int* reservados;
};
typedef clase Clase;

//poner errores relacionados a las funciones de clases

#endif // LIBRERIA_GLOBAL_H
