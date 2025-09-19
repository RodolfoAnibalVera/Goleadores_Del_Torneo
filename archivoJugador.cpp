#include "archivoJugador.h"

archivoJugador::archivoJugador()
{
    _nombreArchivoJugador = "jugador.dat";
}
archivoJugador::archivoJugador(std::string nombreArchivoJugador)
{
    _nombreArchivoJugador = nombreArchivoJugador;
}

bool archivoJugador::guardarRegistro(jugador registroJugador)
{
    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivoJugador.c_str(), "ab");

    if(pFile==nullptr)
    {
        return false;
    }

    resultado = fwrite(&registroJugador, sizeof(jugador), 1, pFile);

    fclose(pFile);

    return resultado;
}

int archivoJugador::getCantidadRegistros()
{
    FILE *pFile;

    pFile = fopen(_nombreArchivoJugador.c_str(), "rb");

    if(pFile==nullptr)
    {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    int total = ftell(pFile);

    int cantidad = total / sizeof(jugador);

    fclose(pFile);

    return cantidad;
}

jugador archivoJugador::leerJugador(int posicion)
{
    FILE* pFile;
    jugador reg;

    pFile = fopen(_nombreArchivoJugador.c_str(), "rb");

    if(pFile==nullptr)
    {
        return reg;
    }

    fseek(pFile, sizeof(jugador)*posicion, SEEK_SET);

    fread(&reg, sizeof(jugador), 1, pFile);

    fclose(pFile);

    return reg;
}

void archivoJugador::leerTodos(jugador vecJugadores[], int cantidad)
{
    FILE* pFile;

    pFile = fopen(_nombreArchivoJugador.c_str(), "rb");

    if(pFile==nullptr)
    {
        return;
    }

    fread(vecJugadores, sizeof(jugador), cantidad, pFile);

    fclose(pFile);
}

int archivoJugador::buscarPorID(int id)
{
    FILE *pFile;
    jugador reg;
    int posicion=0;

    pFile = fopen(_nombreArchivoJugador.c_str(), "rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&reg, sizeof(jugador), 1, pFile)==1)
    {
        if(reg.getJugadorID() == id)
        {
            return posicion;
            fclose(pFile);
        }

        posicion++;
    }

    fclose(pFile);
    return -1;
}

bool archivoJugador::reescribirRegistro(int indice, jugador registroJugador)
{
    FILE *pfile;
    bool resultado;

    pfile= fopen(_nombreArchivoJugador.c_str(), "rb+");

    if(pfile == nullptr)
    {
        return false;
    }

    fseek(pfile, sizeof(jugador) * indice, SEEK_SET);

    resultado = fwrite(&registroJugador, sizeof(jugador), 1, pfile);

    fclose(pfile);

    return resultado;
}

int archivoJugador::generarNuevoId()
{
    int cantidad = getCantidadRegistros();

    if(cantidad > 0)
    {
        return leerJugador(cantidad-1).getJugadorID()+1;
    }
    else
    {
        return 1;
    }
}


