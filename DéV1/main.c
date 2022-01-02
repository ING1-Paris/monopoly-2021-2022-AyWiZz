#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"
#include <windows.h>

void gotoligcol( int lig, int col )
{
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void des(int x,int *px)
{

    int nbr = 0, a = 1;
    const int max = 6, min = 1;
    srand(time(NULL));
    for (int i=0; i<2; i++){

        nbr = (rand() % (max - min + 1)) + min;
        x+=nbr;
        gotoligcol(a,1);
        printf("%c", 0xDA);
        for (int j=0; j<7; j++){
            printf("%c", 0xC4);
        }
        printf("%c", 0xBF);
        a+=1;
        gotoligcol(a, 1);
        printf("%c       %c", 0xB3, 0xB3);
        a+=1;
        gotoligcol(a, 1);
        printf("%c   %d   %c", 0xB3, nbr, 0xB3);
        a+=1;
        gotoligcol(a, 1);
        printf("%c       %c", 0xB3, 0xB3);
        a+=1;
        gotoligcol(a, 1);
        printf("%c", 0xC0);
        for (int j=0; j<7; j++){
            printf("%c", 0xC4);
        }
        printf("%c\n", 0xD9);
        a+=1;
    }

    *px=x;

}




int main ()
{
    int x = 0;
    int *px = &x;
    des(x,px);
    printf("%d", *px);
}

