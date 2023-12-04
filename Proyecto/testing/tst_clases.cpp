//test clientes:

#include <catch2/catch.hpp>
#include "gimnasio.h"


TEST_CASE("Funcion HayCupo"){
    Gimnasio gymAux;
    gymAux.clases = new Clase[1];
    //creo algunas clases:
    gymAux.tamClases= 1;
    gymAux.clases[0].cupo=0;
    gymAux.clases[0].cupo_maximo=3;
    gymAux.clases[0].idClase=0;
    gymAux.clases[0].nombre = "clase0";

    // Hay cupo disponible
    CHECK(hayCupo(0,gymAux)==true);

    // Llenamos el cupo
    gymAux.clases[0].cupo = gymAux.clases[0].cupo_maximo;
    CHECK(hayCupo(0,gymAux)==false); // No debería haber cupo

    // Prueba con un ID de clase que no existe
    CHECK(hayCupo(1,gymAux)==false); // No debería haber cupo

    // Libero la memoria
    delete[] gymAux.clases;
}


//u_int buscarPosClase(Gimnasio gym, u_int horarioIng, string nombreClaseIng);
/*TEST_CASE("Buscar IdClase:"){
    //busco por hora y por nombre de la clase

    Gimnasio* gymAux = new Gimnasio;
    gymAux->clases = new Clase[3];
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

    int prueba1 = buscarIdClase(gymAux, 0, "clase0");
    int prueba2 = buscarIdClase(gymAux, 1, "clase1");
    int prueba3 = buscarIdClase(gymAux, 4, "clase22");

    CHECK(prueba1 == gymAux->clases[0].idClase);
    CHECK(prueba2 == 1);
    CHECK(prueba3 == -1);

    // Libera la memoria asignada
    delete[] gymAux->clases;
    delete gymAux;
}*/

/*TEST_CASE("Buscar PosClase"){
    Gimnasio gymAux;
    //creo algunas clases:
    gymAux.tamClases=3;//creo 3 clases
    gymAux.clases[0].cupo=0;
    gymAux.clases[0].cupo_maximo=3;
    gymAux.clases[0].idClase=0;
    gymAux.clases[0].nombre= "clase0";
    gymAux.clases[0].horario = 0;

    gymAux.clases[1].cupo=22;
    gymAux.clases[1].cupo_maximo=22;
    gymAux.clases[1].idClase=1;
    gymAux.clases[1].nombre= "clase1";
    gymAux.clases[1].horario = 1;

    gymAux.clases[2].cupo=4;
    gymAux.clases[2].cupo_maximo=10;
    gymAux.clases[2].idClase=2;
    gymAux.clases[2].nombre= "clase2";
    gymAux.clases[2].horario = 2;

    int posClasePrueba1 = buscarPosClase(gymAux, 0, "clase0");
    int posClasePrueba2 = buscarPosClase(gymAux, 3, "MAL");
    int posClasePrueba3 = buscarPosClase(gymAux, 1, "clase1");

    CHECK(posClasePrueba1 == 0);
    CHECK(posClasePrueba2 == -1);
    CHECK(posClasePrueba3 == 1);

}*/
//

/*TEST_CASE("Funcion HayCupo") {
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
    CHECK(hayCupo(1,gymAux)==false);
    CHECK(hayCupo(2,gymAux)==true);

    // Libera la memoria al finalizar
    delete[] gymAux.clases;
    delete[] gymAux.clientes;
} */
