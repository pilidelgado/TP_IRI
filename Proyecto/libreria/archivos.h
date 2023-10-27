#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <ctime>
#include "libreria.h" //error!!!!!


typedef struct {
    u_int idClase;
    time_t fechaInscripcion;//a q hora se inscibio al curso
} Inscripcion;

typedef struct {
    u_int idCliente, cantInscripciones;//cantidad del array
    Inscripcion* CursosInscriptos;//array
} Asistencia;

u_int buscarPosAsistencia(Asistencia* Asistencia, u_int idCliente);

bool repetidos(Asistencia* Asistencia, u_int idCliente, u_int idClase);

void hayEspacio(Asistencia[posCliente]);

#endif // LIBRERIA_GLOBAL_H
