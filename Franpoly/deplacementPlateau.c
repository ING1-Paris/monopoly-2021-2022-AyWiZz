#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "header.h"

void des(int x1, int x2, int x, int *px1, int * px2, int *px)
{

    int nbr = 0, a = 23;
    const int max = 6, min = 1;
    srand(time(NULL));
        nbr = (rand() % (max - min)) + min;
        x1=nbr;
        gotoligcol(a,47);
        printf("%c", 0xDA);
        for (int j=0; j<7; j++)
        {
            printf("%c", 0xC4);
        }
        printf("%c", 0xBF);
        a+=1;
        gotoligcol(a, 47);
        printf("%c       %c", 0xB3, 0xB3);
        a+=1;
        gotoligcol(a, 47);
        printf("%c   %d   %c", 0xB3, nbr, 0xB3);
        a+=1;
        gotoligcol(a, 47);
        printf("%c       %c", 0xB3, 0xB3);
        a+=1;
        gotoligcol(a, 47);
        printf("%c", 0xC0);
        for (int j=0; j<7; j++)
        {
            printf("%c", 0xC4);
        }
        printf("%c\n", 0xD9);
        a+=1;


        nbr = (rand() % (max - min)) + min;
        x2=nbr;
        gotoligcol(a,47);
        printf("%c", 0xDA);
        for (int j=0; j<7; j++)
        {
            printf("%c", 0xC4);
        }
        printf("%c", 0xBF);
        a+=1;
        gotoligcol(a, 47);
        printf("%c       %c", 0xB3, 0xB3);
        a+=1;
        gotoligcol(a, 47);
        printf("%c   %d   %c", 0xB3, nbr, 0xB3);
        a+=1;
        gotoligcol(a, 47);
        printf("%c       %c", 0xB3, 0xB3);
        a+=1;
        gotoligcol(a, 47);
        printf("%c", 0xC0);
        for (int j=0; j<7; j++)
        {
            printf("%c", 0xC4);
        }
        printf("%c\n", 0xD9);
        a+=1;

        x=x1+x2;

    *px1=x1;
    *px2=x2;
    *px=x;

}


void affichPion(Joueur j[], int joueurJ)
{
    gotoligcol(4,195);
    int caze[29][2]= {{0,0},{4,26},{4,48},{4,70},{4,92},{4,114},{4,136},{4,158},{4,180},
        {11,180},{18,180},{25,180},{32,180},{39,180},{46,180},{53,180},
        {53,158},{53,136},{53,114},{53,92},{53,70},{53,48},{53,26},
        {46,26},{39,26},{32,26},{25,26},{18,26},{11,26}
    };

    int nbDe = 0;
    int *pnbDe = &nbDe;
    int pos = 0;

    pos = j[joueurJ].position;

    if(pos>27)
    {
        j[joueurJ].argent+=200;
        pos = pos-27;
    }
    j[joueurJ].position = pos;
    pos = 1 + pos + *pnbDe;


    if (pos==1 || pos==2 || pos==3 || pos==4 || pos==5 || pos==6 || pos==7 || pos==9 ||pos==10 || pos==11 || pos==12 || pos==13 || pos==14 || pos==18 || pos==19 || pos==23 || pos==24 || pos==25 || pos==26 || pos==27 || pos==28)
    {
        if(joueurJ == 1)
        {
            Color(10, 0);
            gotoligcol(caze[pos][0]-2,caze[pos][1]-4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-2+1,caze[pos][1]-4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 2)
        {
            Color(11, 0);
            gotoligcol(caze[pos][0]-2,caze[pos][1]);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-2+1,caze[pos][1]);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 3)
        {
            Color(12, 0);
            gotoligcol(caze[pos][0]-2,caze[pos][1]+4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-2+1,caze[pos][1]+4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 4)
        {
            Color(13, 0);
            gotoligcol(caze[pos][0]+1,caze[pos][1]-4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+1+1,caze[pos][1]-4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 5)
        {
            Color(14, 0);
            gotoligcol(caze[pos][0]+1,caze[pos][1]);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+1+1,caze[pos][1]);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 6)
        {
            Color(15, 0);
            gotoligcol(caze[pos][0]+1,caze[pos][1]+4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+1+1,caze[pos][1]+4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
    }

    else if (pos==15 || pos==22)
    {
        if(joueurJ == 1)
        {
            Color(10, 0);
            gotoligcol(caze[pos][0]-2,caze[pos][1]-4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-2+1,caze[pos][1]-4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 2)
        {
            Color(11, 0);
            gotoligcol(caze[pos][0]-2,caze[pos][1]);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-2+1,caze[pos][1]);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 3)
        {
            Color(12, 0);
            gotoligcol(caze[pos][0]-2,caze[pos][1]+4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-2+1,caze[pos][1]+4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 4)
        {
            Color(13, 0);
            gotoligcol(caze[pos][0]+2,caze[pos][1]-4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+2+1,caze[pos][1]-4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 5)
        {
            Color(14, 0);
            gotoligcol(caze[pos][0]+2,caze[pos][1]);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+2+1,caze[pos][1]);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 6)
        {
            Color(15, 0);
            gotoligcol(caze[pos][0]+2,caze[pos][1]+4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+2+1,caze[pos][1]+4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
    }

    else if (pos==16 || pos==17 || pos==20 || pos==21)
    {
        if(joueurJ == 1)
        {
            Color(10, 0);
            gotoligcol(caze[pos][0]-1,caze[pos][1]-4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-1+1,caze[pos][1]-4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 2)
        {
            Color(11, 0);
            gotoligcol(caze[pos][0]-1,caze[pos][1]);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-1+1,caze[pos][1]);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 3)
        {
            Color(12, 0);
            gotoligcol(caze[pos][0]-1,caze[pos][1]+4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-1+1,caze[pos][1]+4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 4)
        {
            Color(13, 0);
            gotoligcol(caze[pos][0]+2,caze[pos][1]-4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+2+1,caze[pos][1]-4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 5)
        {
            Color(14, 0);
            gotoligcol(caze[pos][0]+2,caze[pos][1]);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+2+1,caze[pos][1]);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 6)
        {
            Color(15, 0);
            gotoligcol(caze[pos][0]+2,caze[pos][1]+4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+2+1,caze[pos][1]+4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
    }

    else if (pos==8)
    {
        if(joueurJ == 1)
        {
            Color(10, 0);
            gotoligcol(caze[pos][0]-2,caze[pos][1]-10);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-2+1,caze[pos][1]-10);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 2)
        {
            Color(11, 0);
            gotoligcol(caze[pos][0]-2,caze[pos][1]+8);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-2+1,caze[pos][1]+8);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 3)
        {
            Color(12, 0);
            gotoligcol(caze[pos][0],caze[pos][1]-10);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+1,caze[pos][1]-10);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 4)
        {
            Color(13, 0);
            gotoligcol(caze[pos][0],caze[pos][1]+8);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+1,caze[pos][1]+8);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 5)
        {
            Color(14, 0);
            gotoligcol(caze[pos][0]+2,caze[pos][1]-10);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+2+1,caze[pos][1]-10);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 6)
        {
            Color(15, 0);
            gotoligcol(caze[pos][0]+2,caze[pos][1]+8);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+2+1,caze[pos][1]+8);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
    }



}



