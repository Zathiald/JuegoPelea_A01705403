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
#include "contrincante.h"//Importo el archivo de contrincante para
//poder hacer referencia a la clase jugador
//y tener así agregación y comunicación entre clases

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
	void atacarContrincante1(float fuerzaJug, float fuerzaCont, Jugador* jugador, Contrincante* contrincante);
	void atacarContrincante2(float fuerzaJug, float fuerzaCont,Jugador* jugador,Contrincante* contrincante);
	void atacarContrincante3(float fuerzaJug, float fuerzaCont, Jugador* jugador,Contrincante* contrincante);
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

//Funcion:Generar situaciones en donde se altere tanto la vida del jugador como la del contrincante 
//Parametros: Se toman parametros de float de vida del jugador, vida del contrincante, fuerza del jugador y fuerza del contrincante
//Retorno: Al ser una función void no se regresa algo en sí,en este caso se actualizan los valores de vida de tanto el jugador como del contrincante
void Jugador::atacarContrincante1(float fuerzaJug, float fuerzaCont, Jugador* jugador, Contrincante* contrincante){
	int contrincanteAtaque, jugadorChance;
	float vidaCont,vidaJug;
	contrincanteAtaque = rand() % 2;
	jugadorChance = rand() % 3;
	if (contrincanteAtaque == 0) {
		if (jugadorChance == 2 || jugadorChance == 3) {
			cout << "TU ATAQUE HA FALLADO...pero Bowser tampoco logro hacer nada" << endl;
		}
		else if (jugadorChance == 0 || jugadorChance == 1) {
			vidaCont= contrincante->getvidaCont() - fuerzaJug;
			contrincante->setvidaCont(vidaCont);
			cout << "HAS LOGRADO ATACAR!!!, la vida de Bowser ahora es: " << contrincante->getvidaCont() << endl;
		}
	}
	else if (contrincanteAtaque == 1) {
		if (jugadorChance == 2 || jugadorChance == 3) {
			vidaJug=jugador->getvidaJug() - fuerzaCont;
			jugador->setvidaJug(vidaJug);
			cout << "TU ATAQUE HA FALLADO y peor aun BOWSER SI TE ATACO, tu vida ahora es: " << jugador->getvidaJug() << endl;
		}
		else if (jugadorChance == 0 || jugadorChance == 1) {
			vidaJug = jugador->getvidaJug() - (fuerzaCont/2);
			jugador->setvidaJug(vidaJug);
			vidaCont = contrincante->getvidaCont() - (fuerzaJug/2);
			contrincante->setvidaCont(vidaCont);
			cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador->getvidaJug() << endl;
			cout << "La vida de Bowser ahora es: " << contrincante->getvidaCont() << endl;
		}
	}
	else if (contrincanteAtaque == 2) {
		if (jugadorChance == 2 || jugadorChance == 3) {
			cout << "TU ATAQUE HA FALLADO, pero Bowser se estaba defendiendo así que no paso nada al final " << endl;
		}
		else if (jugadorChance == 0 || jugadorChance == 1) {
			cout << "HAS LOGRADO ATACAR!!, pero Bowser se defendio, nada cambio" << endl;
		}
	}
}

void Jugador::atacarContrincante2(float fuerzaJug, float fuerzaCont, Jugador* jugador, Contrincante* contrincante) {
	int contrincanteAtaque, jugadorChance;
	float vidaCont, vidaJug;
	contrincanteAtaque = rand() % 2;
	jugadorChance = rand() % 3;
	if (contrincanteAtaque == 0) {
		if (jugadorChance == 2 || jugadorChance == 3) {
			cout << "TU ATAQUE HA FALLADO...pero Ganondorf tampoco logro hacer nada" << endl;
		}
		else if (jugadorChance == 0 || jugadorChance == 1) {
			vidaCont = contrincante->getvidaCont() - fuerzaJug;
			contrincante->setvidaCont(vidaCont);
			cout << "HAS LOGRADO ATACAR!!!, la vida de Ganondorf ahora es: " << contrincante->getvidaCont() << endl;
		}
	}
	else if (contrincanteAtaque == 1) {
		if (jugadorChance == 2 || jugadorChance == 3) {
			vidaJug = jugador->getvidaJug() - fuerzaCont;
			jugador->setvidaJug(vidaJug);
			cout << "TU ATAQUE HA FALLADO y peor aun GANONDORF SI TE ATACO, tu vida ahora es: " << jugador->getvidaJug() << endl;
		}
		else if (jugadorChance == 0 || jugadorChance == 1) {
			vidaJug = jugador->getvidaJug() - (fuerzaCont / 2);
			jugador->setvidaJug(vidaJug);
			vidaCont = contrincante->getvidaCont() - (fuerzaJug / 2);
			contrincante->setvidaCont(vidaCont);
			cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador->getvidaJug() << endl;
			cout << "La vida de Ganondorf ahora es: " << contrincante->getvidaCont() << endl;
		}
	}
	else if (contrincanteAtaque == 2) {
		if (jugadorChance == 2 || jugadorChance == 3) {
			cout << "TU ATAQUE HA FALLADO, pero Ganondorf se estaba defendiendo así que no paso nada al final " << endl;
		}
		else if (jugadorChance == 0 || jugadorChance == 1) {
			cout << "HAS LOGRADO ATACAR!!, pero Ganondorf se defendio, nada cambio" << endl;
		}
	}
}

void Jugador::atacarContrincante3(float fuerzaJug, float fuerzaCont, Jugador* jugador, Contrincante* contrincante) {
	int contrincanteAtaque, jugadorChance;
	float vidaCont,vidaJug;
	contrincanteAtaque = rand() % 2;
	jugadorChance = rand() % 3;
	if (contrincanteAtaque == 0) {
		if (jugadorChance == 2 || jugadorChance == 3) {
			cout << "TU ATAQUE HA FALLADO...pero Sephiroth tampoco logro hacer nada" << endl;
		}
		else if (jugadorChance == 0 || jugadorChance == 1) {
			vidaCont = contrincante->getvidaCont() - fuerzaJug;
			contrincante->setvidaCont(vidaCont);
			cout << "HAS LOGRADO ATACAR!!!, la vida de Sephiroth ahora es: " << contrincante->getvidaCont() << endl;
		}
	}
	else if (contrincanteAtaque == 1) {
		if (jugadorChance == 2 || jugadorChance == 3) {
			vidaJug = jugador->getvidaJug() - fuerzaCont;
			jugador->setvidaJug(vidaJug);
			cout << "TU ATAQUE HA FALLADO y peor aun SEPHIROTH SI TE ATACO, tu vida ahora es: " << jugador->getvidaJug() << endl;
		}
		else if (jugadorChance == 0 || jugadorChance == 1) {
			vidaJug = jugador->getvidaJug() - (fuerzaCont / 2);
			jugador->setvidaJug(vidaJug);
			vidaCont = contrincante->getvidaCont() - (fuerzaJug / 2);
			contrincante->setvidaCont(vidaCont);
			cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador->getvidaJug() << endl;
			cout << "La vida de Sephiroth ahora es: " << contrincante->getvidaCont() << endl;
		}
	}
	else if (contrincanteAtaque == 2) {
		if (jugadorChance == 2 || jugadorChance == 3) {
			cout << "TU ATAQUE HA FALLADO, pero Sephiroth se estaba defendiendo así que no paso nada al final " << endl;
		}
		else if (jugadorChance == 0 || jugadorChance == 1) {
			cout << "HAS LOGRADO ATACAR!!, pero Sephiroth se defendio, nada cambio" << endl;
		}
	}
}
#endif