#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define taille 20
#include"header.h"
///fonction permettant de remplir préalablement la structure des joueurs.
///entrées : la structure des joueur.
///sortie : structure des joueurs mais remplie.


void remplir(Joueur j[])
{
    int couleurPion = 10;
    ///boucle permettant de remplir certains arguments de la structure
    for (int i=1; i<7; i++)
    {
        j[i].argent = 1500;
        j[i].position = 0;
        //j[i].haveToPlay = 0;
    }
    ///boucle permettant d'assigner une couleur à chaque joueur.
    for (int i=1; i<7; i++)
    {
        j[i].couleur = couleurPion;
        couleurPion += 1;
    }

}
///fonction permettant le remplissage des informations par les joueurs.
///entrées : la structure joueur.
///sortie : le nombre de joueur.
int remplissageJoueur(Joueur j[])
{
    int nbJoueurs = 0;
    int ligne = 3;///variable permettant le bon placement des éléments sur la console.
    gotoligcol(2,2);
    
    printf("Bienvenue sur le SPACE MONOPOLY !");
    
    ///boucle blindée permettant d'entrer le nombre de joueurs.
    do
    {
        gotoligcol(3,2);
        printf("Combien de joueurs pour cette partie ? ");
        gotoligcol(4,2);
        fflush(stdin);
        scanf("%d", &nbJoueurs);
        if(nbJoueurs>1 && nbJoueurs<6)
        {
            ligne+=1;
        }
    }
    while(nbJoueurs<1 || nbJoueurs>6);

    ///boucle permettant d'entrer le nom des différents joueurs.
    for(int i=1; i<nbJoueurs+1; i++)
    {
        gotoligcol(ligne+i,2);
        printf("Quel est le nom du joueur %d ?", i);
        gotoligcol(ligne+1+i,2);
        fflush(stdin);
        gets(j[i].nom);
        ligne++;
    }
    ///on efface la console pour pouvoir mettre le plateau.
    system("cls");
    ///on retourne le nombre de joueurs
    return nbJoueurs;

}
///fonction permettant de retourner le nombre de joueur sans rappeler la fonction précedente.
///entrées : le nombre de joueurs
///sortie : le nombre de joueurs.
int returnNbJ(int nbJoueurs)
{
    int z=nbJoueurs;
    return z;
}
