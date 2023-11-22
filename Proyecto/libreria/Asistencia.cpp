#include "asistencias.h" // que incluye libreria.h
#include "gimnasio.h"

int buscarPosAsistencia(MisAsistencias asist, int idCliente)
{
    int pos=-3;//inicializo en -1 por si no llego a encontrar al cliente
    for (int i = 0; i < asist.tamAsist ; i++) { // como se el tamaño del array de Asistencia
        if(asist.arrayDeAsistencia[i].idCliente == idCliente)//busco la posicion del cliente que me pasan en mi array de asistencia
            pos=i;//devuelvo la pos
    }
    return pos;
}

void AgregarAsistencia(MisAsistencias& asist,int idClienteIng, int idClaseAReservar, time_t fechaInscripcion){
//función que escriba en el mismo archivo binario una nueva asistencia

}

eAgregarInscripciones agregarInscripciones(MisAsistencias& asist, int posAsistencia, int idClase, time_t fechadeinscripcion)
{

}

Inscripcion* resizeInscripcion(MisAsistencias* asist,u_int cantInscripciones, u_int nuevoTam)
{

}

