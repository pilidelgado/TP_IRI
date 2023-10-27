#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <ctime>
#include "libreria.h"


typedef struct {
    u_int idClase;
    time_t fechaInscripcion;//a q hora se inscibio al curso
} Inscripcion;

typedef struct {
    u_int idCliente, cantInscripciones;//cantidad del array
    Inscripcion* CursosInscriptos;//array
} Asistencia;

u_int buscarPosAsistencia(Asistencia asist, u_int idCliente);

bool repetidos(Asistencia asist, u_int idCliente, u_int idClase);

void hayEspacio(Asistencia asist);

#endif // LIBRERIA_GLOBAL_H
