#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void affichPion(){
    //tableau à double entrée permettant de stocker les positions des cases
    int caze[29][2]={{0,0},{4,26},{4,48},{4,70},{4,92},{4,114},{4,136},{4,158},{4,180},
    {11,180},{18,180},{25,180},{32,180},{39,180},{46,180},{53,180},
    {53,158},{53,136},{53,114},{53,92},{53,70},{53,48},{53,26},
    {46,26},{39,26},{32,26},{25,26},{18,26},{11,26}};
    int mvtPion;
    do{
        gotoligcol(2,195);
        printf("quelle case ? :\t0 pour sortir ");
        scanf("%d", &mvtPion);
        if ((mvtPion == 0)||(mvtPion>28)||(mvtPion<0)){
            gotoligcol(2,195);
            printf("la valeur doit être comprise entre 1 et 28 ");
            scanf("%d", &mvtPion);
        }
    gotoligcol(caze[mvtPion][0],caze[mvtPion][1]);
    printf("%c", 0xDB);
    }while(mvtPion>0 || mvtPion<28);

}
