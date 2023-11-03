#include "archivos.h"
#include "gimnasio.h"

void crearIdCliente(string nombreIng, string apellidoIng, string emailIng, string telefonoIng, Fecha fechaNacIng, Gimnasio gym) //crea un idCliente que no exista en mi clientes* Clientes
{
    Cliente aux = new Cliente;

    u_int idCreado= gym.tamClientes + 1;
    aux.apellido=apellidoIng;
    aux.email=emailIng;
    aux.telefono=telefonoIng;
    aux.nombre=nombreIng;
    aux.estado=0;
    aux.idCliente=idCreado;
    aux.fechaNac=fechaNacIng;

    nuevoCliente(gym, aux);
    delete aux;
    return;
}
void nuevoCliente(Gimnasio* gym, Cliente Ing)// agrega el cliente al array
{
      Cliente* aux = new Cliente[gym->tamClientes +1];

    for(u_int i = 0; i < gym->tamClientes +1 ; i++)
      {
          if(i< gym->tamClientes)
            aux[i] = gym->clientes[i];
          else
            aux[i]= Ing;
    }
    delete[] Cliente;
    gym->clientes = aux;
    gym->tamClientes++;
    return;
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
