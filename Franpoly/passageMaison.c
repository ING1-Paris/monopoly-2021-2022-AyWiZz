#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"

///fonction permettant de faire payer un joueur quand il tombe sur une planète appartenant à un autre joueur
///entrées : structure du joueur et des planètes, le joueur jouant et le numéro de la planète
///sorties : l'argent des joueurs est transféré, un message s'affiche afin de montrer la transaction qui vient de se faire


void passMaison(Joueur j[], CartePlanete tabCartes[], int joueurPlaying, int planete)
{
    if(tabCartes[planete].nbMaisons == 0)///le loyer de la planete change en fonction du nombre de maisons présente sur celle-ci
    {
        gotoligcol(47,90);
        j[joueurPlaying].argent -= tabCartes[planete].loyer; // LE JOUEUR PAYE LE LOYER
        j[tabCartes[planete].possession].argent += tabCartes[planete].loyer;
        printf("Vous venez de payer un loyer de %d M $ au joueur : %s",tabCartes[planete].loyer, j[tabCartes[planete].possession].nom);
    }
    else if(tabCartes[planete].nbMaisons == 1)///le loyer de la planete change en fonction du nombre de maisons présente sur celle-ci
    {
        gotoligcol(47,90);
        j[joueurPlaying].argent -= tabCartes[planete].loyer1; // LE JOUEUR PAYE LE LOYER
        j[tabCartes[planete].possession].argent += tabCartes[planete].loyer1;///on ajoute l'argent au joueur à qui appartient la planète.
        printf("Vous venez de payer un loyer de %d M $ au joueur : %s",tabCartes[planete].loyer1, j[tabCartes[planete].possession].nom);
    }
    else if(tabCartes[planete].nbMaisons == 2)///le loyer de la planete change en fonction du nombre de maisons présente sur celle-ci
    {
        gotoligcol(47,90);
        j[joueurPlaying].argent -= tabCartes[planete].loyer2; // LE JOUEUR PAYE LE LOYER
        j[tabCartes[planete].possession].argent += tabCartes[planete].loyer2;///on ajoute l'argent au joueur à qui appartient la planète.
        printf("Vous venez de payer un loyer de %d M $ au joueur : %s",tabCartes[planete].loyer2, j[tabCartes[planete].possession].nom);
    }
    else if(tabCartes[planete].nbMaisons == 3)///le loyer de la planete change en fonction du nombre de maisons présente sur celle-ci
    {
        gotoligcol(47,90);
        j[joueurPlaying].argent -= tabCartes[planete].loyer3; // LE JOUEUR PAYE LE LOYER
        j[tabCartes[planete].possession].argent += tabCartes[planete].loyer3;///on ajoute l'argent au joueur à qui appartient la planète.
        printf("Vous venez de payer un loyer de %d M $ au joueur : %s",tabCartes[planete].loyer3, j[tabCartes[planete].possession].nom);
    }
    else if(tabCartes[planete].nbMaisons == 4)///le loyer de la planete change en fonction du nombre de maisons présente sur celle-ci
    {
        gotoligcol(47,90);
        j[joueurPlaying].argent -= tabCartes[planete].loyer4; // LE JOUEUR PAYE LE LOYER
        j[tabCartes[planete].possession].argent += tabCartes[planete].loyer4;///on ajoute l'argent au joueur à qui appartient la planète.
        printf("Vous venez de payer un loyer de %d M $ au joueur : %s",tabCartes[planete].loyer4, j[tabCartes[planete].possession].nom);
    }
    else if(tabCartes[planete].nbMaisons == 5)///le loyer de la planete change en fonction du nombre de maisons présente sur celle-ci
    {
        gotoligcol(47,90);
        j[joueurPlaying].argent -= tabCartes[planete].loyer5; // LE JOUEUR PAYE LE LOYER
        j[tabCartes[planete].possession].argent += tabCartes[planete].loyer5;///on ajoute l'argent au joueur à qui appartient la planète.
        printf("Vous venez de payer un loyer de %d au joueur : %s",tabCartes[planete].loyer5, j[tabCartes[planete].possession].nom);
    }
}

///fonction permettant de faire payer un joueur quand il tombe sur un satellite appartenant à un autre joueur
///entrées : structure du joueur et des satellite, le joueur jouant et le numéro du satellite
///sorties : l'argent des joueurs est transféré, un message s'affiche afin de montrer la transaction qui vient de se faire

void passSat(Joueur j[], Satellite sat[], int joueurPlaying, int satellite){

if(j[sat[satellite].possession].nbSat == 1)///le loyer change en fonction du nombre de satellite possedé par le joueur
    {
        gotoligcol(48,90);
        j[joueurPlaying].argent -= sat[satellite].loyer; // LE JOUEUR PAYE LE LOYER
        j[sat[satellite].possession].argent += sat[satellite].loyer;///on ajoute l'argent au joueur à qui appartient le satellite.
        printf("Vous venez de payer un loyer de %d au joueur : %s",sat[satellite].loyer, j[sat[satellite].possession].nom);
    }
else if(j[sat[satellite].possession].nbSat == 2)///le loyer change en fonction du nombre de satellite possedé par le joueur
    {
        gotoligcol(48,90);
        j[joueurPlaying].argent -= sat[satellite].loyer2; // LE JOUEUR PAYE LE LOYER
        j[sat[satellite].possession].argent += sat[satellite].loyer2;///on ajoute l'argent au joueur à qui appartient le satellite.
        printf("Vous venez de payer un loyer de %d au joueur : %s",sat[satellite].loyer2, j[sat[satellite].possession].nom);
    }
else if(j[sat[satellite].possession].nbSat == 3)///le loyer change en fonction du nombre de satellite possedé par le joueur
    {
        gotoligcol(48,90);
        j[joueurPlaying].argent -= sat[satellite].loyer3; // LE JOUEUR PAYE LE LOYER
        j[sat[satellite].possession].argent += sat[satellite].loyer3;///on ajoute l'argent au joueur à qui appartient le satellite.
        printf("Vous venez de payer un loyer de %d au joueur : %s",sat[satellite].loyer3, j[sat[satellite].possession].nom);
    }
else if(j[sat[satellite].possession].nbSat == 4)///le loyer change en fonction du nombre de satellite possedé par le joueur
    {
        gotoligcol(48,90);
        j[joueurPlaying].argent -= sat[satellite].loyer4; // LE JOUEUR PAYE LE LOYER
        j[sat[satellite].possession].argent += sat[satellite].loyer4;///on ajoute l'argent au joueur à qui appartient le satellite.
        printf("Vous venez de payer un loyer de %d au joueur : %s",sat[satellite].loyer4, j[sat[satellite].possession].nom);
    }


}
