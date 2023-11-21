#include "abrirArchivos.h"


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

/*void leerArchivoBinario(MisAsistencias& misAsistencias) {
    MisAsistencias misAsistencias;
    // Abre el archivo binario en modo lectura
    ifstream archivo("asistencias_1697673600000", ios::binary);

    if (!archivo.is_open()) {
        cout <<"Error al abrir el archivo: " << endl;
    }

    while(!archivo.eof()){

        Asistencia nuevaAsistencia;

        archivo.read((char *)& nuevaAsistencia.idCliente,sizeof(u_int);
        archivo.read((char *)& nuevaAsistencia.cantInscripciones,sizeof(u_int);


        Inscripcion * registrados= Inscripcion[nuevaAsistencia.cantInscripciones];
        Inscripcion * auxInscripciones= registrados;

        for(u_int i=0;i<nuevaAsistencia.cantInscripciones;i++){
            archivo.read((char *)auxInscripciones,sizeof(Inscripcion);
            auxInscripciones++;}

        nuevaAsistencia.CursosInscriptos = registrados;

     // Aumenta el tamaño del array y copia la nueva asistencia
        MisAsistencias nuevoAsistencias; //se crea una estructura de mis asistencias
        nuevoAsistencias.tamAsist = misAsistencias.tamAsist + 1; //por cada linea leida, aumenta en uno el tamaño del array
        nuevoAsistencias.arrayDeAsistencia = new MisAsistencias[nuevoAsistencias.tamAsist];//array de misasistencias dinámico
      // Reserva memoria para el array de Asistencia

      // Copia los existentes al nuevo array
        for (u_int i = 0; i < misAsistencias.tamAsist; ++i) {
            nuevoAsistencias.arrayDeAsistencia[i] = misAsistencias.arrayDeAsistencia[i];
        }

        // Agrega la estructura nueva al final del array
        nuevoAsistencias.arrayDeAsistencia[misAsistencias.tamAsist] = nuevaAsistencia;

        // Libera la memoria del antiguo array
        delete[] misAsistencias.arrayDeAsistencia;
        delete[] auxInscripciones;

        // Actualiza miGimnasio con el nuevo array
        misAsistencias = nuevoAsistencias;
    }
    // Cierra el archivo
    archivo.close();

    return;
}*/
