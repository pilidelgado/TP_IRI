#include <iostream>
using namespace std;
#include "abrirArchivos.h"


int main(){
    Gimnasio gym;
    MisAsistencias asist;
    //inicializo a 0 los tamaños de los arrays de la estructura gimnasio
    gym.tamClases = 0;
    gym.tamClientes = 0;
            //MisAsistencias asist; //comentado xq falta resolver est parte
    //leo archivos csv de clases y clientes
    leerClases_CSV(gym);
    leerClientes_CSV(gym);

    // Llamo a mi funcion que inicializa mi array de clases:
    inicializarArrayClases0(gym.clases, gym.tamClases);

    cout << "Bienvenido a gimnasio Musculito. Ingrese los datos pedidos a continuación:" << endl;
    cout << "Ingrese su Id de cliente:" << endl;
    u_int idClienteIng = rand() %  251;//llamo a una funcion random q genere un numero del 0 al 250

    if(RevisarCliente(idClienteIng, gym)) //corrobora que el cliente exista y tenga la cuota al dia
    {
        cout << "Ingrese el nombre de la clase que quiera reservar:"<<endl;
        string nombreClaseIng = nombreClaseAleatorio();
        cout<< "Ingrese su horario que quiera reservar:"<< endl;
        u_int horarioIng = rand() % 12 + 8; // 12 da un numero entre 0 11, se le suma 8
        eResClase resultados = ReservaClases(horarioIng, nombreClaseIng, idClienteIng, asist, &gym);//llamo a la función de reservar clases
        switch(resultados) {
        case -3:{
            cout << "Hubo un error en la inscripción"<<endl <<"Vuelva a intentarlo" << endl;
                break;
        }
        case -2:{
            cout << "La clase ingresada no existe"<<endl<<"Vuelva a intentarlo" << endl;
                break;
        }
        case -1:{
            cout << "El cliente ya se encuentra anotado" << endl;
                break;
        }
        case 0:{
                cout << "Reserva hecha correctamente"<<endl;
                break;
        }
       }
    }
    return 0;
}
