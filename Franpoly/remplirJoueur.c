#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define taille 20
#include"header.h"


void remplir(Joueur j[])
{
    int couleurPion = 10;
    for (int i=1; i<7; i++)
    {
        j[i].argent = 1500;
        j[i].position = 0;
        //j[i].haveToPlay = 0;
    }
    for (int i=1; i<7; i++)
    {
        j[i].couleur = couleurPion;
        couleurPion += 1;
    }

}
int remplissageJoueur(Joueur j[])
{
    int nbJoueurs = 0;
    int ligne = 3;
    gotoligcol(2,2);
    printf("Bienvenue sur le SPACE MONOPOLY !");

    do
    {
        gotoligcol(3,2);
        printf("Combien de joueurs pour cette partie ? ");
        gotoligcol(4,2);
        fflush(stdin);
        scanf("%d", &nbJoueurs);
        if(nbJoueurs>1 && nbJoueurs<6)
        {
            ligne+=1;
        }
    }
    while(nbJoueurs<1 || nbJoueurs>6);


    for(int i=1; i<nbJoueurs+1; i++)
    {
        gotoligcol(ligne+i,2);
        printf("Quel est le nom du joueur %d ?", i);
        gotoligcol(ligne+1+i,2);
        fflush(stdin);
        gets(j[i].nom);
        ligne++;
    }
    system("cls");

    return nbJoueurs;

}
int returnNbJ(int nbJoueurs)
{
    int z=nbJoueurs;
    return z;
}
