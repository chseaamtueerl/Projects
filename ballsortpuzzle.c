#include <stdio.h>
#include <stdlib.h> 
#include "ballsortpuzzle.h"
#include <time.h>
#include <stdbool.h>

// randrange(a,b); a & b included
int randrange(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

// task 1
void generator(const int rows, const int columns, char field[rows][columns]){
    // srand(time(0));
    // 2 empty columns
    int empty_1 = randrange(0, columns - 1);
    int empty_2 = randrange(0, columns - 1);
    while (empty_2 == empty_1)
    {
        empty_2 = randrange(0, columns - 1);
    }
    // filling empty columns
    for (int i = 0; i < rows; i++)
    {
        field[i][empty_1] = BLANK;
    }

     for (int i = 0; i < rows; i++)
    {
        field[i][empty_2] = BLANK;
    }
    // filling others columns
    int symbols[6][2];
    symbols[0][0] = 'O';
    symbols[1][0] = '&';
    symbols[2][0] = '%';
    symbols[3][0] = '+';
    symbols[4][0] = '@';
    symbols[5][0] = '#';
    symbols[0][1] = 0;
    symbols[1][1] = 0;
    symbols[2][1] = 0;
    symbols[3][1] = 0;
    symbols[4][1] = 0;
    symbols[5][1] = 0;
    // generating array
    for (int i = 0; i < columns; i++)
    {   if ((i != empty_1) && (i != empty_2))
        {
            for (int j = 0; j < rows; j++)
            {   
                int index = randrange(0, columns - 3);
                while (symbols[index][1] == rows)
                {
                    index = randrange(0, columns - 3);
                }
                field[j][i] = (char)symbols[index][0];
                symbols[index][1]++;
            }
        }
    }
    return;
}

// task 2
void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y){
    if (x == y)
    {
        printf("Moving to same column is not moving...\n");
        return;
    }
    if (x > columns || y > columns)
    {
        printf("Can you see there more than %d columns?!\n", columns);
        return;
    }
    
    
    // find 1st symbol in column (starts at top)
    char symbol = field[0][x - 1];
    int i = 1;
    while (symbol == BLANK)
    {
        if (i == rows)
        {
            return;
        }
        symbol = field[i][x-1];
        i++;
       
    }
    // checking if destination column isnt full
    if (field[0][y - 1] != BLANK)
    {
        printf("Column is full, look better...\n");
        return;
    }
    // find right position in destination column 
    char destination = field[0][y - 1];
    int j = 1;
    while (destination == BLANK)
    {   
        if (j == rows)
        {
            break;
        }
        destination = field[j][y-1];
        if (destination == BLANK)
        {
            j++;
        }
    }
    if (j != rows)
    {
        if (field[j][y - 1] == symbol)
        {
            field[j-1][y-1] = symbol;
            field[i-1][x-1] = BLANK;
        }
        else
        {
            printf("You can't place character to different one...\n");
            return;
        }
    }
    else
    {
        field[j-1][y-1] = symbol;
        field[i-1][x-1] = BLANK;
    }
    printf("Great move!\n");
    return;
}

// task 3
bool check(const int rows, const int columns, char field[rows][columns]){
    char first_symbol = ' ';
    // checking if every symbol in every column is the same
    for (int i = 0; i < columns; i++)
    {
        first_symbol = field[0][i];
        for (int j = 0; j < rows; j++)
        {
           if (field[j][i] != first_symbol)
           {
               return false;
           }
            
        }
        
    }
    return true;
}

// task 4
void game_field(const int rows, const int columns, char field[rows][columns]){
    printf("\n");
    for(int i = 0; i < rows; i++){
        // printf("%d ", i + 1);
        for(int j = 0; j < columns; j++){
            printf("║%c║ ", field[i][j]);
        }
        printf("\n"); // new line
    }
    //printf(" ");
    for (int i = 0; i < columns; i++)
    {
        printf("╚═╝ ");
    }
    printf("\n ");
    for (int i = 0; i < columns; i++)
    {
        printf("%d   ", i + 1);
    }
    printf("\n");
    return;
}

// task 5
void ball_sort_puzzle(){
    int columns;
    int rows;
    printf("Welcome to the BALLSORTPUZZLE game!\nAt first, choose how many columns you want to play (4-8): ");
    scanf("%d", &columns);
    printf("Now, choose how high columns will be: ");
    scanf("%d", &rows);
    char field[rows][columns];
    generator(rows, columns, field);
    game_field(rows, columns, field);
    int x = 0;
    int y = 0;
    while (check(rows, columns, field) == false)
    {
        printf("FROM ");
        scanf("%d", &x);
        printf("TO ");
        scanf("%d", &y);
        down_possible(rows, columns, field, x, y);
        game_field(rows, columns, field);
    }
    printf("Congratulation! You won €1\n");
}