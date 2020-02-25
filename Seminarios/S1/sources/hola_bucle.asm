pila segment stack 'stack'
	dw 100h dup (?)
pila ends
datos segment 'data'
	msg db 'hola $'
datos ends
codigo segment 'code'
	assume cs:codigo, ds:datos, ss:pila
	main PROC
		mov ax, datos
		mov ds, ax
        xor cx, cx      ; Inicializamos cx a 0

        bucle:
            mov dx, OFFSET msg
            mov ah, 9   ; Función visualización cadena de caracteres
		    int 21h     ; Llamamos a la función 9 para visualizar la cadena
            inc cx      ; Incrementamos cx
            cmp cx, 7   ; Comprobamos si cx es 7
            jne bucle   ; Si cx != 7 volvemos a iterar

		mov ax, 4C00h
		int 21h
    main ENDP
codigo ends

END main