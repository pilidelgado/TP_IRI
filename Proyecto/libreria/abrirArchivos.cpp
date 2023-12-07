#include "abrirArchivos.h" // incluye gimnasio.h --> incluye asistencias.h --> incluye libreria.h

void resize(Clase* &clase_archivos, int &tamC)
{
    if(clase_archivos==nullptr){
        if(tamC<=0)
            clase_archivos = new Clase[tamC++];
        return;
    }

    Clase * aux= new Clase[tamC++];
    for(int i=0; i<tamC-1;i++){
        aux[i]=clase_archivos[i];
    }

    delete[] clase_archivos;
    clase_archivos=aux;
}


void leerClases_CSV(ifstream &archivo, Gimnasio& miGimnasio) {

    if (!archivo.is_open())
        cout << "Error abriendo el archivo CSV de clases" << endl;

    //Lee la primera línea del archivo
    string linea;
    getline(archivo, linea);


    //Lee los datos de cada línea del archivo
    while (getline(archivo, linea)){  //mientras el archivo esté abierto
        miGimnasio.tamClases++;//cuento la cantidad de clases que voy a tener
    }

    miGimnasio.clases= new Clase[miGimnasio.tamClases];

    archivo.clear();
    archivo.seekg(0, ios::beg); //reiniciar el índice

    getline(archivo, linea); // vuelvo a leer el encabezado

    stringstream dato;

    for(int i=0; i<miGimnasio.tamClases; i++){
        getline(archivo, linea);
        dato.clear();
        dato << linea; //12)leo una línea del archivo y separó cada dato individual de ella
        string id,hora;
        getline(dato,id,',');
        miGimnasio.clases[i].idClase= stoi(id); //paso mi dato de string a entero
        getline(dato,miGimnasio.clases[i].nombre,',');
        getline(dato,hora,',');
        miGimnasio.clases[i].horario = stoi(hora); //paso mi dato de string a entero
    }
    archivo.close();
    cout<<endl<<"Exitos al abrir el archivo de clases"<<endl<<endl;
}
void leerClientes_CSV(ifstream &archivo, gimnasio& miGimnasio) {

    if (!archivo.is_open())
        cout << "Error abriendo el archivo CSV de clientes" << endl;

    //Lee la primera línea del archivo
    string linea;
    getline(archivo, linea);

    //Lee los datos de cada línea del archivo
    while (getline(archivo, linea)){  //mientras el archivo esté abierto
        miGimnasio.tamClientes++;//cuento la cantidad de clientes que voy a tener
    }

    miGimnasio.clientes= new Cliente[miGimnasio.tamClientes];

    archivo.clear();
    archivo.seekg(0, ios::beg); //reiniciar el índice

    getline(archivo, linea); // vuelvo a leer el encabezado
    stringstream dato, aux;
    for(int i=0; i<miGimnasio.tamClientes; i++){
        getline(archivo, linea);
        dato.clear();
        dato << linea;//12)leo una línea del archivo y separó cada dato individual de ella

        string id,sdia,smes,sanyo,sestado,fecha;//mis variables del tipo string para pasar
        getline(dato,id,',');
        miGimnasio.clientes[i].idCliente= stoi(id); //paso mi dato de string a entero
        getline(dato,miGimnasio.clientes[i].nombre,',');
        getline(dato,miGimnasio.clientes[i].apellido,',');
        getline(dato,miGimnasio.clientes[i].email,',');
        getline(dato,miGimnasio.clientes[i].telefono,',');
        getline(dato,fecha,',');

        aux.clear();
        aux<<fecha;

        getline(aux,sdia,'-');
        miGimnasio.clientes[i].fechaNac.dia= stoi(sdia);
        getline(aux,smes,'-');
        miGimnasio.clientes[i].fechaNac.mes= stoi(smes);
        getline(aux,sanyo,',');
        miGimnasio.clientes[i].fechaNac.anio= stoi(sanyo);

        getline(dato,sestado,',');
        miGimnasio.clientes[i].estado= (float) stoi(sestado);
    }
    archivo.close();
    cout<<endl<<"Exitos al abrir el archivo de clientes"<<endl<<endl;
}

/*void leerClientes_CSV(gimnasio& miGimnasio) {

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
        for (int i = 0; i < miGimnasio.tamClientes; ++i) {
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
}*/

void escribirBinario(int idCliente, int idClase, time_t fechaInsc){
    ofstream archivoBin("asistencias_diciembre.dat", ios::binary);
    if(!archivoBin.is_open()){
        cout << "Error al crear el archivo binario" <<endl<<endl;//eror de un enum. ERROR AL ABRIR ARCHIVO
        return;
    }

    archivoBin.write((char*)&idCliente, sizeof(int));
    //se convierte el puntero del entero idCliente a un puntero tipo char.
    archivoBin.write((char*)&idClase, sizeof(int));
    archivoBin.write((char*)&fechaInsc, sizeof(time_t));

    archivoBin.close();
    return;
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
