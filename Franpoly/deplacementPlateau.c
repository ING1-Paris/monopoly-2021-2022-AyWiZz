#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void affichPion(){
    //tableau à double entrée permettant de stocker les positions des cases
    int caze[26][2]={{0,0},{4,26},{4,48},{4,70},{4,92},{4,114},{4,136},{4,158},
    {11,158},{18,158},{25,158},{32,158},{39,158},{46,158},{53,158},
    {53,136},{53,114},{53,92},{53,70},{53,48},{53,26},
    {46,26},{39,26},{32,26},{25,26},{18,26},{11,26}};
    int mvtPion;
    do{
        gotoligcol(2,195);
        printf("quelle case ? :\t0 pour sortir ");
        scanf("%d", &mvtPion);
        if ((mvtPion == 0)||(mvtPion>27)||(mvtPion<0)){
            return 1;
        }
    gotoligcol(caze[mvtPion][0],caze[mvtPion][1]);
    printf("%c", 0xDB);
    }while(mvtPion>0 || mvtPion<26);

}
