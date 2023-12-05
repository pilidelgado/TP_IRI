#include "gimnasio.h"
#include "abrirArchivos.h"

/*QUE HACE ESTA FUNCION?
 * dada un idClase y mi estructura de gymnasio que posee el array de clases, y cupo que es la cantidad de inscriptos en esa clase que tiene como
maximo la variable cupo_maximo. busca primero en el array de clases, la posicion de la clase pedida por el usuario, y luego se fija si el cupo de
aquella clase es menor al cupo maximo, en caso que lo sea, retorna verdadero y en el caso contrario, retorna falso*/


int buscarIdClase(Gimnasio *gym, int horarioIng, string nombreClaseIng){
    int idClaseAReservar= -1;
    for(int i=0; i < gym->tamClases; i++) //for que recorre el array de clases
    {
        if(horarioIng == gym->clases[i].horario && nombreClaseIng == gym->clases[i].nombre)
        {//busca el id coparando a partir del horario ingresado y el nombre de la clase
            idClaseAReservar = gym->clases[i].idClase;
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

// AgregarAsistencia(MisAsistencias* &asist,int idClienteIng,int idClaseAReservar, time_t fechaInscripcion);

string nombreClaseAleatorio() {
    // Nombres de las clases
    string nombres[] = {"Spinning", "Yoga", "Pilates", "Stretching", "Zumba", "Boxeo"};

    // Genera un índice aleatorio dentro del rango de la lista de nombres
    int indiceAleatorio = rand() % (sizeof(nombres) / sizeof(nombres[0]));

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
    int posReserva=-1;
    for(int i=0; i < gym.tamClases; i++) //for que recorre el array de clases
    {
        if(horarioIng == gym.clases[i].horario && nombreClaseIng == gym.clases[i].nombre){//busca el id coparando a partir del horario ingresado y el nombre de la clase
            posReserva = i;
            return posReserva; //si lo encuentra, lo retorna
        }
    }
    return posReserva; //si no lo encuentra, retorna -1
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

/*
void nuevoCliente(Gimnasio* gym, Cliente Ing)// agrega el cliente al array
{
    Cliente* aux = new Cliente[gym->tamClientes +1];

    for(u_int i = 0; i < gym->tamClientes +1 ; i++)
    {
        if(i< gym->tamClientes)
            aux[i] = gym->clientes[i];
        else
            aux[i]= Ing;
    }
    delete[] aux;
    gym->clientes = aux;
    gym->tamClientes++;
    return;
}

u_int crearIdCliente(string nombreIng, string apellidoIng, string emailIng, string telefonoIng, Fecha fechaNacIng, Gimnasio &gym) //crea un idCliente que no exista en mi clientes* Clientes
{
    Cliente *aux = new Cliente;

    u_int idCreado= gym.tamClientes + 1;
    aux->apellido=apellidoIng;
    aux->email=emailIng;
    aux->telefono=telefonoIng;
    aux->nombre=nombreIng;
    aux->estado=0;
    aux->idCliente=idCreado;
    aux->fechaNac=fechaNacIng;

    nuevoCliente(&gym, aux);
    delete aux;
    return idCreado;
}
*/

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




//Función principal:

eResClase ReservaClases (int horarioIng, string nombreClaseIng,
                        int idClienteIng, MisAsistencias &asist, Gimnasio &gym)
{/*parametros: horario pedido por el usuario, clase pedida por el usuario, el id del cliengte, mi estructura de MisAsistencia, y la estrcutura del Gym para modificarlo*/
    int idClaseAReservar, posReserva;
    //int errorResize=0;

    posReserva= buscarPosClase(gym,horarioIng, nombreClaseIng);//Funcion que busca mi posicion de la clase pedida en el array de clases
    idClaseAReservar= buscarIdClase(&gym, horarioIng, nombreClaseIng);//dado el horario pedido y el nombre de la clase, busco el id de esta

    if(posReserva== -1 || idClaseAReservar== -1)
        return eResClase :: ErrNoExisteClase;//retorno el error

    else{//si si encontro la clase y su pos:

        if(!hayCupo(idClaseAReservar, gym) || repetidos(gym, posReserva, idClienteIng))
            /*si es verdadero que hay cupo y es falso que esta repetido
             * (funcion repetidos: controla que la persona no esté inscripta en la misma clase dos veces)
             * (funcion que controla si hay lugar en la clase pedida por el usuario)
            */
            return eResClase :: ErrClienteRepetido; //error: o el cliente esta repetido o no hay cupo en la clase

        else //si devuelve false, lo inscribo
        {
            gym.clases[posReserva].cupo++;//aumento el cupo de la clase que me pidio el usuario
            int resultado = agregarAResevados(&gym, idClaseAReservar, idClienteIng);
            // agregarAResevados: funcion que agrega el id del cliente en el array de reservados de la clase que quiere reservar

            //agregarInscripcion=función que agregue los datos de inscripcion de la nueva clase a las clases propias del usuario

            if(resultado==-1)
                return eResClase :: ErrInscripcion; //no pude inscribir, xq no hay cupo, devuelvo error
            time_t fechaInscripcion = 0; //me guardo la hora en la q estoy inscribiendo

            int posAsistencia= buscarPosAsistencia(asist,idClienteIng); //busco la posicion de mi cliente en el array de asistencias

            if(posAsistencia== -3) //si es -3 significa q nunca se incribio a ninguna clase
                AgregarAsistencia(asist,idClienteIng,idClaseAReservar,fechaInscripcion);
            //si posAsistencia!=-3  significa que ya se habia inscripto a otras clases
            int error = agregarInscripciones(asist,posAsistencia,idClaseAReservar,fechaInscripcion);
            if(error == ErrInscripcion)
                return eResClase :: ErrInscripcion;

            time_t fechaInsc = time(nullptr); //se guarda en la variable el tiempo en segundos desde el 1/01/1970

            escribirBinario(idClienteIng, idClaseAReservar, fechaInsc);
        }
    }
    return ExitoReserva;
}



