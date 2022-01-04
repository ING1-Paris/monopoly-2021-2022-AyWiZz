#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
#define tailleCarre 6


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
//fonction permettant de mémoriser les cases et de se déplacer directement dessus
void affichPion(){
    //tableau à double entrée permettant de stocker les positions des cases
    int caze[26][2]={{0,0},{4,26},{4,48},{4,70},{4,92},{4,114},{4,136},{4,158},
    {11,158},{18,158},{25,158},{32,158},{39,158},{46,158},{53,158},
    {53,136},{53,114},{53,92},{53,70},{53,48},{53,26},
    {46,26},{39,26},{32,26},{25,26},{18,26},{11,26}};
    int mvtPion;
    do{
        gotoligcol(2,195);
        printf("quelle case ? :\t0 pour sortir ");
        scanf("%d", &mvtPion);
        if ((mvtPion == 0)||(mvtPion>27)||(mvtPion<0)){
            return 1;
        }
    gotoligcol(caze[mvtPion][0],caze[mvtPion][1]);
    printf("%c", 0xDB);
    }while(mvtPion>0 || mvtPion<26);

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

int main()
{
    setConsoleFullscreen();
    creationPlateau();
    affichPion();
    gotoligcol(2,200);//Pour décaler le message d'erreur
    printf("\n");
    return 0;
}
