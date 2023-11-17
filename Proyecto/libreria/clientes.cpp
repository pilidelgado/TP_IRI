#include "gimnasio.h"
//estas funciones se encuentran declaradas en gym.h


bool RevisarCliente(int idClienteIng, Gimnasio gym)
{
    for(u_int i=0; i < gym.tamClientes; i++)
    {
        if(gym.clientes[i].idCliente==idClienteIng && gym.clientes->estado >= 0) //revisa que el cliente exista y tenga la cuota al dia
            return true;
    }
    return false;
}

int BuscarCliente(string nombreIng, string apellidoIng, Gimnasio gym)
{
    u_int idClienteEncontrado=-1;//en caso de no encontrarlo devuelve -1
    for(u_int i=0; i < gym.tamClientes; i++)
    {
        if((apellidoIng== gym.clientes[i].apellido && nombreIng== gym.clientes[i].nombre))
            idClienteEncontrado=  gym.clientes[i].idCliente;
        else
            idClienteEncontrado=0;

    }
    return idClienteEncontrado;
}


/*
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
    delete[] aux;
    gym->clientes = aux;
    gym->tamClientes++;
    return;
}

u_int crearIdCliente(string nombreIng, string apellidoIng, string emailIng, string telefonoIng, Fecha fechaNacIng, Gimnasio &gym) //crea un idCliente que no exista en mi clientes* Clientes
{
    Cliente *aux = new Cliente;

    u_int idCreado= gym.tamClientes + 1;
    aux->apellido=apellidoIng;
    aux->email=emailIng;
    aux->telefono=telefonoIng;
    aux->nombre=nombreIng;
    aux->estado=0;
    aux->idCliente=idCreado;
    aux->fechaNac=fechaNacIng;

    nuevoCliente(gym, aux);
    delete aux;
    return idCreado;
}
*/
