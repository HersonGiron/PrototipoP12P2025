//Realizado por alumno: Herson Omar Giron Quixtan
//Carn�: 9959-24-20
//Examen 2do parcial
//a�o: 2025
// Inclusi�n de bibliotecas y headers
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include "Juego.h"
#include "Config.h"

using namespace std;

// Main del proyecto
int main()
{
    // Valores predeterminados de la configuraci�n por defecto
    const int FILASTABLERO = 4;
    const int COLUMNASTABLERO = 4;
    const int MINASENTABLERO = 1;
    const string NOMBREUSUARIO= "Anonimo";
    const bool MODODESARROLLADOR = true;
    const int VIDASTABLERO = 3;

    // Llamada a la funci�n de configuraci�n del juego
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO, NOMBREUSUARIO);
    Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero(), configuracionJuego.getnombreUsuario());
    srand(time(NULL));

    int opciones;
    bool repetir = true;

    // Ciclo de men�
    do
    {
        system("cls");

        cout << "\n\n\t\tBUSCA MINAS - Menu -" << endl;
        cout << "\t\t----------------------" << endl;
        cout << "\t\t1. Configuraci�n del Juego" << endl;
        cout << "\t\t2. Iniciar el Juego" << endl;
        cout << "\t\t3. Salir del Juego" << endl;
        cout << "\n\t\tIngrese una opci�n: ";
        cin >> opciones;

        switch (opciones)
        {
        case 1:

            configuracionJuego.menuConfiguracion();
            break;

        case 2:
        {
            // Iniciar juego con configuraci�n actual
            Juego juegoTemporal(
                Tablero(
                    configuracionJuego.getfilasTablero(),
                    configuracionJuego.getcolumnasTablero(),
                    configuracionJuego.getmodoDesarrolladorTablero()
                ),
                configuracionJuego.getminasTablero(),
                configuracionJuego.getnombreUsuario());

            juegoTemporal.iniciar();
            system("pause"); // Pausa para ver resultados
            break;
        }

        case 3:
            repetir = false;
            break;

        default:
            cout << "Opci�n inv�lida. Intente nuevamente.\n";
            system("pause");
            break;
        }

    } while (repetir);

    system("cls"); // Limpia pantalla antes de salir
    return 0;
}

