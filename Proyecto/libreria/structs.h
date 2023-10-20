#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>
#include <ctime>

using namespace std;
struct fecha
{
    u_int dia, mes, anio;
}
typedef fecha Fecha;

struct clase
{
    u_int horario, idClase; //hora de la clase
    string nombre; //yoga, streching, etc.
    u_int cupo; //cantidad de personas anotadas
    int cupo_maximo;
    int reservados[cupo_maximo]; // array de reservas con DNI
};

clase clases[N1]; // definimos despues el N

/*struct musculacion
{
    u_int bloque,cupo; //hora de reserva //cantidad de personas anotadas
    int cupo_maximo;
    int reservados[cupo_maximo];
}

musculacion musculacion[N2]; */


struct cliente
{
    string nombre, apellido, idCliente, email, telefono;
    Fecha fechaNac;
    float estado; //para saber si tiene la cuota al dia (menor a 0 debe, 0 todo ok, mayor a 0 pago por adelantado)
}

cliente clientes[NMAX]; //memoria dinámica (funcion)


typedef struct {
    uint idCurso;
    time_t fechaInscripcion;
} Inscripcion;

typedef struct {
    uint idCliente, cantInscriptos;
    Inscripcion* CursosInscriptos;
} Asistencia;

#endif // LIBRERIA_GLOBAL_H
