#include <stdio.h>
#include <stdlib.h>
#include "cartesChance.h"
#include <string.h>
#include <windows.h>
#include <time.h>




int main()
{
    int i = 0;

    char refaire[3];

    int aleatoire = generationAleatoire();

    setConsoleFullscreen();

    CarteChance tabCartes[32];

    creationCartesChance(tabCartes);

    creationCartesCommunautes(tabCartes);

    creationContourCarte();

    //affichageCarteChance(aleatoire, tabCartes);

    //////////////////Si cartes communautes/////////////
    aleatoire += 16;
    ///////////////////////////////////////////////////

    affichageCarteCommunautes(aleatoire, tabCartes);

    gotoligcol(40, 1);

    /*for(i = 0; i < 16; i++){
        printf("%s\n", tabCartes[i].nom);
    }*/

    /////////////////////////// JUSTE POUR ELABORATION DU CODE ////////////////////////
    printf("Souhaitez vous retirer une carte chance ?\n");

    scanf("%s", &refaire);

    do{
        system("cls");

        aleatoire = generationAleatoire();

        //////////////////// A faire si carte communautes//////////////////
        aleatoire += 16;
        //////////////////////////////////////////////////////////////////

        setConsoleFullscreen();

        CarteChance tabCartes[16];

        creationCartesChance(tabCartes);

        creationCartesCommunautes(tabCartes);

        creationContourCarte();

        //affichageCarteChance(aleatoire, tabCartes);

        affichageCarteCommunautes(aleatoire, tabCartes);

        gotoligcol(40, 1);

        printf("Souhaitez vous retirer une carte chance ?\n");

        scanf("%s", &refaire);

    }while(refaire != "non" || refaire != "NON" || refaire != "Non");
//////////////////////////////////////////////////////////////////////////////


    return 0;
}
