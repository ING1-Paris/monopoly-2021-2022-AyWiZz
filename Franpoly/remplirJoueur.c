#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define taille 20

int nbJoueurs;

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
}Joueur;
Joueur j[6];


void remplissageJoueurDebut(Joueur *j)
{

    for(int i=0; i<nbJoueurs; i++)
    {
        j[i].argent = 1500;
        j[i].position = 0;
    }
}

int remplir()
{
    Joueur j[6];
    remplissageJoueurDebut(&j);
    for(int i = 0; i<nbJoueurs; i++)
    {
        printf("joueur %d : \n", i);
        printf(" argent j%d = %d \n", i, j[i].argent);
        printf("position j%d est case : %d\n",i,j[i].position);
    }
    return 0;
}
