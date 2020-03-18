#include <stdio.h>
#include <stdlib.h>
#include <dos.h>

int get_caracter(void) {
    union REGS inregs, outregs;
    char caracter;

    inregs.h.ah = 1;

    int86(0x21, &inregs, &outregs);

    caracter = outregs.h.al;

    return caracter;
}

void mi_putchar(char c){
    union REGS inregs, outregs;

	inregs.h.ah = 2;
	inregs.h.dl = c;

	int86(0x21, &inregs, &outregs);
}

int main() {

    char tecla;

    do {
        printf("\nPulsa una tecla. Pulsa 'q' para terminar: ");
        tecla = get_caracter();
        printf("\nLa tecla pulsada es: ");
        mi_putchar(tecla);
    } while (tecla != 'q');

    return 0;
}
