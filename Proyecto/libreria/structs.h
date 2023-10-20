#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>
#include <ctime>

using namespace std;
struct fecha
{
    u_int dia, mes, anio;
};
typedef fecha Fecha;

struct clase
{
    u_int horario, idClase; //hora de la clase
    string nombre; //yoga, streching, etc.
    u_int cupo,   cupo_maximo; //cantidad de personas anotadas
    u_int* reservados;
};
typedef clase Clase;


struct cliente
{
    string nombre, apellido, email, telefono;
    u_int idCliente;
    Fecha fechaNac;
    float estado; //para saber si tiene la cuota al dia (menor a 0 debe, 0 todo ok, mayor a 0 pago por adelantado)
};
typedef cliente Cliente;

struct Gimnasio
{
    Cliente* clientes;
    Clase* clases;
    u_int tamClases, tamClientes;
};


typedef struct {
    u_int idClase;
    time_t fechaInscripcion;//a q hora se inscibio al curso
} Inscripcion;

typedef struct {
    u_int idCliente, cantInscripciones;//cantidad del array
    Inscripcion* CursosInscriptos;//array
} Asistencia;

#endif // LIBRERIA_GLOBAL_H
