#ifndef GIMNASIO_H
#define GIMNASIO_H

#include "asistencias.h" //llamo a las estructuras de esta libreria

using namespace std;

enum resClase{ErrInscripcion=-3,ErrNoExisteClase= -2,ErrClienteRepetido=-1, ExitoReserva=0};
typedef enum resClase eResClase;

//ESTRUCTURAS (TIPOS DE DATOS):
struct fecha //estructura de fecha
{
    u_int dia, mes, anio;
};
typedef fecha Fecha;

struct cliente //estructura de cliente
{
    string nombre, apellido, email, telefono;
    int idCliente;
    Fecha fechaNac;
    float estado; //para saber si tiene la cuota al dia (menor a 0 debe, 0 todo ok, mayor a 0 pago por adelantado)
};
typedef cliente Cliente;

struct clase //estructura de clase
{
    u_int horario, cupo,   cupo_maximo; //cantidad de personas anotadas
    int idClase; //hora de la clase
    string nombre; //yoga, streching, etc.
    int* reservados; // reservar el dato de la cantidad del array en el main sabiendo que clase es
};//array reservados: esta inicializado en 0, y se va guartdando el idCliente segun las inscrip
typedef clase Clase;

struct gimnasio //estructura de gimnasio que contiene:
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

//u_int crearIdCliente(string nombreIng, string apellidoIng, string emailIng, string telefonoIng, Fecha fechaNacIng, Gimnasio gym);

//void nuevoCliente(Gimnasio* gym, Cliente Ing);

bool RevisarCliente(int idClienteIng, Gimnasio gym);

int BuscarCliente(string nombreIng, string apellidoIng, Gimnasio gym);// me devuelve su id

string nombreClaseAleatorio();

int agregarAResevados(Gimnasio * gym, u_int idClase, u_int idCliente);

bool repetidos(Gimnasio gym, int posClase, int idCliente);

void inicializarArrayClases0(Clase *&arrayClases, int tamArray);//funcion que inicializa el array de clases con 0 en el array de reservados, y sus respectivos cupos maximos


#endif // LIBRERIA_GLOBAL_H
