#pragma once
#include "jugador.h"
#include "club.h"
#include "goles.h"

class ligaManager
{
public:

    ///Manager Jugador

    void listarRegistros();
    void listarRegistrosDinamico();
    void eliminarJugador();
    void darAltaJugador();
    bool cargarDNIJugador(int &dni);
    bool cargarClub(int &idClub);

    void actualizarDatosJugador(jugador &registroJugador);

    ///Modificacion de datos Jugadores
    void modificarJugadores();

    ///Funciones para Actualizacion de datos Jugadores
    void actualizarDniJugador(jugador &registroJugador);
    void actualizarCodigoClubJugador(jugador &registroJugador);
    void actualizarNombreJugador(jugador &registroJugador);
    void actualizarApellidoJugador(jugador &registroJugador);
    void actualizarTelefonoJugador(jugador &registroJugador);
    void actualizarEmailJugador(jugador &registroJugador);
    void actualizarFechaNacimientoJugador(jugador &registroJugador);


    ///Club

    void actualizarRegistroClub(Club &club);
    void listarClubes();
    void eliminarClub();
    void darAltaClub();

    ///Modificacion de datos Club
    void modificarClub();

    ///Funciones para actualizacion de datos Club
    void actualizarNombreClub(Club &clubM);
    void actualizarPresidenteClub(Club &clubM);
    void actualizarFechaInscripcionClub(Club &clubM);
    void actualizarTorneosGanadosClub(Club &clubM);


    ///Goles

    void listarGoles();
    void listarGolDinamico();
    void eliminarGoles();
    void darAltaGoles();
    void actualizarDatosGoles(Goles &registroGol);
    bool cargarDNIGoleador(int &dni);
    int cantidadDePartidos();

    ///Modificacion de datos Goles
    void modificarGoles();

    ///Funciones para actualizacion de datos Goles
    void actualizarNumeroPartido(Goles &registroGol);
    void actualizarDniGoleador(Goles &registroGol);
    void actualizarTipoDeGol(Goles &registroGol);

};
