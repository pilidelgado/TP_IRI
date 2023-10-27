#ifndef CLASES_H
#define CLASES_H

#include <iostream>
#include <ctime>

using namespace std;
typedef unsigned int u_int;


struct gimnasio
{
    Cliente* clientes;
    Clase* clases;
    u_int tamClases, tamClientes;
};

typedef gimnasio Gimnasio;



#endif // LIBRERIA_GLOBAL_H
