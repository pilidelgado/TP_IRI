#ifndef ASISTENCIAS_H
#define ASISTENCIAS_H

#include <iostream>
#include <ctime>
#include "libreria.h"
#include "gimnasio.h"
#include "archivos.h" //llamo donde estan declarados mis structs

enum agregarInscripciones { ErrNoSeAgrego= -1, ExitoAgregado=0};
typedef enum agregarInscripciones eAgregarInscripciones;

u_int buscarPosAsistencia(MisAsistencias asist, u_int idCliente);

bool repetidos(Asistencia asist, u_int idClase);

/*bool hayEspacio(Asistencia asist);

eResizeInscriptos resizeCantInscripciones(Asistencia asist , u_int nuevoTam);*/

eAgregarInscripciones agregarInscripcion(Gimnasio * gym, u_int idClase, u_int idCliente);

#endif // LIBRERIA_GLOBAL_H
