# Seminario 2. Acceso a dispositivos de E/S en C.

A modo de introducción, implementaré el típico hola mundo en C y lo compilaré utilizando *Borland C*.

![](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S2/images/p1.png) 
![](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S2/images/p2.png)

## Ejercicios

#### 1. Configurar el inicio de DOSBox para que monte en la unidad C: el directorio donde se encuentra el entorno de programación Borland C. Añadir a la variable “PATH” de inicio el directorio “bin” donde se encuentra el ejecutable BC.EXE

Esto lo hicimos en el seminario anterior, si nos fijamos en la anterior imagen, podemos ejecutar *Borland C* sin problema.

#### 2. Realizar un programa en lenguaje C que llame a la función de cambio de modo de vídeo y comprobar su funcionamiento.
El programa implementado es [cambio_video.c](). Al programa se le debe pasar como argumento un número del 0 al 7, (los modos de vídeo posibles). 

+ Si se le pasa un número mayor a 7, se truncará a 0.
+ Si no se le pasa ningún parámetro no se ejecutará.

De esta forma, podemos ir cambiando de modo de vídeo como vemos a continuación:

~~~
cambio_video.exe 1
~~~
![](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S2/images/cambio_1.png)

~~~
cambio_video.exe 5
~~~
![](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S2/images/cambio_5.png)

~~~
cambio_video.exe 3
~~~
![](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S2/images/cambio_3.png)