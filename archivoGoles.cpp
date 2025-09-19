#include "archivoGoles.h"

ArchivoGoles::ArchivoGoles (){
    _nombreArchivoGoles = "Goles.dat";
}

ArchivoGoles ::ArchivoGoles (std::string nombreArchivoGoles){
   _nombreArchivoGoles = nombreArchivoGoles;
}

bool ArchivoGoles::Guardar(Goles GOLES){
    FILE *pArchivo = fopen(_nombreArchivoGoles.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool registrado = fwrite(&GOLES, sizeof(Goles), 1, pArchivo);
    fclose(pArchivo);
    return registrado;
}

bool ArchivoGoles::Guardar(Goles GOLES, int posicion){
    FILE *pArchivo = fopen(_nombreArchivoGoles.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Goles) * posicion, SEEK_SET);
    bool registrado = fwrite(&GOLES, sizeof(Goles), 1, pArchivo);
    fclose(pArchivo);
    return registrado;
}

int ArchivoGoles::getCantidadRegistros()//agrege esto el viernes
{
    FILE *pFile;

    pFile = fopen(_nombreArchivoGoles.c_str(), "rb");

    if(pFile==nullptr)
    {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    int total = ftell(pFile);

    int cantidad = total / sizeof(Goles);

    fclose(pFile);

    return cantidad;
}

int ArchivoGoles::Buscar(int GolesID){
    FILE *pArchivo = fopen(_nombreArchivoGoles.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Goles GOLES;
    int i = 0;
    while(fread(&GOLES, sizeof(Goles), 1, pArchivo)){
        if(GOLES.getGolesID() == GolesID){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Goles ArchivoGoles::LeerGoles(int posicion){
    FILE *pArchivo = fopen(_nombreArchivoGoles.c_str(), "rb");
    if(pArchivo == NULL){
        return Goles();
    }
    Goles GOLES;
    fseek(pArchivo, sizeof(Goles) * posicion, SEEK_SET);
    fread(&GOLES, sizeof(Goles), 1, pArchivo);
    fclose(pArchivo);
    return GOLES;
}

int ArchivoGoles::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivoGoles.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Goles);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoGoles::Leer(int cantidadRegistros, Goles *vector){
    FILE *pArchivo = fopen(_nombreArchivoGoles.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Goles), 1, pArchivo);
    }
    fclose(pArchivo);
}

bool ArchivoGoles::reescribirRegistro(int indice, Goles registroGol ){
    FILE *pfile;
    bool resultado;

    pfile= fopen(_nombreArchivoGoles.c_str(), "rb+");

    if(pfile == nullptr)
    {
        return false;
    }

    fseek(pfile, sizeof(Goles) * indice, SEEK_SET);

    resultado = fwrite(&registroGol, sizeof(Goles), 1, pfile);

    fclose(pfile);

    return resultado;



}

int ArchivoGoles::GenerarNuevoID()
{
    int cantidad =CantidadRegistros();

    if(cantidad > 0)
    {
        return LeerGoles(cantidad-1).getGolesID()+1;
    }
    else
    {
        return 1;
    }
}

void ArchivoGoles::leerTodos(Goles vecGoles[], int cantidad)
{
    FILE* pFile;

    pFile = fopen(_nombreArchivoGoles.c_str(), "rb");

    if(pFile==nullptr)
    {
        return;
    }

    fread(vecGoles, sizeof(Goles), cantidad, pFile);

    fclose(pFile);
}

