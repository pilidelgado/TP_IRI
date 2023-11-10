#include "archivos.h"
#include "gimnasio.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

#define ArchivoClase "C:\Users\emmif\source\Dataset TP (1)"

void leerClases_CSV(ifstream& infile, Clase* &clase_archivos, u_int tamC){ //QUÉ DEVUELVE LA FUNCIÓN? NECESITA PARÁMETROS?

    ifstream infile("iriClasesGYM.csv");
    if(!infile.is_open()) {
        cout << "Error abriendo el archivo CSV de clases" << endl;
        return 1; //cambiar después por un error perteneciente a un enum!!
    }

    string header;
    getline(infile, header);
    char delimitador = ',';
    stringstream s;

    while(infile.good()) {
        string linea;
        getline(infile, linea);
        s<<linea;
        getline(s,)


        string campo;
        istringstream iss(linea);
        while(getline(iss, campo, delimitador)) {
            cout << campo << " ";
        }
        cout << endl;
    }

    infile.close();

    string header;
    stringstream s;
    string auxidClases;
    string auxNombre;
    string auxHorario;
    char coma=',';
    getline(infile, header);

    while(infile.good()) {
        string linea;
        getline(infile, linea);
        s<<linea;
        getline(s,auxidClases,coma);
        clase_archivos[tamC].idClase=stoi(auxidClases);
        getline(s,auxNombre,coma);
        clase_archivos[tamC].nombre=auxNombre;
        getline(s,auxHorario,coma);
        clase_archivos[tamC].horario=auxHorario;
        resize(clase_archivos,tamC);//llamar funcion resize que le vaya agregando uno al tamC segun el archivo
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



int escribirAsistencias_BIN(){

    ofstream outfile("iriClientesGYM.csv", ios::binary);
    if(!outfile.is_open()) {
        cout << "Error abriendo el archivo binario de asistencias" << endl;
        return 1;
    }

    char datos[] = "acá va lo que queremos escribir en el archivo";
    outfile.write(datos, sizeof(datos));

    outfile.close();

    return 0;
}





