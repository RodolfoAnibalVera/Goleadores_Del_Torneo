#pragma once
#include <string>
#include "Fecha.h"

class jugador
{
private:
    int  _jugadorID;
    int  _dni;
    int  _codigoClub;
    char _nombre [50];
    char _apellido [50];
    char _telefono [50];
    char _email [60];
    Fecha _fechaDeNacimiento;
    bool _eliminado;

public:
    jugador();

    jugador(int jugadorID, int dni, int codigoClub, std::string nombre, std::string apellido,
            std::string telefono, std::string email, Fecha fecha, bool eliminado);

            void setJugadorID(int jugadorID);
            void setDni(int dni);
            void setCodigoClub (int codigoClub);
            void setNombre(std::string nombre);
            void setApellido(std::string apellido);
            void setTelefono(std::string telefono);
            void setEmail(std::string email);
            void setFechaNacimiento(Fecha fecha);
            void setEliminado(bool eliminado);

            int getJugadorID();
            int getDni();
            int getCodigoClub ();
            std::string getNombre();
            std::string getApellido();
            std::string getTelefono();
            std::string getEmail();
            Fecha &getFechaNacimiento();
            bool getEliminado();

            void cargarJugador();
            void mostrar();

            std::string mostrarRegistroCSV();
            void encabezadosJugador();
};
