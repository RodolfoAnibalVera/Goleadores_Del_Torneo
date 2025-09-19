#pragma once
#include "Fecha.h"
#include <string>

class Club
{

private:
    int _clubID;
    int _codigoClub;
    char _nombreClub[50];
    char _presidente[50];
    Fecha _fechaInscripcion;
    int _torneosGanados;
    bool _eliminado;

public:
    Club();
    Club(int clubID, int codigoClub, std::string nombreClub, std::string presidente, Fecha fechaInscripcion, int torneosGanados, bool eliminado);
    void setClubID(int clubID);
    void setCodigoClub(int codigoClub);
    void setNombreClub(std::string nombreClub);
    void setPresidente(std::string presidente);
    void setFechaInnscripcion(Fecha fechaInscripcion);
    void setTorneosGanados(int torneosGanados);
    void setEliminado(bool eliminado);

    int getClubID();
    int getCodigoClub();
    std::string getNombreClub();
    std::string getPresidente();
    Fecha& getFechaInscripcion();
    int getTorneosGanados();
    bool getEliminado();

    void cargarClub();
    void mostrarClub();

    std::string leerRegistroClubCSV();
    void encabezadosClub();
};
