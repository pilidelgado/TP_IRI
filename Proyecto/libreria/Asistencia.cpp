#include <gimnasio.h>

int buscarPosAsistencia(MisAsistencias asist, int idCliente)
{
    int pos=-3;//inicializo en -3 por si no llego a encontrar al cliente
    for (int i = 0; i < asist.tamAsist ; i++) { // como se el tamaño del array de Asistencia
        if(asist.arrayDeAsistencia[i].idCliente == idCliente)//busco la posicion del cliente que me pasan en mi array de asistencia
            pos=i;//devuelvo la pos
    }
    return pos;
}

Asistencia* resizeAsistencia(MisAsistencias* asist) //Funcion resize
{
    Asistencia * aux= new Asistencia[asist->tamAsist++];

    if( aux!= nullptr)
    {
        for(int i=0; i<asist->tamAsist; i++)
            aux[i]=asist->arrayDeAsistencia[i];
    }

    return aux;
    delete[] aux;
}

void AgregarAsistencia(MisAsistencias* &asist,int idClienteIng, int idClaseAReservar,
                       time_t fechaDeInscripcion)
{
    asist->arrayDeAsistencia= resizeAsistencia(asist);
    asist->tamAsist++;
    //es asist->tamAsist-1 ya que aumente el tamaño de mi array, pero como este empieza en 0, y yo quiero agregar en la ultima posicion, tengo que hacerlo en la del tamaño -1
    /*Ej: si asist->tamAsist era =3, cuendo entro a esta funcion asist->tamAsist++;
     * asist->tamAsist=4, y yo tengo inicializado asist[0],[1],[2] y ahora tengo que modificar [3] (3=4-1)*/
    asist->arrayDeAsistencia[asist->tamAsist-1].cantInscripciones=1;
    asist->arrayDeAsistencia[asist->tamAsist-1].idCliente = idClienteIng;

    asist->arrayDeAsistencia[asist->tamAsist-1].CursosInscriptos = new Inscripcion[asist->arrayDeAsistencia[asist->tamAsist-1].cantInscripciones];//modifico mi array de inscripciones
    asist->arrayDeAsistencia[asist->tamAsist-1].CursosInscriptos[0].fechaInscripcion = fechaDeInscripcion;
    asist->arrayDeAsistencia[asist->tamAsist-1].CursosInscriptos[0].idClase=idClaseAReservar;
    return;
}

Inscripcion* resizeInscripcion(Asistencia* asistencia, u_int cantInscripciones)
{
    Inscripcion * aux= new Inscripcion[cantInscripciones++];

    if( aux!= nullptr)
    {
        for(u_int i=0; i < cantInscripciones; i++)
            aux[i]=asistencia->CursosInscriptos[i];
    }

    return aux;
    delete[] aux;
}

eAgregarInscripciones agregarInscripciones(MisAsistencias* &asist, int posAsistencia, int idClase,time_t fechadeinscripcion)
/*me pasa como parametros el array de mis asistencias para moficiar, la posicion del cliente
en mi array de aistencia, su id y el momento en el q se esta inscribiendo*/
{
    asist->arrayDeAsistencia[posAsistencia].CursosInscriptos= resizeInscripcion(&asist->arrayDeAsistencia[posAsistencia], asist->arrayDeAsistencia[posAsistencia].cantInscripciones);
    asist->arrayDeAsistencia[posAsistencia].cantInscripciones++;
    asist->arrayDeAsistencia[posAsistencia].CursosInscriptos[asist->arrayDeAsistencia[posAsistencia].cantInscripciones].fechaInscripcion=fechadeinscripcion;
    asist->arrayDeAsistencia[posAsistencia].CursosInscriptos[asist->arrayDeAsistencia[posAsistencia].cantInscripciones].idClase=idClase;

    return ExitoAgregado;
}

/*UNA POSIBLE CORRECION A ESTAS TRES FUNCIONES:
void AgregarAsistencia(MisAsistencias* &asist,int idClienteIng, int idClaseAReservar,
                       time_t fechaDeInscripcion)
{
    asist->arrayDeAsistencia= resizeAsistencia(asist);
    asist->tamAsist++;
    asist->arrayDeAsistencia[asist->tamAsist-1].cantInscripciones=1;
    asist->arrayDeAsistencia[asist->tamAsist-1].idCliente = idClienteIng;

    Inscripcion* temp = new Inscripcion[asist->arrayDeAsistencia[asist->tamAsist-1].cantInscripciones];
    if(temp == nullptr) {
        // Manejo de error
    } else {
        asist->arrayDeAsistencia[asist->tamAsist-1].CursosInscriptos = temp;
        asist->arrayDeAsistencia[asist->tamAsist-1].CursosInscriptos[0].fechaInscripcion = fechaDeInscripcion;
        asist->arrayDeAsistencia[asist->tamAsist-1].CursosInscriptos[0].idClase=idClaseAReservar;
    }
    return;
}

Inscripcion* resizeInscripcion(Asistencia* asistencia, u_int cantInscripciones)
{
    cantInscripciones++;
    Inscripcion * aux= new Inscripcion[cantInscripciones];

    if( aux!= nullptr)
    {
        for(u_int i=0; i < cantInscripciones - 1; i++)
            aux[i]=asistencia->CursosInscriptos[i];
    }

    return aux;
}

eAgregarInscripciones agregarInscripciones(MisAsistencias* &asist, int posAsistencia, int idClase,time_t fechadeinscripcion)
{
    Inscripcion* temp = resizeInscripcion(&asist->arrayDeAsistencia[posAsistencia], asist->arrayDeAsistencia[posAsistencia].cantInscripciones);
    if(temp == nullptr) {
        // Manejo de error
    } else {
        asist->arrayDeAsistencia[posAsistencia].CursosInscriptos = temp;
        asist->arrayDeAsistencia[posAsistencia].CursosInscriptos[asist->arrayDeAsistencia[posAsistencia].cantInscripciones].fechaInscripcion=fechadeinscripcion;
        asist->arrayDeAsistencia[posAsistencia].CursosInscriptos[asist->arrayDeAsistencia[posAsistencia].cantInscripciones].idClase=idClase;
        asist->arrayDeAsistencia[posAsistencia].cantInscripciones++;
    }

    return ExitoAgregado;
}

*/

