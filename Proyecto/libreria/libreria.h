#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <iostream>
#include <string>
#include <fstream>

#define BLK 10;
#define NMAX 200;

using namespace std;

typedef unsigned int u_int;

clientes* nuevoTamaño(clientes* puntero, NMAX, u_int nuevoTam);

    void nuevoCliente(clientes[], DNIDado);

bool DNICorrecto(DNIDado);

bool RevisarCliente(DNIDado, Clientes[]);
#endif // LIBRERIA_H
