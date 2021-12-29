#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void des (int nbDe,int *pnbDe)
{

    int nbr = 0;
    const int max = 6, min = 1;
    srand(time(NULL));
    for (int i=0; i<2; i++){

        nbr = (rand() % (max - min + 1)) + min;
        nbDe+=nbr;

        printf("%c", 0xDA);
        for (int j=0; j<7; j++){
            printf("%c", 0xC4);
        }
        printf("%c\n", 0xBF);
        printf("%c       %c\n", 0xB3, 0xB3);
        printf("%c   %d   %c\n", 0xB3, nbr, 0xB3);
        printf("%c       %c\n", 0xB3, 0xB3);
        printf("%c", 0xC0);
        for (int j=0; j<7; j++){
            printf("%c", 0xC4);
        }
        printf("%c\n", 0xD9);
    }

    *pnbDe=nbDe;
}


void affichPion(){
    int nbDe = 0;
    int *pnbDe = &nbDe;
    gotoligcol(4,195);
    des(nbDe,pnbDe);

    //tableau à double entrée permettant de stocker les positions des cases
    int caze[29][2]={{0,0},{4,26},{4,48},{4,70},{4,92},{4,114},{4,136},{4,158},{4,180},
    {11,180},{18,180},{25,180},{32,180},{39,180},{46,180},{53,180},
    {53,158},{53,136},{53,114},{53,92},{53,70},{53,48},{53,26},
    {46,26},{39,26},{32,26},{25,26},{18,26},{11,26}};

    gotoligcol(caze[*pnbDe][0],caze[*pnbDe][1]);
    printf("%c", 0xDB);


}
