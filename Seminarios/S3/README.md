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

El [ejemplo1.c](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S3/sources/ejemplo1.c) es un pequeño programa el cual mostrará una cadena de texto en la terminal como podemos ver a continuación:

![](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S3/images/ejemplo1.png)