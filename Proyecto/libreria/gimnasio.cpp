#include "gimnasio.h"


eResClase ReservaClases (u_int horarioIng, string nombreClaseIng, u_int idClienteIng, Asistencia* Asistencia, Gimnasio* gimnasio, time_t fechaInscripcion)
{
    u_int i, j, idCursoAReservar, posReserva;

    for(i=0; i < gimnasio.tamClases; i++)
    {
        if(horarioIng == gimnasio.clases[i].horario && nombreClaseIng == gimnasio.clases[i].nombre)
        {
            idCursoAReservar = gimnasio.clases[i].idClase;
            posReserva = i;
        }
        else
             return eResClase :: ErrNoExisteClase;
    }


    u_int posCliente = buscarPosAsistencia(Asistencia, idClienteIng); //definir función buscarPosAsistencia: busca la posición del id del cliente

    if(hayCupo(idCursoAReservar, gimnasio)) //definir función hayCupo: controla si hay lugar en la clase pedida por el usuario
    {
        for(j=0; j< Asistencia[posCliente].cantInscripciones; j++)
        {
            if(repetidos(Asistencia, idClienteIng, idCursoAReservar)) //definir funcion repetidos: controla que la persona no esté inscripta en la misma clase dos veces
                return eResClase :: ErrClienteRepetido; //error, si me devuelve true es porque está repetido

            else //si devuelve false, lo inscribo
            {
                gimnasio.clases[posReserva].cupo++;
                if(!hayEspacio(Asistencia[posCliente]))
                    resizeCantInscripciones(Asistencia[posCliente]); //definir función que, si no hay espacio en Inscripcion*, le agrega memoria


                Asistencia[posCliente].cantInscripciones++;
                agregarInscripcion(Asistencia, idCursoAReservar, posCliente, fechaInscripcion); //definir función que agregue los datos de inscripcion de la nueva clase a las clases propias del usuario
            }
        }
    }
    return eResClase :: ExitoReserva;
}



