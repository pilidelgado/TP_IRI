#include "gimnasio.h"
#include "abrirArchivos.h"

/*QUE HACE ESTA FUNCION?
 * dada un idClase y mi estructura de gymnasio que posee el array de clases, y cupo que es la cantidad de inscriptos en esa clase que tiene como
maximo la variable cupo_maximo. busca primero en el array de clases, la posicion de la clase pedida por el usuario, y luego se fija si el cupo de
aquella clase es menor al cupo maximo, en caso que lo sea, retorna verdadero y en el caso contrario, retorna falso*/


int buscarIdClase(Gimnasio gym, int horarioIng, string nombreClaseIng){
    int idClaseAReservar= -1;
    for(int i=0; i < gym.tamClases; i++) //for que recorre el array de clases
    {
        if(horarioIng == gym.clases[i].horario && nombreClaseIng == gym.clases[i].nombre)
        {//busca el id coparando a partir del horario ingresado y el nombre de la clase
            idClaseAReservar = gym.clases[i].idClase;
        }
    }
    return idClaseAReservar;
}

int agregarAResevados(Gimnasio * gym, int idClase, int idCliente) //es *gym ya que modifico sus datos
//le paso la estructura de gym, el id de clase a reservar y el id del cliente que quiere reservar la clase
{
    int reservaRes=-1;//inicializo resultado en -1, siendo este el valor cundo indica error
    for(int i=0; i<gym->clases[idClase].cupo_maximo; i++)
    //recorro el array especifico de la clase dada hasta mi cupo maximo
    {
        if(gym->clases[idClase].reservados[i]==0)//mi array de reservados por clase esta inicializado en 0, en caso de que alguien se inscruba me guardo su id de cliente
        {
            gym->clases[idClase].reservados[i]= idCliente; //me guardo el idCliente en mi array de reservados
            reservaRes =0; //si me agrego a un cliente, cambio el resultado
            break; //hago un break para no copiarme al mismo clientes muchas veces
        }
    }
    return reservaRes;
} /*QUE HACE LA FUNCION? recorre el array de reservados de mi clase pedida y en caso de encontrar
una posicion donde no este un id, me guardo el id del cliente en esa posicion, retorno 0 si pude reservar
y -1 en caso contrario (indica error)*/

string nombreClaseAleatorio() {
    // Nombres de las clases
    string nombres[6] = {"Spinning", "Yoga", "Pilates", "Stretching", "Zumba", "Boxeo"};

    // Genera un índice aleatorio dentro del rango de la lista de nombres
    int indiceAleatorio = rand() % 6;

    // Devuelve el nombre seleccionado aleatoriamente
    return nombres[indiceAleatorio];
}


bool hayCupo(int idClase, Gimnasio gym)//me pasa el id de la clase y la estructura del gym
{
    int pos=0;//declaro mi indice y posicion:
    for (int i = 0; i < gym.tamClases; i++) { //for que recorre el array de clases
        if(gym.clases[i].idClase == idClase) //si encuentro el id me guardo la pos
            pos=i; //busco la pos de la clase con el id q me pasaron y me guardo su posicion en el array de clases dentro de gym
    }
    if(gym.clases[pos].cupo< gym.clases[pos].cupo_maximo) //si la cantidad de inscriptos es menor al maximo que tiene esa clase
        return true;//devuelvo q hay cupo
    else
        return false; //de lo contrario no hay cupo, retorno falso
}

/*QUE HACE ESTA FUNCION?
 * Dada mi estructura de gimnasio, un horario ingresado por el usuario y un
 * nombre de la clase que este quiere reservar, va a recorrer el array
de clases que se encuentra dentro de gym, comparando si la
clase de aquella posicion tienen el mismo nombre y el mismo horario, en caso que esto pase
se guarda el id de la clase que quiere reservar el cliente en la variable entera
 idClaseAReservar, la cual esta inicializada en -1 por si no llega a encontrarla */


int buscarPosClase(Gimnasio gym, int horarioIng, string nombreClaseIng){
    for(int i=0; i < gym.tamClases; i++) //for que recorre el array de clases
    {
        if(horarioIng == gym.clases[i].horario && nombreClaseIng == gym.clases[i].nombre){//busca el id coparando a partir del horario ingresado y el nombre de la clase
            return i;
        }
    }
    return -1; //si no lo encuentra, retorna -1
}


bool RevisarCliente(int idClienteIng, Gimnasio gym){
    for(int i=0; i < gym.tamClientes; i++)
    {
        if(gym.clientes[i].idCliente==idClienteIng && gym.clientes->estado >= 0) //revisa que el cliente exista y tenga la cuota al dia
            return true; //si lo encuentra, retorna true
    }
    return false; //si no lo encuentra, retorna false
}

/*
 QUE HACE LA FUNCION? recorre mi array de clases buscando si el cliente que me pasan segun el id
 tiene la cuota al dia, es decir que su estado es positivo; si esto pasa retorno verdadero de lo contrario retorno falso
*/

int BuscarCliente(string nombreIng, string apellidoIng, Gimnasio gym){
    int idClienteEncontrado=-1;//en caso de no encontrarlo devuelve -1
    for(int i=0; i < gym.tamClientes; i++)
    {
        if((apellidoIng== gym.clientes[i].apellido && nombreIng== gym.clientes[i].nombre))
            idClienteEncontrado =  gym.clientes[i].idCliente;
    }
    return idClienteEncontrado;
}/*QUE HACE LA FUNCION? dado un nombre y un apellido, recorre el array de clientes que se encuentra
dentro de gym  comparando el nombre y el apellido, si lo encuentra retorno su posicion en el array
de lo contrario retorno -1 (no encontre al cliente) */


bool repetidos(Gimnasio gym, int posClase, int idCliente ) //paso como parametro asistencia, en un cliente y un id de clase cual voy a comparar para ese cliente si ya esta repetido o no
{
    for (int i = 0; i < gym.clases[posClase].cupo_maximo ; i++) {//for que recorre la cantidad de veces q se inscribio el cliente
        if(gym.clases[posClase].reservados[i] == idCliente) //compara si ya se anoto a la clase
            return true;//retorna verdadero si ya esta anotado y falso si no
    }
    return false;
}

void inicializarArrayClases0(Clase *&arrayClases, int tamArray){
    for(int i= 0; i < tamArray; i++)
    {
        if(arrayClases[i].nombre == "Spinning"){
            arrayClases[i].cupo_maximo =45; //inicilizo el cupo cupo_maximo
            arrayClases[i].cupo =0;//como no tengo ningun cliente anotado por el momento inicializo en 0
            arrayClases[i].reservados = new int[arrayClases[i].cupo_maximo]; //vuelvo a reservados un array dinamico segun mi cupo maximo
            for(int j=0;j<arrayClases[i].cupo_maximo; j++)
                arrayClases[i].reservados[j]=0;//inicializo el array de reservados
        }
        if(arrayClases[i].nombre == "Yoga"){
            arrayClases[i].cupo_maximo =25; //inicilizo el cupo cupo_maximo
            arrayClases[i].cupo =0;//como no tengo ningun cliente anotado por el momento inicializo en 0
            arrayClases[i].reservados = new int[arrayClases[i].cupo_maximo]; //vuelvo a reservados un array dinamico segun mi cupo maximo
            for(int j=0;j<arrayClases[i].cupo_maximo; j++)
                arrayClases[i].reservados[j]=0;//inicializo el array de reservados
        }
        if(arrayClases[i].nombre == "Pilates")
        {
            arrayClases[i].cupo_maximo =15; //inicilizo el cupo cupo_maximo
            arrayClases[i].cupo =0;//como no tengo ningun cliente anotado por el momento inicializo en 0
            arrayClases[i].reservados = new int[arrayClases[i].cupo_maximo]; //vuelvo a reservados un array dinamico segun mi cupo maximo
            for(int j=0;j<arrayClases[i].cupo_maximo; j++)
                arrayClases[i].reservados[j]=0;//inicializo el array de reservados
        }
        if(arrayClases[i].nombre == "Stretching")
        {
            arrayClases[i].cupo_maximo =40; //inicilizo el cupo cupo_maximo
            arrayClases[i].cupo =0;//como no tengo ningun cliente anotado por el momento inicializo en 0
            arrayClases[i].reservados = new int[arrayClases[i].cupo_maximo]; //vuelvo a reservados un array dinamico segun mi cupo maximo
            for(int j=0;j<arrayClases[i].cupo_maximo; j++)
                arrayClases[i].reservados[j]=0;//inicializo el array de reservados
        }
        if(arrayClases[i].nombre == "Zumba ")
        {
            arrayClases[i].cupo_maximo =50; //inicilizo el cupo cupo_maximo
            arrayClases[i].cupo =0;//como no tengo ningun cliente anotado por el momento inicializo en 0
            arrayClases[i].reservados = new int[arrayClases[i].cupo_maximo]; //vuelvo a reservados un array dinamico segun mi cupo maximo
            for(int j=0;j<arrayClases[i].cupo_maximo; j++)
                arrayClases[i].reservados[j]=0;//inicializo el array de reservados
        }
        if(arrayClases[i].nombre == "Boxeo")
        {
            arrayClases[i].cupo_maximo =30; //inicilizo el cupo cupo_maximo
            arrayClases[i].cupo =0;//como no tengo ningun cliente anotado por el momento inicializo en 0
            arrayClases[i].reservados = new int[arrayClases[i].cupo_maximo]; //vuelvo a reservados un array dinamico segun mi cupo maximo
            for(int j=0;j<arrayClases[i].cupo_maximo; j++)
                arrayClases[i].reservados[j]=0;//inicializo el array de reservados
        }
        if(arrayClases[i].nombre == "Musculacion")
        {
            arrayClases[i].cupo_maximo =30; //inicilizo el cupo cupo_maximo
            arrayClases[i].cupo =0;//como no tengo ningun cliente anotado por el momento inicializo en 0
            arrayClases[i].reservados = new int[arrayClases[i].cupo_maximo]; //vuelvo a reservados un array dinamico segun mi cupo maximo
            for(int j=0;j<arrayClases[i].cupo_maximo; j++)
                arrayClases[i].reservados[j]=0;//inicializo el array de reservados
        }
    }
}/*QUE HACE LA FUNCION? Dado un array de clientes y su respectivo tamaño, compara los nombres y segun sea el caso
 inicializa esa clase especifica: cambia el cupo maximo, hace que el tamaño del array reservados sea cupo maximo, y pone el cupo en 0, ya que no hay nadie */

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

//Función principal:

eResClase ReservaClases(int horarioIng, string nombreClaseIng, int idClienteIng, MisAsistencias& asist, Gimnasio& gym) {/*parametros: horario pedido por el usuario, clase pedida por el usuario, el id del cliengte, mi estructura de MisAsistencia, y la estrcutura del Gym para modificarlo*/
    int idClaseAReservar, posReserva;
    //int errorResize=0;

    posReserva = buscarPosClase(gym, horarioIng, nombreClaseIng);//Funcion que busca mi posicion de la clase pedida en el array de clases
    idClaseAReservar = buscarIdClase(gym, horarioIng, nombreClaseIng);//dado el horario pedido y el nombre de la clase, busco el id de esta

    if (posReserva == -1 || idClaseAReservar == -1)
        return eResClase::ErrNoExisteClase;//retorno el error
    else {
        //si sí encontro la clase y su pos:
        if (!hayCupo(idClaseAReservar, gym) || repetidos(gym, posReserva, idClienteIng))
            return eResClase::ErrClienteRepetido; //error: o el cliente esta repetido o no hay cupo en la clase
        else //si devuelve false, lo inscribo
        {
            gym.clases[posReserva].cupo++;//aumento el cupo de la clase que me pidio el usuario
            int resultado = agregarAResevados(&gym, idClaseAReservar, idClienteIng);
            // agregarAResevados: funcion que agrega el id del cliente en el array de reservados de la clase que quiere reservar

            //agregarInscripcion=función que agregue los datos de inscripcion de la nueva clase a las clases propias del usuario

            if (resultado == -1)
                return eResClase::ErrInscripcion; //no pude inscribir, xq no hay cupo, devuelvo error
            else {
                time_t fechaInscripcion = 0; //me guardo la hora en la q estoy inscribiendo

                int posAsistencia = 0;
                if (asist.tamAsist > 0) {
                    posAsistencia = buscarPosAsistencia(asist, idClienteIng);
                    //busco la posicion de mi cliente en el array de asistencia
                    if (posAsistencia == -3) {
                        //si es -3 significa q nunca se incribio a ninguna clase

                        asist.tamAsist = asist.tamAsist + 1;//aumento un lugar en mi array de asistencias
                        Asistencia *aux = new Asistencia[asist.tamAsist]; //me creo array dinámico
                        posAsistencia = asist.tamAsist - 1;//la posicion en la q voy a guardar es en la ultima

                        for (int i = 0; i < asist.arrayDeAsistencia[posAsistencia].cantInscripciones; i++) {
                            aux[i] = asist.arrayDeAsistencia[i];
                        }

                        aux[posAsistencia].cantInscripciones = 1;
                        aux[posAsistencia].idCliente = idClienteIng;

                        Inscripcion* auxIns = new Inscripcion[aux.cantInscripciones];
                        auxIns[0].fechaInscripcion = fechaInscripcion;
                        auxIns[0].idClase = idClaseAReservar;
                        for (int i = 0; i < aux.cantInscripciones; ++i) {
                            aux[posAsistencia].CursosInscriptos[i] = auxIns[i];

                        }

                        delete[] auxIns;

                        asist.arrayDeAsistencia = aux;

                        delete [] aux;

                    }
                    if (posAsistencia != -3) {//si posAsistencia!=-3  significa que ya se habia inscripto a otras clases

                        asist.arrayDeAsistencia[posAsistencia].cantInscripciones = asist.arrayDeAsistencia[posAsistencia].cantInscripciones + 1;
                        Inscripcion* auxIns = new Inscripcion[asist.arrayDeAsistencia[posAsistencia].cantInscripciones];

                        for (int i = 0; i < asist.arrayDeAsistencia[posAsistencia].cantInscripciones; i++) {
                            auxIns[i] = asist.arrayDeAsistencia[posAsistencia].CursosInscriptos;
                        }

                        auxIns[asist.arrayDeAsistencia[posAsistencia].cantInscripciones].fechaInscripcion = fechaInscripcion;// en la ultima posicion
                        auxIns.idClase = idClaseAReservar;

                        asist.arrayDeAsistencia[posAsistencia].CursosInscriptos = auxIns;
                        delete[]auxIns;

                        /*
                    int error = agregarInscripciones(asist, posAsistencia,idClaseAReservar,fechaInscripcion);
                    if(error == ErrInscripcion)
                        return eResClase :: ErrInscripcion;*/

                    }

                }
                else {
                    posAsistencia = 0;
                    asist.tamAsist = asist.tamAsist + 1;
                    asist.arrayDeAsistencia = new Asistencia[asist.tamAsist];

                    asist.arrayDeAsistencia[0].cantInscripciones = 1;
                    asist.arrayDeAsistencia[posAsistencia].CursosInscriptos = new Inscripcion[asist.arrayDeAsistencia[0].cantInscripciones];

                    asist.arrayDeAsistencia[0].CursosInscriptos[0].fechaInscripcion = fechaInscripcion;
                    asist.arrayDeAsistencia[0].CursosInscriptos[0].idClase = idClaseAReservar;
                    asist.arrayDeAsistencia[0].idCliente = idClienteIng;

                }
            }

        }
    }
    return ExitoReserva;
}



