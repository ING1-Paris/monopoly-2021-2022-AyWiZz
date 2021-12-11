#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
//////////////////// CETTE FONCTION VIENT DE LA SECTION PROJET INFORMATIQUE///////////////////////
void gotoligcol( int lig, int col ) {

// ressources

COORD mycoord;

mycoord.X = col;

mycoord.Y = lig;

SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

}
///////////////////////////////////////////////////////////////////////////////
///////////// CES FONCTIONS VIENNENT DU TUTORAT////////////////////////////////
void setConsoleSize(short width, short height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {.X=width, .Y=height};
    SMALL_RECT rect = {.Left=0, .Top=0, .Right=width-1, .Bottom=height-1};

    SetConsoleScreenBufferSize(hStdout, coord);
    SetConsoleWindowInfo(hStdout, 1, &rect);
}

void setConsoleFullscreen()
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD maxi = GetLargestConsoleWindowSize(hStdout);
    SMALL_RECT rect = {.Left=0, .Top=0, .Right=maxi.X-1, .Bottom=maxi.Y-1};

    SetConsoleScreenBufferSize(hStdout, maxi);
    SetConsoleWindowInfo(hStdout, 1, &rect);
}
////////////////////////////////////////////////////////////////////////////
int main()
{
    setConsoleFullscreen();
    int i = 0;
    int j = 0;
    int k = 1;
    gotoligcol(0,55);
    for(i = 0; i<120; i++){
        printf("%c",0xC4);
    }
    gotoligcol(0,55);
    printf("%c", 0xDA);
    gotoligcol(1,55);
    for(j = 0; j<55; j++){
        printf("%c\n",0xB3);
        gotoligcol(k,55);
        k += 1;
    }
    gotoligcol(54,55);
    printf("%c", 0xC0);
    for(i = 0; i<120; i++){
        printf("%c",0xC4);
    }
    gotoligcol(0,175);
    printf("%c", 0xBF);
    gotoligcol(1,175);



    return 0;
}
