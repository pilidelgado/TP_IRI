#include <iostream>
using namespace std;

#include <ctime>
#include "clases.h"
#include "archivos.h"
#include "gimnasio.h"
#include <fstream>
#include <sstream>
#include "gimnasio.cpp"

/*
void leerClases_CSV(const char* iriClasesGYM, Gimnasio& miGimnasio) {
    std::ifstream archivo(iriClasesGYM);
    if (!archivo.is_open()) {
        std::cout << "Error abriendo el archivo CSV de clases" << std::endl;
        return;
    }

    // Lee la primera línea del archivo (encabezado)
    std::string encabezado;
    getline(archivo, encabezado);

    // Lee los datos de cada línea del archivo
    while (!archivo.eof()) {
        std::string linea;
        getline(archivo, linea);

        std::stringstream ss(linea);
        Clase nuevaClase;

        // Lee los valores de la línea
        ss >> nuevaClase.idClase >> nuevaClase.nombre >> nuevaClase.horario;

        // Aumenta el tamaño del array de clases y copia la nueva clase
        Gimnasio nuevoGimnasio;
        nuevoGimnasio.tamClases = miGimnasio.tamClases + 1;
        nuevoGimnasio.clases = new Clase[nuevoGimnasio.tamClases];

        // Copia las clases existentes al nuevo array
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

void leerClientes_CSV(const char* nombreArchivo, gimnasio& miGimnasio) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error abriendo el archivo CSV de clientes" << endl;
        return;
    }

    // Lee la primera línea del archivo (encabezado) si es necesario
    string encabezado;
    getline(archivo, encabezado);

    // Lee los datos de cada línea del archivo
    while (!archivo.eof()) {
        string linea;
        getline(archivo, linea);

        if (linea.empty()) {
            continue;  // Salta líneas vacías
        }

        stringstream ss(linea);
        Cliente nuevoCliente;

        // Parsea los valores de la línea
        ss >> nuevoCliente.idCliente >> nuevoCliente.nombre >> nuevoCliente.apellido
            >> nuevoCliente.email >> nuevoCliente.telefono
            >> nuevoCliente.fechaNacimiento.dia >> nuevoCliente.fechaNacimiento.mes >> nuevoCliente.fechaNacimiento.anio
            >> nuevoCliente.estado;

        // Aumenta el tamaño del array de clientes y copia el nuevo cliente
        gimnasio nuevoGimnasio;
        nuevoGimnasio.tamClientes = miGimnasio.tamClientes + 1;
        nuevoGimnasio.clientes = new Cliente[nuevoGimnasio.tamClientes];

        // Copia los clientes existentes al nuevo array
        for (u_int i = 0; i < miGimnasio.tamClientes; ++i) {
            nuevoGimnasio.clientes[i] = miGimnasio.clientes[i];
        }

        // Agrega el nuevo cliente al final del array
        nuevoGimnasio.clientes[miGimnasio.tamClientes] = nuevoCliente;

        // Libera la memoria del antiguo array
        delete[] miGimnasio.clientes;

        // Actualiza miGimnasio con el nuevo array
        miGimnasio = nuevoGimnasio;
    }

    archivo.close();
}*/

/*
int main() {
    const char* archivoClases = "clases.csv";
    const char* archivoClientes = "clientes.csv";

    gimnasio miGimnasio;
    miGimnasio.clases = nullptr;  // Inicializa a nullptr para que sea seguro delete[] más adelante
    miGimnasio.tamClases = 0;
    miGimnasio.clientes = nullptr;  // Inicializa a nullptr para que sea seguro delete[] más adelante
    miGimnasio.tamClientes = 0;

    leerClases_CSV(archivoClases, miGimnasio);
    leerClientes_CSV(archivoClientes, miGimnasio);

    // Haz lo que necesites con los datos cargados

    // Libera la memoria asignada para el array de clases
    delete[] miGimnasio.clases;
    // Libera la memoria asignada para el array de clientes
    delete[] miGimnasio.clientes;
    return 0;
}*/

/*
int main(int argc, char *argv[]) {

    ifstream infile;
    infile.open("iriClasesGYM.csv");
    if(!infile.is_open()) {
        cout << "Error abriendo el archivo CSV de clases" << endl;
        return 1;
    }

    u_int tamCla = 0;
    Clase * clase_archivo= new Clase[tamCla];
   // leerClases_CSV(infile,clase_archivo,tamCla);

    u_int horarioIng=0, idClienteIng=0;
    string nombreIng, apellidoIng, emailIng,  telefonoIng, nombreClaseIng;
    Fecha Fechaing;
    Gimnasio gym;
    int error;
    MisAsistencias asist;

    //for(u_int i=0; i< gym.tamClases; i++)
      //  gym.clases[i].reservados.gym.clases[i].cupo_maximo;

    cout << "Bienvenido al gimnasio Musculito, Ingrese su nombre:"<<endl;
    cin >>nombreIng;
    cout<< "Ingrese su apellido:"<< endl;
    cin>> apellidoIng;
    idClienteIng=BuscarCliente(nombreIng,apellidoIng,gym);


    if(idClienteIng==0)
    {
        cout << "Inscribase en el gimansio, Ingrese su email:"<< endl;
        cin >> emailIng;
        cout << "Ingrese su telefono:"<<endl;
        cin >> telefonoIng;
        cout << "Ingrese su el dia de su fecha de nacimiento:"<< endl;
        cin >> Fechaing.dia;
        cout << "Ingrese su el mes de su fecha de nacimiento:"<< endl;
        cin >> Fechaing.mes;
        cout << "Ingrese su el anio de su fecha de nacimiento:"<< endl;
        cin >> Fechaing.anio;
        //idClienteIng=crearIdCliente(nombreIng,apellidoIng,emailIng,telefonoIng,Fechaing,gym);
    }

    if(RevisarCliente(idClienteIng,gym)==true)
    {
        cout<< "Ingrese el nombre de la clase que quiera reservar:"<<endl;
        cin>> nombreClaseIng;
        cout<< "Ingrese su horario que quiera reservar:"<< endl;
        cin>> horarioIng;
        error= ReservaClases(horarioIng,nombreClaseIng,idClienteIng,asist,gym);//definir el error
    }

    infile.close();
    return 0;
} */
