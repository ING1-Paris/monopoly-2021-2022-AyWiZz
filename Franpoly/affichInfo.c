#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define taille 20
#include "header.h"
///Fonction permettant d'afficher les informations d'un joueur lorsqu'on appelle cette fonction
///Entrées : la structure du  joueur, le joueur en train de jouer et le nombre total de joueurs dans la partie.
///Sortie : affichage de l'argent du joueur et des terrains qu'il possède.

void affichInfo(Joueur j[], int joueurPlaying, int nbJoueurs)
{
    int c = 1; ///variable permettant de positionner le texte

    Color(joueurPlaying+1, 0);///initialisation de la couleur d'affichage
    gotoligcol(19, 195);
    printf("%s vous avez %d M $", j[joueurPlaying].nom,j[joueurPlaying].argent);///affichage de l'argent du joueur.
    gotoligcol(20,195);

    if(j[joueurPlaying].t1Possede ==1)///on teste si le joueur possède le terrain, si oui on affiche le nom du terrain.
    {
        printf("Vous posseder %s.", j[joueurPlaying].terrain1);///affichage du nom du terrain
        gotoligcol(20+c,195);
        c++;
    }
    if(j[joueurPlaying].t2Possede ==1)
    {
        printf("Vous posseder %s.", j[joueurPlaying].terrain2);
        gotoligcol(20+c,195);
        c++;
    }
    if(j[joueurPlaying].t3Possede ==1)
    {
        printf("Vous posseder %s.", j[joueurPlaying].terrain3);
        gotoligcol(20+c,195);
        c++;
    }
    if(j[joueurPlaying].t4Possede ==1)
    {
        printf("Vous posseder %s.", j[joueurPlaying].terrain4);
        gotoligcol(20+c,195);
        c++;
    }
    if(j[joueurPlaying].t5Possede ==1)
    {
        printf("Vous posseder %s.", j[joueurPlaying].terrain5);
        gotoligcol(20+c,195);
        c++;
    }
    if(j[joueurPlaying].t6Possede ==1)
    {
        printf("Vous posseder %s.", j[joueurPlaying].terrain6);
        gotoligcol(20+c,195);
        c++;
    }
    if(j[joueurPlaying].t7Possede ==1)
    {
        printf("Vous posseder %s.", j[joueurPlaying].terrain7);
        gotoligcol(20+c,195);
        c++;
    }
    if(j[joueurPlaying].t8Possede ==1)
    {
        printf("Vous posseder %s.", j[joueurPlaying].terrain8);
        gotoligcol(20+c,195);
        c++;
    }
    if(j[joueurPlaying].t9Possede ==1)
    {
        printf("Vous posseder %s.", j[joueurPlaying].terrain9);
        gotoligcol(20+c,195);
        c++;
    }
    if(j[joueurPlaying].t10Possede ==1)
    {
        printf("Vous posseder %s.", j[joueurPlaying].terrain10);
        gotoligcol(20+c,195);
        c++;
    }

    Color(9,0);
}




