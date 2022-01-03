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
}Joueur ;



void remplir(Joueur j[])
{
    for (int i=1;i<nbJoueurs+1;i++){
    j[i].argent = 1500;
    j[i].position =0;
}
}
void remplissageJoueur(Joueur j[]){

printf("")

}
