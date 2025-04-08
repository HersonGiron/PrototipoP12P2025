//Realizado por alumno: Herson Omar Giron Quixtan
//Carné: 9959-24-20
//Examen 2do parcial
//año: 2025
#ifndef CELDA_H
#define CELDA_H
//Libreria que guarda los atributos y los prototipos de los metodos utilizados para crear y administrar las celdas de juego


class Celda
{
    public:
        Celda();
        Celda(int coordenadaX, int coordenadaY, bool estadoMina);
        int setCoordenadaX(int coordenadaX);
        int getCoordenadaX();
        int setCoordenadaY(int coordenadaY);
        int getCoordenadaY();
        bool setMina(bool estadoMina);
        bool getMina();
        bool setMinaDescubierta(bool minaDescubierta);
        bool getMinaDescubierta();
        void imprimirCelda();
    protected:

    private:
        int coordenadaX, coordenadaY;
        bool mina, minaDescubierta;
};

#endif // CELDA_H
