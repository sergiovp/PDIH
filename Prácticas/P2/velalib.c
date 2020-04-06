/*
    Vela's library.
*/

#include <stdio.h>
#include <dos.h>

/* Coloca el cursor en una posición determinada */
void gotoxy(int row, int col) {
    union REGS inregs, outregs;

    inregs.h.ah = 2;
	inregs.h.dh = row;
	inregs.h.dl = col;
    inregs.h.bh = 0;

    int86(0x10, &inregs, &outregs);
}

/* 
    Fijar el aspecto del cursor, debe admitir tres valores: INVISIBLE, NORMAL y GRUESO.
    0 -> invisible
    1 -> Normal
    2 -> Grueso
    En caso de que le pasemos un valor distinto de 0, 1 o 2, pondremos el cursol normal.
*/
void setcursortype(int type) {

    union REGS inregs, outregs;
	inregs.h.ah = 0x01;

	switch(type) {
		case 0: // invisible
			inregs.h.ch = 010;
			inregs.h.cl = 000;
			break;

		case 1: // normal
			inregs.h.ch = 010;
			inregs.h.cl = 010;
			break;

		case 2: // grueso
			inregs.h.ch = 000;
			inregs.h.cl = 010;
			break;
        
        default: // normal
            inregs.h.ch = 010;
			inregs.h.cl = 010;
			break;
	}
	int86(0x10, &inregs, &outregs);
}

void mi_pausa(){
   union REGS inregs, outregs;
	 inregs.h.ah = 8;
	 int86(0x21, &inregs, &outregs);
}

/* Fija el modo de video deseado */
void setvideomode(unsigned char mode) {
    union REGS inregs, outregs;

    inregs.h.ah = 0;
    inregs.h.al = mode;

    int86(0x10, &inregs, &outregs);
}

/* Obtiene el modo de video actual */
unsigned int getvideomode() {

}

/* Modifica el color de primer plano con que se mostrarán los caracteres */
void textcolor() {

}

/* Modifica el color de fondo con que se mostrarán los caracteres */
void textbackground() {

}

/* Borra toda la pantalla */
void clrscr() {

}

/* Escribe un carácter en pantalla con el color indicado actualmente */
void cputchar() {

}

/* Obtiene un carácter de teclado y lo muestra en pantalla */
void getche() {

}

int main() {
    int row = 5;
    int col = 3;
    //gotoxy(row, col);

    printf("\nCursor invisible: ");
   	setcursortype(0);
   	mi_pausa();
    printf("Debe de aparecer el cursor normal: ");
    setcursortype(-5);
    mi_pausa();
   	printf("\nCursor grueso: ");
   	setcursortype(2);
   	mi_pausa();
   	printf("\nCursor normal: ");
   	setcursortype(1);
   	mi_pausa();
}