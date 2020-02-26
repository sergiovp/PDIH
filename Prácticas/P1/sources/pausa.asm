pila segment stack 'stack'
    dw 100h dup (?)
pila ends
datos segment 'data'
    cadena db 13,10,'pulsa una tecla...',13,10,'$'
datos ends
codigo segment 'code'
    assume cs:codigo, ds:datos, ss:pila
    main PROC
        mov ax,datos
        mov ds,ax
        
        mov dx,OFFSET cadena
        mov ah,9
        int 21h
        
        mov ah,8
        int 21h

        mov ax,4C00h
        int 21h
    main ENDP
codigo ends

END main
