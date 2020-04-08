# Práctica 2. Entrada/Salida utilizando interrupciones con lenguaje C.

Los objetivos de la prática son:

+ Aprender la forma de uso y programación de interrupciones software desde programas de usuario.
+ Comprender la interfaz que permite un sistema operativo para el acceso a los recursos de entrada/salida.
+ Crear una librería de funciones básicas de Entrada/Salida a través de llamadas a interrupciones.

Deberemos implementar 9 funciones a modo de *biblioteca*.

+ `gotoxy`. Coloca el cursor en una posición determinada
+ `setcursortype`. Fijar el aspecto del cursor, debe admitir tres valores: INVISIBLE, NORMAL y GRUESO
+ `setvideomode`. Fija el modo de video deseado
+ `getvideomode`. Obtiene el modo de video actual
+ `textcolor`. Modifica el color de primer plano con que se mostrarán los caracteres
+ `textbackground`. Modifica el color de fondo con que se mostrarán los caracteres
+ `clrscr`. Borra toda la pantalla
+ `cputchar`. Escribe un carácter en pantalla con el color indicado actualmente
+ `getche`. Obtiene un carácter de teclado y lo muestra en pantalla

Como ejercicios adicionales implementaremos:

+ Una función que permita dibujar un recuadro en la pantalla en modo texto. Recibirá como parámetros las coordenadas superior izquierda e inferior derecha del recuadro, el color de primer plano y el color de fondo.
+ Un programa que establezca modo gráfico VGA para crear dibujos sencillos en pantalla.

El fichero en el que he implementado las funciones es [velalib.c](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P2/sources/velalib.c).
Dicho fichero también dispone de un pequeño `main` que prueba el correcto funcionamiento de la biblioteca.

##### Función gotoxy
![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P2/images/gotoxy.png)


##### Función setcursortype

![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P2/images/setcursortype1.png)
![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P2/images/setcursortype2.png)
![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P2/images/setcursortype3.png)

##### Función setvideomode

![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P2/images/setvideomode1.png)
![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P2/images/setvideomode2.png)

##### Función getvideomode
![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P2/images/getvideomode1.png)
![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P2/images/getvideomode2.png)


##### Función textcolor
Ver la función `cputchar`.


##### Función textbackground
Ver la función `cputchar`.


##### Función clrscr

![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P2/images/clrscr1.png)
![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P2/images/clrscr2.png)

##### Función cputchar
![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P2/images/cputchar1.png)
![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P2/images/cputchar2.png)
![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P2/images/cputchar3.png)
![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P2/images/cputchar4.png)


##### Función getche

![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P2/images/getche1.png)