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

Jugador jugador;
Ganondorf ganon;
Sephiroth sephiroth;
Contrincante* contrin[2];
Contrincante* bowser= contrin[0] = new Bowser(30.0, 20.0, 15.0);


void subirNivel();
void turnoJugador();
void turnoContrincante();

void subirNivel() {
    int nivel;
    nivel = jugador.getnivelJug();
    if (nivel == 1) {
        jugador.setnivelJug(2);
        jugador.setvidaJug(45.0);
        jugador.setfuerzaAtaque1(20.0);
        jugador.setfuerzaAtaque2(25.0);
    }
    if (nivel == 2) {
        jugador.setnivelJug(3);
        jugador.setvidaJug(60.0);
        jugador.setfuerzaAtaque1(30.0);
        jugador.setfuerzaAtaque2(45.0);
    }
}

void turnoJugador() {
    string nombreJug;
    int opcionAtaque, nivelJug;
    float  vidaJug, fuerza1, fuerza2;
    nombreJug = jugador.getnombreJug();
    vidaJug = jugador.getvidaJug();
    fuerza1 = jugador.getfuerzaAtaque1();
    fuerza2 = jugador.getfuerzaAtaque2();
    nivelJug = jugador.getnivelJug();
    if (nivelJug == 1) {
        float vidaBowser, fuerzaBola, fuerzaCola;
        int ataqueEnemigo;
        cout << "Que ataque quieres usar: " << endl;
        cout << "1: " << jugador.getnombreAtaque1() << endl;
        cout << "2: " << jugador.getnombreAtaque2() << endl;
        cin >> opcionAtaque;
        if (opcionAtaque != 1 && opcionAtaque != 2) {
            cout << "Escoge una opcion correcta" << endl;
            turnoJugador();
        }
        vidaBowser = bowser -> getvidaCont();
        fuerzaBola = bowser -> getfuerzaCont1();
        fuerzaCola = bowser -> getfuerzaCont2();
        ataqueEnemigo = rand() % 1;
        if (opcionAtaque == 1) {
            if (ataqueEnemigo == 0) {
                jugador.atacarContrincante(fuerza1, fuerzaBola, vidaBowser, jugador);
            }
            else if (ataqueEnemigo == 1) {
                jugador.atacarContrincante(fuerza1, fuerzaCola, vidaBowser, jugador);
            }
        }
        else if (opcionAtaque == 2) {
            if (ataqueEnemigo == 0) {
                jugador.atacarContrincante(fuerza2, fuerzaBola, vidaBowser, jugador);
            }
            else if (ataqueEnemigo == 1) {
                jugador.atacarContrincante(fuerza2, fuerzaCola, vidaBowser, jugador);
            }
        }
        if (vidaBowser <= 0) {
            cout << nombreJug << " HA VENCIDO AL REEEY DE LOS KOOPAS, PASAAA A LA SEGUNDA PELEA ESTELAR" << endl;
            subirNivel();
        }
    }

    if (nivelJug == 2) {
        float vidaGanon, fuerzaWarlock, fuerzaFlame, fuerzaVolcano;
        int ataqueEnemigo;
        cout << "Que ataque quieres usar: " << endl;
        cout << "1: " << jugador.getnombreAtaque1() << endl;
        cout << "2: " << jugador.getnombreAtaque2() << endl;
        cin >> opcionAtaque;
        if (opcionAtaque != 1 && opcionAtaque != 2) {
            cout << "Escoge una opcion correcta" << endl;
            turnoJugador();
        }
        vidaGanon = ganon.getvidaGanon();
        fuerzaWarlock = ganon.getfuerzaWarlock();
        fuerzaFlame = ganon.getfuerzaFlame();
        fuerzaVolcano = ganon.getfuerzaVolcano();
        ataqueEnemigo = rand() % 2;
        if (opcionAtaque == 1) {
            if (ataqueEnemigo == 1) {
                jugador.atacarContrincante(fuerza1, fuerzaWarlock, vidaGanon, jugador);
            }
            else if (ataqueEnemigo == 2) {
                jugador.atacarContrincante(fuerza1, fuerzaFlame, vidaGanon, jugador);
            }
            else if (ataqueEnemigo == 3) {
                jugador.atacarContrincante(fuerza1, fuerzaVolcano, vidaGanon, jugador);
            }
        }
        else if (opcionAtaque == 2) {
            if (ataqueEnemigo == 1) {
                jugador.atacarContrincante(fuerza2, fuerzaWarlock, vidaGanon, jugador);
            }
            else if (ataqueEnemigo == 2) {
                jugador.atacarContrincante(fuerza2, fuerzaFlame, vidaGanon, jugador);
            }
            else if (ataqueEnemigo == 3) {
                jugador.atacarContrincante(fuerza2, fuerzaVolcano, vidaGanon, jugador);
            }
        }
        if (vidaGanon <= 0) {
            cout << nombreJug << " HA VENCIDO AL REY DEMONIO, PASAAA A LA SEGUNDA PELEA ESTELAR" << endl;
            subirNivel();
        }
    }

    if (nivelJug == 3) {
        float vidaSephiroth, fuerzaMasamune, fuerzaShadow, fuerzaOctaslash, fuerzaNova;
        int ataqueEnemigo;
        cout << "Que ataque quieres usar: " << endl;
        cout << "1: " << jugador.getnombreAtaque1() << endl;
        cout << "2: " << jugador.getnombreAtaque2() << endl;
        cin >> opcionAtaque;
        if (opcionAtaque != 1 && opcionAtaque != 2) {
            cout << "Escoge una opcion correcta" << endl;
            turnoJugador();
        }
        vidaSephiroth = sephiroth.getvidaSephiroth();
        fuerzaMasamune = sephiroth.getfuerzaMasamune();
        fuerzaShadow = sephiroth.getfuerzaShadow();
        fuerzaOctaslash = sephiroth.getfuerzaOctaslash();
        fuerzaNova = sephiroth.getfuerzaNova();
        ataqueEnemigo = rand() % 3;
        if (opcionAtaque == 1) {
            if (ataqueEnemigo == 1) {
                jugador.atacarContrincante(fuerza1, fuerzaMasamune, vidaSephiroth, jugador);
            }
            else if (ataqueEnemigo == 2) {
                jugador.atacarContrincante(fuerza1, fuerzaShadow, vidaSephiroth, jugador);
            }
            else if (ataqueEnemigo == 3) {
                jugador.atacarContrincante(fuerza1, fuerzaOctaslash, vidaSephiroth, jugador);
            }
            else if (ataqueEnemigo == 4) {
                jugador.atacarContrincante(fuerza1, fuerzaNova, vidaSephiroth, jugador);
            }
        }
        else if (opcionAtaque == 2) {
            if (ataqueEnemigo == 1) {
                jugador.atacarContrincante(fuerza2, fuerzaMasamune, vidaSephiroth, jugador);
            }
            else if (ataqueEnemigo == 2) {
                jugador.atacarContrincante(fuerza2, fuerzaShadow, vidaSephiroth, jugador);
            }
            else if (ataqueEnemigo == 3) {
                jugador.atacarContrincante(fuerza2, fuerzaOctaslash, vidaSephiroth, jugador);
            }
            else if (ataqueEnemigo == 4) {
                jugador.atacarContrincante(fuerza2, fuerzaNova, vidaSephiroth, jugador);
            }

        }
        if (vidaSephiroth <= 0) {
            cout << nombreJug << " HA VENCIDO AL ANGEL DE UN ALA,LO HA GANADO TODO DAMAS Y SEÑORES, " << nombreJug << " ES NUESTRO CAMPION" << endl;
        }
    }
}

void turnoContrincante() {
    string nombreJug;
    float vidaJug, fuerza1, fuerza2,vidaCont;
    nombreJug = jugador.getnombreJug();
    vidaJug = jugador.getvidaJug();
    fuerza1 = jugador.getfuerzaAtaque1();
    fuerza2 = jugador.getfuerzaAtaque2();
    if (jugador.getnivelJug() == 1) {
        cout << "PARECE SER QUE BOWSER ESTA A PUNTO DE ATACAR, que es lo que hara " << nombreJug << endl;
        cout << "A-Atacar" << endl;
        cout << "D-Defender" << endl;
        string decision;
        cin >> decision;
        vidaCont = bowser->getvidaCont();
        if (decision != "A" && decision != "D") {
            cout << "Escoge una opcion correcta" << endl;
            turnoContrincante();
        }
        if (decision == "D") {
            int aj;
            aj = rand() % 1;
            bowser->atacarJugador("D", aj, jugador);
        }
        if (decision == "A") {
            int aj;
            cout << "PARECE SER QUE " << nombreJug << " esta a punto de contraatacar, pero que ataque usara????" << endl;
            cout << "1: " << jugador.getnombreAtaque1() << endl;
            cout << "2: " << jugador.getnombreAtaque2() << endl;
            cin >> aj;
            if (aj == 1) {
                bowser->atacarJugador("A", 1, jugador);
            }
            if (aj == 2) {
                bowser->atacarJugador("A", 2, jugador);
            }
        }
        if (vidaCont <= 0) {
            cout << nombreJug << " HA VENCIDO AL REEEY DE LOS KOOPAS, PASAAA A LA SEGUNDA PELEA ESTELAR" << endl;
            subirNivel();
        }
    }

    else if (jugador.getnivelJug() == 2) {
        cout << "PARECE SER QUE GANON ESTA A PUNTO DE ATACAR, que es lo que hara " << nombreJug << endl;
        cout << "A-Atacar" << endl;
        cout << "D-Defender" << endl;
        string decision;
        cin >> decision;
        if (decision != "A" && decision != "D") {
            cout << "Escoge una opcion correcta" << endl;
            turnoContrincante();
        }
        contrin[1] = new Ganondorf(40.0, 15.0, 10.0, 25.0);
        vidaCont = contrin[1]->getvidaCont();
        if (decision == "D") {
            int aj;
            aj = rand() % 1;
            contrin[1]->atacarJugador("D", aj, jugador);
        }
        if (decision == "A") {
            int aj;
            cout << "PARECE SER QUE " << nombreJug << " esta a punto de contraatacar, pero que ataque usara????" << endl;
            cout << "1: " << jugador.getnombreAtaque1() << endl;
            cout << "2: " << jugador.getnombreAtaque2() << endl;
            cin >> aj;
            if (aj == 1) {
                contrin[1]->atacarJugador("A", 1, jugador);
            }
            if (aj == 2) {
                contrin[1]->atacarJugador("A", 2, jugador);
            }
        }
        if (vidaCont <= 0) {
            cout << nombreJug << " HA VENCIDO AL REY DEMONIO, PASAAA A LA SEGUNDA PELEA ESTELAR" << endl;
            subirNivel();
        }
    }

    else if (jugador.getnivelJug() == 3) {
        cout << "PARECE SER QUE SEPHIROTH ESTA A PUNTO DE ATACAR, que es lo que hara " << nombreJug << endl;
        cout << "A-Atacar" << endl;
        cout << "D-Defender" << endl;
        string decision;
        cin >> decision;
        if (decision != "A" && decision != "D") {
            cout << "Escoge una opcion correcta" << endl;
            turnoContrincante();
        }
        contrin[2] = new Sephiroth(60.0, 15.0, 13.0, 22.0, 40.0);
        vidaCont = contrin[2]->getvidaCont();
        if (decision == "D") {
            int aj;
            aj = rand() % 1;
            contrin[2]->atacarJugador("D", aj, jugador);
        }
        if (decision == "A") {
            int aj;
            cout << "PARECE SER QUE " << nombreJug << " esta a punto de contraatacar, pero que ataque usara????" << endl;
            cout << "1: " << jugador.getnombreAtaque1() << endl;
            cout << "2: " << jugador.getnombreAtaque2() << endl;
            cin >> aj;
            if (aj == 1) {
                contrin[2]->atacarJugador("A", 1, jugador);
            }
            if (aj == 2) {
                contrin[2]->atacarJugador("A", 2, jugador);
            }
        }
        if (vidaCont <= 0) {
            cout << nombreJug << " HA VENCIDO AL ANGEL DE UN ALA,LO HA GANADO TODO DAMAS Y SEÑORES, " << nombreJug << " ES NUESTRO CAMPION" << endl;
            subirNivel();
        }
    }
}

int main()
{
    string nombreJug, nombreAtaque1, nombreAtaque2;
    cout << "Ingresa el nombre de tu jugador: ";
    cin >> nombreJug;
    jugador.setnombreJug(nombreJug);
    cout << endl;
    cout << "Como quieres que se llame tu primer ataque: ";
    cin >> nombreAtaque1;
    jugador.setnombreAtaque1(nombreAtaque1);
    cout << endl;
    cout << "Como quieres que se llame tu segundo ataque: ";
    cin >> nombreAtaque2;
    jugador.setnombreAtaque2(nombreAtaque2);
    cout << endl;
    jugador.setnivelJug(1);
    jugador.setvidaJug(35.0);
    jugador.setfuerzaAtaque1(10.0);
    jugador.setfuerzaAtaque2(15.0);
    if (jugador.getnivelJug() == 1) {
        cout << "BIEEEEEEENVENIDOS A LAAAA PELEA ESTELAAARRRRR!!!!" << endl;
        cout << "Ahora de la esquina izquierda tenemos a " << jugador.getnombreJug() << endl;
        cout << "Yyy de la esquina derecha tenemos al rey de los Kooppas, al enemigo del reino Champinion, BOWSER!!!" << endl;
        cout << "Pelearan para ver quien es el mejor y.... PELIEN" << endl;
        cout << "Y aqui estan los stats para nuestros luchadores" << endl;
        cout << "-----------------BOWSER--------------------------" << endl;
        cout << "VIDA BOWSER: " << bowser->getvidaCont() << endl;
        cout << "FUERZA BOLA DE FUEGO: " << bowser->getfuerzaCont1() << endl;
        cout << "FUERZA ATAQUE DE COLA: " << bowser->getfuerzaCont2() << endl;
    }
    if (jugador.getnivelJug() == 2) {
        cout << "BIEEEEEEENVENIDOS A LAAAA PELEA ESTELAAARRRRR!!!!" << endl;
        cout << "Ahora de la esquina izquierda tenemos a " << jugador.getnombreJug() << endl;
        cout << "Yyy de la esquina derecha tenemos al Rey Demonio, al portador de la trifuerza del poder, GANONDORF!!!" << endl;
        cout << "Pelearan para ver quien es el mejor y.... PELIEN" << endl;
    }
    if (jugador.getnivelJug() == 3) {
        cout << "BIEEEEEEENVENIDOS A LAAAA PELEA ESTELAAARRRRR!!!!" << endl;
        cout << "Ahora de la esquina izquierda tenemos a " << jugador.getnombreJug() << endl;
        cout << "Yyy de la esquina derecha tenemos al Angel de un ala, al Angel de la muerte, SEPHIROTH!!!" << endl;
        cout << "Pelearan para ver quien es el mejor y.... PELIEN" << endl;
    }
    while (jugador.getvidaJug() > 0) {
        turnoJugador();
        if (jugador.getvidaJug() <= 0) {
            cout << "JUEGO TERMINADO" << endl;
            return 0;
        }
        turnoContrincante();
        if (jugador.getvidaJug() <= 0) {
            cout << "JUEGO TERMINADO" << endl;
            return 0;
        }   
    }
}
