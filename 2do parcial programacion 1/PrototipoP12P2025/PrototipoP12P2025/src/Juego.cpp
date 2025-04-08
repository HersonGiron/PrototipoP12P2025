//Realizado por alumno: Herson Omar Giron Quixtan
//Carné: 9959-24-20
//Examen 2do parcial
//año: 2025

//incluye las bibliotecas
#include "Juego.h"
#include <fstream>
#include <unistd.h>
#include <chrono>

int Juego::aleatorio_en_rango(int minimo, int maximo)
{
	return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

int Juego::filaAleatoria()
{
	return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
}

int Juego::columnaAleatoria()
{
	return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
}

Juego::Juego(Tablero tablero, int cantidadMinas,string nombreUsuario)
{
	this->tablero = tablero;
	this->cantidadMinas = cantidadMinas;
	this->score = 0;
	this->nombreUsuario = nombreUsuario;
	this->colocarMinasAleatoriamente();
}

//coloca las minas aleatoriamente en el juego
void Juego::colocarMinasAleatoriamente()
{
	int x, y, minasColocadas = 0;

	while (minasColocadas < this->cantidadMinas)
	{
		x = this->columnaAleatoria();
		y = this->filaAleatoria();
		if (this->tablero.colocarMina(x, y))
		{
			minasColocadas++;
		}
	}
}

//le solicita la fila a jugar al usuario
int Juego::solicitarFilaUsuario()
{
	int fila = 0;
	cout << this->nombreUsuario << ",ingresa la FILA en la que desea jugar: ";
	cin >> fila;
	return fila - 1;
}
//le solicita la columna a jugar al usuario
int Juego::solicitarColumnaUsuario()
{
	int columna = 0;
	cout << this->nombreUsuario << ",ingresa la COLUMNA en la que desea jugar: ";
	cin >> columna;
	return columna - 1;
}

bool Juego::jugadorGana()
{
	int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir();
	return conteo == 0;
}

void Juego::iniciar()
{
    //nos indica el nombre de la persona que esta jugando
    cout << "Persona que esta jugando: " << this->nombreUsuario << ",Buena suerte!\n";
	int fila, columna;
	auto inicio = std::chrono::high_resolution_clock::now(); // Se guarda el tiempo de inicio

	while (this->vidasTablero > 0)
	{
		this->tablero.imprimir();
		//nos indica el puntuaje que tenemos en cada ronda
		cout << "Puntaje actual de " << this->nombreUsuario << ",es: " << this->score << "\n";

		fila = this->solicitarFilaUsuario();
		columna = this->solicitarColumnaUsuario();

		bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);
		if (!respuestaAUsuario)
		{
		    //nos indica la cantidad de vidas que nos quedan
			this->vidasTablero--;
			cout << "Te quedan " << this->vidasTablero << " vidas, " << this->nombreUsuario << "\n";

			if (this->vidasTablero == 0)
			{

				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				// Calculamos el tiempo total jugado
				auto fin = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> duracion = fin - inicio;
				int totalSegundos = static_cast<int>(duracion.count());
				int minutos = totalSegundos / 60;
				int segundos = totalSegundos % 60;
                //indica el nombre del jugador que ha perdido el juego
                cout << "El jugador: " << this->nombreUsuario << ",¡Ha perdido el juego!\n";
				//nos indica nuestro puntaje final
				cout << "El puntaje final de: " << this->nombreUsuario << ",fue " << this->score << "\n";
				//tiempo total que se jugó
				cout << "El tiempo total en el que jugó: " << this->nombreUsuario << ",fue de: " << minutos << " min y " << segundos << " seg\n";
				break;
			}
		}
		else
		{
		    //va contando de uno en uno cada vez que se gana una ronda
			this->score += 1;
		}

		if (this->jugadorGana())
		{
			this->tablero.setModoDesarrollador(true);
			this->tablero.imprimir();
			// Calculamos el tiempo total jugado
			auto fin = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> duracion = fin - inicio;
			int totalSegundos = static_cast<int>(duracion.count());
			int minutos = totalSegundos / 60;
			int segundos = totalSegundos % 60;
			//indica el nombre del jugador que ha ganado el juego
		    cout << "El jugador: " << this->nombreUsuario << ",¡Ha ganado el juego!\n";
			//Nos indica el puntaje final
            cout << "El puntaje final de: " << this->nombreUsuario << ",fue " << this->score << "\n";
			//Nos indica la cantidad de tiempo el cual se jugó junto con el nombre del usuario
			cout << "El tiempo total en el que jugó: " << this->nombreUsuario << ",fue de: " << minutos << " min y " << segundos << " seg\n";
			break;
		}
	}
}
