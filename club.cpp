#include "club.h"
#include "archivoClub.h"
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;

Club::Club()
{
    _clubID = 0;
    _codigoClub = 0;
    strcpy(_nombreClub, "");
    strcpy(_presidente, "");
    _fechaInscripcion = Fecha();
    _torneosGanados = 0;
    _eliminado = true;
}

Club::Club(int clubID, int codigoClub, std::string nombreClub, std::string presidente, Fecha fechaInscripcion, int torneosGanados, bool eliminado)
{
    setClubID(clubID);
    setCodigoClub(codigoClub);
    setNombreClub(nombreClub);
    setPresidente(presidente);
    setFechaInnscripcion(fechaInscripcion);
    setTorneosGanados(torneosGanados);
    setEliminado(eliminado);
}

//setters
void Club::setClubID(int clubID)
{
    _clubID=clubID;
}

void Club::setCodigoClub(int codigoClub)
{
    _codigoClub=codigoClub;
}

void Club::setNombreClub(std::string nombreClub)
{
    strcpy(_nombreClub, nombreClub.c_str());
}


void Club::setPresidente(std::string presidente)
{
    strcpy(_presidente, presidente.c_str());
}

void Club::setFechaInnscripcion(Fecha fechaInscripcion)
{
    _fechaInscripcion=fechaInscripcion;
}

void Club::setTorneosGanados(int torneosGanados)
{
    _torneosGanados=torneosGanados;
}

void Club::setEliminado(bool eliminado)
{
    _eliminado = eliminado;

}

//getters
int Club::getClubID()
{
    return _clubID;
}

int Club::getCodigoClub()
{
    return _codigoClub;
}

std::string Club::getNombreClub()
{
    return _nombreClub;
}

std::string Club::getPresidente()
{
    return _presidente;
}

Fecha& Club::getFechaInscripcion()
{
    return _fechaInscripcion;
}

int Club::getTorneosGanados()
{
    return _torneosGanados;
}

bool Club::getEliminado()
{
    return _eliminado;
}

void Club::cargarClub()
{
    Club club;
    ArchivoClub archivoClub;

    int ingreso, clubID, codigoClub, dia, mes, anio, torneosGanados;
    string nombreClub, presidente;
    bool eliminado = false;

    cout<< "1= Comenzar inscripcion /  0= Salir: ";
    cin>> ingreso;
    system("cls");

    while(ingreso == 1)
    {


        clubID = archivoClub.GenerarNuevoIdClub();
        cout << "ID del Club: ";
        cout << clubID;
        cout << endl;

        cout << "Codigo del Club: ";
        codigoClub = 1000 + archivoClub.GenerarNuevoIdClub();
        cout << codigoClub;
        cout << endl<<endl;

        cout << "Ingrese nombre del Club: ";
        cin.ignore();
        getline(cin, nombreClub);
        cout << endl;

        cout << "Ingrese nombre del Presidente: ";
        getline(cin, presidente);
        cout << endl;

        cout << "  Ingrese fecha de inscripcion " << endl;
        Fecha().cargarFecha(dia, mes, anio);

        cout << "Ingrese en numero, la cantidad de torneos ganados: ";
        cin >> torneosGanados;
        cout << endl;


        Fecha fechaInscripcion(dia, mes, anio);


        club = Club(clubID, codigoClub, nombreClub, presidente, fechaInscripcion, torneosGanados, eliminado);
        if(archivoClub.GuardarRegistroClub(club))
        {
            cout << "El Club se registro correctamente" << endl;
        }
        else
        {
            cout <<endl << "Hubo un error, vuelva a intentarlo o llame a soporte" << endl<<endl;
        }

        cout << endl << club.leerRegistroClubCSV() << endl << endl;

        cout << "Continuar inscripcion? "<<endl;
        cout << "1=SI       0=NO: ";
        cin>> ingreso;
        cout << endl;
    }
}

void Club::mostrarClub()
{
    std::cout << std::left
              << std::setw(10) << _clubID
              << std::setw(10) << _codigoClub
              << std::setw(30) << _nombreClub
              << std::setw(30) << _presidente
              << std::setw(15) << _fechaInscripcion.mostrarFecha()
              << std::setw(10) << _torneosGanados
              << std::endl<<endl;
}

std::string Club::leerRegistroClubCSV()
{
    std::string str = "";

    str = to_string(_clubID) + ",";
    str += to_string(_codigoClub) + ",";
    str += string(_nombreClub) + ",";
    str += string(_presidente) + ",";
    str += _fechaInscripcion.mostrarFecha()+ ",";
    str += to_string(_torneosGanados) + ",";
    str += to_string(_eliminado);
    return str;
}

void Club::encabezadosClub()
{
    std::cout << std::left
              << std::setw(10) << "ID"
              << std::setw(10) << "CodClub"
              << std::setw(30) << "NombreClub"
              << std::setw(30) << "Presidente"
              << std::setw(15) << "F. Inscripcion"
              << std::setw(10) << "T. Ganados"
              << std::endl;

    std::cout << std::string(107, '-') << std::endl;
}

