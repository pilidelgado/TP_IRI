#ifndef ASISTENCIAS_H
#define ASISTENCIAS_H

#include "libreria.h"


enum agregarInscripciones { ErrNoSeAgrego= -1, ExitoAgregado=0}; //enum de mis errores
typedef enum agregarInscripciones eAgregarInscripciones;

/*Que tenemos aca?
    -definicion struct inscripcion (que leemos del archivo binario)
        - definicion struct asistencia (que leemos del archivo binario)
        - definicion del struct misAsistencias que contiene un array de asistencias de cada cliente, y su tamaño
        - funcion  rezice asistencia
        - funcion para leer el archivo csv de clase*/

//MIS ESTRUCTURAS:
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

//DECLARACION DE FUNCIONES:

int buscarPosAsistencia(MisAsistencias asist, u_int idCliente);//funcion que busca el cliente en el  array de mis asistencias

eAgregarInscripciones agregarInscripciones(MisAsistencias* &asist, int posAsistencia, int idClase, time_t fechadeinscripcion);

void AgregarAsistencia(MisAsistencias* &asist,idClienteIng,idClaseAReservar,fechaInscripcion);

Inscripcion* resizeInscripcion(MisAsistencias* asist,u_int cantInscripciones, u_int nuevoTam);


/*bool hayEspacio(Asistencia asist);
eResizeInscriptos resizeCantInscripciones(Asistencia asist , u_int nuevoTam);*/
#endif // LIBRERIA_GLOBAL_H
