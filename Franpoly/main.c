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
    creationPlateau();
    remplir(player);
    gotoligcol(100, 50);

    CarteChance tabCartes[16];
    creationCartesChance(tabCartes);
    creationContourCarte();
    affichageCarteChance(aleatoire, tabCartes);
    gotoligcol(10,0);
    printf("A qui le tour ? ");
    scanf("%d", &joueurJ);
    for(int i=0;i<6;i++){
    if(joueurJ == i){
        joueurJ = i;
    }}
    printf("Le joueur %d joue ", joueurJ);
    affichPion(player, joueurJ);



    gotoligcol(57,0);
    return 0;

}
