#include "archivos.h"
#include "gimnasio.h"

bool hayCupo(u_int idClase, Gimnasio gym)
{
    u_int i=0,pos=0;
    for (int i = 0; i < tamClases; i++) {
        if(gym.clases[i].idClase == idClase)
            pos=i;
    }
    if(gym.clases[pos].cupo< gym.clases[pos].cupo_maximo)
        return true;
    else
        return false;
}


