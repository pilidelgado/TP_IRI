#include "gimnasio.h"

bool hayCupo(int idClase, Gimnasio gym)//me pasa el id de la clase y la estructura del gym
{
    int pos=0;//declaro mi indice y posicion:
    for (u_int i = 0; i < gym.tamClases; i++) { //for que recorre el array de clases
        if(gym.clases[i].idClase == idClase) //si encuentro el id me guardo la pos
            pos=i; //busco la pos de la clase con el id q me pasaron y me guardo su posicion en el array de clases dentro de gym
    }
    if(gym.clases[pos].cupo< gym.clases[pos].cupo_maximo) //si la cantidad de inscriptos es menor al maximo que tiene esa clase
        return true;//devuelvo q hay cupo
    else
        return false; //de lo contrario no hay cupo, retorno falso
}
/*QUE HACE ESTA FUNCION?
 * dada un idClase y mi estructura de gymnasio que posee el array de clases, y cupo que es la cantidad de inscriptos en esa clase que tiene como
maximo la variable cupo_maximo. busca primero en el array de clases, la posicion de la clase pedida por el usuario, y luego se fija si el cupo de
aquella clase es menor al cupo maximo, en caso que lo sea, retorna verdadero y en el caso contrario, retorna falso*/

int buscarIdClase(Gimnasio *gym, u_int horarioIng, string nombreClaseIng){
    int idClaseAReservar= -1;
    for(u_int i=0; i < gym->tamClases; i++) //for que recorre el array de clases
    {
        if(horarioIng == gym->clases[i].horario && nombreClaseIng == gym->clases[i].nombre)
        {//busca el id coparando a partir del horario ingresado y el nombre de la clase
           idClaseAReservar = gym->clases[i].idClase;
        }
    }
    return idClaseAReservar;
}
/*QUE HACE ESTA FUNCION?
 * Dada mi estructura de gimnasio, un horario ingresado por el usuario y un
 * nombre de la clase que este quiere reservar, va a recorrer el array
de clases que se encuentra dentro de gym, comparando si la
clase de aquella posicion tienen el mismo nombre y el mismo horario, en caso que esto pase
se guarda el id de la clase que quiere reservar el cliente en la variable entera
 idClaseAReservar, la cual esta inicializada en -1 por si no llega a encontrarla */

int buscarPosClase(Gimnasio gym, u_int horarioIng, string nombreClaseIng){
    int posReserva=-1;
    for(u_int i=0; i < gym.tamClases; i++) //for que recorre el array de clases
    {
        if(horarioIng == gym.clases[i].horario && nombreClaseIng == gym.clases[i].nombre)
        {//busca el id coparando a partir del horario ingresado y el nombre de la clase
            posReserva = i;
        }
        return posReserva;
    }
}


