#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define tailleCarre 7
#define longd 191
#define longda 169
#define longdb 37
#define dplusk 2+k
#define six 6
#define neuf 9
#define trentesept 37

void gotoligcol( int lig, int col )
{

// ressources

    COORD mycoord;

    mycoord.X = col;

    mycoord.Y = lig;

    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

}

void setConsoleSize(short width, short height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {.X=width, .Y=height};
    SMALL_RECT rect = {.Left=0, .Top=0, .Right=width-1, .Bottom=height-1};

    SetConsoleScreenBufferSize(hStdout, coord);
    SetConsoleWindowInfo(hStdout, 1, &rect);
}

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void setConsoleFullscreen()
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD maxi = GetLargestConsoleWindowSize(hStdout);
    SMALL_RECT rect = {.Left=0, .Top=0, .Right=maxi.X-1, .Bottom=maxi.Y-1};

    SetConsoleScreenBufferSize(hStdout, maxi);
    SetConsoleWindowInfo(hStdout, 1, &rect);
}

void clearScreen()
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

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
        for(i = 0; i < six; i++)
        {
            gotoligcol((dplusk),15);
            printf("%c", 0xB3);
            k = k+1;
        }
        gotoligcol((dplusk),15);
        printf("%c", 0xC3);
        k = k + 1;
    }

    for(i = 0; i < six; i++)
    {
        gotoligcol((dplusk),15);
        printf("%c", 0xB3);
        k = k+1;
    }
    gotoligcol((dplusk),15);
    printf("%c", 0xC0);
    k = k + 1;

    ///////////////////////////////////////////////////////////////////
    ////////////////////////// Ligne verticale à Droite //////////////
    for(j = 0; j <7; j++)
    {
        for(i = 0; i < six; i++)
        {
            gotoligcol((2+l),longd);
            printf("%c", 0xB3);
            l = l+1;
        }
        gotoligcol((2+l),longd);
        printf("%c", 0xB4);
        l = l + 1;
    }
    for(i = 0; i < six; i++)
    {
        gotoligcol((2+l),longd);
        printf("%c", 0xB3);
        l = l+1;
    }
    gotoligcol((2+l),longd);
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
    for(i = 0; i < 7; i++)
    {
        for(j = 0; j < 6; j++)
        {
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
        for(i = 0; i < six; i++)
        {
            gotoligcol(p,longdb);
            printf("%c", 0xB3);
            p = p+1;
        }
        gotoligcol(p,longdb);
        printf("%c", 0xB4);
        p = p + 1;
    }
    for(i = 0; i < six; i++)
    {
        gotoligcol(p,longdb);
        printf("%c", 0xB3);
        p = p+1;
    }
    gotoligcol(p,longdb);
    printf("%c", 0xD9);
    p = p + 1;
////////////////////////////////////////////////////////////////////////
/////////////////////// On trace la grande barre intérieur droite //////
    //gotoligcol(9, 147);
    for(j = 0; j < 5; j++)
    {
        for(i = 0; i < six; i++)
        {
            gotoligcol(q,longda);
            printf("%c", 0xB3);
            q = q+1;
        }
        gotoligcol(q,longda);
        printf("%c", 0xC3);
        q = q + 1;
    }

    for(i = 0; i < six; i++)
    {
        gotoligcol(q,longda);
        printf("%c", 0xB3);
        q = q+1;
    }
    gotoligcol(q,longda);
    printf("%c", 0xC0);
    q = q + 1;
/////////////////////////////// OBLIGE DE METTRE CA SINON BUG/////////////////
    gotoligcol(7, longda);
    printf("%c", 0XB3);

    gotoligcol(56, longda);
    printf("%c", 0XB3);
////////////////////////////////////////////////////////////////////////////
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
    for(i = 0; i < 7; i++)
    {
        for(j = 0; j < 6; j++)
        {
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
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 21; j++)
        {
            printf("%c", 0xC4);
        }
        t += 7;
        gotoligcol(t, 16);
    }
    ///////////////////////////////////////////////////////////////////
    ///////////// On trace les minis barres horizontales à droite /////
    gotoligcol(15,longda+1);
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 21; j++)
        {
            printf("%c", 0xC4);
        }
        u += 7;
        gotoligcol(u, longda+1);
    }

}



void couleursPlateau()
{

    int i = 0;

    int j = 0;

/////////////////// CASES BLEU FONCE /////////////////////////////
    Color(1,0);

    for(j = 0; j < 4; j++)
    {
        /*gotoligcol(8,(37-j));
        printf("%c", 0xDB);*/

        gotoligcol(9,(37-j));

        for(i = 0; i < 14; i++)
        {
            printf("%c", 0xDB);
            gotoligcol((neuf+i),(37-j));
        }
    }
///////////////////////////////////////////////////////////////

/////////////////// CASES Bleu Fonce /////////////////////////////
    Color(1,0);

    for(j = 0; j < 4; j++)
    {
        /*gotoligcol(8,(37-j));
        printf("%c", 0xDB);*/

        gotoligcol(44,(37-j));

        for(i = 0; i < 7; i++)
        {
            printf("%c", 0xDB);
            gotoligcol((44+i),(37-j));
        }
    }
///////////////////////////////////////////////////////////////

/////////////////// CASES ROUGE FONCE V2 /////////////////////////////
    Color(4,0);

    for(j = 0; j < 4; j++)
    {
        /*gotoligcol(8,(37-j));
        printf("%c", 0xDB);*/

        gotoligcol(9,(172-j));

        for(i = 0; i < 14; i++)
        {
            printf("%c", 0xDB);
            gotoligcol((neuf+i),(172-j));
        }
    }
///////////////////////////////////////////////////////////////

/////////////////// CASES ROUGE FLUO V2 /////////////////////////////
    Color(12,0);

    for(j = 0; j < 4; j++)
    {
        /*gotoligcol(8,(37-j));
        printf("%c", 0xDB);*/

        gotoligcol(37,(172-j));

        for(i = 0; i < 14; i++)
        {
            printf("%c", 0xDB);
            gotoligcol((trentesept+i),(172-j));
        }
    }
///////////////////////////////////////////////////////////////

/////////////////// CASES TURQUOISE ////////////////////////////

    Color(11,0);

    for(j = 0; j < 2; j++)
    {
        /*gotoligcol(8,(37-j));
        printf("%c", 0xDB);*/

        gotoligcol((8-j),37);

        for(i = 0; i < 45; i++)
        {
            printf("%c", 0xDB);
            gotoligcol((8-j), (trentesept+i));
        }
    }
//////////////////////////////////////////////////////////////

/////////////////// CASES BLEU CLAIR V2 ////////////////////////////

    Color(9,0);

    for(j = 0; j < 2; j++)
    {
        /*gotoligcol(8,(37-j));
        printf("%c", 0xDB);*/

        gotoligcol((8-j),125);

        for(i = 0; i < 45; i++)
        {
            printf("%c", 0xDB);
            gotoligcol((8-j), (125+i));
        }
    }
//////////////////////////////////////////////////////////////

/////////////////// CASES JAUNES ET VERTES ////////////////////////////

    Color(10,0);

    for(j = 0; j < 2; j++)
    {
        /*gotoligcol(8,(37-j));
        printf("%c", 0xDB);*/

        gotoligcol((50+j),37);

        for(i = 0; i < 45; i++)
        {
            printf("%c", 0xDB);
            gotoligcol((50+j), (trentesept+i));
        }
    }

    Color(14,0);
    for(j = 0; j < 2; j++)
    {
        /*gotoligcol(8,(37-j));
        printf("%c", 0xDB);*/

        gotoligcol((50+j),125);

        for(i = 0; i < 45; i++)
        {
            printf("%c", 0xDB);
            gotoligcol((50+j), (125+i));
        }
    }
//////////////////////////////////////////////////////////////

}
