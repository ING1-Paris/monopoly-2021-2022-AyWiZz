#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define taille 20

int nbJoueurs = 6;

typedef struct Joueur
{
    char nom[taille];
    char couleur[taille];
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
        j[i].position = 0;
    }
}
int remplissageJoueur(Joueur j[])
{
    int nbJoueurs = 0;
    int ligne = 3;
    gotoligcol(2,2);
    printf("Bienvenue sur le SPACE MONOPOLY !");
    gotoligcol(3,2);
    do{
    printf("Combien de joueurs pour cette partie ? ");
    gotoligcol(4,2);
    ligne+=1;
    fflush(stdin);
    scanf("%d", &nbJoueurs);
    }while(nbJoueurs<1 || nbJoueurs>6);
    for(int i=1; i<nbJoueurs+1; i++)
    {
        gotoligcol(ligne+i,2);
        printf("Quel est le nom du joueur %d ?", i);
        gotoligcol(ligne+1+i,2);
        fflush(stdin);
        gets(j[i].nom);
        gotoligcol(ligne+2+i,2);
        printf("Veuillez choisir la couleur de votre pion : (rouge, vert, jaune, violet, turquoise ou blanc) : ");
        gets(j[i].couleur);
        gotoligcol(ligne+3+i,2);
        fflush(stdin);
        ligne+=3;
    }
    system("cls");

    return nbJoueurs;

}
