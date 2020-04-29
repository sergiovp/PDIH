install.packages('tuneR', dep=TRUE)
install.packages('seewave', dep=TRUE)

library(tuneR)
library(seewave)
library(audio)

setwd("/home/vela/PDIH/Prácticas/P4/sources") # Direcotorio de trabajo.
setWavPlayer('/usr/bin/celluloid')            # Ruta reproductor a usar. 

# Leemos el fichero del perro.
perro <- readWave('../sounds/perro.wav')

# Mostramos información del fichero cargado.
perro

# Escuchamos el audio del perro.
listen(perro)

# Leemos el fichero del gato.
gato <- readMP3('../sounds/gato.mp3')

# Mostramos información del fichero cargado.
gato

# Escuchamos el audio del gato.
listen(gato)

# Dibujamos onda del gato y del perro
plot(extractWave(gato, from = 1, to = length(gato)))
plot(extractWave(perro, from = 1, to = length(perro)))

# Mostramos información de cabeceras del gato y del perro
str(gato)
str(perro)

# Unimos en un mismo objeto el sonido del gato y del perro
gato_y_perro <- pastew(perro, gato, output="Wave")

# Escuchamos el audio del gato y del perro.
listen(gato_y_perro)

# Dibujamos onda del gato y del perro
plot(extractWave(gato_y_perro, from = 1, to = length(gato_y_perro)))

# Filtro para eliminar frecuencias entre 10000Hz y 20000Hz
f <-  gato_y_perro@samp.rate
filtro_gato_y_perro <- bwfilter(gato_y_perro, f = f, channel = 1, n = 1, 
                                from = 10000, to = 20000, bandpass = TRUE, output = "Wave")

# Almacenar la señal obtenida como un fichero WAV
writeWave(filtro_gato_y_perro, file.path("../sounds/mezcla.wav"))

# Cargamos un nuevo fichero de sonido
oveja <- readWave('../sounds/oveja.wav')

# Le aplicamos eco
ovejaECO <- echo(oveja, f = 22050, amp = c(0.8, 0.4, 0.2),
                 delay = c(1, 2, 3), output = "Wave")

# Multiplicamos las muestras para incrementar la amplitud
ovejaECO@left <- 1000 * ovejaECO@left

# Le damos la vuelta al sonido
ovejaECOalreves <- revw(ovejaECO, output="Wave")

# Lo guardamos
writeWave(ovejaECOalreves, file.path("../sounds/alreves.wav"))