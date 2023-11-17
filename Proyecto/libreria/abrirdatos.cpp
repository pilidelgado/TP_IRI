#include "archivos.h"
#include "gimnasio.h"
#include "asistencias.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

#define ArchivoClase "C:\Users\emmif\source\Dataset TP (1)"

void resize(Clase* &clase_archivos, u_int &tamC)
{
    if(clase_archivos==nullptr){
        if(tamC<=0)
            clase_archivos = new Clase[tamC++];
        return;
    }

    Clase * aux= new Clase[tamC++];
    for(u_int i=0; i<tamC-1;i++){
        aux[i]=clase_archivos[i];
    }

    delete[] clase_archivos;
    clase_archivos=aux;
}

void leerClases_CSV(Gimnasio& miGimnasio) {

    ifstream archivo("iriClasesGYM");
    if (!archivo.is_open()) {
        cout << "Error abriendo el archivo CSV de clases" << std::endl;
        return;
    }

    //Lee la primera línea del archivo
    string encabezado;
    getline(archivo, encabezado);

    //Lee los datos de cada línea del archivo
    while (!archivo.eof()) { //mientras el archivo esté abierto
        string linea;
        getline(archivo, linea);

        stringstream ss(linea);
        Clase nuevaClase; //me creo un struct de clase

        //Lee los valores de la línea
        ss >> nuevaClase.idClase >> nuevaClase.nombre >> nuevaClase.horario;

        // Aumenta el tamaño del array de clases y copia la nueva clase
        Gimnasio nuevoGimnasio; //me creo un struct de gimnasio
        nuevoGimnasio.tamClases = miGimnasio.tamClases + 1; //por cada clase leida, se suma una al tamaño
        nuevoGimnasio.clases = new Clase[nuevoGimnasio.tamClases]; //creo un array dinámico de las clases almacenadas en el gimnasio

        // Copia las clases existentes al nuevo array de clases
        for (u_int i = 0; i < miGimnasio.tamClases; i++) {
            nuevoGimnasio.clases[i] = miGimnasio.clases[i];
        }

        // Agrega la nueva clase al final del array
        nuevoGimnasio.clases[miGimnasio.tamClases] = nuevaClase;

        // Libera la memoria del antiguo array
        delete[] miGimnasio.clases;

        // Actualiza miGimnasio con el nuevo array
        miGimnasio = nuevoGimnasio;
    }

    archivo.close();
}

void leerClientes_CSV(gimnasio& miGimnasio) {
    ifstream archivo("iriClientesGYM");
    if (!archivo.is_open()) {
        cout << "Error abriendo el archivo CSV de clientes" << endl;
        return;
    }

    // Lee la primera línea del archivo
    string encabezado;
    getline(archivo, encabezado);

    // Lee los datos de cada línea del archivo
    while (!archivo.eof()) { //mientras el archivo no esté cerrado
        string linea;
        getline(archivo, linea);

        stringstream ss(linea);
        Cliente nuevoCliente; //creo una estructura de clientes

        //lee los valores de la línea
        ss >> nuevoCliente.idCliente >> nuevoCliente.nombre >> nuevoCliente.apellido >> nuevoCliente.email >> nuevoCliente.telefono >> nuevoCliente.fechaNac.dia >> nuevoCliente.fechaNac.mes >> nuevoCliente.fechaNac.anio >> nuevoCliente.estado;

        // Aumenta el tamaño del array de clientes y copia el nuevo cliente
        gimnasio nuevoGimnasio; //se crea una estructura de gimnasio
        nuevoGimnasio.tamClientes = miGimnasio.tamClientes + 1; //por cada linea leida, aumenta en uno el tamaño del array de clientes
        nuevoGimnasio.clientes = new Cliente[nuevoGimnasio.tamClientes]; //array de clientes dinámico

        // Copia los clientes existentes al nuevo array
        for (u_int i = 0; i < miGimnasio.tamClientes; ++i) {
            nuevoGimnasio.clientes[i] = miGimnasio.clientes[i];
        }

        // Agrega la estructura nueva de clientes al final del array
        nuevoGimnasio.clientes[miGimnasio.tamClientes] = nuevoCliente;

        // Libera la memoria del antiguo array
        delete[] miGimnasio.clientes;

        // Actualiza miGimnasio con el nuevo array
        miGimnasio = nuevoGimnasio;
    }

    archivo.close();
}

MisAsistencias leerArchivoBinario() {
    MisAsistencias misAsistencias;
    // Abre el archivo binario en modo lectura
    ifstream archivo("asistencias_1697673600000", ios::binary);

    if (!archivo) {
        cerr << "Error al abrir el archivo: " << "asistencias_1697673600000" << endl;

    }

    // Lee la cantidad de asistencias
    archivo.read(reinterpret_cast<char*>(&misAsistencias.tamAsist), sizeof(misAsistencias.tamAsist));

    // Reserva memoria para el array de Asistencia
    misAsistencias.arrayDeAsistencia = new Asistencia[misAsistencias.tamAsist];

    // Lee cada asistencia del archivo
    for (u_int i = 0; i < misAsistencias.tamAsist; ++i) {
        // Lee idCliente y cantInscripciones
        archivo.read(reinterpret_cast<char*>(&misAsistencias.arrayDeAsistencia[i].idCliente), sizeof(misAsistencias.arrayDeAsistencia[i].idCliente));
        archivo.read(reinterpret_cast<char*>(&misAsistencias.arrayDeAsistencia[i].cantInscripciones), sizeof(misAsistencias.arrayDeAsistencia[i].cantInscripciones));

        // Reserva memoria para el array de Inscripcion
        misAsistencias.arrayDeAsistencia[i].CursosInscriptos = new Inscripcion[misAsistencias.arrayDeAsistencia[i].cantInscripciones];

        // Lee cada Inscripcion
        for (u_int j = 0; j < misAsistencias.arrayDeAsistencia[i].cantInscripciones; ++j) {
            archivo.read(reinterpret_cast<char*>(&misAsistencias.arrayDeAsistencia[i].CursosInscriptos[j].idClase), sizeof(misAsistencias.arrayDeAsistencia[i].CursosInscriptos[j].idClase));
            archivo.read(reinterpret_cast<char*>(&misAsistencias.arrayDeAsistencia[i].CursosInscriptos[j].fechaInscripcion), sizeof(misAsistencias.arrayDeAsistencia[i].CursosInscriptos[j].fechaInscripcion));
        }
    }

    // Cierra el archivo
    archivo.close();

    return misAsistencias;
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






