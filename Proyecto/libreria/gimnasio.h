#ifndef GIMNASIO_H
#define GIMNASIO_H

#include "asistencias.h" //incluye a su vez a libreria.h

using namespace std;

enum resClase{ErrInscripcion=-3,ErrNoExisteClase= -2,ErrClienteRepetido=-1, ExitoReserva=0};
typedef enum resClase eResClase;

//ESTRUCTURAS (TIPOS DE DATOS):
struct fecha //estructura de fecha
{
    int dia, mes, anio;
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
    int horario, cupo,   cupo_maximo; //cantidad de personas anotadas
    int idClase; //hora de la clase
    string nombre; //yoga, streching, etc.
    int* reservados; // reservar el dato de la cantidad del array en el main sabiendo que clase es
};//array reservados: esta inicializado en 0, y se va guartdando el idCliente segun las inscrip
typedef clase Clase;

struct gimnasio //estructura de gimnasio que contiene:
{
    Cliente* clientes;//array de clientes
    Clase* clases; //array de clases
    int tamClases, tamClientes; //el tamaño de ambos arrays
};
typedef gimnasio Gimnasio;

eResClase ReservaClases (int horarioIng, string nombreClaseIng, int idClienteIng,MisAsistencias &asist, Gimnasio &gym);

bool hayCupo(int idClase, Gimnasio gym);

int buscarIdClase(Gimnasio gym, int horarioIng, string nombreClaseIng); //busco por hora y por nombre de la clase

int buscarPosClase(Gimnasio gym, int horarioIng, string nombreClaseIng);

bool RevisarCliente(int idClienteIng, Gimnasio gym);

int BuscarCliente(string nombreIng, string apellidoIng, Gimnasio gym);// me devuelve su id

string nombreClaseAleatorio();

int agregarAResevados(Gimnasio * gym, int idClase, int idCliente);

bool repetidos(Gimnasio gym, int posClase, int idCliente);

void inicializarArrayClases0(Clase *&arrayClases, int tamArray);//funcion que inicializa el array de clases con 0 en el array de reservados, y sus respectivos cupos maximos

#endif // GIMNASIO_H
