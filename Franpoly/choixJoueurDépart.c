#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
///fonction permettant de  choisir le joueur de départ
///entrées: le nombre de joueurs
///sortie : la selection d'un joueur qui commencera, representer par un entier.



int choixDepart(nbJoueurs)
{
    int selection = 0;
    srand(time(NULL));///on importe le temps pour avoir une génération réellement aléatoire
    selection = (rand() % (nbJoueurs - 1 + 1)) + 1;///sélection aléatoire du joueur
    return selection;///on renvoie le nombre

}
