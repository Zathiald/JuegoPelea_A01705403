/*
 *
 * Proyecto Juego de Peleas
 * Samir Baidon Pardo
 * A01705403
 * 20/05/2023
 * versio : 4
 * Esta clase define la clase de Contrincante, tiene los setters y
 * getter necesarios para que se creen objetos derivados de
 * la clase y tener así un arreglo de contrincantes
 */


#ifndef CONTRINCANTE_H
#define CONTRINCANTE_H
#include "jugador.h"//Importo el archivo de jugador para
//poder hacer referencia a la clase jugador
//y tener así agregación y comunicación entre clases
#include <iostream>
#include <cstdlib>

using namespace std;

class Contrincante {

//Se declaran los atributos privados de la clase
private:
    float vidaCont;
    float fuerzaCont1;
    float fuerzaCont2;
    float fuerzaCont3;
    float fuerzaCont4;

public:
    Contrincante() {}

    Contrincante(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2);
    Contrincante(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2, float fuerzaEnem3);
    Contrincante(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2, float fuerzaEnem3, float fuerzaEnem4);

    //getters
    float getvidaCont() { return vidaCont; }
    float getfuerzaCont1() { return fuerzaCont1; }
    float getfuerzaCont2() { return fuerzaCont2; }
    float getfuerzaCont3() { return fuerzaCont3; }
    float getfuerzaCont4() { return fuerzaCont4; }

    //setters
    void setvidaCont(float vidaEnem);

    //Método de clase abstracta
    virtual void atacarJugador(string decision, int aJ, Jugador* jugador, Contrincante* contrincante)=0;
};

void Contrincante::setvidaCont(float vidaEnem) {
    vidaCont = vidaEnem;
}

Contrincante::Contrincante(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2) {
    vidaCont = vidaEnem;
    fuerzaCont1 = fuerzaEnem1;
    fuerzaCont2 = fuerzaEnem2;
}

Contrincante::Contrincante(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2, float fuerzaEnem3) {
    vidaCont = vidaEnem;
    fuerzaCont1 = fuerzaEnem1;
    fuerzaCont2 = fuerzaEnem2;
    fuerzaCont3 = fuerzaEnem3;
}

Contrincante::Contrincante(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2, float fuerzaEnem3, float fuerzaEnem4) {
    vidaCont = vidaEnem;
    fuerzaCont1 = fuerzaEnem1;
    fuerzaCont2 = fuerzaEnem2;
    fuerzaCont3 = fuerzaEnem3;
    fuerzaCont4 = fuerzaEnem4;
}

#endif
