#include <windows.h>
#include "cartesVilles.h"
#define tailleCarre 6
#define decal 78

///////////////////////// TUTORAT /////////////////////////////////

void setConsoleSize(short width, short height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {.X=width, .Y=height};
    SMALL_RECT rect = {.Left=0, .Top=0, .Right=width-1, .Bottom=height-1};

    SetConsoleScreenBufferSize(hStdout, coord);
    SetConsoleWindowInfo(hStdout, 1, &rect);
}

////////////////////// Viens du Sujet///////////////////////////////////////////////////
void gotoligcol( int lig, int col )
{

// ressources

    COORD mycoord;

    mycoord.X = col;

    mycoord.Y = lig;

    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

}
///////////////////////////////////////////////////////////////////////////////////


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

////////////////////////////////////////////////////////////////////////////////////


/*  ENTREES : AUCUNE
    SORTIES : AUCUNE
    BUT DE CETTE FONCTION : CREER LE CONTOUR D'UNE CARTE
*/
void creationContourCarte()
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



/*  ENTREES : LE NOMBRE ALEATOIRE ENTRE PAR L'UTILISATEUR, LE TABLEAU DE 15 CARTES
    SORTIES : AUCUNE
    BUT DE LA FONCTION : AFFICHER UNE CARTE DANS LA CONSOLE
*/
void affichageCartesVilles(int aleatoire, CartePlanete tabCartesPlanetes[])
{
    int i = 0;

    int j = 0;

    int k = 0;

    char turquoise[] = "turquoise";

    char bleuClair[] = "bleu clair";

    char rougeFonce[] = "rouge fonce";

    char rouge[] = "rouge";

    char jaune[] = "jaune";

    char vert[] = "vert";

    char bleuFonce[] = "bleu fonce";

    if(strcmp(tabCartesPlanetes[aleatoire].couleur,turquoise) == 0){
        Color(11,0);
    }

    else if(strcmp(tabCartesPlanetes[aleatoire].couleur,bleuClair) == 0){
        Color(9,0);
    }

    else if(strcmp(tabCartesPlanetes[aleatoire].couleur,rougeFonce) == 0){
        Color(4,0);
    }

    else if(strcmp(tabCartesPlanetes[aleatoire].couleur,rouge) == 0){
        Color(12,0);
    }

    else if(strcmp(tabCartesPlanetes[aleatoire].couleur,jaune) == 0){
        Color(14,0);
    }

    else if(strcmp(tabCartesPlanetes[aleatoire].couleur,vert) == 0){
        Color(10,0);
    }

    else if(strcmp(tabCartesPlanetes[aleatoire].couleur,bleuFonce) == 0){
        Color(11,0);
    }

    //Color(9,0);
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
    gotoligcol(14, 85);

    if(strcmp(tabCartesPlanetes[aleatoire].couleur,turquoise) == 0){
        Color(0,11);
    }

    else if(strcmp(tabCartesPlanetes[aleatoire].couleur,bleuClair) == 0){
        Color(0,9);
    }

    else if(strcmp(tabCartesPlanetes[aleatoire].couleur,rougeFonce) == 0){
        Color(0,4);
    }

    else if(strcmp(tabCartesPlanetes[aleatoire].couleur,rouge) == 0){
        Color(0,12);
    }

    else if(strcmp(tabCartesPlanetes[aleatoire].couleur,jaune) == 0){
        Color(0,14);
    }

    else if(strcmp(tabCartesPlanetes[aleatoire].couleur,vert) == 0){
        Color(0,10);
    }

    else if(strcmp(tabCartesPlanetes[aleatoire].couleur,bleuFonce) == 0){
        Color(0,11);
    }

    //Color(0,9);

    printf("%s", tabCartesPlanetes[aleatoire].nom);

    Color(15,0);

    gotoligcol(20, 85);

    printf("LOYER : %d M $", tabCartesPlanetes[aleatoire].loyer);

    gotoligcol(24, decal);

    printf("LOYER AVEC UNE MAISON : %d M $", tabCartesPlanetes[aleatoire].loyer1);

    gotoligcol(26, decal);

    printf("LOYER AVEC DEUX MAISONS : %d M $", tabCartesPlanetes[aleatoire].loyer2);

    gotoligcol(28, decal);

    printf("LOYER AVEC TROIS MAISONS : 120 M $", tabCartesPlanetes[aleatoire].loyer3);

    gotoligcol(30, decal);

    printf("LOYER AVEC QUATRE MAISONS : %d M $", tabCartesPlanetes[aleatoire].loyer4);

    gotoligcol(32, decal);

    printf("LOYER AVEC UN HOTEL : %d M $", tabCartesPlanetes[aleatoire].loyer5);

    gotoligcol(36, decal);

    printf("VALEUR HYPOTHEQUE : %d M $", tabCartesPlanetes[aleatoire].hypo);
}

/*  ENTREES : TABLEAU DE 15 CARTES
    SORTIES : AUCUNE
    BUT DE LA FONCTION : CREER LES 15 CARTES DIFFERENTES AVEC LEURS CARACTERISTIQUES.
*/
void creationCartesPlanetes(CartePlanete tabCartesPlanetes[]){

    char planete0[] = "M   E   R   C   U   R   E";
    strcpy(tabCartesPlanetes[0].nom, planete0);
    char couleur0[] = "turquoise";
    strcpy(tabCartesPlanetes[0].couleur, couleur0);
    tabCartesPlanetes[0].loyer = 60;
    tabCartesPlanetes[0].loyer1 = 80;
    tabCartesPlanetes[0].loyer2 = 100;
    tabCartesPlanetes[0].loyer3 = 120;
    tabCartesPlanetes[0].loyer4 = 140;
    tabCartesPlanetes[0].loyer5 = 160;
    tabCartesPlanetes[0].hypo = 40;


    char planete1[] = "V   E   N   U   S";
    strcpy(tabCartesPlanetes[1].nom, planete1);
    char couleur1[] = "turquoise";
    strcpy(tabCartesPlanetes[1].couleur, couleur1);
    tabCartesPlanetes[1].loyer = 60;
    tabCartesPlanetes[1].loyer1 = 80;
    tabCartesPlanetes[1].loyer2 = 100;
    tabCartesPlanetes[1].loyer3 = 120;
    tabCartesPlanetes[1].loyer4 = 140;
    tabCartesPlanetes[1].loyer5 = 160;
    tabCartesPlanetes[1].hypo = 40;


    char planete2[] = "L   U   N   E";
    strcpy(tabCartesPlanetes[2].nom, planete2);
    char couleur2[] = "bleu clair";
    strcpy(tabCartesPlanetes[2].couleur, couleur2);
    tabCartesPlanetes[2].loyer = 100;
    tabCartesPlanetes[2].loyer1 = 120;
    tabCartesPlanetes[2].loyer2 = 140;
    tabCartesPlanetes[2].loyer3 = 160;
    tabCartesPlanetes[2].loyer4 = 180;
    tabCartesPlanetes[2].loyer5 = 200;
    tabCartesPlanetes[2].hypo = 80;


    char planete3[] = "T   E   R   R   E";
    strcpy(tabCartesPlanetes[3].nom, planete3);
    char couleur3[] = "bleu clair";
    strcpy(tabCartesPlanetes[3].couleur, couleur3);
    tabCartesPlanetes[3].loyer = 120;
    tabCartesPlanetes[3].loyer1 = 140;
    tabCartesPlanetes[3].loyer2 = 180;
    tabCartesPlanetes[3].loyer3 = 200;
    tabCartesPlanetes[3].loyer4 = 220;
    tabCartesPlanetes[3].loyer5 = 240;
    tabCartesPlanetes[3].hypo = 100;


    char planete4[] = "P   H   O   B   O   S";
    strcpy(tabCartesPlanetes[4].nom, planete4);
    char couleur4[] = "rouge fonce";
    strcpy(tabCartesPlanetes[4].couleur, couleur4);
    tabCartesPlanetes[4].loyer = 140;
    tabCartesPlanetes[4].loyer1 = 160;
    tabCartesPlanetes[4].loyer2 = 180;
    tabCartesPlanetes[4].loyer3 = 200;
    tabCartesPlanetes[4].loyer4 = 220;
    tabCartesPlanetes[4].loyer5 = 240;
    tabCartesPlanetes[4].hypo = 120;


    char planete5[] = "M   A   R   S";
    strcpy(tabCartesPlanetes[5].nom, planete5);
    char couleur5[] = "rouge fonce";
    strcpy(tabCartesPlanetes[5].couleur, couleur5);
    tabCartesPlanetes[5].loyer = 150;
    tabCartesPlanetes[5].loyer1 = 170;
    tabCartesPlanetes[5].loyer2 = 190;
    tabCartesPlanetes[5].loyer3 = 210;
    tabCartesPlanetes[5].loyer4 = 230;
    tabCartesPlanetes[5].loyer5 = 250;
    tabCartesPlanetes[5].hypo = 130;


    char planete6[] = "T   R   I   T   O   N";
    strcpy(tabCartesPlanetes[6].nom, planete6);
    char couleur6[] = "rouge";
    strcpy(tabCartesPlanetes[6].couleur, couleur6);
    tabCartesPlanetes[6].loyer = 180;
    tabCartesPlanetes[6].loyer1 = 200;
    tabCartesPlanetes[6].loyer2 = 220;
    tabCartesPlanetes[6].loyer3 = 240;
    tabCartesPlanetes[6].loyer4 = 260;
    tabCartesPlanetes[6].loyer5 = 280;
    tabCartesPlanetes[6].hypo = 160;


    char planete7[] = "N   E   P   T   U   N   E";
    strcpy(tabCartesPlanetes[7].nom, planete7);
    char couleur7[] = "rouge";
    strcpy(tabCartesPlanetes[7].couleur, couleur7);
    tabCartesPlanetes[7].loyer = 200;
    tabCartesPlanetes[7].loyer1 = 220;
    tabCartesPlanetes[7].loyer2 = 240;
    tabCartesPlanetes[7].loyer3 = 260;
    tabCartesPlanetes[7].loyer4 = 280;
    tabCartesPlanetes[7].loyer5 = 300;
    tabCartesPlanetes[7].hypo = 180;


    char planete8[] = "T   I   T   A   N   I   A";
    strcpy(tabCartesPlanetes[8].nom, planete8);
    char couleur8[] = "jaune";
    strcpy(tabCartesPlanetes[8].couleur, couleur8);
    tabCartesPlanetes[8].loyer = 220;
    tabCartesPlanetes[8].loyer1 = 240;
    tabCartesPlanetes[8].loyer2 = 260;
    tabCartesPlanetes[8].loyer3 = 280;
    tabCartesPlanetes[8].loyer4 = 300;
    tabCartesPlanetes[8].loyer5 = 320;
    tabCartesPlanetes[8].hypo = 200;


    char planete9[] = "U   R   A   N   U   S";
    strcpy(tabCartesPlanetes[9].nom, planete9);
    char couleur9[] = "jaune";
    strcpy(tabCartesPlanetes[9].couleur, couleur9);
    tabCartesPlanetes[9].loyer = 240;
    tabCartesPlanetes[9].loyer1 = 260;
    tabCartesPlanetes[9].loyer2 = 280;
    tabCartesPlanetes[9].loyer3 = 300;
    tabCartesPlanetes[9].loyer4 = 320;
    tabCartesPlanetes[9].loyer5 = 340;
    tabCartesPlanetes[9].hypo = 220;


    char planete10[] = "T   I   T   A   N";
    strcpy(tabCartesPlanetes[10].nom, planete10);
    char couleur10[] = "vert";
    strcpy(tabCartesPlanetes[10].couleur, couleur10);
    tabCartesPlanetes[10].loyer = 260;
    tabCartesPlanetes[10].loyer1 = 280;
    tabCartesPlanetes[10].loyer2 = 300;
    tabCartesPlanetes[10].loyer3 = 320;
    tabCartesPlanetes[10].loyer4 = 340;
    tabCartesPlanetes[10].loyer5 = 360;
    tabCartesPlanetes[10].hypo = 240;


    char planete11[] = "S   A   T   U   R   N   E";
    strcpy(tabCartesPlanetes[11].nom, planete11);
    char couleur11[] = "vert";
    strcpy(tabCartesPlanetes[11].couleur, couleur11);
    tabCartesPlanetes[11].loyer = 280;
    tabCartesPlanetes[11].loyer1 = 300;
    tabCartesPlanetes[11].loyer2 = 320;
    tabCartesPlanetes[11].loyer3 = 340;
    tabCartesPlanetes[11].loyer4 = 360;
    tabCartesPlanetes[11].loyer5 = 380;
    tabCartesPlanetes[11].hypo = 260;


    char planete12[] = "E   U   R   O   P   E";
    strcpy(tabCartesPlanetes[12].nom, planete12);
    char couleur12[] = "bleu fonce";
    strcpy(tabCartesPlanetes[12].couleur, couleur12);
    tabCartesPlanetes[12].loyer = 300;
    tabCartesPlanetes[12].loyer1 = 320;
    tabCartesPlanetes[12].loyer2 = 340;
    tabCartesPlanetes[12].loyer3 = 360;
    tabCartesPlanetes[12].loyer4 = 380;
    tabCartesPlanetes[12].loyer5 = 400;
    tabCartesPlanetes[12].hypo = 280;


    char planete13[] = "G   A   N   Y   M   E   D   E";
    strcpy(tabCartesPlanetes[13].nom, planete13);
    char couleur13[] = "bleu fonce";
    strcpy(tabCartesPlanetes[13].couleur, couleur13);
    tabCartesPlanetes[13].loyer = 350;
    tabCartesPlanetes[13].loyer1 = 370;
    tabCartesPlanetes[13].loyer2 = 390;
    tabCartesPlanetes[13].loyer3 = 410;
    tabCartesPlanetes[13].loyer4 = 430;
    tabCartesPlanetes[13].loyer5 = 450;
    tabCartesPlanetes[13].hypo = 330;


    char planete14[] = "J   U   P   I   T   E   R";
    strcpy(tabCartesPlanetes[14].nom, planete14);
    char couleur14[] = "bleu fonce";
    strcpy(tabCartesPlanetes[14].couleur, couleur14);
    tabCartesPlanetes[14].loyer = 400;
    tabCartesPlanetes[14].loyer1 = 420;
    tabCartesPlanetes[14].loyer2 = 440;
    tabCartesPlanetes[14].loyer3 = 460;
    tabCartesPlanetes[14].loyer4 = 480;
    tabCartesPlanetes[14].loyer5 = 500;
    tabCartesPlanetes[14].hypo = 380;
}
