#define _POSIX_C_SOURCE 200201L
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

// randrange(a,b); a & b included
int randrange(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}
//game launch
int launch(){
    mvprintw(2,5,"--------------");
    attron(COLOR_PAIR(2));
    mvprintw(3,5,"CATCH THE BALL");
    attroff(COLOR_PAIR(2));
    mvprintw(4,5,"--------------");
    mvprintw(7,5,"Select level and press P:");
    mvprintw(8,5,"EXPERT");
    mvprintw(9,5,"ADVANCED");
    mvprintw(10,5,"BEGINNER");
    mvprintw(8, 4, ">");
    int pointer_position = 1;
    while (1)
    {
        int input = getch();
        switch(input){
            case 'w': case 'W': case KEY_UP:{
               if (pointer_position != 1)
               {
                   mvprintw((7+pointer_position), 4, " ");
                   pointer_position--;
                   mvprintw((7+pointer_position), 4, ">");
                }
                
            }
        }
        switch(input){
            case 's': case 'S': case KEY_DOWN:{
               if (pointer_position != 3)
               {
                   mvprintw((7+pointer_position), 4, " ");
                   pointer_position++;
                   mvprintw((7+pointer_position), 4, ">");
                }
                
            }
        }
        switch(input){
            case 'p': case 'P':{
              erase();
              return pointer_position;             
            }
        }
    }
    return pointer_position;
}
// first game field draw
void game_field(const int size, char array[size][size]){
    move(0,0);
    printw("+");
    for (int i = 0; i < size; i++)
    {
        printw("-");
    }
    printw("+\n");
    for (int i = 0; i < size; i++)
    {
        printw("|");
        for (int j = 0; j < size; j++)
        {
            printw(" ");
        }
        printw("|\n");
    }
    printw("+");
    for (int i = 0; i < size; i++)
    {
        printw("-");
    }
    printw("+\nSCORE: 0\nPress Q anytime to exit the game");  //22 8
    mvprintw(size, size/2, "_");
    refresh();
}
// time delay 0.001s for drawing city
struct timespec ts = {
    .tv_sec = 0,                    // nr of secs
    .tv_nsec = 0.2 * 1000000000L  // nr of nanosecs
};

int main(){
    srand(time(NULL));
    curs_set(FALSE);
    // init curses
    initscr();
    // set implicit modes
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    // invisible cursor, visibility of cursor (0,1,2)
    curs_set(FALSE);
    // getch() will be non-blocking
    nodelay(stdscr, TRUE);
    // colours
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    //launching the game
    int level = launch();
    // defining game field
    int size = 20;
    char array[size][size];
    // drawing gamefield
    game_field(size, array);
    //game
    int catcher_y = size / 2;
    int i = 0;
    int position = randrange(1, size);
    int counter = 1;
    int is_playing = 1;
    int score = 0;
    while (is_playing)
    {
        // moving catcher right
        int input = getch();
        switch(input){
            case 'd': case 'D': case KEY_RIGHT:{
                if (catcher_y !=size)
                {
                    mvprintw(size, catcher_y, " ");
                    catcher_y++;
                    mvprintw(size, catcher_y, "_");
                    refresh();
                }
            }
        }
        // moving catcher left
        switch(input){
            case 'a': case 'A': case KEY_LEFT:{
                if (catcher_y != 1)
                {
                    mvprintw(size, catcher_y, " ");
                    catcher_y--;
                    mvprintw(size, catcher_y, "_");
                    refresh();
                }
            }
        }
        // setting colour of ball
        if (counter > 10 && counter < 15)
        {
            attron(COLOR_PAIR(1));
            mvprintw(1+i, position, "O");
            refresh();
            mvprintw(1+i, position, " ");
            attroff(COLOR_PAIR(1));
        }
        else if (counter > 14)
        {
            attron(COLOR_PAIR(2));
            mvprintw(1+i, position, "O");
            refresh();
            mvprintw(1+i, position, " ");
            attroff(COLOR_PAIR(2));
        }
        else{
            mvprintw(1+i, position, "O");
           refresh();
            mvprintw(1+i, position, " ");
        }

        for (int i = 0; i < level; i++)
        {
            nanosleep(&ts, NULL);
        }

        i++;
        counter++;
        mvprintw(22, 7, "%d", score);
        
        //checking if player caught the ball
        if (counter == size)
        {
            if (catcher_y != position)
            {
            erase();
            is_playing = 0;
            }
            else
            {
                position = randrange(1, size);
                i = 0;
                counter = 1;
                score++;
            }
        }
        // switching the game off
        switch(input){
            case 'q': case 'Q': {
                is_playing = 0;
                endwin();
                return EXIT_SUCCESS;
            }
        }
    }
    while (1)
    {
        int input = getch();
        mvprintw(5, 5, "You lost!");
        mvprintw(6, 5, "SCORE REACHED: %d", score);
        mvprintw(7,5,"Press Q to exit.");
        nanosleep(&ts, NULL);
        switch(input){
            case 'q': case 'Q': {
                is_playing = 0;
                endwin();
                return EXIT_SUCCESS;
            }
        }
    }
    // end curses
    endwin();
    return EXIT_SUCCESS;
}
