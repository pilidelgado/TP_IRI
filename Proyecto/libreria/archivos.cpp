#include "archivos.h"
#include "gimnasio.h"

u_int buscarPosAsistencia(Asistencia asist, u_int idCliente) // va con puntero asist
{
    u_int pos;
    for (int i = 0; i < tamA ; ++i) { // como se el tamaño del array de Asistencia
        if(asist.idCliente == idCliente)
            pos=i;
    }
    return pos;
}

bool repetidos(Asistencia asist, u_int idClase)
{
    u_int pos;
    for (int i = 0; i < asist.cantInscripciones ; ++i) {
        if(asist.CursosInscriptos[i].idClase == idClase)
            return true;
    }
    return false;
}

bool hayEspacio(Asistencia asist )
{
    if(asist.tamArrayCI-asist.cantInscripciones<=0)
        return false;
    else
        return true;
}


eResizeInscriptos resizeCantInscripciones(Asistencia asist, u_int nuevoTam)
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

}

