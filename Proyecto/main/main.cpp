#include <iostream>
using namespace std;

#include <ctime>
#include "archivos.h"
#include "gimnasio.h"
#include <fstream>
#include <sstream>

int main(int argc, char *argv[]) {

    ifstream infile;
    infile.open("iriClasesGYM.csv");
    if(!infile.is_open()) {
        cout << "Error abriendo el archivo CSV de clases" << endl;
        return 1;
    }
    u_int tamCla=0;
    Clase * clase_archivo= new Clase[tamCla];
    leerClases_CSV(infile,clase_archivo,tamCla);

    u_int horarioIng=0, idClienteIng=0;
    string nombreIng, apellidoIng, emailIng,  telefonoIng, nombreClaseIng;
    Fecha Fechaing;
    Gimnasio gym;
    int error;
    MisAsistencias asist;

    for(u_int i=0; i< gym.tamClases; i++)
        gym.clases[i].reservados[gym.clases[i].cupo_maximo];

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
        idClienteIng=crearIdCliente(nombreIng,apellidoIng,emailIng,telefonoIng,Fechaing,gym);
    }

    if(RevisarCliente(idClienteIng,gym)==true)
    {
        cout<< "Ingrese el nombre de la clase que quiera reservar:"<<endl;
        cin>> nombreClaseIng;
        cout<< "Ingrese su horario que quiera reservar:"<< endl;
        cin>> horarioIng;
        error= ReservaClases(horarioIng,nombreClaseIng,idClienteIng,asist,gym);//definir el error
    }
    






    return 0;
}
