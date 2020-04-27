# Práctica 4. Experimentación con el sistema de salida de sonido

Los objetivos de esta práctica son:

+ Identificar y representar gráficamente la forma de onda de señales de sonido
+ Conocer la estructura de un fichero típico de sonido (ficheros WAV)
+ Entender y operar con los parámetros principales de una señal de sonido
+ Utilizar el entorno de programación RStudio para el manejo de sonido

Utilizaremos los paquetes *tuneR* y *seewave* de *R* para trabajar con varios archivos de sonido (tanto en formato WAV como en MP3).

Para trabajar con sonidos en R, utilizaremos las bibliotecas  `tuneR` y `seewave`. Para instalar ambas librerías, debemos añadir en nuestro script lo siguiente:
~~~
install.packages('tuneR', dep=TRUE)
install.packages('seewave', dep=TRUE)
~~~
Tras lo cual, cargaremos las bibliotecas:
~~~
library(tuneR)
library(seewave)
library(audio)
~~~

Cabe destacar, que para evitar problemas de permisos a la hora de reproducir audios, hay que especificar la ruta absoluta del reproductor de audio con el que queramos que se reproduzcan. En mi caso, al utilizar Linux como SO y tener *Celluloid* como reproductor, deberé poner la siguiente línea en el script:
~~~
setWavPlayer('/usr/bin/celluloid')
~~~

Tras esto, podemos empezar a realizar la práctica.

Deberemos crear un script en *R* que realice las siguientes acciones:

### 1. Leer dos ficheros de sonido (WAV o MP3) de unos pocos segundos de duración cada uno

Para ello, utilizaremos los audios incorporados [aquí](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P4/sounds/).

En concreto, podemos utilizar [gato.mp3](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P4/sounds/gato.mp3) y [perro.wav](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P4/sounds/perro.wav).