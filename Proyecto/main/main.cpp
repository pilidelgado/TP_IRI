#include <iostream>
using namespace std;
#include "abrirArchivos.h"


int main() {
    Gimnasio gym;
    //inicializo a 0 los tamaños de los arrays de la estructura gimnasio
    gym.tamClases = 0;
    gym.tamClientes = 0;
    MisAsistencias asist;
    //leo archivos csv de clases y clientes
    leerClases_CSV(gym);
    leerClientes_CSV(gym);

    // Inicializa las clases
    for(u_int i=0; i<gym.tamClases; i++)
    {
        if(gym.clases[i].nombre == "Spinning")
        {
            gym.clases[i].cupo_maximo =45; //inicilizo el cupo cupo_maximo
            gym.clases[i].cupo =0;
            for(u_int j=0;j<gym.clases[i].cupo_maximo; j++)
                gym.clases[i].reservados[j]=0;//inicializo el array de reservados
        }
        if(gym.clases[i].nombre == "Yoga")
        {
            gym.clases[i].cupo_maximo =25; //inicilizo el cupo cupo_maximo
            gym.clases[i].cupo =0;
            for(u_int j=0;j<gym.clases[i].cupo_maximo; j++)
                gym.clases[i].reservados[j]=0;//inicializo el array de reservados
        }
        if(gym.clases[i].nombre == "Pilates")
        {
            gym.clases[i].cupo_maximo =15; //inicilizo el cupo cupo_maximo
            gym.clases[i].cupo =0;
            for(u_int j=0;j<gym.clases[i].cupo_maximo; j++)
                gym.clases[i].reservados[j]=0;//inicializo el array de reservados
        }
        if(gym.clases[i].nombre == "Stretching")
        {
            gym.clases[i].cupo_maximo =40; //inicilizo el cupo cupo_maximo
            gym.clases[i].cupo =0;
            for(u_int j=0;j<gym.clases[i].cupo_maximo; j++)
                gym.clases[i].reservados[j]=0;//inicializo el array de reservados
        }
        if(gym.clases[i].nombre == "Zumba ")
        {
            gym.clases[i].cupo_maximo =50; //inicilizo el cupo cupo_maximo
            gym.clases[i].cupo =0;
            for(u_int j=0;j<gym.clases[i].cupo_maximo; j++)
                gym.clases[i].reservados[j]=0;//inicializo el array de reservados
        }
        if(gym.clases[i].nombre == "Boxeo")
        {
            gym.clases[i].cupo_maximo =30; //inicilizo el cupo cupo_maximo
            gym.clases[i].cupo =0;
            for(u_int j=0;j<gym.clases[i].cupo_maximo; j++)
                gym.clases[i].reservados[j]=0;//inicializo el array de reservados
        }
    }


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
