#ifndef SEPHIROTH_H
#define SEPHIROTH_H

#include <iostream>
#include <cstdlib>
#include "contrincante.h"

class Sephiroth : public Contrincante {

private:
	float vidaSephiroth = 60.0;
	float fuerzaMasamune = 15.0;
	float fuerzaShadow = 13.0;
	float fuerzaOctaslash = 22.0;
	float fuerzaNova = 40.0;

public:
	float getvidaSephiroth() { return vidaSephiroth; }
	float getfuerzaMasamune() { return fuerzaMasamune; }
	float getfuerzaShadow() { return fuerzaShadow; }
	float getfuerzaOctaslash() { return fuerzaOctaslash; }
	float getfuerzaNova() { return fuerzaNova; }
	void atacarJugador(string decision, int aJ);
	Sephiroth(){}
	Sephiroth(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2, float fuerzaEnem3, float fuerzaEnem4) :Contrincante(vidaEnem, fuerzaEnem1, fuerzaEnem2, fuerzaEnem3, fuerzaEnem4) {}
};

void Sephiroth::atacarJugador(string decision, int aJ) {
	string nombreJug;
	nombreJug = jugador.getnombreJug();
	int turnoContrincante, defensaChance, contrincanteAtaque, ataqueChance;
	turnoContrincante = rand() % 2;
	defensaChance = rand() % 3;
	contrincanteAtaque = rand() % 3;
	ataqueChance = rand() % 3;
	if (decision == "D") {
		if (defensaChance == 0 || defensaChance == 1 || defensaChance == 2)
		{
			if (turnoContrincante == 0) {
				cout << "El ataque de Sephiroth ha fallado, el solo ríe, ya que " << nombreJug << " solo se estaba defendiendo" << endl;
			}
			else if (turnoContrincante == 1) {
				cout << nombreJug << " SE HA DEFENDIDO CONTRA SEPHIROTH" << endl;
				cout << "Pero Sephiroth solo sonríe, el ángel de un ala ya se lo esperaba" << endl;
			}
			else if (turnoContrincante == 2) {
				cout << "...No pues, ambos se defendieron,bueno PELIEN" << endl;
				cout << "Parece ser Sephiroth hace una sonrisa, pensando el ya gano" << endl;
			}
		}
		else if (defensaChance == 3) {
			if (turnoContrincante == 0) {
				cout << "WOW,tanto Sephiroth como " << nombreJug << " han fallado sus ataques, no ha sucedido nada" << endl;
			}
			else if (turnoContrincante == 1) {
				float vidaJug;
				if (contrincanteAtaque == 0) {
					vidaJug = jugador.getvidaJug() - fuerzaCont1;
					jugador.setvidaJug(vidaJug);
					cout << "Sephiroth ha usado su mitica Masamune con exito, sonrie al ver a " << nombreJug << " caer" << endl;
					cout << "La vida de" << nombreJug << " ahora es : " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					vidaJug = jugador.getvidaJug() - fuerzaCont2;
					jugador.setvidaJug(vidaJug);
					cout << "Sephiroth ha usado Shadow Flare con exito, sonrie al ver a " << nombreJug << " caer" << endl;
					cout << "La vida de" << nombreJug << " ahora es : " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 2) {
					vidaJug = jugador.getvidaJug() - fuerzaCont3;
					jugador.setvidaJug(vidaJug);
					cout << "Sephiroth ha usado Octaslash con exito, sonrie al ver a " << nombreJug << " caer" << endl;
					cout << "La vida de" << nombreJug << " ahora es : " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 3) {
					vidaJug = jugador.getvidaJug() - fuerzaCont4;
					jugador.setvidaJug(vidaJug);
					cout << "Sephiroth ha usado Super Nova con exito, sonrie al ver a " << nombreJug << " caer" << endl;
					cout << "La vida de" << nombreJug << " ahora es : " << jugador.getvidaJug() << endl;
				}
			}
			else if (turnoContrincante == 2) {
				cout << "La defensa de " << nombreJug << " ha fallado" << endl;
				cout << "Sephiroth solo se queda defendiendo, llama a " << nombreJug << " patetico" << endl;
			}
		}
	}
	if (decision == "A") {
		if (ataqueChance == 0 || ataqueChance == 1 || ataqueChance == 2) {
			if (turnoContrincante == 0) {
				if (aJ == 1) {
					vidaCont = vidaCont - jugador.getfuerzaAtaque1();
					cout << "NO ME LO CREO " << nombreJug << " HA ATACADO A SEPHIROTH CON " << jugador.getnombreAtaque1() << endl;
					cout << "Pero parece ser Sephiroth solo sonrie al haber recibido el ataque" << endl;
					cout << "La vida de Sephiroth ahora es: " << vidaCont << endl;
				}
				if (aJ == 2) {
					vidaCont = vidaCont - jugador.getfuerzaAtaque2();
					cout << "NO ME LO CREO " << nombreJug << " HA ATACADO A SEPHIROTH CON " << jugador.getnombreAtaque2() << endl;
					cout << "Pero parece ser Sephiroth solo sonrie al haber recibido el ataque" << endl;
					cout << "La vida de Sephiroth ahora es: " << vidaCont << endl;
				}
			}
			else if (turnoContrincante == 1) {
				if (contrincanteAtaque == 0) {
					if (aJ == 1) {
						float vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerzaCont1 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "NO ME LO CREO " << nombreJug << " HA ATACADO A SEPHIROTH CON " << jugador.getnombreAtaque1() << endl;
						cout << "Pero Sephiroth no se queda atras y remata con su Masamune, parece ser Sephiroth disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;

					}
					if (aJ == 2) {
						float vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerzaCont1 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << "NO ME LO CREO " << nombreJug << " HA ATACADO A SEPHIROTH CON " << jugador.getnombreAtaque2() << endl;
						cout << "Pero Sephiroth no se queda atras y remata con su Masamune, parece ser Sephiroth disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
				}
				else if (contrincanteAtaque == 1) {
					if (aJ == 1) {
						float vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerzaCont2 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "NO ME LO CREO " << nombreJug << " HA ATACADO A SEPHIROTH CON " << jugador.getnombreAtaque1() << endl;
						cout << "Pero Sephiroth no se queda atras y remata con Shadow Flare, parece ser Sephiroth disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
					if (aJ == 2) {
						float vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerzaCont2 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << "NO ME LO CREO " << nombreJug << " HA ATACADO A SEPHIROTH CON " << jugador.getnombreAtaque2() << endl;
						cout << "Pero Sephiroth no se queda atras y remata con Shadow Flare, parece ser Sephiroth disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
				}
				else if (contrincanteAtaque == 2) {
					if (aJ == 1) {
						float vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerzaCont3 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "NO ME LO CREO " << nombreJug << " HA ATACADO A SEPHIROTH CON " << jugador.getnombreAtaque1() << endl;
						cout << "Pero Sephiroth no se queda atras y remata con Octaslash, parece ser Sephiroth disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
					if (aJ == 2) {
						float vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerzaCont3 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << "NO ME LO CREO " << nombreJug << " HA ATACADO A SEPHIROTH CON " << jugador.getnombreAtaque2() << endl;
						cout << "Pero Sephiroth no se queda atras y remata con Octaslash, parece ser Sephiroth disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
				}
				else if (contrincanteAtaque == 3) {
					if (aJ == 1) {
						float vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerzaCont4 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "NO ME LO CREO " << nombreJug << " HA ATACADO A SEPHIROTH CON " << jugador.getnombreAtaque1() << endl;
						cout << "Pero Sephiroth no se queda atras y remata con Super Nova, parece ser Sephiroth disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
					if (aJ == 2) {
						float vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerzaCont4 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << "NO ME LO CREO " << nombreJug << " HA ATACADO A SEPHIROTH CON " << jugador.getnombreAtaque2() << endl;
						cout << "Pero Sephiroth no se queda atras y remata con Super Nova, parece ser Sephiroth disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
				}
			}
			else if (turnoContrincante == 2) {
				cout << nombreJug << " HA ATACADO A SEPHIROTH" << endl;
				cout << "Pero Sephiroth se ha defendido, el dice al fin estar feliz de tener una pelea divertida" << endl;
			}
		}

		else if (ataqueChance == 3) {
			if (turnoContrincante == 0) {
				cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
				cout << "Pero el ataque de Sephiroth también, el angel de una Ala se esta cansando" << endl;
			}
			else if (turnoContrincante == 1) {
				if (contrincanteAtaque == 2) {
					float vidaJug;
					vidaJug = jugador.getvidaJug() - fuerzaCont1;
					jugador.setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
					cout << "Ahora Sephiroth ha rematado con un su Masamune, parece ser que quiere terminar ya esta pelea!!!!" << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					float vidaJug;
					vidaJug = jugador.getvidaJug() - fuerzaCont2;
					jugador.setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
					cout << "Ahora Sephiroth ha rematado con Shadow Flare, parece ser que quiere terminar ya esta pelea!!!!" << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 2) {
					float vidaJug;
					vidaJug = jugador.getvidaJug() - fuerzaCont3;
					jugador.setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
					cout << "Ahora Sephiroth ha rematado con Octaslash, parece ser que quiere terminar ya esta pelea!!!!" << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 3) {
					float vidaJug;
					vidaJug = jugador.getvidaJug() - fuerzaCont4 ;
					jugador.setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
					cout << "Ahora Sephiroth ha rematado con una Super Nova, parece ser que quiere terminar ya esta pelea!!!!" << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
			}
			else if (turnoContrincante == 2) {
				cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
				cout << "Pero Sephiroth solo bloqueaba, el angel de un ala llama patetico a " << nombreJug << endl;
			}
		}
	}
}
#endif 

