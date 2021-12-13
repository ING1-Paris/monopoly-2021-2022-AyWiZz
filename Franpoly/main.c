#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
//////////////////// CETTE FONCTION VIENT DE LA SECTION PROJET INFORMATIQUE///////////////////////
void gotoligcol( int lig, int col )
{

// ressources

    COORD mycoord;

    mycoord.X = col;

    mycoord.Y = lig;

    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

}

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
///////////////////////////////////////////////////////////////////////////////
///////////// CES FONCTIONS VIENNENT DU TUTORAT////////////////////////////////
void setConsoleSize(short width, short height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {.X=width, .Y=height};
    SMALL_RECT rect = {.Left=0, .Top=0, .Right=width-1, .Bottom=height-1};

    SetConsoleScreenBufferSize(hStdout, coord);
    SetConsoleWindowInfo(hStdout, 1, &rect);
}

void setConsoleFullscreen()
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD maxi = GetLargestConsoleWindowSize(hStdout);
    SMALL_RECT rect = {.Left=0, .Top=0, .Right=maxi.X-1, .Bottom=maxi.Y-1};

    SetConsoleScreenBufferSize(hStdout, maxi);
    SetConsoleWindowInfo(hStdout, 1, &rect);
}
////////////////////////////////////////////////////////////////////////////
int main()
{
    Color(9,0);
    setConsoleFullscreen();
    int i = 0;
    int j = 0;
    int k = 1;
    int l = 1;
    int m = 1;
    int n = 5;
    int o = 1;
    int p;
    int q = 1;
    int r = 5;
    int s = 42;
    int t;
    //////////////////////TRACE LA LIGNE HORIZONTAL EN HAUT//////////////////////
    gotoligcol(0,55);
    for(i = 0; i<93; i++)
    {
        printf("%c",0xC4);
    }
    ///////////////////////////////////////////////////////////////////////////
    //////////////////////// L'ANGLE EN HAUT A GAUCHE/////////////////////
    gotoligcol(0,55);
    printf("%c", 0xDA);
    //////////////////////////////////////////////////////////////////////////
    //////////////////////// LA LIGNE VERTICALE A GAUCHE/////////////////
    gotoligcol(1,55);
    for(j = 0; j<45; j++)
    {
        printf("%c\n",0xB3);
        gotoligcol(k,55);
        k += 1;

    }
    ////////////////////////////////////////////////////////////////////////
    ///////////////////////ANGLE EN BAS A GAUCHE/////////////////////
    gotoligcol(54,55);
    printf("%c", 0XC0);
    //////////////////////////////////////////////////////////////////////
    /////////////////////////// LIGNE HORIZONTALE DU BAS//////////////////
    for(i = 0; i<92; i++)
    {
        printf("%c",0xC4);
    }
    /////////////////////////////////////////////////////////////////////
    //////////////////////ANGLE EN BAS A DROITE/////////////////////////
    gotoligcol(54, 148);
    printf("%c", 0XD9);
    ///////////////////////////////////////////////////////////////////
    ////////////////////LIGNE VERTICALE A DROITE///////////////////////
    gotoligcol(1, 148);
    for(j = 0; j<45; j++)
    {
        printf("%c\n",0xB3);
        gotoligcol(l,148);
        l += 1;

    }
    ///////////////////////////////////////////////////////////////////
    ////////////////////ANGLE EN HAUT A DROITE/////////////////////////
    gotoligcol(0,148);
    printf("%c", 0XBF);
    //////////////////////////////////////////////////////////////////
    ///////////////////LIGNE INTERIEUR GAUCHE/////////////////////////
    gotoligcol(1,65);
    for(j = 0; j<45; j++)
    {
        printf("%c\n",0xB3);
        gotoligcol(m,65);
        m += 1;

    }
    ////////////////////////////////////////////////////////////////
    /////////////////////// CASES A GAUCHE//////////////////////////
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j<9; j++)
        {
            printf("%c", 0xC4);
        }
        printf("\n");
        gotoligcol(n, 56);
        n += 6;
    }
    //////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////
    gotoligcol(5, 56);
    for(i = 0; i<92; i++)
    {
        printf("%c",0xC4);
    }
    gotoligcol(41, 56);
    for(i = 0; i<92; i++)
    {
        printf("%c",0xC4);
    }
    ////////////////////////////////////////////////////////////
    ///////////////////AFFICHE LES CASES DU HAUT////////////////
    gotoligcol(1, 77);
    p = 77;
    for(i = 0; i < 6; i++) //SI NOUS METTONS J = 7 CELA DEPASSE
    {
        for(j = 0; j < 5; j++)
        {
        printf("%c\n",0xB3);
        gotoligcol(o,p);
        o += 1;
        }
        p += 12;
        gotoligcol(1, p);
        o = 1;
    }
    ///////////////////////////////////////////////////////////
    //////////////////LIGNE INTERIEUR DROITE //////////////////
    gotoligcol(1,137);
    for(j = 0; j<45; j++)
    {
        printf("%c\n",0xB3);
        gotoligcol(q,137);
        q += 1;

    }
    //////////////////////////////////////////////////////////
    ////////////////////////CASES A DROITE////////////////////
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j<10; j++)
        {
            printf("%c", 0xC4);
        }
        printf("\n");
        gotoligcol(r, 138);
        r += 6;
    }
    /////////////////////////////////////////////////////////
    /////////////////////CASES EN BAS////////////////////////
    gotoligcol(42,77);
    t = 77;
    for(i = 0; i < 6; i++) //SI NOUS METTONS J = 7 CELA DEPASSE
    {
        for(j = 0; j < 4; j++)
        {
        printf("%c\n",0xB3);
        gotoligcol(s,t);
        s += 1;
        }
        t += 12;
        gotoligcol(42, t);
        s = 42;
    }






    return 0;
}
