# JuegoPelea_A01705403
Proyecto parte de el curso TC1030 Programación orientada a objetos del Gpo 304

# Concepto
Este proyecto trata sobre crear un juego de peleas usando diferentes clases y objetos, utilizando lo aprendido en clase se tiene un juego pequeño donde se escoge contra quien pelear, el juego va por turnos y el jugador sera capáz de ir subiendo de nivel para enfrentar a los enemigos con mayor nivel y decidir que ataque le favorece más. El juego sera de dificultad tipo Punch out, en el sentido que el siguiente enemigo será más fuerte que el anterior.

En el código se tienen principalmente dos clases, Jugador y Contrincante, estas se van a unir en la clase principal de la consola. Desde la clase de Contrincante se van a heredar otros 3 diferentes tipos de Contrincantes.

El turno del juego consiste en que el jugador primero crea su personaje, dandole nombre y nombre a sus ataques, luego podra escoger que ataque usar primero, entonces se generará un número random que determinara si el contrincante ha:
  °Defendido el ataque
  °Atacado de vuelta
  °Recibido el ataque
 
Si el contrincante defendio el ataque, entonces no se le baja vida, si ataco de vuelta ha tanto el jugador como el contrincante se le baja una mitad de la fuerza del ataque que usaron, por ejemplo si el jugador uso un ataque con fuerza 10 y el contrincante un ataque con fuerza 15, entonces el jugador perdera 7.5 de vida y el contrincante 5.

Esta misma ideología se aplica cuando el contrincante ataca, pero en este caso el jugador podra escoger entre defenderse o atacar de vuelta, dando así una sensación de riesgo y gananza.

# Casos en donde causa error el código

### 24/05/23 (Avance 2):
Por ahora se causa error en el codigo cuando en el momento de atacar se selecciona una tecla que no sea A o D, también hay que notar que por ahora las variables no estan siendo cargadas a través de cada función, esto por la falta de apuntadores, los cuáles seran agregados en el Avance 3.

El código por ahora esta tomando datos ejemplo que no son iguales a los valores de las clases herencia de Contrincante,esto será ya ajustado para el Avance 3.

### 24/05/23 (Avance 2) (Revisión 2):
Después de alterar unos datos, ya se van guardando los datos de la clase de Jugador, aún falta el alterar otros datos y guardar otros, también hay que ver el poder guardar los cambios y analizar el factor random, porque parece ser va fallando.
 
 
