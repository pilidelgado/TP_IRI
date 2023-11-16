#ifndef ASISTENCIAS_H
#define ASISTENCIAS_H

#include <iostream>
#include <ctime>
#include "libreria.h"
#include "gimnasio.h"
#include "archivos.h" //llamo donde estan declarados mis structs

/*enum agregarInscripciones { ErrNoSeAgrego= -1, ExitoAgregado=0}; //enum de mis errores
typedef enum agregarInscripciones eAgregarInscripciones;*/

u_int buscarPosAsistencia(MisAsistencias asist, u_int idCliente);//funcion que busca el cliente en el  array de mis asistencias

bool repetidos(Asistencia asist, u_int idClase); //funcion booleana que se fija si ya se anoto en esa clase

/*bool hayEspacio(Asistencia asist);

eResizeInscriptos resizeCantInscripciones(Asistencia asist , u_int nuevoTam);*/

u_int agregarInscripcion(Gimnasio * gym, u_int idClase, u_int idCliente);

#endif // LIBRERIA_GLOBAL_H
