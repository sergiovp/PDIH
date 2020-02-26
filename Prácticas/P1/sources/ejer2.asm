TEXTO40x25BN	EQU 0
TEXTO40x25C		EQU 1
TEXTO80x25BN	EQU 2
TEXTO80x25C		EQU 3
GRAFICO EQU 4

BLANCO  EQU 3
ROSA    EQU 2
VERDE   EQU 1

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

; MACRO pixel
; Pone un pixel en la coordenada X,Y de color C
pixel MACRO X,Y,C
        push ax
        push cx
		push dx
		mov ax,Y
		mov cx,X
		mov dx,ax
        mov al,C
        mov ah,0Ch
        int 10h
        pop dx
        pop cx
		pop ax
ENDM

pila segment stack 'stack'
	dw 100h dup (?)
pila ends

datos segment 'data'
		msg_informacion db 13,10,'Presione cualquier tecla para entrar en modo grafico...',13,10,'$'
		msg_final db 13,10,'Modo texto 80x25 restablecido.',13,10,'$'
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

        ; Pasamos a modo gráfico
		modo_video GRAFICO

		;pintar linea horizontal superior
		mov cx,240
        mov bx,80
		bucle1:
			pixel cx,50,ROSA
			dec cx
            cmp cx,bx
			jne bucle1

        ;pintar linea horizontal inferior
		mov cx,240
        mov bx,80
		bucle2:
			pixel cx,100,ROSA
			dec cx
            cmp cx,bx
			jne bucle2

        ;pintar linea vertical izquierda
		mov cx,50
        mov bx,101
		bucle3:
			pixel 80,cx,ROSA
			inc cx
            cmp cx,bx
			jne bucle3

        ;pintar linea vertical derecha
		mov cx,50
        mov bx,101
		bucle4:
			pixel 240,cx,ROSA
			inc cx
            cmp cx,bx
			jne bucle4

        ; Punto rosa
		pixel 160,75,ROSA

        ; Punto verde
		pixel 100,80,VERDE

        ; Punto blanco
		pixel 220,70,BLANCO

        ; Punto verde
		pixel 100,70,BLANCO

        ; Punto blanco
		pixel 220,80,VERDE

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
