/*
 *
 * Proyecto Juego de Peleas
 * Samir Baidon Pardo
 * A01705403
 * 20/05/2023
 * versio : 4
 * Esta clase define la clase de Contrincante, tiene los setters y
 * getter necesarios para que se creen objetos derivados de
 * la clase y tener así un arreglo de contrincantes
 */


#ifndef CONTRINCANTE_H
#define CONTRINCANTE_H
#include "jugador.h"//Importo el archivo de jugador para
//poder hacer referencia a la clase jugador
//y tener así agregación y comunicación entre clases
#include <iostream>
#include <cstdlib>

using namespace std;

class Contrincante {

//Se declaran los atributos privados de la clase
private:
    float vidaCont;
    float fuerzaCont1;
    float fuerzaCont2;
    float fuerzaCont3;
    float fuerzaCont4;

public:
    Contrincante() {}

    Contrincante(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2);
    Contrincante(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2, float fuerzaEnem3);
    Contrincante(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2, float fuerzaEnem3, float fuerzaEnem4);

    //getters
    float getvidaCont() { return vidaCont; }
    float getfuerzaCont1() { return fuerzaCont1; }
    float getfuerzaCont2() { return fuerzaCont2; }
    float getfuerzaCont3() { return fuerzaCont3; }
    float getfuerzaCont4() { return fuerzaCont4; }

    //setters
    void setvidaCont(float vidaEnem);

    virtual void atacarJugador(string decision, int aJ, Jugador* jugador, Contrincante* contrincante);
};

void Contrincante::setvidaCont(float vidaEnem) {
    vidaCont = vidaEnem;
}

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

void Contrincante::atacarJugador(string decision, int aJ,Jugador* jugador, Contrincante* contrincante) {
    int turnoContrincante, defensaChance, contrincanteAtaque, ataqueChance;
    turnoContrincante = rand() % 2;
    defensaChance = rand() % 3;
    contrincanteAtaque = rand() % 1;
    ataqueChance = rand() % 3;

    if (decision == "D") {
        if (defensaChance == 0 || defensaChance == 1 || defensaChance == 2) {
            if (turnoContrincante == 0) {
                cout << "El ataque del contrincante ha fallado mientras defendiste, no sucedió nada" << endl;
            }
            else if (turnoContrincante == 1) {
                cout << "Te has defendido perfectamente contra el enemigo" << endl;
            }
            else if (turnoContrincante == 2) {
                cout << "...No pues, ambos se defendieron, bueno ¡PELEEN!" << endl;
            }
        }
        else if (defensaChance == 3) {
            if (turnoContrincante == 0) {
                cout << "El ataque del contrincante ha fallado pero tu defensa también ha fallado, no sucedió nada" << endl;
            }
            else if (turnoContrincante == 1) {
                float vidaJug;
                if (contrincanteAtaque == 0) {
                    vidaJug = jugador->getvidaJug() - fuerzaCont1;
                    jugador->setvidaJug(vidaJug);
                    cout << "El enemigo ha atacado con éxito, tu vida ahora es: " << jugador->getvidaJug() << endl;
                }
                else if (contrincanteAtaque == 1) {
                    vidaJug = jugador->getvidaJug() - fuerzaCont2;
                    jugador->setvidaJug(vidaJug);
                    cout << "El enemigo ha atacado con éxito, tu vida ahora es: " << jugador->getvidaJug() << endl;
                }
            }
            else if (turnoContrincante == 2) {
                cout << "...Tu defensa falló, pero el enemigo estaba defendiendo... ¡bueno, PELIEN!" << endl;
            }
        }
    }
    else if (decision == "A") {
        if (ataqueChance == 0 || ataqueChance == 1 || ataqueChance == 2) {
            if (turnoContrincante == 0) {
                if (aJ == 1) {
                    vidaCont = contrincante->getvidaCont() - (jugador->getfuerzaAtaque1());
                    contrincante->setvidaCont(vidaCont);
                    cout << "¡HAS ATACADO! Lograste quitarle vida al contrincante, su vida ahora es: " << vidaCont << endl;
                }
                if (aJ == 2) {
                    vidaCont = contrincante->getvidaCont() - (jugador->getfuerzaAtaque2());
                    contrincante->setvidaCont(vidaCont);
                    cout << "¡HAS ATACADO! Lograste quitarle vida al contrincante, su vida ahora es: " << vidaCont << endl;
                }
            }
            else if (turnoContrincante == 1) {
                if (contrincanteAtaque == 0) {
                    if (aJ == 1) {
                        float vidaJug;
                        vidaJug = jugador->getvidaJug() - (fuerzaCont1 / 2);
                        jugador->setvidaJug(vidaJug);
                        vidaCont = contrincante->getvidaCont() - (jugador->getfuerzaAtaque1() / 2);
                        contrincante->setvidaCont(vidaCont);
                        cout << "¡HAS ATACADO!, pero el contrincante te ha contraatacado, tu vida ahora es: " << jugador->getvidaJug() << endl;
                        cout << "La vida del contrincante ahora es: " << vidaCont << endl;
                    }
                    if (aJ == 2) {
                        float vidaJug;
                        vidaJug = jugador->getvidaJug() - (fuerzaCont1 / 2);
                        jugador->setvidaJug(vidaJug);
                        vidaCont = contrincante->getvidaCont() - (jugador->getfuerzaAtaque2() / 2);
                        contrincante->setvidaCont(vidaCont);
                        cout << "¡HAS ATACADO!, pero el contrincante te ha contraatacado, tu vida ahora es: " << jugador->getvidaJug() << endl;
                        cout << "La vida del contrincante ahora es: " << vidaCont << endl;
                    }
                }
                else if (contrincanteAtaque == 1) {
                    if (aJ == 1) {
                        float vidaJug;
                        vidaJug = jugador->getvidaJug() - (fuerzaCont2 / 2);
                        jugador->setvidaJug(vidaJug);
                        vidaCont = contrincante->getvidaCont() - (jugador->getfuerzaAtaque1() / 2);
                        contrincante->setvidaCont(vidaCont);
                        cout << "¡HAS ATACADO!, pero el contrincante te ha contraatacado, tu vida ahora es: " << jugador->getvidaJug() << endl;
                        cout << "La vida del contrincante ahora es: " << vidaCont << endl;
                    }
                    if (aJ == 2) {
                        float vidaJug;
                        vidaJug = jugador->getvidaJug() - (fuerzaCont2 / 2);
                        jugador->setvidaJug(vidaJug);
                        vidaCont = contrincante->getvidaCont() - (jugador->getfuerzaAtaque2() / 2);
                        contrincante->setvidaCont(vidaCont);
                        cout << "¡HAS ATACADO!, pero el contrincante te ha contraatacado, tu vida ahora es: " << jugador->getvidaJug() << endl;
                        cout << "La vida del contrincante ahora es: " << vidaCont << endl;
                    }
                }
            }
            else if (turnoContrincante == 2) {
                cout << "¡HAS ATACADO!, pero el enemigo logró defenderse, ni modo, ¡toca pelear!" << endl;
            }
        }
        else if (ataqueChance == 3) {
            if (turnoContrincante == 0) {
                cout << "¡TU ATAQUE HA FALLADO!, pero también el ataque del contrincante" << endl;
            }
            else if (turnoContrincante == 1) {
                if (contrincanteAtaque == 0) {
                    float vidaJug;
                    vidaJug = jugador->getvidaJug() - fuerzaCont1;
                    jugador->setvidaJug(vidaJug);
                    cout << "¡TU ATAQUE HA FALLADO! Y ahora el contrincante te ha atacado" << endl;
                    cout << "Tu vida ahora es: " << jugador->getvidaJug() << endl;
                }
                else if (contrincanteAtaque == 1) {
                    float vidaJug;
                    vidaJug = jugador->getvidaJug() - fuerzaCont2;
                    jugador->setvidaJug(vidaJug);
                    cout << "¡TU ATAQUE HA FALLADO! Y ahora el contrincante te ha atacado" << endl;
                    cout << "Tu vida ahora es: " << jugador->getvidaJug() << endl;
                }
            }
            else if (turnoContrincante == 2) {
                cout << "¡AMBOS ATAQUES HAN FALLADO!" << endl;
            }
        }
    }
}

#endif
