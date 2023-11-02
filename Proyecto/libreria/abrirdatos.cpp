#include "archivos.h"
#include "gimnasio.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

#define ArchivoClase "C:\Users\emmif\source\Dataset TP (1)"

int leerClases_CSV(){ //QUÉ DEVUELVE LA FUNCIÓN? NECESITA PARÁMETROS?

    ifstream infile("iriClasesGYM.csv");
    if(!infile.is_open()) {
        cout << "Error abriendo el archivo CSV de clases" << endl;
        return 1; //cambiar después por un error perteneciente a un enum!!
    }

    string header;
    getline(infile, header);

    while(infile.good()) {
        string linea;
        getline(infile, linea);

        char delimitador = ',';
        string campo;
        istringstream iss(linea);
        while(getline(iss, campo, delimitador)) {
            cout << campo << " ";
        }
        cout << endl;
    }

    infile.close();
    return 0; //cambiar después por un error perteneciente a un enum!!
}

int leerClientes_CSV(){ //QUÉ DEVUELVE LA FUNCIÓN? NECESITA PARÁMETROS?

    ifstream infile("iriClientesGYM.csv");
    if(!infile.is_open()) {
        cout << "Error abriendo el archivo CSV de clientes" << endl;
        return 1; //cambiar después por un error perteneciente a un enum!!
    }

    string header;
    getline(infile, header);

    while(infile.good()) {
        string linea;
        getline(infile, linea);

        char delimitador = ',';
        string campo;
        istringstream iss(linea);
        while(getline(iss, campo, delimitador)) {
            cout << campo << " ";
        }
        cout << endl;
    }

    infile.close();
    return 0; //cambiar después por un éxito perteneciente a un enum!!
}

int leerAsistencias_BIN(){

    ifstream infile("iriClientesGYM.csv");
    if(!infile.is_open()) {
        cout << "Error abriendo el archivo binario de asistencias" << endl;
        return 1; //cambiar después por un error perteneciente a un enum!!
    }

    char buffer[1024];
    while(infile.good()) {
        infile.read(buffer, sizeof(buffer));
    }

    infile.close();
    return 0; //cambiar después por un éxito perteneciente a un enum!!
}









