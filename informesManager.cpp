#include "informesManager.h"
#include "jugador.h"
#include "club.h"
#include "goles.h"
#include "archivoJugador.h"
#include "archivoClub.h"
#include "archivoGoles.h"

#include <iostream>
using namespace std;


void InformesManager::InfoGolesPorJugador()
{
    jugador aux;

    int cantRegistrosJugador = archivoJugador().getCantidadRegistros();
    int cantRegistrosGoles = ArchivoGoles().getCantidadRegistros();

    jugador *registrosJugador;
    Goles *registrosGoles;
    int *vecJugadorXgoles;

    registrosJugador = new jugador[cantRegistrosJugador];
    registrosGoles = new Goles[cantRegistrosGoles];
    vecJugadorXgoles = new int[cantRegistrosJugador] {};

    if(registrosJugador==nullptr || registrosGoles==nullptr || vecJugadorXgoles==nullptr)
    {
        cout<< "No se pudo pedir memoria!"<<endl;
        return;
    }

    archivoJugador().leerTodos(registrosJugador, cantRegistrosJugador);
    ArchivoGoles().leerTodos(registrosGoles, cantRegistrosGoles);


    for (int i = 0; i < cantRegistrosJugador; i++)
    {
        for (int j = 0 ; j < cantRegistrosGoles; j++)
        {
            if (registrosJugador[i].getDni() == registrosGoles[j].getDNI())
            {
                vecJugadorXgoles[i] ++;
            }
        }
    }

    if(cantRegistrosGoles > 0)
    {

        for(int x=0; x<cantRegistrosJugador; x++)
        {
            if(registrosJugador[x].getEliminado() != true && vecJugadorXgoles[x] != 0)
            {
                cout<< registrosJugador[x].getNombre()<<" "
                    << registrosJugador[x].getApellido()
                    << " (ID: "<< registrosJugador[x].getJugadorID()<< ")"
                    << " Goles: "<< vecJugadorXgoles[x]
                    <<endl<<endl;
            }
        }
    }
    else
    {
        cout<< "No hay registros de goles"<<endl;
    }

    delete []registrosJugador;
    delete []registrosGoles;
    delete []vecJugadorXgoles;
}


void InformesManager::InfoGolesPorClub()
{
    ArchivoGoles archGoles("Goles.dat");
    archivoJugador archJugador("jugador.dat");
    ArchivoClub archClub("club.dat");

    Goles registroGoles;
    jugador registroJugador;
    Club registroClub;

    int cantRegistroGol = archGoles.getCantidadRegistros();

    if(cantRegistroGol<1)
    {
        cout << "*Aun no hay registros de goles*" << endl << endl;
        return;
    }


    int cantRegistroJugador = archJugador.getCantidadRegistros();

    int *vecGolxDni = nullptr;
    vecGolxDni = new int[cantRegistroJugador];
    if(vecGolxDni==nullptr)
    {
        cout<< "No se pudo pedir memoria!"<<endl;
        return;
    }

    for (int i = 0; i < cantRegistroJugador; ++i)
    {
        vecGolxDni[i] = 0;
    }


    for(int i=0; i<cantRegistroJugador; i++)
    {

        registroJugador = archJugador.leerJugador(i);
        for(int j=0; j<cantRegistroGol; j++)
        {
            registroGoles = archGoles.LeerGoles(j);

            if(registroJugador.getDni() == registroGoles.getDNI() && !registroGoles.getEliminado())
            {
                vecGolxDni[i] +=1;
            }
        }
    }


    int cantRegistroClub = archClub.getCantidadRegistros();
    int *vecGolxClub = nullptr;
    vecGolxClub = new int[cantRegistroClub];
    if(vecGolxClub==nullptr)
    {
        cout<< "No se pudo pedir memoria!"<<endl;
        return;
    }
    for (int i = 0; i < cantRegistroClub; ++i)
    {
        vecGolxClub[i] = 0;
    }


    cout << "          *GOLES POR CLUB*"  << endl;
    cout << "---------------------------------------------" << endl;

    for(int i=0; i<cantRegistroClub; i++)
    {
        registroClub = archClub.LeerRegistroClub(i);

        if(!registroClub.getEliminado())
        {

            for(int j=0; j<cantRegistroJugador; j++)
            {
                registroJugador = archJugador.leerJugador(j);

                if(registroJugador.getCodigoClub() == registroClub.getCodigoClub())
                {
                    vecGolxClub[i] += vecGolxDni[j];
                }
            }
        }
        if(vecGolxClub[i] > 0){
            cout << registroClub.getNombreClub() << "    -Cantidad de goles: ";
            cout << vecGolxClub[i] << endl << endl;
        }

    }


    delete []vecGolxDni;

    delete []vecGolxClub;
}


void  InformesManager::InfoGolesPorTipo()
{
    Goles registroGoles ;
    ArchivoGoles archivoGOLES;
    int vecTipoDeGol[3]= {0};
    std::string strTipoDeGol[3]= {" Penal "," Tiro libre "," Jugada  "};

    int cantidadRegistros = archivoGOLES.CantidadRegistros();

    for(int x=0; x<cantidadRegistros; x++)
    {
        registroGoles = archivoGOLES.LeerGoles(x);

        if (registroGoles.getEliminado() != true)
        {
            vecTipoDeGol[registroGoles.getTipoDeGol()-1]++;
        }
    }

    cout<< "Cantidad de goles por penal: "<< vecTipoDeGol[0]<<endl<<endl;
    cout<< "Cantidad de goles por tiro libre: "<< vecTipoDeGol[1]<<endl<<endl;
    cout<< "Cantidad de goles por jugada: "<< vecTipoDeGol[2]<<endl<<endl;
    system("pause");
    cout<<endl;

    for(int x=0; x<3; x++)
    {
        cout<<"-----------------------------------------"<<endl;
        cout<<"Goles por "<<strTipoDeGol[x] <<": "<<endl;
        for(int i=0; i<cantidadRegistros; i++)
        {
            registroGoles = archivoGOLES.LeerGoles(i);
            if (registroGoles.getEliminado() != true)
            {

                if (registroGoles.getTipoDeGol()==x+1)
                {
                    cout<<"Numero De Gol : "<<registroGoles.getGolesID()<<" DNI : "<<registroGoles.getDNI()<<" Tipo De Gol : ";
                    cout<<strTipoDeGol[registroGoles.getTipoDeGol()-1]<<endl<<endl;
                }
            }
        }
    }
}
