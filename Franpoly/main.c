#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"


void cartes()
{
    int aleatoire = generationAleatoire();
    gotoligcol(100, 50);

    CarteChance tabCartes[16];
    creationCartesChance(tabCartes);
    creationContourCarte();
    affichageCarteChance(aleatoire, tabCartes);
}

int main()
{
    Joueur player[6];
    setConsoleFullscreen();
    int game = 1;

    int joueurJ = 0;

    int joueurPlaying = 0;
    int ligne = 0;
    int curseur = 1;
    int sauvegarde = 0;
    int nbJoueurs = 0;

    int nbDe = 0;
    int *pnbDe = &nbDe;

    /*
    curseur = positionCurseur();
    if(curseur == 2)
    {
        sauvegarde = checkPartie();
    }
    system("cls");

    */

    nbJoueurs = remplissageJoueur(player);
    remplir(player);
    joueurPlaying = choixDepart(nbJoueurs);

    // system("cls");
    couleursPlateau();
    creationPlateau();

    gotoligcol(1, 195);
    printf("C'est %s qui commence la partie", player[joueurPlaying].nom);
    while(joueurPlaying<nbJoueurs){
    do
    {
        gotoligcol(2, 195);

        printf("C'est %s qui joue", player[joueurPlaying].nom);
        player[joueurPlaying].haveToPlay = 1;

        gotoligcol(3, 195);

        printf("Entrez 1 pour tirer les dees. \n");
        gotoligcol(4, 195);

        scanf("%d", &player[joueurPlaying].choix);


        if(player[joueurPlaying].choix == 1)
        {
            gotoligcol(5, 195);
            printf("Daccord");
            player[joueurPlaying].choix = 0;

            des(nbDe,pnbDe);
            player[joueurPlaying].position = nbDe;
            gotoligcol(6, 195);
            printf("Tu va vers l'avant de %d cases ! ", player[joueurPlaying].position);
            affichPion(player, joueurPlaying);
        }

        switch(player[joueurPlaying].position)
        {
        case 1:

            gotoligcol(7, 195);
            printf("Good ca marche");

            break;
        case 2:
            gotoligcol(7, 195);
            printf("Good ca marche");

            break;
        case 3:
            gotoligcol(7, 195);
            printf("Good ca marche");

            break;
        case 4:
            gotoligcol(7, 195);
            printf("Good ca marche");
            cartes();

            break;
        case 5:
            gotoligcol(7, 195);
            printf("Good  la carte chance marche");
            cartes();


            break;
        case 6:
            gotoligcol(7, 195);
            printf("Good ca marche");
            cartes();

            break;
        case 7:
            gotoligcol(7, 195);
            printf("Good ca marche");

            break;
        case 8:
            gotoligcol(7, 195);
            printf("Good ca marche");

            break;
        case 9:

            break;
        case 10:

            break;
        case 11:

            break;
        case 12:

            break;
        case 13:

            break;
        case 14:

            break;
        case 15:

            break;
        case 16:

            break;
        case 17:

            break;
        case 18:

            break;
        case 19:

            break;
        case 20:

            break;
        case 21:

            break;
        case 22:

            break;
        case 23:

            break;
        case 24:

            break;
        case 25:

            break;
        case 26:

            break;
        case 27:

            break;
        case 28:

            break;
        case 29:
            player[joueurPlaying].position = 0;
            break;
        }
    joueurPlaying+=1;
    printf("joueurplaying  = %d",joueurPlaying);

    }
    while(player[joueurPlaying].haveToPlay == 1);
    }




    // des(nbDe,pnbDe);

    // affichPion(player, joueurJ);


    gotoligcol(58,0);

    return 0;

}
