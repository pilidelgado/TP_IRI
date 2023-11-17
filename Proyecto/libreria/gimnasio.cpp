#include "gimnasio.h"
#include "archivos.h"
#include "asistencias.h"

eResClase ReservaClases (u_int horarioIng, string nombreClaseIng, int idClienteIng, MisAsistencias asist, Gimnasio &gym)
{/*parametros: horario pedido por el usuario, clase pedida por el usuario, el id del cliengte, mi estructura de MisAsistencia, y la estrcutura del Gym para modificarlo*/
    int idClaseAReservar, posReserva;
    //int errorResize=0;

    posReserva= buscarPosClase(gym,horarioIng, nombreClaseIng);
    idClaseAReservar= buscarIdClase(gym,horarioIng, nombreClaseIng);

    if(posReserva== -1 || idClaseAReservar== -1)
        return eResClase :: ErrNoExisteClase;//retorno el error

    else{//si si encontro la clase y la pos:
        int posCliente = buscarPosAsistencia(asist, idClienteIng);

        if(posCliente==-3)//-3 indica error
            return eResClase :: ErrNoExisteCliente;//enum de error, devuelvo si no encontre al cliente

        else{//si encuentro al cliente:
                if(hayCupo(idClaseAReservar, gym)) //si es verdadero que hay cupo. funcion que controla si hay lugar en la clase pedida por el usuario
                {//si hay cupo:
                    if(repetidos(asist.arrayDeAsistencia[posCliente], idClaseAReservar)) //funcion repetidos: controla que la persona no esté inscripta en la misma clase dos veces
                        return eResClase :: ErrClienteRepetido; //error, si me devuelve true es porque está repetido

                    else //si devuelve false, lo inscribo
                    {
                        gym.clases[posReserva].cupo++;//aumento el cupo de la clase que me pidio el usuario
                        int resultado = agregarInscripcion(&gym, idClaseAReservar, idClienteIng);
                        //agregarInscripcion=función que agregue los datos de inscripcion de la nueva clase a las clases propias del usuario
                        if(resultado==-1)
                            return eResClase :: ErrNoHayCupo;
                    }
                }
                else
                    return eResClase :: ErrNoHayCupo; //retorno que no hay cupo
            }
    }
    return eResClase :: ExitoReserva;
}

//time(NULL) lo pongo en una variable y lo ´pongfo en la funcion de agregar
// memoria dinamica solo en resize


