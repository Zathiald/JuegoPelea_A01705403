#ifndef CONTRINCANTE_H
#define CONTRINCANTE_H

#include <iostream>
#include <cstdlib>
#include "jugador.h"

using namespace std;

class Contrincante {
private:
	Jugador jugador;
public:
	void atacarJugador(string decision, int aJ, float fuerza1Cont, float fuerza2Cont, float vidaCont, Jugador jugador);
	void atacarJugador(string decision, int aJ, float fuerza1Cont, float fuerza2Cont, float fuerza3Cont, float vidaCont, Jugador jugador);
	void atacarJugador(string decision, int aJ, float fuerza1Cont, float fuerza2Cont, float fuerza3Cont, float fuerza4Cont, float vidaCont, Jugador jugador);
};

void Contrincante::atacarJugador(string decision, int aJ, float fuerza1Cont, float fuerza2Cont, float vidaCont, Jugador jugador) {
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
				int vidaJug;
				if (contrincanteAtaque == 0) {
					vidaJug = jugador.getvidaJug() - fuerza1Cont;
					jugador.setvidaJug(vidaJug);
					cout << "El enemigo ha atacado con exito, tu vida ahora es: " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					vidaJug = jugador.getvidaJug() - fuerza2Cont;
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
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza1Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
					if (aJ == 2) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza1Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
				}
				else if (contrincanteAtaque == 1) {
					if (aJ == 1) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza2Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
					if (aJ == 2) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza2Cont / 2);
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
					int vidaJug;
					vidaJug = jugador.getvidaJug() -fuerza1Cont;
					jugador.setvidaJug(vidaJug);
					cout << "TU ATAQUE HA FALLADO y ahora el contrincante te ataco" << endl;
					cout << "Tu vida ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					int vidaJug;
					vidaJug = jugador.getvidaJug() - fuerza2Cont;
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


void Contrincante::atacarJugador(string decision, int aJ, float fuerza1Cont, float fuerza2Cont, float fuerza3Cont,float vidaCont, Jugador jugador) {
	int turnoContrincante, defensaChance, contrincanteAtaque, ataqueChance;
	turnoContrincante = rand() % 2;
	defensaChance = rand() % 3;
	contrincanteAtaque = rand() % 2;
	ataqueChance = rand() % 3;
	if (decision == "D") {
		if (defensaChance == 0 || defensaChance == 1 || defensaChance == 2)
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
				int vidaJug;
				if (contrincanteAtaque == 0) {
					vidaJug = jugador.getvidaJug() - fuerza1Cont;
					jugador.setvidaJug(vidaJug);
					cout << "El enemigo ha atacado con exito, tu vida ahora es: " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					vidaJug = jugador.getvidaJug() - fuerza2Cont;
					jugador.setvidaJug(vidaJug);
					cout << "El enemigo ha atacado con exito, tu vida ahora es: " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 2) {
					vidaJug = jugador.getvidaJug() - fuerza3Cont;
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
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza1Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
					if (aJ == 2) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza1Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
				}
				else if (contrincanteAtaque == 1) {
					if (aJ == 1) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza2Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
					if (aJ == 2) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza2Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
				}
				else if (contrincanteAtaque == 2) {
					if (aJ == 1) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza3Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
					if (aJ == 2) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza3Cont / 2);
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
					int vidaJug;
					vidaJug = jugador.getvidaJug() - fuerza1Cont;
					jugador.setvidaJug(vidaJug);
					cout << "TU ATAQUE HA FALLADO y ahora el contrincante te ataco" << endl;
					cout << "Tu vida ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					int vidaJug;
					vidaJug = jugador.getvidaJug() - fuerza2Cont;
					jugador.setvidaJug(vidaJug);
					cout << "TU ATAQUE HA FALLADO y ahora el contrincante te ataco" << endl;
					cout << "Tu vida ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 2) {
					int vidaJug;
					vidaJug = jugador.getvidaJug() - fuerza3Cont;
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

void Contrincante::atacarJugador(string decision, int aJ, float fuerza1Cont, float fuerza2Cont, float fuerza3Cont, float fuerza4Cont, float vidaCont, Jugador jugador) {
	int turnoContrincante, defensaChance, contrincanteAtaque, ataqueChance;
	turnoContrincante = rand() % 2;
	defensaChance = rand() % 3;
	contrincanteAtaque = rand() % 3;
	ataqueChance = rand() % 3;
	if (decision == "D") {
		if (defensaChance == 0 || defensaChance == 1 || defensaChance == 2)
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
				int vidaJug;
				if (contrincanteAtaque == 0) {
					vidaJug = jugador.getvidaJug() - fuerza1Cont;
					jugador.setvidaJug(vidaJug);
					cout << "El enemigo ha atacado con exito, tu vida ahora es: " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					vidaJug = jugador.getvidaJug() - fuerza2Cont;
					jugador.setvidaJug(vidaJug);
					cout << "El enemigo ha atacado con exito, tu vida ahora es: " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 2) {
					vidaJug = jugador.getvidaJug() - fuerza3Cont;
					jugador.setvidaJug(vidaJug);
					cout << "El enemigo ha atacado con exito, tu vida ahora es: " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 3) {
					vidaJug = jugador.getvidaJug() - fuerza4Cont;
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
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza1Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
					if (aJ == 2) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza1Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
				}
				else if (contrincanteAtaque == 1) {
					if (aJ == 1) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza2Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
					if (aJ == 2) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza2Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
				}
				else if (contrincanteAtaque == 2) {
					if (aJ == 1) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza3Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
					if (aJ == 2) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza3Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
				}
				else if (contrincanteAtaque == 3) {
					if (aJ == 1) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza4Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "HAS ATACADO!!!, pero el contrincante te la remato y ataco de vuelta, tu vida ahora es: " << jugador.getvidaJug() << endl;
						cout << "La vida del contrincante ahora es: " << vidaCont << endl;
					}
					if (aJ == 2) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza4Cont / 2);
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
					int vidaJug;
					vidaJug = jugador.getvidaJug() - fuerza1Cont;
					jugador.setvidaJug(vidaJug);
					cout << "TU ATAQUE HA FALLADO y ahora el contrincante te ataco" << endl;
					cout << "Tu vida ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					int vidaJug;
					vidaJug = jugador.getvidaJug() - fuerza2Cont;
					jugador.setvidaJug(vidaJug);
					cout << "TU ATAQUE HA FALLADO y ahora el contrincante te ataco" << endl;
					cout << "Tu vida ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 2) {
					int vidaJug;
					vidaJug = jugador.getvidaJug() - fuerza3Cont;
					jugador.setvidaJug(vidaJug);
					cout << "TU ATAQUE HA FALLADO y ahora el contrincante te ataco" << endl;
					cout << "Tu vida ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 3) {
					int vidaJug;
					vidaJug = jugador.getvidaJug() - fuerza4Cont;
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



class Bowser : public Contrincante {
	private:
		Contrincante contrincante;
		float vidaBowser;
		float fuerzabolaFuego;
		float fuerzaCola;
	public:
		float getvidaBowser() { return vidaBowser; }
		float getfuerzabolaFuego() { return fuerzabolaFuego; }
		float getfuerzaCola() { return fuerzaCola; }
		void setvidaBowser(float vida_Bowser);
		void setfuerzabolaFuego(float fuerza_Bola);
		void setfuerzaCola(float fuerza_Cola);
		void atacarJugador(string decision, int aJ, float fuerza1Cont, float fuerza2Cont, float vidaCont, Jugador jugador);
};

void Bowser::setvidaBowser(float vida_Bowser) {
	vidaBowser = vida_Bowser;
}

void Bowser::setfuerzabolaFuego(float fuerza_Bola) {
	fuerzabolaFuego = fuerza_Bola;
}

void Bowser::setfuerzaCola(float fuerza_Cola) {
	fuerzaCola = fuerza_Cola;
}


void Bowser::atacarJugador(string decision, int aJ, float fuerza1Cont, float fuerza2Cont, float vidaCont, Jugador jugador) {
	string nombreJug;
	int turnoContrincante, defensaChance, contrincanteAtaque,ataqueChance;
	nombreJug = jugador.getnombreJug();
	turnoContrincante = rand() % 2;
	defensaChance = rand() % 3;
	contrincanteAtaque = rand() % 1;
	ataqueChance = rand() % 3;
	if (decision == "D") {
		if (defensaChance == 0 || defensaChance == 1 || defensaChance == 2)
		{
			if (turnoContrincante == 0 ){
				cout << "EL ATAQUE DE BOWSER HA FALLADO!!, pero " << nombreJug << "solo se estaba defendiendo, SIGUE LA PELEA!!!" << endl;
			}
			else if (turnoContrincante == 1) {
				cout << "INCREIBLE DEFENSA CONTRA BOWSER por parte de " << nombreJug << endl;
			}
			else if (turnoContrincante == 2) {
				cout << "...No pues, ambos se defendieron,bueno PELIEN" << endl;
			}
		}
		else if (defensaChance == 3) {
			if (turnoContrincante == 0) {
				cout << "EL ATAQUE DE BOWSER HA FALLADO!!, pero  la defensa de " << nombreJug << "tambien habia fallado, SIGUE LA PELEA!!!" << endl;
			}
			else if (turnoContrincante == 1) {
				int vidaJug;
				if (contrincanteAtaque == 0) {
					vidaJug = jugador.getvidaJug() - fuerza1Cont;
					jugador.setvidaJug(vidaJug);
					cout<<"BOWSER HA UTILIZADO SU BOLA DE FUEGO, ha pegado con exito, el Rey de los Koopas viene con fuerza"<<endl; 
					cout << "La vida de " << nombreJug << " ha bajado, ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					vidaJug = jugador.getvidaJug() - fuerza2Cont;
					jugador.setvidaJug(vidaJug);
					cout << "BOWSER HA ATACADO CON SU COLA, ha pegado con exito, el Rey de los Koopas viene con fuerza" << endl;
					cout << "La vida de " << nombreJug << " ha bajado, ahora es " << vidaJug << endl;
				}
			}
			else if (turnoContrincante == 2) {
				cout << "La defensa de"<<nombreJug<<"fallo, pero el enemigo andaba defendiendo...bueno PELIEN" << endl;
			}
		}
	}
	if (decision == "A") {
		if (ataqueChance == 0 || ataqueChance == 1 || ataqueChance == 2) {
			if (turnoContrincante == 0) {
				if (aJ == 1) {
					vidaCont = vidaCont - jugador.getfuerzaAtaque1();
					cout << nombreJug << " HA REMATADO EL ATAQUE DE BOWSER CON "<<jugador.getnombreAtaque1()<<" Bowser se ve muy furioso";
					cout << "La vida de Bowser ahora es: " << vidaCont << endl;
				}
				if (aJ == 2) {
					vidaCont = vidaCont - jugador.getfuerzaAtaque2();
					cout << nombreJug << " HA REMATADO EL ATAQUE DE BOWSER CON " << jugador.getnombreAtaque2() << " Bowser se ve muy furioso";
					cout << "La vida de Bowser ahora es: " << vidaCont << endl;
				}
			}
			else if (turnoContrincante == 1) {
				int vidaJug;
				if (contrincanteAtaque == 0) {
					if (aJ == 1) {
						vidaJug = jugador.getvidaJug() - (fuerza1Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << nombreJug << " HA REMATADO EL ATAQUE DE BOWSER CON " << jugador.getnombreAtaque1() << endl;
						cout << "Pero Bowser no se queda abajo y ataca de vuelta con UNA BOLA DE FUEGOOO, gruñe al lanzar el ataque" << endl;
						cout << "La vida de Bowser ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
					if (aJ == 2) {
						int vida_Jug;
						vida_Jug = jugador.getvidaJug() - (fuerza1Cont / 2);
						jugador.setvidaJug(vida_Jug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << nombreJug << " HA REMATADO EL ATAQUE DE BOWSER CON " << jugador.getnombreAtaque2() << endl;
						cout << "Pero Bowser no se queda abajo y ataca de vuelta con UNA BOLA DE FUEGOOOOO, gruñe al lanzar el ataque" << endl;
						cout << "La vida de Bowser ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
				}
				else if (contrincanteAtaque == 1) {
					int vidaJug;
					if (aJ == 1) {
						vidaJug = jugador.getvidaJug() - (fuerza2Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << nombreJug << " HA REMATADO EL ATAQUE DE BOWSER CON " << jugador.getnombreAtaque1() << endl;
						cout << "Pero Bowser no se queda abajo y ataca de vuelta con UN ATAQUE DE COLAAAA, gruñe al lanzar el ataque" << endl;
						cout << "La vida de Bowser ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
					if (aJ == 2) {
						vidaJug = jugador.getvidaJug() - (fuerza2Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << nombreJug << " HA REMATADO EL ATAQUE DE BOWSER CON " << jugador.getnombreAtaque2() << endl;
						cout << "Pero Bowser no se queda abajo y ataca de vuelta con UN ATAQUE DE COLAAAA, gruñe al lanzar el ataque" << endl;
						cout << "La vida de Bowser ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
				}
			}
			else if (turnoContrincante == 2) {
				cout << nombreJug << "HA ATACADOOO, pero Bowser se ha defendido con exito, Bowser se rie en su cara" << endl;
			}
		}

		else if (ataqueChance == 3) {
			int vidaJug;
			if (turnoContrincante == 0) {
				cout << "LOS ATAQUES DE BOWSER y " << nombreJug << " HAN FALLADO SIMULTANEAMENTE!!" << endl;
			}
			else if (turnoContrincante == 1) {
				if (contrincanteAtaque == 0) {
					vidaJug = jugador.getvidaJug() - fuerza1Cont;
					jugador.setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO " << endl;
					cout << "Bowser se rie y ha utilizado una bola de fuego contra " << nombreJug << endl;
					cout << "La vida de"<<nombreJug<<" ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					int vidaJug;
					vidaJug = jugador.getvidaJug() - fuerza2Cont;
					jugador.setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO " << endl;
					cout << "Bowser se rie y ha atacado con su cola contra " << nombreJug << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
			}
			else if (turnoContrincante == 2) {
				cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO, pero Bowser solo se estaba defendiendo" << endl;
				cout << "Bowser se parte de risa al ver que " << nombreJug << "no ha logrado atacarlo" << endl;
			}
		}
	}
}


class Ganondorf: public Contrincante {
private:
	Contrincante contrincante;
	float vidaGanondorf;
	float fuerzawarlockPunch;
	float fuerzaflameChoke;
	float fuerzavolcanoKick;
public:
	float getvidaGanondorf() { return vidaGanondorf; }
	float getfuerzawarlockPunch() { return fuerzawarlockPunch; }
	float getfuerzaflameChoke() { return fuerzaflameChoke; }
	float getfuerzavolcanoKick() { return fuerzavolcanoKick; }
	void setvidaGanondorf(float vida_Ganon);
	void setfuerzawarlockPunch(float fuerza_Warlock);
	void setfuerzaflameChoke(float fuerza_Flame);
	void setfuerzavolcanoKick(float fuerza_Volcano);
	void atacarJugador(string decision, int aJ, float fuerza1Cont, float fuerza2Cont, float fuerza3Cont, float vidaCont, Jugador jugador);
};

void Ganondorf::setvidaGanondorf(float vida_Ganon) {
	vidaGanondorf = vida_Ganon;
}

void Ganondorf::setfuerzawarlockPunch(float fuerza_Warlock) {
	fuerzawarlockPunch = fuerza_Warlock;
}

void Ganondorf::setfuerzaflameChoke(float fuerza_Flame) {
	fuerzaflameChoke = fuerza_Flame;
}

void Ganondorf::setfuerzavolcanoKick(float fuerza_Volcano) {
	fuerzavolcanoKick= fuerza_Volcano;
}

void Ganondorf::atacarJugador(string decision, int aJ, float fuerza1Cont, float fuerza2Cont, float fuerza3Cont, float vidaCont, Jugador jugador) {
	string nombreJug;
	nombreJug = jugador.getnombreJug();
	int turnoContrincante, defensaChance, contrincanteAtaque, ataqueChance;
	turnoContrincante = rand() % 2;
	defensaChance = rand() % 3;
	contrincanteAtaque = rand() % 2;
	ataqueChance = rand() % 3;
	if (decision == "D") {
		if (defensaChance == 0 || defensaChance == 1 || defensaChance == 2)
		{
			if (turnoContrincante == 0) {
				cout << "Ganondorf ha fallado su ataque mientras " << nombreJug << " defendia, asi que sigue la pelea igual" << endl;
			}
			else if (turnoContrincante == 1) {
				cout << "IMPRESIONANTE " << nombreJug << " SE HA DEFENDIDO CONTRA GANONDORF CON EXITO" << endl;
			}
			else if (turnoContrincante == 2) {
				cout << "...No pues, ambos se defendieron,bueno PELIEN" << endl;
			}
		}
		else if (defensaChance == 3) {
			if (turnoContrincante == 0) {
				cout << "GANONDORF HA FALLADO SU ATAQUE, tiene suerte " << nombreJug << " porque su defensa habia fallado" << endl;
			}
			else if (turnoContrincante == 1) {
				int vidaJug;
				if (contrincanteAtaque == 0) {
					vidaJug = jugador.getvidaJug() - fuerza1Cont;
					jugador.setvidaJug(vidaJug);
					cout << "GANONDORF HA USADO SU WARLOCK PUNCH CON EXITO!!!, el rey demonio no va a ser derribado tan facil" << endl;
					cout << "La vida de"<<nombreJug<<" ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					vidaJug = jugador.getvidaJug() - fuerza2Cont;
					jugador.setvidaJug(vidaJug);
					cout << "GANONDORF HA USADO FLAME CHOKE CON EXITO!!!, el rey demonio no va a ser derribado tan faci" << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 2) {
					vidaJug = jugador.getvidaJug() - fuerza3Cont;
					jugador.setvidaJug(vidaJug);
					cout << "GANONDORF HA USADO VOLCANO KICK CON EXITO!!!, el rey demonio no va a ser derribado tan faci" << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
			}
			else if (turnoContrincante == 2) {
				cout << "La defensa de "<<nombreJug<<" fallo, pero Ganondorf se estaba defendiendo...bueno PELIEN" << endl;
			}
		}
	}
	if (decision == "A") {
		if (ataqueChance == 0 || ataqueChance == 1 || ataqueChance == 2) {
			if (turnoContrincante == 0) {
				if (aJ == 1) {
					vidaCont = vidaCont - jugador.getfuerzaAtaque1();
					cout << "INCREIBLE " << nombreJug << " HA ATACADO A GANONDORF CON "<<jugador.getnombreAtaque1()<<" Ganondorf se ve enojado" << endl;
					cout << "La vida de Ganondorf ahora es: " << vidaCont << endl;
				}
				if (aJ == 2) {
					vidaCont = vidaCont - jugador.getfuerzaAtaque2();
					cout << "INCREIBLE " << nombreJug << " HA ATACADO A GANONDORF CON " << jugador.getnombreAtaque2() << " Ganondorf se ve enojado" << endl;
					cout << "La vida de Ganondorf ahora es: " << vidaCont << endl;
				}
			}
			else if (turnoContrincante == 1) {
				if (contrincanteAtaque == 0) {
					if (aJ == 1) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza1Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "INCREIBLE " << nombreJug << " HA ATACADO A GANONDORF CON " << jugador.getnombreAtaque1()<< endl;
						cout << "Pero Ganondorf usando la trifuerza del poder ha rematado con un Warlock Punch, esto se pone fiero" << endl;
						cout << "La vida de Ganondorf ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
					if (aJ == 2) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza1Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << "INCREIBLE " << nombreJug << " HA ATACADO A GANONDORF CON " << jugador.getnombreAtaque2()<< endl;
						cout << "Pero Ganondorf usando la trifuerza del poder ha rematado con un Warlock Punch, esto se pone fiero" << endl;
						cout << "La vida de Ganondorf ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
				}
				else if (contrincanteAtaque == 1) {
					if (aJ == 1) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza2Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "INCREIBLE " << nombreJug << " HA ATACADO A GANONDORF CON " << jugador.getnombreAtaque1() << endl;
						cout << "Pero Ganondorf usando la trifuerza del poder ha rematado con un Flame Choke, esto se pone fiero" << endl;
						cout << "La vida de Ganondorf ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
					if (aJ == 2) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza2Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << "INCREIBLE " << nombreJug << " HA ATACADO A GANONDORF CON " << jugador.getnombreAtaque2() << endl;
						cout << "Pero Ganondorf usando la trifuerza del poder ha rematado con un Flame Choke, esto se pone fiero" << endl;
						cout << "La vida de Ganondorf ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
				}
				else if (contrincanteAtaque == 2) {
					if (aJ == 1) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza3Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "INCREIBLE " << nombreJug << " HA ATACADO A GANONDORF CON " << jugador.getnombreAtaque1() << endl;
						cout << "Pero Ganondorf usando la trifuerza del poder ha rematado con un Volcano Kick, esto se pone fiero" << endl;
						cout << "La vida de Ganondorf ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
					if (aJ == 2) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza3Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << "INCREIBLE " << nombreJug << " HA ATACADO A GANONDORF CON " << jugador.getnombreAtaque2() << endl;
						cout << "Pero Ganondorf usando la trifuerza del poder ha rematado con un Volcano Kick, esto se pone fiero" << endl;
						cout << "La vida de Ganondorf ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
				}
			}
			else if (turnoContrincante == 2) {
				cout << nombreJug << " HA ATACADO A GANONDORF" << endl;
				cout << "Pero Ganondorf se ha defendido, el rie al defender el ataque" << endl;
			}
		}

		else if (ataqueChance == 3) {
			if (turnoContrincante == 0) {
				cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
				cout << "Pero el ataque de Ganondorf también ha fallado, el rey Demonio parece ser que se debilita" << endl;
			}
			else if (turnoContrincante == 1) {
				if (contrincanteAtaque == 0) {
					int vidaJug;
					vidaJug = jugador.getvidaJug() - fuerza1Cont;
					jugador.setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
					cout << "Ahora Ganondorf ha rematado con un Warlock Punch, el rey Demonio viene fuerte esta noche!!!!" << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					int vidaJug;
					vidaJug = jugador.getvidaJug() - fuerza2Cont;
					jugador.setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
					cout << "Ahora Ganondorf ha rematado con un Flame Choke, el rey Demonio viene fuerte esta noche!!!!" << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 2) {
					int vidaJug;
					vidaJug = jugador.getvidaJug() - fuerza3Cont;
					jugador.setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
					cout << "Ahora Ganondorf ha rematado con un Volcano Kick, el rey Demonio viene fuerte esta noche!!!!" << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
			else if (turnoContrincante == 2) {
					cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
					cout << "Pero Ganondorf solo bloqueaba, el rey Demonio se rie en la cara de " << nombreJug << endl;
				}
			}
		}
	}
}

class Sephiroth : public Contrincante {
private:
	Contrincante contrincante;
	float vidaSephiroth;
	float fuerzaMasamune;
	float fuerzashadowFlare;
	float fuerzaOctaslash;
	float fuerzasuperNova;
public:
	float getvidaSephiroth() { return vidaSephiroth; }
	float getfuerzaMasamune() { return fuerzaMasamune; }
	float getfuerzashadowFlare() { return fuerzashadowFlare; }
	float getfuerzaOctaslash() { return fuerzaOctaslash; }
	float getfuerzasuperNova() { return fuerzasuperNova; }
	void setvidaSephiroth(float vida_Sephiroth);
	void setfuerzaMasamune(float fuerza_Masamune);
	void setfuerzashadowFlare(float fuerza_Shadow);
	void setfuerzaOctaslash(float fuerza_Octaslash);
	void setfuerzasuperNova(float fuerza_Nova);
	void atacarJugador(string decision, int aJ, float fuerza1Cont, float fuerza2Cont, float fuerza3Cont, float fuerza4Cont, float vidaCont, Jugador jugador);
};

void Sephiroth::setvidaSephiroth(float vida_Sephiroth) {
	vidaSephiroth = vida_Sephiroth;
}

void Sephiroth::setfuerzaMasamune(float fuerza_Masamune) {
	fuerzaMasamune = fuerza_Masamune;
}

void Sephiroth::setfuerzashadowFlare(float fuerza_Shadow) {
	fuerzashadowFlare = fuerza_Shadow;
}

void Sephiroth::setfuerzaOctaslash(float fuerza_Octaslash) {
	fuerzaOctaslash = fuerza_Octaslash;
}

void Sephiroth::setfuerzasuperNova(float fuerza_Nova) {
	fuerzasuperNova = fuerza_Nova;
}

void Sephiroth::atacarJugador(string decision, int aJ, float fuerza1Cont, float fuerza2Cont, float fuerza3Cont, float fuerza4Cont, float vidaCont, Jugador jugador) {
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
				int vidaJug;
				if (contrincanteAtaque == 0) {
					vidaJug = jugador.getvidaJug() - fuerza1Cont;
					jugador.setvidaJug(vidaJug);
					cout << "Sephiroth ha usado su mitica Masamune con exito, sonrie al ver a " << nombreJug << " caer" << endl;
					cout << "La vida de"<<nombreJug<<" ahora es : " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					vidaJug = jugador.getvidaJug() - fuerza2Cont;
					jugador.setvidaJug(vidaJug);
					cout << "Sephiroth ha usado Shadow Flare con exito, sonrie al ver a " << nombreJug << " caer" << endl;
					cout << "La vida de" << nombreJug << " ahora es : " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 2) {
					vidaJug = jugador.getvidaJug() - fuerza3Cont;
					jugador.setvidaJug(vidaJug);
					cout << "Sephiroth ha usado Octaslash con exito, sonrie al ver a " << nombreJug << " caer" << endl;
					cout << "La vida de" << nombreJug << " ahora es : " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 3) {
					vidaJug = jugador.getvidaJug() - fuerza4Cont;
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
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza1Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "NO ME LO CREO " << nombreJug << " HA ATACADO A SEPHIROTH CON " << jugador.getnombreAtaque1() << endl;
						cout << "Pero Sephiroth no se queda atras y remata con su Masamune, parece ser Sephiroth disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
						
					}
					if (aJ == 2) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza1Cont / 2);
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
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza2Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "NO ME LO CREO " << nombreJug << " HA ATACADO A SEPHIROTH CON " << jugador.getnombreAtaque1() << endl;
						cout << "Pero Sephiroth no se queda atras y remata con Shadow Flare, parece ser Sephiroth disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
					if (aJ == 2) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza2Cont / 2);
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
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza3Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "NO ME LO CREO " << nombreJug << " HA ATACADO A SEPHIROTH CON " << jugador.getnombreAtaque1() << endl;
						cout << "Pero Sephiroth no se queda atras y remata con Octaslash, parece ser Sephiroth disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
					if (aJ == 2) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza3Cont / 2);
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
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza4Cont / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "NO ME LO CREO " << nombreJug << " HA ATACADO A SEPHIROTH CON " << jugador.getnombreAtaque1() << endl;
						cout << "Pero Sephiroth no se queda atras y remata con Super Nova, parece ser Sephiroth disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
					if (aJ == 2) {
						int vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerza4Cont / 2);
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
					int vidaJug;
					vidaJug = jugador.getvidaJug() - fuerza1Cont;
					jugador.setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
					cout << "Ahora Sephiroth ha rematado con un su Masamune, parece ser que quiere terminar ya esta pelea!!!!" << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					int vidaJug;
					vidaJug = jugador.getvidaJug() - fuerza2Cont;
					jugador.setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
					cout << "Ahora Sephiroth ha rematado con Shadow Flare, parece ser que quiere terminar ya esta pelea!!!!" << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 2) {
					int vidaJug;
					vidaJug = jugador.getvidaJug() - fuerza3Cont;
					jugador.setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
					cout << "Ahora Sephiroth ha rematado con Octaslash, parece ser que quiere terminar ya esta pelea!!!!" << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 3) {
					int vidaJug;
					vidaJug = jugador.getvidaJug() - fuerza4Cont;
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
 
