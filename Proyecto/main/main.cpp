#include <iostream>
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

    for(i=0; i< gym.tamClases; i++)
        gym.clases[i].reservados[gym.clases[i].cupo_maximo];

    cin>> "Bienvenido al gimnasio Musculito, Ingrese su nombre:">> endl;
    cout<< nombreIng;
    cin>> "Ingrese su apellido:">> endl;
    cout<< apellidoIng;
    idClienteIng=BuscarCliente(nombreIng,apellidoIng,gym);

    if(idClienteIng==0)
    {
        cin>> "Inscribase en el gimansio, Ingrese su email:">> endl;
        cout<< emailIng;
        cin>> "Ingrese su telefono:">> endl;
        cout<< telefonoIng;
        cin>> "Ingrese su fecha de nacimiento:">> endl; //INGRESAR FECHA
        cout<< fechaNacIng;
        idClienteIng=crearIdCliente(nombreIng,apellidoIng,emailIng,tekefonoIng,fechaNacIng,gym);
    }

    if(RevisarCliente(idClienteIng,gym);)
    {
        cin>> "Ingrese el nombre de la clase que quiera reservar:">> endl;
        cout<< nombreClaseIng;
        cin>> "Ingrese su horario que quiera reservar:">> endl;
        cout<< horarioIng;
        error= ReservaClases(horarioIng,nombreClaseIng,idClienteIng,asist,gym);
    }
    
    return 0;
}
