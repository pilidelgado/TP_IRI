#ifndef CLIENTES_H
#define CLIENTES_H

#include <iostream>
#include <ctime>
#include "libreria.h"

using namespace std;


struct fecha
{
    u_int dia, mes, anio;
};
typedef fecha Fecha;

struct cliente
{
    string nombre, apellido, email, telefono;
    u_int idCliente;
    Fecha fechaNac;
    float estado; //para saber si tiene la cuota al dia (menor a 0 debe, 0 todo ok, mayor a 0 pago por adelantado)
};
typedef cliente Cliente;

#endif // LIBRERIA_GLOBAL_H
