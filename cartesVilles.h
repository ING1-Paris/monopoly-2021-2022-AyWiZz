#ifndef CARTESVILLES_H_INCLUDED
#define CARTESVILLES_H_INCLUDED



void setConsoleFullscreen();







void gotoligcol( int lig, int col );

void Color(int couleurDuTexte,int couleurDeFond);

void setConsoleSize(short width, short height);

typedef struct
{
    char nom[30];

    char couleur[15];

    int loyer;

    int loyer1;

    int loyer2;

    int loyer3;

    int loyer4;

    int loyer5;

    int hypo;

} CartePlanete;

void affichageCartesVilles(int aleatoire, CartePlanete tabCartesPlanetes[]);


void creationCartesPlanetes(CartePlanete tabCartesPlanetes[]);


void creationContourCarte();
#endif // CARTESVILLES_H_INCLUDED
