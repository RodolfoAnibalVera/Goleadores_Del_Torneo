#include "archivoClub.h"

ArchivoClub::ArchivoClub()
{
    _nombreArchivoClub = "club.dat";
}

ArchivoClub::ArchivoClub(std::string nombreArchivoClub)
{
    _nombreArchivoClub = nombreArchivoClub;
}

bool ArchivoClub::GuardarRegistroClub(Club club)
{
    FILE *pArchivo = fopen(_nombreArchivoClub.c_str(), "ab");
    if(pArchivo == NULL)
    {
        return false;
    }
    bool registrado = fwrite(&club, sizeof(Club), 1, pArchivo);
    fclose(pArchivo);
    return registrado;
}

bool ArchivoClub::ReescribirRegistroClub(int indice, Club club)
{
    FILE *pArchivo = fopen(_nombreArchivoClub.c_str(), "rb+");
    if(pArchivo == NULL)
    {
        return false;
    }
    fseek(pArchivo, sizeof(Club) * indice, SEEK_SET);
    bool registrado = fwrite(&club, sizeof(Club), 1, pArchivo);
    fclose(pArchivo);
    return registrado;
}

int ArchivoClub::BuscarPorIDClub(int clubID)
{
    FILE *pArchivo = fopen(_nombreArchivoClub.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return -1;
    }
    Club club;
    int i = 0;
    while(fread(&club, sizeof(Club), 1, pArchivo)==1)
    {
        if(club.getClubID() == clubID)
        {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Club ArchivoClub::LeerRegistroClub(int posicion)
{
    FILE *pArchivo = fopen(_nombreArchivoClub.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return Club();
    }
    Club club;
    fseek(pArchivo, sizeof(Club) * posicion, SEEK_SET);
    fread(&club, sizeof(Club), 1, pArchivo);
    fclose(pArchivo);
    return club;
}

int ArchivoClub::getCantidadRegistros()
{
    FILE *pArchivo = fopen(_nombreArchivoClub.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Club);
    fclose(pArchivo);
    return cantidadRegistros;
}

int ArchivoClub::GenerarNuevoIdClub()
{
    int cantidad = getCantidadRegistros();

    if(cantidad > 0)
    {
        return LeerRegistroClub(cantidad-1).getClubID()+1;
    }
    else
    {
        return 1;
    }
}

void ArchivoClub::LeerTodosClub(int cantidadRegistros, Club *vector)
{
    FILE *pArchivo = fopen(_nombreArchivoClub.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vector[i], sizeof(Club), 1, pArchivo);
    }
    fclose(pArchivo);
}
