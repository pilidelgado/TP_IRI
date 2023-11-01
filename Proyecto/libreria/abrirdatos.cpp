#include "archivos.h"
#include "gimnasio.h"
#include <fstream>

#define ArchivoClase "C:\Users\emmif\source\Dataset TP (1)"

Clase* leer(){
    ifstream infile;
    string line = "";
    char delimitador = ",";
    Clase ArrayClase[60];

    u_int w=0,c;
    infile.open("iriClasesGYM.csv",ios::in);
    while(getline(infile,line))
    {
        w++;
        c=0;
        stringstream strstr(line);
        string palabra = "";
        //cada linea la separa x la coma
        while(getline(strstr,palabra,delimitador))
        {
            c++
                if(w!=1){
                for(u_int i=0; i<60;i++){
                    if(c==1)
                        ArrayClase[i].idClase = (u_int)palabra;
                    if(c==2)
                        ArrayClase[i].nombre = palabra;
                    if(c==3)
                       ArrayClase[i].horario = (u_int)palabra;
                }

            }
        }
    }
    infile.close();
    return  *ArrayClase;
}


