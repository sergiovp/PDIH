#include <ncurses.h>
#include <stdlib.h>

int main () {
    int rows, cols;
    initscr();

    if (has_colors() == FALSE) {
        endwin();
        printf("El terminal no tiene soporte de color.\n");
        exit(1);
    }

    start_color();

    init_pair(1, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    init_pair(3,COLOR_WHITE,COLOR_BLUE);

    clear();
    refresh();

    getmaxyx(stdscr, rows, cols);

    WINDOW *window = newwin(rows,cols,0,0);

    wbkgd(window, COLOR_PAIR(1));
    box(window, '|', '-');
    mvwprintw(window, 10, 10, "Que pasa gente");
    wrefresh(window);

    mvwprintw(window, 15, 1, "Este otro ejemplo es de regalo.");
    wrefresh(window);
    getch();
    endwin();

    return 0;
}

