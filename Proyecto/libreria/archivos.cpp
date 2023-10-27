u_int buscarPosAsistencia(Asistencia asist, u_int idCliente)
{

}

bool repetidos(Asistencia asist, u_int idCliente, u_int idClase)
{

}

void hayEspacio(Asistencia asist )
{

}
void nuevoSize(NSize &error, Asistencia asist , tam , u_int nuevoTam) { //va puntero?
    if(nuevoTam==0)
    {
        error= NSize :: ErrSize;
        return;
    }
    cliente* aux = new cliente[nuevoTam];

    u_int longitud = (NMAX < nuevoTam) ? NMAX: nuevoTam;

    if(aux == nullptr)
    {
        error= NTamaño :: ErrNull;
            return;
    }

    for(u_int i = 0; i < longitud; i++)
        aux[i] = lista[i];


    delete[] lista;
    lista = aux;

}

