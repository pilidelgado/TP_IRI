
#include <gimnasio.h>

int buscarPosAsistencia(MisAsistencias asist, int idCliente)
{
    int pos=-3;//inicializo en -1 por si no llego a encontrar al cliente
    for (int i = 0; i < asist.tamAsist ; i++) { // como se el tamaño del array de Asistencia
        if(asist.arrayDeAsistencia[i].idCliente == idCliente)//busco la posicion del cliente que me pasan en mi array de asistencia
            pos=i;//devuelvo la pos
    }
    return pos;
}


Asistencia* resizeAsistencia(MisAsistencias* asist)
{
    Asistencia * aux= new Asistencia[asist->tamAsist++];

    if( aux!= nullptr)
    {
        for(int i=0; i<asist->tamAsist; i++)
            aux[i]=asist->arrayDeAsistencia[i];
    }

    delete[] aux;
    return aux;
}

void AgregarAsistencia(MisAsistencias* &asist,u_int idClienteIng, u_int idClaseAReservar,time_t fechaInscripcion)
{
    asist->arrayDeAsistencia= resizeAsistencia(asist);
    asist->tamAsist++;
    asist->arrayDeAsistencia[asist->tamAsist].cantInscripciones=1;
    asist->arrayDeAsistencia[asist->tamAsist].idCliente=idClienteIng;
    asist->arrayDeAsistencia[asist->tamAsist].CursosInscriptos[asist->arrayDeAsistencia[asist->tamAsist].cantInscripciones].fechaInscripcion=fechaInscripcion;
    asist->arrayDeAsistencia[asist->tamAsist].CursosInscriptos[asist->arrayDeAsistencia[asist->tamAsist].cantInscripciones].idClase=idClaseAReservar;
    return;
}

Inscripcion* resizeInscripcion(Asistencia* asistencia, u_int cantInscripciones)
{
    Inscripcion * aux= new Inscripcion[cantInscripciones++];

    if( aux!= nullptr)
    {
        for(u_int i=0; i<cantInscripciones; i++)
            aux[i]=asistencia->CursosInscriptos[i];
    }

    delete[] aux;
    return aux;
}

eAgregarInscripciones agregarInscripciones(MisAsistencias* &asist, int posAsistencia, int idClase, time_t fechadeinscripcion)
{
    asist->arrayDeAsistencia[posAsistencia].CursosInscriptos= resizeInscripcion(asist->arrayDeAsistencia[posAsistencia], asist->arrayDeAsistencia[posAsistencia].cantInscripciones);
    asist->arrayDeAsistencia[posAsistencia].cantInscripciones++;
    asist->arrayDeAsistencia[posAsistencia].CursosInscriptos[asist->arrayDeAsistencia[posAsistencia].cantInscripciones].fechaInscripcion=fechadeinscripcion;
    asist->arrayDeAsistencia[posAsistencia].CursosInscriptos[asist->arrayDeAsistencia[posAsistencia].cantInscripciones].idClase=idClase;

    return ExitoAgregado;
}

