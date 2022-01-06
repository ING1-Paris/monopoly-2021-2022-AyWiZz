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

int carteSatellite()
{
    int aleatoire = generationAleatoireSatellite();

    creationContourCarteSatellite();

    bandeauCartes();

    Satellite tabSatellites[4];

    creationSatellites(tabSatellites);

    ecritureSatellite(tabSatellites, aleatoire);

    return aleatoire;
}

int main()
{
    CartePlanete tabCartesPlanetes[15];
    creationCartesPlanetes(tabCartesPlanetes); //CREER LES 15 CARTES

    Joueur player[6];
    setConsoleFullscreen();

    //int game = 1;
    //int numero = 0;
    //int joueurJ = 0;

    int joueurPlaying = 0;
    //int ligne = 0;
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
        player[i].nbTerrain = 0;
        //j[i].haveToPlay = 0;
    }
    for(int i = 0 ; i < 15; i++)
    {
        tabCartesPlanetes[i].possede = 0;
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

            for(int i = 0; i <= nbJoueurs; i++)
            {
                affichPion(player, i);
            }

            gotoligcol(6, 195);

            printf("Tu va vers l'avant de %d cases position %d! ", nbDe, player[joueurPlaying].position);
            nbDe = 0;
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
                    switch (player[joueurPlaying].nbTerrain)
                    {
                    case 0:
                        strcpy(player[joueurPlaying].terrain1,"MERCURE");
                        player[joueurPlaying].t1Possede = 1;
                        break;
                    case 1:
                        strcpy(player[joueurPlaying].terrain2,"MERCURE");
                        player[joueurPlaying].t2Possede = 1;
                        break;
                    case 2:
                        strcpy(player[joueurPlaying].terrain3,"MERCURE");
                        player[joueurPlaying].t3Possede = 1;
                        break;
                    case 3:
                        strcpy(player[joueurPlaying].terrain4,"MERCURE");
                        player[joueurPlaying].t4Possede = 1;
                        break;
                    case 4:
                        strcpy(player[joueurPlaying].terrain5,"MERCURE");
                        player[joueurPlaying].t5Possede = 1;
                        break;
                    }

                    player[joueurPlaying].nbTerrain+=1;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Mercure");

                    gotoligcol(47, 90);
                    tabCartesPlanetes[0].possede = 1;


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
                    switch (player[joueurPlaying].nbTerrain)
                    {
                    case 0:
                        strcpy(player[joueurPlaying].terrain1,"VENUS");
                        player[joueurPlaying].t1Possede = 1;
                        break;
                    case 1:
                        strcpy(player[joueurPlaying].terrain2,"VENUS");
                        player[joueurPlaying].t2Possede = 1;
                        break;
                    case 2:
                        strcpy(player[joueurPlaying].terrain3,"VENUS");
                        player[joueurPlaying].t3Possede = 1;
                        break;
                    case 3:
                        strcpy(player[joueurPlaying].terrain4,"VENUS");
                        player[joueurPlaying].t4Possede = 1;
                        break;
                    case 4:
                        strcpy(player[joueurPlaying].terrain5,"VENUS");
                        player[joueurPlaying].t5Possede = 1;
                        break;
                    }

                    player[joueurPlaying].nbTerrain+=1;
                    player[joueurPlaying].argent -= tabCartesPlanetes[1].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Venus");
                    tabCartesPlanetes[1].possede = 1;

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
                    switch (player[joueurPlaying].nbTerrain)
                    {
                    case 0:
                        strcpy(player[joueurPlaying].terrain1,"LUNE");
                        player[joueurPlaying].t1Possede = 1;
                        break;
                    case 1:
                        strcpy(player[joueurPlaying].terrain2,"LUNE");
                        player[joueurPlaying].t2Possede = 1;
                        break;
                    case 2:
                        strcpy(player[joueurPlaying].terrain3,"LUNE");
                        player[joueurPlaying].t3Possede = 1;
                        break;
                    case 3:
                        strcpy(player[joueurPlaying].terrain4,"LUNE");
                        player[joueurPlaying].t4Possede = 1;
                        break;
                    case 4:
                        strcpy(player[joueurPlaying].terrain5,"LUNE");
                        player[joueurPlaying].t5Possede = 1;
                        break;
                    }

                    player[joueurPlaying].nbTerrain+=1;
                    player[joueurPlaying].argent -= tabCartesPlanetes[2].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Lune");
                    tabCartesPlanetes[2].possede = 1;

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
                    player[joueurPlaying].nbTerrain+=1;

                    switch (player[joueurPlaying].nbTerrain)
                    {
                    case 0:
                        strcpy(player[joueurPlaying].terrain1,"TERRE");
                        player[joueurPlaying].t1Possede = 1;
                        break;
                    case 1:
                        strcpy(player[joueurPlaying].terrain2,"TERRE");
                        player[joueurPlaying].t2Possede = 1;
                        break;
                    case 2:
                        strcpy(player[joueurPlaying].terrain3,"TERRE");
                        player[joueurPlaying].t3Possede = 1;
                        break;
                    case 3:
                        strcpy(player[joueurPlaying].terrain4,"TERRE");
                        player[joueurPlaying].t4Possede = 1;
                        break;
                    case 4:
                        strcpy(player[joueurPlaying].terrain5,"TERRE");
                        player[joueurPlaying].t5Possede = 1;
                        break;
                    }

                    player[joueurPlaying].nbTerrain+=1;
                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter la Terre");
                    tabCartesPlanetes[3].possede=1;

                    gotoligcol(47, 90);
                    /*printf(" Vous avez %d $", player[joueurPlaying]. argent);
                    gotoligcol(47, 90);
                    printf("%s", player[joueurPlaying].terrain1);*/

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
                    switch (player[joueurPlaying].nbTerrain)
                    {
                    case 0:
                        strcpy(player[joueurPlaying].terrain1,"PHOBOS");
                        player[joueurPlaying].t1Possede = 1;
                        break;
                    case 1:
                        strcpy(player[joueurPlaying].terrain2,"PHOBOS");
                        player[joueurPlaying].t2Possede = 1;
                        break;
                    case 2:
                        strcpy(player[joueurPlaying].terrain3,"PHOBOS");
                        player[joueurPlaying].t3Possede = 1;
                        break;
                    case 3:
                        strcpy(player[joueurPlaying].terrain4,"PHOBOS");
                        player[joueurPlaying].t4Possede = 1;
                        break;
                    case 4:
                        strcpy(player[joueurPlaying].terrain5,"PHOBOS");
                        player[joueurPlaying].t5Possede = 1;
                        break;
                    }

                    player[joueurPlaying].nbTerrain+=1;
                    player[joueurPlaying]. argent -= tabCartesPlanetes[4].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Phobos");
                    tabCartesPlanetes[4].possede = 1;

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
                    switch (player[joueurPlaying].nbTerrain)
                    {
                    case 0:
                        strcpy(player[joueurPlaying].terrain1,"MARS");
                        player[joueurPlaying].t1Possede = 1;
                        break;
                    case 1:
                        strcpy(player[joueurPlaying].terrain2,"MARS");
                        player[joueurPlaying].t2Possede = 1;
                        break;
                    case 2:
                        strcpy(player[joueurPlaying].terrain3,"MARS");
                        player[joueurPlaying].t3Possede = 1;
                        break;
                    case 3:
                        strcpy(player[joueurPlaying].terrain4,"MARS");
                        player[joueurPlaying].t4Possede = 1;
                        break;
                    case 4:
                        strcpy(player[joueurPlaying].terrain5,"MARS");
                        player[joueurPlaying].t5Possede = 1;
                        break;
                    }

                    player[joueurPlaying].nbTerrain+=1;
                    player[joueurPlaying]. argent -= tabCartesPlanetes[5].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Mars");
                    tabCartesPlanetes[5].possede = 1;

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
                    switch (player[joueurPlaying].nbTerrain)
                    {
                    case 0:
                        strcpy(player[joueurPlaying].terrain1,"TRITON");
                        player[joueurPlaying].t1Possede = 1;
                        break;
                    case 1:
                        strcpy(player[joueurPlaying].terrain2,"TRITON");
                        player[joueurPlaying].t2Possede = 1;
                        break;
                    case 2:
                        strcpy(player[joueurPlaying].terrain3,"TRITON");
                        player[joueurPlaying].t3Possede = 1;
                        break;
                    case 3:
                        strcpy(player[joueurPlaying].terrain4,"TRITON");
                        player[joueurPlaying].t4Possede = 1;
                        break;
                    case 4:
                        strcpy(player[joueurPlaying].terrain5,"TRITON");
                        player[joueurPlaying].t5Possede = 1;
                        break;
                    }

                    player[joueurPlaying].nbTerrain+=1;
                    player[joueurPlaying]. argent -= tabCartesPlanetes[6].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Triton");

                    tabCartesPlanetes[6].possede = 1;

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
                    switch (player[joueurPlaying].nbTerrain)
                    {
                    case 0:
                        strcpy(player[joueurPlaying].terrain1,"NEPTUNE");
                        player[joueurPlaying].t1Possede = 1;
                        break;
                    case 1:
                        strcpy(player[joueurPlaying].terrain2,"NEPTUNE");
                        player[joueurPlaying].t2Possede = 1;
                        break;
                    case 2:
                        strcpy(player[joueurPlaying].terrain3,"NEPTUNE");
                        player[joueurPlaying].t3Possede = 1;
                        break;
                    case 3:
                        strcpy(player[joueurPlaying].terrain4,"NEPTUNE");
                        player[joueurPlaying].t4Possede = 1;
                        break;
                    case 4:
                        strcpy(player[joueurPlaying].terrain5,"NEPTUNE");
                        player[joueurPlaying].t5Possede = 1;
                        break;
                    }

                    player[joueurPlaying].nbTerrain+=1;
                    player[joueurPlaying]. argent -= tabCartesPlanetes[7].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Neptune");
                    tabCartesPlanetes[7].possede = 1;

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
                    switch (player[joueurPlaying].nbTerrain)
                    {
                    case 0:
                        strcpy(player[joueurPlaying].terrain1,"TITANIUM");
                        player[joueurPlaying].t1Possede = 1;
                        break;
                    case 1:
                        strcpy(player[joueurPlaying].terrain2,"TITANIUM");
                        player[joueurPlaying].t2Possede = 1;
                        break;
                    case 2:
                        strcpy(player[joueurPlaying].terrain3,"TITANIUM");
                        player[joueurPlaying].t3Possede = 1;
                        break;
                    case 3:
                        strcpy(player[joueurPlaying].terrain4,"TITANIUM");
                        player[joueurPlaying].t4Possede = 1;
                        break;
                    case 4:
                        strcpy(player[joueurPlaying].terrain5,"TITANIUM");
                        player[joueurPlaying].t5Possede = 1;
                        break;
                    }

                    player[joueurPlaying].nbTerrain+=1;
                    player[joueurPlaying]. argent -= tabCartesPlanetes[8].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Titania");

                    tabCartesPlanetes[8].possede = 1;

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
                    switch (player[joueurPlaying].nbTerrain)
                    {
                    case 0:
                        strcpy(player[joueurPlaying].terrain1,"URANUS");
                        player[joueurPlaying].t1Possede = 1;
                        break;
                    case 1:
                        strcpy(player[joueurPlaying].terrain2,"URANUS");
                        player[joueurPlaying].t2Possede = 1;
                        break;
                    case 2:
                        strcpy(player[joueurPlaying].terrain3,"URANUS");
                        player[joueurPlaying].t3Possede = 1;
                        break;
                    case 3:
                        strcpy(player[joueurPlaying].terrain4,"URANUS");
                        player[joueurPlaying].t4Possede = 1;
                        break;
                    case 4:
                        strcpy(player[joueurPlaying].terrain5,"URANUS");
                        player[joueurPlaying].t5Possede = 1;
                        break;
                    }

                    player[joueurPlaying].nbTerrain+=1;

                    player[joueurPlaying]. argent -= tabCartesPlanetes[9].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Uranus");

                    tabCartesPlanetes[9].possede = 1;

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
                    switch (player[joueurPlaying].nbTerrain)
                    {
                    case 0:
                        strcpy(player[joueurPlaying].terrain1,"TITAN");
                        player[joueurPlaying].t1Possede = 1;
                        break;
                    case 1:
                        strcpy(player[joueurPlaying].terrain2,"TITAN");
                        player[joueurPlaying].t2Possede = 1;
                        break;
                    case 2:
                        strcpy(player[joueurPlaying].terrain3,"TITAN");
                        player[joueurPlaying].t3Possede = 1;
                        break;
                    case 3:
                        strcpy(player[joueurPlaying].terrain4,"TITAN");
                        player[joueurPlaying].t4Possede = 1;
                        break;
                    case 4:
                        strcpy(player[joueurPlaying].terrain5,"TITAN");
                        player[joueurPlaying].t5Possede = 1;
                        break;
                    }

                    player[joueurPlaying].nbTerrain+=1;
                    player[joueurPlaying]. argent -= tabCartesPlanetes[10].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Titan");

                    tabCartesPlanetes[10].possede = 1;

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
                    switch (player[joueurPlaying].nbTerrain)
                    {
                    case 0:
                        strcpy(player[joueurPlaying].terrain1,"SATURNE");
                        player[joueurPlaying].t1Possede = 1;
                        break;
                    case 1:
                        strcpy(player[joueurPlaying].terrain2,"SATURNE");
                        player[joueurPlaying].t2Possede = 1;
                        break;
                    case 2:
                        strcpy(player[joueurPlaying].terrain3,"SATURNE");
                        player[joueurPlaying].t3Possede = 1;
                        break;
                    case 3:
                        strcpy(player[joueurPlaying].terrain4,"SATURNE");
                        player[joueurPlaying].t4Possede = 1;
                        break;
                    case 4:
                        strcpy(player[joueurPlaying].terrain5,"SATURNE");
                        player[joueurPlaying].t5Possede = 1;
                        break;
                    }

                    player[joueurPlaying].nbTerrain+=1;
                    player[joueurPlaying]. argent -= tabCartesPlanetes[11].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Saturne");
                    tabCartesPlanetes[11].possede = 1;

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
                    switch (player[joueurPlaying].nbTerrain)
                    {
                    case 0:
                        strcpy(player[joueurPlaying].terrain1,"EUROPE");
                        player[joueurPlaying].t1Possede = 1;
                        break;
                    case 1:
                        strcpy(player[joueurPlaying].terrain2,"EUROPE");
                        player[joueurPlaying].t2Possede = 1;
                        break;
                    case 2:
                        strcpy(player[joueurPlaying].terrain3,"EUROPE");
                        player[joueurPlaying].t3Possede = 1;
                        break;
                    case 3:
                        strcpy(player[joueurPlaying].terrain4,"EUROPE");
                        player[joueurPlaying].t4Possede = 1;
                        break;
                    case 4:
                        strcpy(player[joueurPlaying].terrain5,"EUROPE");
                        player[joueurPlaying].t5Possede = 1;
                        break;
                    }

                    player[joueurPlaying].nbTerrain+=1;

                    player[joueurPlaying]. argent -= tabCartesPlanetes[12].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Europe");

                    tabCartesPlanetes[12].possede = 1;

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
                    switch (player[joueurPlaying].nbTerrain)
                    {
                    case 0:
                        strcpy(player[joueurPlaying].terrain1,"GANYMEDE");
                        player[joueurPlaying].t1Possede = 1;
                        break;
                    case 1:
                        strcpy(player[joueurPlaying].terrain2,"GANYMEDE");
                        player[joueurPlaying].t2Possede = 1;
                        break;
                    case 2:
                        strcpy(player[joueurPlaying].terrain3,"GANYMEDE");
                        player[joueurPlaying].t3Possede = 1;
                        break;
                    case 3:
                        strcpy(player[joueurPlaying].terrain4,"GANYMEDE");
                        player[joueurPlaying].t4Possede = 1;
                        break;
                    case 4:
                        strcpy(player[joueurPlaying].terrain5,"GANYMEDE");
                        player[joueurPlaying].t5Possede = 1;
                        break;
                    }

                    player[joueurPlaying].nbTerrain+=1;
                    player[joueurPlaying]. argent -= tabCartesPlanetes[13].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Ganymede");

                    tabCartesPlanetes[13].possede = 1;

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
                    switch (player[joueurPlaying].nbTerrain)
                    {
                    case 0:
                        strcpy(player[joueurPlaying].terrain1,"JUPITER");
                        player[joueurPlaying].t1Possede = 1;
                        break;
                    case 1:
                        strcpy(player[joueurPlaying].terrain2,"JUPITER");
                        player[joueurPlaying].t2Possede = 1;
                        break;
                    case 2:
                        strcpy(player[joueurPlaying].terrain3,"JUPITER");
                        player[joueurPlaying].t3Possede = 1;
                        break;
                    case 3:
                        strcpy(player[joueurPlaying].terrain4,"JUPITER");
                        player[joueurPlaying].t4Possede = 1;
                        break;
                    case 4:
                        strcpy(player[joueurPlaying].terrain5,"JUPITER");
                        player[joueurPlaying].t5Possede = 1;
                        break;
                    }

                    player[joueurPlaying].nbTerrain+=1;
                    player[joueurPlaying]. argent -= tabCartesPlanetes[14].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Jupiter");

                    tabCartesPlanetes[14].possede = 1;

                }

            }
            else if(tabCartesPlanetes[14].possede == 1)
            {
                gotoligcol(45, 90);
                printf("Jupiter est déjà possede !");
            }

            break;
        case 28:
            break;

        }


        affichInfo(player,joueurPlaying);

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
