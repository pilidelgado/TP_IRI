#ifndef GIMNASIO_H
#define GIMNASIO_H

#include <iostream>
#include <ctime>
#include "clientes.h"//
#include "clases.h"

using namespace std;

enum resClase { ErrNoExisteClase= -2, ErrClienteRepetido=-1, ExitoReserva=0}
typedef enum resClase eResClase;

struct gimnasio
{
    Cliente* clientes;
    Clase* clases;
    u_int tamClases, tamClientes;
};

typedef gimnasio Gimnasio;

eResClase ReservaClases (u_int horarioIng, string nombreClaseIng, u_int idClienteIng, Asistencia* Asistencia, Gimnasio* gimnasio, time_t fechaInscripcion);

bool hayCupo(idCurso, Gimnasio gimnasio);

#endif // LIBRERIA_GLOBAL_H
