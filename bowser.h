/*
 * Proyecto Juego de Peleas
 * Samir Baidon Pardo
 * A01705403
 * 20/05/2023
 * versio : 4
 * Esta clase define la clase de Bowser, esta clase hereda
 * de la clase de Contrincante y sobreescribe unas de sus funciones
 */

#ifndef BOWSER_H
#define BOWSER_H

#include <iostream>
#include <cstdlib>
/*Se incluye la clase de Contrincante
*para heredar de ella
*/
#include "contrincante.h" 

using namespace std;

class Bowser : public Contrincante {

/*Se declaran los métodos públicos
*/
public:
	Jugador jugador;
	/*Declaramos de nuevo la función para tener polimorfismo
	*/
	void atacarJugador(string decision, int aJ, Jugador* jugador,
		Contrincante* bowser); 

	Bowser() {}

	/*Declaramos el constructor para Bowser
	*que toma elementos de Contrincante
	*/
	Bowser(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2):
		Contrincante(vidaEnem, fuerzaEnem1, fuerzaEnem2){}
};

/*Funcion:Alterar la vida de tanto el enemigo como el jugador
*se tiene sobreescritura al tener un dialogo diferente 
* 
*Parametros: Se toma un parametro string para 
*la decision del jugador, un parametro int para
*el ataque que decidio usar el jugador, un parametro apuntador
*para poder evitar que se creen copias del jugador y
*un parametro apuntador de Contrincante para poder usar el mismo
*enemigo durante el round
*
*Retorno: Al ser una función void no se regresa algo en sí,solo se 
*alteran los valores de vida del jugador y el enemigo
*/
void Bowser::atacarJugador(string decision, int aJ,
	Jugador* jugador,Contrincante* bowser){
	float vidaJug,vidaCont;
	int turnoContrincante, defensaChance,
		contrincanteAtaque, ataqueChance;
	turnoContrincante = rand() % 2;
	defensaChance = rand() % 3;
	contrincanteAtaque = rand() % 1;
	ataqueChance = rand() % 3;
	if (decision == "D") {
		if (defensaChance == 0 || defensaChance == 1 ||
			defensaChance == 2)
		{
			if (turnoContrincante == 0) {
				cout << "EL ATAQUE DE BOWSER HA FALLADO!!, pero "<<
					jugador->getnombreJug() <<
					" solo se estaba defendiendo, SIGUE LA PELEA!!!" << endl; 
			}
			else if (turnoContrincante == 1) {
				cout << "INCREIBLE DEFENSA CONTRA BOWSER por parte de " <<
					jugador->getnombreJug() << endl;
			}
			else if (turnoContrincante == 2) {
				cout << "...No pues, ambos se defendieron,bueno PELIEN"
					<< endl;
			}
		}
		else if (defensaChance == 3) {
			if (turnoContrincante == 0) {
				cout << "EL ATAQUE DE BOWSER HA FALLADO!!, pero  la defensa de "
					<< jugador->getnombreJug() <<
					" tambien habia fallado, SIGUE LA PELEA!!!" << endl;
			}
			else if (turnoContrincante == 1) {
				if (contrincanteAtaque == 0) {
					vidaJug = jugador->getvidaJug() - bowser->getfuerzaCont1();
					jugador->setvidaJug(vidaJug);
					cout << "BOWSER HA UTILIZADO SU BOLA DE FUEGO,\
						 ha pegado con exito,el Rey de los Koopas\
						 viene con fuerza" << endl;
					cout << "La vida de " << jugador->getnombreJug() <<
						" ha bajado, ahora es " << jugador->getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					vidaJug = jugador->getvidaJug() - bowser->getfuerzaCont2();
					jugador->setvidaJug(vidaJug);
					cout << "BOWSER HA ATACADO CON SU COLA,\
						 ha pegado con exito, el Rey de los Koopas\
						viene con fuerza" << endl;
					cout << "La vida de " << jugador->getnombreJug() <<
						" ha bajado, ahora es " << jugador->getvidaJug() << endl;
				}
			}
			else if (turnoContrincante == 2) {
				cout << "La defensa de " << 
					jugador->getnombreJug() << 
					" fallo, pero el enemigo andaba\
					defendiendo...bueno PELIEN" << endl;
			}
		}
	}
	else if (decision == "A") {
		if (ataqueChance == 0 || ataqueChance == 1 ||
			ataqueChance == 2) {
			if (turnoContrincante == 0) {
				if (aJ == 1) {
					vidaCont = bowser->getvidaCont()
						- jugador->getfuerzaAtaque1();
					bowser->setvidaCont(vidaCont);
					cout << jugador->getnombreJug() <<
						" HA REMATADO EL ATAQUE DE BOWSER CON "
						<< jugador->getnombreAtaque1() <<
						" Bowser se ve muy furioso"<<endl;
					cout << "La vida de Bowser ahora es: " << vidaCont << endl;
				}
				else if (aJ == 2) {
					vidaCont = bowser->getvidaCont() - jugador->getfuerzaAtaque2();
					bowser->setvidaCont(vidaCont);
					cout << jugador->getnombreJug() <<
						" HA REMATADO EL ATAQUE DE BOWSER CON " 
						<< jugador->getnombreAtaque2() <<
						" Bowser se ve muy furioso"<<endl;
					cout << "La vida de Bowser ahora es: " << vidaCont << endl;
				}
			}
			else if (turnoContrincante == 1) {
				if (contrincanteAtaque == 0) {
					if (aJ == 1) {
						vidaJug = jugador->getvidaJug()
							- (bowser->getfuerzaCont1() / 2);
						jugador->setvidaJug(vidaJug);
						vidaCont = bowser->getvidaCont()
							- (jugador->getfuerzaAtaque1() / 2);
						bowser->setvidaCont(vidaCont);
						cout << jugador->getnombreJug() <<
							" HA REMATADO EL ATAQUE DE BOWSER CON "
							<< jugador->getnombreAtaque1() << endl;
						cout << "Pero Bowser no se queda abajo y ataca de vuelta\
							con UNA BOLA DE FUEGOOO, gruñe al lanzar el ataque" << endl;
						cout << "La vida de Bowser ahora es: " << vidaCont << endl;
						cout << "La vida de " << jugador->getnombreJug() <<
							" ahora es: " << jugador->getvidaJug() << endl;
					}
					else if (aJ == 2) {
						vidaJug = jugador->getvidaJug()
							- (bowser->getfuerzaCont1() / 2);
						jugador->setvidaJug(vidaJug);
						vidaCont = bowser->getvidaCont()
							- (jugador->getfuerzaAtaque2() / 2);
						bowser->setvidaCont(vidaCont);
						cout << jugador->getnombreJug() <<
							" HA REMATADO EL ATAQUE DE BOWSER CON "
							<< jugador->getnombreAtaque2() << endl;
						cout << "Pero Bowser no se queda abajo y ataca de vuelta con\
							UNA BOLA DE FUEGOOOOO, gruñe al lanzar el ataque" << endl;
						cout << "La vida de Bowser ahora es: " << vidaCont << endl;
						cout << "La vida de " << jugador->getnombreJug() <<
							" ahora es: " << jugador->getvidaJug() << endl;
					}
				}
				else if (contrincanteAtaque == 1) {
					if (aJ == 1) {
						vidaJug = jugador->getvidaJug() 
							- (bowser->getfuerzaCont2() / 2);
						jugador->setvidaJug(vidaJug);
						vidaCont = bowser->getvidaCont() 
							- (jugador->getfuerzaAtaque1() / 2);
						bowser->setvidaCont(vidaCont);
						cout << jugador->getnombreJug() <<
							" HA REMATADO EL ATAQUE DE BOWSER CON "
							<< jugador->getnombreAtaque1() << endl;
						cout << "Pero Bowser no se queda abajo y ataca de vuelta con\
							UN ATAQUE DE COLAAAA, gruñe al lanzar el ataque" << endl;
						cout << "La vida de Bowser ahora es: " << vidaCont << endl;
						cout << "La vida de " << jugador->getnombreJug() <<
							" ahora es: " << jugador->getvidaJug() << endl;
					}
					else if (aJ == 2) {
						vidaJug = jugador->getvidaJug()
							- (bowser->getfuerzaCont2() / 2);
						jugador->setvidaJug(vidaJug);
						vidaCont = bowser->getvidaCont()
							- (jugador->getfuerzaAtaque2() / 2);
						bowser->setvidaCont(vidaCont);
						cout << jugador->getnombreJug() 
							<< " HA REMATADO EL ATAQUE DE BOWSER CON "
							<< jugador->getnombreAtaque2() << endl;
						cout << "Pero Bowser no se queda abajo y ataca de vuelta con\
							UN ATAQUE DE COLAAAA, gruñe al lanzar el ataque" << endl;
						cout << "La vida de Bowser ahora es: " << vidaCont << endl;
						cout << "La vida de " << jugador->getnombreJug()
							<< " ahora es: " << jugador->getvidaJug() << endl;
					}
				}
			}
			else if (turnoContrincante == 2) {
				cout << jugador->getnombreJug() << "HA ATACADOOO, pero Bowser\
					se ha defendido con exito, Bowser se rie en su cara" << endl;
			}
		}

		else if (ataqueChance == 3) {
			if (turnoContrincante == 0) {
				cout << "LOS ATAQUES DE BOWSER y "
					<< jugador->getnombreJug() <<
					" HAN FALLADO SIMULTANEAMENTE!!" << endl;
			}
			else if (turnoContrincante == 1) {
				if (contrincanteAtaque == 0) {
					vidaJug = jugador->getvidaJug()
						- bowser->getfuerzaCont1();
					jugador->setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " <<
						jugador->getnombreJug() << " HA FALLADO " << endl;
					cout << "Bowser se rie y ha utilizado una bola de fuego contra "
						<< jugador->getnombreJug() << endl;
					cout << "La vida de" << jugador->getnombreJug()
						<< " ahora es " << jugador->getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					vidaJug = jugador->getvidaJug()
						- bowser->getfuerzaCont2();
					jugador->setvidaJug(vidaJug);
					cout << "EL ATAQUE DE "
						<< jugador->getnombreJug() << " HA FALLADO " << endl;
					cout << "Bowser se rie y ha atacado con su cola contra "
						<< jugador->getnombreJug() << endl;
					cout << "La vida de "<< jugador->getnombreJug() 
						<< " ahora es "<< jugador->getvidaJug() << endl;
				}
			}
			else if (turnoContrincante == 2) {
				cout << "EL ATAQUE DE "
					<< jugador->getnombreJug() << " HA FALLADO, pero Bowser\
					solo se estaba defendiendo" << endl;
				cout << "Bowser se parte de risa al ver que "
					<< jugador->getnombreJug()
					<< "no ha logrado atacarlo" << endl;
			}
		}
	}
}
#endif