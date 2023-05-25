#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Jugador {
	private:
		string nombreJug;
		string nombreAtaque1;
		string nombreAtaque2;
		float vidaJug;
		float fuerzaAtaque1;
		float fuerzaAtaque2;
		int nivelJug;
	public:
		float getvidaJug() { return vidaJug; }
		float getfuerzaAtaque1() { return fuerzaAtaque1; }
		float getfuerzaAtaque2() { return fuerzaAtaque2; }
		int getnivelJug() { return nivelJug; }
		string getnombreJug() { return nombreJug; }
		string getnombreAtaque1() { return nombreAtaque1; }
		string getnombreAtaque2() { return nombreAtaque2; }
		void setnivelJug(int nivel_Jug);
		void setvidaJug(float vida_Jug);
		void setfuerzaAtaque1(float fuerza_Ataque1);
		void setfuerzaAtaque2(float fuerza_Ataque2);
		void setnombreJug(string nombre_Jug);
		void setnombreAtaque1(string nombre_Ataque1);
		void setnombreAtaque2(string nombre_Ataque2);
		void atacarContrincante(float vidaCont, float vidaJug, float fuerzaCont, float fuerzaJug);
};

void Jugador::setnivelJug(int nivel_Jug) {
	nivelJug = nivel_Jug;
}

void Jugador::setvidaJug(float vida_Jug) {
	vidaJug = vida_Jug;
}

void Jugador::setfuerzaAtaque1(float fuerza_Ataque1) {
	fuerzaAtaque1 = fuerza_Ataque1;
}

void Jugador::setfuerzaAtaque2(float fuerza_Ataque2) {
	fuerzaAtaque2 = fuerza_Ataque2;
}

void Jugador::setnombreJug(string nombre_Jug) {
	nombreJug = nombre_Jug;
}

void Jugador::setnombreAtaque1(string nombre_Ataque1) {
	nombreAtaque1 = nombre_Ataque1;
}

void Jugador::setnombreAtaque2(string nombre_Ataque2) {
	nombreAtaque2 = nombre_Ataque2;
}

void Jugador::atacarContrincante(float vidaCont, float vidaJug, float fuerzaCont, float fuerzaJug) {
	int contrincanteAtaque, jugadorChance;
	contrincanteAtaque = rand() % 2;
	jugadorChance = rand() % 1;
	if (contrincanteAtaque == 0) {
		if (jugadorChance == 0) {
			cout << "TU ATAQUE HA FALLADO...pero el enemigo tampoco logro hacer nada" << endl;
		}
		if (jugadorChance == 1) {
			vidaCont = vidaCont - fuerzaJug;
			cout << "HAS LOGRADO ATACAR!!!, la vida del enemigo ahora es: " << vidaCont<< endl;
		}
	}
	if (contrincanteAtaque == 1) {
		if (jugadorChance == 0) {
			vidaJug = vidaJug - fuerzaCont;
			cout << "TU ATAQUE HA FALLADO y peor aun EL ENEMIGO SI TE ATACO, tu vida ahora es: " << vidaJug << endl;
		}
		if (jugadorChance == 1) {
			vidaJug = vidaJug - (fuerzaCont / 2);
			vidaCont = vidaCont - (fuerzaJug / 2);
			cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << vidaJug << endl;
			cout << "La vida del enemigo es: " << vidaCont << endl;
		}
	}
	if (contrincanteAtaque == 2) {
		if (jugadorChance == 0) {
			cout << "TU ATAQUE HA FALLADO, pero el enemigo se estaba defendiendo así que no paso nada al final "<< endl;
		}
		if (jugadorChance == 1) {
			cout << "HAS LOGRADO ATACAR!!, pero el enemigo se defendio, nada cambio" << endl;
		}
	}
}

#endif

