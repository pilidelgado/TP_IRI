#include "archivos.h"
#include "gimnasio.h"

u_int nuevoCliente(Gimnasio* gym, Cliente aux)// crea un idCliente que no exista en mi clientes* Clientes
{

}

bool RevisarCliente(u_int idClienteIng, Gimnasio gym)
{
    for(u_int i=0; i < tamClientes; i++)
    {
        if(gym.clientes[i].idCliente==idClienteIng)
            return true;
    }
    return false;
}

u_int BuscarCliente(Cliente aux, Gimnasio gym)
{
    u_int idClienteEncontrado;
    for(u_int i=0; i < tamClientes; i++)
    {
        if((aux.apellido== gym.clientes[i].apellido && aux.nombre== gym.clientes[i].nombre) || aux.email== gym.clientes[i].email || aux.telefono== gym.clientes[i].telefono)
            idClienteEncontrado=  gym.clientes[i].idCliente;
        else
            idClienteEncontrado=nuevoCliente(Gimnasio* gym, aux);

    }
    return idClienteEncontrado;
}
