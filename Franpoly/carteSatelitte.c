#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define tailleCarre 6
#define decal 70
#include <time.h>
#include"header.h"



void creationContourCarteSatellite()
{
    int i = 0;
    int j = 0;
    int k = 9;
    int l = 9;
    int m = 24;
    gotoligcol(10,65);
    for(i = 0; i <55; i++)
    {
        printf("%c", 0xC4);
    }
    gotoligcol(10,65);
    printf("%c", 0xDA);
    gotoligcol(10,120);
    printf("%c", 0xBF);
    gotoligcol(20,65);

    for(j = 0; j <4; j++)
    {
        for(i = 0; i < 7; i++)
        {
            gotoligcol((2+k),65);
            printf("%c", 0xB3);
            k = k+1;
        }

    }
    for(i = 0; i < 5; i++)
    {
        gotoligcol((2+m),65);
        printf("%c", 0xB3);
        m = m+1;
    }

    gotoligcol(40, 65);
    printf("%c", 0xC0);

    for(i = 0; i < 55; i++)
    {
        printf("%c", 0xC4);
    }
    gotoligcol(40, 120);
    printf("%c", 0xD9);

    gotoligcol(10, 120);
    for(j = 0; j < 4; j++)
    {
        for(i = 0; i < tailleCarre; i++)
        {
            gotoligcol((2+l),120);
            printf("%c", 0xB3);
            l = l+1;
        }

    }
    for(i = 0; i < 4; i++)
    {
        gotoligcol((2+l),120);
        printf("%c", 0xB3);
        l = l+1;
    }
//////////////////////////// OBLIGATOIRE SINON BUG///////////
    gotoligcol(39,65);
    printf("%c", 0xB3);

    gotoligcol(39,120);
    printf("%c", 0xB3);
////////////////////////////////////////////////////////////

}


void bandeauCartes()
{
    Color(8,0); // GRIS FONCE
    int i = 0;
    int j = 0;
    int k = 0;
///////////////////// BANDEAU COULEUR //////////////////////////////
    gotoligcol(11, 65);

    for(j = 0; j < 6; j++)
    {
        for(i = 0; i < 56; i++)
        {
            printf("%c", 0xDB);
        }
        k += 1;
        gotoligcol((11 + k), 65);
    }

    gotoligcol(10,65);

    for(i = 0; i < 56; i++)
    {
        printf("%c", 0xDC);
    }
////////////////////////////////////////////////////////////////////////
}


void ecritureSatellite(Satellite tabSatellites[4], int aleatoire)
{
    Color(0,8);

    gotoligcol(14, 82);

    printf("%s", tabSatellites[aleatoire].nom);

    Color(15,0);

    gotoligcol(21, decal);

    printf("LOYER EN POSSEDANT UN SATELLITE : %d M $", tabSatellites[aleatoire].loyer);

    gotoligcol(24, decal);

    printf("LOYER EN POSSEDANT DEUX SATELLITES : %d M $", tabSatellites[aleatoire].loyer2);

    gotoligcol(27, decal);

    printf("LOYER EN POSSEDANT TROIS SATELLITES : %d M $", tabSatellites[aleatoire].loyer3);

    gotoligcol(30, decal);

    printf("LOYER EN POSSEDANT QUATRE SATELLITES : %d M $", tabSatellites[aleatoire].loyer4);

}

void creationSatellites(Satellite tabSatellites[4])
{
    int i = 0;

    char satellite1[] = "I   S   S";
    strcpy(tabSatellites[0].nom, satellite1);

    char satellite2[] = "S   P   O   U   T   N   I   K";
    strcpy(tabSatellites[1].nom, satellite2);

    char satellite3[] = "V   O   S   T   O   K";
    strcpy(tabSatellites[2].nom, satellite3);

    char satellite4[] = "A   P   O   L   L   O";
    strcpy(tabSatellites[3].nom, satellite4);

    for(i = 0; i < 4; i++)
    {
        tabSatellites[i].loyer = 50;

        tabSatellites[i].loyer2 = 100;

        tabSatellites[i].loyer3 = 150;

        tabSatellites[i].loyer4 = 200;

        tabSatellites[i].possede = 0;
    }

}

/*int generationAleatoireSatellite()
{
    srand(time(NULL));
    int aleatoire = 0;
    aleatoire = rand() % 4;
    return (aleatoire);
}*/
