#include <stdio.h>
#include <stdlib.h>
#include <dos.h>

void cambio_modo_video(unsigned char modo) {
    union REGS inregs, outregs;

    inregs.h.ah = 0;
    inregs.h.al = modo;

    int86(0x10, &inregs, &outregs);

    printf("Modo de texto <%u> activado\n", modo);
}

int main(int argc, char **argv) {
    
    unsigned char modo;

    if (argc < 2) {
        printf("Debes introducir un parámetro\n");
        exit(0);
    }

    modo = atoi(argv[1]);

    if (modo > 7) {
        modo = 0;
    }

    cambio_modo_video(modo);

    return 0;
}