// Juego_Peleas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstdlib>
#include "jugador.h"
#include "contrincante.h"

Jugador jugador;
Bowser bowser;
Ganondorf ganon;
Sephiroth sephiroth;
Contrincante contrincante;
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
        int opcionAtaque,ac;
        float vidaCont,vidaJug, fuerza1, fuerza2, fuerza1Cont, fuerza2Cont;
        vidaCont = 10.0;
        nombreJug = jugador.getnombreJug();
        vidaJug = jugador.getvidaJug();
        fuerza1 = jugador.getfuerzaAtaque1();
        fuerza2 = jugador.getfuerzaAtaque2();
        fuerza1Cont = 5.0;
        fuerza2Cont = 10.0;
        cout << "Que ataque quieres usar: " << endl;
        cout << "1: " << jugador.getnombreAtaque1() << endl;
        cout << "2: " << jugador.getnombreAtaque2() << endl;
        cin >> opcionAtaque;
        while (opcionAtaque != 1 && opcionAtaque != 2) {
            cout << "Escoge una opcion correcta" << endl;
            turnoJugador();
        }
        if (opcionAtaque == 1) {
            jugador.atacarContrincante(vidaCont, vidaJug, fuerza1Cont, fuerza1);
        }
        else if (opcionAtaque == 2) {
            jugador.atacarContrincante(vidaCont, vidaJug, fuerza2Cont, fuerza2);
        }
        if (vidaCont <= 0) {
            cout << nombreJug <<"HA VENCIDO A SU CONTRINCANTE, PASAAA A LA SEGUNDA PELEA ESTELAR" << endl;
            subirNivel();
        }
        if (jugador.getvidaJug() <= 0) {
            cout << nombreJug << "ESTA FUERAAAAAAA, SE ACABO" << endl;
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
        cout << "PARECE SER QUE EL CONTRINCANTE ESTA A PUNTO DE ATACAR, que es lo que hara " << nombreJug << endl;
        cout << "A-Atacar" << endl;
        cout << "D-Defender" << endl;
        string decision;
        cin >> decision;
        while (decision != "A" && decision != "D") {
            cout << "Escoge una opcion correcta" << endl;
            turnoContrincante();
        }
        if (decision == "D") {
            int aj;
            aj = rand() % 1;
            contrincante.atacarJugador("D", aj, fuerza1Cont, fuerza2Cont, vidaCont);
        }
        if (decision == "A") {
            int aj;
            cout << "PARECE SER QUE " << nombreJug << " esta a punto de contraatacar, pero que ataque usara????" << endl;
            cout << "1: " << jugador.getnombreAtaque1() << endl;
            cout << "2: " << jugador.getnombreAtaque2() << endl;
            cin >> aj;
            if (aj == 1) {
                contrincante.atacarJugador("A", 1, fuerza1Cont, fuerza2Cont, vidaCont);
            }
            if (aj == 2) {
                contrincante.atacarJugador("A", 2, fuerza1Cont, fuerza2Cont, vidaCont);
            }
        }
        if (vidaCont <= 0) {
            cout << nombreJug << "HA VENCIDO A SU CONTRINCANTE, PASAAA A LA SEGUNDA PELEA ESTELAR" << endl;
            subirNivel();
        }

        if (jugador.getvidaJug() <= 0) {
            cout << nombreJug << "ESTA FUERAAAAAAA, SE ACABO" << endl;
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

