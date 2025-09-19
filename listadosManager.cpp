#include "ligaManager.h"
#include "listadosManager.h"
#include "jugador.h"
#include "club.h"
#include "goles.h"
#include "archivoJugador.h"
#include "archivoClub.h"
#include "archivoGoles.h"
#include "utilidades.h"

#include <iostream>
using namespace std;

/// LISTADOS
void ListadosManager::JugadoresXapellido()
{
    jugador aux;

    int cantRegistros = archivoJugador().getCantidadRegistros();

    jugador *registros;

    registros = new jugador[cantRegistros];

    if(registros==nullptr)
    {
        cout<< "No se pudo pedir memoria!"<<endl;
        return;
    }

    archivoJugador().leerTodos(registros, cantRegistros);

    for (int i = 0; i < cantRegistros - 1; i++)
    {
        for (int j = i + 1; j < cantRegistros; j++)
        {
            if (aMinuscula(registros[i].getApellido()) > aMinuscula(registros[j].getApellido()))
            {
                aux = registros[i];
                registros[i] = registros[j];
                registros[j] = aux;
            }
        }
    }

    if(cantRegistros > 0)
    {

        for(int x=0; x<cantRegistros; x++)
        {
            if(registros[x].getEliminado() != true)
            {

                cout<< registros[x].getApellido()<< " (ID: "<< registros[x].getJugadorID()<< ")"  <<endl<<endl;
            }
        }
    }
    else
    {
        cout<< "No hay registros"<<endl;
    }

    delete []registros;
}


void  ListadosManager::ClubesPorNombre()
{
    /// Listado de clubes ordenados por nombre.
    ArchivoClub archClub("club.dat");
    Club registro;

    int cantRegistro = archClub.getCantidadRegistros();

    if(cantRegistro<1){
        cout << "*Aun no hay registros*" << endl << endl;
        return;
    }

    std::string *nombreClub = nullptr;

    nombreClub = new std::string[cantRegistro];

    if(nombreClub == nullptr)
    {
        cout<< "No se pudo pedir memoria!"<<endl;
        return;
    }
    for(int i=0; i<cantRegistro; i++)
    {
        registro = archClub.LeerRegistroClub(i);

        nombreClub[i]=registro.getNombreClub();
    }

    cout << "CLUBES INSCRIPTOS: " <<endl << "--------------------------------" << endl << endl;
    for(int i=0; i<cantRegistro; i++)
    {
        registro = archClub.LeerRegistroClub(i);

        if(!registro.getEliminado())
        {
            cout << "*" <<nombreClub[i]<<endl<<endl;

        }
    }

    int contEliminado = 0;

    for(int i=0; i<cantRegistro; i++)
    {
        registro = archClub.LeerRegistroClub(i);
        if(registro.getEliminado())
        {
            contEliminado++;
        }
    }

    if (contEliminado > 0)
    {
        cout << endl << "=================================" << endl << endl;

        cout << "CLUBES DADOS DE BAJA: " << endl << "---------------------------------" << endl<< endl;

        for(int i=0; i<cantRegistro; i++)
        {
            registro = archClub.LeerRegistroClub(i);

            if(registro.getEliminado())
            {
                cout << "-" <<nombreClub[i]<<"  #ID: "<<registro.getClubID()<<endl<<endl;
            }
        }
    }


    delete []nombreClub;
}


void  ListadosManager::ListadoGolesPorPartido()
{
    Goles registroGoles ;
    ArchivoGoles archivoGOLES;
    ligaManager lManager;

    int cantidadRegistros = archivoGOLES.CantidadRegistros();
    int maxPartidos = lManager.cantidadDePartidos();

    std::string tipoDeGol[3]= {" Penal "," Tiro libre "," Jugada  "};
    for(int x=0; x<maxPartidos; x++)
    {
        cout<<"-----------------------------------------"<<endl;
        cout<<"PARTIDO : "<<x+1<<endl;
        for(int i=0; i<cantidadRegistros; i++)
        {
            registroGoles = archivoGOLES.LeerGoles(i);
            if (registroGoles.getEliminado() != true)
            {

                if (registroGoles.getNumeroDePartido()==x+1)
                {
                    cout<<"Numero De Gol : "<<registroGoles.getGolesID()<<" DNI : "<<registroGoles.getDNI()<<" Tipo De Gol : ";
                    cout<<tipoDeGol[registroGoles.getTipoDeGol()-1]<<endl;
                }
            }
        }
    }
}




