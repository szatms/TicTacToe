#include <stdio.h>
#include <stdlib.h>

// -- CONSTANTS

#define ROWS 3
#define COLUMNS 3
#define BUFSIZE 5
#define WARNING "Invalid coordinates! Choose again!"

// -- GAME LOGIC

void my_print(char table[ROWS][COLUMNS]){
    printf("  1 2 3\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf("%d ",i+1);
        for (int j = 0; j < COLUMNS; j++)
        {
            printf("%c ", table[i][j]);
            //printf("#%d-%d",i,j);
        }
        puts("");
    }
    puts("");
}

int is_valid(const char* coords, const int x, const int y, char table[ROWS][COLUMNS]){
    if (atoi(coords) > 33 || table[x][y] != '-')
        return 0;
    return 1;
}

int is_won(char table[ROWS][COLUMNS], char player){
    if (
            table[0][0]==player && table[0][1]==player && table[0][2]==player
        ||
            table[1][0]==player && table[1][1]==player && table[1][2]==player
        ||
            table[2][0]==player && table[2][1]==player && table[2][2]==player
        ||
            table[0][0]==player && table[1][0]==player && table[2][0]==player
        ||
            table[0][1]==player && table[1][1]==player && table[2][1]==player
        ||
            table[0][2]==player && table[1][2]==player && table[2][2]==player
        ||
            table[0][0]==player && table[1][1]==player && table[2][2]==player
        ||
            table[0][2]==player && table[1][1]==player && table[2][0] == player
    )
    {
        return 1;
    }
    return 0;
}

void new_turn(const char player, char table[ROWS][COLUMNS]){
    char coords[BUFSIZE];
    int x, y;

    printf("Player %c! Pick a spot on the table (ie: 13 for row 1 column 3): ", player);
    fgets(coords, BUFSIZE, stdin);
    x = coords[0] - '0' - 1;
    y = coords[1] - '0' - 1;
    if (!is_valid(coords, x, y, table))
    {
        printf("%s\n",WARNING);
        new_turn(player, table);
        return;
    }

    table[x][y] = player;

    system("clear");
    my_print(table);

    if (is_won(table, player))
    {
        printf("Player %c won!\n", player);
        exit(0);
    }
}

int main(){

    char table[ROWS][COLUMNS] = {
        {'-','-','-'},
        {'-','-','-'},
        {'-','-','-'}
    };

// -- CALLING GAME LOGIC FUNCTIONS

    system("clear");
    my_print(table);

    new_turn('x', table);
    new_turn('o', table);
    new_turn('x', table);
    new_turn('o', table);
    new_turn('x', table);
    new_turn('o', table);
    new_turn('x', table);
    new_turn('o', table);
    new_turn('x', table);

    return 0;
}