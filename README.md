# JuegoPelea_Samir Baidon Pardo_A01705403
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

### 25/05/03 (Avance 2) (Revisión 4)
Algo que notar es que en esta construcción actual del código, el ingresar una letra que no sea A o D en el turno del jugador, va a mostrar varias veces el mensaje de escoger la opción correcta y después ya te dejará escoger de nuevo entre A o D, para tener eso en mente y arreglarlo.

### 30/05/23 (Avance 3) (Revisión 1)
En esta construcción actual del código, lo que sucede es que al ingresar una opción de ataque que no sea 1 o 2, se genera un ciclo infinito donde dice que se escoga una opción correcta, y también no se le baja la vida al enemigo, solo al usuario y al llegar a vida 0, no se termina el juego.

### 31/05/23 (Avance 3) (Revisión 2-3)
He visto que hay ocasiones en donde al poner una opción que no sea las que el código te proporciona, se genera un error de printear muchas veces el mismo mensaje y luego se termina solo el código, pero sucede en ocasiones, en otras el código solo muestra el mensaje una vez y luego lo quita.

# Historial de Revisiones

### 24/05/23 (Avance 2) (Revisión 1):
Por ahora se causa error en el codigo cuando en el momento de atacar se selecciona una tecla que no sea A o D, también hay que notar que por ahora las variables no estan siendo cargadas a través de cada función, esto por la falta de apuntadores, los cuáles seran agregados en el Avance 3.

El código por ahora esta tomando datos ejemplo que no son iguales a los valores de las clases herencia de Contrincante,esto será ya ajustado para el Avance 3.

### 24/05/23 (Avance 2) (Revisión 2):
Después de alterar unos datos, ya se van guardando los datos de la clase de Jugador, aún falta el alterar otros datos y guardar otros, también hay que ver el poder guardar los cambios y analizar el factor random, porque parece ser va fallando.

### 24/05/23 (Avance 2) (Revisión 3):
El factor random ya fue controlado más, bajando la probabilidad de fallo a 25% en vez de 50%, los datos que salen al pelear son todos diferentes por el hecho de que aun no tenemos el constructor de los enemigos creado para cada Round, pero eso se hará en el Avance 3.

### 25/05/23 (Avance 2) (Revisión 4):
Solo se agregaron comentarios al archivo de "jugador.h", por ahora solo se tiene la sobrecarga y sobreescritura definidas en el archivo de "contrincante.h", aun hace falta el alterar las funciones de la clase para que en cada Round sea un contrincante diferente, agregar constructores y agregar apuntadores para poder lograr que las variables se conecten correctamente, conceptos que se iran implementando en el avance 3.

## 30/05/23 (Avance 3) (Revisión 1):
En esta revisión se movieron por completo todas las clases herencias, tal como fue recomendado en los comentarios del avance, también modifique las funciones de atacarJugador para poder aún tener sobreescritura en ellos, pero ahora incluí constructores dentro de la clase de Contrincante, constructores que implementé en el archivo main, pero aún hay un factor que analizar en lo de la función de atacarContrincante, ya que ahí aún no he sido capaz de implementar poliformismo a través de los constructores, es algo que voy a tener que revisar.

##31/05/23 (Avance 3) (Revisión 2):
En esta revisión se movio el creador de jugador al main ya que es una función que solo se hara una vez, también empece a interactuar más con las referencias y objetos, por ahora solo el rival Bowser tiene la implementación con constructores para cargar los valores de vida a través de las referencias, el plan es que una vez que funcione Bowser, entonces se alterara tanto Sephiroth como Ganondorf para funcionar igual, por ahora mi teoría es que se debe alterar el main.

##31/05/23 (Avance 3) (Revisión 3):
En esta revisión ya se altero las construcciones para tanto los contrincantes Ganondorf como Sephiroth, aún hace falta analizar los factores para que las variables se comuniquen entre ellas, pero para eso creo es cuestión de modificar más el main para no dividir en mayores funciones.


 
 
