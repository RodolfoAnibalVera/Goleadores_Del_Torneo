#pragma once
#include "club.h"
#include <string>

class ArchivoClub
{
private:
    std::string _nombreArchivoClub;

public:
    ArchivoClub();
    ArchivoClub(std::string nombreArchivoClub);
    bool GuardarRegistroClub(Club club);
    bool ReescribirRegistroClub(int indice, Club club);
    int BuscarPorIDClub(int clubID);
    Club LeerRegistroClub(int posicion);
    int getCantidadRegistros();
    int GenerarNuevoIdClub();
    void LeerTodosClub(int cantidadRegistros, Club *vector);
};
