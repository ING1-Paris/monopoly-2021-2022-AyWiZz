#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define taille 20
#include "header.h"
/*typedef struct Joueur
{
    char nom[taille];
    int argent;
    int lastposition;
    int position;
    int couleur;
    int choix;
    int haveToPlay;
    int t1Possede;
    int t2Possede;
    int t3Possede;
    int t4Possede;
    int t5Possede;
    int nbTerrain;
    char terrain1[taille];
    char terrain2[taille];
    char terrain3[taille];
    char terrain4[taille];
    char terrain5[taille];
}Joueur;*/

void affichInfo(Joueur j[], int joueurPlaying, int nbJoueurs)
{
    int c = 1;
    Color(14, 0);
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
        printf("Vous posseder %s.", j[joueurPlaying].terrain3);
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
    Color(9,0);

}
