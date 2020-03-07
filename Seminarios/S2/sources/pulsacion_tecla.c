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

int main() {

    char tecla;

    printf("Pulsa una tecla. Pulsa 'q' para terminar\n");

    do {
        tecla = get_caracter();
        printf("\nLa tecla pulsada es: <%c>\n", tecla);
    } while (tecla != 'q');

    return 0;
}
