#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "cartesVilles.h"
#define decal 78



int main()
{
    ///////////////////////////// INITIALISATION DES VARIABLES //////////////////

    int i = 0;

    int j = 0;

    int k = 0;

    int aleatoire = 0;

    ////////////////////////////////////////////////////////////////////////////

    /////////////////////// TUTORAT ///////////////////////////////////////////

    setConsoleFullscreen();

    //////////////////////////////////////////////////////////////////////////

    do{
    CartePlanete tabCartesPlanetes[15]; //CREER UN TABLEAU DE 15 CARTES

    creationCartesPlanetes(tabCartesPlanetes); //CREER LES 15 CARTES

    printf("Veuillez entrez une carte");// AFFICHE "VEUILLEZ ENTREZ UNE CARTE"

    scanf("%d", &aleatoire);//RECUPERE LE NUMERO DE LA CARTE QUE L'ON SOUHAITE AFFICHé

    system("cls");// EFFACE LA CONSOLE

    creationContourCarte();// CREER LE CONTOUR D'UNE CARTE

    affichageCartesVilles(aleatoire, tabCartesPlanetes);// PERMET D'AFFICHER LA CARTE QUE L'ON SOUHAITE

    gotoligcol(0,0); // MET LE CURSEUR TOUT EN HAUT A GAUCHE

    }while(aleatoire >= 0 && aleatoire <= 14);

    Color(1,0);

    gotoligcol(55,1);

    return 0;






















}
