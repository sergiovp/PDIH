## Ejercicios

#### 1. Instalar el software DOSBox y ejecutar aplicaciones de MS-DOS (p.ej. juegos clásicos).
Para la instalación del software, he creado un pequeño [script](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S1/script_instalacion.sh) que descarga el paquete, lo descomprime e instala. También instala dependencias. *Únicamente funciona para distribuciones linux basadas en Debian*. Para ejecutarlo: 
~~~
. ./script_instalacion.sh
~~~

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

Como indica el enunciado, ejecutaremos algunos juegos clásicos. Dichos juegos los he descargado  [aquí](https://www.dosgames.com).

En mi caso, he probado una versión del [pac-man](https://www.dosgames.com/game/ack-man/)  y otra del [tetris](https://www.dosgames.com/game/blocks-from-hell/). 
![](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S1/images/pacman.png) 
![](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S1/images/tetris.png)

#### 2. Configurar el inicio de DOSBox para que monte en la unidad C: el directorio donde se encuentra el entorno de programación Borland C (que incluye las herramientas para compilar no sólo lenguaje C, sino también ensamblador). Añadir a la variable “PATH” de inicio el directorio “bin” donde se encuentra el ejecutable BC.EXE

Al tener ya montada en la unidad C: el contenido de un directorio de mi host, únicamente he tenido que añadir en dicho directorio lo relativo a *Borland*, con lo cual ya puedo compilar programas en ensamblador haciendo uso de *TASM.EXE y TLINK.EXE*.
En lugar de compilar y enlazar manualmente, siguiendo el guión he implementado un script [compilar.bat]().

Para añadir a la variable *PATH* el directorio *BIN* he añadido `set path=%path%;c:\bc\bin` nuevamente en el fichero `~/.dosbox/dosbox-0.74-3.conf`.

#### 3. Crear el ejemplo “Hola mundo” en ensamblador, compilarlo y comprobar su funcionamiento. A continuación incluir un bucle para mostrar el mensaje 7 veces.