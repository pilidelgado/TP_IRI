#ifndef ABRIRARCHIVOS_H
#define ABRIRARCHIVOS_H

#include "gimnasio.h" //incluye asistencias.h --> incluye libreria.h

//FUNCIONES ARCHIVOS:

void resize(Clase* &clase_archivos, int &tamC);

void leerClases_CSV(ifstream &archivo, Gimnasio& miGimnasio);

void leerClientes_CSV(ifstream &archivo2, Gimnasio& miGimnasio);

void escribirBinario(ofstream &archivoBin, MisAsistencias &asist);

//void escribirTxt(ofstream &archivoTxt, MisAsistencias &asist);

#endif // ABRIRARCHIVOS_H
