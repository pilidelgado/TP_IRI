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

struct misAsistencias {
    u_int tamAsist;//cantidad del array
    Asistencia* arrayDeAsistencia;//array
};
typedef misAsistencias MisAsistencias;

void leerClases_CSV(ifstream& infile, Asistencia* &asistencia_archivos, u_int tamAsistenciaArchivos);

void resize(Clase* &clase_archivos, u_int &tamC);

#endif // LIBRERIA_GLOBAL_H
