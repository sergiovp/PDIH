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

Destacar que en [sounds](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P4/sounds/) tenemos los audios con los que trabajaremos la práctica, y que en [sources](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P4/sounds/practica_sonido.R) tenemos el script en R.

Tras esto, podemos empezar a realizar la práctica.

### 1. Leer dos ficheros de sonido (WAV o MP3) de unos pocos segundos de duración cada uno

Usaremos los audios [perro.wav](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P4/sounds/perro.wav) y [gato.mp3](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P4/sounds/gato.mp3).

~~~
perro <- readWave('../sounds/perro.wav')
perro
listen(perro)

gato <- readMP3('../sounds/gato.mp3')
gato
listen(gato)
~~~

La salida será la información sobre cada fichero y la reproducción de ambos:
~~~
> perro <- readWave('../sounds/perro.wav')
> perro

Wave Object
	Number of Samples:      159732
	Duration (seconds):     3.62
	Samplingrate (Hertz):   44100
	Channels (Mono/Stereo): Stereo
	PCM (integer format):   TRUE
	Bit (8/16/24/32/64):    16 

> listen(perro)
~~~

~~~
> gato <- readMP3('../sounds/gato.mp3')
> gato

Wave Object
	Number of Samples:      393984
	Duration (seconds):     8.93
	Samplingrate (Hertz):   44100
	Channels (Mono/Stereo): Stereo
	PCM (integer format):   TRUE
	Bit (8/16/24/32/64):    16 

> listen(gato)
~~~