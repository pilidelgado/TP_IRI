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


void leerClases_CSV(ifstream &archivo, Gimnasio &miGimnasio) {

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
void leerClientes_CSV(ifstream &archivo2, Gimnasio &miGimnasio) {

    if (!archivo2.is_open())
        cout << "Error abriendo el archivo CSV de clientes" << endl;

    //Lee la primera línea del archivo
    string linea;
    getline(archivo2, linea);

    //Lee los datos de cada línea del archivo
    while (getline(archivo2, linea)){  //mientras el archivo esté abierto
        miGimnasio.tamClientes++;//cuento la cantidad de clientes que voy a tener
    }

    miGimnasio.clientes= new Cliente[miGimnasio.tamClientes];

    archivo2.clear();
    archivo2.seekg(0, ios::beg); //reiniciar el índice

    getline(archivo2, linea); // vuelvo a leer el encabezado
    stringstream dato, aux;
    for(int i=0; i<miGimnasio.tamClientes; i++){
        getline(archivo2, linea);
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
    archivo2.close();
    cout<<endl<<"Exitos al abrir el archivo de clientes"<<endl<<endl;
}

/*void escribirTxt(ofstream& archivoTxt, MisAsistencias& asist) {
    if (archivoTxt.is_open()) {
        // Escribir cada elemento de arrayDeAsistencia
        for (int i = 0; i < asist.tamAsist; ++i) {
            archivoTxt << asist.arrayDeAsistencia[i].idCliente << "," << asist.arrayDeAsistencia[i].cantInscripciones << ", { ";

            // Escribir el Cliente completo en el archivo
            for (int j = 0; j < asist.arrayDeAsistencia[i].cantInscripciones; ++j) {
                archivoTxt << asist.arrayDeAsistencia[i].CursosInscriptos[j].idClase << ":" << asist.arrayDeAsistencia[i].CursosInscriptos[j].fechaInscripcion;
                if (j < asist.arrayDeAsistencia[i].cantInscripciones - 1) {
                    archivoTxt << ", ";
                }
            }

            archivoTxt << " }" << endl;
        }

        // Verificar si hubo errores durante la escritura
        if (!archivoTxt) {
            cout << "Error al escribir en el archivo txt." << endl;
        }
        else {
            cout << "Escritura exitosa en el archivo txt." << endl;
        }
    }
    else {
        cout << "Error al abrir el archivo txt." << endl;
    }

    archivoTxt.close();
}*/
void escribirBinario(ofstream &archivoBin, MisAsistencias &asist) {
    if (archivoBin.is_open()) {
        // Escribir cada elemento de arrayDeAsistencia
        for (int i = 0; i < asist.tamAsist; ++i) {
            // Escribir el Cliente completo en el archivo
            archivoBin.write((char*)&asist.arrayDeAsistencia[i].idCliente, sizeof(int));
            archivoBin.write((char*)&asist.arrayDeAsistencia[i].cantInscripciones, sizeof(int));

            for (int j = 0; j < asist.arrayDeAsistencia[i].cantInscripciones; ++j)
                archivoBin.write((char*)&asist.arrayDeAsistencia[i].CursosInscriptos[j], sizeof(Inscripcion));
        }

        // Verificar si hubo errores durante la escritura
        if (!archivoBin) {
            cout << "Error al escribir en el archivo binario." << endl;
        } else {
            cout << "Escritura exitosa en el archivo binario." << endl;
        }
    } else {
        cout << "Error al abrir el archivo binario." << endl;
    }

    archivoBin.close();
}


/*VERSION VIEJA
 * void escribirBinario(ofstream &archivoBin, MisAsistencias &asist){

    if(archivoBin.is_open()){
        for (int i = 0; i < asist.tamAsist; ++i) {
            archivoBin.write((char*)&asist.arrayDeAsistencia[i].idCliente, sizeof(int));
            archivoBin.write((char*)&asist.arrayDeAsistencia[i].cantInscripciones, sizeof(int));

            for (int j = 0; j < asist.arrayDeAsistencia[i].cantInscripciones; ++j)
                archivoBin.write((char*)&asist.arrayDeAsistencia[i].CursosInscriptos[j], sizeof(Inscripcion));
        }
    }
    //se convierte el puntero del entero idCliente a un puntero tipo char.

    archivoBin.close();

    return;
}*/





