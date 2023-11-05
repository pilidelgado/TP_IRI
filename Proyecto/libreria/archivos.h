#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <ctime>
#include "libreria.h"
#include "gimnasio.h"

enum agregarInscripciones { ErrNoSeAgrego= -1, ExitoAgregado=0};
typedef enum agregarInscripciones eAgregarInscripciones;

typedef struct {
    u_int idClase;
    time_t fechaInscripcion;//a q hora se inscibio al curso
} Inscripcion;

typedef struct {
    u_int idCliente, cantInscripciones;//cantidad del array
    Inscripcion* CursosInscriptos;//array
} Asistencia;

typedef struct {
    u_int tamAsist;//cantidad del array
    Asistencia* arrayDeAsistencia;//array
} MisAsistencias;

u_int buscarPosAsistencia(MisAsistencias asist, u_int idCliente);

bool repetidos(Asistencia asist, u_int idClase);

/*bool hayEspacio(Asistencia asist);

eResizeInscriptos resizeCantInscripciones(Asistencia asist , u_int nuevoTam);*/

eAgregarInscripciones agregarInscripcion(Gimnasio * gym, u_int idClase, u_int idCliente);

#endif // LIBRERIA_GLOBAL_H
