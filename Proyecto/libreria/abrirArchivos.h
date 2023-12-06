#ifndef ABRIRARCHIVOS_H
#define ABRIRARCHIVOS_H

#include "gimnasio.h" //incluye asistencias.h --> incluye libreria.h

//FUNCIONES ARCHIVOS:

void resize(Clase* &clase_archivos, int &tamC);

void leerClases_CSV(ifstream &archivo, Gimnasio& miGimnasio);

void leerClientes_CSV(ifstream &archivo2, gimnasio& miGimnasio);

void escribirBinario(int idCliente, int idClase, time_t fechaInsc);

/*void leerArchivoBinario(MisAsistencias& misAsistencias);*/

#endif // ABRIRARCHIVOS_H
