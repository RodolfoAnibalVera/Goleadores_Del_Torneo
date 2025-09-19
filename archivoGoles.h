#pragma once
#include "goles.h"
#include <string>

class ArchivoGoles {
private:
    std::string _nombreArchivoGoles;

public:
    ArchivoGoles();
    ArchivoGoles(std::string nombreArchivoGoles);
    bool Guardar(Goles GOLES );
    bool Guardar(Goles GOLES , int posicion);
    int Buscar(int golesID);
    Goles LeerGoles(int posicion);
    int CantidadRegistros();
    void Leer(int cantidadRegistros, Goles *vector);
    void leerTodos(Goles vecGoles[], int cantidad);
    bool reescribirRegistro(int indice ,Goles registroGol);
    int getCantidadRegistros();
    int GenerarNuevoID();
};
