/*
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

//Se declaran los atributos públicos de la clase
public:
    Contrincante() {}

    //Métodos con sobrecarga
    Contrincante(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2);
    Contrincante(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2, float fuerzaEnem3); //Agregamos más parametros para tener sobrecarga
    Contrincante(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2, float fuerzaEnem3, float fuerzaEnem4); //Igual aqui tenemos sobrecarga de funciones

    //getters
    float getvidaCont() { return vidaCont; }
    float getfuerzaCont1() { return fuerzaCont1; }
    float getfuerzaCont2() { return fuerzaCont2; }
    float getfuerzaCont3() { return fuerzaCont3; }
    float getfuerzaCont4() { return fuerzaCont4; }

    //setters
    void setvidaCont(float vidaEnem);

    //Método de clase abstracta, 
    // esta función va a ser sobreescrita en clases heredadas
    virtual void atacarJugador(string decision, int aJ, Jugador* jugador, Contrincante* contrincante)=0;
};

//Funcion:Darle nuevo valor a la variable de vida del contrincante
// 
//Parametros: Se toma un parametro float para darle ese valor a la
//vida del jugador
// 
//Retorno: Al ser una función void no se regresa algo en sí,solo se 
//da el valor a la vida del enemigo
void Contrincante::setvidaCont(float vidaEnem) {
    vidaCont = vidaEnem;
}

//Funcion:Ser un constructor base para el contrincante
// 
//Parametros: Se toman parametros float para 
// la vida del contrincante, la fuerza de su primer ataque 
// y la fuerza de su segundo ataque
// 
//Retorno: Al ser un constructor no regresa ningún valor,
//solo se da el valor de la vida, y fuerzas de ataques
Contrincante::Contrincante(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2) {
    vidaCont = vidaEnem;
    fuerzaCont1 = fuerzaEnem1;
    fuerzaCont2 = fuerzaEnem2;
}

//Funcion:Ser un constructor base para el contrincante, se hace
// sobrecarga al tener más parametros
// 
//Parametros: Se toman parametros float para 
// la vida del contrincante, la fuerza de su primer ataque 
// ,la fuerza de su segundo ataque y la fuerza de su tercer ataque
// 
//Retorno: Al ser un constructor no regresa ningún valor,
//solo se da el valor de la vida, y fuerzas de ataques
Contrincante::Contrincante(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2, float fuerzaEnem3) {
    vidaCont = vidaEnem;
    fuerzaCont1 = fuerzaEnem1;
    fuerzaCont2 = fuerzaEnem2;
    fuerzaCont3 = fuerzaEnem3;
}

//Funcion:Ser un constructor base para el contrincante, se hace
// sobrecarga al tener más parametros
//Parametros: Se toman parametros float para 
// la vida del contrincante, la fuerza de su primer ataque 
// ,la fuerza de su segundo ataque, la fuerza de su tercer ataque 
// y fuerza de su cuarto ataque
//Retorno: Al ser un constructor no regresa ningún valor,
//solo se da el valor de la vida, y fuerzas de ataques
Contrincante::Contrincante(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2, float fuerzaEnem3, float fuerzaEnem4) {
    vidaCont = vidaEnem;
    fuerzaCont1 = fuerzaEnem1;
    fuerzaCont2 = fuerzaEnem2;
    fuerzaCont3 = fuerzaEnem3;
    fuerzaCont4 = fuerzaEnem4;
}

#endif
