#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define taille 20

typedef struct Joueur
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
    char terrain1[taille];
    char terrain2[taille];
    char terrain3[taille];
    char terrain4[taille];
    char terrain5[taille];
}Joueur;

void affichInfo(Joueur j[], int joueurPlaying){
int c = 0;
gotoligcol(10, 145);
printf("%s vous avez %d M $", j[joueurPlaying].nom,j[joueurPlaying].argent);
gotoligcol(11,100);
if(j[joueurPlaying].t1Possede ==1){
    printf("Vous posseder %s.", j[joueurPlaying].terrain1);
    gotoligcol(11+c,145);
    c++;
}
if(j[joueurPlaying].t2Possede ==1){
    printf("Vous posseder %s.", j[joueurPlaying].terrain2);
    gotoligcol(11+c,145);
    c++;
}
if(j[joueurPlaying].t3Possede ==1){
    printf("Vous posseder %s.", j[joueurPlaying].terrain3);
    gotoligcol(11+c,145);
    c++;
}
if(j[joueurPlaying].t4Possede ==1){
    printf("Vous posseder %s.", j[joueurPlaying].terrain4);
    gotoligcol(11+c,145);
    c++;
}
if(j[joueurPlaying].t5Possede ==1){
    printf("Vous posseder %s.", j[joueurPlaying].terrain5);
    gotoligcol(11+c,145);
    c++;
}

}
