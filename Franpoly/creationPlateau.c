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
////////////////////// FONCTION PROVENANT DU TUTORAT ////////////////////////
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

///////////////////////////////////////////////////////////////////////////
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
    printf("%c", 0xDA); //AFFICHE L'ANGLE EN HAUT A GAUCHE
    for(i = 0; i < tailleCarre; i++)
    {
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
        printf("%c", 0xC2); //AFFICHE LA RELIURE ENTRE UNE BARRE HORIZONTALE ET UNE BARRE VERTICALE
    }
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c", 0xBF); //AFFICHE L'ANGLE EN HAUT A DROITE
    /////////////////////////////////////////////////////////////////////

    /////////////////////// 1ère Ligne Verticale ///////////////////////
    for(j = 0; j <7; j++)
    {
        for(i = 0; i < six; i++)
        {
            gotoligcol((dplusk),15);
            printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE
            k = k+1; //INCREMENTE k DE 1
        }
        gotoligcol((dplusk),15);
        printf("%c", 0xC3); //AFFICHE LA RELIURE ENTRE UNE BARRE HORIZONTALE ET UNE BARRE VERTICALE
        k = k + 1; //INCREMENTE k DE 1
    }

    for(i = 0; i < six; i++)
    {
        gotoligcol((dplusk),15);
        printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE
        k = k+1; //INCREMENTE k DE 1
    }
    gotoligcol((dplusk),15);
    printf("%c", 0xC0); //AFFICHE L'ANGLE EN BAS A GAUCHE
    k = k + 1; //INCREMENTE k DE 1

    ///////////////////////////////////////////////////////////////////
    ////////////////////////// Ligne verticale à Droite //////////////
    for(j = 0; j <7; j++)
    {
        for(i = 0; i < six; i++)
        {
            gotoligcol((2+l),longd);
            printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE
            l = l+1; //INCREMENTE l DE 1
        }
        gotoligcol((2+l),longd);
        printf("%c", 0xB4);//AFFICHE LA RELIURE ENTRE UNE BARRE HORIZONTALE ET UNE BARRE VERTICALE
        l = l + 1; //INCREMENTE l DE 1
    }
    for(i = 0; i < six; i++)
    {
        gotoligcol((2+l),longd);
        printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE
        l = l+1; //INCREMENTE l DE 1
    }
    gotoligcol((2+l),longd);
    printf("%c", 0xD9); //AFFICHE L'ANGLE EN BAS A DROITE
    l = l + 1; //INCREMENTE l DE 1
    ///////////////////////////////////////////////////////////////////////
    /////////////////////////// 2ème Ligne/////////////////////////////////

    gotoligcol(8,16);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c", 0xC5); //AFFICHE LA RELIURE ENTRE UNE BARRE HORIZONTALE ET UNE BARRE VERTICALE
    for(i = 0; i < (tailleCarre-2); i++)
    {
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
        printf("%c", 0xC1); //AFFICHE LA RELIURE ENTRE UNE BARRE HORIZONTALE ET UNE BARRE VERTICALE
    }
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c", 0xC5); //AFFICHE LA RELIURE ENTRE UNE BARRE HORIZONTALE ET UNE BARRE VERTICALE

    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c", 0xB4); //AFFICHE LA RELIURE ENTRE UNE BARRE HORIZONTALE ET UNE BARRE VERTICALE
//////////////////////////////////////////////////////////////////////////
////////////////////// Barre du Bas //////////////////////////////////////
    gotoligcol(57,16);
    for(i = 0; i < tailleCarre; i++)
    {
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
        printf("%c", 0xC1); //AFFICHE LA RELIURE ENTRE UNE BARRE HORIZONTALE ET UNE BARRE VERTICALE
    }
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
////////////////////// Jonction entre la première ligne et la deuxième////
    gotoligcol(2,37);
    for(i = 0; i < 7; i++)
    {
        for(j = 0; j < 6; j++)
        {
            printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE
            gotoligcol(m, n);
            m += 1; //INCREMENTE m DE 1
        }
        n += 22; //INCREMENTE m DE 22
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
            printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE
            p = p+1;
        }
        gotoligcol(p,longdb);
        printf("%c", 0xB4); //AFFICHE LA RELIURE ENTRE UNE BARRE HORIZONTALE ET UNE BARRE VERTICALE
        p = p + 1; //INCREMENTE p DE 1
    }
    for(i = 0; i < six; i++)
    {
        gotoligcol(p,longdb);
        printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE
        p = p+1; //INCREMENTE p DE 1
    }
    gotoligcol(p,longdb);
    printf("%c", 0xD9); //AFFICHE L'ANGLE EN BAS A DROITE
    p = p + 1; //INCREMENTE p DE 1
////////////////////////////////////////////////////////////////////////
/////////////////////// On trace la grande barre intérieur droite //////
    //gotoligcol(9, 147);
    for(j = 0; j < 5; j++)
    {
        for(i = 0; i < six; i++)
        {
            gotoligcol(q,longda);
            printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE
            q = q+1;
        }
        gotoligcol(q,longda);
        printf("%c", 0xC3); //AFFICHE LA RELIURE ENTRE UNE BARRE HORIZONTALE ET UNE BARRE VERTICALE
        q = q + 1; //INCREMENTE q DE 1
    }

    for(i = 0; i < six; i++)
    {
        gotoligcol(q,longda);
        printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE
        q = q+1; //INCREMENTE q DE 1
    }
    gotoligcol(q,longda);
    printf("%c", 0xC0); //AFFICHE L'ANGLE EN BAS A GAUCHE
    q = q + 1; //INCREMENTE q DE 1
/////////////////////////////// OBLIGE DE METTRE CA SINON BUG/////////////////
    gotoligcol(7, longda);
    printf("%c", 0XB3); //AFFICHE UNE BARRE VERTICALE

    gotoligcol(56, longda);
    printf("%c", 0XB3); //AFFICHE UNE BARRE VERTICALE
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
//////////////////// On trace l'avant dernière ligne du plateau////////
    gotoligcol(50, 16);
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c", 0xC5); //AFFICHE LA RELIURE ENTRE UNE BARRE HORIZONTALE ET UNE BARRE VERTICALE
    for(i = 0; i < (tailleCarre-2); i++)
    {
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
        printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
        printf("%c", 0xC2); //AFFICHE LA RELIURE ENTRE UNE BARRE HORIZONTALE ET UNE BARRE VERTICALE
    }
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c", 0xC5); //AFFICHE LA RELIURE ENTRE UNE BARRE HORIZONTALE ET UNE BARRE VERTICALE

    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    printf("%c%c%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //AFFICHE DES BARRES HORIZONTALES
    /////////////////////////////////////////////////////////////////////
    ////////////////////// Jonction entre les deux dernières lignes//////
    gotoligcol(51,37);
    for(i = 0; i < 7; i++)
    {
        for(j = 0; j < 6; j++)
        {
            printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE
            gotoligcol(r, s);
            r += 1; //INCREMENTE r DE 1
        }
        s += 22; //INCREMENTE s DE 22
        r = 51;
    }
    /////////////////////////////////////////////////////////////////////
    /////////////// On trace les minis barres horizontales à gauche ////
    gotoligcol(15,16);
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 21; j++)
        {
            printf("%c", 0xC4); //AFFICHE UNE BARRE HORIZONTALE
        }
        t += 7; //INCREMENTE t DE 7
        gotoligcol(t, 16);
    }
    ///////////////////////////////////////////////////////////////////
    ///////////// On trace les minis barres horizontales à droite /////
    gotoligcol(15,longda+1);
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 21; j++)
        {
            printf("%c", 0xC4); //AFFICHE UNE BARRE HORIZONTALE
        }
        u += 7; //INCREMENTE u DE 7
        gotoligcol(u, longda+1);
    }

}



void couleursPlateau()
{

    int i = 0;

    int j = 0;

/////////////////// CASES BLEU FONCE /////////////////////////////
    Color(1,0); //CASES BLEU FONCE

    for(j = 0; j < 4; j++)
    {
        /*gotoligcol(8,(37-j));
        printf("%c", 0xDB);*/

        gotoligcol(9,(37-j)); //A CHAQUE TOUR DE BOUCLE

        for(i = 0; i < 14; i++)
        {
            printf("%c", 0xDB); //AFFICHE UN CARRE DE COULEUR
            gotoligcol((neuf+i),(37-j)); //A CHAQUE TOUR DE BOUCLE ON AJOUTE I LIGNE ET ON ENLEVE J COLONNE
        }
    }
///////////////////////////////////////////////////////////////

/////////////////// CASES Bleu Fonce /////////////////////////////
    Color(1,0); //CASES BLEU FONCE

    for(j = 0; j < 4; j++)
    {
        /*gotoligcol(8,(37-j));
        printf("%c", 0xDB);*/

        gotoligcol(44,(37-j)); //A CHAQUE TOUR DE BOUCLE ON REVIENT EN ARRIERE DE 1 COLONNE

        for(i = 0; i < 7; i++)
        {
            printf("%c", 0xDB); //AFFICHE UN CARRE DE COULEUR
            gotoligcol((44+i),(37-j)); //A CHAQUE TOUR DE BOUCLE ON AJOUTE I LIGNE ET ON ENLEVE J COLONNE
        }
    }
///////////////////////////////////////////////////////////////

/////////////////// CASES ROUGE FONCE V2 /////////////////////////////
    Color(4,0); //CASES ROUGES FONCE

    for(j = 0; j < 4; j++)
    {
        /*gotoligcol(8,(37-j));
        printf("%c", 0xDB);*/

        gotoligcol(9,(172-j)); //A CHAQUE TOUR DE BOUCLE ON REVIENT EN ARRIERE DE 1 COLONNE

        for(i = 0; i < 14; i++)
        {
            printf("%c", 0xDB); //AFFICHE UN CARRE DE COULEUR
            gotoligcol((neuf+i),(172-j)); //A CHAQUE TOUR DE BOUCLE ON AJOUTE I LIGNE ET ON ENLEVE J COLONNE
        }
    }
///////////////////////////////////////////////////////////////

/////////////////// CASES ROUGE FLUO V2 /////////////////////////////
    Color(12,0); //CASES ROUGE FLUO

    for(j = 0; j < 4; j++)
    {
        /*gotoligcol(8,(37-j));
        printf("%c", 0xDB);*/

        gotoligcol(37,(172-j)); //A CHAQUE TOUR DE BOUCLE ON REVIENT EN ARRIERE DE 1 COLONNE

        for(i = 0; i < 14; i++)
        {
            printf("%c", 0xDB); //AFFICHE UN CARRE DE COULEUR
            gotoligcol((trentesept+i),(172-j)); //A CHAQUE TOUR DE BOUCLE ON AJOUTE I LIGNE ET ON ENLEVE J COLONNE
        }
    }
///////////////////////////////////////////////////////////////

/////////////////// CASES TURQUOISE ////////////////////////////

    Color(11,0); //CASES TURQUOISES

    for(j = 0; j < 2; j++)
    {
        /*gotoligcol(8,(37-j));
        printf("%c", 0xDB);*/

        gotoligcol((8-j),37); //A CHAQUE TOUR DE BOUCLE ON REVIENT EN ARRIERE DE 1 LIGNE

        for(i = 0; i < 45; i++)
        {
            printf("%c", 0xDB); //AFFICHE UN CARRE DE COULEUR
            gotoligcol((8-j), (trentesept+i)); //A CHAQUE TOUR DE BOUCLE ON AJOUTE I LIGNE ET ON ENLEVE J COLONNE
        }
    }
//////////////////////////////////////////////////////////////

/////////////////// CASES BLEU CLAIR V2 ////////////////////////////

    Color(9,0); //CASES BLEU CLAIR

    for(j = 0; j < 2; j++)
    {
        /*gotoligcol(8,(37-j));
        printf("%c", 0xDB);*/

        gotoligcol((8-j),125); //A CHAQUE TOUR DE BOUCLE ON REVIENT EN ARRIERE DE 1 LIGNE

        for(i = 0; i < 45; i++)
        {
            printf("%c", 0xDB); //AFFICHE UN CARRE DE COULEUR
            gotoligcol((8-j), (125+i)); //A CHAQUE TOUR DE BOUCLE ON AJOUTE I LIGNE ET ON ENLEVE J COLONNE
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
            gotoligcol((50+j), (trentesept+i)); //A CHAQUE TOUR DE BOUCLE ON AJOUTE I LIGNE ET J COLONNE
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
            printf("%c", 0xDB); //ON AFFICHE UN CARRE DE COULEUR
            gotoligcol((50+j), (125+i)); //A CHAQUE TOUR DE BOUCLE ON AJOUTE I LIGNE ET J COLONNE
        }
    }
//////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////
///////////////////// PRISON /////////////////////////////////
    Color(15,0);
    /////////////////// PREMIER BARREAU /////////////////////
    gotoligcol(1,174);
    for(j = 0; j< 1; j++)
    {
        for(i = 0; i < 6; i++)
        {
            printf("%c", 0xDB);//ON AFFICHE UN CARRE DE COULEUR
            gotoligcol((1+i), (174+j)); //A CHAQUE TOUR DE BOUCLE ON AJOUTE I LIGNE ET J COLONNE
        }
        gotoligcol(1, (174 + j)); //A CHAQUE TOUR DE BOUCLE ON AJOUTE J LIGNE
    }
    ///////////////////////////////////////////////////////
    //////////////// DEUXIEME BARREAU /////////////////////
    gotoligcol(1,177);
    for(j = 0; j< 1; j++)
    {
        for(i = 0; i < 6; i++)
        {
            printf("%c", 0xDB); //ON AFFICHE UN CARRE DE COULEUR
            gotoligcol((1+i), (177+j)); //A CHAQUE TOUR DE BOUCLE ON AJOUTE I LIGNE ET J COLONNE
        }
        gotoligcol(1, (177 + j)); //A CHAQUE TOUR DE BOUCLE ON AJOUTE J LIGNE
    }
    ///////////////////////////////////////////////
    //////////////// 3 EME BARREAU ///////////////
    gotoligcol(1,180);
    for(j = 0; j< 1; j++)
    {
        for(i = 0; i < 6; i++)
        {
            printf("%c", 0xDB); //ON AFFICHE UN CARRE DE COULEUR
            gotoligcol((1+i), (180+j)); //A CHAQUE TOUR DE BOUCLE ON AJOUTE I LIGNE ET J COLONNE
        }
        gotoligcol(1, (180 + j)); //A CHAQUE TOUR DE BOUCLE ON AJOUTE J LIGNE
    }
    /////////////////////////////////////////////
    //////////////// 4 EME BARREAU ///////////////
    gotoligcol(1,183);
    for(j = 0; j< 1; j++)
    {
        for(i = 0; i < 6; i++)
        {
            printf("%c", 0xDB); //ON AFFICHE UN CARRE DE COULEUR
            gotoligcol((1+i), (183+j)); //A CHAQUE TOUR DE BOUCLE ON AJOUTE I LIGNE ET J COLONNE
        }
        gotoligcol(1, (183 + j)); //A CHAQUE TOUR DE BOUCLE ON AJOUTE J LIGNE
    }
    /////////////////////////////////////////////
    //////////////// 5 EME BARREAU ///////////////
    gotoligcol(1,186);
    for(j = 0; j< 1; j++)
    {
        for(i = 0; i < 6; i++)
        {
            printf("%c", 0xDB); //ON AFFICHE UN CARRE DE COULEUR
            gotoligcol((1+i), (186+j)); //A CHAQUE TOUR DE BOUCLE ON AJOUTE I LIGNE ET J COLONNE
        }
        gotoligcol(1, (186 + j)); //A CHAQUE TOUR DE BOUCLE ON AJOUTE J LIGNE
    }

    gotoligcol(7, 176);
    printf("TROU NOIR");
    /////////////////////////////////////////////

    ////////////// CASE DEPART /////////////////
    gotoligcol(4, 16);
    printf("D   E   P   A   R   T");
//////////////////////////////////////////////////////////////
////////////////// AFFICHAGE CARTES CHANCES SUR PLATEAU //////
    gotoligcol(4, 108); // EN HAUT
    printf("CARTE CHANCE");
    gotoligcol(53, 108);
    printf("CARTE CHANCE");// EN BAS
/////////////////////////////////////////////////////////////
///////////////// AFFICHAGE CARTES COMMUNAUTES///////////////
    gotoligcol(39, 18);//A GAUCHE
    printf("CARTE COMMUNAUTE");

    gotoligcol(25, 172);//A DROITE
    printf("CARTE COMMLUNAUTE");
////////////////////////////////////////////////////////////
///////////////////// AFFICHAGES GARES ////////////////////

    gotoligcol(4,88);//EN HAUT
    printf("SATELLITE");

    gotoligcol(32, 177);// A DROITE
    printf("SATELLITE");

    gotoligcol(53, 88);// EN BAS
    printf("SATELLITE");

    gotoligcol(32, 22);// A GAUCHE
    printf("SATELLITE");

///////////////////////////////////////////////////////////
/////////////////////// AFFICHAGE IMPOTS //////////////////

    gotoligcol(25, 23);
    printf("IMPOTS");
//////////////////////////////////////////////////////////
////////////////////// AFFICHAGE ALLER //////////////////
    gotoligcol(53, 23);
    printf("ALLER");
    gotoligcol(54, 21);
    printf("EN PRISON");
////////////////////////////////////////////////////////
//////////////////////// PARC GRATUIT //////////////////
    gotoligcol(53, 178);
    printf("PARC");
    gotoligcol(54, 177);
    printf("GRATUIT");


}



