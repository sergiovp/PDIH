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

Destacar que en [sounds](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P4/sounds/) tenemos los audios con los que trabajaremos la práctica, y que en [sources](https://github.com/sergiovp/PDIH/blob/master/Pr%C3%A1cticas/P4/sources/practica_sonido.R) tenemos el script en R.

Tras esto, podemos empezar a realizar la práctica.

### 1. Leer dos ficheros de sonido (WAV o MP3) de unos pocos segundos de duración cada uno

Usaremos los audios [perro.wav](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P4/sounds/perro.wav) y [gato.mp3](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P4/sounds/gato.mp3).

Para leer los audios, haremos uso de la función `readWave` y `readMP3`. Para escucharlos, la función `listen()`.
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

### 2. Dibujar la forma de onda de ambos sonidos.

Para ello, haremos uso de la función `plot()` como sigue:

~~~
plot(extractWave(perro, from = 1, to = length(perro)))
plot(extractWave(gato, from = 1, to = length(gato)))
~~~

Originando la siguiente salida:

**Perro**

![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P4/images/onda_perro.png)

**Gato**

![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P4/images/onda_gato.png)

Como podemos ver hay dos canales, esto es debido a que es sonido estéreo.

### 3. Obtener la información de las cabeceras de ambos sonidos.

Haremos uso de la función `str`.
~~~
str(gato)
str(perro)
~~~
Obteniendo las siguientes salidas:

**Gato**
~~~
> str(gato)
Formal class 'Wave' [package "tuneR"] with 6 slots
  ..@ left     : int [1:393984] 0 0 0 0 0 0 0 0 0 0 ...
  ..@ right    : int [1:393984] 0 0 0 0 0 0 0 0 0 0 ...
  ..@ stereo   : logi TRUE
  ..@ samp.rate: num 44100
  ..@ bit      : num 16
  ..@ pcm      : logi TRUE
~~~

**Perro**
~~~
> str(perro)
Formal class 'Wave' [package "tuneR"] with 6 slots
  ..@ left     : int [1:159732] 0 0 0 0 0 0 0 0 1 1 ...
  ..@ right    : int [1:159732] 0 0 0 0 0 0 0 0 1 1 ...
  ..@ stereo   : logi TRUE
  ..@ samp.rate: int 44100
  ..@ bit      : int 16
  ..@ pcm      : logi TRUE
~~~

### 4. Unir ambos sonidos en uno nuevo.

Haremos uso de la función `pastew()`.
~~~
gato_y_perro <- pastew(perro, gato, output="Wave")
~~~
Si lo escuchamos, veremos como primero escucharemos al gato y después al perro.

### 5. Dibujar la forma de onda de la señal resultante.

Haremos lo mismo que en el ejercicio 2.
~~~
plot(extractWave(gato_y_perro, from = 1, to = length(gato_y_perro)))
~~~

![](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P4/images/onda_gato_perro.png)

Como vemos, los casi 9 primeros segundos corresponden al audio del gato, los restantes son del perro.

### 6. Pasarle un filtro de frecuencia para eliminar las frecuencias entre 10000Hz y 20000Hz.
Para ello, haremos uso de la función `bwfilter()` como sigue:
~~~
f <-  gato_y_perro@samp.rate
filtro_gato_y_perro <- bwfilter(gato_y_perro, f = f, channel = 1, n = 1, from = 10000, to = 20000, bandpass = TRUE, output = "Wave")
~~~
### 7. Almacenar la señal obtenida como un fichero WAV denominado “mezcla.wav”.

Hacemos uso de la función `writeWave`.
~~~
writeWave(filtro_gato_y_perro, file.path("../sounds/mezcla.wav"))
~~~

El fichero es [mezcla.wav](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P4/sounds/mezcla.wav).

### 8. Cargar un nuevo archivo de sonido, aplicarle eco y a continuación darle la vuelta al sonido. Almacenar la señal obtenida como un fichero WAV denominado “alreves.wav”.

Para ello, usaremos el sonido [oveja.wav](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P4/sounds/oveja.wav) y las funciones `echo` y `revw`.

~~~
oveja <- readWave('../sounds/oveja.wav')

ovejaECO <- echo(oveja, f = 22050, amp = c(0.8, 0.4, 0.2), delay = c(1, 2, 3), output = "Wave")
ovejaECO@left <- 1000 * ovejaECO@left

ovejaECOalreves <- revw(ovejaECO, output="Wave")
~~~

Si nos fijamos en la tercera línea, estamos multiplicando las muestras para aumentar la amplitud, ya que al meterle el eco las muestras pasan a tener valores muy pequeños y a la hora de guardar los sonidos, estos no se escucharían.

Por último, al igual que en el ejercicio anterior, guardamos el sonido modificado como [alreves.wav](https://github.com/sergiovp/PDIH/blob/master/Prácticas/P4/sounds/alreves.wav).