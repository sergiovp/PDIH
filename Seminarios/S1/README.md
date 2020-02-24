## Ejercicios

#### 1. Instalar el software DOSBox y ejecutar aplicaciones de MS-DOS (p.ej. juegos clásicos).
Para la instalación del software, he creado un pequeño [script](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S1/script_instalacion.sh) que descarga el paquete, lo descomprime e instala. También instala dependencias. *Únicamente funciona para distribuciones linux basadas en Debian*. Para ejecutarlo, `. ./script_instalacion.sh`.

Para la configuración he seguido el guión, por lo tanto:

+ Añadir en la sección `autoexec` del fichero `~/.dosbox/dosbox-0.74-3.conf` lo siguiente:
~~~
# Montar en la unidad C: el contenido del directorio de nuestro host
mount C /home/vela/Universidad/PDIH/DOSBOX
# Teclado español
keyb sp
~~~

Para comprobar que todo esté correcto, nos deberá aparecer lo siguiente cuando arranquemos *DosBox*.
![](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S1/images/configuraci%C3%B3n.png)

Ahora, podemos ejecutar aplicaciones, más en concreto, juegos clásicos. La página de la que me he descargado los juegos es [esta](https://www.dosgames.com).

En mi caso, he probado una versión del [pac-man](https://www.dosgames.com/game/ack-man/)  y otra del [tetris](https://www.dosgames.com/game/blocks-from-hell/). 
![](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S1/images/pacman.png) 
![](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S1/images/tetris.png) 