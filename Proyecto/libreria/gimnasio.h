#ifndef GIMNASIO_H
#define GIMNASIO_H

#include <iostream>
#include <ctime>
#include "clientes.h"//
#include "clases.h"
#include "archivos.h"
#include "libreria.h"

using namespace std;

enum resClase{ErrNoHayCupo=-4,ErrNoExisteCliente = -3,ErrNoExisteClase= -2,
                ErrClienteRepetido=-1, ExitoReserva=0};
typedef enum resClase eResClase;

struct gimnasio
{
    Cliente* clientes;//array de clientes
    Clase* clases; //array de clases
    u_int tamClases, tamClientes; //el tamaño de ambos arrays
};

typedef gimnasio Gimnasio;

eResClase ReservaClases (u_int horarioIng, string nombreClaseIng, int idClienteIng, MisAsistencias asist, Gimnasio* gym);

//se encuentra en clases.cpp
bool hayCupo(int idClase, Gimnasio gym);
int buscarIdClase(Gimnasio gym, u_int horarioIng, string nombreClaseIng); //busco por hora y por nombre de la clase
int buscarPosClase(Gimnasio gym, u_int horarioIng, string nombreClaseIng);

//funciones dentro de clientes.cpp:
//u_int crearIdCliente(string nombreIng, string apellidoIng, string emailIng, string telefonoIng, Fecha fechaNacIng, Gimnasio gym);

//void nuevoCliente(Gimnasio* gym, Cliente Ing);

bool RevisarCliente(int idClienteIng, Gimnasio gym);

int BuscarCliente(string nombreIng, string apellidoIng, Gimnasio gym);// me devuelve su id

#endif // LIBRERIA_GLOBAL_H
