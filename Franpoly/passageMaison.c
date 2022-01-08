#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"

void passMaison(Joueur j[], CartePlanete tabCartes[], int joueurPlaying, int planete)
{
    if(tabCartes[planete].nbMaisons == 0)
    {
        j[joueurPlaying].argent -= tabCartes[planete].loyer; // LE JOUEUR PAYE LE LOYER
        j[tabCartes[planete].possession].argent += tabCartes[planete].loyer;
        printf("Vous venez de payer un loyer de %d au joueur : %s",tabCartes[planete].loyer, j[tabCartes[planete].possession].nom);
    }
    else if(tabCartes[planete].nbMaisons == 1)
    {
        j[joueurPlaying].argent -= tabCartes[planete].loyer1; // LE JOUEUR PAYE LE LOYER
        j[tabCartes[planete].possession].argent += tabCartes[planete].loyer1;
        printf("Vous venez de payer un loyer de %d au joueur : %s",tabCartes[planete].loyer1, j[tabCartes[planete].possession].nom);
    }
    else if(tabCartes[planete].nbMaisons == 2)
    {
        j[joueurPlaying].argent -= tabCartes[planete].loyer2; // LE JOUEUR PAYE LE LOYER
        j[tabCartes[planete].possession].argent += tabCartes[planete].loyer2;
        printf("Vous venez de payer un loyer de %d au joueur : %s",tabCartes[planete].loyer2, j[tabCartes[planete].possession].nom);
    }
    else if(tabCartes[planete].nbMaisons == 3)
    {
        j[joueurPlaying].argent -= tabCartes[planete].loyer3; // LE JOUEUR PAYE LE LOYER
        j[tabCartes[planete].possession].argent += tabCartes[planete].loyer3;
        printf("Vous venez de payer un loyer de %d au joueur : %s",tabCartes[planete].loyer3, j[tabCartes[planete].possession].nom);
    }
    else if(tabCartes[planete].nbMaisons == 4)
    {
        j[joueurPlaying].argent -= tabCartes[planete].loyer4; // LE JOUEUR PAYE LE LOYER
        j[tabCartes[planete].possession].argent += tabCartes[planete].loyer4;
        printf("Vous venez de payer un loyer de %d au joueur : %s",tabCartes[planete].loyer4, j[tabCartes[planete].possession].nom);
    }
    else if(tabCartes[planete].nbMaisons == 5)
    {
        j[joueurPlaying].argent -= tabCartes[planete].loyer5; // LE JOUEUR PAYE LE LOYER
        j[tabCartes[planete].possession].argent += tabCartes[planete].loyer5;
        printf("Vous venez de payer un loyer de %d au joueur : %s",tabCartes[planete].loyer5, j[tabCartes[planete].possession].nom);
    }
}
