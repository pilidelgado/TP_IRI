#include "libreria.h"
#include "structs.h"

void nuevoSize(NSize &error, cliente*& lista, NMAX, u_int nuevoTam) { //va puntero?
    if(nuevoTam==0)
    {
        error= NSize :: ErrSize;
        return;
    }
    cliente* aux = new cliente[nuevoTam];

    u_int longitud = (NMAX < nuevoTam) ? NMAX: nuevoTam;

    if(aux == nullptr)
    {
        error= NTamaño :: ErrNull;
            return;
    }

    for(u_int i = 0; i < longitud; i++)
        aux[i] = lista[i];


    delete[] lista;
    lista = aux;

}


void nuevoCliente(clientes[], DNIDado)
{

}


bool DNICorrecto(DNIDado) //chequea caracteres del dni ingresado
{
    u_int cont = 0;

    if(strlen(DNIDado) >= 6 && strlen(DNIDado) <= 8)
    {
        for(u_int i = 0; i < strlen(DNIDado); i++)
        {
            if(DNIDado[i] >= 48 && DNIDado[i] <= 57)
                cont++;
        }

        if(cont == strlen(DNIDado))
            return true;
        else
            return false;
    }
    else
        return false;
}




bool RevisarCliente(DNIDado, Clientes[]) //chequea que el dni esté bien y esté agendado
{
    if(DNICorrecto(DNIDado))
    {
        for(u_int i = 0; i < NMAX; i++)
        {
            if(DNIDado == Clientes[i].DNI)
                return true;
        }

        nuevoCliente(clientes[NMAX], DNIDado);
        return true;
    }
    else
        return false;
}
