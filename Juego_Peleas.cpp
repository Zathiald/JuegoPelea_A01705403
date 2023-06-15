/*
 * Proyecto Juego de Peleas
 * Samir Baidon Pardo
 * A01705403 
 * 20/05/2023
 * versio : 4
 * Este es el archivo main, en donde se harán las interacciones
 * entre el usuario(jugador) y los enemigos hechos por el código
 */

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
 /*Importo el archivo de jugador para
 ¨*poder hacer referencia a esta clase
 */
#include "jugador.h" 

 /*Importo el archivo de contrincante para
 *poder hacer referencia a esta clase
 */
#include "contrincante.h" 

 /*Importo el archivo de bowser para
 *poder hacer referencia a esta clase
 */
#include "bowser.h" 

 /*Importo el archivo de ganondorf para
 *poder hacer referencia a esta clase
 */
#include "ganondorf.h" 

 /*Importo el archivo de sephiroth para
 *poder hacer referencia a esta clase
 */
#include "sephiroth.h" 

using namespace std;

void subirNivel(Jugador* jugador);

/*Funcion:Alterar las stats del jugador cuando suba de nivel
*
*Parametros: Se toma un parametro de apuntador de Jugador,esto
*para que se altere los stats del mismo jugador
*
*Retorno: Al ser una función void no se regresa algo en sí,solo se
*alteran los valores de fuerza, vida y nivel del jugador
*/
void subirNivel(Jugador* jugador) {
	int nivel;
	nivel = jugador->getnivelJug();
	if (nivel == 1) {
		jugador->setnivelJug(2);
		jugador->setvidaJug(55.0);
		jugador->setfuerzaAtaque1(22.0);
		jugador->setfuerzaAtaque2(27.0);
		cout << "TUS STATS HAN MEJORADO" << endl;
	}
	else if (nivel == 2) {
		jugador->setnivelJug(3);
		jugador->setvidaJug(70.0);
		jugador->setfuerzaAtaque1(33.0);
		jugador->setfuerzaAtaque2(40.0);
		cout << "TUS STATS HAN MEJORADO" << endl;
	}
}

int main() {
	/*Se declaran los arreglos para el contrincante y
	*para el jugador, se les da tambien los valores
	*de vida y fuerzas a los enemigos
	*/
	Jugador* jugador[2];
	jugador[0] = new Jugador(0.0, 0.0, 0.0);
	Contrincante* contrin[4];
	contrin[0] = new Bowser(40.0, 20.0, 15.0);
	contrin[1] = new Ganondorf(60.0, 15.0, 10.0, 25.0);
	contrin[2] = new Sephiroth(80.0, 15.0, 13.0, 22.0, 40.0);

	//Se le pide al usuario darle un nombre a su personaje
	// y a sus ataques, después se le da el valor inicial a
	// la fuerza de los ataques del jugador
	string nombreJug, nombreAtaque1, nombreAtaque2;
	cout << "Ingresa el nombre de tu jugador: ";
	cin >> nombreJug;
	jugador[0]->setnombreJug(nombreJug);
	cout << endl;
	cout << "Como quieres que se llame tu primer ataque: ";
	cin >> nombreAtaque1;
	jugador[0]->setnombreAtaque1(nombreAtaque1);
	cout << endl;
	cout << "Como quieres que se llame tu segundo ataque: ";
	cin >> nombreAtaque2;
	jugador[0]->setnombreAtaque2(nombreAtaque2);
	cout << endl;
	jugador[0]->setnivelJug(1);
	jugador[0]->setvidaJug(35.0);
	jugador[0]->setfuerzaAtaque1(15.0);
	jugador[0]->setfuerzaAtaque2(17.0);


	/*Se da un mensaje de introducción a la pelea
	*este mensaje sale para la primera pelea
	*/
	if (jugador[0]->getnivelJug() == 1) {
		cout << "BIEEEEEEENVENIDOS A LAAAA PELEA ESTELAAARRRRR!!!!"
			<< endl;
		cout << "Ahora de la esquina izquierda tenemos a "
			<< jugador[0]->getnombreJug() << endl;
		cout << "Yyy de la esquina derecha tenemos al\
            rey de los Kooppas, al enemigo del\
            reino Champinion, BOWSER!!!" << endl;
		cout << "Pelearan para ver quien es el mejor y\
            .... PELIEN" << endl;
		cout << "Y aqui estan los stats para\
            nuestros luchadores" << endl;

		cout << "-----------------BOWSER------------------" << endl;
		cout << "VIDA BOWSER: "
			<< contrin[0]->getvidaCont() << endl;
		cout << "FUERZA BOLA DE FUEGO: "
			<< contrin[0]->getfuerzaCont1() << endl;
		cout << "FUERZA ATAQUE DE COLA: "
			<< contrin[0]->getfuerzaCont2() << endl;

		cout << "-----"
			<< jugador[0]->getnombreJug()
			<< "-----" << endl;
		cout << "VIDA: " << jugador[0]->getvidaJug() << endl;
		cout << "FUERZA " << jugador[0]->getnombreAtaque1()
			<< " : " << jugador[0]->getfuerzaAtaque1() << endl;
		cout << "FUERZA " << jugador[0]->getnombreAtaque2()
			<< " : " << jugador[0]->getfuerzaAtaque2() << endl;
	}

	/*Se crea un ciclo para la primera pelea en donde se sigue
	*siempre y cuando el jugador y el enemigo tengan
	*una vida mayor a 0 y el jugador sea nivel 1
	*/
	while (jugador[0]->getvidaJug() > 0
		&& contrin[0]->getvidaCont() > 0
		&& jugador[0]->getnivelJug() == 1) {
		int contrincanteChance, jugadorChance;
		float vidaCont, vidaJug;
		string decision;
		int ataqueEnemigo, opcionAtaque;
		/*Es un numero random
		*entre 0,1 y 2 que define si el ataque del Enemigo
		*funciona,falla o  si se defiente
		*/
		contrincanteChance = rand() % 2;

		/*Es un numero random
		*entre 0,1 y 2 que define si el ataque del Jugador
		*funciona,falla o  si se defiende
		*/
		jugadorChance = rand() % 2;

		/*Es un numero random
		*entre 0 y 1 que define que ataque usara el enemigo
		*/
		ataqueEnemigo = rand() % 1;
		cout << "Que ataque quieres usar: " << endl;
		cout << "1: " << jugador[0]->getnombreAtaque1() << endl;
		cout << "2: " << jugador[0]->getnombreAtaque2() << endl;
		cin >> opcionAtaque;

		/*Se crea un ciclo para si el jugador pone una opción
		*incorrecta entonces se le pide ingresar
		*de nuevo una opción
		*/
		if (opcionAtaque != 1 && opcionAtaque != 2) {
			cout << "Escoge una opcion correcta" << endl;
			cin >> opcionAtaque;
		}

		/*Se crea un if para cuando el
		*jugador escoge el primer ataque
		*/
		if (opcionAtaque == 1) {
			/*Se crea un if para cuando el
			*enemigo usa su primer ataque
			*/
			if (ataqueEnemigo == 0) {
				/*Se crea un if para cuando el
				*ataque del enemigo falla
				*/
				if (contrincanteChance == 0) {
					/*Se crea un if para cuando el
					*ataque del jugador falla
					*/
					if (jugadorChance == 2) {
						cout << "TU ATAQUE HA FALLADO...pero Bowser\
                            tampoco logro hacer nada" << endl;
					}
					/*Se crea un if para cuando el
					*ataque del jugador funciona
					*/
					else if (jugadorChance == 0 ||
						jugadorChance == 1) {
						vidaCont = contrin[0]->getvidaCont()
							- jugador[0]->getfuerzaAtaque1();
						contrin[0]->setvidaCont(vidaCont);
						cout << "HAS LOGRADO ATACAR!!!, la vida de Bowser\
                            ahora es: "
							<< contrin[0]->getvidaCont() << endl;
					}
				}
				/*Se crea un if para cuando el
				*ataque del enemigo funciona
				*/
				else if (contrincanteChance == 1) {
					if (jugadorChance == 2) {
						vidaJug = jugador[0]->getvidaJug()
							- contrin[0]->getfuerzaCont1();
						jugador[0]->setvidaJug(vidaJug);
						cout << "TU ATAQUE HA FALLADO y peor aun\
                            BOWSER SI TE ATACO, tu vida ahora es: "
							<< jugador[0]->getvidaJug() << endl;
					}
					/*Se crea un if para cuando el
					ataque del jugador tambien funciona,
					creando un contraataque
					*/
					else if (jugadorChance == 0 ||
						jugadorChance == 1) {
						vidaJug = jugador[0]->getvidaJug()
							- (contrin[0]->getfuerzaCont1() / 2);
						jugador[0]->setvidaJug(vidaJug);
						vidaCont = contrin[0]->getvidaCont()
							- (jugador[0]->getfuerzaAtaque1() / 2);
						contrin[0]->setvidaCont(vidaCont);
						cout << "AMBOS SE HAN ATACADO MUTUAMENTE,\
                            tu vida ahora es: "
							<< jugador[0]->getvidaJug() << endl;
						cout << "La vida de Bowser ahora es: "
							<< contrin[0]->getvidaCont() << endl;
					}
				}
				/*Se crea un if para cuando el
				*enemigo se defiente
				*/
				else if (contrincanteChance == 2) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO, pero Bowser\
                            se estaba defendiendo\
                            así que no paso nada al final" << endl;
					}
					else if (jugadorChance == 0 ||
						jugadorChance == 1) {
						cout << "HAS LOGRADO ATACAR!!, pero Bowser\
                            se defendio, nada cambio" << endl;
					}
				}
			}
			/*Se crea un if para cuando el
			*enemigo usa su segundo ataque
			* */
			else if (ataqueEnemigo == 1) {
				if (contrincanteChance == 0) {
					if (jugadorChance == 2) {
						cout << "TU ATAQUE HA FALLADO...\
                            pero Bowser tampoco\
                            logro hacer nada" << endl;
					}
					else if (jugadorChance == 0 ||
						jugadorChance == 1) {
						vidaCont = contrin[0]->getvidaCont()
							- jugador[0]->getfuerzaAtaque1();
						contrin[0]->setvidaCont(vidaCont);
						cout << "HAS LOGRADO ATACAR!!!,\
                            la vida de Bowser ahora es: "
							<< contrin[0]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 1) {
					if (jugadorChance == 2) {
						vidaJug = jugador[0]->getvidaJug()
							- contrin[0]->getfuerzaCont2();
						jugador[0]->setvidaJug(vidaJug);
						cout << "TU ATAQUE HA FALLADO y peor aun\
                            BOWSER SI TE ATACO, tu vida ahora es: "
							<< jugador[0]->getvidaJug() << endl;
					}
					else if (jugadorChance == 0 ||
						jugadorChance == 1) {
						vidaJug = jugador[0]->getvidaJug()
							- (contrin[0]->getfuerzaCont2() / 2);
						jugador[0]->setvidaJug(vidaJug);
						vidaCont = contrin[0]->getvidaCont()
							- (jugador[0]->getfuerzaAtaque1() / 2);
						contrin[0]->setvidaCont(vidaCont);
						cout << "AMBOS SE HAN ATACADO MUTUAMENTE,\
                            tu vida ahora es: "
							<< jugador[0]->getvidaJug() << endl;
						cout << "La vida de Bowser ahora es: "
							<< contrin[0]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 2) {
					if (jugadorChance == 2 ||
						jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO, pero Bowser\
                            se estaba defendiendo así que\
                            no paso nada al final " << endl;
					}
					else if (jugadorChance == 0 ||
						jugadorChance == 1) {
						cout << "HAS LOGRADO ATACAR!!,\
                            pero Bowser se defendio, nada cambio"
							<< endl;
					}
				}
			}
		}

		/*Se crea un if para cuando el jugador
		*decide usar su segundo ataque
		*/
		else if (opcionAtaque == 2) {
			if (ataqueEnemigo == 0) {
				if (contrincanteChance == 0) {
					if (jugadorChance == 2) {
						cout << "TU ATAQUE HA FALLADO...\
							pero Bowser tampoco logro hacer nada" 
							<< endl;
					}
					else if (jugadorChance == 0 || 
						jugadorChance == 1) {
						vidaCont = contrin[0]->getvidaCont() 
							- jugador[0]->getfuerzaAtaque2();
						contrin[0]->setvidaCont(vidaCont);
						cout << "HAS LOGRADO ATACAR!!!, la vida\
							de Bowser ahora es: " 
							<< contrin[0]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 1) {
					if (jugadorChance == 2) {
						vidaJug = jugador[0]->getvidaJug() 
							- contrin[0]->getfuerzaCont1();
						jugador[0]->setvidaJug(vidaJug);
						cout << "TU ATAQUE HA FALLADO y peor aun\
							BOWSER SI TE ATACO, tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
					}
					else if (jugadorChance == 0 || 
						jugadorChance == 1) {
						vidaJug = jugador[0]->getvidaJug() 
							- (contrin[0]->getfuerzaCont1() / 2);
						jugador[0]->setvidaJug(vidaJug);
						vidaCont = contrin[0]->getvidaCont() 
							- (jugador[0]->getfuerzaAtaque2() / 2);
						contrin[0]->setvidaCont(vidaCont);
						cout << "AMBOS SE HAN ATACADO MUTUAMENTE,\
							tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
						cout << "La vida de Bowser ahora es: " 
							<< contrin[0]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 2) {
					if (jugadorChance == 2) {
						cout << "TU ATAQUE HA FALLADO, pero Bowser\
							se estaba defendiendo así que no paso nada al final " 
							<< endl;
					}
					else if (jugadorChance == 0 || 
						jugadorChance == 1) {
						cout << "HAS LOGRADO ATACAR!!, pero Bowser\
							se defendio, nada cambio" << endl;
					}
				}
			}
			else if (ataqueEnemigo == 1) {
				if (contrincanteChance == 0) {
					if (jugadorChance == 2) {
						cout << "TU ATAQUE HA FALLADO...\
							pero Bowser tampoco logro hacer nada" 
							<< endl;
					}
					else if (jugadorChance == 0 || 
						jugadorChance == 1) {
						vidaCont = contrin[0]->getvidaCont() 
							- jugador[0]->getfuerzaAtaque2();
						contrin[0]->setvidaCont(vidaCont);
						cout << "HAS LOGRADO ATACAR!!!,\
							la vida de Bowser ahora es: " 
							<< contrin[0]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 1) {
					if (jugadorChance == 2) {
						vidaJug = jugador[0]->getvidaJug() 
							- contrin[0]->getfuerzaCont2();
						jugador[0]->setvidaJug(vidaJug);
						cout << "TU ATAQUE HA FALLADO y peor\
							aun BOWSER SI TE ATACO, tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaJug = jugador[0]->getvidaJug() 
							- (contrin[0]->getfuerzaCont2() / 2);
						jugador[0]->setvidaJug(vidaJug);
						vidaCont = contrin[0]->getvidaCont() 
							- (jugador[0]->getfuerzaAtaque2() / 2);
						contrin[0]->setvidaCont(vidaCont);
						cout << "AMBOS SE HAN ATACADO MUTUAMENTE,\
							tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
						cout << "La vida de Bowser ahora es: " 
							<< contrin[0]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 2) {
					if (jugadorChance == 2) {
						cout << "TU ATAQUE HA FALLADO, pero Bowser\
							se estaba defendiendo así que no paso\
							nada al final " << endl;
					}
					else if (jugadorChance == 0 || 
						jugadorChance == 1) {
						cout << "HAS LOGRADO ATACAR!!,\
							pero Bowser se defendio, nada cambio" 
							<< endl;
					}
				}
			}
		}

		/*Este if analiza si el enemigo llego a vida 0 o menor a 0,
		*si se logro se sube de nivel al jugador
		*/
		if (contrin[0]->getvidaCont() <= 0) {
			cout << nombreJug << " HA VENCIDO AL REEEY DE LOS\
				KOOPAS, PASAAA A LA SEGUNDA PELEA ESTELAR" << endl;
			subirNivel(jugador[0]);
		}
		/*Este if analiza si el jugador llego a vida 0 o menor a 0,
		*si esto pasa se termina el juego
		*/
		else if (jugador[0]->getvidaJug() <= 0) {
			cout << nombreJug << " ESTA FUEERAAAAA, SE ACABO" 
				<< endl;
			return 0;
		}
		/*Si tanto el jugador y el enemigo aun tienen vida,
		*se sigue a el turno del enemigo a atacar
		*/
		else {

			/*Se muestra un mensaje al usuario sobre
			*si quiere atacar o defenderse
			*/
			cout << "PARECE SER QUE BOWSER ESTA A PUNTO DE ATACAR,\
				que es lo que hara " << nombreJug << endl;
			cout << "A-Atacar" << endl;
			cout << "D-Defender" << endl;
			cin >> decision;

			/*Se crea un ciclo para si el jugador pone una opción
			*incorrecta entonces se le pide 
			*ingresar de nuevo una opción
			*/
			if (decision != "A" && decision != "D" 
				&& decision != "a" && decision != "d") {
				cout << "Escoge una opcion correcta" << endl;
				cin >> decision;
			}

			/*Se crea un if para si el jugador decidio defenderse
			*/
			if (decision == "D") {
				int ataqueJugador;
				/*Es un número random
				*entre 0 y 1, solo para llamar a 
				*la función de atacarJugador
				*este número al final no hara nada
				*/
				ataqueJugador = rand() % 1; 

				/*Se llama a la función de atacarJugador
				*con la opción de haber defendido
				*/
				contrin[0]->atacarJugador("D", ataqueJugador,
					jugador[0], contrin[0]); 
			}

			/*Se crea un if para si el jugador decidio atacar*/
			else if (decision == "A") {

				/*//Es ún numero que nos determinara 
				*que número de ataca usa el jugador 
				*/
				int ataqueJugador; 
				cout << "PARECE SER QUE " << nombreJug 
					<< " esta a punto de contraatacar, pero que ataque usara????" 
					<< endl;
				cout << "1: " << jugador[0]->getnombreAtaque1() << endl;
				cout << "2: " << jugador[0]->getnombreAtaque2() << endl;
				cin >> ataqueJugador;

				/*Se crea un ciclo para si el jugador pone una opción
				*incorrecta entonces se le pide ingresar de nuevo una opción
				*/
				while (ataqueJugador != 1 && ataqueJugador != 2) {
					cout << "Escoge una opcion correcta" << endl;
					cin >> ataqueJugador;
				}
				/*Si el jugador decide 1, se llama la funcion de 
				*atacarJugador con la opcion de Ataque y de primer ataque
				*/
				if (ataqueJugador == 1) {
					contrin[0]->atacarJugador("A", 1, jugador[0], contrin[0]);
				}
				/*Si el jugador decide 1, se llama la funcion de 
				atacarJugador con la opcion de Ataque y de segundo ataque*/
				else if (ataqueJugador == 2) {
					contrin[0]->atacarJugador("A", 2, jugador[0], contrin[0]);
				}
			}
			if (contrin[0]->getvidaCont() <= 0) {
				cout << nombreJug << " HA VENCIDO AL REEEY\
					DE LOS KOOPAS, PASAAA A LA SEGUNDA PELEA ESTELAR" << endl;
				subirNivel(jugador[0]);
			}
			if (jugador[0]->getvidaJug() <= 0) {
				cout << nombreJug << " ESTA FUEERAAAAA, SE ACABO" << endl;
				return 0;
			}
		}
	}

	if (jugador[0]->getnivelJug() == 2) {
		cout << "BIEEEEEEENVENIDOS A LAAAA\
			PELEA ESTELAAARRRRR!!!!" << endl;
		cout << "Ahora de la esquina izquierda tenemos a " 
			<< jugador[0]->getnombreJug() << endl;
		cout << "Yyy de la esquina derecha tenemos al Rey Demonio,\
			al portador de la trifuerza del poder, GANONDORF!!!" << endl;
		cout << "Pelearan para ver quien es el mejor y\
			.... PELIEN" << endl;

		cout << "-----------------GANONDORF--------------------" << endl;
		cout << "VIDA GANONDORF: " << contrin[1]->getvidaCont() << endl;
		cout << "FUERZA WARLOCK PUNCH: " 
			<< contrin[1]->getfuerzaCont1() << endl;
		cout << "FUERZA FLAME CHOKE: " 
			<< contrin[1]->getfuerzaCont2() << endl;
		cout << "FUERZA VOLCANO KICK: " 
			<< contrin[1]->getfuerzaCont3() << endl;

		cout << "-----" << jugador[0]->getnombreJug() << "-----" << endl;
		cout << "VIDA: " << jugador[0]->getvidaJug() << endl;
		cout << "FUERZA " << jugador[0]->getnombreAtaque1() << " : " 
			<< jugador[0]->getfuerzaAtaque1() << endl;
		cout << "FUERZA " << jugador[0]->getnombreAtaque2() << " : " 
			<< jugador[0]->getfuerzaAtaque2() << endl;
	}
	while (jugador[0]->getvidaJug() > 0 
		&& contrin[1]->getvidaCont() > 0 
		&& jugador[0]->getnivelJug() == 2) {
		int contrincanteChance, jugadorChance;
		float vidaCont, vidaJug;
		string decision;
		int ataqueEnemigo, opcionAtaque;
		contrincanteChance = rand() % 2;
		jugadorChance = rand() % 3;
		ataqueEnemigo = rand() % 2;
		cout << "Que ataque quieres usar: " << endl;
		cout << "1: " << jugador[0]->getnombreAtaque1() << endl;
		cout << "2: " << jugador[0]->getnombreAtaque2() << endl;
		cin >> opcionAtaque;
		while (opcionAtaque != 1 && opcionAtaque != 2) {
			cout << "Escoge una opcion correcta" << endl;
			cin >> opcionAtaque;
		}
		if (opcionAtaque == 1) {

			if (ataqueEnemigo == 0) {
				if (contrincanteChance == 0) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO...\
							pero Ganondorf tampoco logro hacer nada" << endl;
					}
					else if (jugadorChance == 0 || 
						jugadorChance == 1) {
						vidaCont = contrin[1]->getvidaCont() 
							- jugador[0]->getfuerzaAtaque1();
						contrin[1]->setvidaCont(vidaCont);
						cout << "HAS LOGRADO ATACAR!!!,\
							la vida de Ganondorf ahora es: " 
							<< contrin[1]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 1) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						vidaJug = jugador[0]->getvidaJug() 
							- contrin[1]->getfuerzaCont1();
						jugador[0]->setvidaJug(vidaJug);
						cout << "TU ATAQUE HA FALLADO y peor aun\
							GANONDORF SI TE ATACO, tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaJug = jugador[0]->getvidaJug() 
							- (contrin[1]->getfuerzaCont1() / 2);
						jugador[0]->setvidaJug(vidaJug);
						vidaCont = contrin[1]->getvidaCont() 
							- (jugador[0]->getfuerzaAtaque1() / 2);
						contrin[1]->setvidaCont(vidaCont);
						cout << "AMBOS SE HAN ATACADO MUTUAMENTE,\
							tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
						cout << "La vida de Ganondorf ahora es: " 
							<< contrin[1]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 2) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO, pero Ganondorf\
							se estaba defendiendo así que no paso nada al final " 
							<< endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						cout << "HAS LOGRADO ATACAR!!, pero Ganondorf\
							se defendio, nada cambio" << endl;
					}
				}
			}

			else if (ataqueEnemigo == 1) {
				if (contrincanteChance == 0) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO...pero Ganondorf\
							tampoco logro hacer nada" << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaCont = contrin[1]->getvidaCont() 
							- jugador[0]->getfuerzaAtaque1();
						contrin[1]->setvidaCont(vidaCont);
						cout << "HAS LOGRADO ATACAR!!!, la vida de\
							Ganondorf ahora es: " 
							<< contrin[1]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 1) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						vidaJug = jugador[0]->getvidaJug() 
							- contrin[1]->getfuerzaCont2();
						jugador[0]->setvidaJug(vidaJug);
						cout << "TU ATAQUE HA FALLADO y peor aun\
							GANONDORF SI TE ATACO, tu vida ahora es: "
							<< jugador[0]->getvidaJug() << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaJug = jugador[0]->getvidaJug() 
							- (contrin[1]->getfuerzaCont2() / 2);
						jugador[0]->setvidaJug(vidaJug);
						vidaCont = contrin[1]->getvidaCont() 
							- (jugador[0]->getfuerzaAtaque1() / 2);
						contrin[1]->setvidaCont(vidaCont);
						cout << "AMBOS SE HAN ATACADO MUTUAMENTE,\
							tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
						cout << "La vida de Ganondorf ahora es: "
							<< contrin[1]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 2) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO, pero Ganondorf\
							se estaba defendiendo así que no paso nada al final " 
							<< endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						cout << "HAS LOGRADO ATACAR!!, pero Ganondorf\
							se defendio, nada cambio" << endl;
					}
				}
			}

			else if (ataqueEnemigo == 2) {
				if (contrincanteChance == 0) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO...pero Ganondorf\
							tampoco logro hacer nada" << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaCont = contrin[1]->getvidaCont() 
							- jugador[0]->getfuerzaAtaque1();
						contrin[1]->setvidaCont(vidaCont);
						cout << "HAS LOGRADO ATACAR!!!, la vida de\
							Ganondorf ahora es: " << 
							contrin[1]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 1) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						vidaJug = jugador[0]->getvidaJug() 
							- contrin[1]->getfuerzaCont3();
						jugador[0]->setvidaJug(vidaJug);
						cout << "TU ATAQUE HA FALLADO y peor aun\
							GANONDORF SI TE ATACO, tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaJug = jugador[0]->getvidaJug() 
							- (contrin[1]->getfuerzaCont3() / 2);
						jugador[0]->setvidaJug(vidaJug);
						vidaCont = contrin[1]->getvidaCont() 
							- (jugador[0]->getfuerzaAtaque1() / 2);
						contrin[1]->setvidaCont(vidaCont);
						cout << "AMBOS SE HAN ATACADO MUTUAMENTE,\
							tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
						cout << "La vida de Ganondorf ahora es: " 
							<< contrin[1]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 2) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO, pero Ganondorf\
							se estaba defendiendo así que no paso nada al final " 
							<< endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						cout << "HAS LOGRADO ATACAR!!, pero Ganondorf\
							se defendio, nada cambio" << endl;
					}
				}
			}
		}

		else if (opcionAtaque == 2) {

			if (ataqueEnemigo == 0) {
				if (contrincanteChance == 0) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO...pero Ganondorf\
							tampoco logro hacer nada" << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaCont = contrin[1]->getvidaCont() 
							- jugador[0]->getfuerzaAtaque2();
						contrin[1]->setvidaCont(vidaCont);
						cout << "HAS LOGRADO ATACAR!!!, la vida de\
							Ganondorf ahora es: " << contrin[1]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 1) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						vidaJug = jugador[0]->getvidaJug() 
							- contrin[1]->getfuerzaCont1();
						jugador[0]->setvidaJug(vidaJug);
						cout << "TU ATAQUE HA FALLADO y peor aun\
							GANONDORF SI TE ATACO, tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaJug = jugador[0]->getvidaJug() 
							- (contrin[1]->getfuerzaCont1() / 2);
						jugador[0]->setvidaJug(vidaJug);
						vidaCont = contrin[1]->getvidaCont() 
							- (jugador[0]->getfuerzaAtaque2() / 2);
						contrin[1]->setvidaCont(vidaCont);
						cout << "AMBOS SE HAN ATACADO MUTUAMENTE,\
							tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
						cout << "La vida de Ganondorf ahora es: " 
							<< contrin[1]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 2) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO, pero Ganondorf\
							se estaba defendiendo así que no paso nada al final " 
							<< endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						cout << "HAS LOGRADO ATACAR!!, pero Ganondorf\
							se defendio, nada cambio" << endl;
					}
				}
			}

			else if (ataqueEnemigo == 1) {
				if (contrincanteChance == 0) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO...pero Ganondorf\
							tampoco logro hacer nada" << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaCont = contrin[1]->getvidaCont() 
							- jugador[0]->getfuerzaAtaque2();
						contrin[1]->setvidaCont(vidaCont);
						cout << "HAS LOGRADO ATACAR!!!, la vida de\
							Ganondorf ahora es: " << contrin[1]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 1) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						vidaJug = jugador[0]->getvidaJug() 
							- contrin[1]->getfuerzaCont2();
						jugador[0]->setvidaJug(vidaJug);
						cout << "TU ATAQUE HA FALLADO y peor aun\
							GANONDORF SI TE ATACO, tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaJug = jugador[0]->getvidaJug()
							- (contrin[1]->getfuerzaCont2() / 2);
						jugador[0]->setvidaJug(vidaJug);
						vidaCont = contrin[1]->getvidaCont() 
							- (jugador[0]->getfuerzaAtaque2() / 2);
						contrin[1]->setvidaCont(vidaCont);
						cout << "AMBOS SE HAN ATACADO MUTUAMENTE,\
							tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
						cout << "La vida de Ganondorf ahora es: " 
							<< contrin[1]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 2) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO, pero Ganondorf\
							se estaba defendiendo así que no paso nada al final " << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						cout << "HAS LOGRADO ATACAR!!, pero Ganondorf\
							se defendio, nada cambio" << endl;
					}
				}
			}

			else if (ataqueEnemigo == 2) {
				if (contrincanteChance == 0) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO...pero Ganondorf\
							tampoco logro hacer nada" << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaCont = contrin[1]->getvidaCont() 
							- jugador[0]->getfuerzaAtaque2();
						contrin[1]->setvidaCont(vidaCont);
						cout << "HAS LOGRADO ATACAR!!!, la vida de\
							Ganondorf ahora es: " << contrin[1]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 1) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						vidaJug = jugador[0]->getvidaJug() 
							- contrin[1]->getfuerzaCont3();
						jugador[0]->setvidaJug(vidaJug);
						cout << "TU ATAQUE HA FALLADO y peor aun\
							GANONDORF SI TE ATACO, tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaJug = jugador[0]->getvidaJug() 
							- (contrin[1]->getfuerzaCont3() / 2);
						jugador[0]->setvidaJug(vidaJug);
						vidaCont = contrin[1]->getvidaCont() 
							- (jugador[0]->getfuerzaAtaque2() / 2);
						contrin[1]->setvidaCont(vidaCont);
						cout << "AMBOS SE HAN ATACADO MUTUAMENTE,\
							tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
						cout << "La vida de Ganondorf ahora es: " 
							<< contrin[1]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 2) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO, pero Ganondorf\
							se estaba defendiendo así que no paso nada al final " 
							<< endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						cout << "HAS LOGRADO ATACAR!!, pero Ganondorf\
							se defendio, nada cambio" << endl;
					}
				}
			}
		}
		if (contrin[1]->getvidaCont() <= 0) {
			cout << nombreJug << " HA VENCIDO AL REY DEMONIO,\
				PASAAA A LA SEGUNDA PELEA ESTELAR" << endl;
			subirNivel(jugador[0]);
		}
		else if (jugador[0]->getvidaJug() <= 0) {
			cout << nombreJug << " ESTA FUEERAAAAA, SE ACABO" << endl;
			return 0;
		}
		else {
			cout << "PARECE SER QUE GANON ESTA A PUNTO DE ATACAR,\
				que es lo que hara " << nombreJug << endl;
			cout << "A-Atacar" << endl;
			cout << "D-Defender" << endl;
			cin >> decision;
			while (decision != "A" && decision != "D" 
				&& decision != "a" && decision != "d") {
				cout << "Escoge una opcion correcta" << endl;
				cin >> decision;
			}
			if (decision == "D") {
				int ataqueJugador;
				ataqueJugador = rand() % 1;
				contrin[1]->atacarJugador("D", ataqueJugador,
					jugador[0], contrin[1]);
			}
			else if (decision == "A") {
				int ataqueJugador;
				cout << "PARECE SER QUE " << nombreJug 
					<< " esta a punto de contraatacar,\
					pero que ataque usara????" << endl;
				cout << "1: " << jugador[0]->getnombreAtaque1() << endl;
				cout << "2: " << jugador[0]->getnombreAtaque2() << endl;
				cin >> ataqueJugador;
				while (ataqueJugador != 1 && ataqueJugador != 2) {
					cout << "Escoge una opcion correcta" << endl;
					cin >> ataqueJugador;
				}
				if (ataqueJugador == 1) {
					contrin[1]->atacarJugador("A", 1, jugador[0], contrin[1]);
				}
				else if (ataqueJugador == 2) {
					contrin[1]->atacarJugador("A", 2, jugador[0], contrin[1]);
				}
			}
			if (contrin[1]->getvidaCont() <= 0) {
				cout << nombreJug << " HA VENCIDO AL REY DEMONIO,\
					PASAAA A LA SEGUNDA PELEA ESTELAR" << endl;
				subirNivel(jugador[0]);
			}
			if (jugador[0]->getvidaJug() <= 0) {
				cout << nombreJug << " ESTA FUEERAAAAA,\
					SE ACABO" << endl;
				return 0;
			}
		}
	}

	if (jugador[0]->getnivelJug() == 3) {
		cout << "BIEEEEEEENVENIDOS A LAAAA\
			PELEA ESTELAAARRRRR!!!!" << endl;
		cout << "Ahora de la esquina izquierda tenemos a " 
			<< jugador[0]->getnombreJug() << endl;
		cout << "Yyy de la esquina derecha tenemos al Angel\
			de un ala, al Angel de la muerte, SEPHIROTH!!!" << endl;
		cout << "Pelearan para ver quien es el mejor y....\
			PELIEN" << endl;

		cout << "-----SEPHIROTH-----" << endl;
		cout << "VIDA SEPHIROTH: " << contrin[2]->getvidaCont() << endl;
		cout << "FUERZA MASAMUNE: " 
			<< contrin[2]->getfuerzaCont1() << endl;
		cout << "FUERZA SHADOW FLARE: " 
			<< contrin[2]->getfuerzaCont2() << endl;
		cout << "FUERZA OCTASLASH: " 
			<< contrin[2]->getfuerzaCont3() << endl;
		cout << "FUERZA SUPER NOVA: " 
			<< contrin[2]->getfuerzaCont4() << endl;

		cout << "-----" << jugador[0]->getnombreJug() << "-----" << endl;
		cout << "VIDA: " << jugador[0]->getvidaJug() << endl;
		cout << "FUERZA " << jugador[0]->getnombreAtaque1() << " : " 
			<< jugador[0]->getfuerzaAtaque1() << endl;
		cout << "FUERZA " << jugador[0]->getnombreAtaque2() << " : " 
			<< jugador[0]->getfuerzaAtaque2() << endl;
	}

	while (jugador[0]->getvidaJug() > 0 && 
		contrin[2]->getvidaCont() > 0 && 
		jugador[0]->getnivelJug() == 3) {
		int contrincanteChance, jugadorChance;
		float vidaCont, vidaJug;
		string decision;
		int ataqueEnemigo, opcionAtaque;
		contrincanteChance = rand() % 2;
		jugadorChance = rand() % 3;
		ataqueEnemigo = rand() % 3;
		cout << "Que ataque quieres usar: " << endl;
		cout << "1: " << jugador[0]->getnombreAtaque1() << endl;
		cout << "2: " << jugador[0]->getnombreAtaque2() << endl;
		cin >> opcionAtaque;
		while (opcionAtaque != 1 && opcionAtaque != 2) {
			cout << "Escoge una opcion correcta" << endl;
			cin >> opcionAtaque;
		}
		if (opcionAtaque == 1) {
			if (ataqueEnemigo == 0) {
				if (contrincanteChance == 0) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO...\
							pero Sephiroth tampoco logro hacer nada" << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaCont = contrin[2]->getvidaCont() 
							- jugador[0]->getfuerzaAtaque1();
						contrin[2]->setvidaCont(vidaCont);
						cout << "HAS LOGRADO ATACAR!!!, la vida de\
							Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 1) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						vidaJug = jugador[0]->getvidaJug() 
							- contrin[2]->getfuerzaCont1();
						jugador[0]->setvidaJug(vidaJug);
						cout << "TU ATAQUE HA FALLADO y peor aun\
							SEPHIROTH SI TE ATACO, tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaJug = jugador[0]->getvidaJug() 
							- (contrin[2]->getfuerzaCont1() / 2);
						jugador[0]->setvidaJug(vidaJug);
						vidaCont = contrin[2]->getvidaCont() 
							- (jugador[0]->getfuerzaAtaque1() / 2);
						contrin[2]->setvidaCont(vidaCont);
						cout << "AMBOS SE HAN ATACADO MUTUAMENTE,\
							tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
						cout << "La vida de Sephiroth ahora es: " 
							<< contrin[2]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 2) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO, pero Sephiroth\
							se estaba defendiendo así que no paso nada al final " 
							<< endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						cout << "HAS LOGRADO ATACAR!!, pero Sephiroth\
							se defendio, nada cambio" << endl;
					}
				}
			}

			else if (ataqueEnemigo == 1) {
				if (contrincanteChance == 0) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO...pero Sephiroth\
							tampoco logro hacer nada" << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaCont = contrin[2]->getvidaCont() 
							- jugador[0]->getfuerzaAtaque1();
						contrin[2]->setvidaCont(vidaCont);
						cout << "HAS LOGRADO ATACAR!!!, la vida de\
							Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 1) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						vidaJug = jugador[0]->getvidaJug() 
							- contrin[2]->getfuerzaCont2();
						jugador[0]->setvidaJug(vidaJug);
						cout << "TU ATAQUE HA FALLADO y peor aun\
							SEPHIROTH SI TE ATACO, tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaJug = jugador[0]->getvidaJug() 
							- (contrin[2]->getfuerzaCont2() / 2);
						jugador[0]->setvidaJug(vidaJug);
						vidaCont = contrin[2]->getvidaCont() 
							- (jugador[0]->getfuerzaAtaque1() / 2);
						contrin[2]->setvidaCont(vidaCont);
						cout << "AMBOS SE HAN ATACADO MUTUAMENTE,\
							tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
						cout << "La vida de Sephiroth ahora es: " 
							<< contrin[2]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 2) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO, pero Sephiroth\
							se estaba defendiendo así que no paso nada al final " 
							<< endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						cout << "HAS LOGRADO ATACAR!!, pero Sephiroth\
							se defendio, nada cambio" << endl;
					}
				}
			}

			else if (ataqueEnemigo == 2) {
				if (contrincanteChance == 0) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO...pero Sephiroth\
							tampoco logro hacer nada" << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaCont = contrin[2]->getvidaCont() 
							- jugador[0]->getfuerzaAtaque1();
						contrin[2]->setvidaCont(vidaCont);
						cout << "HAS LOGRADO ATACAR!!!, la vida de\
							Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 1) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						vidaJug = jugador[0]->getvidaJug() 
							- contrin[2]->getfuerzaCont3();
						jugador[0]->setvidaJug(vidaJug);
						cout << "TU ATAQUE HA FALLADO y peor aun\
							SEPHIROTH SI TE ATACO, tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaJug = jugador[0]->getvidaJug()
							- (contrin[2]->getfuerzaCont3() / 2);
						jugador[0]->setvidaJug(vidaJug);
						vidaCont = contrin[2]->getvidaCont() 
							- (jugador[0]->getfuerzaAtaque1() / 2);
						contrin[2]->setvidaCont(vidaCont);
						cout << "AMBOS SE HAN ATACADO MUTUAMENTE,\
							tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
						cout << "La vida de Sephiroth ahora es: " 
							<< contrin[2]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 2) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO, pero Sephiroth\
							se estaba defendiendo así que no paso nada al final " 
							<< endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						cout << "HAS LOGRADO ATACAR!!, pero Sephiroth\
							se defendio, nada cambio" << endl;
					}
				}
			}

			else if (ataqueEnemigo == 3) {
				if (contrincanteChance == 0) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO...pero Sephiroth\
							tampoco logro hacer nada" << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaCont = contrin[2]->getvidaCont() 
							- jugador[0]->getfuerzaAtaque1();
						contrin[2]->setvidaCont(vidaCont);
						cout << "HAS LOGRADO ATACAR!!!, la vida de\
							Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 1) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						vidaJug = jugador[0]->getvidaJug() 
							- contrin[2]->getfuerzaCont4();
						jugador[0]->setvidaJug(vidaJug);
						cout << "TU ATAQUE HA FALLADO y peor aun\
							SEPHIROTH SI TE ATACO, tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaJug = jugador[0]->getvidaJug() 
							- (contrin[2]->getfuerzaCont4() / 2);
						jugador[0]->setvidaJug(vidaJug);
						vidaCont = contrin[2]->getvidaCont() 
							- (jugador[0]->getfuerzaAtaque1() / 2);
						contrin[2]->setvidaCont(vidaCont);
						cout << "AMBOS SE HAN ATACADO MUTUAMENTE,\
							tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
						cout << "La vida de Sephiroth ahora es: " 
							<< contrin[2]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 2) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO, pero Sephiroth\
							se estaba defendiendo así que no paso nada al final " 
							<< endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						cout << "HAS LOGRADO ATACAR!!, pero Sephiroth\
							se defendio, nada cambio" << endl;
					}
				}
			}
		}

		else if (opcionAtaque == 2) {
			if (ataqueEnemigo == 0) {
				if (contrincanteChance == 0) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO...\
							pero Sephiroth tampoco logro hacer nada" << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaCont = contrin[2]->getvidaCont() 
							- jugador[0]->getfuerzaAtaque2();
						contrin[2]->setvidaCont(vidaCont);
						cout << "HAS LOGRADO ATACAR!!!,\
							la vida de Sephiroth ahora es: " 
							<< contrin[2]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 1) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						vidaJug = jugador[0]->getvidaJug() 
							- contrin[2]->getfuerzaCont1();
						jugador[0]->setvidaJug(vidaJug);
						cout << "TU ATAQUE HA FALLADO y peor aun\
							SEPHIROTH SI TE ATACO, tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaJug = jugador[0]->getvidaJug() 
							- (contrin[2]->getfuerzaCont1() / 2);
						jugador[0]->setvidaJug(vidaJug);
						vidaCont = contrin[2]->getvidaCont() 
							- (jugador[0]->getfuerzaAtaque2() / 2);
						contrin[2]->setvidaCont(vidaCont);
						cout << "AMBOS SE HAN ATACADO MUTUAMENTE,\
							tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
						cout << "La vida de Sephiroth ahora es: " 
							<< contrin[2]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 2) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO, pero Sephiroth\
							se estaba defendiendo así que no paso nada al final " 
							<< endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						cout << "HAS LOGRADO ATACAR!!, pero Sephiroth\
							se defendio, nada cambio" << endl;
					}
				}
			}

			else if (ataqueEnemigo == 1) {
				if (contrincanteChance == 0) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO...pero Sephiroth\
							tampoco logro hacer nada" << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaCont = contrin[2]->getvidaCont() 
							- jugador[0]->getfuerzaAtaque2();
						contrin[2]->setvidaCont(vidaCont);
						cout << "HAS LOGRADO ATACAR!!!, la vida de\
							Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 1) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						vidaJug = jugador[0]->getvidaJug() 
							- contrin[2]->getfuerzaCont2();
						jugador[0]->setvidaJug(vidaJug);
						cout << "TU ATAQUE HA FALLADO y peor aun\
							SEPHIROTH SI TE ATACO, tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaJug = jugador[0]->getvidaJug() 
							- (contrin[2]->getfuerzaCont2() / 2);
						jugador[0]->setvidaJug(vidaJug);
						vidaCont = contrin[2]->getvidaCont() 
							- (jugador[0]->getfuerzaAtaque2() / 2);
						contrin[2]->setvidaCont(vidaCont);
						cout << "AMBOS SE HAN ATACADO MUTUAMENTE,\
							tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
						cout << "La vida de Sephiroth ahora es: " 
							<< contrin[2]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 2) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO, pero Sephiroth\
							se estaba defendiendo así que no paso nada al final " 
							<< endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						cout << "HAS LOGRADO ATACAR!!, pero Sephiroth\
							se defendio, nada cambio" << endl;
					}
				}
			}

			else if (ataqueEnemigo == 2) {
				if (contrincanteChance == 0) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO...pero Sephiroth\
							tampoco logro hacer nada" << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaCont = contrin[2]->getvidaCont() 
							- jugador[0]->getfuerzaAtaque2();
						contrin[2]->setvidaCont(vidaCont);
						cout << "HAS LOGRADO ATACAR!!!, la vida de\
							Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 1) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						vidaJug = jugador[0]->getvidaJug() 
							- contrin[2]->getfuerzaCont3();
						jugador[0]->setvidaJug(vidaJug);
						cout << "TU ATAQUE HA FALLADO y peor aun\
							SEPHIROTH SI TE ATACO, tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaJug = jugador[0]->getvidaJug() 
							- (contrin[2]->getfuerzaCont3() / 2);
						jugador[0]->setvidaJug(vidaJug);
						vidaCont = contrin[2]->getvidaCont() 
							- (jugador[0]->getfuerzaAtaque2() / 2);
						contrin[2]->setvidaCont(vidaCont);
						cout << "AMBOS SE HAN ATACADO MUTUAMENTE,\
							tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
						cout << "La vida de Sephiroth ahora es: " 
							<< contrin[2]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 2) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO, pero Sephiroth\
							se estaba defendiendo así que no paso nada al final " 
							<< endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						cout << "HAS LOGRADO ATACAR!!, pero Sephiroth\
							se defendio, nada cambio" << endl;
					}
				}
			}

			else if (ataqueEnemigo == 3) {
				if (contrincanteChance == 0) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO...pero Sephiroth\
							tampoco logro hacer nada" << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaCont = contrin[2]->getvidaCont() 
							- jugador[0]->getfuerzaAtaque2();
						contrin[2]->setvidaCont(vidaCont);
						cout << "HAS LOGRADO ATACAR!!!, la vida de\
							Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 1) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						vidaJug = jugador[0]->getvidaJug() 
							- contrin[2]->getfuerzaCont4();
						jugador[0]->setvidaJug(vidaJug);
						cout << "TU ATAQUE HA FALLADO y peor aun\
							SEPHIROTH SI TE ATACO, tu vida ahora es: " 
							<< jugador[0]->getvidaJug() << endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						vidaJug = jugador[0]->getvidaJug() 
							- (contrin[2]->getfuerzaCont4() / 2);
						jugador[0]->setvidaJug(vidaJug);
						vidaCont = contrin[2]->getvidaCont() 
							- (jugador[0]->getfuerzaAtaque2() / 2);
						contrin[2]->setvidaCont(vidaCont);
						cout << "AMBOS SE HAN ATACADO MUTUAMENTE,\
							tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
						cout << "La vida de Sephiroth ahora es: " 
							<< contrin[2]->getvidaCont() << endl;
					}
				}
				else if (contrincanteChance == 2) {
					if (jugadorChance == 2 || jugadorChance == 3) {
						cout << "TU ATAQUE HA FALLADO, pero Sephiroth\
							se estaba defendiendo así que no paso nada al final " 
							<< endl;
					}
					else if (jugadorChance == 0 || jugadorChance == 1) {
						cout << "HAS LOGRADO ATACAR!!, pero Sephiroth\
							se defendio, nada cambio" << endl;
					}
				}
			}
		}
		if (contrin[2]->getvidaCont() <= 0) {
			cout << nombreJug << " HA VENCIDO AL ANGEL DE UN ALA,\
				LO HA GANADO TODO DAMAS Y SEÑORES, " << nombreJug 
				<< " ES NUESTRO CAMPION" << endl;
			cout << "ERES EL CAMPION" << endl;
			return 0;
		}

		else if (jugador[0]->getvidaJug() <= 0) {
			cout << nombreJug << " ESTA FUEERAAAAA, SE ACABO" << endl;
			return 0;
		}
		else {
			cout << "PARECE SER QUE SEPHIROTH ESTA A PUNTO DE ATACAR,\
				que es lo que hara " << nombreJug << endl;
			cout << "A-Atacar" << endl;
			cout << "D-Defender" << endl;
			cin >> decision;
			while (decision != "A" && decision != "D" && 
				decision != "a" && decision != "d") {
				cout << "Escoge una opcion correcta" << endl;
				cin >> decision;
			}
			if (decision == "D") {
				int ataqueJugador;
				ataqueJugador = rand() % 1;
				contrin[2]->atacarJugador("D", ataqueJugador, 
					jugador[0], contrin[2]);
			}
			else if (decision == "A") {
				int ataqueJugador;
				cout << "PARECE SER QUE " << nombreJug << " esta a punto\
					de contraatacar, pero que ataque usara????" << endl;
				cout << "1: " << jugador[0]->getnombreAtaque1() << endl;
				cout << "2: " << jugador[0]->getnombreAtaque2() << endl;
				cin >> ataqueJugador;
				while (ataqueJugador != 1 && ataqueJugador != 2) {
					cout << "Escoge una opcion correcta" << endl;
					cin >> ataqueJugador;
				}
				if (ataqueJugador == 1) {
					contrin[2]->atacarJugador("A", 1, jugador[0], contrin[2]);
				}
				else if (ataqueJugador == 2) {
					contrin[2]->atacarJugador("A", 2, jugador[0], contrin[2]);
				}
			}
			if (contrin[2]->getvidaCont() <= 0) {
				cout << nombreJug << " HA VENCIDO AL ANGEL DE UN ALA,\
					LO HA GANADO TODO DAMAS Y SEÑORES, " << nombreJug 
					<< " ES NUESTRO CAMPION" << endl;
				cout << "ERES EL CAMPION" << endl;
				return 0;
			}

			else if (jugador[0]->getvidaJug() <= 0) {
				cout << nombreJug << " ESTA FUEERAAAAA, SE ACABO" << endl;
				return 0;
			}
		}
	}
}
