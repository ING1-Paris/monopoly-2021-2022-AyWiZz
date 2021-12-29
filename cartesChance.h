#ifndef CARTESCHANCE_H_INCLUDED
#define CARTESCHANCE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Chance{
    char nom[100];
}CarteChance;




void gotoligcol( int lig, int col );

void creationCartesChance(CarteChance tabCartes[]);

void creationContourCarte();

void setConsoleSize(short width, short height);

void Color(int couleurDuTexte,int couleurDeFond);

void setConsoleFullscreen();

void affichageCarteChance(int aleatoire, CarteChance tabCartes[]);

int generationAleatoire();

void creationCartesCommunautes(CarteChance tabCartes[]);

void affichageCarteCommunautes(int aleatoire, CarteChance tabCartes[]);



#endif // CARTESCHANCE_H_INCLUDED
