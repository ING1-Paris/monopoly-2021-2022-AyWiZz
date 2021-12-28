#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"

int main()
{

    int curseur = 1;
    int sauvegarde = 0;
    curseur = positionCurseur();
    if(curseur == 2)
    {
        sauvegarde = checkPartie();
    }

    clearScreen();
    creationPlateau();
    gotoligcol(57,0);

    creationPlateau();
    affichPion();


    gotoligcol(57,0);
    return 0;
}
