//Creación de la clase de Contrincante,Bowser,Ganondorf y Sephiroth usado para almacenar todos los datos relacionados a estas clases
//Creación: 20/05/23

#ifndef CONTRINCANTE_H
#define CONTRINCANTE_H

#include <iostream>
#include <cstdlib>
#include "jugador.h"

using namespace std;

class Contrincante {

public:
	float vidaCont;
	float fuerzaCont1;
	float fuerzaCont2;
	float fuerzaCont3;
	float fuerzaCont4;
	Jugador jugador;
	virtual void atacarJugador(string decision, int aJ);
	Contrincante(){}
	Contrincante(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2);
	Contrincante(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2, float fuerzaEnem3);
	Contrincante(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2,float fuerzaEnem3,float fuerzaEnem4);
};

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

void Contrincante::atacarJugador(string decision, int aJ) {
	int turnoContrincante, defensaChance, contrincanteAtaque, ataqueChance;
	turnoContrincante = rand() % 2;
	defensaChance = rand() % 3;
	contrincanteAtaque = rand() % 1;
	ataqueChance = rand() % 3;
	if (decision == "D") {
		if (defensaChance == 0 || defensaChance==1 || defensaChance==2) 
		{
			if (turnoContrincante == 0) {
				cout << "El ataque del contrincante ha fallado mientras defendiste, no sucedio nada" << endl;
			}
			else if (turnoContrincante == 1) {
				cout << "Te has defendido perfectamente contra el enemigo" << endl;
			}
			else if (turnoContrincante == 2) {
				cout << "...No pues, ambos se defendieron,bueno PELIEN" << endl;
			}
		}
		else if (defensaChance == 3) {
			if (turnoContrincante == 0) {
				cout << "El ataque del contrincante ha fallado pero tu defensa también habia fallado, no sucedio nada" << endl;
			}
			else if (turnoContrincante == 1) {
				float vidaJug;
				if (contrincanteAtaque == 0) {
					vidaJug = jugador.getvidaJug() - fuerzaCont1;
					jugador.setvidaJug(vidaJug);
					cout << "El enemigo ha atacado con exito, tu vida ahora es: " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					vidaJug = jugador.getvidaJug() - fuerzaCont2;
					jugador.setvidaJug(vidaJug);
					cout << "El enemigo ha atacado con exito, tu vida ahora es: " << jugador.getvidaJug() << endl;
				}
			}
			else if (turnoContrincante == 2) {
				cout << "...Tu defensa fallo, pero el enemigo andaba defendiendo...bueno PELIEN" << endl;
			}
		}
	}
	if (decision == "A") {
		if (ataqueChance == 0 || ataqueChance == 1 || ataqueChance == 2) {
			if (turnoContrincante == 0) {
				if (aJ == 1) {
					vidaCont = vidaCont - jugador.getfuerzaAtaque1();
					cout << "HAS ATACADO!!!, lograste quitarle vida al contrincante, su vida ahora es: " << vidaCont << endl;
				}
				if (aJ == 2) {
					vidaCont = vidaCont - jugador.getfuerzaAtaque2();
					cout << "HAS ATACADO!!!, lograste quitarle vida al contrincante, su vida ahora es: " << vidaCont << endl;
				}
			}
			else if (turnoContrincante == 1) {
				if (contrincanteAtaque == 0) {
					if (aJ == 1) {
						float vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerzaCont1 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
					if (aJ == 2) {
						float vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerzaCont1 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
				}
				else if (contrincanteAtaque == 1) {
					if (aJ == 1) {
						float vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerzaCont2 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
					if (aJ == 2) {
						float vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerzaCont2 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
				}
			}	
			else if (turnoContrincante == 2) {
				cout << "HAS ATACADO!!!, pero el enemigo logro defenderse, ni modo toca pelear" << endl;
			}
		}

		else if (ataqueChance == 3) {
			if (turnoContrincante == 0) {
				cout << "TU ATAQUE HA FALLADO, pero tambien lo ha hecho el ataque del contrincante" << endl;
			}
			else if (turnoContrincante == 1) {
				if (contrincanteAtaque == 0) {
					float vidaJug;
					vidaJug = jugador.getvidaJug() -fuerzaCont1;
					jugador.setvidaJug(vidaJug);
					cout << "TU ATAQUE HA FALLADO y ahora el contrincante te ataco" << endl;
					cout << "Tu vida ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					float vidaJug;
					vidaJug = jugador.getvidaJug() - fuerzaCont2;
					jugador.setvidaJug(vidaJug);
					cout << "TU ATAQUE HA FALLADO y ahora el contrincante te ataco" << endl;
					cout << "Tu vida ahora es " << jugador.getvidaJug() << endl;
				}
			}
			else if (turnoContrincante == 2) {
				cout << "TU ATAQUE FALLO!!!, pero el enemigo solo se estaba defendiendo" << endl;
			}
		}
	}
}
#endif