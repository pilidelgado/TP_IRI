#include "archivos.h" //donde esta definida mis estructuras
#include "asistencias.h" //llamo donde estan definidas mis funciones
#include "gimnasio.h"

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

int agregarInscripcion(Gimnasio * gym, int idClase, int idCliente) //es *gym ya que modifico sus datos
//le paso la estructura de gym, el id de clase a reservar y el id del cliente que quiere reservar la clase
{
    int reservaRes=-1;//inicializo resultado en -1, siendo este el valor cunaod indica error
    for(u_int i=0; i<gym->clases[idClase].cupo_maximo; i++)
    //recorro el array especifico de la clase dada hasta mi cupo maximo
    {
        if(gym->clases[idClase].reservados[i]==0)//mi array de reservados por clase esta inicializado en 0, en caso de que alguien se inscruba me guardo su id de cliente
        {
            gym->clases[idClase].reservados[i]= idCliente; //me guardo el idCliente en mi array de reservados
            reservaRes =0; //si me agrego a un cliente, cambio el resultado
            break; //hago un break para no copiarme al mismo clientes muchas veces
        }
    }

        return reservaRes;

}
