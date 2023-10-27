#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <ctime>
#include "libreria.h" //error!!!!!

typedef unsigned int u_int;

typedef struct {
    u_int idClase;
    time_t fechaInscripcion;//a q hora se inscibio al curso
} Inscripcion;

typedef struct {
    u_int idCliente, cantInscripciones;//cantidad del array
    Inscripcion* CursosInscriptos;//array
} Asistencia;

#endif // LIBRERIA_GLOBAL_H
