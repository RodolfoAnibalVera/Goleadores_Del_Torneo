#include "menu.h"
#include "ligaManager.h"
#include "consultasManager.h"
#include "listadosManager.h"
#include "informesManager.h"

#include<iostream>
#include <cstdlib>
#include "rlutil.h"
#include <string>

using namespace std;

void showItem(const char* TEXT,int posx,int posy,bool select )
{
// con este if aparece la barrita para indicarnos que esta seleccionado de una manera mas vistosa y que no.
    if (select)
    {
        //seleccionado con fondo verde claro
        rlutil::setBackgroundColor(rlutil::LIGHTGREEN );
        rlutil::locate(posx-3,posy); // el -3 quiere decir que empiece a dibujar en la posicion -3
        cout << (char)175<<" "<< TEXT<<" "<<(char)174<<" "<<endl;
    }
    else
    {
        //sin seleccionar con fondo negro
        rlutil::setBackgroundColor(rlutil::BLACK );
        rlutil::locate(posx-3,posy);// el -3 quiere decir que empiece a dibujar en la posicion -3
        cout <<"  "<< TEXT<<"  " <<"  "<<endl;
    }
    rlutil::setBackgroundColor(rlutil::BLACK);
//rlutil::locate(posx,posy);
// aca vamos a poner que dibuje en pantalla TEXT (osea la cadena de caracteres)
//std::cout<< TEXT <<std::endl;
}

///********************************************************************///
///Menu principal

void menu::menuPrincipal()
{
    menu mJugador;
    menu mClub;
    menu mGoles ;
    menu mListado;
    menu mConsulta;
    menu mInformes;

///inicializacion para las opciones del menu
/// a " Y " la inicializamos en 0.
    int   y=0;
    //esta opcion de rlutil te oculta el cursor (hidecursor)
    rlutil::hidecursor();
///inicializacion para vectores del las opciones 1,2,3,4
// el  ciclo while controlador esta cubierto por el ciclo while bandera para que no le permita salir del programa
// salvo que toque la opcion salir. con una bandera de verdadero o falso.
    bool controlador = true;
    bool bandera=true;
    while (bandera)
    {
        while (controlador)
        {

            bool controlador2 = true;/// controlador de la pregunta si o no para salir

            rlutil::setBackgroundColor(rlutil::BLACK );/// color del fondo
            rlutil::setColor(rlutil::WHITE);/// color del texto

//usamos el rlutil en cls para limpiar la pantalla y en locate para ubicar el menu y los numeros dentro de los () son las
// coordenadas. la posicion "30" es la posicion inicial de la primer palabra. segun el N° que pongamos es donde arranca.
// y si pongo el "12" por ejemplo , me lo pone en la misma fila.
            //rlutil::cls();
            rlutil::locate(30,11);
            cout << "  Goleadores de torneo de futbol  "<<endl;
            rlutil::locate(30,12);
            cout << "--------------"<<endl;
            rlutil::locate(30,13);
            cout << " 1)Jugadores  "<<endl;
            rlutil::locate(30,14);
            cout << " 2)Club "<<endl;
            rlutil::locate(30,15);
            cout << " 3)Goles "<<endl;
            rlutil::locate(30,16);
            cout <<" 4)Listados"<<endl;
            rlutil::locate(30,17);
            cout <<" 5)Consultas"<<endl;
            rlutil::locate(30,18);
            cout <<" 6)Imformes"<<endl;
            rlutil::locate(30,19);
            cout << " 7)SALIR "<<endl;
            rlutil::locate(30,20);
            cout << "--------------"<<endl;
            rlutil::locate(30,21);
            cout << "Use las flechas para arriba y para abajo para moverse en el menu "<<endl;
            rlutil::locate(30,22);
            cout << "Use la tecla enter para seleccionar"<<endl;

            //en showitem como primer parametro le mandamos las opciones del menu
            // ejemplo 1)MODO UN JUGADOR  , EN El segundo parametro le mandamos el 30 , el tercero el 12
            // como cuarto parametro mandamos el seleccionado poniendo lo que tiene" Y " si es igual igual a 0 ,
            // como resultado manda verdadero(true).y si no es igual igual a 0, es porque es 2, osea es falso.esto
            // va a cambiar por cada una de las opciones. esto seria una operacion logica, utilizando el operador de relacion.
            // va a devolver verdadero o falso segun baje o suba " Y " va cambiando segun cuanto valga.
            showItem(" 1)Jugadores  ",30,13,y==0 );
            showItem(" 2)Club       ",30,14,y==1 );
            showItem(" 3)Goles      ",30,15,y==2 );
            showItem(" 4)Listados   ",30,16,y==3 );
            showItem(" 5)Consultas  ",30,17,y==4 );
            showItem(" 6)Informes   ",30,18,y==5 );
            showItem(" 7)SALIR      ",30,19,y==6 );
            rlutil::locate(30,12+y);
            // agregandole al comando rlutil::locate(30,12); una +y asi : rlutil::locate(30,12+y);
            //cout << (char)175<<endl;
            int key = rlutil::getkey();
            // este comando representa un entero que estas presionando en el teclado ( getkey )
            /* // ANYKEY //
              rlutil::locate(10,12);
              cout << "key "<<key<<endl;
              rlutil::anykey();
              // este funcion espera que uno ingrese cualquier tecla ( anykey) por ende sirve para identificar que tecla
              //o numero de tecla o key ,que estoy tocando. diferenciando si esta en mayuscula o minuscula , cambia.
              */
            rlutil::locate(30,19);
            // para mover el cursor hay que cambiar la posicion de Y en locate.
            switch (key)
            {
            case 14 : // up ( TECLA PARA ARRIBA)
                rlutil::locate(30,12+y);
                cout <<" " <<endl;
                // colocando aca ente comando de rlutil y cout antes del y-- o en el y++ lo que hace es dibujar un espacio
                // en blanco para que se borre la flecha para seleccionar y se dibuje donde corresponde.
                y--;
                // el y con el menos menos es para que le quite uno y suba

                if (y<0)
                {
                    y=0;
                }
                // con este if pongo el limite inicial
                break;
            case 15: //down( TECLA PARA ABAJO)
                rlutil::locate(30,12+y);
                cout <<" " <<endl;
                // colocando aca ente comando de rlutil y cout antes del y-- o en el y++ lo que hace es dibujar un espacio
                // en blanco para que se boore la flecha para seleccionar y se dibuje donde corresponde.
                y++;
                // el y con el mas mas es para que suba
                if (y>6)
                {
                    y=6;
                }
                // con este if pongo el limite Final del menu para seleccionar.
                /// se pone de 0 a 4 ya que cuenta desde el 0,la cantidad de opciones.

                break;

            case 1://enter (en este case, seleccionamos las diferentes opciones con la tecla enter )
                system("cls");

///********************************************************************************************/
/// Aca hacemos otro switch para que podamos seleccionar las opciones. analizando el valor de y.
/// los system("pause"); y system ("cls"); de los case del switch(y) es para que vuelva en cada opcion.

                switch(y)
                {
                case 0:

                    mJugador.menuJugadores();
                    system("pause");
                    system ("cls");
                    break;
                case 1:
                    mClub.menuClub();
                    system("pause");
                    system ("cls");
                    break;
                case 2:
                    mGoles.menuGoles();
                    system("pause");
                    system ("cls");
                    break;
                case 3:
                    mListado.menuListados();
                    system("pause");
                    system ("cls");
                    break;
                case 4:
                    mConsulta.menuConsultas();
                    system("pause");
                    system ("cls");
                    break;
                case 5:
                    mInformes.menuInformes();
                    system("pause");
                    system ("cls");
                    break;
                case 6:
                    ///SALIR
                    /// en este caso apretamos enter y sale que es la opcion de salir.

                    system("cls");

                    int ysalida = 0;
                    while (controlador2 == true)
                    {
                        rlutil::locate(30,11);
                        cout << "Esta seguro que quiere salir?";
                        showItem("  SI        ", 30, 12, ysalida == 0);
                        showItem("  NO        ", 30, 13, ysalida == 1);
                        int key = rlutil::getkey();
                        switch (key)
                        {
                        case 14:
                            ysalida--;
                            if (ysalida < 0) ysalida = 0;
                            break;
                        case 15:
                            ysalida++;
                            if (ysalida > 1) ysalida = 1;
                            break;
                        case 1:
                            if (ysalida == 0)
                            {
                                system("cls");
                                cout << "Saliendo del programa...\n";

                                controlador2 = false;
                                controlador = false;
                                bandera = false;
                            }
                            else
                            {
                                controlador2 = false;
                                system("cls");
                            }
                            break;
                        }
                    }
                    break;
                }// fin del  switch Y del menu principal del case 1.
            }// fin switch key del menu principal
        }// fin while controlador del menu principal
    }//fin while bandera
}



///Jugadores
void menu::menuJugadores()
{
    ligaManager lManager;

///inicializacion para las opciones del menu
/// a " Y " la inicializamos en 0.
    int   y=0;
    //esta opcion de rlutil te oculta el cursor (hidecursor)
    rlutil::hidecursor();
///inicializacion para vectores del las opciones 1,2,3,4
// el  ciclo while controlador esta cubierto por el ciclo while bandera para que no le permita salir del programa
// salvo que toque la opcion salir. con una bandera de verdadero o falso.
    bool controlador = true;
    bool bandera=true;
    while (bandera)
    {
        while (controlador)
        {
            rlutil::setBackgroundColor(rlutil::BLACK );/// color del fondo
            rlutil::setColor(rlutil::WHITE);/// color del texto

//usamos el rlutil en cls para limpiar la pantalla y en locate para ubicar el menu y los numeros dentro de los () son las
// coordenadas. la posicion "30" es la posicion inicial de la primer palabra. segun el N° que pongamos es donde arranca.
// y si pongo el "12" por ejemplo , me lo pone en la misma fila.
            //rlutil::cls();
            rlutil::locate(30,11);
            cout << "  Jugadores  "<<endl;
            rlutil::locate(30,12);
            cout << "--------------"<<endl;
            rlutil::locate(30,13);
            cout << " 1)Inscripcion de Jugadores  "<<endl;
            rlutil::locate(30,14);
            cout << " 2)Listar jugadores inscriptos "<<endl;
            rlutil::locate(30,15);
            cout << " 3)Modificar jugadores inscriptos "<<endl;
            rlutil::locate(30,16);
            cout << " 4)Eliminar jugadores inscriptos "<<endl;
            rlutil::locate(30,17);
            cout << " 5)Alta de jugadores eliminados" << endl;
            rlutil::locate(30,18);
            cout << " 4)Volver "<<endl;

            rlutil::locate(30,19);
            cout << "--------------"<<endl;
            rlutil::locate(30,20);
            cout << "Use las flechas para arriba y para abajo para moverse en el menu "<<endl;
            rlutil::locate(30,21);
            cout << "Use la tecla enter para seleccionar"<<endl;

            //en showitem como primer parametro le mandamos las opciones del menu
            // ejemplo 1)MODO UN JUGADOR  , EN El segundo parametro le mandamos el 30 , el tercero el 12
            // como cuarto parametro mandamos el seleccionado poniendo lo que tiene" Y " si es igual igual a 0 ,
            // como resultado manda verdadero(true).y si no es igual igual a 0, es porque es 2, osea es falso.esto
            // va a cambiar por cada una de las opciones. esto seria una operacion logica, utilizando el operador de relacion.
            // va a devolver verdadero o falso segun baje o suba " Y " va cambiando segun cuanto valga.
            showItem(" 1)Inscripcion de Jugadores        ",30,13,y==0 );
            showItem(" 2)Listar jugadores inscriptos     ",30,14,y==1 );
            showItem(" 3)Modificar jugadores inscriptos  ",30,15,y==2 );
            showItem(" 4)Eliminar jugadores inscriptos   ",30,16,y==3 );
            showItem(" 5)Alta de jugadores eliminados    ",30,17,y==4 );
            showItem(" 6)Volver                          ",30,18,y==5 );

            rlutil::locate(30,12+y);
            // agregandole al comando rlutil::locate(30,12); una +y asi : rlutil::locate(30,12+y);
            //cout << (char)175<<endl;
            int key = rlutil::getkey();
            // este comando representa un entero que estas presionando en el teclado ( getkey )
            /* // ANYKEY //
              rlutil::locate(10,12);
              cout << "key "<<key<<endl;
              rlutil::anykey();
              // este funcion espera que uno ingrese cualquier tecla ( anykey) por ende sirve para identificar que tecla
              //o numero de tecla o key ,que estoy tocando. diferenciando si esta en mayuscula o minuscula , cambia.
              */
            rlutil::locate(30,19);
            // para mover el cursor hay que cambiar la posicion de Y en locate.
            switch (key)
            {
            case 14 : // up ( TECLA PARA ARRIBA)
                rlutil::locate(30,12+y);
                cout <<" " <<endl;
                // colocando aca ente comando de rlutil y cout antes del y-- o en el y++ lo que hace es dibujar un espacio
                // en blanco para que se borre la flecha para seleccionar y se dibuje donde corresponde.
                y--;
                // el y con el menos menos es para que le quite uno y suba

                if (y<0)
                {
                    y=0;
                }
                // con este if pongo el limite inicial
                break;
            case 15: //down( TECLA PARA ABAJO)
                rlutil::locate(30,12+y);
                cout <<" " <<endl;
                // colocando aca ente comando de rlutil y cout antes del y-- o en el y++ lo que hace es dibujar un espacio
                // en blanco para que se boore la flecha para seleccionar y se dibuje donde corresponde.
                y++;
                // el y con el mas mas es para que suba
                if (y>5)
                {
                    y=5;
                }
                // con este if pongo el limite Final del menu para seleccionar.
                /// se pone de 0 a 4 ya que cuenta desde el 0,la cantidad de opciones.

                break;

            case 1://enter (en este case, seleccionamos las diferentes opciones con la tecla enter )
                system("cls");

///********************************************************************************************/
/// Aca hacemos otro switch para que podamos seleccionar las opciones. analizando el valor de y.
/// los system("pause"); y system ("cls"); de los case del switch(y) es para que vuelva en cada opcion.

                switch(y)
                {
                case 0:
                    jugador().cargarJugador();///Metodo para ingresar jugadores
                    system("pause");
                    system ("cls");
                    break;
                case 1:
                    lManager.listarRegistrosDinamico(); ///Metodo para listar jugadores
                    system("pause");
                    system ("cls");
                    break;
                case 2:
                    system ("cls");
                    rlutil::showcursor();
                    lManager.modificarJugadores();
                    rlutil::hidecursor();
                    system("pause");
                    system ("cls");
                    break;
                case 3:
                    system ("cls");
                    lManager.eliminarJugador();
                    system("pause");
                    system ("cls");
                    break;
                case 4:
                    system("cls");
                    lManager.darAltaJugador();
                    system("pause");
                    system("cls");
                    break;
                case 5:
                    ///volver
                    /// en este caso apretamos enter para volver.
                    system("cls");
                    controlador=false;
                    bandera=false;
                    break;
                }// fin del  switch Y del menu principal del case 1.
            }// fin switch key del menu principal
        }// fin while controlador del menu principal
    }//fin while bandera
}

///Club
void menu::menuClub()
{
    Club club;
    ligaManager lManager;

///inicializacion para las opciones del menu
/// a " Y " la inicializamos en 0.
    int   y=0;
    //esta opcion de rlutil te oculta el cursor (hidecursor)
    rlutil::hidecursor();
///inicializacion para vectores del las opciones 1,2,3,4
// el  ciclo while controlador esta cubierto por el ciclo while bandera para que no le permita salir del programa
// salvo que toque la opcion salir. con una bandera de verdadero o falso.
    bool controlador = true;
    bool bandera=true;
    while (bandera)
    {
        while (controlador)
        {
            rlutil::setBackgroundColor(rlutil::BLACK );/// color del fondo
            rlutil::setColor(rlutil::WHITE);/// color del texto

//usamos el rlutil en cls para limpiar la pantalla y en locate para ubicar el menu y los numeros dentro de los () son las
// coordenadas. la posicion "30" es la posicion inicial de la primer palabra. segun el N° que pongamos es donde arranca.
// y si pongo el "12" por ejemplo , me lo pone en la misma fila.
            //rlutil::cls();
            rlutil::locate(30,11);
            cout << "  Menu Club  "<<endl;
            rlutil::locate(30,12);
            cout << "--------------"<<endl;
            rlutil::locate(30,13);
            cout << " 1)Inscripcion de Club  "<<endl;
            rlutil::locate(30,14);
            cout << " 2)Listar Clubs "<<endl;
            rlutil::locate(30,15);
            cout << " 3)Modificar Clubs "<<endl;
            rlutil::locate(30,16);
            cout << " 4)Eliminar Club "<<endl;
            rlutil::locate(30,17);
            cout << " 5)Alta de club eliminado"<<endl;
            rlutil::locate(30,18);
            cout << " 6)Volver "<<endl;

            rlutil::locate(30,19);
            cout << "--------------"<<endl;
            rlutil::locate(30,20);
            cout << "Use las flechas para arriba y para abajo para moverse en el menu "<<endl;
            rlutil::locate(30,21);
            cout << "Use la tecla enter para seleccionar"<<endl;

            //en showitem como primer parametro le mandamos las opciones del menu
            // ejemplo 1)MODO UN JUGADOR  , EN El segundo parametro le mandamos el 30 , el tercero el 12
            // como cuarto parametro mandamos el seleccionado poniendo lo que tiene" Y " si es igual igual a 0 ,
            // como resultado manda verdadero(true).y si no es igual igual a 0, es porque es 2, osea es falso.esto
            // va a cambiar por cada una de las opciones. esto seria una operacion logica, utilizando el operador de relacion.
            // va a devolver verdadero o falso segun baje o suba " Y " va cambiando segun cuanto valga.
            showItem(" 1)Inscripcion de Clubs  ",30,13,y==0 );
            showItem(" 2)Listar Clubs          ",30,14,y==1 );
            showItem(" 3)Modificar Clubs       ",30,15,y==2 );
            showItem(" 4)Eliminar Club         ",30,16,y==3);
            showItem(" 5)Alta de club eliminado",30,17,y==4 );
            showItem(" 6)Volver                ",30,18,y==5 );

            rlutil::locate(30,12+y);
            // agregandole al comando rlutil::locate(30,12); una +y asi : rlutil::locate(30,12+y);
            //cout << (char)175<<endl;
            int key = rlutil::getkey();
            // este comando representa un entero que estas presionando en el teclado ( getkey )
            /* // ANYKEY //
              rlutil::locate(10,12);
              cout << "key "<<key<<endl;
              rlutil::anykey();
              // este funcion espera que uno ingrese cualquier tecla ( anykey) por ende sirve para identificar que tecla
              //o numero de tecla o key ,que estoy tocando. diferenciando si esta en mayuscula o minuscula , cambia.
              */
            rlutil::locate(30,19);
            // para mover el cursor hay que cambiar la posicion de Y en locate.
            switch (key)
            {
            case 14 : // up ( TECLA PARA ARRIBA)
                rlutil::locate(30,12+y);
                cout <<" " <<endl;
                // colocando aca ente comando de rlutil y cout antes del y-- o en el y++ lo que hace es dibujar un espacio
                // en blanco para que se borre la flecha para seleccionar y se dibuje donde corresponde.
                y--;
                // el y con el menos menos es para que le quite uno y suba

                if (y<0)
                {
                    y=0;
                }
                // con este if pongo el limite inicial
                break;
            case 15: //down( TECLA PARA ABAJO)
                rlutil::locate(30,12+y);
                cout <<" " <<endl;
                // colocando aca ente comando de rlutil y cout antes del y-- o en el y++ lo que hace es dibujar un espacio
                // en blanco para que se boore la flecha para seleccionar y se dibuje donde corresponde.
                y++;
                // el y con el mas mas es para que suba
                if (y>5)
                {
                    y=5;
                }
                // con este if pongo el limite Final del menu para seleccionar.
                /// se pone de 0 a 4 ya que cuenta desde el 0,la cantidad de opciones.

                break;

            case 1://enter (en este case, seleccionamos las diferentes opciones con la tecla enter )
                system("cls");

///********************************************************************************************/
/// Aca hacemos otro switch para que podamos seleccionar las opciones. analizando el valor de y.
/// los system("pause"); y system ("cls"); de los case del switch(y) es para que vuelva en cada opcion.

                switch(y)
                {
                case 0:
                    club.cargarClub();
                    system("pause");
                    system ("cls");
                    break;
                case 1:
                    lManager.listarClubes();
                    system("pause");
                    system ("cls");
                    break;
                case 2:
                    rlutil::showcursor();
                    lManager.modificarClub();
                    rlutil::hidecursor();
                    system("pause");
                    system ("cls");
                    break;
                case 3:
                    lManager.eliminarClub();
                    system("pause");
                    system ("cls");
                    break;
                case 4:
                    lManager.darAltaClub();
                    system("pause");
                    system ("cls");
                    break;
                case 5:
                    ///volver
                    system("cls");
                    controlador=false;
                    bandera=false;
                    break;
                }// fin del  switch Y del menu case 1.
            }// fin switch key del menu
        }// fin while controlador del menu
    }//fin while bandera
}

///Goles
void menu::menuGoles()
{
    Goles regGoles;
    ligaManager lManager;

///inicializacion para las opciones del menu
/// a " Y " la inicializamos en 0.
    int   y=0;
    //esta opcion de rlutil te oculta el cursor (hidecursor)
    rlutil::hidecursor();
///inicializacion para vectores del las opciones 1,2,3,4
// el  ciclo while controlador esta cubierto por el ciclo while bandera para que no le permita salir del programa
// salvo que toque la opcion salir. con una bandera de verdadero o falso.
    bool controlador = true;
    bool bandera=true;
    while (bandera)
    {
        while (controlador)
        {
            rlutil::setBackgroundColor(rlutil::BLACK );/// color del fondo
            rlutil::setColor(rlutil::WHITE);/// color del texto

//usamos el rlutil en cls para limpiar la pantalla y en locate para ubicar el menu y los numeros dentro de los () son las
// coordenadas. la posicion "30" es la posicion inicial de la primer palabra. segun el N� que pongamos es donde arranca.
// y si pongo el "12" por ejemplo , me lo pone en la misma fila.
            //rlutil::cls();
            rlutil::locate(30,11);
            cout << "  Menu Goles  "<<endl;
            rlutil::locate(30,12);
            cout << "--------------"<<endl;
            rlutil::locate(30,13);
            cout << " 1)Registro Goles"<<endl;
            rlutil::locate(30,14);
            cout << " 2)Listar Goles   "<<endl;
            rlutil::locate(30,15);
            cout << " 3)Modificar Goles  "<<endl;
            rlutil::locate(30,16);
            cout << " 4)Eliminar Goles "<<endl;
            rlutil::locate(30,17);
            cout << " 5)Alta de Gol eliminado"<< endl;
            rlutil::locate(30,18);
            cout << " 6)Volver "<<endl;

            rlutil::locate(30,19);
            cout << "--------------"<<endl;
            rlutil::locate(30,20);
            cout << "Use las flechas para arriba y para abajo para moverse en el menu "<<endl;
            rlutil::locate(30,21);
            cout << "Use la tecla enter para seleccionar"<<endl;

            //en showitem como primer parametro le mandamos las opciones del menu
            // ejemplo 1)MODO UN JUGADOR  , EN El segundo parametro le mandamos el 30 , el tercero el 12
            // como cuarto parametro mandamos el seleccionado poniendo lo que tiene" Y " si es igual igual a 0 ,
            // como resultado manda verdadero(true).y si no es igual igual a 0, es porque es 2, osea es falso.esto
            // va a cambiar por cada una de las opciones. esto seria una operacion logica, utilizando el operador de relacion.
            // va a devolver verdadero o falso segun baje o suba " Y " va cambiando segun cuanto valga.
            showItem(" 1)Registro Goles       ",30,13,y==0 );
            showItem(" 2)Listar Goles         ",30,14,y==1 );
            showItem(" 3)Modificar Goles      ",30,15,y==2 );
            showItem(" 4)Eliminar Goles       ",30,16,y==3 );
            showItem(" 5)Alta de Gol eliminado",30,17,y==4 );
            showItem(" 6)Volver               ",30,18,y==5 );

            rlutil::locate(30,12+y);
            // agregandole al comando rlutil::locate(30,12); una +y asi : rlutil::locate(30,12+y);
            //cout << (char)175<<endl;
            int key = rlutil::getkey();
            // este comando representa un entero que estas presionando en el teclado ( getkey )
            /* // ANYKEY //
              rlutil::locate(10,12);
              cout << "key "<<key<<endl;
              rlutil::anykey();
              // este funcion espera que uno ingrese cualquier tecla ( anykey) por ende sirve para identificar que tecla
              //o numero de tecla o key ,que estoy tocando. diferenciando si esta en mayuscula o minuscula , cambia.
              */
            rlutil::locate(30,19);
            // para mover el cursor hay que cambiar la posicion de Y en locate.
            switch (key)
            {
            case 14 : // up ( TECLA PARA ARRIBA)
                rlutil::locate(30,12+y);
                cout <<" " <<endl;
                // colocando aca ente comando de rlutil y cout antes del y-- o en el y++ lo que hace es dibujar un espacio
                // en blanco para que se borre la flecha para seleccionar y se dibuje donde corresponde.
                y--;
                // el y con el menos menos es para que le quite uno y suba

                if (y<0)
                {
                    y=0;
                }
                // con este if pongo el limite inicial
                break;
            case 15: //down( TECLA PARA ABAJO)
                rlutil::locate(30,12+y);
                cout <<" " <<endl;
                // colocando aca ente comando de rlutil y cout antes del y-- o en el y++ lo que hace es dibujar un espacio
                // en blanco para que se boore la flecha para seleccionar y se dibuje donde corresponde.
                y++;
                // el y con el mas mas es para que suba
                if (y>5)
                {
                    y=5;
                }
                // con este if pongo el limite Final del menu para seleccionar.
                /// se pone de 0 a 4 ya que cuenta desde el 0,la cantidad de opciones.

                break;

            case 1://enter (en este case, seleccionamos las diferentes opciones con la tecla enter )
                system("cls");

///********************************************************************************************/
/// Aca hacemos otro switch para que podamos seleccionar las opciones. analizando el valor de y.
/// los system("pause"); y system ("cls"); de los case del switch(y) es para que vuelva en cada opcion.

                switch(y)
                {
                case 0:// TODO: CAMBIAR ESTO PARA QUE APUNTE A GOLES.CPP O .H DEPENDE DE COMO LO HIZO RODO BUSCAR INSCRIPCION Y LISTAR Y REAPLICARLO
                    regGoles.cargarGoles();
                    system("pause");
                    system ("cls");
                    break;
                case 1:

                    lManager.listarGoles();
                    system("pause");
                    system ("cls");
                    break;
                case 2:
                    rlutil::showcursor();
                    lManager.modificarGoles();
                    rlutil::hidecursor();
                    system("pause");
                    system ("cls");
                    break;
                case 3:
                    lManager.eliminarGoles();

                    system("pause");
                    system ("cls");
                    break;
                case 4:
                    lManager.darAltaGoles();
                    system("pause");
                    system ("cls");
                    break;
                case 5:
                    //volver
                    system("cls");
                    controlador=false;
                    bandera=false;
                    break;
                }// fin del  switch Y del menu principal del case 1.
            }// fin switch key del menu principal
        }// fin while controlador del menu principal
    }//fin while bandera
}




///********************************************************************///
/// listado

void menu::menuListados()
{
    ListadosManager listados;

///inicializacion para las opciones del menu
/// a " Y " la inicializamos en 0.
    int   y=0;
    //esta opcion de rlutil te oculta el cursor (hidecursor)
    rlutil::hidecursor();
///inicializacion para vectores del las opciones 1,2,3,4
// el  ciclo while controlador esta cubierto por el ciclo while bandera para que no le permita salir del programa
// salvo que toque la opcion salir. con una bandera de verdadero o falso.
    bool controlador = true;
    bool bandera=true;
    while (bandera)
    {
        while (controlador)
        {
            rlutil::setBackgroundColor(rlutil::BLACK );/// color del fondo
            rlutil::setColor(rlutil::WHITE);/// color del texto

//usamos el rlutil en cls para limpiar la pantalla y en locate para ubicar el menu y los numeros dentro de los () son las
// coordenadas. la posicion "30" es la posicion inicial de la primer palabra. segun el N� que pongamos es donde arranca.
// y si pongo el "12" por ejemplo , me lo pone en la misma fila.
            //rlutil::cls();
            rlutil::locate(30,11);
            cout << "  Menu Listados  "<<endl;
            rlutil::locate(30,12);
            cout << "--------------"<<endl;
            rlutil::locate(30,13);
            cout << " 1)Jugadores por apellido"<<endl;/// aca lo ingresa
            rlutil::locate(30,14);
            cout << " 2)Clubes por nombre "<<endl;/// aca lo muestra
            rlutil::locate(30,15);
            cout << " 3)Goles por numero de partido  "<<endl;
            rlutil::locate(30,16);
            cout << " 4)Volver "<<endl;
            rlutil::locate(30,17);

            cout << "--------------"<<endl;
            rlutil::locate(30,18);
            cout << "Use las flechas para arriba y para abajo para moverse en el menu "<<endl;
            rlutil::locate(30,19);
            cout << "Use la tecla enter para seleccionar"<<endl;

            //en showitem como primer parametro le mandamos las opciones del menu
            // ejemplo 1)MODO UN JUGADOR  , EN El segundo parametro le mandamos el 30 , el tercero el 12
            // como cuarto parametro mandamos el seleccionado poniendo lo que tiene" Y " si es igual igual a 0 ,
            // como resultado manda verdadero(true).y si no es igual igual a 0, es porque es 2, osea es falso.esto
            // va a cambiar por cada una de las opciones. esto seria una operacion logica, utilizando el operador de relacion.
            // va a devolver verdadero o falso segun baje o suba " Y " va cambiando segun cuanto valga.
            showItem(" 1)Jugadores por apellido     ",30,13,y==0 );
            showItem(" 2)Clubes por nombre          ",30,14,y==1 );
            showItem(" 3)Goles por numero de partido",30,15,y==2 );
            showItem(" 4)Volver                     ",30,16,y==3 );
            rlutil::locate(30,12+y);
            // agregandole al comando rlutil::locate(30,12); una +y asi : rlutil::locate(30,12+y);
            //cout << (char)175<<endl;
            int key = rlutil::getkey();
            // este comando representa un entero que estas presionando en el teclado ( getkey )
            /* // ANYKEY //
              rlutil::locate(10,12);
              cout << "key "<<key<<endl;
              rlutil::anykey();
              // este funcion espera que uno ingrese cualquier tecla ( anykey) por ende sirve para identificar que tecla
              //o numero de tecla o key ,que estoy tocando. diferenciando si esta en mayuscula o minuscula , cambia.
              */
            rlutil::locate(30,19);
            // para mover el cursor hay que cambiar la posicion de Y en locate.
            switch (key)
            {
            case 14 : // up ( TECLA PARA ARRIBA)
                rlutil::locate(30,12+y);
                cout <<" " <<endl;
                // colocando aca ente comando de rlutil y cout antes del y-- o en el y++ lo que hace es dibujar un espacio
                // en blanco para que se borre la flecha para seleccionar y se dibuje donde corresponde.
                y--;
                // el y con el menos menos es para que le quite uno y suba

                if (y<0)
                {
                    y=0;
                }
                // con este if pongo el limite inicial
                break;
            case 15: //down( TECLA PARA ABAJO)
                rlutil::locate(30,12+y);
                cout <<" " <<endl;
                // colocando aca ente comando de rlutil y cout antes del y-- o en el y++ lo que hace es dibujar un espacio
                // en blanco para que se boore la flecha para seleccionar y se dibuje donde corresponde.
                y++;
                // el y con el mas mas es para que suba
                if (y>3)
                {
                    y=3;
                }
                // con este if pongo el limite Final del menu para seleccionar.
                /// se pone de 0 a 4 ya que cuenta desde el 0,la cantidad de opciones.

                break;

            case 1://enter (en este case, seleccionamos las diferentes opciones con la tecla enter )
                system("cls");

///********************************************************************************************/
/// Aca hacemos otro switch para que podamos seleccionar las opciones. analizando el valor de y.
/// los system("pause"); y system ("cls"); de los case del switch(y) es para que vuelva en cada opcion.

                switch(y)
                {
                case 0:

                    listados.JugadoresXapellido();
                    system("pause");
                    system ("cls");
                    break;
                case 1:
                    listados.ClubesPorNombre();
                    system("pause");
                    system ("cls");
                    break;
                case 2:
                    listados.ListadoGolesPorPartido();
                    system("pause");
                    system ("cls");
                    break;
                case 3:
                    ///volver
                    /// en este caso apretamos enter para volver.
                    system("cls");
                    controlador=false;
                    bandera=false;
                    break;
                }// fin del  switch Y del menu principal del case 1.
            }// fin switch key del menu principal
        }// fin while controlador del menu principal
    }//fin while bandera
}



///********************************************************************///
/// consultas
void menu::menuConsultas()
{
    ConsultasManager consultas;

///inicializacion para las opciones del menu
/// a " Y " la inicializamos en 0.
    int   y=0;
    //esta opcion de rlutil te oculta el cursor (hidecursor)
    //rlutil::hidecursor();
///inicializacion para vectores del las opciones 1,2,3,4
// el  ciclo while controlador esta cubierto por el ciclo while bandera para que no le permita salir del programa
// salvo que toque la opcion salir. con una bandera de verdadero o falso.
    bool controlador = true;
    bool bandera=true;
    while (bandera)
    {
        while (controlador)
        {
            rlutil::setBackgroundColor(rlutil::BLACK );/// color del fondo
            rlutil::setColor(rlutil::WHITE);/// color del texto

//usamos el rlutil en cls para limpiar la pantalla y en locate para ubicar el menu y los numeros dentro de los () son las
// coordenadas. la posicion "30" es la posicion inicial de la primer palabra. segun el N� que pongamos es donde arranca.
// y si pongo el "12" por ejemplo , me lo pone en la misma fila.
            rlutil::cls();
            rlutil::locate(30,11);
            cout << "  Menu Consultas  "<<endl;
            rlutil::locate(30,12);
            cout << "--------------"<<endl;
            rlutil::locate(30,13);
            cout << " 1)Buscar con DNI de Jugadores "<<endl;/// aca lo ingresa
            rlutil::locate(30,14);
            cout << " 2)Buscar Club por codigo "<<endl;/// aca lo muestra
            rlutil::locate(30,15);
            cout << " 3)Buscar goles con numero de partido "<<endl;
            rlutil::locate(30,16);
            cout << " 4)Cantidad de Jugadores por nombre Club "<<endl;
            rlutil::locate(30,17);
            cout << "4)Volver " << endl;
            rlutil::locate(30,18);
            cout << "--------------"<<endl;
            rlutil::locate(30,19);
            cout << "Use las flechas para arriba y para abajo para moverse en el menu "<<endl;
            rlutil::locate(30,20);
            cout << "Use la tecla enter para seleccionar"<<endl;

            //en showitem como primer parametro le mandamos las opciones del menu
            // ejemplo 1)MODO UN JUGADOR  , EN El segundo parametro le mandamos el 30 , el tercero el 12
            // como cuarto parametro mandamos el seleccionado poniendo lo que tiene" Y " si es igual igual a 0 ,
            // como resultado manda verdadero(true).y si no es igual igual a 0, es porque es 2, osea es falso.esto
            // va a cambiar por cada una de las opciones. esto seria una operacion logica, utilizando el operador de relacion.
            // va a devolver verdadero o falso segun baje o suba " Y " va cambiando segun cuanto valga.
            showItem(" 1)Buscar con DNI de Jugadores           ",30,13,y==0 );
            showItem(" 2)Buscar Club por codigo                ",30,14,y==1 );
            showItem(" 3)Buscar goles con numero de partido    ",30,15,y==2 );
            showItem(" 4)Cantidad de Jugadores por nombre Club ",30,16,y==3 );
            showItem(" 5)Volver                                ",30,17,y==4 );

            rlutil::locate(30,12+y);
            // agregandole al comando rlutil::locate(30,12); una +y asi : rlutil::locate(30,12+y);
            //cout << (char)175<<endl;
            int key = rlutil::getkey();
            // este comando representa un entero que estas presionando en el teclado ( getkey )
            /* // ANYKEY //
              rlutil::locate(10,12);
              cout << "key "<<key<<endl;
              rlutil::anykey();
              // este funcion espera que uno ingrese cualquier tecla ( anykey) por ende sirve para identificar que tecla
              //o numero de tecla o key ,que estoy tocando. diferenciando si esta en mayuscula o minuscula , cambia.
              */
            rlutil::locate(30,19);
            // para mover el cursor hay que cambiar la posicion de Y en locate.
            switch (key)
            {
            case 14 : // up ( TECLA PARA ARRIBA)
                rlutil::locate(30,12+y);
                cout <<" " <<endl;
                // colocando aca ente comando de rlutil y cout antes del y-- o en el y++ lo que hace es dibujar un espacio
                // en blanco para que se borre la flecha para seleccionar y se dibuje donde corresponde.
                y--;
                // el y con el menos menos es para que le quite uno y suba

                if (y<0)
                {
                    y=0;
                }
                // con este if pongo el limite inicial
                break;
            case 15: //down( TECLA PARA ABAJO)
                rlutil::locate(30,12+y);
                cout <<" " <<endl;
                // colocando aca ente comando de rlutil y cout antes del y-- o en el y++ lo que hace es dibujar un espacio
                // en blanco para que se boore la flecha para seleccionar y se dibuje donde corresponde.
                y++;
                // el y con el mas mas es para que suba
                if (y>4)
                {
                    y=4;
                }
                // con este if pongo el limite Final del menu para seleccionar.
                /// se pone de 0 a 4 ya que cuenta desde el 0,la cantidad de opciones.

                break;

            case 1://enter (en este case, seleccionamos las diferentes opciones con la tecla enter )
                system("cls");

///********************************************************************************************/
/// Aca hacemos otro switch para que podamos seleccionar las opciones. analizando el valor de y.
/// los system("pause"); y system ("cls"); de los case del switch(y) es para que vuelva en cada opcion.

                switch(y)
                {
                case 0:
                    consultas.buscarDNIjugador();
                    system("pause");
                    system ("cls");
                    break;
                case 1:
                    consultas.ClubesPorCodigo();
                    system("pause");
                    system ("cls");
                    break;
                case 2:
                    consultas.golesXpartido();
                    system("pause");
                    system ("cls");
                    break;

                case 3:
                    rlutil::showcursor();
                    consultas.CantidadJugadoresPorNombreClub();
                    rlutil::hidecursor();
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    ///volver
                    /// en este caso apretamos enter para volver.
                    system("cls");
                    controlador=false;
                    bandera=false;
                    break;
                }// fin del  switch Y del menu principal del case 1.
            }// fin switch key del menu principal
        }// fin while controlador del menu principal
    }//fin while bandera
}


///********************************************************************///
/// informes
void menu::menuInformes()
{
    InformesManager informes;

///inicializacion para las opciones del menu
/// a " Y " la inicializamos en 0.
    int   y=0;
    //esta opcion de rlutil te oculta el cursor (hidecursor)
    rlutil::hidecursor();
///inicializacion para vectores del las opciones 1,2,3,4
// el  ciclo while controlador esta cubierto por el ciclo while bandera para que no le permita salir del programa
// salvo que toque la opcion salir. con una bandera de verdadero o falso.
    bool controlador = true;
    bool bandera=true;
    while (bandera)
    {
        while (controlador)
        {
            rlutil::setBackgroundColor(rlutil::BLACK );/// color del fondo
            rlutil::setColor(rlutil::WHITE);/// color del texto

//usamos el rlutil en cls para limpiar la pantalla y en locate para ubicar el menu y los numeros dentro de los () son las
// coordenadas. la posicion "30" es la posicion inicial de la primer palabra. segun el N� que pongamos es donde arranca.
// y si pongo el "12" por ejemplo , me lo pone en la misma fila.
            //rlutil::cls();
            rlutil::locate(30,11);
            cout << "  Menu Informes  "<<endl;
            rlutil::locate(30,12);
            cout << "--------------"<<endl;
            rlutil::locate(30,13);
            cout << " 1) Informe de los Goles por Jugador (en el torneo) "<<endl;
            rlutil::locate(30,14);
            cout << " 2) Informe de los Goles por Club "<<endl;
            rlutil::locate(30,15);
            cout << " 3) Informe de los Goles por el tipo de gol "<<endl;
            rlutil::locate(30,16);
            cout << " 4) Volver                                         "<<endl;
            rlutil::locate(30,17);


            cout << "--------------"<<endl;
            rlutil::locate(30,18);
            cout << "Use las flechas para arriba y para abajo para moverse en el menu "<<endl;
            rlutil::locate(30,19);
            cout << "Use la tecla enter para seleccionar"<<endl;

            //en showitem como primer parametro le mandamos las opciones del menu
            // ejemplo 1)MODO UN JUGADOR  , EN El segundo parametro le mandamos el 30 , el tercero el 12
            // como cuarto parametro mandamos el seleccionado poniendo lo que tiene" Y " si es igual igual a 0 ,
            // como resultado manda verdadero(true).y si no es igual igual a 0, es porque es 2, osea es falso.esto
            // va a cambiar por cada una de las opciones. esto seria una operacion logica, utilizando el operador de relacion.
            // va a devolver verdadero o falso segun baje o suba " Y " va cambiando segun cuanto valga.
            showItem(" 1) Informe de los Goles por Jugador (en un torneo)",30,13,y==0 );
            showItem(" 2) Informe de los Goles por Club                  ",30,14,y==1 );
            showItem(" 3) Informe de los Goles por el tipo de gol        ",30,15,y==2 );
            showItem(" 4) Volver                                         ",30,16,y==3 );

            rlutil::locate(30,12+y);
            // agregandole al comando rlutil::locate(30,12); una +y asi : rlutil::locate(30,12+y);
            //cout << (char)175<<endl;
            int key = rlutil::getkey();
            // este comando representa un entero que estas presionando en el teclado ( getkey )
            /* // ANYKEY //
              rlutil::locate(10,12);
              cout << "key "<<key<<endl;
              rlutil::anykey();
              // este funcion espera que uno ingrese cualquier tecla ( anykey) por ende sirve para identificar que tecla
              //o numero de tecla o key ,que estoy tocando. diferenciando si esta en mayuscula o minuscula , cambia.
              */
            rlutil::locate(30,19);
            // para mover el cursor hay que cambiar la posicion de Y en locate.
            switch (key)
            {
            case 14 : // up ( TECLA PARA ARRIBA)
                rlutil::locate(30,12+y);
                cout <<" " <<endl;
                // colocando aca ente comando de rlutil y cout antes del y-- o en el y++ lo que hace es dibujar un espacio
                // en blanco para que se borre la flecha para seleccionar y se dibuje donde corresponde.
                y--;
                // el y con el menos menos es para que le quite uno y suba

                if (y<0)
                {
                    y=0;
                }
                // con este if pongo el limite inicial
                break;
            case 15: //down( TECLA PARA ABAJO)
                rlutil::locate(30,12+y);
                cout <<" " <<endl;
                // colocando aca ente comando de rlutil y cout antes del y-- o en el y++ lo que hace es dibujar un espacio
                // en blanco para que se boore la flecha para seleccionar y se dibuje donde corresponde.
                y++;
                // el y con el mas mas es para que suba
                if (y>3)
                {
                    y=3;
                }
                // con este if pongo el limite Final del menu para seleccionar.
                /// se pone de 0 a 4 ya que cuenta desde el 0,la cantidad de opciones.

                break;

            case 1://enter (en este case, seleccionamos las diferentes opciones con la tecla enter )
                system("cls");

///********************************************************************************************/
/// Aca hacemos otro switch para que podamos seleccionar las opciones. analizando el valor de y.
/// los system("pause"); y system ("cls"); de los case del switch(y) es para que vuelva en cada opcion.

                switch(y)
                {
                case 0:
                    informes.InfoGolesPorJugador();
                    cout << "Aca INFORME GOLES POR JUGADOR"<<endl;
                    system("pause");
                    system ("cls");
                    break;
                case 1:
                    informes.InfoGolesPorClub();
                    system("pause");
                    system ("cls");
                    break;
                case 2:
                    informes.InfoGolesPorTipo();
                    system("pause");
                    system ("cls");
                    break;
                case 3:
                    ///volver
                    /// en este caso apretamos enter para volver.
                    system("cls");
                    controlador=false;
                    bandera=false;
                    break;
                }// fin del  switch Y del menu principal del case 1.
            }// fin switch key del menu principal
        }// fin while controlador del menu principal
    }//fin while bandera
}

