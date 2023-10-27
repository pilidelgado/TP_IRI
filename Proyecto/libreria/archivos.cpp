#include "libreria.h"
#include "structs.h"



//crear un struct aux de los datos q me van a ingresar
//funcion bool que se fije q la clase y ese horario existe y la llamo en la reserva

(NombreError) ReservaClases (u_int horarioIng, u_int idClase, string diaIng, u_int idClienteIng, Asistencia* asistencia, Gimnasio* gimnasio)

u_int i, j, k, l, m, pos1, pos2;
Gimnasio.*

   while(diaIng != “Domingo”)
   {
        if(!buscarCliente(idClienteIng)) //hacer fucion  bool de buscar cliente
           agendarCliente(idClienteIng);    //hacer funcion de  void agendarCliente

        for (i=0;i< Gimnasio.tamClases; i++)
        {

        }

                  Para i = 0 hasta N_Clases con paso 1 hacer // recorre archivo de clases

                     Si (Clase[i].Turno = TurnoPedido Y Clase[i].Tipo = ClasePedida Y
                     Clase[i].Cupo <= Clase[i].Máximo) entonces

                         pos1 = i;

                         Si (Cliente[j].DNI = DNIDado) entonces

                         Para k = 0 hasta Clase[pos1].Máximo con paso 1 hacer // recorre el array de
                         Reservados, que almacena los DNI de los clientes que ya reservaron un
                         lugar

                             Si (Clase[pos1].Reservados[k] != DNIDado) entonces // si no se encuentra
                             el DNI del cliente que quiere reservar:
                                  Clase[pos1].Cupo += 1;
                                  Clase[pos1].Reservados[k] = DNIDado;
                             Sino //si se encuentra, no puede reservar otro lugar
                                  Escribir(‘Usted ya reservó un lugar en esta clase’);
                                  Retornar;
                             Fin Si;

                         Fin Para;

                         Sino
                             Escribir(‘Usted no es cliente de Gimnasio Musculito’);
                         Fin Si;

                     Sino
                         Escribir(‘La clase que seleccionó no está disponible’);
                         Retornar;
                     Fin Si;
                  Fin Para;

         Sino // si el cliente es del grupo 2, musculación
                  Para l = 0 hasta 28 con paso 1 hacer //hay 28 bloques en total
                     Si (Musculación[l].Bloque = BloquePedido Y Musculación[l].Cupo <=
                     Musculación[l].Máximo) entonces

                         pos2 = l;

                         Si (Cliente[j].DNI = DNIDado) entonces

                           Para m = 0 hasta 30 con paso 1 hacer

                             Si (Musculación[pos2].Reservados[m] != DNIDado) entonces
                                  Musculación[pos2].Cupo += 1;
                                  Musculación[pos2].Reservados[k] = DNIDado;
                             Sino
                                  Escribir(‘Usted ya reservó un lugar en este bloque’);
                                  Retornar;
                             Fin Si;

                           Fin Para;

                         Sino
                           Escribir(‘Usted no es cliente de Gimnasio Musculito’);
                           Retornar;
                         Fin Si;

                     Sino
                           Escribir(‘El bloque que seleccionó no está disponible’);
                           Retornar;
                     Fin Si;
                  Fin Para;
         Fin Si;

      Fin Para;

   Sino
      Escribir(‘Gimnasio Musculito no da clases los domingos’);
      Retornar;
   Fin Si;

Fin Función;
