#ifndef BOWSER_H
#define BOWSER_H

#include <iostream>
#include <cstdlib>
#include "contrincante.h"

class Bowser : public Contrincante {
public:
	void atacarJugador(string decision, int aJ, Jugador jugador, Contrincante* bowser);
	Bowser() {}
	Bowser(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2) :Contrincante(vidaEnem, fuerzaEnem1, fuerzaEnem2) {}
};

void Bowser::atacarJugador(string decision, int aJ, Jugador jugador,Contrincante* bowser) {
	float vidaJug;
	int turnoContrincante, defensaChance, contrincanteAtaque, ataqueChance;
	turnoContrincante = rand() % 2;
	defensaChance = rand() % 3;
	contrincanteAtaque = rand() % 1;
	ataqueChance = rand() % 3;
	if (decision == "D") {
		if (defensaChance == 0 || defensaChance == 1 || defensaChance == 2)
		{
			if (turnoContrincante == 0) {
				cout << "EL ATAQUE DE BOWSER HA FALLADO!!, pero " << jugador.getnombreJug() << "solo se estaba defendiendo, SIGUE LA PELEA!!!" << endl;
			}
			else if (turnoContrincante == 1) {
				cout << "INCREIBLE DEFENSA CONTRA BOWSER por parte de " << jugador.getnombreJug() << endl;
			}
			else if (turnoContrincante == 2) {
				cout << "...No pues, ambos se defendieron,bueno PELIEN" << endl;
			}
		}
		else if (defensaChance == 3) {
			if (turnoContrincante == 0) {
				cout << "EL ATAQUE DE BOWSER HA FALLADO!!, pero  la defensa de " << jugador.getnombreJug() << "tambien habia fallado, SIGUE LA PELEA!!!" << endl;
			}
			else if (turnoContrincante == 1) {
				if (contrincanteAtaque == 0) {
					vidaJug = jugador.getvidaJug() - fuerzaCont1;
					jugador.setvidaJug(vidaJug);
					cout << "BOWSER HA UTILIZADO SU BOLA DE FUEGO, ha pegado con exito, el Rey de los Koopas viene con fuerza" << endl;
					cout << "La vida de " << jugador.getnombreJug() << " ha bajado, ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					vidaJug = jugador.getvidaJug() - fuerzaCont2;
					jugador.setvidaJug(vidaJug);
					cout << "BOWSER HA ATACADO CON SU COLA, ha pegado con exito, el Rey de los Koopas viene con fuerza" << endl;
					cout << "La vida de " << jugador.getnombreJug() << " ha bajado, ahora es " << vidaJug << endl;
				}
			}
			else if (turnoContrincante == 2) {
				cout << "La defensa de" << jugador.getnombreJug() << "fallo, pero el enemigo andaba defendiendo...bueno PELIEN" << endl;
			}
		}
	}
	else if (decision == "A") {
		if (ataqueChance == 0 || ataqueChance == 1 || ataqueChance == 2) {
			if (turnoContrincante == 0) {
				if (aJ == 1) {
					vidaCont = bowser->getvidaCont() - jugador.getfuerzaAtaque1();
					bowser->setvidaCont(vidaCont);
					cout << jugador.getnombreJug() << " HA REMATADO EL ATAQUE DE BOWSER CON " << jugador.getnombreAtaque1() << " Bowser se ve muy furioso"<<endl;
					cout << "La vida de Bowser ahora es: " << vidaCont << endl;
				}
				else if (aJ == 2) {
					vidaCont = bowser->getvidaCont() - jugador.getfuerzaAtaque2();
					bowser->setvidaCont(vidaCont);
					cout << jugador.getnombreJug() << " HA REMATADO EL ATAQUE DE BOWSER CON " << jugador.getnombreAtaque2() << " Bowser se ve muy furioso"<<endl;
					cout << "La vida de Bowser ahora es: " << vidaCont << endl;
				}
			}
			else if (turnoContrincante == 1) {
				if (contrincanteAtaque == 0) {
					if (aJ == 1) {
						vidaJug = jugador.getvidaJug() - (fuerzaCont1 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = bowser->getvidaCont() - (jugador.getfuerzaAtaque1() / 2);
						bowser->setvidaCont(vidaCont);
						cout << jugador.getnombreJug() << " HA REMATADO EL ATAQUE DE BOWSER CON " << jugador.getnombreAtaque1() << endl;
						cout << "Pero Bowser no se queda abajo y ataca de vuelta con UNA BOLA DE FUEGOOO, gruñe al lanzar el ataque" << endl;
						cout << "La vida de Bowser ahora es: " << vidaCont << endl;
						cout << "La vida de " << jugador.getnombreJug() << " ahora es: " << jugador.getvidaJug() << endl;
					}
					else if (aJ == 2) {
						vidaJug = jugador.getvidaJug() - (fuerzaCont1 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = bowser->getvidaCont() - (jugador.getfuerzaAtaque2() / 2);
						bowser->setvidaCont(vidaCont);
						cout << jugador.getnombreJug() << " HA REMATADO EL ATAQUE DE BOWSER CON " << jugador.getnombreAtaque2() << endl;
						cout << "Pero Bowser no se queda abajo y ataca de vuelta con UNA BOLA DE FUEGOOOOO, gruñe al lanzar el ataque" << endl;
						cout << "La vida de Bowser ahora es: " << vidaCont << endl;
						cout << "La vida de " << jugador.getnombreJug() << " ahora es: " << jugador.getvidaJug() << endl;
					}
				}
				else if (contrincanteAtaque == 1) {
					if (aJ == 1) {
						vidaJug = jugador.getvidaJug() - (fuerzaCont2 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = bowser->getvidaCont() - (jugador.getfuerzaAtaque1() / 2);
						bowser->setvidaCont(vidaCont);
						cout << jugador.getnombreJug() << " HA REMATADO EL ATAQUE DE BOWSER CON " << jugador.getnombreAtaque1() << endl;
						cout << "Pero Bowser no se queda abajo y ataca de vuelta con UN ATAQUE DE COLAAAA, gruñe al lanzar el ataque" << endl;
						cout << "La vida de Bowser ahora es: " << vidaCont << endl;
						cout << "La vida de " << jugador.getnombreJug() << " ahora es: " << jugador.getvidaJug() << endl;
					}
					else if (aJ == 2) {
						vidaJug = jugador.getvidaJug() - (fuerzaCont2 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = bowser->getvidaCont() - (jugador.getfuerzaAtaque2() / 2);
						bowser->setvidaCont(vidaCont);
						cout << jugador.getnombreJug() << " HA REMATADO EL ATAQUE DE BOWSER CON " << jugador.getnombreAtaque2() << endl;
						cout << "Pero Bowser no se queda abajo y ataca de vuelta con UN ATAQUE DE COLAAAA, gruñe al lanzar el ataque" << endl;
						cout << "La vida de Bowser ahora es: " << vidaCont << endl;
						cout << "La vida de " << jugador.getnombreJug() << " ahora es: " << jugador.getvidaJug() << endl;
					}
				}
			}
			else if (turnoContrincante == 2) {
				cout << jugador.getnombreJug() << "HA ATACADOOO, pero Bowser se ha defendido con exito, Bowser se rie en su cara" << endl;
			}
		}

		else if (ataqueChance == 3) {
			if (turnoContrincante == 0) {
				cout << "LOS ATAQUES DE BOWSER y " << jugador.getnombreJug() << " HAN FALLADO SIMULTANEAMENTE!!" << endl;
			}
			else if (turnoContrincante == 1) {
				if (contrincanteAtaque == 0) {
					vidaJug = jugador.getvidaJug() - fuerzaCont1;
					jugador.setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << jugador.getnombreJug() << " HA FALLADO " << endl;
					cout << "Bowser se rie y ha utilizado una bola de fuego contra " << jugador.getnombreJug() << endl;
					cout << "La vida de" << jugador.getnombreJug() << " ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					vidaJug = jugador.getvidaJug() - fuerzaCont2;
					jugador.setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << jugador.getnombreJug() << " HA FALLADO " << endl;
					cout << "Bowser se rie y ha atacado con su cola contra " << jugador.getnombreJug() << endl;
					cout << "La vida de" << jugador.getnombreJug() << " ahora es " << jugador.getvidaJug() << endl;
				}
			}
			else if (turnoContrincante == 2) {
				cout << "EL ATAQUE DE " << jugador.getnombreJug() << " HA FALLADO, pero Bowser solo se estaba defendiendo" << endl;
				cout << "Bowser se parte de risa al ver que " << jugador.getnombreJug() << "no ha logrado atacarlo" << endl;
			}
		}
	}
}
#endif