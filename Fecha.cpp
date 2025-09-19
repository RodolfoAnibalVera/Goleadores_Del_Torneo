#include <iostream>
#include "fecha.h"
#include <limits>
#include <sstream>
#include <iomanip>

using namespace std;

Fecha::Fecha(){
    _dia = 0;
    _mes = 0;
    _anio = 0;
}

Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

void Fecha::setDia(int dia){
    _dia = dia;
}

void Fecha::setMes(int mes){
    _mes = mes;
}

void Fecha::setAnio(int anio){
    _anio = anio;
}

void Fecha::cargarFecha(int &dia, int &mes, int &anio)
{
    int diaT, mesT, anioT;
    bool controlDia, controlMes, controlAnio, general;


    do
    {
        controlDia=false;
        controlMes=false;
        controlAnio=false;
        general=false;

        cout << "Ingrese dos digitos para el dia: ";
        cin >> diaT;


        cout << "Ingrese dos digitos para el mes: ";
        cin >> mesT;

        cout << "Ingrese cuatro digitos para el anio: ";
        cin >> anioT;
        cout << endl;

        // Validación de entrada numérica
        if (cin.fail())
        {
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Ignorar entrada inválida
            cout << endl << "Error: Solo se permiten numeros. Intente nuevamente." << endl<< endl;
            continue; // Volver a solicitar la entrada
        }



        //Mes
        if (mesT >= 1 && mesT <= 12)
        {
            controlMes = true;
        }
        else
        {
            cout << "Error: El mes debe estar entre 1 y 12" << endl;
        }

        //Anio
        if (anioT >= 1900 && anioT <= 2025)
        {
            controlAnio = true;
        }
        else
        {
            cout << "Error: El anio debe estar entre 1900 y 2025" << endl;
        }

        //Dia
        if (controlMes == true && controlAnio == true)
        {
            if (mesT == 2)
            {
                if ((anioT % 4 == 0 && anioT % 100 != 0) || (anioT % 400 == 0))
                {
                    if (diaT >= 1 && diaT <= 29)
                    {
                        controlDia = true;
                    }
                    else
                    {
                        if(diaT<1)
                        {
                            cout << "Error: Ingrese un numero mayor a cero para el dia" << endl;
                        }
                        else
                        {
                            cout << "Error: En anio bisiesto, febrero tiene hasta 29 dias" << endl;
                        }

                    }
                }
                else
                {
                    if (diaT >= 1 && diaT <= 28)
                    {
                        controlDia = true;
                    }
                    else
                    {
                        if(diaT<1)
                        {
                            cout << "Error: Ingrese un numero mayor a cero para el dia" << endl;
                        }
                        else
                        {
                            cout << "Error: En anio normal, febrero tiene hasta 28 dias" << endl;
                        }

                    }
                }
            }
            else if (mesT == 4 || mesT == 6 || mesT == 9 || mesT == 11)
            {
                if (diaT >= 1 && diaT <= 30)
                {
                    controlDia = true;
                }
                else
                {
                    if(diaT<1)
                    {
                        cout << "Error: Ingrese un numero mayor a cero para el dia" << endl;
                    }
                    else
                    {
                        cout << "Error: Este mes solo tiene 30 dias" << endl;
                    }

                }
            }
            else
            {
                if (diaT >= 1 && diaT <= 31)
                {
                    controlDia = true;
                }
                else
                {
                    if(diaT<1)
                    {
                        cout << "Error: Ingrese un numero mayor a cero para el dia" << endl;
                    }
                    else
                    {
                        cout << "Error: Este mes tiene hasta 31 dias" << endl;
                    }

                }
            }
        }

        //General
        if(controlDia == true && controlMes == true && controlAnio == true)
        {
            dia = diaT;
            mes = mesT;
            anio = anioT;
            general=true;
        }
        else
        {
            cout << endl <<"Vuelva a ingresar la fecha"<<endl;
        }

    }
    while(!general);


}

std::string Fecha::mostrarFecha()
{
    std::ostringstream fecha;

    fecha << std::setfill('0') << std::setw(2) << _dia << "/"
        << std::setw(2) << _mes << "/"
        << _anio;

    return fecha.str();
}


