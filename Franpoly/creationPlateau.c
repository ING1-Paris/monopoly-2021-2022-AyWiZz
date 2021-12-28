#define tailleCarre 6
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void creationPlateau()
{
    /////////////////// Initialisation des variables //////////////////////
    int i = 0;
    int j = 0;
    int k = 0; //compteur des petites lignes horizontales à gauches (place)
    int l = 0;
    int m = 2;
    int n = 37;
    int p = 9;
    int q = 9;
    int r = 51;
    int s = 37;
    int t = 15;
    int u = 15;
    Color(9, 0);
    ///////////////////////////////////////////////////////////////////////
    ////////////////////// 1ère Ligne Horizontale /////////////////////////
    gotoligcol(1,15);
    printf("%c", 0xDA);
    for(i = 0; i < tailleCarre; i++)
    {
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
        printf("%c", 0xC2);
    }
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c", 0xBF);
    /////////////////////////////////////////////////////////////////////

    /////////////////////// 1ère Ligne Verticale ///////////////////////
    for(j = 0; j <7; j++)
    {
        for(i = 0; i < tailleCarre; i++)
        {
            gotoligcol((2+k),15);
            printf("%c", 0xB3);
            k = k+1;
        }
        gotoligcol((2+k),15);
        printf("%c", 0xC3);
        k = k + 1;
    }

    for(i = 0; i < tailleCarre; i++)
    {
        gotoligcol((2+k),15);
        printf("%c", 0xB3);
        k = k+1;
    }
    gotoligcol((2+k),15);
    printf("%c", 0xC0);
    k = k + 1;

    ///////////////////////////////////////////////////////////////////
    ////////////////////////// Ligne verticale à Droite //////////////
    for(j = 0; j <7; j++)
    {
        for(i = 0; i < tailleCarre; i++)
        {
            gotoligcol((2+l),169);
            printf("%c", 0xB3);
            l = l+1;
        }
        gotoligcol((2+l),169);
        printf("%c", 0xB4);
        l = l + 1;
    }
    for(i = 0; i < tailleCarre; i++)
    {
        gotoligcol((2+l),169);
        printf("%c", 0xB3);
        l = l+1;
    }
    gotoligcol((2+l),169);
    printf("%c", 0xD9);
    l = l + 1;
    ///////////////////////////////////////////////////////////////////////
    /////////////////////////// 2ème Ligne/////////////////////////////////

    gotoligcol(8,16);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c", 0xC5);
    for(i = 0; i < (tailleCarre-2); i++)
    {
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
        printf("%c", 0xC1);
    }
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c", 0xC5);

    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c", 0xB4);
//////////////////////////////////////////////////////////////////////////
////////////////////// Barre du Bas //////////////////////////////////////
    gotoligcol(57,16);
    for(i = 0; i < tailleCarre; i++)
    {
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
        printf("%c", 0xC1);
    }
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
////////////////////// Jonction entre la première ligne et la deuxième////
    gotoligcol(2,37);
    for(i = 0; i < 7; i++){
       for(j = 0; j < 6; j++){
            printf("%c", 0xB3);
            gotoligcol(m, n);
            m += 1;
        }
        n += 22;
        m = 2;
    }
/////////////////////////////////////////////////////////////////////////
/////////////////////// On trace la grande barre intérieur gauche //////
    //gotoligcol(9, 37);

    for(j = 0; j <5; j++)
    {
        for(i = 0; i < tailleCarre; i++)
        {
            gotoligcol(p,37);
            printf("%c", 0xB3);
            p = p+1;
        }
        gotoligcol(p,37);
        printf("%c", 0xB4);
        p = p + 1;
    }
    for(i = 0; i < tailleCarre; i++)
    {
        gotoligcol(p,37);
        printf("%c", 0xB3);
        p = p+1;
    }
    gotoligcol(p,37);
    printf("%c", 0xD9);
    p = p + 1;
////////////////////////////////////////////////////////////////////////
/////////////////////// On trace la grande barre intérieur droite //////
    //gotoligcol(9, 147);
    for(j = 0; j <5; j++)
    {
        for(i = 0; i < tailleCarre; i++)
        {
            gotoligcol(q,147);
            printf("%c", 0xB3);
            q = q+1;
        }
        gotoligcol(q,147);
        printf("%c", 0xC3);
        q = q + 1;
    }

    for(i = 0; i < tailleCarre; i++)
    {
        gotoligcol(q,147);
        printf("%c", 0xB3);
        q = q+1;
    }
    gotoligcol(q,147);
    printf("%c", 0xC0);
    q = q + 1;
////////////////////////////////////////////////////////////////////////
//////////////////// On trace l'avant dernière ligne du plateau////////
    gotoligcol(50, 16);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c", 0xC5);
    for(i = 0; i < (tailleCarre-2); i++)
    {
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
        printf("%c", 0xC2);
    }
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c", 0xC5);

    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4);
    /////////////////////////////////////////////////////////////////////
    ////////////////////// Jonction entre les deux dernières lignes//////
    gotoligcol(51,37);
    for(i = 0; i < 7; i++){
       for(j = 0; j < 6; j++){
            printf("%c", 0xB3);
            gotoligcol(r, s);
            r += 1;
        }
        s += 22;
        r = 51;
    }
    /////////////////////////////////////////////////////////////////////
    /////////////// On trace les minis barres horizontales à gauche ////
    gotoligcol(15,16);
    for(i = 0; i < 5; i++){
        for(j = 0; j < 21; j++){
            printf("%c", 0xC4);
        }
        t += 7;
        gotoligcol(t, 16);
    }
    ///////////////////////////////////////////////////////////////////
    ///////////// On trace les minis barres horizontales à droite /////
    gotoligcol(15,148);
    for(i = 0; i < 5; i++){
        for(j = 0; j < 21; j++){
            printf("%c", 0xC4);
        }
        u += 7;
        gotoligcol(u, 148);
    }

}
