#!/bin/bash
echo "Descargando paquete..."
wget https://netcologne.dl.sourceforge.net/project/dosbox/dosbox/0.74-3/dosbox-0.74-3.tar.gz  > /dev/null 2>&1

# Si la descarga ha ido bien.
if [ $? -eq 0 ] 
then
    echo "Descarga realizada con éxito, descomprimiendo..."
    tar -xvf dosbox-0.74-3.tar.gz > /dev/null 2>&1
    cd dosbox-0.74-3
    echo "Instalando dependencias..."
    apt update
    apt install gcc g++ build-essential libc6-dev libsdl1.2-dev libsdl-image1.2-dev -y
    echo "Compilando e instalando..."
    ./configure
    make
    make install
else
    echo "Ha habido un error :("
    exit
fi