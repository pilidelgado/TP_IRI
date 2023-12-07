#ifndef ASISTENCIAS_H
#define ASISTENCIAS_H

#include "libreria.h"


//enum agregarInscripciones { ErrNoSeAgrego= -1, ExitoAgregado=0}; //enum de mis errores
//typedef enum agregarInscripciones eAgregarInscripciones;


/*Que tenemos aca?
    -definicion struct inscripcion (que leemos del archivo binario)
    - definicion struct asistencia (que leemos del archivo binario)
    - definicion del struct misAsistencias que contiene un array de asistencias de cada cliente, y su tamaño
    - funcion  resize asistencia
    - funcion para leer el archivo csv de clase
*/

//MIS ESTRUCTURAS:
typedef struct {
    int idClase;
    time_t fechaInscripcion;//a q hora se inscibio al curso
} Inscripcion;

typedef struct {
    int idCliente, cantInscripciones;//cantidad del array
    Inscripcion* CursosInscriptos;//array
} Asistencia;

struct misAsistencias {
    int tamAsist;//cantidad del array
    Asistencia* arrayDeAsistencia;//array
};
typedef misAsistencias MisAsistencias;

//DECLARACION DE FUNCIONES:

int buscarPosAsistencia(MisAsistencias asist, int idCliente);//funcion que busca el cliente en el  array de mis asistencias

#endif // ASISTENCIAS_H
