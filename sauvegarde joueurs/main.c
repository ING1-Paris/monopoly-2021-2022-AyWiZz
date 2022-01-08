#include "header.h"
#include "fonctions.c"



int main()
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
