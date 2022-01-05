#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"


int cartesChance()
{
    int aleatoire = generationAleatoireChance();
    gotoligcol(100, 50);

    CarteChance tabCartes[32];
    creationCartesChance(tabCartes);
    creationContourCarteChanceCommunaute();
    affichageCarteChance(aleatoire, tabCartes);

    return aleatoire;
}
void carteVille(int numero)
{

    gotoligcol(100, 50);

    CartePlanete tabCartesPlanetes[15]; //CREER UN TABLEAU DE 15 CARTES
    creationCartesPlanetes(tabCartesPlanetes); //CREER LES 15 CARTES
    creationContourCarteVille();// CREER LE CONTOUR D'UNE CARTE
    affichageCartesVilles(numero, tabCartesPlanetes);// PERMET D'AFFICHER LA CARTE QUE L'ON SOUHAITE

}

int carteCommunaute()
{
    int aleatoire = generationAleatoireCommu();
    gotoligcol(100, 50);

    CarteChance tabCartes[32];
    creationCartesCommunautes(tabCartes);
    creationContourCarteChanceCommunaute();
    affichageCarteCommunautes(aleatoire, tabCartes);

    return aleatoire;

}

int main()
{


    Joueur player[6];
    setConsoleFullscreen();

    int game = 1;
    int numero = 0;
    int joueurJ = 0;

    int joueurPlaying = 0;
    int ligne = 0;
    int curseur = 1;
    int sauvegarde = 0;
    int nbJoueurs = 0;

    int nbDe = 0;
    int *pnbDe = &nbDe;

    curseur = positionCurseur();
    if(curseur == 2)
    {
        sauvegarde = checkPartie();
    }
    system("cls");



    nbJoueurs = remplissageJoueur(player);
    remplir(player);
    joueurPlaying = choixDepart(nbJoueurs);

    // system("cls");
    couleursPlateau();
    creationPlateau();

    gotoligcol(1, 195);
    printf("C'est %s qui commence la partie", player[joueurPlaying].nom);
    // while(joueurPlaying<nbJoueurs){
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
            if(player[joueurPlaying].position > 27)
            {
                player[joueurPlaying].position = 0;
            }
            gotoligcol(5, 195);
            printf("Daccord");
            player[joueurPlaying].choix = 0;

            des(nbDe,pnbDe);
            player[joueurPlaying].lastposition = player[joueurPlaying].position;
            player[joueurPlaying].position = player[joueurPlaying].lastposition + nbDe;

            gotoligcol(6, 195);

            printf("Tu va vers l'avant de %d cases ! ", nbDe);
            nbDe = 0;
            affichPion(player, joueurPlaying);
        }

        switch(player[joueurPlaying].position)
        {
        case 1:
            carteVille(0);


            break;
        case 2:
            carteVille(1);

            break;
        case 3:

            break;
        case 4:
            cartesChance();


            break;
        case 5:
            carteVille(2);


            break;
        case 6:
            carteVille(3);
            break;
        case 7:
            break;
        case 8:
            carteVille(4);

            break;
        case 9:
            carteVille(5);

            break;
        case 10:
            carteCommunaute();

            break;
        case 11:

            break;
        case 12:
            carteVille(6);

            break;
        case 13:
            carteVille(7);

            break;
        case 14:

            break;
        case 15:
            carteVille(8);

            break;
        case 16:
            carteVille(9);

            break;
        case 17:
            cartesChance();

            break;
        case 18:

            break;
        case 19:
            carteVille(10);

            break;
        case 20:
            carteVille(11);

            break;
        case 21:

            break;
        case 22:
            carteVille(12);

            break;
        case 23:
            carteCommunaute();

            break;
        case 24:

            break;
        case 25:

            break;
        case 26:
            carteVille(13);

            break;
        case 27:
            carteVille(14);

            break;
        case 28:
            player[joueurPlaying].position = 1;
            break;

        }

        //joueurPlaying+=1;

        gotoligcol(8,195);
        printf("joueurplaying  = %d",joueurPlaying);

    }
    while(player[joueurPlaying].haveToPlay == 1);
    //}




    // des(nbDe,pnbDe);

    // affichPion(player, joueurJ);


    gotoligcol(58,0);

    return 0;

}
