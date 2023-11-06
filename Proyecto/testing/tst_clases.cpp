//test clientes:

#include <catch2/catch.hpp>
#include "archivos.h"
#include "gimnasio.h"

TEST_CASE("My first test with Catch2", "[fancy]")
{
    REQUIRE(0 == 0);
}

TEST_CASE("Funcion HayCupo"){
    Gimnasio* gymAux = new Gimnasio;
    //creo algunas clases:
    gymAux->tamClases=3;
    gymAux->clases[0].cupo=0;
    gymAux->clases[0].cupo_maximo=3;
    gymAux->clases[0].idClase=0;
    gymAux->clases[0].nombre= "clase0";

    gymAux->clases[1].cupo=22;
    gymAux->clases[1].cupo_maximo=22;
    gymAux->clases[1].idClase=1;
    gymAux->clases[1].nombre= "clase1";

    gymAux->clases[2].cupo=4;
    gymAux->clases[2].cupo_maximo=10;
    gymAux->clases[2].idClase=2;
    gymAux->clases[2].nombre= "clase2";

    CHECK(hayCupo(0,gymAux)==true);
    CHECK(hayCupo(1,gymAux)==false);
    CHECK(hayCupo(2,gymAux)==true);

    delete gymAux; //libero la memoria
}

