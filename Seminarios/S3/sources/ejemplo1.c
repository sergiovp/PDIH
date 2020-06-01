/*
    Programa básico usando ncurses para mostrar
    un mensaje por pantalla.
*/

#include <ncurses.h>

int main() {
    initscr();          // Inicializamos modo curses 

    printw("Hello people!!");   // Imprimimos mensaje (aún no se verá)
    refresh();          // Mostramos el mensaje por pantalla
    getch();            // Esperamos hasta que se pulse una tecla

    endwin();           // Terminamos modo curses (liberamos memoria) 

    return 0;
}
