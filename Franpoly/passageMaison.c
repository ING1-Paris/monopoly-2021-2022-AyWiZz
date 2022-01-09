#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"

void passMaison(Joueur j[], CartePlanete tabCartes[], int joueurPlaying, int planete)
{
    if(tabCartes[planete].nbMaisons == 0)
    {
        gotoligcol(47,90);
        j[joueurPlaying].argent -= tabCartes[planete].loyer; // LE JOUEUR PAYE LE LOYER
        j[tabCartes[planete].possession].argent += tabCartes[planete].loyer;
        printf("Vous venez de payer un loyer de %d M $ au joueur : %s",tabCartes[planete].loyer, j[tabCartes[planete].possession].nom);
    }
    else if(tabCartes[planete].nbMaisons == 1)
    {
        gotoligcol(47,90);
        j[joueurPlaying].argent -= tabCartes[planete].loyer1; // LE JOUEUR PAYE LE LOYER
        j[tabCartes[planete].possession].argent += tabCartes[planete].loyer1;
        printf("Vous venez de payer un loyer de %d M $ au joueur : %s",tabCartes[planete].loyer1, j[tabCartes[planete].possession].nom);
    }
    else if(tabCartes[planete].nbMaisons == 2)
    {
        gotoligcol(47,90);
        j[joueurPlaying].argent -= tabCartes[planete].loyer2; // LE JOUEUR PAYE LE LOYER
        j[tabCartes[planete].possession].argent += tabCartes[planete].loyer2;
        printf("Vous venez de payer un loyer de %d M $ au joueur : %s",tabCartes[planete].loyer2, j[tabCartes[planete].possession].nom);
    }
    else if(tabCartes[planete].nbMaisons == 3)
    {
        gotoligcol(47,90);
        j[joueurPlaying].argent -= tabCartes[planete].loyer3; // LE JOUEUR PAYE LE LOYER
        j[tabCartes[planete].possession].argent += tabCartes[planete].loyer3;
        printf("Vous venez de payer un loyer de %d M $ au joueur : %s",tabCartes[planete].loyer3, j[tabCartes[planete].possession].nom);
    }
    else if(tabCartes[planete].nbMaisons == 4)
    {
        gotoligcol(47,90);
        j[joueurPlaying].argent -= tabCartes[planete].loyer4; // LE JOUEUR PAYE LE LOYER
        j[tabCartes[planete].possession].argent += tabCartes[planete].loyer4;
        printf("Vous venez de payer un loyer de %d M $ au joueur : %s",tabCartes[planete].loyer4, j[tabCartes[planete].possession].nom);
    }
    else if(tabCartes[planete].nbMaisons == 5)
    {
        gotoligcol(47,90);
        j[joueurPlaying].argent -= tabCartes[planete].loyer5; // LE JOUEUR PAYE LE LOYER
        j[tabCartes[planete].possession].argent += tabCartes[planete].loyer5;
        printf("Vous venez de payer un loyer de %d au joueur : %s",tabCartes[planete].loyer5, j[tabCartes[planete].possession].nom);
    }
}
void passSat(Joueur j[], Satellite sat[], int joueurPlaying, int satellite){

printf("j[joueurPLaying].nbSat = %d dans la boucle de payment ",j[joueurPlaying].nbSat);
if(j[joueurPlaying].nbSat == 1)
    {
        gotoligcol(48,90);
        j[joueurPlaying].argent -= sat[satellite].loyer; // LE JOUEUR PAYE LE LOYER
        j[sat[satellite].possession].argent += sat[satellite].loyer;
        printf("Vous venez de payer un loyer de %d au joueur : %s",sat[satellite].loyer, j[sat[satellite].possession].nom);
    }
else if(j[joueurPlaying].nbSat == 2)
    {
        gotoligcol(48,90);
        j[joueurPlaying].argent -= sat[satellite].loyer2; // LE JOUEUR PAYE LE LOYER
        j[sat[satellite].possession].argent += sat[satellite].loyer2;
        printf("Vous venez de payer un loyer de %d au joueur : %s",sat[satellite].loyer2, j[sat[satellite].possession].nom);
    }
else if(j[joueurPlaying].nbSat == 3)
    {
        gotoligcol(48,90);
        j[joueurPlaying].argent -= sat[satellite].loyer3; // LE JOUEUR PAYE LE LOYER
        j[sat[satellite].possession].argent += sat[satellite].loyer3;
        printf("Vous venez de payer un loyer de %d au joueur : %s",sat[satellite].loyer3, j[sat[satellite].possession].nom);
    }
else if(j[joueurPlaying].nbSat == 4)
    {
        gotoligcol(48,90);
        j[joueurPlaying].argent -= sat[satellite].loyer4; // LE JOUEUR PAYE LE LOYER
        j[sat[satellite].possession].argent += sat[satellite].loyer4;
        printf("Vous venez de payer un loyer de %d au joueur : %s",sat[satellite].loyer4, j[sat[satellite].possession].nom);
    }


}
