# Seminario 7. El lenguaje Postscript.

El lenguaje PostScript (**PS**) es el código de programación que se usa para decirle a una impresora qué y cómo debe imprimir, paso a paso.

PS es un lenguaje interpretado, de forma que se necesita un procesador o intérprete (un dispositivo físico o un programa en el ordenador) entre el código PS y la impresora física.

Si abrimos un archivo PS, veremos una serie de simples instrucciones escritas en formato texto plano. Esas instrucciones, habitualmente "vectoriales", vienen a decir cosas como "traza un círculo de 3 cm. de radio", o "dibuja una línea de 4,5 cm. en un ángulo de 45 grados", etc.

Como cuestiones a resolver, se propone conocer cómo utilizar el lenguaje Postscript a nivel básico. Para ello, crearemos varios archivos Postscript para aprender cómo crear figuras, líneas, textos y establecer propiedades de esos elementos.

### Ejemplo 1.

En este primer ejemplo, mostraremos texto estableciendo ciertas propiedades como el tamaño o el color.

El fichero con el código es [ejemplo_texto.ps](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S7/sources/ejemplo_texto.ps) y el resultado obtenido es el siguiente:

![](https://github.com/sergiovp/PDIH/blob/master/Seminarios/S7/images/ejemplo_texto.png)

### Ejemplo 2.