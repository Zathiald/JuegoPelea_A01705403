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
Bowser bowser;
Ganondorf ganon;
Sephiroth sephiroth;
Contrincante* contrin[2];

void crearJugador();
void subirNivel();
void turnoJugador();
void turnoContrincante();
void pelea();

void crearJugador() {
    string nombreJug,nombreAtaque1,nombreAtaque2;
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
    jugador.setvidaJug(20.0);
    jugador.setfuerzaAtaque1(10.0);
    jugador.setfuerzaAtaque2(15.0);
}

void subirNivel() {  
    int nivel;
    nivel = jugador.getnivelJug();
    if (nivel == 1) {
        jugador.setnivelJug(2);
        jugador.setvidaJug(30.0);
        jugador.setfuerzaAtaque1(20.0);
        jugador.setfuerzaAtaque2(25.0);
    }
    if (nivel == 2) {
        jugador.setnivelJug(3);
        jugador.setvidaJug(50.0);
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
    cout << "Que ataque quieres usar: " << endl;
    cout << "1: " << jugador.getnombreAtaque1() << endl;
    cout << "2: " << jugador.getnombreAtaque2() << endl;
    cin >> opcionAtaque;
    while (opcionAtaque != 1 && opcionAtaque != 2) {
        cout << "Escoge una opcion correcta" << endl;
        turnoJugador();
    }
    if (nivelJug == 1) {
        float vidaBowser,fuerzaBola,fuerzaCola;
        vidaBowser = bowser.getvidaBowser();
        fuerzaBola = bowser.getfuerzabolaFuego();
        fuerzaCola = bowser.getfuerzaCola();
        int ataqueEnemigo;
        ataqueEnemigo = rand() % 1;
        if (opcionAtaque == 1) {
            if (ataqueEnemigo == 0) {
                jugador.atacarContrincante(fuerza1, fuerzaBola, vidaBowser);
            }
            else if (ataqueEnemigo == 1) {
                jugador.atacarContrincante(fuerza1, fuerzaCola, vidaBowser);
            }
        }
        else if (opcionAtaque == 2) {
            if (ataqueEnemigo == 0) {
                jugador.atacarContrincante(fuerza2, fuerzaBola, vidaBowser);
            }
            else if (ataqueEnemigo == 1) {
                jugador.atacarContrincante(fuerza2, fuerzaCola, vidaBowser);
            }
        }
        if (vidaBowser <= 0) {
            cout << nombreJug << "HA VENCIDO AL REEEY DE LOS KOOPAS, PASAAA A LA SEGUNDA PELEA ESTELAR" << endl;
            subirNivel();
        }
        if (jugador.getvidaJug() <= 0) {
            cout << nombreJug << "ESTA FUERAAAAAAA, SE ACABO" << endl;
            exit();
        }
    }

    if (nivelJug == 2) {
        float vidaGanon, fuerzaWarlock, fuerzaFlame, fuerzaVolcano;
        vidaGanon = ganon.getvidaGanon();
        fuerzaWarlock = ganon.getfuerzaWarlock();
        fuerzaFlame = ganon.getfuerzaFlame();
        fuerzaVolcano = ganon.getfuerzaVolcano();
        int ataqueEnemigo;
        ataqueEnemigo = rand() % 2;
        if (opcionAtaque == 1) {
            if (ataqueEnemigo == 1) {
                jugador.atacarContrincante(fuerza1, fuerzaWarlock, vidaGanon);
            }
            else if (ataqueEnemigo == 2) {
                jugador.atacarContrincante(fuerza1, fuerzaFlame, vidaGanon);
            }
            else if (ataqueEnemigo == 3) {
                jugador.atacarContrincante(fuerza1, fuerzaVolcano, vidaGanon);
            }
        }
        else if (opcionAtaque == 2) {
            if (ataqueEnemigo == 1) {
                jugador.atacarContrincante(fuerza2, fuerzaWarlock, vidaGanon);
            }
            else if (ataqueEnemigo == 2) {
                jugador.atacarContrincante(fuerza2, fuerzaFlame, vidaGanon);
            }
            else if (ataqueEnemigo == 3) {
                jugador.atacarContrincante(fuerza2, fuerzaVolcano, vidaGanon);
            }
        }
        if (vidaGanon <= 0) {
            cout << nombreJug << "HA VENCIDO AL REY DEMONIO, PASAAA A LA SEGUNDA PELEA ESTELAR" << endl;
            subirNivel();
        }
        if (jugador.getvidaJug() <= 0) {
            cout << nombreJug << "ESTA FUERAAAAAAA, SE ACABO" << endl;
        }
    }

    if (nivelJug == 2) {
        float vidaSephiroth, fuerzaMasamune, fuerzaShadow, fuerzaOctaslash, fuerzaNova;
        vidaSephiroth = sephiroth.getvidaSephiroth();
        fuerzaMasamune = sephiroth.getfuerzaMasamune();
        fuerzaShadow = sephiroth.getfuerzaShadow();
        fuerzaOctaslash = sephiroth.getfuerzaOctaslash();
        fuerzaNova = sephiroth.getfuerzaNova();
        int ataqueEnemigo;
        ataqueEnemigo = rand() % 3;
        if (opcionAtaque == 1) {
            if (ataqueEnemigo == 1) {
                jugador.atacarContrincante(fuerza1, fuerzaMasamune, vidaSephiroth);
            }
            else if (ataqueEnemigo == 2) {
                jugador.atacarContrincante(fuerza1, fuerzaShadow, vidaSephiroth);
            }
            else if (ataqueEnemigo == 3) {
                jugador.atacarContrincante(fuerza1, fuerzaOctaslash, vidaSephiroth);
            }
            else if (ataqueEnemigo == 4) {
                jugador.atacarContrincante(fuerza1, fuerzaNova, vidaSephiroth);
            }
        }
        else if (opcionAtaque == 2) {
            if (ataqueEnemigo == 1) {
                jugador.atacarContrincante(fuerza2, fuerzaMasamune, vidaSephiroth);
            }
            else if (ataqueEnemigo == 2) {
                jugador.atacarContrincante(fuerza2, fuerzaShadow, vidaSephiroth);
            }
            else if (ataqueEnemigo == 3) {
                jugador.atacarContrincante(fuerza2, fuerzaOctaslash, vidaSephiroth);
            }
            else if (ataqueEnemigo == 4) {
                jugador.atacarContrincante(fuerza2, fuerzaNova, vidaSephiroth);
            }
            
        }
        if (vidaSephiroth <= 0) {
            cout << nombreJug << "HA VENCIDO AL ANGEL DE UN ALA,LO HA GANADO TODO DAMAS Y SEÑORES, " << nombreJug << " ES NUESTRO CAMPION" << endl;
        }
        if (jugador.getvidaJug() <= 0) {
            cout << nombreJug << "ESTA FUERAAAAAAA, SE ACABO" << endl;
        }
    }


}

void turnoContrincante() {
        string nombreJug;
        float vidaCont, vidaJug, fuerza1, fuerza2, fuerza1Cont, fuerza2Cont;
        vidaCont = 10.0;
        nombreJug = jugador.getnombreJug();
        vidaJug = jugador.getvidaJug();
        fuerza1 = jugador.getfuerzaAtaque1();
        fuerza1 = jugador.getfuerzaAtaque2();
        fuerza1Cont = 5.0;
        fuerza2Cont = 10.0;
        string decision;
        cin >> decision;
        while (decision != "A" && decision != "D") {
            cout << "Escoge una opcion correcta" << endl;
            turnoContrincante();
        }
        if (jugador.getnivelJug() == 1) {
            cout << "PARECE SER QUE BOWSER ESTA A PUNTO DE ATACAR, que es lo que hara " << nombreJug << endl;
            cout << "A-Atacar" << endl;
            cout << "D-Defender" << endl;
            contrin[0] = new Bowser(30.0, 20.0, 15.0);
            if (decision == "D") {
                int aj;
                aj = rand() % 1;
                contrin[0]->atacarJugador("D", aj);
            }
            if (decision == "A") {
                int aj;
                cout << "PARECE SER QUE " << nombreJug << " esta a punto de contraatacar, pero que ataque usara????" << endl;
                cout << "1: " << jugador.getnombreAtaque1() << endl;
                cout << "2: " << jugador.getnombreAtaque2() << endl;
                cin >> aj;
                if (aj == 1) {
                    contrin[0]->atacarJugador("A", 1);
                }
                if (aj == 2) {
                    contrin[0]->atacarJugador("A", 2);
                }
            }
            if (vidaCont <= 0) {
                cout << nombreJug << "HA VENCIDO AL REEEY DE LOS KOOPAS, PASAAA A LA SEGUNDA PELEA ESTELAR" << endl;
                subirNivel();
            }

            if (jugador.getvidaJug() <= 0) {
                cout << nombreJug << "ESTA FUERAAAAAAA, SE ACABO" << endl;
            }
        }

        else if (jugador.getnivelJug() == 2) {
            cout << "PARECE SER QUE GANON ESTA A PUNTO DE ATACAR, que es lo que hara " << nombreJug << endl;
            cout << "A-Atacar" << endl;
            cout << "D-Defender" << endl;
            contrin[1] = new Ganondorf(40.0, 15.0, 10.0,25.0);
            if (decision == "D") {
                int aj;
                aj = rand() % 1;
                contrin[1]->atacarJugador("D", aj);
            }
            if (decision == "A") {
                int aj;
                cout << "PARECE SER QUE " << nombreJug << " esta a punto de contraatacar, pero que ataque usara????" << endl;
                cout << "1: " << jugador.getnombreAtaque1() << endl;
                cout << "2: " << jugador.getnombreAtaque2() << endl;
                cin >> aj;
                if (aj == 1) {
                    contrin[1]->atacarJugador("A", 1);
                }
                if (aj == 2) {
                    contrin[1]->atacarJugador("A", 2);
                }
            }
            if (vidaCont <= 0) {
                cout << nombreJug << "HA VENCIDO AL REY DEMONIO, PASAAA A LA SEGUNDA PELEA ESTELAR" << endl;
                subirNivel();
            }

            if (jugador.getvidaJug() <= 0) {
                cout << nombreJug << "ESTA FUERAAAAAAA, SE ACABO" << endl;
            }
        }

        else if (jugador.getnivelJug() == 3) {
            cout << "PARECE SER QUE SEPHIROTH ESTA A PUNTO DE ATACAR, que es lo que hara " << nombreJug << endl;
            cout << "A-Atacar" << endl;
            cout << "D-Defender" << endl;
            contrin[2] = new Sephiroth(60.0,15.0,13.0,22.0,40.0);
            if (decision == "D") {
                int aj;
                aj = rand() % 1;
                contrin[2]->atacarJugador("D", aj);
            }
            if (decision == "A") {
                int aj;
                cout << "PARECE SER QUE " << nombreJug << " esta a punto de contraatacar, pero que ataque usara????" << endl;
                cout << "1: " << jugador.getnombreAtaque1() << endl;
                cout << "2: " << jugador.getnombreAtaque2() << endl;
                cin >> aj;
                if (aj == 1) {
                    contrin[2]->atacarJugador("A", 1);
                }
                if (aj == 2) {
                    contrin[2]->atacarJugador("A", 2);
                }
            }
            if (vidaCont <= 0) {
                cout << nombreJug << "HA VENCIDO AL ANGEL DE UN ALA,LO HA GANADO TODO DAMAS Y SEÑORES, "<<nombreJug<<" ES NUESTRO CAMPION" << endl;
                subirNivel();
            }

            if (jugador.getvidaJug() <= 0) {
                cout << nombreJug << "ESTA FUERAAAAAAA, SE ACABO" << endl;
            }
        }
}

void pelea() {
    cout << "BIEEEEEEENVENIDOS A LAAAA PELEA ESTELAAARRRRR!!!!" << endl;
    cout << "Ahora de la esquina izquierda tenemos a " << jugador.getnombreJug() << endl;
    cout << "Yyy de la esquina derecha tenemos a contrincante" << endl;
    cout << "Pelearan para ver quien es el mejor y.... PELIEN" << endl;
    while (jugador.getvidaJug() > 0) {
        turnoJugador();
        turnoContrincante();
    }
}

int main()
{
    crearJugador();
    pelea();
}

