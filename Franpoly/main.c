#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"

int main()
{
    setConsoleFullscreen();
    /*
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
    affichPion();


    gotoligcol(57,0);
    return 0;
    */
    int i = 0;

    int aleatoire = generationAleatoire();

    setConsoleFullscreen();

    CarteChance tabCartes[16];

    creationCartesChance(tabCartes);

    creationContourCarte();

    affichageCarteChance(aleatoire, tabCartes);

    gotoligcol(40, 1);

    /*for(i = 0; i < 16; i++){
        printf("%s\n", tabCartes[i].nom);
    }*/

    return 0;
}
