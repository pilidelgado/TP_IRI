#include "asistencias.h"

int buscarPosAsistencia(MisAsistencias asist, int idCliente)
{
    int pos=-3;//inicializo en -1 por si no llego a encontrar al cliente
    for (u_int i = 0; i < asist.tamAsist ; i++) { // como se el tamaño del array de Asistencia
        if(asist.arrayDeAsistencia[i].idCliente == idCliente)//busco la posicion del cliente que me pasan en mi array de asistencia
            pos=i;//devuelvo la pos
    }
    return pos;
}

void AgregarAsistencia(MisAsistencias* &asist,idClienteIng,idClaseAReservar,fechaInscripcion)
{

}

eAgregarInscripciones agregarInscripciones(MisAsistencias* &asist, int posAsistencia, int idClase, time_t fechadeinscripcion)
{

}

Inscripcion* resizeInscripcion(MisAsistencias* asist,u_int cantInscripciones, u_int nuevoTam)
{

}

