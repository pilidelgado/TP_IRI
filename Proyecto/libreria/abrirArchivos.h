#ifndef ABRIRARCHIVOS_H
#define ABRIRARCHIVOS_H

#include "gimnasio.h" //incluye asistencias.h --> incluye libreria.h

//FUNCIONES ARCHIVOS:

void resize(Clase* &clase_archivos, u_int &tamC);

void leerClases_CSV(Gimnasio& miGimnasio);

void leerClientes_CSV(gimnasio& miGimnasio);

/*void leerArchivoBinario(MisAsistencias& misAsistencias);*/

#endif // ABRIRARCHIVOS_H
