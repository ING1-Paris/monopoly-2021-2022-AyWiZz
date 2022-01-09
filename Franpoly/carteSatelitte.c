#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define tailleCarre 6
#define decal 70
#include <time.h>
#include"header.h"


/*  ENTREE : AUCUNE 
    SORTIE : AUCUNE
    BUT DE LA FONCTION : CRÉER LE CONTOUR DES CARTES SATELLITES
*/
void creationContourCarteSatellite()
{
//////////////////////// INITIALISATION DES VARIABLES ////////////   
    int i = 0;
    int j = 0;
    int k = 9;
    int l = 9;
    int m = 24;
 ///////////////////////////////////////////////////////////////
    gotoligcol(10,65);
    for(i = 0; i <55; i++)
    {
        printf("%c", 0xC4);
    }
    gotoligcol(10,65);
    printf("%c", 0xDA); //AFFICHE LE COIN EN HAUT À GAUCHE
    gotoligcol(10,120);
    printf("%c", 0xBF); //AFFICHE LE COIN EN HAUT À DROITE
    gotoligcol(20,65);

    for(j = 0; j <4; j++)
    {
        for(i = 0; i < 7; i++)
        {
            gotoligcol((2+k),65);
            printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE
            k = k+1;
        }

    }
    for(i = 0; i < 5; i++)
    {
        gotoligcol((2+m),65);
        printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE
        m = m+1;
    }

    gotoligcol(40, 65);
    printf("%c", 0xC0); //AFFICHE LE COIN EN BAS À GAUCHE

    for(i = 0; i < 55; i++)
    {
        printf("%c", 0xC4); //AFFICHE LA BARRE HORIZONTALE
    }
    gotoligcol(40, 120);
    printf("%c", 0xD9); //AFFICHE LE COIN EN BAS À DROITE

    gotoligcol(10, 120);
    for(j = 0; j < 4; j++)
    {
        for(i = 0; i < tailleCarre; i++)
        {
            gotoligcol((2+l),120);
            printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE
            l = l+1;
        }

    }
    for(i = 0; i < 4; i++)
    {
        gotoligcol((2+l),120);
        printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE
        l = l+1;
    }
//////////////////////////// OBLIGATOIRE SINON BUG///////////
    gotoligcol(39,65);
    printf("%c", 0xB3);

    gotoligcol(39,120);
    printf("%c", 0xB3);
////////////////////////////////////////////////////////////

}

/*  ENTREE : AUCUNE
    SORTIE : AUCUNE
    BUT DE LA FONCTION : CRÉER LE BANDEAU DE COULEUR DE LA CARTE SATELLITE
*/
void bandeauCartes()
{
    /////////////////// INITIALISATION DES VARIABLES ////////////////////
    Color(8,0); // GRIS FONCE
    int i = 0;
    int j = 0;
    int k = 0;
    ///////////////////////////////////////////////////////////////////
///////////////////// BANDEAU COULEUR //////////////////////////////
    gotoligcol(11, 65);

    for(j = 0; j < 6; j++)
    {
        for(i = 0; i < 56; i++)
        {
            printf("%c", 0xDB); //AFFICHE UN CARRE DE LA COULEUR CHOISI
        }
        k += 1;
        gotoligcol((11 + k), 65); //ON VA À LA LIGNE EN DESSOUS
    }

    gotoligcol(10,65);

    for(i = 0; i < 56; i++)
    {
        printf("%c", 0xDC); //AFFICHE UN PETIT RECTANGLE DE LA COULEUR CHOISI
    }
////////////////////////////////////////////////////////////////////////
}

/* ENTREE : UN TABLEAU DE STRUCTURE SATELLITE ET UN NOMBRE ALÉATOIRE
   SORTIE : AUCUNE
   BUT DE LA FONCTION : ÉCRITURE DES CARTES SATELITTES ET LES AFFICHER DANS LA CONSOLE
*/
void ecritureSatellite(Satellite tabSatellites[4], int aleatoire)
{
    Color(0,8);

    gotoligcol(14, 82);

    printf("%s", tabSatellites[aleatoire].nom); //AFFICHE LE NOM DU SATELLITE

    Color(15,0);

    gotoligcol(21, decal);

    printf("LOYER EN POSSEDANT UN SATELLITE : %d M $", tabSatellites[aleatoire].loyer); //AFFICHE LE LOYER QUAND LE JOUEUR POSSÈDE 1 SATELLITE

    gotoligcol(24, decal);

    printf("LOYER EN POSSEDANT DEUX SATELLITES : %d M $", tabSatellites[aleatoire].loyer2); //AFFICHE LE LOYER QUAND LE JOUEUR POSSÈDE 2 SATELLITE

    gotoligcol(27, decal);

    printf("LOYER EN POSSEDANT TROIS SATELLITES : %d M $", tabSatellites[aleatoire].loyer3); //AFFICHE LE LOYER QUAND LE JOUEUR POSSÈDE 3 SATELLITE

    gotoligcol(30, decal);

    printf("LOYER EN POSSEDANT QUATRE SATELLITES : %d M $", tabSatellites[aleatoire].loyer4); //AFFICHE LE LOYER QUAND LE JOUEUR POSSÈDE 4 SATELLITE
}
/*
    ENTREE : UN TABLEAU DE STRUCTURE SATELLITE
    SORTIE : AUCUNE
    BUT DE LA FONCTION : INITIALISER LES CARTES SATELLITES 
*/
void creationSatellites(Satellite tabSatellites[4])
{
    int i = 0;

    char satellite1[] = "I   S   S";
    strcpy(tabSatellites[0].nom, satellite1); //ON COPIE LE NOM DU SATELLITE 1 DANS LE TABLEAU DE STRUCTURE

    char satellite2[] = "S   P   O   U   T   N   I   K";
    strcpy(tabSatellites[1].nom, satellite2); //ON COPIE LE NOM DU SATELLITE 2 DANS LE TABLEAU DE STRUCTURE

    char satellite3[] = "V   O   S   T   O   K";
    strcpy(tabSatellites[2].nom, satellite3); //ON COPIE LE NOM DU SATELLITE 3 DANS LE TABLEAU DE STRUCTURE

    char satellite4[] = "A   P   O   L   L   O";
    strcpy(tabSatellites[3].nom, satellite4); //ON COPIE LE NOM DU SATELLITE 4 DANS LE TABLEAU DE STRUCTURE

    for(i = 0; i < 4; i++) //COMME LES LOYERS SONT LES MÊMES POUR CHAQUE SATELLITE ON PEUT FAIRE CETTE BOUCLE
    {
        tabSatellites[i].loyer = 50;
        tabSatellites[i].loyer2 = 100;
        tabSatellites[i].loyer3 = 150;
        tabSatellites[i].loyer4 = 200;
        tabSatellites[i].possede = 0;
        tabSatellites[i].hypo = 30;
    }

}

/*int generationAleatoireSatellite()
{
    srand(time(NULL));
    int aleatoire = 0;
    aleatoire = rand() % 4;
    return (aleatoire);
}*/
