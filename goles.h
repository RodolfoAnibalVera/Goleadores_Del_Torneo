#pragma once
#include <string>

//TODO: CLASE GOLES DESARROLLAR

 class Goles{
private:
    int  _golesID;
    int  _numeroDePartido;
    int  _dni;
    int  _tipoDeGol;
    bool _eliminado;
public:

    Goles ();
    Goles(int goles,int numeroDePartido,int dni, int tipoDeGol,bool eliminado);

    // Setters declaraciones
    void setGolesID(int goles) ;
    void setNumeroDePartido(int numeroDePartido) ;
    void setDNI(int dni) ;
    void setTipoDeGol(int tipoDeGol);
    void setEliminado(bool eliminado);

    // Getters Declaraciones
    int getGolesID();
    int getNumeroDePartido();
    int getDNI();
    int getTipoDeGol();
    bool getEliminado();

    //////////////////////////
    void cargarGoles();
    void encabezados();
    void mostrarEnColumna();
    std::string leerRegistros();



};


