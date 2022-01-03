#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"

int main()
{

    Joueur player[6];
    setConsoleFullscreen();

    int joueurJ = 0;

    int aleatoire = generationAleatoire();
    int curseur = 1;
    int sauvegarde = 0;

    curseur = positionCurseur();
    if(curseur == 2)
    {
        sauvegarde = checkPartie();
    }
    clearScreen();
    remplissageJoueur(player);


    clearScreen();
    couleursPlateau();

    creationPlateau();


    remplir(player);

    gotoligcol(100, 50);

    CarteChance tabCartes[16];
    creationCartesChance(tabCartes);
    creationContourCarte();
    affichageCarteChance(aleatoire, tabCartes);

    //affichPion(player, joueurJ);


    gotoligcol(58,0);

    return 0;

}
