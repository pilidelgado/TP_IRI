#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <ctime>
#include "clases.h"
#include "libreria.h"

/*Que tenemos aca?
-definicion struct inscripcion (que leemos del archivo binario)
- definicion struct asistencia (que leemos del archivo binario)
- definicion del struct misAsistencias que contiene un array de asistencias de cada cliente, y su tamaño
- funcion  rezice asistencia
- funcion para leer el archivo csv de clase*/


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

void resize(Clase* &clase_archivos, u_int &tamC);

#endif // LIBRERIA_GLOBAL_H
