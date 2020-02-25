@echo off

REM Hay que pasarle un fichero ensamblador sin la extensión

if "%1"=="" goto :error_parametros

if NOT EXIST "%1.asm" goto :error_parametros

REM Compilamos, enlazamos y depuramos
c:\BC\BIN\TASM /zi %1.asm
c:\BC\BIN\TLINK /v %1.obj

goto :fin

:error_parametros
    echo ERROR: Necesito un fichero en ensamblador sin extensión
:fin