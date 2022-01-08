#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define taille 20
#include "header.h"


void affichInfo(Joueur j[], int joueurPlaying, int nbJoueurs)
{
    int c = 1;

    Color(joueurPlaying+1, 0);
    gotoligcol(19, 195);
    printf("%s vous avez %d M $", j[joueurPlaying].nom,j[joueurPlaying].argent);
    gotoligcol(20,195);

    if(j[joueurPlaying].t1Possede ==1)
    {
        printf("Vous posseder %s.", j[joueurPlaying].terrain1);
        gotoligcol(20+c,195);
        c++;
    }
    if(j[joueurPlaying].t2Possede ==1)
    {
        printf("Vous posseder %s.", j[joueurPlaying].terrain2);
        gotoligcol(20+c,195);
        c++;
    }
    if(j[joueurPlaying].t3Possede ==1)
    {
        printf("Vous posseder %s. elle bug", j[joueurPlaying].terrain3);
        gotoligcol(20+c,195);
        c++;
    }
    if(j[joueurPlaying].t4Possede ==1)
    {
        printf("Vous posseder %s.", j[joueurPlaying].terrain4);
        gotoligcol(20+c,195);
        c++;
    }
    if(j[joueurPlaying].t5Possede ==1)
    {
        printf("Vous posseder %s.", j[joueurPlaying].terrain5);
        gotoligcol(20+c,195);
        c++;
    }
    if(j[joueurPlaying].t6Possede ==1)
    {
        printf("Vous posseder %s.", j[joueurPlaying].terrain6);
        gotoligcol(20+c,195);
        c++;
    }
    if(j[joueurPlaying].t7Possede ==1)
    {
        printf("Vous posseder %s.", j[joueurPlaying].terrain7);
        gotoligcol(20+c,195);
        c++;
    }
    if(j[joueurPlaying].t8Possede ==1)
    {
        printf("Vous posseder %s.", j[joueurPlaying].terrain8);
        gotoligcol(20+c,195);
        c++;
    }
    if(j[joueurPlaying].t9Possede ==1)
    {
        printf("Vous posseder %s. elle bug", j[joueurPlaying].terrain9);
        gotoligcol(20+c,195);
        c++;
    }
    if(j[joueurPlaying].t10Possede ==1)
    {
        printf("Vous posseder %s.", j[joueurPlaying].terrain10);
        gotoligcol(20+c,195);
        c++;
    }

    Color(9,0);
}


