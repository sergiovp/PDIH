/*
    Vela's library.
*/

#include <stdio.h>
#include <dos.h>

unsigned int TEXT_COLOR = 7;
unsigned int BACK_COLOR = 0;
unsigned int MODO_TEXTO = 3;
unsigned int MODO_VIDEO = 4;

/* Coloca el cursor en una posición determinada */
void gotoxy(int row, int col) {
    union REGS inregs, outregs;

    inregs.h.ah = 0x02;

	inregs.h.dh = row;
	inregs.h.dl = col;

    inregs.h.bh = 0x00;

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

/* Para continuar, deberemos pulsar una tecla */
void mi_pausa(void){
   union REGS inregs, outregs;

	inregs.h.ah = 8;

	int86(0x21, &inregs, &outregs);
}

/* Fija el modo de video deseado */
void setvideomode(unsigned char mode) {
    union REGS inregs, outregs;

    inregs.h.ah = 0x00;
    inregs.h.al = mode;

    int86(0x10, &inregs, &outregs);
}

/* Obtiene el modo de video actual */
unsigned int getvideomode(void) {
    union REGS inregs, outregs;

    inregs.h.ah = 0xF;

    int86(0x10, &inregs, &outregs);

    return outregs.h.al;
}

/* Modifica el color de primer plano con que se mostrarán los caracteres */
void textcolor(int color) {
    TEXT_COLOR = color;
}

/* Modifica el color de fondo con que se mostrarán los caracteres */
void textbackground(int color) {
    BACK_COLOR = color;
}

/* Borra toda la pantalla */
void clrscr(void) {
    union REGS inregs, outregs;

    inregs.h.ah = 0x06;
    inregs.h.al = 0;
    inregs.h.ch = 0;
    inregs.h.cl = 0;

    inregs.h.bh = (BACK_COLOR << 4) | TEXT_COLOR;

    inregs.h.dh = 100;
    inregs.h.dl = 100;

    int86(0x10, &inregs, &outregs);

    gotoxy(0, 0);
}

/* Escribe un carácter en pantalla con el color indicado actualmente */
void cputchar(char caracter) {
    union REGS inregs, outregs;

    inregs.h.ah = 0x09;

    inregs.h.al = caracter;
    inregs.h.bl = (BACK_COLOR << 4) | TEXT_COLOR;
    inregs.h.bh = 0x00;
    inregs.x.cx = 1;

    int86(0x10, &inregs, &outregs);
}

/* Obtiene un carácter de teclado y lo muestra en pantalla */
char getche(void) {
    union REGS inregs, outregs;

    inregs.h.ah = 1;

    int86(0x21, &inregs, &outregs);

    return outregs.h.al;
}

void rectangulo_texto(int x1, int y1, int x2, int y2) {
    union REGS inregs, outregs;
    
    clrscr();

    inregs.h.ah = 0x06;
    inregs.h.al = 0;
    inregs.h.ch = x1;
    inregs.h.cl = y1;

    textcolor(3);
    textbackground(3);
    inregs.h.bh = (BACK_COLOR << 4) | TEXT_COLOR;

    inregs.h.dh = x2;
    inregs.h.dl = y2;

    int86(0x10, &inregs, &outregs);

}

int main() {

    printf("\nCursor invisible: ");
   	setcursortype(0);
   	mi_pausa();
    
   	printf("\nCursor grueso: ");
   	setcursortype(2);
   	mi_pausa();

   	printf("\nCursor normal: ");
   	setcursortype(1);
   	mi_pausa();

    setvideomode(MODO_VIDEO);
    printf("Estamos en modo <%u>, vídeo\n", getvideomode());
    mi_pausa();
    setvideomode(MODO_TEXTO);
    printf("Estamos en modo <%u>, texto\n", getvideomode());
    mi_pausa();

    printf("Introduce un carácter: ");
    printf("\nEl carácter es: <%c>", getche());

    printf("\nMostramos la letra <V> con otros colores\n");

    textcolor(11);
    textbackground(6);
    cputchar('V');

    gotoxy(10, 1);
    printf("Hemos movido el cursor\n");
    printf("Pulsa una tecla y se limpiará la pantalla\n");

    mi_pausa();
    textcolor(7);
    textbackground(0);
    clrscr();
    gotoxy(0, 0);
    
    rectangulo_texto(5, 35, 10, 35);

    return 0;
}
