#include "jugador.h"
#include "archivoJugador.h"
#include "ligaManager.h"
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

jugador::jugador()
{
    _jugadorID = 0;
    _dni = 0;
    _codigoClub = 0;
    strcpy(_apellido, "");
    strcpy(_nombre, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
    _fechaDeNacimiento = Fecha();
    _eliminado = true;
}

jugador::jugador(int jugadorID, int dni, int codigoClub, std::string nombre, std::string apellido,
                 std::string telefono, std::string email, Fecha fecha, bool eliminado)
{
    setJugadorID(jugadorID);
    setDni(dni);
    setCodigoClub(codigoClub);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setEmail(email);
    setFechaNacimiento(fecha);
    setEliminado(eliminado);
}

//Setter:
void jugador::setJugadorID(int jugadorID)
{
    _jugadorID = jugadorID;
}
void jugador::setDni(int dni)
{
    _dni = dni;
}
void jugador::setCodigoClub (int codigoClub)
{
    _codigoClub = codigoClub;
}
void jugador::setNombre(std::string nombre)
{
    strcpy(_nombre, nombre.c_str());
}
void jugador::setApellido(std::string apellido)
{
    strcpy(_apellido, apellido.c_str());
}
void jugador::setTelefono(std::string telefono)
{
    strcpy(_telefono, telefono.c_str());
}
void jugador::setEmail(std::string email)
{
    strcpy(_email, email.c_str());
}
void jugador::setFechaNacimiento(Fecha fecha)
{
    _fechaDeNacimiento = fecha;
}
void jugador::setEliminado(bool eliminado)
{
    _eliminado = eliminado;
}


//Getter:
int jugador::getJugadorID()
{
    return _jugadorID;
}
int jugador::getDni()
{
    return _dni;
}
int jugador::getCodigoClub ()
{
    return _codigoClub;
}
std::string jugador::getNombre()
{
    return _nombre;
}
std::string jugador::getApellido()
{
    return _apellido;
}
std::string jugador::getTelefono()
{
    return _telefono;
}
std::string jugador::getEmail()
{
    return _email;
}
Fecha &jugador::getFechaNacimiento()
{
    return _fechaDeNacimiento;
}
bool jugador::getEliminado()
{
    return _eliminado;
}


//*****************************************************************************************//
///Metodos Jugador

void jugador::cargarJugador()
{
    int ingreso, jugadorID, dni, codClub, dia, mes, anio;
    string nombre, apellido, telefono, email;
    bool eliminado = false;
    Fecha fechaDeNacimiento;
    jugador nuevoJugador;
    archivoJugador archJugador;

    cout<< "1= Comenzar inscripcion /  0= Salir: ";
    cin>> ingreso;
    system ("cls");

    while(ingreso == 1)
    {
        jugadorID = archJugador.generarNuevoId();
        cout<< "ID del jugador: "<<endl;
        cout<< jugadorID<<endl;
        cout<<endl;

        if(ligaManager().cargarDNIJugador(dni))
        {
            break;
        }


        //cout<< "Ingrese codigo que identifica al club: ";
        if(!ligaManager().cargarClub(codClub))
        {
            break;
        }

        cout<< "Ingrese nombre: ";
        cin.ignore();
        getline(cin, nombre);
        cout<<endl;

        cout<< "Ingrese apellido: ";
        getline(cin, apellido);
        cout<<endl;

        cout<< "Ingrese telefono: ";
        cin>> telefono;
        cout<<endl;

        cout<< "Ingrese email: ";
        cin.ignore();
        getline(cin, email);
        cout<<endl;


        cout<< "Ingrese fecha de nacimiento: "<<endl;
        Fecha().cargarFecha(dia, mes, anio);

        fechaDeNacimiento.setDia(dia);
        fechaDeNacimiento.setMes(mes);
        fechaDeNacimiento.setAnio(anio);

        nuevoJugador = jugador(jugadorID, dni, codClub, nombre, apellido, telefono, email, fechaDeNacimiento, eliminado);

        if(archJugador.guardarRegistro(nuevoJugador))
        {
            cout<<endl;
            cout<< "Se inscribio correctamente el jugador!"<<endl;
        }
        else
        {
            cout<< "No se pudo guardar. Consultar a operario de sistema"<<endl;
        }

        cout<< nuevoJugador.mostrarRegistroCSV()<<endl<<endl;


        cout<< "Continuar inscripcion?"<<endl;
        cout<< "1=SI       0=NO: ";
        cin>> ingreso;
        cout << endl;
    }
}

void jugador::mostrar()
{
    std::cout << std::left
              << std::setw(8) << _jugadorID
              << std::setw(10) << _dni
              << std::setw(10) << _codigoClub
              << std::setw(25) << _nombre
              << std::setw(25) << _apellido
              << std::setw(13) << _telefono
              << std::setw(35) << _email
              << std::setw(15) << _fechaDeNacimiento.mostrarFecha()
              << std::endl<<endl;
}

void jugador::encabezadosJugador()
{
    std::cout << std::left
              << std::setw(8) << "ID"
              << std::setw(10) << "DNI"
              << std::setw(10) << "CodClub"
              << std::setw(25) << "Nombre"
              << std::setw(25) << "Apellido"
              << std::setw(13) << "Telefono"
              << std::setw(35) << "Email"
              << std::setw(15) << "F. Nacim."
              << std::endl;

    std::cout << std::string(130, '-') << std::endl;
}

std::string jugador::mostrarRegistroCSV()
{
    std::string str = "";

    str = to_string(_dni) + ",";
    str += to_string(_codigoClub) + ",";
    str += string(_nombre) + ",";
    str += string(_apellido) + ",";
    str += string(_telefono) + ",";
    str += string(_email) + ",";
    str += _fechaDeNacimiento.mostrarFecha() + ",";
    str += to_string(_eliminado);
    return str;
}

