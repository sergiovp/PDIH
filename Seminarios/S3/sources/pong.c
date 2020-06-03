#include <ncurses.h>
#include <unistd.h>

#define DELAY 4000

typedef struct {
    short int x, y, c; 
    bool movhor, movver;
} object;

int main() {
    object scr; 
    int i = 0, cont = 0; 
    int end = 0;
    
    initscr();
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    keypad(stdscr,true);
    noecho();
    curs_set(0);

    getmaxyx(stdscr,scr.y,scr.x);
    object b1 = {scr.x - 2, scr.y / 2, 0, 0, 0};
    object b2 = {1, scr.y / 2, 0, 0, 0};
    object b = {scr.x / 2, scr.y / 2, 0, 0, 0};

    mvprintw(0,0, "Jugador 1 controles. 'a' hacia abajo, 'q' hacia arriba.\n"
                "Jugador 2 controles. Las flechas del teclado.\n"
                "Pulsa cualquier tecla para empezar, 'p' para pausar y 'esc' para salir.");

    getch();
    for (nodelay(stdscr,1); !end; usleep(DELAY)) {
        if (++cont % 16 == 0) {
        if ((b.y == scr.y - 1) || (b.y == 1))
            b.movver =! b.movver;
        if ((b.x >= scr.x - 2) || (b.x <= 2)) {
            b.movhor =! b.movhor;
            if ((b.y == b1.y - 1) || (b.y == b2.y - 1)) {
            b.movver = false;
            } else if ((b.y == b1.y + 1) || (b.y == b2.y + 1)) {
            b.movver = true;
            } else if ((b.y != b1.y) && (b.y != b2.y)) {
            (b.x >= scr.x - 2) ? b1.c++ : b2.c++;
            b.x = scr.x / 2;
            b.y = scr.y / 2;
            }
        }
        b.x = b.movhor ? b.x + 1 : b.x - 1;
        b.y = b.movver ? b.y + 1 : b.y - 1;

        if (b1.y <= 1)
            b1.y = scr.y - 2;
        if (b1.y >= scr.y - 1)
            b1.y = 2;
        if (b2.y <= 1)
            b2.y = scr.y - 2;
        if (b2.y >= scr.y - 1)
            b2.y = 2;
        }
        switch (getch()) {
        case KEY_DOWN: b1.y++; break;
        case KEY_UP:   b1.y--; break;
        case 'q':      b2.y--; break;
        case 'a':      b2.y++; break;
        case 'p':      getchar(); break;
        case 0x1B:    endwin(); end++; break;
        }
        erase();
        mvprintw(2, scr.x / 2 - 2,"%i | %i", b1.c, b2.c);
        mvvline(0, scr.x / 2, ACS_VLINE, scr.y);
        attron(COLOR_PAIR(1));
        mvprintw(b.y, b.x, "o");
        
        for(i = -1; i < 2; i++){
        mvprintw(b1.y + i, b1.x, "|");
        mvprintw(b2.y + i, b2.x, "|");}
        attroff(COLOR_PAIR(1));
    }
}
