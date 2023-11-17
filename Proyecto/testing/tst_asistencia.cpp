//test asistencia:
#include "archivos.h"
#include <catch2/catch.hpp>

TEST_CASE("My first test with Catch2", "[fancy]")
{
    REQUIRE(0 == 0);
}

/*TEST_CASE("Funcion buscar por asistencia"){
    MisAsistencias asistAux;
    asistAux.tamAsist=2;
    asistAux.arrayDeAsis
    asistAux->arrayDeAsistencia[0].cantInscripciones = 2;

    u_int buscarPosAsistencia(MisAsistencias asist, u_int idCliente)
{
    u_int pos=-3;//inicializo en -1 por si no llego a encontrar al cliente
    for (u_int i = 0; i < asist.tamAsist ; i++) { // como se el tamaño del array de Asistencia
        if(asist.arrayDeAsistencia[i].idCliente == idCliente)//busco la posicion del cliente que me pasan en mi array de asistencia
            pos=i;//devuelvo la pos
    }
    return pos;
}
    delete asistAux;
}*/
