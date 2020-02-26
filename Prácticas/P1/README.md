# Práctica 1. Introducción a la programación de periféricos.

Como introducción a la práctica, implementaremos un programa que lance una interrupción que pausará la ejecución del programa a la espera de que pulsemos una tecla.
Dicho programa es [pausa.asm](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P1/sources/pausa.asm).

![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P1/images/pausa.png)

Como podemos ver, el programa hace una pausa hasta que pulsemos una tecla.

Otro programa a modo de entrenamiento que podría implementar es [holapausa.asm](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P1/sources/holapausa.asm), el cual es una fusión del típico *"hola mundo"* con el programa implementado anteriormente.

![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P1/images/holapausa.png)

## Ejercicios.

#### 1. programa que use la función de interrupción de cambio de modo de vídeo (usar el modo texto 40x25) y mostrar una cadena de texto para comprobar el funcionamiento. Antes de terminar, hacer una pausa esperando la pulsación de una tecla, y restaurar el modo de vídeo de 80x25.

Al ejecutar el programa, informo al usuario de que al presionar una tecla se cambiará al *modo texto 40x25*. Al cambiar el modo, volveremos a pausar la ejecución del programa, mostraremos otro mensaje y al volver a presionar otra tecla, volveremos a 80x25.
El fichero en cuestión es [ejer1.asm](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P1/sources/ejer1.asm)

![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P1/images/ejer1_1.png)
![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P1/images/ejer1_2.png)
![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P1/images/ejer1_3.png)


#### 2. programa que use la función de interrupción de cambio de modo de vídeo (usar el modo gráfico 320x200 color) y dibujar un rectángulo blanco en pantalla; a continuación, mostrar varios pixels de diferentes colores dentro del rectángulo. Antes de terminar, hacer una pausa esperando la pulsación de una tecla, y restaurar el modo de vídeo de 80x25.