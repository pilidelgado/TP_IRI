#include "archivos.h"
#include "gimnasio.h"

bool hayCupo(u_int idClase, Gimnasio gym)//me pasa el id de la clase y la estructura del gym
{
    u_int i,pos=0;//declaro mi indice y posicion:
    for (int i = 0; i < gym.tamClases; i++) { //for que recorre el array de clases
        if(gym.clases[i].idClase == idClase) //si encuentro el id me guardo la pos
            pos=i; //busco la pos de la clase con el id q me pasaron y me guardo su posicion en el array de clases dentro de gym
    }
    if(gym.clases[pos].cupo< gym.clases[pos].cupo_maximo) //si la cantidad de inscriptos es menor al maximo que tiene esa clase
        return true;//devuelvo q hay cupo
    else
        return false; //de lo contrario no hay cupo, retorno falso
}

u_int buscarIdClase(Gimnasio gym, u_int horarioIng, string nombreClaseIng){
    u_int idClaseAReservar= -1;
    for(u_int i=0; i < gym.tamClases; i++) //for que recorre el array de clases
    {
        if(horarioIng == gym.clases[i].horario && nombreClaseIng == gym.clases[i].nombre)
        {//busca el id coparando a partir del horario ingresado y el nombre de la clase
           idClaseAReservar = gym.clases[i].idClase;
        }
        return idClaseAReservar;
    }
}

u_int buscarPosClase(Gimnasio gym, u_int horarioIng, string nombreClaseIng){
    u_int posReserva=-1;
    for(u_int i=0; i < gym.tamClases; i++) //for que recorre el array de clases
    {
        if(horarioIng == gym.clases[i].horario && nombreClaseIng == gym.clases[i].nombre)
        {//busca el id coparando a partir del horario ingresado y el nombre de la clase
            posReserva = i;
        }
        return posReserva;
    }
}


