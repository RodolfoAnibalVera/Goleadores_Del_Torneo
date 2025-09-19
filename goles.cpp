#include <iostream>
#include "goles.h"
#include "ligaManager.h"
#include "archivoGoles.h"
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;

Goles::Goles()
{
//propiedades
// 1er constructor
    _golesID=0;
    _numeroDePartido=0;
    _dni=0;
    _tipoDeGol=0;
    _eliminado=true;
}
Goles::Goles(int goles,int numeroDePartido,int dni, int tipoDeGol, bool eliminado)
{
/// asignacion de variables
    _golesID=goles;
    _numeroDePartido=numeroDePartido;
    _dni=dni;
    _tipoDeGol=tipoDeGol;
    _eliminado=eliminado;
}

void Goles::setGolesID(int golesID)
{
    _golesID=golesID;
}
void Goles::setNumeroDePartido(int numeroDePartido)
{
    _numeroDePartido=numeroDePartido;
}
void Goles::setDNI(int Dni)
{
    _dni=Dni;
}
void Goles::setTipoDeGol(int TipoDeGol)
{
    _tipoDeGol=TipoDeGol;
}
void Goles::setEliminado(bool eliminado)
{
    _eliminado=eliminado;
}
////////////////////////////////////////
int Goles::getGolesID()
{
    return _golesID;
}
int Goles::getNumeroDePartido()
{
    return _numeroDePartido;
}
int Goles::getDNI()
{
    return _dni;
}
int Goles::getTipoDeGol()
{
    return _tipoDeGol;
}

bool Goles::getEliminado()
{
    return _eliminado;
}

void Goles::cargarGoles()
{
    Goles GOLES ;
    ArchivoGoles archivoGOLES;

    int  ingreso,golesID,numeroDePartido,dni,tipoDeGol;
    bool eliminado=false;
    cout<< "1= Comenzar inscripcion /  0= Salir: ";
    cin>> ingreso;
    system ("cls");
    while(ingreso == 1)
    {

        golesID=archivoGOLES.GenerarNuevoID();
        cout << "ID de Goles : ";
        cout<<golesID;
        cout << endl;
        cout << "Ingrese el numero del Partido: ";
        cin >> numeroDePartido;
        cout << endl;
        if(!ligaManager().cargarDNIGoleador(dni))
        {
            break;
        }


        cout << "Ingrese el tipo de gol segun las siguientes opciones "<<endl;
        cout << " Opcion 1 : Penal "<<endl;
        cout << " Opcion 2 : Tiro Libre "<<endl;
        cout << " Opcion 3 : Jugada en General "<<endl;
        bool bandera= false;
        while(!bandera)
        {

            cout <<"Ingrese Opcion : ";
            cin >> tipoDeGol;

            if(tipoDeGol > 0 && tipoDeGol < 4)
            {
                bandera = true;
            }
            else
            {

                cout<<endl<< "Ingrese una opcion correcta!!"<<endl<<endl;
                bandera = false;
            }
        };


        GOLES=Goles(golesID,numeroDePartido,dni,tipoDeGol,eliminado);

        if(archivoGOLES.Guardar(GOLES))
        {
            cout<<"El gol se guardo correctamente"<<endl;
            cout <<GOLES.leerRegistros()<< endl<<endl;

        }
        else
        {
            cout<<"No se pudo guardar correctamente "<<endl;

        }

        cout<< "Continuar inscripcion?"<<endl;
        cout<< "1=SI       0=NO: ";
        cin>> ingreso;
        cout<< "--------------------------------"<<endl;
    }

}


void Goles::mostrarEnColumna()
{
    std::string vecTipo[3]={"Penal", "Tiro libre", "Jugada"};

    std::cout << std::left
              << std::setw(10) << _golesID
              << std::setw(20) << _numeroDePartido
              << std::setw(20) << _dni
              << std::setw(10) << vecTipo[_tipoDeGol-1]
              << std::endl<<endl;

}

void Goles::encabezados()
{
    std::cout << std::left
              << std::setw(10) << "ID Gol"
              << std::setw(20) << "Num Partido"
              << std::setw(20) << "DNI"
              << std::setw(10) << "Tipo De Gol "

              << std::endl;

    std::cout << std::string(107, '-') << std::endl;
}



std::string Goles::leerRegistros()
{
    std::string str = "";

    str = to_string(_golesID) + ",";
    str += to_string(_numeroDePartido) + ",";
    str += to_string(_dni) + ",";
    str += to_string(_tipoDeGol) + ",";
    str += to_string(_eliminado);
    return str;






}
