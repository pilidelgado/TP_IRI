//test clientes:

#include <catch2/catch.hpp>
#include "gimnasio.h"

TEST_CASE("My first test with Catch2", "[fancy]")
{
    REQUIRE(0 == 0);
}

TEST_CASE("Funcion HayCupo"){
    Gimnasio gymAux;

    //creo algunas clases:
    gymAux.tamClases= 1;
    gymAux.clases[0].cupo=0;
    gymAux.clases[0].cupo_maximo=3;
    gymAux.clases[0].idClase=0;
    gymAux.clases[0].nombre = "clase0";


    CHECK(hayCupo(0,gymAux)==true);

    /*CHECK(hayCupo(1,gymAux)==false);
    CHECK(hayCupo(2,gymAux)==true);
    */
    return;
}

//u_int buscarPosClase(Gimnasio gym, u_int horarioIng, string nombreClaseIng);
/*TEST_CASE("Buscar IdClase:"){
    //u_int buscarIdClase(Gimnasio gym, u_int horarioIng, string nombreClaseIng);
    //busco por hora y por nombre de la clase

    Gimnasio* gymAux = new Gimnasio;
    //creo algunas clases:
    gymAux->tamClases=3;
    gymAux->clases[0].cupo=0;
    gymAux->clases[0].cupo_maximo=3;
    gymAux->clases[0].idClase=0;
    gymAux->clases[0].nombre= "clase0";
    gymAux->clases[0].horario = 0;

    gymAux->clases[1].cupo=22;
    gymAux->clases[1].cupo_maximo=22;
    gymAux->clases[1].idClase=1;
    gymAux->clases[1].nombre= "clase1";
    gymAux->clases[1].horario = 1;

    gymAux->clases[2].cupo=4;
    gymAux->clases[2].cupo_maximo=10;
    gymAux->clases[2].idClase=2;
    gymAux->clases[2].nombre= "clase2";
    gymAux->clases[2].horario = 2;

    u_int prueba1 =buscarIdClase(gymAux, 0, "clase0");
    u_int prueba2 = buscarIdClase(gymAux, 1, "clase1");
    u_int prueba3 = buscarIdClase(gymAux, 4, "clase22");

    CHECK(prueba1 == gymAux->clases[0].idClase);
    CHECK(prueba2 == 1);
    CHECK(prueba3 == -1);

    delete gymAux; //libero la memoria
}

*/

TEST_CASE("Funcion HayCupo") {
    Gimnasio gymAux;
    // Reserva espacio para las clases y clientes
    gymAux.clases = new Clase[1];
    gymAux.clientes = new Cliente[1];

    // Configura algunas clases
    gymAux.tamClases = 1;
    gymAux.clases[0].cupo = 0;
    gymAux.clases[0].cupo_maximo = 3;
    gymAux.clases[0].idClase = 0;
    gymAux.clases[0].nombre = "clase0";

    CHECK(hayCupo(0, gymAux) == true);
    /*CHECK(hayCupo(1,gymAux)==false);
    CHECK(hayCupo(2,gymAux)==true);
    */

    // Libera la memoria al finalizar
    delete[] gymAux.clases;
    delete[] gymAux.clientes;
}
