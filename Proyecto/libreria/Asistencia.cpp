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

bool repetidos(Asistencia asist, int idClase) //paso como parametro asistencia, en un cliente y un id de clase cual voy a comparar para ese cliente si ya esta repetido o no
{
    for (u_int i = 0; i < asist.cantInscripciones ; i++) {//for que recorre la cantidad de veces q se inscribio el cliente
        if(asist.CursosInscriptos[i].idClase == idClase) //compara si ya se anoto a la clase
            return true;
    }
    return false;
}




/* bool hayEspacio(Asistencia asist )
{
    if(asist.tamArrayCI-asist.cantInscripciones<=0)
        return false;
    else
        return true;
} */


/*eResizeInscriptos resizeCantInscripciones(Asistencia asist, u_int nuevoTam)
{
    if(nuevoTam==0)
        return eResizeInscriptos :: ErrSize;


    Inscripcion* aux = new Inscripcion[nuevoTam];

    u_int longitud = (asist.tamArrayCI < nuevoTam) ? tam: nuevoTam;

    if(aux == nullptr)
        return eResizeInscriptos :: ErrNull;


    for(u_int i = 0; i < longitud; i++)
        aux[i] = asist.CursosInscriptos[i];


    delete[] CursosIncriptos;
    asist.CursosInscriptos = aux;
    asist.tamArrayCI=nuevoTam;
    return eResizeInscriptos :: ExitoResize;

}*/

