## Visión por computador.

A la hora de escoger tema para presentar, me llamó mucho la atención la visión por computador, era un tema sobre el que había escuchado, incluso había visto algún que otro vídeo pero nunca había tocado.

En este pequeña presentación, expliqué brevemente qué es la visión por computador y qué biblioteca había utilizado para hacer los ejemplos.

### Guión

![portada](https://github.com/sergiovp/PDIH/tree/master/Exposición/images/P1.png)

La visión por computador es la disciplina que incluye métodos para adquirir, proesar, analizar y comprender las imágenes del mundo real con el fin de producit información numérica para que puedan ser tratados por un ordenador.

A modo de ejemplo, nos podríamos preguntar **¿qué ocurre cuando un humano ve una imagen?**
La respuesta es sencilla, éste será capaz de reconocer caras de personas, distitos objetos, el número de coches que ha captado la imagen y un largo etcétera. Pues bien, la visión por computador permite a los ordenadores ver y procesar estos datos visuales tal y como los hacemos los humanos.

![utilidades](https://github.com/sergiovp/PDIH/tree/master/Exposición/images/P2.png)

Hay infinidad de utilidades, entre las que podríamos destacar:

+ Reconocimiento facial. En los aeropuertos, por ejemplo, en los que introduces el pasaporte en una especie de lector y mirando hacia una cámara, detectará si realmente eres tú. Lo podemos ver también en las cámaras de móvil, cuando al ir a sacar una foto detecta cuantas personas hay, retratos robots de la policia, etc.

+ Detección de objetos. Con cámaras en las carreteras se podría detectar el nivel de tráfico que hay. También en coches autonónomos, que son capaces de detectar los límites de la carretera y obstáculos.

+ Interacción hombre-máquina "más natural". Mediante la interpretación de gestos.

![utilidades](https://github.com/sergiovp/PDIH/tree/master/Exposición/images/P3.png)

+ Detección de anomalías en cámaras de seguridad. Podemos detectar la presensia de personas.

+ Ámbito médico. Mediante patrones y características se podrían detectar enfermedades.

![OpenCV](https://github.com/sergiovp/PDIH/tree/master/Exposición/images/P4.png)
Este tipo de cosas se podrían implementar utilizando **OpenCV** (Open Computer Vision), es una biblioteca opensource. El código lo podemos encontrar [aquí](https://github.com/opencv/opencv). Inicialmente fue desarrollada por Intel en el año 99 y actualmente se la sigue considenrando la biblioteca más popular de visión por computador.

![Ejemplos](https://github.com/sergiovp/PDIH/tree/master/Exposición/images/P5.png)

A modo de ejemplo, se han implementado tres pequeños programas en phyton.

En [emeplo1.py]() podemos ver cómo el programa detecta a las personas del vídeo en movimiento.
![Ejemplos1](https://github.com/sergiovp/PDIH/tree/master/Exposición/images/gente1.png)

En [ejemplo2.py]() se abrirá la cam de nuestro ordenador y se detectará la cara.
![Ejemplos1](https://github.com/sergiovp/PDIH/tree/master/Exposición/images/yo1.png)

En [ejemplo2.py]() a parte de detectar la cara, también se detectará los ojos.
![Ejemplos1](https://github.com/sergiovp/PDIH/tree/master/Exposición/images/yo2.png)

En estos dos últimos ejemplos he utilizado los clasificadores que nos proporciona OpenCV, los cuales se pueden encontrar [aquí](https://github.com/opencv/opencv/tree/master/data).

A modo de curiosidad, destacar que si quieres pasar desarpecibido en algún momento frente a técnicas de este tipo, te recomiendo que leas la siguiente noticia.
![Ejemplos1]()

Webgrafía:

+ [Curso OpenCV](https://www.youtube.com/playlist?list=PLS1QulWo1RIa7D1O6skqDQ-JZ1GGHKK-K)

+ [Pequeña presentación de visión por computador](http://www.ehu.eus/ccwintco/uploads/d/d4/PresentacionMundoVirtual.pdf)

+ [Visión por computador (Wikipedia)](https://www.google.es/url?sa=t&rct=j&q=&esrc=s&source=web&cd=8&cad=rja&uact=8&ved=2ahUKEwib96jL-sLpAhUnDWMBHUMXAaYQFjAHegQIEBAF&url=https%3A%2F%2Fes.wikipedia.org%2Fwiki%2FVisi%25C3%25B3n_artificial&usg=AOvVaw3h7AN6yrFwNY8Q2k32ujaF)

+ [OpenCV](https://opencv.org/)

+ [Documentación OpenCV](https://docs.opencv.org/)

+ [Proyecto de OpenCV (GitHub)](https://github.com/opencv/opencv)

+ [Clasificadores](https://github.com/opencv/opencv/tree/master/data)