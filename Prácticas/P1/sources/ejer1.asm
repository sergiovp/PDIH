TEXTO40x25BN	EQU 0
TEXTO40x25C		EQU 1
TEXTO80x25BN	EQU 2
TEXTO80x25C		EQU 3

; MACRO pausa_tecla
; Espera la pulsacion de una tecla
pausa_tecla MACRO
        push ax
        mov ah,0   ;funcion para leer una tecla
        int 16h    ;interrupcion BIOS para teclado
        pop ax
ENDM

; MACRO modo_video
; Cambia el modo de video
modo_video MACRO modo
        push ax
        mov al,modo
        mov ah,0
        int 10h
        pop ax
ENDM

pila segment stack 'stack'
	dw 100h dup (?)
pila ends

datos segment 'data'
		msg_informacion db 13,10,'Presione cualquier tecla, para entrar en modo texto 40x25...',13,10,'$'
		msg_texto db 13,10,'Modo texto 40x25 activado, presiona cualquier tecla para volver...',13,10,'$'
		msg_final db 13,10,'Se ha restablecido el modo texto',13,10,'$'
datos ends


codigo segment 'code'
	assume cs:codigo, ds:datos, ss:pila
	main PROC
		mov ax,datos
		mov ds,ax

		mov dx,OFFSET msg_informacion
		mov ah,9
		int 21h
		pausa_tecla

		; Cambiamos el modo
		modo_video TEXTO40x25C

		mov dx,OFFSET msg_texto
		mov ah,9
		int 21h

		; Pausamos y volvemos a 80x25
		pausa_tecla
		modo_video TEXTO80x25C

		mov dx,OFFSET msg_final
		mov ah,9
		int 21h

		mov ax,4C00h
		int 21h
	main ENDP
codigo ends

END main
