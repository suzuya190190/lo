/*========================================
 * ($_$).oO keisuke Yamagishi 
 * (¥_¥).oO 2015/0411
 * (#_#).oO　I edit  lol
 *========================================
 */

#include <curses.h>
#include <signal.h>
#include <unistd.h>
#include "lo.h"

void add_com(int y, int x);
int add_lol(int x);
void option(char *str);
int move_str(int y, int x, char *str);

int com_name  = 0;
//remove string!!!!
int move_str(int y, int x, char *str)
{
    for ( ; x < 0; ++x, ++str)
        if (*str == '\0')  return ERR;
    for ( ; *str != '\0'; ++str, ++x)
        if (mvaddch(y, x, *str) == ERR)  return ERR;
    return OK;
}

/*
 * option comand
 */
void option(char *str)
{
    extern int com_name;
    while (*str != '\0') {
        switch (*str++) {
            case 's': com_name = 1; break;
            default:                break;
        }
    }
}

int main(int argc, char *argv[])
{
    int x, i;

    for (i = 1; i < argc; ++i) {
        if (*argv[i] == '-') {
            option(argv[i] + 1);
        }
    }
    initscr();
    signal(SIGINT, SIG_IGN);
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    leaveok(stdscr, TRUE);
    scrollok(stdscr, FALSE);

    for (x = COLS - 1; ; --x) {
        if (add_lol(x) == ERR) break;
        getch();
        refresh();
        usleep(40000);
    }
    mvcur(0, COLS - 1, LINES - 1, 0);
    endwin();
}

int add_lol(int x)
{
    static char *shi_c[10 + 1]
        = {SHI01, SHI02, SHI03, SHI04, SHI05,
           SHI06, SHI07, SHI08, SHI09, SHI10, DEL};
    int y=0;

    if (x < - 80)  return ERR;
    y = LINES / 2 - 5;

    for (int i = 0; i <= 10; ++i) {
        move_str(y + i, x, shi_c[i]);
    }
    return OK;
}

void add_com(int y, int x)
{
    static char *com[2][2] = {{"shiChimiTouCarashi ", "(O)"}, {"lol", "\\O/"}};
    int i;

    for (i = 0; i < 2; ++i) {
        move_str(y + i, x, com[(84 + x) / 12 % 2][i]);
    }
}