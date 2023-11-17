//test clientes:

#include <catch2/catch.hpp>
#include "gimnasio.h"

TEST_CASE("My first test with Catch2", "[fancy]")
{
    REQUIRE(0 == 0);
}

/*TEST_CASE("Funcion crear IdCliente y nuevoCliente"){
    Gimnasio* gymAux = new Gimnasio;

    gymAux->tamClientes=3;//voy a tener 3 clientes de base
    //agrego algunos clientes en mi array de clientes dentro de gymAux:
    gymAux->clientes[0].nombre= "Lucas";
    gymAux->clientes[0].apellido= "Fernandez";
    gymAux->clientes[0].email= "lucas@mail.com";
    gymAux->clientes[0].telefono = "0000";
    gymAux->clientes[0].fechaNac = {4,12,2003};
    gymAux->clientes[0].idCliente = 0;

    CHECK(gymAux->clientes[0].nombre.compare ("Lucas")==0);

    gymAux->clientes[1].nombre= "Raul";
    gymAux->clientes[1].apellido= "Flores";
    gymAux->clientes[1].email= "raul@mail.com";
    gymAux->clientes[1].telefono = "0001";
    gymAux->clientes[1].fechaNac = {6,2,2003};
    gymAux->clientes[1].idCliente = 1;

    gymAux->clientes[2].nombre= "Lola";
    gymAux->clientes[2].apellido= "Garcia";
    gymAux->clientes[2].email= "lola@mail.com";
    gymAux->clientes[2].telefono = "0002";
    gymAux->clientes[2].fechaNac = {18,3,2001};
    gymAux->clientes[2].idCliente = 2;

    u_int idCarla;
    //me creo tres nuevos clientes
    idCarla= crearIdCliente("Carla", "Gomez", "carla@mail.com" , "1111" , {1,1,2000}, gymAux);
    //crearIdCliente(Jose, Fernandez, jose.mail.com , 1112 , {2,1,2000}, gymAux);
    // crearIdCliente(Pepe, Lopez, pepe.mail.com , 1113 , {3,1,2000}, gymAux);

    CHECK(strcmp(gymAux->clientes[3].nombre, "Carla")==0);
    CHECK(gymAux->tamClientes == 4); //me fijo si aumente el tamaño

    delete gymAux; //libero la memoria
}*/

TEST_CASE("Revisar Cliente"){

    Gimnasio gymAux;

    gymAux.tamClientes=3;//voy a tener 3 clientes de base
    //agrego algunos clientes en mi array de clientes dentro de gymAux:
    gymAux.clientes[0].nombre= "Lucas";
    gymAux.clientes[0].apellido= "Fernandez";
    gymAux.clientes[0].email= "lucas@mail.com";
    gymAux.clientes[0].telefono = "0000";
    gymAux.clientes[0].fechaNac = {4,12,2003};
    gymAux.clientes[0].idCliente = 0;

    gymAux.clientes[1].nombre= "Raul";
    gymAux.clientes[1].apellido= "Flores";
    gymAux.clientes[1].email= "raul@mail.com";
    gymAux.clientes[1].telefono = "0001";
    gymAux.clientes[1].fechaNac = {6,2,2003};
    gymAux.clientes[1].idCliente = 1;

    gymAux.clientes[2].nombre= "Lola";
    gymAux.clientes[2].apellido= "Garcia";
    gymAux.clientes[2].email= "lola@mail.com";
    gymAux.clientes[2].telefono = "0002";
    gymAux.clientes[2].fechaNac = {18,3,2001};
    gymAux.clientes[2].idCliente = 2;

    CHECK(RevisarCliente(0,gymAux)==true);
    CHECK(RevisarCliente(22,gymAux)==false);


}

TEST_CASE("Funcion buscar id de cliente por nombre y apellido"){
    Gimnasio gymAux;

    gymAux.tamClientes=3;//voy a tener 3 clientes de base
    //agrego algunos clientes en mi array de clientes dentro de gymAux:
    gymAux.clientes[0].nombre= "Lucas";
    gymAux.clientes[0].apellido= "Fernandez";
    gymAux.clientes[0].email= "lucas@mail.com";
    gymAux.clientes[0].telefono = "0000";
    gymAux.clientes[0].fechaNac = {4,12,2003};
    gymAux.clientes[0].idCliente = 0;

    gymAux.clientes[1].nombre= "Raul";
    gymAux.clientes[1].apellido= "Flores";
    gymAux.clientes[1].email= "raul@mail.com";
    gymAux.clientes[1].telefono = "0001";
    gymAux.clientes[1].fechaNac = {6,2,2003};
    gymAux.clientes[1].idCliente = 1;

    gymAux.clientes[2].nombre= "Lola";
    gymAux.clientes[2].apellido= "Garcia";
    gymAux.clientes[2].email= "lola@mail.com";
    gymAux.clientes[2].telefono = "0002";
    gymAux.clientes[2].fechaNac = {18,3,2001};
    gymAux.clientes[2].idCliente = 2;

    int idDeLucas, idDeRaul;
    idDeLucas = BuscarCliente("Lucas", "Fernandez",gymAux);
    idDeRaul = BuscarCliente("Raul", "Flores",gymAux);

    CHECK(idDeLucas == gymAux.clientes[0].idCliente);
    CHECK(idDeRaul == 1);
}

