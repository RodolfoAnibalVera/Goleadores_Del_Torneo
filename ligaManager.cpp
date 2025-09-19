#include <iostream>
#include "ligaManager.h"
#include "jugador.h"
#include "club.h"
#include "goles.h"
#include "archivoJugador.h"
#include "archivoClub.h"
#include "archivoGoles.h"
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

///************************************************************************
///Liga manager Jugador

void ligaManager::listarRegistros()
{
    archivoJugador archJugador;
    jugador registro;

    int cantRegistros = archJugador.getCantidadRegistros();

    if(cantRegistros > 0)
    {
        registro.encabezadosJugador();
        for(int x=0; x<cantRegistros; x++)
        {
            registro = archJugador.leerJugador(x);
            if(registro.getEliminado() != true)
            {
                registro.mostrar();
            }
        }
    }
    else
    {
        cout<< "No hay registros"<<endl;
    }
}

void ligaManager::listarRegistrosDinamico()
{
    int cantRegistros = archivoJugador().getCantidadRegistros();

    jugador *registros;

    registros = new jugador[cantRegistros];

    if(registros==nullptr)
    {
        cout<< "No se pudo pedir memoria"<<endl;
        return;
    }

    archivoJugador().leerTodos(registros, cantRegistros);

    if(cantRegistros > 0)
    {
        jugador().encabezadosJugador();
        for(int x=0; x<cantRegistros; x++)
        {
            if(registros[x].getEliminado() != true)
            {
                registros[x].mostrar();
            }
        }
    }
    else
    {
        cout<< "No hay registros"<<endl;
    }

    delete []registros;
}

void ligaManager::eliminarJugador()
{
    int idJugador, indiceRegistro;
    bool eliminar=0;
    jugador regJugador;
    archivoJugador archJugador;

    cout<< "Ingrese ID del jugador a eliminar: ";
    cin>> idJugador;
    cout<<endl;

    indiceRegistro = archJugador.buscarPorID(idJugador);

    if(indiceRegistro != -1 && !archJugador.leerJugador(indiceRegistro).getEliminado())
    {
        regJugador = archJugador.leerJugador(indiceRegistro);
        cout<< regJugador.mostrarRegistroCSV()<<endl<<endl;

        cout<< "¿Estas seguro que quiere eliminar el jugador?"<<endl;
        cout<<endl<< "   1-Si  0-No: ";
        cin>> eliminar;

        if(eliminar)
        {
            regJugador.setEliminado(eliminar);

            if(archJugador.reescribirRegistro(indiceRegistro, regJugador) )
            {
                cout<< "Se elimino con exito!!"<<endl;
            }
            else
            {
                cout<< "No se pudo eliminar el jugador!"<<endl;
            }
        }
        else
        {
            cout<< "El jugador no se elimino!"<<endl;
        }

    }
    else
    {
        cout<< "No se encontro jugador con ese ID "<<endl<<endl;
    }
}


void ligaManager::darAltaJugador()
{
    int idJugador, indiceRegistro;
    jugador regJugador;
    archivoJugador archJugador;
    bool alta;

    cout<< "Ingrese ID del jugador: ";
    cin>> idJugador;
    cout<<endl;

    indiceRegistro = archJugador.buscarPorID(idJugador);

    if(indiceRegistro != -1)
    {
        regJugador = archJugador.leerJugador(indiceRegistro);
        cout<< regJugador.mostrarRegistroCSV()<<endl<<endl;

        if(regJugador.getEliminado()== true)
        {
            cout<< "Este jugador se encuentra dado de baja"<<endl<<endl;
            cout<< "Desea volver a dar el alta nuevamente?"<<endl;
            cout<< "   Presione 1-SI / 0-NO: ";
            cin>>alta;
            cout << endl;
            if(alta)
            {
                regJugador.setEliminado(0);
                if(archJugador.reescribirRegistro(indiceRegistro, regJugador))
                {
                    cout<< "Se habilito con exito el jugador!"<<endl<<endl;
                }

            }
            else
            {
                cout<< "No se habilito el jugador"<<endl<<endl;
            }
        }
        else
        {
            cout << "Este Jugador ya se encuentra habilitado!" << endl << endl;
        }
    }
}


void ligaManager::actualizarDatosJugador(jugador &registroJugador)
{
    int dni, codClub, dia, mes, anio;
    string nombre, apellido, telefono, email;

    bool corte=false;
    while(!corte)
    {
        corte=true;
        cout<< "Ingrese DNI: ";
        cin>> dni;
        cout << endl;

        if(ligaManager().cargarClub(codClub))
        {
            registroJugador.setCodigoClub(codClub);
        }
        else
        {
            registroJugador.setCodigoClub(codClub);
            break;
        }

        registroJugador.setDni(dni);

        cout<< "Ingrese nombre: ";
        cin.ignore();
        getline(cin, nombre);
        cout << endl;
        registroJugador.setNombre(nombre);

        cout<< "Ingrese apellido: ";
        getline(cin, apellido);
        cout << endl;
        registroJugador.setApellido(apellido);

        cout<< "Ingrese telefono: ";
        cin>> telefono;
        cout << endl;
        registroJugador.setTelefono(telefono);

        cout<< "Ingrese email: ";
        cin.ignore();
        getline(cin, email);
        cout << endl;
        registroJugador.setEmail(email);

        cout<< "Ingrese fecha de nacimiento"<<endl;
        Fecha().cargarFecha(dia,mes,anio);

        registroJugador.getFechaNacimiento().setDia(dia);
        registroJugador.getFechaNacimiento().setMes(mes);
        registroJugador.getFechaNacimiento().setAnio(anio);

    }
}

bool ligaManager::cargarDNIJugador(int &dni)
{
    cout<< "Ingrese DNI: ";
    cin>> dni;
    cout<<endl;

    int cantRegistros = archivoJugador().getCantidadRegistros();

    jugador *registros;

    registros = new jugador[cantRegistros];

    if(registros==nullptr)
    {
        cout<< "No se pudo pedir memoria"<<endl;
        return true;
    }

    archivoJugador().leerTodos(registros, cantRegistros);

    if(cantRegistros > 0)
    {
        for(int x=0; x<cantRegistros; x++)
        {
            if(registros[x].getDni() == dni)
            {
                cout<< "DNI ya registrado"<<endl<<endl;
                cout<<registros[x].getJugadorID()<< "(ID),";
                cout<<registros[x].mostrarRegistroCSV()<<endl<<endl;
                return true;
            }
        }
    }
    else
    {
        cout<< "No hay registros"<<endl;
    }

    delete []registros;

    return false;
}

bool ligaManager::cargarClub(int &idClub)
{
    ArchivoClub archivoClub;
    Club registroClub;
    bool respuesta = false;

    cout<< "Ingrese codigo que identifica al club: ";
    cin>> idClub;
    cout<<endl;

    while(idClub != 0 && respuesta == false)
    {
        int cantidadRegistros = archivoClub.getCantidadRegistros();

        for(int i=0; i<cantidadRegistros; i++)
        {
            registroClub = archivoClub.LeerRegistroClub(i);

            if (registroClub.getCodigoClub()== idClub&& !registroClub.getEliminado())
            {
                respuesta = true;
            }
        }

        if(!respuesta)
        {
            //system("cls");
            cout<< "No se encuentra Club registrado con este codigo!!"<<endl<<endl;
            cout<< "Ingrese Codigo Club o cero(0) para salir!! "<<endl<<endl;

            cout<< "Ingrese codigo: ";
            cin>> idClub;
            cout<<endl;
        }

    }
    return respuesta;
}


///Modificacion de datos Jugadores
void ligaManager::modificarJugadores()
{
    int idJugador, indiceRegistro, opcion;
    jugador regJugador;
    archivoJugador archJugador;

    cout<< "Ingrese ID del jugador a modificar: ";
    cin>> idJugador;
    cout<<endl;

    indiceRegistro = archJugador.buscarPorID(idJugador);

    if(indiceRegistro != -1)
    {
        regJugador = archJugador.leerJugador(indiceRegistro);
        cout<< regJugador.mostrarRegistroCSV()<<endl<<endl;

        if(!regJugador.getEliminado())
        {
            cout << "INGRESE UNA OPCION A MODIFICAR" << endl;
            cout << "---------------------------------" << endl;
            cout << "DNI ------------------ Ingrese #1" << endl;
            cout << "Codigo de Club ------- Ingrese #2" << endl;
            cout << "Nombre --------------- Ingrese #3" << endl;
            cout << "Apellido ------------- Ingrese #4" << endl;
            cout << "Telefono ------------- Ingrese #5" << endl;
            cout << "Email ---------------- Ingrese #6" << endl;
            cout << "Fecha de nacimiento -- Ingrese #7" << endl;
            cout << "---------------------------------" << endl;
            cout << "      SALIR --- Ingrese #0" << endl;
            cout << "---------------------------------" << endl;

            cout << "          Opcion: ";
            cin >> opcion;
            cout << endl;

            if(opcion >=0 && opcion <=7)
            {


                switch(opcion)
                {
                case 1:
                    actualizarDniJugador(regJugador);

                    archJugador.reescribirRegistro(indiceRegistro, regJugador);

                    break;
                case 2:
                    actualizarCodigoClubJugador(regJugador);

                    archJugador.reescribirRegistro(indiceRegistro, regJugador);

                    break;
                case 3:
                    actualizarNombreJugador(regJugador);

                    archJugador.reescribirRegistro(indiceRegistro, regJugador);

                    break;
                case 4:
                    actualizarApellidoJugador(regJugador);

                    archJugador.reescribirRegistro(indiceRegistro, regJugador);

                    break;

                case 5:
                    actualizarTelefonoJugador(regJugador);

                    archJugador.reescribirRegistro(indiceRegistro, regJugador);

                    break;
                case 6:
                    actualizarEmailJugador(regJugador);

                    archJugador.reescribirRegistro(indiceRegistro, regJugador);

                    break;
                case 7:
                    actualizarFechaNacimientoJugador(regJugador);

                    archJugador.reescribirRegistro(indiceRegistro, regJugador);

                    break;
                case 0:

                    break;
                }
            }
            else
            {
                cout << "Error: Opcion invalida!" << endl<<endl;
                return;
            }

        }
        else
        {
            cout << "El Jugador se encuentra eliminado!" << endl<<endl;
        }
    }
    else
    {
        cout<< "No se encontro jugador con el ID ingresado!"<<endl<<endl;
    }

}

///Funciones para actualizacion de datos Jugadores
void ligaManager::actualizarDniJugador(jugador &registroJugador)
{
    int dni;

    if(cargarDNIJugador(dni) == false)
    {
        registroJugador.setDni(dni);

        cout<<endl<< "El DNI se modifico con exito!"<<endl<<endl;
    }
    else
    {
        cout<< "No se pudo modificar el DNI"<<endl<<endl;
    }
}

void ligaManager::actualizarCodigoClubJugador(jugador &registroJugador)
{
    int codClub;

    if(ligaManager().cargarClub(codClub))
    {
        registroJugador.setCodigoClub(codClub);

        if(codClub != 0)
        {

            cout<<endl<< "El Codigo del Club se modifico con exito!"<<endl<<endl;
        }

    }
    else
    {
        cout<< "No se pudo modificar el Codigo del Club"<<endl<<endl;
    }

}

void ligaManager::actualizarNombreJugador(jugador &registroJugador)
{
    std::string nombre;

    cout<< "Ingrese el nombre: ";
    cin.ignore();
    getline(cin, nombre);
    cout << endl;

    // Eliminar espacios en blanco al inicio y final
    nombre.erase(nombre.begin(), std::find_if(nombre.begin(), nombre.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    nombre.erase(std::find_if(nombre.rbegin(), nombre.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), nombre.end());

    if (!nombre.empty())
    {
        registroJugador.setNombre(nombre);
        cout << "El Nombre se modifico con exito!" << endl<<endl;
    }
    else
    {
        cout << "No se pudo modificar el Nombre" << endl<<endl;
    }


}

void ligaManager::actualizarApellidoJugador(jugador &registroJugador)
{
    std::string apellido;

    cout<< "Ingrese el apellido: ";
    cin.ignore();
    getline(cin, apellido);
    cout << endl;

    // Eliminar espacios en blanco al inicio y final
    apellido.erase(apellido.begin(), std::find_if(apellido.begin(), apellido.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    apellido.erase(std::find_if(apellido.rbegin(), apellido.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), apellido.end());

    if (!apellido.empty())
    {
        registroJugador.setApellido(apellido);
        cout << "El Apellido se modifico con exito!" << endl<<endl;
    }
    else
    {
        cout << "No se pudo modificar el Apellido" << endl<<endl;
    }
}

void ligaManager::actualizarTelefonoJugador(jugador &registroJugador)
{
    std::string telefono;

    cout<< "Ingrese numero de telefono: ";
    cin.ignore();
    getline(cin, telefono);
    cout << endl;
    registroJugador.setTelefono(telefono);
    cout << "El numero de Telefono se modifico con exito!" << endl << endl;

}

void ligaManager::actualizarEmailJugador(jugador &registroJugador)
{
    std::string email;

    cout<< "Ingrese el email: ";
    cin.ignore();
    getline(cin, email);
    cout << endl;
    registroJugador.setEmail(email);
    cout << "El email se modifico con exito!" << endl << endl;

}

void ligaManager::actualizarFechaNacimientoJugador(jugador &registroJugador)
{
    int dia, mes, anio;

    cout<< "Ingrese fecha de nacimiento"<<endl;

    Fecha().cargarFecha(dia,mes,anio);

    registroJugador.getFechaNacimiento().setDia(dia);
    registroJugador.getFechaNacimiento().setMes(mes);
    registroJugador.getFechaNacimiento().setAnio(anio);

    cout << "La fecha de nacimiento se actualizo con exito!" << endl << endl;
}


///************************************************************************
///Liga manager Club


void ligaManager::actualizarRegistroClub(Club &club)
{


    string nombreClub, presidente;
    int dia, mes, anio, torneosGanados;

    cout << "Ingrese nombre del Club: ";
    cin.ignore();
    getline(cin, nombreClub);
    club.setNombreClub(nombreClub);
    cout << endl;

    cout << "Ingrese nombre del Presidente: ";
    getline(cin, presidente);
    club.setPresidente(presidente);
    cout << endl;

    cout << "  Ingrese fecha de inscripcion " << endl;

    Fecha().cargarFecha(dia, mes, anio);


    club.getFechaInscripcion().setDia(dia);


    club.getFechaInscripcion().setMes(mes);


    club.getFechaInscripcion().setAnio(anio);


    cout << "Ingrese en numero, la cantidad de torneos ganados: ";
    cin >> torneosGanados;
    club.setTorneosGanados(torneosGanados);
    cout << endl;

}

void ligaManager::listarClubes()
{
    ArchivoClub archivoClub;
    Club registroClub;

    int cantidadRegistros = archivoClub.getCantidadRegistros();

    registroClub.encabezadosClub();
    for(int i=0; i<cantidadRegistros; i++)
    {
        registroClub = archivoClub.LeerRegistroClub(i);

        if (registroClub.getEliminado()!= true)
        {

            registroClub.mostrarClub();
        }

    }
}

void ligaManager::eliminarClub()
{
    int idClub, indiceRegistro;
    bool eliminar=0;

    Club clubM;
    ArchivoClub archivoClub;

    cout<< "Ingrese ID del Club a eliminar: ";
    cin>> idClub;
    cout<<endl;

    indiceRegistro = archivoClub.BuscarPorIDClub(idClub);

    if(indiceRegistro != -1 && !archivoClub.LeerRegistroClub(indiceRegistro).getEliminado())
    {
        clubM = archivoClub.LeerRegistroClub(indiceRegistro);
        cout<< clubM.leerRegistroClubCSV()<<endl<<endl;

        cout << "¿Estas seguro que quieres eliminar el Club?" << endl;
        cout <<endl<< "   1-Si  0-No: ";
        cin >> eliminar;
        cout << endl;

        if(eliminar)
        {
            clubM.setEliminado(eliminar);

            if(archivoClub.ReescribirRegistroClub(indiceRegistro, clubM))
            {

                cout<< "El Club se elimino con exito"<<endl<<endl;
            }
            else
            {
                cout<< "No se pudo eliminarar el Club"<<endl<<endl;
            }


        }
        else
        {
            cout<< "El Club no se elimino"<<endl<<endl;
        }

    }
    else
    {
        cout<< "No se encontro el Club con el numero de ID ingresado"<<endl<<endl;
    }

}

void ligaManager::darAltaClub()
{
    int idClub, indiceRegistro;
    bool alta;

    Club clubM;
    ArchivoClub archivoClub;

    cout<< "Ingrese ID del Club a modificar: ";
    cin>> idClub;
    cout<<endl;

    indiceRegistro = archivoClub.BuscarPorIDClub(idClub);

    if(indiceRegistro != -1)
    {
        clubM = archivoClub.LeerRegistroClub(indiceRegistro);
        cout<< clubM.leerRegistroClubCSV()<<endl<<endl;

        if(clubM.getEliminado()==true)
        {
            cout<< "Este club se encuentra dado de baja"<<endl<<endl;
            cout<< "Desea darle el alta nuevamente?"<<endl;
            cout<< "   Presione 1-SI / 0-NO: ";
            cin>>alta;
            cout << endl;
            if(alta)
            {
                clubM.setEliminado(0);
                if(archivoClub.ReescribirRegistroClub(indiceRegistro, clubM))
                {
                    cout<<endl<< "Se habilito con exito el Club!"<<endl<<endl;
                }

            }
            else
            {
                cout<< "No se habilito el Club"<<endl<<endl;
            }
        }
        else
        {
            cout << "El Club ya se encuentra habilitado" << endl << endl;
        }
    }
}


///Modificacion de datos Club
void ligaManager::modificarClub()
{
    int idClub, indiceRegistro, opcion;

    Club clubM;
    ArchivoClub archivoClub;

    cout<< "Ingrese ID del Club a modificar: ";
    cin>> idClub;
    cout<<endl;

    indiceRegistro = archivoClub.BuscarPorIDClub(idClub);

    if(indiceRegistro != -1)
    {
        clubM = archivoClub.LeerRegistroClub(indiceRegistro);
        cout<< clubM.leerRegistroClubCSV()<<endl<<endl;

        if(!clubM.getEliminado())
        {
            cout << "INGRESE UNA OPCION A MODIFICAR" << endl;
            cout << "----------------------------------" << endl;
            cout << "Nombre del Club ------- Ingrese #1" << endl;
            cout << "Nombre del Presidente - Ingrese #2" << endl;
            cout << "Fecha de inscripcion -- Ingrese #3" << endl;
            cout << "Torneos ganados ------- Ingrese #4" << endl;
            cout << "----------------------------------" << endl;
            cout << "      SALIR --- Ingrese #0" << endl;
            cout << "----------------------------------" << endl;

            cout << "          Opcion: ";
            cin >> opcion;
            cout << endl;

            if(opcion >=0 && opcion <=4)
            {


                switch(opcion)
                {
                case 1:
                    actualizarNombreClub(clubM);
                    archivoClub.ReescribirRegistroClub(indiceRegistro, clubM);

                    break;
                case 2:
                    actualizarPresidenteClub(clubM);
                    archivoClub.ReescribirRegistroClub(indiceRegistro, clubM);

                    break;
                case 3:
                    actualizarFechaInscripcionClub(clubM);
                    archivoClub.ReescribirRegistroClub(indiceRegistro, clubM);

                    break;
                case 4:
                    actualizarTorneosGanadosClub(clubM);
                    archivoClub.ReescribirRegistroClub(indiceRegistro, clubM);

                    break;


                case 0:

                    break;
                }
            }
            else
            {
                cout << "Error: Opcion invalida!" << endl<<endl;
                return;
            }

        }
        else
        {
            cout << "El club se encuentra eliminado" << endl<<endl;
        }

    }
    else
    {
        cout<< "No se encontro el Club con el numero de ID ingresado"<<endl<<endl;
    }

}

///Funciones para actualizacion de datos del Club
void ligaManager::actualizarNombreClub(Club &clubM)
{
    string nombre;

    cout << "Ingrese nombre del Club: ";
    cin.ignore();
    getline(cin, nombre);
    cout << endl;

    // Eliminar espacios en blanco al inicio y final
    nombre.erase(nombre.begin(), std::find_if(nombre.begin(), nombre.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    nombre.erase(std::find_if(nombre.rbegin(), nombre.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), nombre.end());

    if (!nombre.empty())
    {
        clubM.setNombreClub(nombre);
        cout << "El Nombre del Club se modifico con exito!" << endl<<endl;
    }
    else
    {
        cout << "No se pudo modificar el Nombre del Club" << endl<<endl;
    }
}

void ligaManager::actualizarPresidenteClub(Club &clubM)
{
    string nombre;

    cout << "Ingrese el nombre del Presidente: ";
    cin.ignore();
    getline(cin, nombre);
    cout << endl;

    // Eliminar espacios en blanco al inicio y final
    nombre.erase(nombre.begin(), std::find_if(nombre.begin(), nombre.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    nombre.erase(std::find_if(nombre.rbegin(), nombre.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), nombre.end());

    if (!nombre.empty())
    {
        clubM.setPresidente(nombre);
        cout << "El Nombre del Presidente se modifico con exito!" << endl<<endl;
    }
    else
    {
        cout << "No se pudo modificar el Nombre del Presidente" << endl<<endl;
    }


}

void ligaManager::actualizarFechaInscripcionClub(Club &clubM)
{
    int dia, mes, anio;

    cout << "  Ingrese fecha de inscripcion " << endl;

    Fecha().cargarFecha(dia, mes, anio);


    clubM.getFechaInscripcion().setDia(dia);


    clubM.getFechaInscripcion().setMes(mes);


    clubM.getFechaInscripcion().setAnio(anio);

    cout << "La Fecha de Inscripcion se modifico con exito!" << endl << endl;
}

void ligaManager::actualizarTorneosGanadosClub(Club &clubM)
{
    int torneosGanados;

    cout << "Ingrese en numero, la cantidad de torneos ganados: ";
    cin >> torneosGanados;
    clubM.setTorneosGanados(torneosGanados);
    cout << endl;
    cout << "La Cantidad de Torneos Ganados se modifico con exito!" << endl << endl;
}



///************************************************************************
///Liga manager Goles

void ligaManager::listarGoles()
{
    Goles registroGoles ;
    ArchivoGoles archivoGOLES;

    int cantidadRegistros = archivoGOLES.CantidadRegistros();
    registroGoles.encabezados();
    for(int i=0; i<cantidadRegistros; i++)
    {
        registroGoles = archivoGOLES.LeerGoles(i);

        if (registroGoles.getEliminado() != true)
        {
            registroGoles.mostrarEnColumna();
        }


    }
}

void ligaManager::listarGolDinamico()
{
    int cantRegistros = ArchivoGoles().getCantidadRegistros();

    Goles *registroGoles;/// preguntar por registros

    registroGoles = new Goles[cantRegistros];

    if(registroGoles==nullptr)
    {
        cout<< "No se pudo pedir memoria"<<endl;
        return;
    }

    ArchivoGoles archivo;  // crear objeto
    archivo.Leer(cantRegistros, registroGoles); // llamado correcto


    if(cantRegistros > 0)
    {
        Goles().encabezados();
        for(int x=0; x<cantRegistros; x++)
        {
            if(registroGoles[x].getEliminado() != true)
            {
                registroGoles[x].mostrarEnColumna();
            }
        }
    }
    else
    {
        cout<< "No hay registros"<<endl;
    }

    delete []registroGoles;
}

void ligaManager::eliminarGoles()
{
    int idGoles, indiceRegistroGol;
    bool eliminar=0;
    Goles regGoles;
    ArchivoGoles archGoles;

    cout<< "Ingrese ID del Gol a eliminar: ";
    cin>> idGoles;
    cout<<endl;

    indiceRegistroGol = archGoles.Buscar(idGoles);

    if(indiceRegistroGol != -1 && !archGoles.LeerGoles(indiceRegistroGol).getEliminado())
    {
        regGoles = archGoles.LeerGoles(indiceRegistroGol);
        cout<< regGoles.leerRegistros()<<endl<<endl;

        cout<< "¿Estas seguro que quiere eliminar el gol?"<<endl;
        cout<< "     1-Si  0-No: ";
        cin>> eliminar;
        cout << endl;

        if(eliminar)
        {
            regGoles.setEliminado(eliminar);

            if(archGoles.reescribirRegistro(indiceRegistroGol, regGoles))
            {

                cout<< "El Gol elimino con exito!"<<endl<<endl;
            }
            else
            {
                cout<< "No se pudo eliminar el gol"<<endl<<endl;
            }
        }
        else
        {
            cout<< "El Gol no se elimino"<<endl<<endl;
        }

    }
    else
    {
        cout<< "No se encontro el ID Del Gol "<<endl<<endl;
    }
}

void ligaManager::darAltaGoles()
{
    int idGoles, indiceRegistroGol;
    bool alta;
    Goles regGoles;
    ArchivoGoles archGoles;


    cout<< "Ingrese ID del  Gol a modificar: ";
    cin>> idGoles;
    cout<<endl;

    indiceRegistroGol =archGoles.Buscar(idGoles);

    if(indiceRegistroGol != -1)
    {
        regGoles =archGoles.LeerGoles(indiceRegistroGol);
        cout<< regGoles.leerRegistros()<<endl<<endl;

        if(regGoles.getEliminado()== true)
        {
            cout<< "Este Gol se encuentra dado de baja"<<endl<<endl;
            cout<< "Desea volver a dar alta nuevamente?"<<endl;
            cout<< "   Presione  1-SI / 0-NO: ";
            cin>>alta;
            cout << endl;
            if(alta)
            {
                regGoles.setEliminado(0);

                if(archGoles.reescribirRegistro(indiceRegistroGol, regGoles))
                {
                    cout<< "El Gol se habilito con exito!"<<endl<<endl;
                }

            }
            else
            {
                cout<< "No se pudo habilitar el Gol"<<endl<<endl;

            }
        }
    }
}

void ligaManager::actualizarDatosGoles(Goles &registroGol)
{


    int  numeroDePartido,dni,tipoDeGol;
    cout << "Ingrese el numero del Partido: ";
    cin >> numeroDePartido;

    registroGol.setNumeroDePartido(numeroDePartido);

    cout << endl;
    cout << "Ingrese DNI del jugador que metio el gol: ";
    cin >> dni;

    registroGol.setDNI(dni);

    cout << endl;
    cout << "Ingrese el tipo de gol segun las siguientes opciones : ";
    cout << endl;
    cout << " Opcion 1 : Penal ";
    cout << endl;
    cout << " Opcion 2 : Tiro Libre ";
    cout << endl;
    cout << " Opcion 3 : Jugada en General ";
    cout << endl;
    cout <<" Ingrese opcion: " ;
    cin >> tipoDeGol;

    registroGol.setTipoDeGol(tipoDeGol);

    cout << endl;


}

bool ligaManager::cargarDNIGoleador(int &dni)
{
    bool respuesta=false ;
    cout<< "Ingrese DNI: ";
    cin>> dni;
    cout<<endl;

    archivoJugador archJugador;
    jugador registro;
    int cantRegistros = archJugador.getCantidadRegistros();

    if(cantRegistros > 0)
    {
        for(int x=0; x<cantRegistros; x++)
        {
            registro = archJugador.leerJugador(x);
            if (registro.getDni()==dni && !registro.getEliminado())
            {
                respuesta=true;
            }
        }
    }
    else
    {
        cout<< "No hay registros"<<endl;
    }
    if(respuesta==false)
    {
        cout<<"Dni de Jugador no registrado. "<<endl<<endl;


    }
    return respuesta;
}

int ligaManager::cantidadDePartidos()
{
    Goles regGoles;
    ArchivoGoles archGoles;
    int maxNumeroPartido = 0, numPartido=0;

    int cantidadRegistros = archGoles.CantidadRegistros();


    for (int i = 0; i < cantidadRegistros; i++)
    {
        regGoles = archGoles.LeerGoles(i);
        numPartido = regGoles.getNumeroDePartido();

        if (numPartido > maxNumeroPartido)
        {
            maxNumeroPartido = numPartido;
        }
    }

    return maxNumeroPartido;
}


///Modificacion de datos Goles
void ligaManager::modificarGoles()
{
    int idGoles, indiceRegistroGol, opcion;

    Goles regGoles;
    ArchivoGoles archGoles;

    cout<< "Ingrese ID del  Gol a modificar: ";
    cin>> idGoles;
    cout<<endl;

    indiceRegistroGol =archGoles.Buscar(idGoles);

    if(indiceRegistroGol != -1)
    {
        regGoles =archGoles.LeerGoles(indiceRegistroGol);
        cout<< regGoles.leerRegistros()<<endl<<endl;

        if(!regGoles.getEliminado()==true)
        {
            cout << "INGRESE UNA OPCION A MODIFICAR" << endl;
            cout << "----------------------------------" << endl;
            cout << "Numero de Partido ----- Ingrese #1" << endl;
            cout << "DNI del Goleador ------ Ingrese #2" << endl;
            cout << "Tipo de Gol ----------- Ingrese #3" << endl;
            cout << "----------------------------------" << endl;
            cout << "      SALIR --- Ingrese #0" << endl;
            cout << "----------------------------------" << endl;

            cout << "          Opcion: ";
            cin >> opcion;
            cout << endl;

            if(opcion >=0 && opcion <=3)
            {


                switch(opcion)
                {
                case 1:
                    actualizarNumeroPartido(regGoles);
                    archGoles.reescribirRegistro(indiceRegistroGol, regGoles);
                    break;
                case 2:
                    actualizarDniGoleador(regGoles);
                    archGoles.reescribirRegistro(indiceRegistroGol, regGoles);
                    break;
                case 3:
                    actualizarTipoDeGol(regGoles);
                    archGoles.reescribirRegistro(indiceRegistroGol, regGoles);
                    break;

                case 0:

                    break;
                }
            }
            else
            {
                cout << "Error: Opcion invalida!" << endl<<endl;
                return;
            }


        }
        else
        {
            cout<< "El Gol se encuentra eliminado"<<endl<<endl;
        }
    }
    else
    {
        cout<< "No se encontro el Gol con ese ID "<<endl<<endl;
    }

}

///Funciones para actualizacion de datos del Goles
void ligaManager::actualizarNumeroPartido(Goles &registroGol)
{
    int numeroDePartido;
    cout << "Ingrese el numero de Partido: ";
    cin >> numeroDePartido;
    cout <<endl;
    registroGol.setNumeroDePartido(numeroDePartido);

    cout << "El numero de partido se modifico con exito!" << endl << endl;
}

void ligaManager::actualizarDniGoleador(Goles &registroGol)
{
    int dni;

    if(ligaManager().cargarDNIGoleador(dni))
    {
        registroGol.setDNI(dni);

        if(dni != 0)
        {

            cout << "El DNI se actualizo con exito!"<<endl<<endl;
        }

    }

}

void ligaManager::actualizarTipoDeGol(Goles &registroGol)
{
    int tipoDeGol;

    cout << endl;
    cout << "Ingrese el tipo de gol segun las siguientes opciones : ";
    cout << endl;
    cout << "   Opcion 1 : Penal ";
    cout << endl;
    cout << "   Opcion 2 : Tiro Libre ";
    cout << endl;
    cout << "   Opcion 3 : Jugada en General ";
    cout << endl;
    cout <<"        Ingrese opcion: " ;
    cin >> tipoDeGol;
    cout << endl;

    if(tipoDeGol>=1 && tipoDeGol<=3)
    {
        registroGol.setTipoDeGol(tipoDeGol);
        cout << "El Tipo de Gol se actualizo con exito!"<<endl<<endl;
    }
    else
    {
        cout << "No se pudo actualizar el tipo de gol"<<endl<<endl;
    }


}

