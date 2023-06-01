//Creación de la clase de Jugador usado para almacenar todos los datos relacionados al Jugador
//Creación: 20/05/23

#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Jugador {
	private:
		string nombreJug;
		string nombreAtaque1;
		string nombreAtaque2;
		float vidaJug;
		float fuerzaAtaque1;
		float fuerzaAtaque2;
		int nivelJug;
	public:

		//Funcion:Regresar el valor de la variable de vida del jugador
		//Parametros: Al ser un getter no se obtienen parametros, solo se regresa un valor
		//Retorno: Se regresa el valor de la variable de vida del jugador
		float getvidaJug() { return vidaJug; }

		//Funcion:Regresar el valor de la variable de fuerza del primer ataque
		//Parametros: Al ser un getter no se obtienen parametros, solo se regresa un valor
		//Retorno: Se regresa el valor de la variable de fuerza del primer ataque
		float getfuerzaAtaque1() { return fuerzaAtaque1; }

		//Funcion:Regresar el valor de la variable de fuerza del segundo ataque
		//Parametros: Al ser un getter no se obtienen parametros, solo se regresa un valor
		//Retorno: Se regresa el valor de la variable de fuerza del segundo ataque
		float getfuerzaAtaque2() { return fuerzaAtaque2; }

		//Funcion:Regresar el valor de la variable de nivel del jugador
		//Parametros: Al ser un getter no se obtienen parametros, solo se regresa un valor
		//Retorno: Se regresa el valor de la variable de nivel del jugador
		int getnivelJug() { return nivelJug; }

		//Funcion:Regresar el valor de la variable de nombre del jugador
		//Parametros: Al ser un getter no se obtienen parametros, solo se regresa un valor
		//Retorno: Se regresa el valor de la variable de nombre del jugador
		string getnombreJug() { return nombreJug; }

		//Funcion:Regresar el valor de la variable de nombre del primer ataque
		//Parametros: Al ser un getter no se obtienen parametros, solo se regresa un valor
		//Retorno: Se regresa el valor de la variable de nombre del primer ataque
		string getnombreAtaque1() { return nombreAtaque1; }

		//Funcion:Regresar el valor de la variable de nombre del segundo ataque
		//Parametros: Al ser un getter no se obtienen parametros, solo se regresa un valor
		//Retorno: Se regresa el valor de la variable de nombre del segundo ataque
		string getnombreAtaque2() { return nombreAtaque2; }


		void setnivelJug(int nivelJugador);
		void setvidaJug(float vidaJugador);
		void setfuerzaAtaque1(float fuerzaJugador1);
		void setfuerzaAtaque2(float fuerzaJugador2);
		void setnombreJug(string nombreJugador);
		void setnombreAtaque1(string nombreFuerza1);
		void setnombreAtaque2(string nombreFuerza2);
		void atacarContrincante1(float fuerzaJug,float fuerzaCont, float vidaCont,Jugador jugador);
		void atacarContrincante2(float fuerzaJug, float fuerzaCont, float vidaCont, Jugador jugador);
		void atacarContrincante3(float fuerzaJug, float fuerzaCont, float vidaCont, Jugador jugador);
};


//Funcion:Darle nuevo valor a la variable de nivel del jugador
//Parametros: Se toma un parametro int para darle ese valor a la variable de nivel del jugador
//Retorno: Al ser una función void no se regresa algo en sí,solo se actualiza el valor de la variable de nivel del jugador
void Jugador::setnivelJug(int nivelJugador) {
	nivelJug = nivelJugador;
}

//Funcion:Darle nuevo valor a la variable de la vida del jugador
//Parametros: Se toma un parametro float para darle ese valor a la variable de vida del jugador
//Retorno: Al ser una función void no se regresa algo en sí,solo se actualiza el valor de la variable de vida del jugador
void Jugador::setvidaJug(float vidaJugador) {
	vidaJug = vidaJugador;
}

//Funcion:Darle nuevo valor a la variable de fuerza del primer ataque del jugador
//Parametros: Se toma un parametro float para darle ese valor a la variable de fuerza del primer ataque del jugador
//Retorno: Al ser una función void no se regresa algo en sí,solo se actualiza el valor de la variable de fuerza del primer ataque del jugador
void Jugador::setfuerzaAtaque1(float fuerzaJugador1) {
	fuerzaAtaque1 = fuerzaJugador1;
}

//Funcion:Darle nuevo valor a la variable de fuerza del segundo ataque del jugador
//Parametros: Se toma un parametro float para darle ese valor a la variable de fuerza del segundo ataque del jugador
//Retorno: Al ser una función void no se regresa algo en sí,solo se actualiza el valor de la variable de fuerza del segundo ataque del jugador
void Jugador::setfuerzaAtaque2(float fuerzaJugador2) {
	fuerzaAtaque2 = fuerzaJugador2;
}

//Funcion:Darle nuevo valor a la variable del nombre del jugador
//Parametros: Se toma un parametro string para darle ese valor a la variable de nombre del jugador
//Retorno: Al ser una función void no se regresa algo en sí,solo se actualiza el valor de la variable de nombre del jugador
void Jugador::setnombreJug(string nombreJugador) {
	nombreJug = nombreJugador;
}

//Funcion:Darle nuevo valor a la variable del nombre del primer ataque del jugador
//Parametros: Se toma un parametro string para darle ese valor a la variable del nombre del primer ataque del jugador
//Retorno: Al ser una función void no se regresa algo en sí,solo se actualiza el valor de la variable del nombre del primer ataque del jugador
void Jugador::setnombreAtaque1(string nombreFuerza1) {
	nombreAtaque1 = nombreFuerza1;
}

//Funcion:Darle nuevo valor a la variable del nombre del segundo ataque del jugador
//Parametros: Se toma un parametro string para darle ese valor a la variable del nombre del segundo ataque del jugador
//Retorno: Al ser una función void no se regresa algo en sí,solo se actualiza el valor de la variable del nombre del segundo ataque del jugador
void Jugador::setnombreAtaque2(string nombreFuerza2) {
	nombreAtaque2 = nombreFuerza2;
}

//Funcion:Generar situaciones en donde se altere tanto la vida del jugador como la del contrincante 
//Parametros: Se toman parametros de float de vida del jugador, vida del contrincante, fuerza del jugador y fuerza del contrincante
//Retorno: Al ser una función void no se regresa algo en sí,en este caso se actualizan los valores de vida de tanto el jugador como del contrincante
void Jugador::atacarContrincante1(float fuerzaJug,float fuerzaCont, float vidaCont,Jugador jugador) {
	int contrincanteAtaque, jugadorChance;
	contrincanteAtaque = rand() % 2;
	jugadorChance = rand() % 3;
	if (contrincanteAtaque == 0) {
		if (jugadorChance == 3) {
			cout << "TU ATAQUE HA FALLADO...pero Bowser tampoco logro hacer nada" << endl;
		}
		if (jugadorChance == 0 || jugadorChance == 1 || jugadorChance == 2) {
			vidaCont = vidaCont - fuerzaJug;
			cout << "HAS LOGRADO ATACAR!!!, la vida de Bowser ahora es: " << vidaCont<< endl;
		}
	}
	if (contrincanteAtaque == 1) {
		if (jugadorChance == 3) {
			vidaJug = vidaJug - fuerzaCont;
			cout << "TU ATAQUE HA FALLADO y peor aun BOWSER SI TE ATACO, tu vida ahora es: " << vidaJug << endl;
		}
		if (jugadorChance == 0 || jugadorChance == 1 || jugadorChance == 2) {
			vidaJug = vidaJug - (fuerzaCont / 2);
			vidaCont = vidaCont - (fuerzaJug / 2);
			cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << vidaJug << endl;
			cout << "La vida de Bowser ahora es: " << vidaCont << endl;
		}
	}
	if (contrincanteAtaque == 2) {
		if (jugadorChance == 3) {
			cout << "TU ATAQUE HA FALLADO, pero Bowser se estaba defendiendo así que no paso nada al final "<< endl;
		}
		if (jugadorChance == 0 || jugadorChance == 1 || jugadorChance == 2) {
			cout << "HAS LOGRADO ATACAR!!, pero Bowser se defendio, nada cambio" << endl;
		}
	}
}

void Jugador::atacarContrincante2(float fuerzaJug, float fuerzaCont, float vidaCont, Jugador jugador) {
	int contrincanteAtaque, jugadorChance;
	contrincanteAtaque = rand() % 2;
	jugadorChance = rand() % 3;
	if (contrincanteAtaque == 0) {
		if (jugadorChance == 3) {
			cout << "TU ATAQUE HA FALLADO...pero Ganondorf tampoco logro hacer nada" << endl;
		}
		if (jugadorChance == 0 || jugadorChance == 1 || jugadorChance == 2) {
			vidaCont = vidaCont - fuerzaJug;
			cout << "HAS LOGRADO ATACAR!!!, la vida de Ganondorf ahora es: " << vidaCont << endl;
		}
	}
	if (contrincanteAtaque == 1) {
		if (jugadorChance == 3) {
			vidaJug = vidaJug - fuerzaCont;
			cout << "TU ATAQUE HA FALLADO y peor aun GANONDORF SI TE ATACO, tu vida ahora es: " << vidaJug << endl;
		}
		if (jugadorChance == 0 || jugadorChance == 1 || jugadorChance == 2) {
			vidaJug = vidaJug - (fuerzaCont / 2);
			vidaCont = vidaCont - (fuerzaJug / 2);
			cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << vidaJug << endl;
			cout << "La vida de Bowser ahora es: " << vidaCont << endl;
		}
	}
	if (contrincanteAtaque == 2) {
		if (jugadorChance == 3) {
			cout << "TU ATAQUE HA FALLADO, pero Ganondorf se estaba defendiendo así que no paso nada al final " << endl;
		}
		if (jugadorChance == 0 || jugadorChance == 1 || jugadorChance == 2) {
			cout << "HAS LOGRADO ATACAR!!, pero Ganondorf se defendio, nada cambio" << endl;
		}
	}
}

void Jugador::atacarContrincante3(float fuerzaJug, float fuerzaCont, float vidaCont, Jugador jugador) {
	int contrincanteAtaque, jugadorChance;
	contrincanteAtaque = rand() % 2;
	jugadorChance = rand() % 3;
	if (contrincanteAtaque == 0) {
		if (jugadorChance == 3) {
			cout << "TU ATAQUE HA FALLADO...pero Sephiroth tampoco logro hacer nada" << endl;
		}
		if (jugadorChance == 0 || jugadorChance == 1 || jugadorChance == 2) {
			vidaCont = vidaCont - fuerzaJug;
			cout << "HAS LOGRADO ATACAR!!!, la vida de Sephiroth ahora es: " << vidaCont << endl;
		}
	}
	if (contrincanteAtaque == 1) {
		if (jugadorChance == 3) {
			vidaJug = vidaJug - fuerzaCont;
			cout << "TU ATAQUE HA FALLADO y peor aun SEPHIROTH SI TE ATACO, tu vida ahora es: " << vidaJug << endl;
		}
		if (jugadorChance == 0 || jugadorChance == 1 || jugadorChance == 2) {
			vidaJug = vidaJug - (fuerzaCont / 2);
			vidaCont = vidaCont - (fuerzaJug / 2);
			cout << "AMBOS SE HAN ATACADO MUTUAMENTE, tu vida ahora es: " << vidaJug << endl;
			cout << "La vida de Bowser ahora es: " << vidaCont << endl;
		}
	}
	if (contrincanteAtaque == 2) {
		if (jugadorChance == 3) {
			cout << "TU ATAQUE HA FALLADO, pero Sephiroth se estaba defendiendo así que no paso nada al final " << endl;
		}
		if (jugadorChance == 0 || jugadorChance == 1 || jugadorChance == 2) {
			cout << "HAS LOGRADO ATACAR!!, pero Sephiroth se defendio, nada cambio" << endl;
		}
	}
}
#endif