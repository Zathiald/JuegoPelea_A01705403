// Juego_Peleas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "jugador.h"
#include "contrincante.h"
#include "bowser.h"
#include "ganondorf.h"
#include "sephiroth.h"

using namespace std;

void subirNivel(Jugador* jugador);

void subirNivel(Jugador* jugador) {
    int nivel;
    nivel = jugador->getnivelJug();
    if (nivel == 1) {
        jugador->setnivelJug(2);
        jugador->setvidaJug(55.0);
        jugador->setfuerzaAtaque1(20.0);
        jugador->setfuerzaAtaque2(25.0);
        cout << "TUS STATS HAN MEJORADO" << endl;
    }
    else if (nivel == 2) {
        jugador->setnivelJug(3);
        jugador->setvidaJug(70.0);
        jugador->setfuerzaAtaque1(30.0);
        jugador->setfuerzaAtaque2(45.0);
        cout << "TUS STATS HAN MEJORADO" << endl;
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

int main() {
    Jugador* jugador[2];
    jugador[0] = new Jugador(0.0, 0.0, 0.0);
    Contrincante* contrin[4];
    contrin[0] = new Bowser(50.0, 20.0, 15.0);
    contrin[1] = new Ganondorf(70.0, 15.0, 10.0, 25.0);
    contrin[2] = new Sephiroth(90.0, 15.0, 13.0, 22.0, 40.0);
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
    jugador[0]->setfuerzaAtaque1(10.0);
    jugador[0]->setfuerzaAtaque2(15.0);


    if (jugador[0]->getnivelJug() == 1) {
        cout << "BIEEEEEEENVENIDOS A LAAAA PELEA ESTELAAARRRRR!!!!" << endl;
        cout << "Ahora de la esquina izquierda tenemos a " << jugador[0]->getnombreJug() << endl;
        cout << "Yyy de la esquina derecha tenemos al rey de los Kooppas, al enemigo del reino Champinion, BOWSER!!!" << endl;
        cout << "Pelearan para ver quien es el mejor y.... PELIEN" << endl;
        cout << "Y aqui estan los stats para nuestros luchadores" << endl;

        cout << "-----------------BOWSER--------------------------" << endl;
        cout << "VIDA BOWSER: " << contrin[0]->getvidaCont() << endl;
        cout << "FUERZA BOLA DE FUEGO: " << contrin[0]->getfuerzaCont1() << endl;
        cout << "FUERZA ATAQUE DE COLA: " << contrin[0]->getfuerzaCont2() << endl;

        cout << "-----------------" << jugador[0]->getnombreJug() << "-----------" << endl;
        cout << "VIDA: " << jugador[0]->getvidaJug() << endl;
        cout << "FUERZA " << jugador[0]->getnombreAtaque1() << " : " << jugador[0]->getfuerzaAtaque1() << endl;
        cout << "FUERZA " << jugador[0]->getnombreAtaque2() << " : " << jugador[0]->getfuerzaAtaque2() << endl;
    }
        while (jugador[0]->getvidaJug() > 0 && contrin[0]->getvidaCont() > 0) {
            int contrincanteChance, jugadorChance;
            float vidaCont, vidaJug;
            string decision;
            int ataqueEnemigo, opcionAtaque;
            contrincanteChance = rand() % 2;
            jugadorChance = rand() % 3;
            ataqueEnemigo = rand() % 1;
            cout << "Que ataque quieres usar: " << endl;
            cout << "1: " << jugador[0]->getnombreAtaque1() << endl;
            cout << "2: " << jugador[0]->getnombreAtaque2() << endl;
            cin >> opcionAtaque;
            if (opcionAtaque != 1 && opcionAtaque != 2) {
                cout << "Escoge una opcion correcta" << endl;
                cin >> opcionAtaque;
            }
            if (opcionAtaque == 1) {
                if (ataqueEnemigo == 0) {
                    if (contrincanteChance == 0) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO...pero Bowser tampoco logro hacer nada" << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaCont = contrin[0]->getvidaCont() - jugador[0]->getfuerzaAtaque1();
                            contrin[0]->setvidaCont(vidaCont);
                            cout << "HAS LOGRADO ATACAR!!!, la vida de Bowser ahora es: " << contrin[0]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 1) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            vidaJug = jugador[0]->getvidaJug() - contrin[0]->getfuerzaCont1();
                            jugador[0]->setvidaJug(vidaJug);
                            cout << "TU ATAQUE HA FALLADO y peor aun BOWSER SI TE ATACO, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaJug = jugador[0]->getvidaJug() - (contrin[0]->getfuerzaCont1() / 2);
                            jugador[0]->setvidaJug(vidaJug);
                            vidaCont = contrin[0]->getvidaCont() - (jugador[0]->getfuerzaAtaque1() / 2);
                            contrin[0]->setvidaCont(vidaCont);
                            cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                            cout << "La vida de Bowser ahora es: " << contrin[0]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 2) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO, pero Bowser se estaba defendiendo así que no paso nada al final " << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            cout << "HAS LOGRADO ATACAR!!, pero Bowser se defendio, nada cambio" << endl;
                        }
                    }
                }
                else if (ataqueEnemigo == 1) {
                    if (contrincanteChance == 0) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO...pero Bowser tampoco logro hacer nada" << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaCont = contrin[0]->getvidaCont() - jugador[0]->getfuerzaAtaque1();
                            contrin[0]->setvidaCont(vidaCont);
                            cout << "HAS LOGRADO ATACAR!!!, la vida de Bowser ahora es: " << contrin[0]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 1) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            vidaJug = jugador[0]->getvidaJug() - contrin[0]->getfuerzaCont2();
                            jugador[0]->setvidaJug(vidaJug);
                            cout << "TU ATAQUE HA FALLADO y peor aun BOWSER SI TE ATACO, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaJug = jugador[0]->getvidaJug() - (contrin[0]->getfuerzaCont2() / 2);
                            jugador[0]->setvidaJug(vidaJug);
                            vidaCont = contrin[0]->getvidaCont() - (jugador[0]->getfuerzaAtaque1() / 2);
                            contrin[0]->setvidaCont(vidaCont);
                            cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                            cout << "La vida de Bowser ahora es: " << contrin[0]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 2) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO, pero Bowser se estaba defendiendo así que no paso nada al final " << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            cout << "HAS LOGRADO ATACAR!!, pero Bowser se defendio, nada cambio" << endl;
                        }
                    }
                }
            }
            else if (opcionAtaque == 2) {
                if (ataqueEnemigo == 0) {
                    if (contrincanteChance == 0) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO...pero Bowser tampoco logro hacer nada" << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaCont = contrin[0]->getvidaCont() - jugador[0]->getfuerzaAtaque2();
                            contrin[0]->setvidaCont(vidaCont);
                            cout << "HAS LOGRADO ATACAR!!!, la vida de Bowser ahora es: " << contrin[0]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 1) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            vidaJug = jugador[0]->getvidaJug() - contrin[0]->getfuerzaCont1();
                            jugador[0]->setvidaJug(vidaJug);
                            cout << "TU ATAQUE HA FALLADO y peor aun BOWSER SI TE ATACO, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaJug = jugador[0]->getvidaJug() - (contrin[0]->getfuerzaCont1() / 2);
                            jugador[0]->setvidaJug(vidaJug);
                            vidaCont = contrin[0]->getvidaCont() - (jugador[0]->getfuerzaAtaque2() / 2);
                            contrin[0]->setvidaCont(vidaCont);
                            cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                            cout << "La vida de Bowser ahora es: " << contrin[0]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 2) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO, pero Bowser se estaba defendiendo así que no paso nada al final " << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            cout << "HAS LOGRADO ATACAR!!, pero Bowser se defendio, nada cambio" << endl;
                        }
                    }
                }
                else if (ataqueEnemigo == 1) {
                    if (contrincanteChance == 0) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO...pero Bowser tampoco logro hacer nada" << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaCont = contrin[0]->getvidaCont() - jugador[0]->getfuerzaAtaque2();
                            contrin[0]->setvidaCont(vidaCont);
                            cout << "HAS LOGRADO ATACAR!!!, la vida de Bowser ahora es: " << contrin[0]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 1) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            vidaJug = jugador[0]->getvidaJug() - contrin[0]->getfuerzaCont2();
                            jugador[0]->setvidaJug(vidaJug);
                            cout << "TU ATAQUE HA FALLADO y peor aun BOWSER SI TE ATACO, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaJug = jugador[0]->getvidaJug() - (contrin[0]->getfuerzaCont2() / 2);
                            jugador[0]->setvidaJug(vidaJug);
                            vidaCont = contrin[0]->getvidaCont() - (jugador[0]->getfuerzaAtaque2() / 2);
                            contrin[0]->setvidaCont(vidaCont);
                            cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                            cout << "La vida de Bowser ahora es: " << contrin[0]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 2) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO, pero Bowser se estaba defendiendo así que no paso nada al final " << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            cout << "HAS LOGRADO ATACAR!!, pero Bowser se defendio, nada cambio" << endl;
                        }
                    }
                }
            }
            cout << "PARECE SER QUE BOWSER ESTA A PUNTO DE ATACAR, que es lo que hara " << nombreJug << endl;
            cout << "A-Atacar" << endl;
            cout << "D-Defender" << endl;
            cin >> decision;
            if (decision != "A" && decision != "D") {
                cout << "Escoge una opcion correcta" << endl;
                cin >> decision;
            }
            if (decision == "D") {
                int ataqueJugador;
                ataqueJugador = rand() % 1;
                contrin[0]->atacarJugador("D", ataqueJugador, jugador[0], contrin[0]);
            }
            else if (decision == "A") {
                int ataqueJugador;
                cout << "PARECE SER QUE " << nombreJug << " esta a punto de contraatacar, pero que ataque usara????" << endl;
                cout << "1: " << jugador[0]->getnombreAtaque1() << endl;
                cout << "2: " << jugador[0]->getnombreAtaque2() << endl;
                cin >> ataqueJugador;
                while (ataqueJugador != 1 && ataqueJugador != 2) {
                    cout << "Escoge una opcion correcta" << endl;
                    cin >> ataqueJugador;
                }
                if (ataqueJugador == 1) {
                    contrin[0]->atacarJugador("A", 1, jugador[0], contrin[0]);
                }
                else if (ataqueJugador == 2) {
                    contrin[0]->atacarJugador("A", 2, jugador[0], contrin[0]);
                }
            }
            if (contrin[0]->getvidaCont() <= 0) {
                cout << nombreJug << " HA VENCIDO AL REEEY DE LOS KOOPAS, PASAAA A LA SEGUNDA PELEA ESTELAR" << endl;
                subirNivel(jugador[0]);
            }
            if (jugador[0]->getvidaJug() <= 0) {
                cout << nombreJug << " ESTA FUEERAAAAA, SE ACABO" << endl;
                return 0;
            }
        }


    //----------------------------------------------------------------------------------------------------------------------------------

    while (jugador[0]->getnivelJug() == 2) {
        cout << "BIEEEEEEENVENIDOS A LAAAA PELEA ESTELAAARRRRR!!!!" << endl;
        cout << "Ahora de la esquina izquierda tenemos a " << jugador[0]->getnombreJug() << endl;
        cout << "Yyy de la esquina derecha tenemos al Rey Demonio, al portador de la trifuerza del poder, GANONDORF!!!" << endl;
        cout << "Pelearan para ver quien es el mejor y.... PELIEN" << endl;

        cout << "-----------------GANONDORF--------------------------" << endl;
        cout << "VIDA GANONDORF: " << contrin[1]->getvidaCont() << endl;
        cout << "FUERZA WARLOCK PUNCH: " << contrin[1]->getfuerzaCont1() << endl;
        cout << "FUERZA FLAME CHOKE: " << contrin[1]->getfuerzaCont2() << endl;
        cout << "FUERZA VOLCANO KICK: " << contrin[1]->getfuerzaCont3() << endl;

        cout << "-----------------" << jugador[0]->getnombreJug() << "-----------" << endl;
        cout << "VIDA: " << jugador[0]->getvidaJug() << endl;
        cout << "FUERZA " << jugador[0]->getnombreAtaque1() << " : " << jugador[0]->getfuerzaAtaque1() << endl;
        cout << "FUERZA " << jugador[0]->getnombreAtaque2() << " : " << jugador[0]->getfuerzaAtaque2() << endl;
        while (jugador[0]->getvidaJug() > 0 && contrin[1]->getvidaCont() > 0) {
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
                            cout << "TU ATAQUE HA FALLADO...pero Ganondorf tampoco logro hacer nada" << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaCont = contrin[1]->getvidaCont() - jugador[0]->getfuerzaAtaque1();
                            contrin[1]->setvidaCont(vidaCont);
                            cout << "HAS LOGRADO ATACAR!!!, la vida de Ganondorf ahora es: " << contrin[1]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 1) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            vidaJug = jugador[0]->getvidaJug() - contrin[1]->getfuerzaCont1();
                            jugador[0]->setvidaJug(vidaJug);
                            cout << "TU ATAQUE HA FALLADO y peor aun GANONDORF SI TE ATACO, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaJug = jugador[0]->getvidaJug() - (contrin[1]->getfuerzaCont1() / 2);
                            jugador[0]->setvidaJug(vidaJug);
                            vidaCont = contrin[1]->getvidaCont() - (jugador[0]->getfuerzaAtaque1() / 2);
                            contrin[1]->setvidaCont(vidaCont);
                            cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                            cout << "La vida de Ganondorf ahora es: " << contrin[1]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 2) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO, pero Ganondorf se estaba defendiendo así que no paso nada al final " << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            cout << "HAS LOGRADO ATACAR!!, pero Ganondorf se defendio, nada cambio" << endl;
                        }
                    }
                }

                else if (ataqueEnemigo == 1) {
                    if (contrincanteChance == 0) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO...pero Ganondorf tampoco logro hacer nada" << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaCont = contrin[1]->getvidaCont() - jugador[0]->getfuerzaAtaque1();
                            contrin[1]->setvidaCont(vidaCont);
                            cout << "HAS LOGRADO ATACAR!!!, la vida de Ganondorf ahora es: " << contrin[1]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 1) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            vidaJug = jugador[0]->getvidaJug() - contrin[1]->getfuerzaCont2();
                            jugador[0]->setvidaJug(vidaJug);
                            cout << "TU ATAQUE HA FALLADO y peor aun GANONDORF SI TE ATACO, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaJug = jugador[0]->getvidaJug() - (contrin[1]->getfuerzaCont2() / 2);
                            jugador[0]->setvidaJug(vidaJug);
                            vidaCont = contrin[1]->getvidaCont() - (jugador[0]->getfuerzaAtaque1() / 2);
                            contrin[1]->setvidaCont(vidaCont);
                            cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                            cout << "La vida de Ganondorf ahora es: " << contrin[1]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 2) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO, pero Ganondorf se estaba defendiendo así que no paso nada al final " << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            cout << "HAS LOGRADO ATACAR!!, pero Ganondorf se defendio, nada cambio" << endl;
                        }
                    }
                }

                else if (ataqueEnemigo == 2) {
                    if (contrincanteChance == 0) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO...pero Ganondorf tampoco logro hacer nada" << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaCont = contrin[1]->getvidaCont() - jugador[0]->getfuerzaAtaque1();
                            contrin[1]->setvidaCont(vidaCont);
                            cout << "HAS LOGRADO ATACAR!!!, la vida de Ganondorf ahora es: " << contrin[1]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 1) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            vidaJug = jugador[0]->getvidaJug() - contrin[1]->getfuerzaCont3();
                            jugador[0]->setvidaJug(vidaJug);
                            cout << "TU ATAQUE HA FALLADO y peor aun GANONDORF SI TE ATACO, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaJug = jugador[0]->getvidaJug() - (contrin[1]->getfuerzaCont3() / 2);
                            jugador[0]->setvidaJug(vidaJug);
                            vidaCont = contrin[1]->getvidaCont() - (jugador[0]->getfuerzaAtaque1() / 2);
                            contrin[1]->setvidaCont(vidaCont);
                            cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                            cout << "La vida de Ganondorf ahora es: " << contrin[1]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 2) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO, pero Ganondorf se estaba defendiendo así que no paso nada al final " << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            cout << "HAS LOGRADO ATACAR!!, pero Ganondorf se defendio, nada cambio" << endl;
                        }
                    }
                }
            }

            else if (opcionAtaque == 2) {

                if (ataqueEnemigo == 0) {
                    if (contrincanteChance == 0) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO...pero Ganondorf tampoco logro hacer nada" << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaCont = contrin[1]->getvidaCont() - jugador[0]->getfuerzaAtaque2();
                            contrin[1]->setvidaCont(vidaCont);
                            cout << "HAS LOGRADO ATACAR!!!, la vida de Ganondorf ahora es: " << contrin[1]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 1) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            vidaJug = jugador[0]->getvidaJug() - contrin[1]->getfuerzaCont1();
                            jugador[0]->setvidaJug(vidaJug);
                            cout << "TU ATAQUE HA FALLADO y peor aun GANONDORF SI TE ATACO, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaJug = jugador[0]->getvidaJug() - (contrin[1]->getfuerzaCont1() / 2);
                            jugador[0]->setvidaJug(vidaJug);
                            vidaCont = contrin[1]->getvidaCont() - (jugador[0]->getfuerzaAtaque2() / 2);
                            contrin[1]->setvidaCont(vidaCont);
                            cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                            cout << "La vida de Ganondorf ahora es: " << contrin[1]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 2) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO, pero Ganondorf se estaba defendiendo así que no paso nada al final " << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            cout << "HAS LOGRADO ATACAR!!, pero Ganondorf se defendio, nada cambio" << endl;
                        }
                    }
                }

                else if (ataqueEnemigo == 1) {
                    if (contrincanteChance == 0) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO...pero Ganondorf tampoco logro hacer nada" << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaCont = contrin[1]->getvidaCont() - jugador[0]->getfuerzaAtaque2();
                            contrin[1]->setvidaCont(vidaCont);
                            cout << "HAS LOGRADO ATACAR!!!, la vida de Ganondorf ahora es: " << contrin[1]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 1) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            vidaJug = jugador[0]->getvidaJug() - contrin[1]->getfuerzaCont2();
                            jugador[0]->setvidaJug(vidaJug);
                            cout << "TU ATAQUE HA FALLADO y peor aun GANONDORF SI TE ATACO, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaJug = jugador[0]->getvidaJug() - (contrin[1]->getfuerzaCont2() / 2);
                            jugador[0]->setvidaJug(vidaJug);
                            vidaCont = contrin[1]->getvidaCont() - (jugador[0]->getfuerzaAtaque2() / 2);
                            contrin[1]->setvidaCont(vidaCont);
                            cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                            cout << "La vida de Ganondorf ahora es: " << contrin[1]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 2) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO, pero Ganondorf se estaba defendiendo así que no paso nada al final " << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            cout << "HAS LOGRADO ATACAR!!, pero Ganondorf se defendio, nada cambio" << endl;
                        }
                    }
                }

                else if (ataqueEnemigo == 2) {
                    if (contrincanteChance == 0) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO...pero Ganondorf tampoco logro hacer nada" << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaCont = contrin[1]->getvidaCont() - jugador[0]->getfuerzaAtaque2();
                            contrin[1]->setvidaCont(vidaCont);
                            cout << "HAS LOGRADO ATACAR!!!, la vida de Ganondorf ahora es: " << contrin[1]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 1) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            vidaJug = jugador[0]->getvidaJug() - contrin[1]->getfuerzaCont3();
                            jugador[0]->setvidaJug(vidaJug);
                            cout << "TU ATAQUE HA FALLADO y peor aun GANONDORF SI TE ATACO, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaJug = jugador[0]->getvidaJug() - (contrin[1]->getfuerzaCont3() / 2);
                            jugador[0]->setvidaJug(vidaJug);
                            vidaCont = contrin[1]->getvidaCont() - (jugador[0]->getfuerzaAtaque2() / 2);
                            contrin[1]->setvidaCont(vidaCont);
                            cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                            cout << "La vida de Ganondorf ahora es: " << contrin[1]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 2) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO, pero Ganondorf se estaba defendiendo así que no paso nada al final " << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            cout << "HAS LOGRADO ATACAR!!, pero Ganondorf se defendio, nada cambio" << endl;
                        }
                    }
                }
            }
            if (contrin[1]->getvidaCont() <= 0) {
                cout << nombreJug << " HA VENCIDO AL REY DEMONIO, PASAAA A LA SEGUNDA PELEA ESTELAR" << endl;
                subirNivel(jugador[0]);
            }
            if (jugador[0]->getvidaJug() <= 0) {
                cout << nombreJug << " ESTA FUEERAAAAA, SE ACABO" << endl;
                return 0;
            }
            cout << "PARECE SER QUE GANON ESTA A PUNTO DE ATACAR, que es lo que hara " << nombreJug << endl;
            cout << "A-Atacar" << endl;
            cout << "D-Defender" << endl;
            cin >> decision;
            while (decision != "A" && decision != "D") {
                cout << "Escoge una opcion correcta" << endl;
                cin >> decision;
            }
            if (decision == "D") {
                int ataqueJugador;
                ataqueJugador = rand() % 1;
                contrin[1]->atacarJugador("D", ataqueJugador, jugador[0], contrin[1]);
            }
            else if (decision == "A") {
                int ataqueJugador;
                cout << "PARECE SER QUE " << nombreJug << " esta a punto de contraatacar, pero que ataque usara????" << endl;
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
                cout << nombreJug << " HA VENCIDO AL REY DEMONIO, PASAAA A LA SEGUNDA PELEA ESTELAR" << endl;
                subirNivel(jugador[0]);
            }
            if (jugador[0]->getvidaJug() <= 0) {
                cout << nombreJug << " ESTA FUEERAAAAA, SE ACABO" << endl;
                return 0;
            }
        }
    }


    while (jugador[0]->getnivelJug() == 3) {
        cout << "BIEEEEEEENVENIDOS A LAAAA PELEA ESTELAAARRRRR!!!!" << endl;
        cout << "Ahora de la esquina izquierda tenemos a " << jugador[0]->getnombreJug() << endl;
        cout << "Yyy de la esquina derecha tenemos al Angel de un ala, al Angel de la muerte, SEPHIROTH!!!" << endl;
        cout << "Pelearan para ver quien es el mejor y.... PELIEN" << endl;

        cout << "-----------------SEPHIROTH--------------------------" << endl;
        cout << "VIDA SEPHIROTH: " << contrin[2]->getvidaCont() << endl;
        cout << "FUERZA MASAMUNE: " << contrin[2]->getfuerzaCont1() << endl;
        cout << "FUERZA SHADOW FLARE: " << contrin[2]->getfuerzaCont2() << endl;
        cout << "FUERZA OCTASLASH: " << contrin[2]->getfuerzaCont3() << endl;
        cout << "FUERZA SUPER NOVA: " << contrin[2]->getfuerzaCont4() << endl;

        cout << "-----------------" << jugador[0]->getnombreJug() << "-----------" << endl;
        cout << "VIDA: " << jugador[0]->getvidaJug() << endl;
        cout << "FUERZA " << jugador[0]->getnombreAtaque1() << " : " << jugador[0]->getfuerzaAtaque1() << endl;
        cout << "FUERZA " << jugador[0]->getnombreAtaque2() << " : " << jugador[0]->getfuerzaAtaque2() << endl;

        while (jugador[0]->getvidaJug() > 0 && contrin[1]->getvidaCont() > 0) {
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
                            cout << "TU ATAQUE HA FALLADO...pero Sephiroth tampoco logro hacer nada" << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaCont = contrin[2]->getvidaCont() - jugador[0]->getfuerzaAtaque1();
                            contrin[2]->setvidaCont(vidaCont);
                            cout << "HAS LOGRADO ATACAR!!!, la vida de Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 1) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            vidaJug = jugador[0]->getvidaJug() - contrin[2]->getfuerzaCont1();
                            jugador[0]->setvidaJug(vidaJug);
                            cout << "TU ATAQUE HA FALLADO y peor aun SEPHIROTH SI TE ATACO, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaJug = jugador[0]->getvidaJug() - (contrin[2]->getfuerzaCont1() / 2);
                            jugador[0]->setvidaJug(vidaJug);
                            vidaCont = contrin[2]->getvidaCont() - (jugador[0]->getfuerzaAtaque1() / 2);
                            contrin[2]->setvidaCont(vidaCont);
                            cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                            cout << "La vida de Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 2) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO, pero Sephiroth se estaba defendiendo así que no paso nada al final " << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            cout << "HAS LOGRADO ATACAR!!, pero Sephiroth se defendio, nada cambio" << endl;
                        }
                    }
                }

                else if (ataqueEnemigo == 1) {
                    if (contrincanteChance == 0) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO...pero Sephiroth tampoco logro hacer nada" << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaCont = contrin[2]->getvidaCont() - jugador[0]->getfuerzaAtaque1();
                            contrin[2]->setvidaCont(vidaCont);
                            cout << "HAS LOGRADO ATACAR!!!, la vida de Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 1) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            vidaJug = jugador[0]->getvidaJug() - contrin[2]->getfuerzaCont2();
                            jugador[0]->setvidaJug(vidaJug);
                            cout << "TU ATAQUE HA FALLADO y peor aun SEPHIROTH SI TE ATACO, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaJug = jugador[0]->getvidaJug() - (contrin[2]->getfuerzaCont2() / 2);
                            jugador[0]->setvidaJug(vidaJug);
                            vidaCont = contrin[2]->getvidaCont() - (jugador[0]->getfuerzaAtaque1() / 2);
                            contrin[2]->setvidaCont(vidaCont);
                            cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                            cout << "La vida de Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 2) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO, pero Sephiroth se estaba defendiendo así que no paso nada al final " << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            cout << "HAS LOGRADO ATACAR!!, pero Sephiroth se defendio, nada cambio" << endl;
                        }
                    }
                }

                else if (ataqueEnemigo == 2) {
                    if (contrincanteChance == 0) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO...pero Sephiroth tampoco logro hacer nada" << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaCont = contrin[2]->getvidaCont() - jugador[0]->getfuerzaAtaque1();
                            contrin[2]->setvidaCont(vidaCont);
                            cout << "HAS LOGRADO ATACAR!!!, la vida de Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 1) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            vidaJug = jugador[0]->getvidaJug() - contrin[2]->getfuerzaCont3();
                            jugador[0]->setvidaJug(vidaJug);
                            cout << "TU ATAQUE HA FALLADO y peor aun SEPHIROTH SI TE ATACO, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaJug = jugador[0]->getvidaJug() - (contrin[2]->getfuerzaCont3() / 2);
                            jugador[0]->setvidaJug(vidaJug);
                            vidaCont = contrin[2]->getvidaCont() - (jugador[0]->getfuerzaAtaque1() / 2);
                            contrin[2]->setvidaCont(vidaCont);
                            cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                            cout << "La vida de Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 2) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO, pero Sephiroth se estaba defendiendo así que no paso nada al final " << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            cout << "HAS LOGRADO ATACAR!!, pero Sephiroth se defendio, nada cambio" << endl;
                        }
                    }
                }

                else if (ataqueEnemigo == 3) {
                    if (contrincanteChance == 0) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO...pero Sephiroth tampoco logro hacer nada" << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaCont = contrin[2]->getvidaCont() - jugador[0]->getfuerzaAtaque1();
                            contrin[2]->setvidaCont(vidaCont);
                            cout << "HAS LOGRADO ATACAR!!!, la vida de Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 1) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            vidaJug = jugador[0]->getvidaJug() - contrin[2]->getfuerzaCont4();
                            jugador[0]->setvidaJug(vidaJug);
                            cout << "TU ATAQUE HA FALLADO y peor aun SEPHIROTH SI TE ATACO, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaJug = jugador[0]->getvidaJug() - (contrin[2]->getfuerzaCont4() / 2);
                            jugador[0]->setvidaJug(vidaJug);
                            vidaCont = contrin[2]->getvidaCont() - (jugador[0]->getfuerzaAtaque1() / 2);
                            contrin[2]->setvidaCont(vidaCont);
                            cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                            cout << "La vida de Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 2) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO, pero Sephiroth se estaba defendiendo así que no paso nada al final " << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            cout << "HAS LOGRADO ATACAR!!, pero Sephiroth se defendio, nada cambio" << endl;
                        }
                    }
                }
            }

            else if (opcionAtaque == 2) {
                if (ataqueEnemigo == 0) {
                    if (contrincanteChance == 0) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO...pero Sephiroth tampoco logro hacer nada" << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaCont = contrin[2]->getvidaCont() - jugador[0]->getfuerzaAtaque2();
                            contrin[2]->setvidaCont(vidaCont);
                            cout << "HAS LOGRADO ATACAR!!!, la vida de Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 1) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            vidaJug = jugador[0]->getvidaJug() - contrin[2]->getfuerzaCont1();
                            jugador[0]->setvidaJug(vidaJug);
                            cout << "TU ATAQUE HA FALLADO y peor aun SEPHIROTH SI TE ATACO, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaJug = jugador[0]->getvidaJug() - (contrin[2]->getfuerzaCont1() / 2);
                            jugador[0]->setvidaJug(vidaJug);
                            vidaCont = contrin[2]->getvidaCont() - (jugador[0]->getfuerzaAtaque2() / 2);
                            contrin[2]->setvidaCont(vidaCont);
                            cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                            cout << "La vida de Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 2) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO, pero Sephiroth se estaba defendiendo así que no paso nada al final " << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            cout << "HAS LOGRADO ATACAR!!, pero Sephiroth se defendio, nada cambio" << endl;
                        }
                    }
                }

                else if (ataqueEnemigo == 1) {
                    if (contrincanteChance == 0) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO...pero Sephiroth tampoco logro hacer nada" << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaCont = contrin[2]->getvidaCont() - jugador[0]->getfuerzaAtaque2();
                            contrin[2]->setvidaCont(vidaCont);
                            cout << "HAS LOGRADO ATACAR!!!, la vida de Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 1) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            vidaJug = jugador[0]->getvidaJug() - contrin[2]->getfuerzaCont2();
                            jugador[0]->setvidaJug(vidaJug);
                            cout << "TU ATAQUE HA FALLADO y peor aun SEPHIROTH SI TE ATACO, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaJug = jugador[0]->getvidaJug() - (contrin[2]->getfuerzaCont2() / 2);
                            jugador[0]->setvidaJug(vidaJug);
                            vidaCont = contrin[2]->getvidaCont() - (jugador[0]->getfuerzaAtaque2() / 2);
                            contrin[2]->setvidaCont(vidaCont);
                            cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                            cout << "La vida de Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 2) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO, pero Sephiroth se estaba defendiendo así que no paso nada al final " << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            cout << "HAS LOGRADO ATACAR!!, pero Sephiroth se defendio, nada cambio" << endl;
                        }
                    }
                }

                else if (ataqueEnemigo == 2) {
                    if (contrincanteChance == 0) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO...pero Sephiroth tampoco logro hacer nada" << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaCont = contrin[2]->getvidaCont() - jugador[0]->getfuerzaAtaque2();
                            contrin[2]->setvidaCont(vidaCont);
                            cout << "HAS LOGRADO ATACAR!!!, la vida de Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 1) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            vidaJug = jugador[0]->getvidaJug() - contrin[2]->getfuerzaCont3();
                            jugador[0]->setvidaJug(vidaJug);
                            cout << "TU ATAQUE HA FALLADO y peor aun SEPHIROTH SI TE ATACO, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaJug = jugador[0]->getvidaJug() - (contrin[2]->getfuerzaCont3() / 2);
                            jugador[0]->setvidaJug(vidaJug);
                            vidaCont = contrin[2]->getvidaCont() - (jugador[0]->getfuerzaAtaque2() / 2);
                            contrin[2]->setvidaCont(vidaCont);
                            cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                            cout << "La vida de Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 2) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO, pero Sephiroth se estaba defendiendo así que no paso nada al final " << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            cout << "HAS LOGRADO ATACAR!!, pero Sephiroth se defendio, nada cambio" << endl;
                        }
                    }
                }

                else if (ataqueEnemigo == 3) {
                    if (contrincanteChance == 0) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO...pero Sephiroth tampoco logro hacer nada" << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaCont = contrin[2]->getvidaCont() - jugador[0]->getfuerzaAtaque2();
                            contrin[2]->setvidaCont(vidaCont);
                            cout << "HAS LOGRADO ATACAR!!!, la vida de Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 1) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            vidaJug = jugador[0]->getvidaJug() - contrin[2]->getfuerzaCont4();
                            jugador[0]->setvidaJug(vidaJug);
                            cout << "TU ATAQUE HA FALLADO y peor aun SEPHIROTH SI TE ATACO, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            vidaJug = jugador[0]->getvidaJug() - (contrin[2]->getfuerzaCont4() / 2);
                            jugador[0]->setvidaJug(vidaJug);
                            vidaCont = contrin[2]->getvidaCont() - (jugador[0]->getfuerzaAtaque2() / 2);
                            contrin[2]->setvidaCont(vidaCont);
                            cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << jugador[0]->getvidaJug() << endl;
                            cout << "La vida de Sephiroth ahora es: " << contrin[2]->getvidaCont() << endl;
                        }
                    }
                    else if (contrincanteChance == 2) {
                        if (jugadorChance == 2 || jugadorChance == 3) {
                            cout << "TU ATAQUE HA FALLADO, pero Sephiroth se estaba defendiendo así que no paso nada al final " << endl;
                        }
                        else if (jugadorChance == 0 || jugadorChance == 1) {
                            cout << "HAS LOGRADO ATACAR!!, pero Sephiroth se defendio, nada cambio" << endl;
                        }
                    }
                }
            }
            if (contrin[2]->getvidaCont() <= 0) {
                cout << nombreJug << " HA VENCIDO AL ANGEL DE UN ALA,LO HA GANADO TODO DAMAS Y SEÑORES, " << nombreJug << " ES NUESTRO CAMPION" << endl;
                cout << "ERES EL CAMPION" << endl;
                return 0;
            }

            if (jugador[0]->getvidaJug() <= 0) {
                cout << nombreJug << " ESTA FUEERAAAAA, SE ACABO" << endl;
                return 0;
            }
            cout << "PARECE SER QUE SEPHIROTH ESTA A PUNTO DE ATACAR, que es lo que hara " << nombreJug << endl;
            cout << "A-Atacar" << endl;
            cout << "D-Defender" << endl;
            cin >> decision;
            while (decision != "A" && decision != "D") {
                cout << "Escoge una opcion correcta" << endl;
                cin >> decision;
            }
            if (decision == "D") {
                int ataqueJugador;
                ataqueJugador = rand() % 1;
                contrin[2]->atacarJugador("D", ataqueJugador, jugador[0], contrin[2]);
            }
            else if (decision == "A") {
                int ataqueJugador;
                cout << "PARECE SER QUE " << nombreJug << " esta a punto de contraatacar, pero que ataque usara????" << endl;
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
                cout << nombreJug << " HA VENCIDO AL ANGEL DE UN ALA,LO HA GANADO TODO DAMAS Y SEÑORES, " << nombreJug << " ES NUESTRO CAMPION" << endl;
                cout << "ERES EL CAMPION" << endl;
                return 0;
            }

            if (jugador[0]->getvidaJug() <= 0) {
                cout << nombreJug << " ESTA FUEERAAAAA, SE ACABO" << endl;
                return 0;
            }
        }
    }
}