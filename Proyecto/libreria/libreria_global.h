#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>

using namespace std;

struct clase
{
    u_int turno; //hora de la clase
    string tipo; //yoga, streching, etc.
    u_int cupo; //cantidad de personas anotadas
    int cupo_maximo;
    int reservados[cupo_maximo]; // array de reservas con DNI
};

clase clases[N1]; // definimos despues el N

struct musculacion
{
    u_int bloque,cupo; //hora de reserva //cantidad de personas anotadas
    int cupo_maximo;
    int reservados[cupo_maximo];
}

musculacion musculacion[N2];

struct cliente
{
    string nombre, apellido, num_socio;
    string DNI;
    float debe; //para saber si tiene la cuota al dia (menor a 0 debe, 0 todo ok, mayor a 0 pago por adelantado)
    u_int grupo; //1 = clase, 2 = musculación
}

cliente clientes[NMAX]; //memoria dinámica (funcion)



#endif // LIBRERIA_GLOBAL_H
