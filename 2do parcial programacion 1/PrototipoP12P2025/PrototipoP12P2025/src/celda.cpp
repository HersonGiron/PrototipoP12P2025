//Realizado por alumno: Herson Omar Giron Quixtan
//Carné: 9959-24-20
//Examen 2do parcial
//año: 2025
#include "Celda.h"
#include <iostream>
using namespace std;
Celda::Celda()
{
}
//Constructor de la clase Celda.
Celda::Celda(int coordenadaX, int coordenadaY, bool estadoMina)
{
    this->coordenadaX = coordenadaX;
    this->coordenadaY = coordenadaY;
    this->mina = estadoMina;
    this->minaDescubierta = false;
}
//Establece la coordenada X de la celda
int Celda::setCoordenadaX(int coordenadaX)
{
    this->coordenadaX = coordenadaX;
}
//Obtiene la coordenada X de la celda
int Celda::getCoordenadaX()
{
    return this->coordenadaX;
}
//Establece la coordenada y de la celda
int Celda::setCoordenadaY(int coordenadaY)
{
    this->coordenadaY = coordenadaY;
}
//Obtiene la coordenada y de la celda
int Celda::getCoordenadaY()
{
    return this->coordenadaY;
}
//Establece el estado de la mina en la celda e indica si la celda debe contener una mina.
bool Celda::setMina(bool estadoMina)
{
    if (this->getMina())
    {
        return false;
    }
    else{
        this->mina = estadoMina;
        return true;
    }
}
bool Celda::getMina()
{
    return this->mina;
}
bool Celda::setMinaDescubierta(bool minaDescubierta)
{
    this->minaDescubierta = minaDescubierta;
}
bool Celda::getMinaDescubierta()
{
    return this->minaDescubierta;
}
//Imprime la información de la celda en consola
void Celda::imprimirCelda()
{
    cout << "Celda en " << this->coordenadaX << ", " << this->coordenadaY << " con mina? " << this->mina << "\n";
}


