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
    int k = 0; //compteur des petites lignes horizontales � gauches (place)
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
    ////////////////////// 1�re Ligne Horizontale /////////////////////////
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

    /////////////////////// 1�re Ligne Verticale ///////////////////////
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
    ////////////////////////// Ligne verticale � Droite //////////////
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
    /////////////////////////// 2�me Ligne/////////////////////////////////

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
////////////////////// Jonction entre la premi�re ligne et la deuxi�me////
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
/////////////////////// On trace la grande barre int�rieur gauche //////
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
/////////////////////// On trace la grande barre int�rieur droite //////
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
//////////////////// On trace l'avant derni�re ligne du plateau////////
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
    ////////////////////// Jonction entre les deux derni�res lignes//////
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
    /////////////// On trace les minis barres horizontales � gauche ////
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
    ///////////// On trace les minis barres horizontales � droite /////
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

/////////////////// CASES BLEU FLUO /////////////////////////////
    Color(9,0);

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

/////////////////// CASES Turquoises /////////////////////////////
    Color(11,0);

    for(j = 0; j < 4; j++)
    {
        /*gotoligcol(8,(37-j));

        printf("%c", 0xDB);*/

        gotoligcol(37,(37-j));

        for(i = 0; i < 14; i++)
        {
            printf("%c", 0xDB);
            gotoligcol((trentesept+i),(37-j));
        }
    }
///////////////////////////////////////////////////////////////

/////////////////// CASES JAUNES /////////////////////////////
    Color(14,0);

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

/////////////////// CASES Turquoises /////////////////////////////
    Color(10,0);

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

/////////////////// CASES ROUGE FONCE ////////////////////////////

    Color(4,0);

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

/////////////////// CASES ROUGE FLUO ////////////////////////////

    Color(12,0);

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

/////////////////// CASES BLEU FONCE ////////////////////////////

    Color(1,0);

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

    for(j = 0; j < 2; j++)
    {
        /*gotoligcol(8,(37-j));

        printf("%c", 0xDB);*/

        gotoligcol((50+j),125);

        for(i = 0; i < 23; i++)
        {
            printf("%c", 0xDB);
            gotoligcol((50+j), (148+i));
        }
    }
//////////////////////////////////////////////////////////////

}


int main()
{
    setConsoleFullscreen();

    couleursPlateau();

    creationPlateau();

    //couleursPlateau();

    gotoligcol(58,0);

    return 0;
}
