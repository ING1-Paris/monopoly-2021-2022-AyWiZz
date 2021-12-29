#include "header.h"

struct Joueur
{
    char nom[taille];
    int argent;
    int position;
    char terrain1[taille];
    char terrain2[taille];
    char terrain3[taille];
    char terrain4[taille];
    char terrain5[taille];
};
Joueur j[6];

void remplissageJoueurDebut(Joueur *j){

    for(int i=0; i<nbJoueurs; i++)
    {
        j[i].argent = 1500;
        j[i].position = 0;
    }
}
