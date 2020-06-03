# Seminario 3. Uso de ncurses para crear interfaces de usuario en modo texto bajo Linux.

La biblioteca "*ncurses*" provee una API que permite al programador escribir interfaces basadas en texto.

Al no ser una biblioteca estándar de C, le deberemos especificar al compilador que la enlace con nuestro programa.

Para instalarla en distribuciones basadas en Debian, es tan sencillo como:
~~~
apt install libncurses5-dev libncursesw5-dev
~~~

A la hora de compilar, deberemos hacerlo de la siguiente forma:
~~~
gcc programa.c -o programa -lncurses
~~~

Empezaremos comprobando el funcionamiento de los programas de ejemplo que encontramos en el seminario.

### Ejemplo 1.

El [ejemplo1.c](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S3/sources/ejemplo1.c) es un pequeño programa el cual mostrará una cadena de texto en la terminal como podemos ver a continuación:

![](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S3/images/ejemplo1.png)

### Ejemplo 2.

En el [ejemplo2.c](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S3/sources/ejemplo2.c) mostramos una ventana en la terminal, con sus marcos y un color de fondo.

![](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S3/images/ejemplo2_1.png)

![](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S3/images/ejemplo2_2.png)

### Ejemplo 3.


En el [ejemplo3.c](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S3/sources/ejemplo3.c) moveremos una "pelotita" (carácter 'o') en la pantalla.

![](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S3/images/ejemplo3.gif)

### Ejercicio.

Como ejercicio a resolver, se propone crear un juego sencillo tipo pong.

Para la realización, me he basado en el pong implementado por el usuario [vicentebolea](https://github.com/vicentebolea) que podemos ver en su [repositorio](https://github.com/vicentebolea/Pong-curses).

El fichero en cuestión es [pong.c](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S3/sources/pong.c).

La demo la podemos ver a continuación:

![](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S3/images/pong.gif)
