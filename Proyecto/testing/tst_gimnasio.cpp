//test GIMNASIO:

#include <catch2/catch.hpp>
#include "gimnasio.h"

TEST_CASE("My first test with Catch2", "[fancy]")
{
    REQUIRE(0 == 0);
}


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



TEST_CASE("Revisar Cliente"){
    Gimnasio gym;//creo una variable de tipo un Gimnasio
    gym.tamClientes = 3;
    gym.clientes = new Cliente[gym.tamClientes];//creo un array dinamico de clientes para mi gym

    // Inicializo los clientes
    gym.clientes[0].idCliente = 1;
    gym.clientes[0].estado = 0;  //cuota al día
    gym.clientes[1].idCliente = 2;
    gym.clientes[1].estado = -1;  //cuota adeudada
    gym.clientes[2].idCliente = 3;
    gym.clientes[2].estado = 22;  //cuota por adelantado

    //verifico los resultados
    REQUIRE(RevisarCliente(1, gym) == true);//tiene la cuota al día
    CHECK(RevisarCliente(2, gym) == false); //le falta pagar
    CHECK(RevisarCliente(3, gym) == true); //pago por adelantado

    delete[] gym.clientes;//libero la memoria
}

//TESTING:
TEST_CASE("Funcion buscar id de cliente por nombre y apellido"){
    Gimnasio gymAux;
    gymAux.tamClientes=3;//voy a tener 3 clientes de base

    gymAux.clientes = new Cliente[gymAux.tamClientes];//reservo memoria para los clientes
    //agrego algunos clientes en mi array de clientes dentro de gymAux:
    gymAux.clientes[0].nombre= "Lucas";
    gymAux.clientes[0].apellido= "Fernandez";
    gymAux.clientes[0].idCliente = 0;

    gymAux.clientes[1].nombre= "Raul";
    gymAux.clientes[1].apellido= "Flores";
    gymAux.clientes[1].idCliente = 1;

    gymAux.clientes[2].nombre= "Lola";
    gymAux.clientes[2].apellido= "Garcia";
    gymAux.clientes[2].idCliente = 2;

    int idDeLucas, idDeRaul, idLola, idError;

    idDeLucas = BuscarCliente("Lucas", "Fernandez",gymAux);
    idDeRaul = BuscarCliente("Raul", "Flores",gymAux);
    idLola= BuscarCliente("Lola", "Garcia",gymAux);
    idError =BuscarCliente("Nadie", "Nada",gymAux);

    CHECK(idDeLucas == gymAux.clientes[0].idCliente);
    CHECK(idDeRaul == 1);
    CHECK(idLola != -1);
    CHECK(idError == -1);

    delete[] gymAux.clientes;// libero la memoria al final
}


//testing de la función nombreClaseAleatorio :
TEST_CASE("Funcion NombreClaseAleatorio") {
    SECTION("DevuelveNombreValido") {
        string nombre = nombreClaseAleatorio(); //creo un string y llamo a la funcion
        REQUIRE_FALSE(nombre.empty()); //corroboro que el nombre no sea vacio
    }

    SECTION("DevuelveNombresDiferentes") { //me fijo si me dos nombres diferentes
        string nombre1 = nombreClaseAleatorio();
        string nombre2 = nombreClaseAleatorio();
        CHECK(nombre1 == nombre2);
    }
}

TEST_CASE("Funcion Inicializar array de clases en 0"){
    int tamArray = 6;// Creo un array dinamico de Clase
    Clase* arrayClases = new Clase[tamArray];

    arrayClases[0].nombre = "Spinning";// Inicializo los nombres de las clases
    arrayClases[1].nombre = "Yoga";
    arrayClases[2].nombre = "Pilates";
    arrayClases[3].nombre = "Stretching";
    arrayClases[4].nombre = "Zumba ";
    arrayClases[5].nombre = "Boxeo";

    inicializarArrayClases0(arrayClases, tamArray);// Llamo a mi función

    // Verifico algunos valores de cupo_maximo, cupo y reservados
    REQUIRE(arrayClases[0].cupo_maximo == 45);
    CHECK(arrayClases[3].cupo == 0);
    CHECK(arrayClases[1].reservados[0] == 0);

    // Libero la memoria tanto de reservados como de array de clases
    for(int i = 0; i < tamArray; i++) {//como al crear un array de clases dinamico, genere respectivamente otros arrays dinamicos pero esta vez de reservados los elimino
        delete arrayClases[i].reservados;
    }
    delete arrayClases;//libero la memoria
}
