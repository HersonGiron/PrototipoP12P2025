//Realizado por alumno: Herson Omar Giron Quixtan
//Carn�: 9959-24-20
//Examen 2do parcial
//a�o: 2025
//Directiva para evitar inclusiones m�ltiples del archivo
#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>

using namespace std;

//clase para manejar la configuraci�n del juego.
class Config
{
    public:
        //Constructor de la clase Config
        Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero, string nombreUsuario);
        // M�todos getter y setter para acceder y modificar los atributos privados
        int getfilasTablero();
        void setfilasTablero(int filasTablero);

        int getcolumnasTablero();
        void setcolumnasTablero(int columnasTablero);

        int getminasTablero();
        void setminasTablero(int minasTablero);

        bool getmodoDesarrolladorTablero();
        void setmodoDesarrolladorTablero(bool modoDesarrolladorTablero);

        int getvidasTablero();
        void setvidasTablero(int vidasTablero);

        string getnombreUsuario();
        void setnombreUsuario(string nombreUsuario);

        void menuConfiguracion();
        //Muestra un men� de configuraci�n para modificar par�metros del tablero
    protected:

    private:
        //indica el numero de filas, columnas, minas, vidas del tablero y muestra si el modo desarrollador esta activado o desactivado
        int filasTablero;
        int columnasTablero;
        int minasTablero;
        bool modoDesarrolladorTablero;
        int vidasTablero;
        string nombreUsuario;
};

//Finalizaci�n de la directiva
#endif // CONFIG_H
