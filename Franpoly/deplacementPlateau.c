#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "header.h"

void des(int x,int *px)
{

    int nbr = 0, a = 1;
    const int max = 6, min = 1;
    srand(time(NULL));
    for (int i=0; i<2; i++)
    {

        nbr = (rand() % (max - min)) + min;
        x+=nbr;
        gotoligcol(a,1);
        printf("%c", 0xDA);
        for (int j=0; j<7; j++)
        {
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
        for (int j=0; j<7; j++)
        {
            printf("%c", 0xC4);
        }
        printf("%c\n", 0xD9);
        a+=1;
    }

    *px=x;

}


void affichPion(Joueur j[], int joueurJ)
{
    gotoligcol(4,195);
    int caze[29][2]= {{0,0},{4,26},{4,48},{4,70},{4,92},{4,114},{4,136},{4,158},{4,180},
        {11,180},{18,180},{25,180},{32,180},{39,180},{46,180},{53,180},
        {53,158},{53,136},{53,114},{53,92},{53,70},{53,48},{53,26},
        {46,26},{39,26},{32,26},{25,26},{18,26},{11,26}};

    int v=0;
    int nbDe = 0;
    int *pnbDe = &nbDe;
    int pos = 0;

    pos = j[joueurJ].position;
    pos = 1+pos + *pnbDe;

    Color(5, 0);
    gotoligcol(caze[pos][0],caze[pos][1]);
    printf("%c%c%c", 0xC9, 0xCD, 0xBB);
    gotoligcol(caze[pos][0]+1,caze[pos][1]);
    printf("%c%c%c", 0xC8, 0xCD, 0xBC);

    if(j[joueurJ].position > 28)
    {
        j[joueurJ].position = 1;
    }
}



