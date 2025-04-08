//Realizado por alumno: Herson Omar Giron Quixtan
//Carné: 9959-24-20
//Examen 2do parcial
//año: 2025
#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"

class Juego
{
private:
	Tablero tablero;
	int cantidadMinas;
    int score;
    int vidasTablero = 3;
	int aleatorio_en_rango(int minimo, int maximo);
	int filaAleatoria();
	int columnaAleatoria();
public:
    string nombreUsuario;
    Juego(Tablero tablero, int cantidadMinas, string nombreUsuario);
	void colocarMinasAleatoriamente();
	int solicitarFilaUsuario();
	int solicitarColumnaUsuario();
	bool jugadorGana();
	void iniciar();
	void dibujarPortada(string nombreArchivo);
};

#endif // JUEGO_H
