#include <iostream>
using namespace std;
#include <ctime>
#include "gimnasio.h"
#include "asistencias.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>


int main() {
    Gimnasio gym;
    //inicializo a 0 los tamaños de los arrays de la estructura gimnasio
    gym.tamClases = 0;
    gym.tamClientes = 0;

    //leo archivos csv de clases y clientes
    leerClases_CSV(gym);
    leerClientes_CSV(gym);

    MisAsistencias asist;

    cout << "Bienvenido a gimnasio Musculito. Ingrese los datos pedidos a continuación:" << endl;
    cout << "Ingrese su Id de cliente:" << endl;
    u_int idClienteIng = rand() %  249;

    if(RevisarCliente(idClienteIng, gym)) //corrobora que el cliente exista y tenga la cuota al dia
    {
        cout << "Ingrese el nombre de la clase que quiera reservar:"<<endl;
        string nombreClaseIng = nombreClaseAleatorio();
        cout<< "Ingrese su horario que quiera reservar:"<< endl;
        u_int horarioIng = rand() % 12 + 8; // 12 da un numero entre 0 11, se le suma 8
        eResClase resultados = ReservaClases(horarioIng,nombreClaseIng,idClienteIng,asist,&gym);//llamo a la función de reservar clases
        if(resultados == 0)
            cout << "Reserva hecha correctamente" << endl;
        else
            cout << "Hubo un problema a la hora de hacer la reserva, vuelva a intentarlo" << endl;
    }

 return 0;
}
