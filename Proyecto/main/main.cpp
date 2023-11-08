#include <iostream>
using namespace std;

#include <ctime>
#include "archivos.h"
#include "gimnasio.h"
#include <fstream>
#include <sstream>

int main(int argc, char *argv[]) {

    u_int horarioIng=0, idClienteIng=0;
    string nombreIng, apellidoIng, emailIng,  telefonoIng, nombreClaseIng;
    Fecha fechaNacIng;
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
        cout << "Ingrese su fecha de nacimiento:"<< endl; //INGRESAR FECHA
        cin >> fechaNacIng;
        idClienteIng=crearIdCliente(nombreIng,apellidoIng,emailIng,telefonoIng,fechaNacIng,gym);
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
