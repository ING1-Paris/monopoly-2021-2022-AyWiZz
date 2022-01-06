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
    CartePlanete tabCartesPlanetes[15];

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

    int repAchat = 0;

    curseur = positionCurseur();
    if(curseur == 2)
    {
        sauvegarde = checkPartie();
    }
    system("cls");

    nbJoueurs = remplissageJoueur(player);
    //remplir(player);
    //////////////// REMPLI TOUT LES JOUEURS //////////////
    for (int i=1; i<7; i++)
    {
        player[i].argent = 1500;
        player[i].position = 0;
        //j[i].haveToPlay = 0;
    }
    //////////////////////////////////////////////////////
    joueurPlaying = choixDepart(nbJoueurs);

    // system("cls");
    couleursPlateau();
    creationPlateau();

    gotoligcol(1, 195);
    printf("C'est %s qui commence la partie", player[joueurPlaying].nom);

    do
    {

        gotoligcol(2, 195);

        printf("C'est %s qui joue ,c'est le joueur %d", player[joueurPlaying].nom,joueurPlaying);
        player[joueurPlaying].haveToPlay = 1;

        gotoligcol(3, 195);

        printf("Entrez 1 pour tirer les dees. \n");
        gotoligcol(4, 195);

        scanf("%d", &player[joueurPlaying].choix);

        system("cls");
        couleursPlateau();
        creationPlateau();


        if(player[joueurPlaying].choix == 1)
        {
            gotoligcol(5, 195);
            printf("D'accord");
            player[joueurPlaying].choix = 0;

            des(nbDe,pnbDe);
            player[joueurPlaying].lastposition = player[joueurPlaying].position;
            player[joueurPlaying].position = player[joueurPlaying].lastposition + nbDe;

            gotoligcol(6, 195);

            printf("Tu va vers l'avant de %d cases ! ", nbDe);
            nbDe = 0;
            for(int i = 0; i <= nbJoueurs; i++)
            {
                affichPion(player, i);
            }
            //affichPion(player, joueurPlaying);
        }

        switch(player[joueurPlaying].position)
        {
        case 1:
            carteVille(0);
            if(tabCartesPlanetes[0].possede == 0)
            {
                gotoligcol(45, 90);
                printf("Voulez vous acheter Mercure ? 1 pour Oui; 0 pour Non.");
                scanf("%d", &repAchat);
                if(repAchat == 1)
                {
                    player[joueurPlaying].argent -= tabCartesPlanetes[0].loyer;
                    player[joueurPlaying].terrain1[15] = "MERCURE";
                    tabCartesPlanetes[0].possession == joueurPlaying;
                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Mercure");
                    gotoligcol(47, 90);
                    printf(" Vous avez %d $", player[joueurPlaying]. argent);

                }

            }
            else if(tabCartesPlanetes[0].possede == 1)
            {
                gotoligcol(45, 90);
                printf("Mercure est déjà possede !");
            }


            break;
        case 2:
            carteVille(1);
            if(tabCartesPlanetes[1].possede == 0)
            {
                gotoligcol(45, 90);
                printf("Voulez vous acheter Venus ? 1 pour Oui; 0 pour Non.");
                scanf("%d", &repAchat);
                if(repAchat == 1)
                {
                    player[joueurPlaying].argent -= tabCartesPlanetes[1].loyer;
                    player[joueurPlaying].terrain1[15] = "VENUS";
                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Venus");

                }

            }
            else if(tabCartesPlanetes[1].possede == 1)
            {
                gotoligcol(45, 90);
                printf("Venus est déjà possede !");
            }
            break;
        case 3:

            break;
        case 4:
            cartesChance();


            break;
        case 5:
            carteVille(2);
            if(tabCartesPlanetes[2].possede == 0)
            {
                gotoligcol(45, 90);
                printf("Voulez vous acheter la Lune ? 1 pour Oui; 0 pour Non.");
                scanf("%d", &repAchat);
                if(repAchat == 1)
                {
                    player[joueurPlaying].argent -= tabCartesPlanetes[2].loyer;
                    player[joueurPlaying].terrain1[15] = "LUNE";
                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Lune");

                }

            }
            else if(tabCartesPlanetes[0].possede == 1)
            {
                gotoligcol(45, 90);
                printf("Lune est déjà possede !");
            }

            break;
        case 6:
            carteVille(3);
            if(tabCartesPlanetes[3].possede == 0)
            {
                gotoligcol(45, 90);
                printf("Voulez vous acheter la Terre ? 1 pour Oui; 0 pour Non.");
                scanf("%d", &repAchat);
                if(repAchat == 1)
                {
                    /*gotoligcol(47, 90);
                    printf(" Vous avez %d $", player[joueurPlaying]. argent);*/
                    player[joueurPlaying].argent -= tabCartesPlanetes[3].loyer;
                    player[joueurPlaying].terrain1[taille] = "TERRE";
                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter la Terre");
                    gotoligcol(47, 90);
                    printf(" Vous avez %d $", player[joueurPlaying]. argent);
                    gotoligcol(47, 90);
                    printf("%s", player[joueurPlaying].terrain1);

                }

            }
            else if(tabCartesPlanetes[3].possede == 1)
            {
                gotoligcol(45, 90);
                printf("La Terre est déjà possede !");
            }
            break;
        case 7:
            break;
        case 8:
            carteVille(4);
            if(tabCartesPlanetes[4].possede == 0)
            {
                gotoligcol(45, 90);
                printf("Voulez vous acheter Phobos ? 1 pour Oui; 0 pour Non.");
                scanf("%d", &repAchat);
                if(repAchat == 1)
                {
                    player[joueurPlaying]. argent -= tabCartesPlanetes[4].loyer;
                    player[joueurPlaying].terrain1[15] = "PHOBOS";
                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Phobos");

                }

            }
            else if(tabCartesPlanetes[4].possede == 1)
            {
                gotoligcol(45, 90);
                printf("Phobos est déjà possede !");
            }

            break;
        case 9:
            carteVille(5);
            if(tabCartesPlanetes[5].possede == 0)
            {
                gotoligcol(45, 90);
                printf("Voulez vous acheter Mars ? 1 pour Oui; 0 pour Non.");
                scanf("%d", &repAchat);
                if(repAchat == 1)
                {
                    player[joueurPlaying]. argent -= tabCartesPlanetes[5].loyer;
                    player[joueurPlaying].terrain1[15] = "MARS";
                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Mars");

                }

            }
            else if(tabCartesPlanetes[5].possede == 1)
            {
                gotoligcol(45, 90);
                printf("Mars est déjà possede !");
            }

            break;
        case 10:
            carteCommunaute();

            break;
        case 11:

            break;
        case 12:
            carteVille(6);
            if(tabCartesPlanetes[6].possede == 0)
            {
                gotoligcol(45, 90);
                printf("Voulez vous acheter Triton ? 1 pour Oui; 0 pour Non.");
                scanf("%d", &repAchat);
                if(repAchat == 1)
                {
                    player[joueurPlaying]. argent -= tabCartesPlanetes[6].loyer;
                    player[joueurPlaying].terrain1[taille] = "TRITON";
                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Triton");

                }

            }
            else if(tabCartesPlanetes[6].possede == 1)
            {
                gotoligcol(45, 90);
                printf("Triton est déjà possede !");
            }

            break;
        case 13:
            carteVille(7);
            if(tabCartesPlanetes[7].possede == 0)
            {
                gotoligcol(45, 90);
                printf("Voulez vous acheter Neptune ? 1 pour Oui; 0 pour Non.");
                scanf("%d", &repAchat);
                if(repAchat == 1)
                {
                    player[joueurPlaying]. argent -= tabCartesPlanetes[7].loyer;
                    player[joueurPlaying].terrain1[15] = "NEPTUNE";
                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Neptune");

                }

            }
            else if(tabCartesPlanetes[7].possede == 1)
            {
                gotoligcol(45, 90);
                printf("Neptune est déjà possede !");
            }

            break;
        case 14:

            break;
        case 15:
            carteVille(8);
            if(tabCartesPlanetes[8].possede == 0)
            {
                gotoligcol(45, 90);
                printf("Voulez vous acheter Titanium ? 1 pour Oui; 0 pour Non.");
                scanf("%d", &repAchat);
                if(repAchat == 1)
                {
                    player[joueurPlaying]. argent -= tabCartesPlanetes[8].loyer;
                    player[joueurPlaying].terrain1[15] = "TITANIUM";
                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Titanium");

                }

            }
            else if(tabCartesPlanetes[8].possede == 1)
            {
                gotoligcol(45, 90);
                printf("Titanium est déjà possede !");
            }

            break;
        case 16:
            carteVille(9);
            if(tabCartesPlanetes[9].possede == 0)
            {
                gotoligcol(45, 90);
                printf("Voulez vous acheter Uranus ? 1 pour Oui; 0 pour Non.");
                scanf("%d", &repAchat);
                if(repAchat == 1)
                {
                    player[joueurPlaying]. argent -= tabCartesPlanetes[9].loyer;
                    player[joueurPlaying].terrain1[15] = "URANUS";
                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Uranus");

                }

            }
            else if(tabCartesPlanetes[9].possede == 1)
            {
                gotoligcol(45, 90);
                printf("Uranus est déjà possede !");
            }

            break;
        case 17:
            cartesChance();

            break;
        case 18:

            break;
        case 19:
            carteVille(10);
            if(tabCartesPlanetes[10].possede == 0)
            {
                gotoligcol(45, 90);
                printf("Voulez vous acheter Titan ? 1 pour Oui; 0 pour Non.");
                scanf("%d", &repAchat);
                if(repAchat == 1)
                {
                    player[joueurPlaying]. argent -= tabCartesPlanetes[10].loyer;
                    player[joueurPlaying].terrain1[15] = "TITAN";
                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Titan");

                }

            }
            else if(tabCartesPlanetes[10].possede == 1)
            {
                gotoligcol(45, 90);
                printf("Titan est déjà possede !");
            }

            break;
        case 20:
            carteVille(11);
            if(tabCartesPlanetes[11].possede == 0)
            {
                gotoligcol(45, 90);
                printf("Voulez vous acheter Saturne ? 1 pour Oui; 0 pour Non.");
                scanf("%d", &repAchat);
                if(repAchat == 1)
                {
                    player[joueurPlaying]. argent -= tabCartesPlanetes[11].loyer;
                    player[joueurPlaying].terrain1[15] = "SATURNE";
                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Saturne");

                }

            }
            else if(tabCartesPlanetes[11].possede == 1)
            {
                gotoligcol(45, 90);
                printf("Saturne est déjà possede !");
            }
            break;
        case 21:

            break;
        case 22:
            carteVille(12);
            if(tabCartesPlanetes[12].possede == 0)
            {
                gotoligcol(45, 90);
                printf("Voulez vous acheter Europe ? 1 pour Oui; 0 pour Non.");
                scanf("%d", &repAchat);
                if(repAchat == 1)
                {
                    player[joueurPlaying]. argent -= tabCartesPlanetes[12].loyer;
                    player[joueurPlaying].terrain1[15] = "EUROPE";
                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Europe");

                }

            }
            else if(tabCartesPlanetes[12].possede == 1)
            {
                gotoligcol(45, 90);
                printf("Europe est déjà possede !");
            }
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
            if(tabCartesPlanetes[13].possede == 0)
            {
                gotoligcol(45, 90);
                printf("Voulez vous acheter Ganymede ? 1 pour Oui; 0 pour Non.");
                scanf("%d", &repAchat);
                if(repAchat == 1)
                {
                    player[joueurPlaying]. argent -= tabCartesPlanetes[13].loyer;
                    player[joueurPlaying].terrain1[15] = "GANYMEDE";
                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Ganymede");

                }

            }
            else if(tabCartesPlanetes[13].possede == 1)
            {
                gotoligcol(45, 90);
                printf("Ganymede est déjà possede !");
            }

            break;
        case 27:
            carteVille(14);
            if(tabCartesPlanetes[14].possede == 0)
            {
                gotoligcol(45, 90);
                printf("Voulez vous acheter Jupiter ? 1 pour Oui; 0 pour Non.");
                scanf("%d", &repAchat);
                if(repAchat == 1)
                {
                    player[joueurPlaying]. argent -= tabCartesPlanetes[14].loyer;
                    player[joueurPlaying].terrain1[15] = "JUPITER";
                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Jupiter");

                }

            }
            else if(tabCartesPlanetes[14].possede == 1)
            {
                gotoligcol(45, 90);
                printf("Jupiter est déjà possede !");
            }

            break;
        case 28:
            player[joueurPlaying].position = 1;
            break;

        }

        //joueurPlaying+=1;

        gotoligcol(8,195);

        affichInfo(player,joueurPlaying);
        printf("joueurplaying a fini  = % d",joueurPlaying);
        if(joueurPlaying>=nbJoueurs)
        {
            joueurPlaying = 1;
        }
        else
        {
            joueurPlaying++;
        }
    }
    while(1==1);






    // des(nbDe,pnbDe);

    // affichPion(player, joueurJ);


    gotoligcol(58,0);

    return 0;

}
