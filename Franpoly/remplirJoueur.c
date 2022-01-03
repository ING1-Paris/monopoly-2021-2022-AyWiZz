#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define taille 20

int nbJoueurs = 6;

typedef struct Joueur
{
    char nom[taille];
    int argent;
    int position;
    char terrain1[taille];
    char terrain2[taille];
    char terrain3[taille];
    char terrain4[taille];
    char terrain5[taille];
} Joueur ;



void remplir(Joueur j[])
{
    for (int i=1; i<7; i++)
    {
        j[i].argent = 1500;
        j[i].position =0;
    }
}
void remplissageJoueur(Joueur j[])
{
    int jDepart = 0;
    jDepart = choixDepart();
    gotoligcol(2,2);
    printf("Bienvenue sur le SPACE MONOPOLY !");
    gotoligcol(3,2);
    printf("Combien de joueurs pour cette partie ? ");
    gotoligcol(4,2);
    scanf("%d", &nbJoueurs);
    for(int i=1; i<nbJoueurs+1; i++)
    {
        gotoligcol(4+i,2);
        printf("Quel est le nom du joueur %d ?", i);
        gotoligcol(5+i,2);
        fflush(stdin);
        gets(j[i].nom);
    }
    //gotoligcol(2,8);
    //printf("C'est %s qui commence !", j[2].nom);

}
