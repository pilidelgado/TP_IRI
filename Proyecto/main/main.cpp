#include <iostream>
using namespace std;
#include "abrirArchivos.h"


int main(){
    Gimnasio gym;
    MisAsistencias asist;
    asist.tamAsist =0; //inicializo mi tamaño del arrat
    //inicializo a 0 los tamaños de los arrays de la estructura gimnasio
    gym.tamClases = 0;
    gym.tamClientes = 0; //MisAsistencias asist; //comentado xq falta resolver est parte

    ifstream archivo_clases;//me creo una variable del tipo ifstream
    archivo_clases.open("C:\\Users\\emmif\\source\\Trabajo Gym\\TP_IRI\\iriClasesGYM.csv",ios::in);

    if (!archivo_clases) {
        cout << "Error abriendo el archivo de clases" << endl;
        return 1;
    }

    ifstream archivo_clientes;
    archivo_clientes.open("C:\\Users\\emmif\\source\\Trabajo Gym\\TP_IRI\\iriClientesGYM.csv", ios::in); //me creo una variable del tipo ifstream

    if (!archivo_clientes){
        cout << "Error abriendo el archivo de clientes" << endl;
        return 1;
    }

    //leo archivos csv de clases y clientes
    leerClases_CSV(archivo_clases, gym);
    leerClientes_CSV(archivo_clientes, gym);

    // Llamo a mi funcion que inicializa mi array de clases:
    inicializarArrayClases0(gym.clases, gym.tamClases);
    //void inicializarArrayClases0(Clase *&arrayClases, int tamArray)

    int N= 1;

    for (int i = 0; N!=-1; i++) {
        cout << endl << "\tBienvenido a gimnasio Musculito."<<endl<< "\tIngrese los datos pedidos a continuacion:" << endl<<endl;

        int idClienteIng = rand() %  251;//llamo a una funcion random q genere un numero del 0 al 250
        cout << "Ingrese su Id de cliente:\t" << idClienteIng <<endl;
        /*//EN CASO DE AGREGARLO MANUAL:
        * cin >> idClienteIng;
        cin.ignore();//para q no me tome el enter */

        if(RevisarCliente(idClienteIng, gym)) //corrobora que el cliente exista y tenga la cuota al dia
        {

            string nombreClaseIng = nombreClaseAleatorio();
            cout << "Ingrese el nombre de la clase que quiera reservar:\t"<<nombreClaseIng<<endl;

            //getline(cin, nombreClaseIng);

            int horarioIng = rand() % 12 + 8; // 12 da un numero entre 0 11, se le suma 8
            cout<< "Ingrese su horario que quiera reservar:\t"<< horarioIng<<endl;

            //cin >> horarioIng;

            eResClase resultados = ReservaClases(horarioIng, nombreClaseIng, idClienteIng, asist, gym);//llamo a la función de reservar clases

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

       cout << endl << "\tPresione 1 para realizar otra reserva o -1 para finalizar."<<endl;
       cin>> N;
    }

    // Crear un archivo binario para escribir en él
    ofstream archivoBin("asistencias_diciembre.dat", ios::binary);
    if(!archivoBin.is_open()){
       cout << "Error al crear el archivo binario" <<endl<<endl;
       return eResClase :: ErrInscripcion;
    }

    // Llamar a la función escribirBinario
    escribirBinario(archivoBin, asist);

    // Cerrar el archivo binario
    archivoBin.close();
    /* ofstream archivoTxt("PruebaDeAsist.txt", ios::app);
                       if (!archivoTxt.is_open()) {
                           cout << "Error al crear el archivo binario" << endl << endl;
                           return eResClase::ErrInscripcion;
                       }
                   escribirTxt(archivoTxt, asist);
*/


    for(u_int i = 0; i < gym.tamClases; i++){
       delete[]gym.clases[i];
    }
    for(u_int i = 0; i < gym.tamClientes; i++){
       delete[]gym.clientes[i];
    }
    for(u_int i = 0; i < asist.tamAsist; i++){
       for(u_int j = 0; j < asist.arrayDeAsistencia[i].cantInscripciones; j++){
            delete[]asist.arrayDeAsistencia[i].CursosInscriptos[j];
       }
       delete[]asist.arrayDeAsistencia[i];
    }


    return 0;
}
