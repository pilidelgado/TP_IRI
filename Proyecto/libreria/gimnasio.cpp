#include "gimnasio.h"


eResClase ReservaClases (u_int horarioIng, string nombreClaseIng, u_int idClienteIng, Asistencia* asist, Gimnasio* gym)
{
    u_int i, j, idCursoAReservar, posReserva;
    // hacerla aparte con parametro de gimansio sin *
    for(i=0; i < gym.tamClases; i++)
    {
        if(horarioIng == gym.clases[i].horario && nombreClaseIng == gym.clases[i].nombre)
        {
            idCursoAReservar = gym.clases[i].idClase;
            posReserva = i;
        }
        else
             return eResClase :: ErrNoExisteClase;
    }


    u_int posCliente = buscarPosAsistencia(asist, idClienteIng); //definir función buscarPosAsistencia: busca la posición del id del cliente

    if(hayCupo(idCursoAReservar, gym)) //definir función hayCupo: controla si hay lugar en la clase pedida por el usuario
    {
        for(j=0; j< asist[posCliente].cantInscripciones; j++)
        {
            if(repetidos(asist, idClienteIng, idCursoAReservar)) //definir funcion repetidos: controla que la persona no esté inscripta en la misma clase dos veces
                return eResClase :: ErrClienteRepetido; //error, si me devuelve true es porque está repetido

            else //si devuelve false, lo inscribo
            {
                gym.clases[posReserva].cupo++;
                if(!hayEspacio(asist[posCliente]))
                    resizeCantInscripciones(asist[posCliente],asist[posCliente].cantInscripciones); //definir función que, si no hay espacio en Inscripcion*, le agrega memoria

                asist[posCliente].cantInscripciones++;
                agregarInscripcion(asist, idCursoAReservar, posCliente, time(NULL)); //definir función que agregue los datos de inscripcion de la nueva clase a las clases propias del usuario
            }
        }
    }
    return eResClase :: ExitoReserva;
}

//time(NULL) lo pongo en una variable y lo ´pongfo en la funcion de agregar
// memoria dinamica solo en resize


