#include "consultasManager.h"
#include "jugador.h"
#include "goles.h"
#include "club.h"
#include "archivoJugador.h"
#include "archivoGoles.h"
#include "archivoClub.h"

#include <iostream>
using namespace std;


void ConsultasManager::buscarDNIjugador()
{
    int dni;
    jugador regJugador, regRespuesta;
    archivoJugador archJugador;

    cout<< "Ingrese DNI: ";
    cin>> dni;
    cout<<endl<<endl;

    int cantidadRegistros = archJugador.getCantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++)
    {
        regJugador = archJugador.leerJugador(i);

        if (regJugador.getDni()== dni)
        {
            regRespuesta = regJugador;
        }
    }

    if (regRespuesta.getDni()== dni)
    {
        regRespuesta.encabezadosJugador();
        regRespuesta.mostrar();
    }
    else
    {
        cout<< "Jugador no registrado o dado de baja!!"<<endl<<endl;
    }
}


void ConsultasManager::ClubesPorCodigo()
{
    ArchivoClub archClub("club.dat");
    Club registro;

    int cantRegistro = archClub.getCantidadRegistros();

    if(cantRegistro<1)
    {
        cout << "*Aun no hay registros*" << endl << endl;
        return;
    }

    int codClub;

    cout << "Ingrese El Codigo Del Club: ";
    cin>>codClub;
    cout << endl;
    bool cartel=false;

    for(int i=0; i<cantRegistro; i++)
    {
        registro = archClub.LeerRegistroClub(i);
        if(registro.getCodigoClub() == codClub && !registro.getEliminado())
        {

            registro.encabezadosClub();
            registro.mostrarClub();

            cartel=true;
            cout << endl;
        }
    }
    if(!cartel)
    {
        cout << "      ¡Error!" << endl << endl << "*El Club con el codigo ingresado no existe o se encuentra eliminado*" << endl << endl;
    }
}


void ConsultasManager::golesXpartido()
{
    int numPartido, contador=0;
    Goles registroGoles ;
    ArchivoGoles archivoGOLES;

    cout<< "Ingrese numero de partido: ";
    cin>> numPartido;
    cout<<endl<<endl;

    int cantidadRegistros = archivoGOLES.CantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++)
    {
        registroGoles = archivoGOLES.LeerGoles(i);

        if (registroGoles.getEliminado() != true && registroGoles.getNumeroDePartido() == numPartido)
        {
            contador++;
        }
    }

    if(contador>0)
    {
        registroGoles.encabezados();
        for(int i=0; i<cantidadRegistros; i++)
        {
            registroGoles = archivoGOLES.LeerGoles(i);

            if (registroGoles.getEliminado() != true && registroGoles.getNumeroDePartido() == numPartido)
            {
                registroGoles.mostrarEnColumna();

            }
        }
    }
    else
    {
        cout<< "No se econtro numero de partido o el registro esta eliminado!!"<<endl<<endl;
    }

}


void ConsultasManager::CantidadJugadoresPorNombreClub()
{
    //Dado un nombre de un club informar cuántos jugadores tiene inscriptos
    ArchivoClub archClub("club.dat");
    archivoJugador archJugador("jugador.dat");
    jugador registroJug;
    Club registroClub;

    int cantRegClub = archClub.getCantidadRegistros();
    int cantRegJugador = archJugador.getCantidadRegistros();
    if(cantRegClub<1)
    {
        cout << " No hay registros!"<<endl;
    }
    cout << "Ingrese nombre club: ";
    std::string nombreClub=" ";
    getline(cin, nombreClub);
    cout << endl;

    int contJugador=0;
    bool bandera=false;
    for (int i=0; i<cantRegClub; i++)
    {

        registroClub=archClub.LeerRegistroClub(i);
        if(nombreClub==registroClub.getNombreClub())
        {
            bandera=true;

            for(int j=0; j<cantRegJugador; j++)
            {

                registroJug=archJugador.leerJugador(j);
                if(registroClub.getCodigoClub()==registroJug.getCodigoClub())
                {
                    contJugador+=1;
                }
            }

        }
    }
    if(bandera)
    {
        cout << "Club: " << nombreClub << "  ---  Cantidad de jugadores: " << contJugador<<endl <<endl;
    }
    else
    {
        cout << "El nombre del Club ingresado no existe" << endl << endl;
    }

}
