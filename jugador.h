/*
 *
 * Proyecto Juego de Peleas
 * Samir Baidon Pardo
 * A01705403
 * 20/05/2023
 * versio : 4
 * Esta clase define la clase de Jugador, tiene los setters y 
 * getter necesarios para que dentro del main el jugador cree 
 * a su propio personaje, también se tienen las funciones para
 * que según el round se muestren diferentes textos para coordinar
 * con el enemigo de ese round
 */

#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Jugador {

//Declaro todos los atributos privados que tendra la clase
private:
	string nombreJug;
	string nombreAtaque1;
	string nombreAtaque2;
	float vidaJug;
	float fuerzaAtaque1;
	float fuerzaAtaque2;
	int nivelJug;

//Declaro los metodos publicos que tendra la clase
public:

	//Getters
	float getvidaJug() { return vidaJug; }
	float getfuerzaAtaque1() { return fuerzaAtaque1; }
	float getfuerzaAtaque2() { return fuerzaAtaque2; }
	int getnivelJug() { return nivelJug; }
	string getnombreJug() { return nombreJug; }
	string getnombreAtaque1() { return nombreAtaque1; }
	string getnombreAtaque2() { return nombreAtaque2; }

	//Setters
	void setnivelJug(int nivelJugador);
	void setvidaJug(float vidaJugador);
	void setfuerzaAtaque1(float fuerzaJugador1);
	void setfuerzaAtaque2(float fuerzaJugador2);
	void setnombreJug(string nombreJugador);
	void setnombreAtaque1(string nombreFuerza1);
	void setnombreAtaque2(string nombreFuerza2);

	Jugador() {}
	Jugador(float vJ, float fA1, float fA2);
};

//Funcion:Darle nuevo valor a la variable de nivel del jugador
//Parametros: Se toma un parametro int para darle ese valor a la variable de nivel del jugador
//Retorno: Al ser una función void no se regresa algo en sí,solo se actualiza el valor de la variable de nivel del jugador
void Jugador::setnivelJug(int nivelJugador) {
	nivelJug = nivelJugador;
}

//Funcion:Darle nuevo valor a la variable de la vida del jugador
//Parametros: Se toma un parametro float para darle ese valor a la variable de vida del jugador
//Retorno: Al ser una función void no se regresa algo en sí,solo se actualiza el valor de la variable de vida del jugador
void Jugador::setvidaJug(float vidaJugador) {
	vidaJug = vidaJugador;
}

//Funcion:Darle nuevo valor a la variable de fuerza del primer ataque del jugador
//Parametros: Se toma un parametro float para darle ese valor a la variable de fuerza del primer ataque del jugador
//Retorno: Al ser una función void no se regresa algo en sí,solo se actualiza el valor de la variable de fuerza del primer ataque del jugador
void Jugador::setfuerzaAtaque1(float fuerzaJugador1) {
	fuerzaAtaque1 = fuerzaJugador1;
}

//Funcion:Darle nuevo valor a la variable de fuerza del segundo ataque del jugador
//Parametros: Se toma un parametro float para darle ese valor a la variable de fuerza del segundo ataque del jugador
//Retorno: Al ser una función void no se regresa algo en sí,solo se actualiza el valor de la variable de fuerza del segundo ataque del jugador
void Jugador::setfuerzaAtaque2(float fuerzaJugador2) {
	fuerzaAtaque2 = fuerzaJugador2;
}

//Funcion:Darle nuevo valor a la variable del nombre del jugador
//Parametros: Se toma un parametro string para darle ese valor a la variable de nombre del jugador
//Retorno: Al ser una función void no se regresa algo en sí,solo se actualiza el valor de la variable de nombre del jugador
void Jugador::setnombreJug(string nombreJugador) {
	nombreJug = nombreJugador;
}

//Funcion:Darle nuevo valor a la variable del nombre del primer ataque del jugador
//Parametros: Se toma un parametro string para darle ese valor a la variable del nombre del primer ataque del jugador
//Retorno: Al ser una función void no se regresa algo en sí,solo se actualiza el valor de la variable del nombre del primer ataque del jugador
void Jugador::setnombreAtaque1(string nombreFuerza1) {
	nombreAtaque1 = nombreFuerza1;
}

//Funcion:Darle nuevo valor a la variable del nombre del segundo ataque del jugador
//Parametros: Se toma un parametro string para darle ese valor a la variable del nombre del segundo ataque del jugador
//Retorno: Al ser una función void no se regresa algo en sí,solo se actualiza el valor de la variable del nombre del segundo ataque del jugador
void Jugador::setnombreAtaque2(string nombreFuerza2) {
	nombreAtaque2 = nombreFuerza2;
}

Jugador::Jugador(float vJ, float fA1, float fA2) {
	vidaJug = vJ;
	fuerzaAtaque1 = fA1;
	fuerzaAtaque2 = fA2;
}
#endif