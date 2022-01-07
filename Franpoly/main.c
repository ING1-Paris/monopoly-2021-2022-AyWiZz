#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"
#include <unistd.h>


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
        player[i].prison = 0;
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


    ////////////////////////////////////////////////////////////////////
    ///Boucle Principale///
    ///////////////////////////////////////////////////////////////////

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

        affichInfo(player,joueurPlaying);


        if(player[joueurPlaying].choix == 1)
        {
            gotoligcol(5, 195);
            printf("D'accord");
            player[joueurPlaying].choix = 0;

            if(player[joueurPlaying].prison != 1)
            {


            des(nbDe,pnbDe);
            player[joueurPlaying].lastposition = player[joueurPlaying].position;
            player[joueurPlaying].position = player[joueurPlaying].lastposition + nbDe;

            }


            for(int i = 0; i <= nbJoueurs; i++)
            {
                affichPion(player, i);
            }

            gotoligcol(6, 195);

            ///////////////////////////// Pour prison///////////////////////

            if(player[joueurPlaying].position == 21) // Pour l'affichage si il est dans la prison alors on raffiche tout
            {

                gotoligcol(16, 195);
                printf("Vous allez en prison !!!!!!!!");
                sleep(3);

                player[joueurPlaying].position = 7;
                player[joueurPlaying].prison = 1;

                system("cls");
                couleursPlateau();
                creationPlateau();

                for(int i = 0; i <= nbJoueurs; i++)
                {
                    affichPion(player, i);

                }
                affichInfo(player,joueurPlaying);
                gotoligcol(16, 195);
                printf("Vous avez atteri en prison !");
            }

            if(player[joueurPlaying].prison == 1)
            {
                player[joueurPlaying].position = 7;
            }

            //////////////////////////////////////////////////////

        }



        printf("Tu va vers l'avant de %d cases position %d! ", nbDe, player[joueurPlaying].position);
        nbDe = 0;





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
                    //////////////// NOUVELES MODIF ACHAT /////////////////////////////
                    //strcpy(tabCartesPlanetes[0].possession, player[joueurPlaying].nom);

                    tabCartesPlanetes[0].possession = joueurPlaying;


                    gotoligcol(48,90);

                    printf("%d", tabCartesPlanetes[0].possession);
                    ///////////////////////////////////////////////////////////////:

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Mercure");

                    gotoligcol(47, 90);
                    tabCartesPlanetes[0].possede = 1;





                }

            }
            else if(tabCartesPlanetes[0].possede == 1 && tabCartesPlanetes[0].possession == joueurPlaying)
            {
                gotoligcol(45, 90);
                printf("Voulez vous acheter des maisons ?");
            }
            else if(tabCartesPlanetes[0].possede == 1 && tabCartesPlanetes[0].possession != joueurPlaying)// LE TERRAIN N'EST PAS AU JOUEUR PLAYING
            {

                player[joueurPlaying].argent -= tabCartesPlanetes[0].loyer; // LE JOUEUR PAYE LE LOYER
                player[tabCartesPlanetes[0].possession].argent += tabCartesPlanetes[0].loyer;

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

                    //////////////// NOUVELES MODIF ACHAT /////////////////////////////
                    tabCartesPlanetes[1].possession = joueurPlaying;


                    player[joueurPlaying].argent -= tabCartesPlanetes[1].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Venus");
                    tabCartesPlanetes[1].possede = 1;

                }

            }
            else if(tabCartesPlanetes[1].possede == 1 && tabCartesPlanetes[1].possession == joueurPlaying)//PERMET DE SAVOIR SI C'EST AU JOUEUR QUI EST EN TRAIN DE JOUER)
            {
                gotoligcol(45, 90);
                printf("Venus est déjà possede !");
            }
            else if(tabCartesPlanetes[1].possede == 1 && tabCartesPlanetes[1].possession != joueurPlaying)// LE TERRAIN N'EST PAS AU JOUEUR PLAYING
            {

                player[joueurPlaying].argent -= tabCartesPlanetes[1].loyer; // LE JOUEUR PAYE LE LOYER
                player[tabCartesPlanetes[1].possession].argent += tabCartesPlanetes[1].loyer;

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
                    //////////////// NOUVELES MODIF ACHAT /////////////////////////////
                    tabCartesPlanetes[2].possession = joueurPlaying;


                    player[joueurPlaying].argent -= tabCartesPlanetes[2].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Lune");
                    tabCartesPlanetes[2].possede = 1;

                }

            }
            else if(tabCartesPlanetes[2].possede == 1 && tabCartesPlanetes[2].possession == joueurPlaying)
            {
                gotoligcol(45, 90);
                printf("Lune est déjà possede !");
            }
            else if(tabCartesPlanetes[2].possede == 1 && tabCartesPlanetes[2].possession != joueurPlaying)// LE TERRAIN N'EST PAS AU JOUEUR PLAYING
            {

                player[joueurPlaying].argent -= tabCartesPlanetes[2].loyer; // LE JOUEUR PAYE LE LOYER
                player[tabCartesPlanetes[2].possession].argent += tabCartesPlanetes[2].loyer;

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
                    //////////////// NOUVELES MODIF ACHAT /////////////////////////////
                    tabCartesPlanetes[3].possession = joueurPlaying;



                    player[joueurPlaying].argent -= tabCartesPlanetes[3].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter la Terre");
                    tabCartesPlanetes[3].possede=1;

                    gotoligcol(47, 90);
                    /*printf(" Vous avez %d $", player[joueurPlaying]. argent);
                    gotoligcol(47, 90);
                    printf("%s", player[joueurPlaying].terrain1);*/

                }

            }
            else if(tabCartesPlanetes[3].possede == 1 && tabCartesPlanetes[3].possession == joueurPlaying)
            {
                gotoligcol(45, 90);
                printf("La Terre est déjà possede !");
            }
            else if(tabCartesPlanetes[3].possede == 1 && tabCartesPlanetes[3].possession != joueurPlaying)// LE TERRAIN N'EST PAS AU JOUEUR PLAYING
            {

                player[joueurPlaying].argent -= tabCartesPlanetes[3].loyer; // LE JOUEUR PAYE LE LOYER
                player[tabCartesPlanetes[3].possession].argent += tabCartesPlanetes[3].loyer;

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

                    //////////////// NOUVELES MODIF ACHAT /////////////////////////////
                    tabCartesPlanetes[4].possession = joueurPlaying;


                    player[joueurPlaying]. argent -= tabCartesPlanetes[4].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Phobos");
                    tabCartesPlanetes[4].possede = 1;

                }

            }
            else if(tabCartesPlanetes[4].possede == 1 && tabCartesPlanetes[4].possession == joueurPlaying)
            {
                gotoligcol(45, 90);
                printf("Phobos est déjà possede !");
            }
            else if(tabCartesPlanetes[4].possede == 1 && tabCartesPlanetes[4].possession != joueurPlaying)// LE TERRAIN N'EST PAS AU JOUEUR PLAYING
            {

                player[joueurPlaying].argent -= tabCartesPlanetes[4].loyer; // LE JOUEUR PAYE LE LOYER
                player[tabCartesPlanetes[4].possession].argent += tabCartesPlanetes[4].loyer;

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
                    //////////////// NOUVELES MODIF ACHAT /////////////////////////////
                    tabCartesPlanetes[5].possession = joueurPlaying; //DIT QUE LE TERRAIN EST POSSEDE PAR LE NOM DU JOUEUR EN TRAIN DE JOUER

                    player[joueurPlaying]. argent -= tabCartesPlanetes[5].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Mars");
                    tabCartesPlanetes[5].possede = 1;

                }

            }
            else if(tabCartesPlanetes[5].possede == 1 && tabCartesPlanetes[5].possession == joueurPlaying)
            {
                gotoligcol(45, 90);
                printf("Mars est déjà possede !");
            }
            else if(tabCartesPlanetes[5].possede == 1 && tabCartesPlanetes[5].possession != joueurPlaying)// LE TERRAIN N'EST PAS AU JOUEUR PLAYING
            {

                player[joueurPlaying].argent -= tabCartesPlanetes[5].loyer; // LE JOUEUR PAYE LE LOYER
                player[tabCartesPlanetes[5].possession].argent += tabCartesPlanetes[5].loyer;

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

                    //////////////// NOUVELES MODIF ACHAT /////////////////////////////
                    tabCartesPlanetes[6].possession = joueurPlaying; //DIT QUE LE TERRAIN EST POSSEDE PAR LE NOM DU JOUEUR EN TRAIN DE JOUER

                    player[joueurPlaying]. argent -= tabCartesPlanetes[6].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Triton");

                    tabCartesPlanetes[6].possede = 1;

                }

            }
            else if(tabCartesPlanetes[6].possede == 1 && tabCartesPlanetes[6].possession == joueurPlaying)
            {
                gotoligcol(45, 90);
                printf("Triton est déjà possede !");
            }
            else if(tabCartesPlanetes[6].possede == 1 && tabCartesPlanetes[6].possession != joueurPlaying)// LE TERRAIN N'EST PAS AU JOUEUR PLAYING
            {

                player[joueurPlaying].argent -= tabCartesPlanetes[6].loyer; // LE JOUEUR PAYE LE LOYER
                player[tabCartesPlanetes[6].possession].argent += tabCartesPlanetes[6].loyer;

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

                    //////////////// NOUVELES MODIF ACHAT /////////////////////////////
                    tabCartesPlanetes[7].possession = joueurPlaying; //DIT QUE LE TERRAIN EST POSSEDE PAR LE NOM DU JOUEUR EN TRAIN DE JOUER

                    player[joueurPlaying]. argent -= tabCartesPlanetes[7].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Neptune");
                    tabCartesPlanetes[7].possede = 1;

                }

            }
            else if(tabCartesPlanetes[7].possede == 1 && tabCartesPlanetes[7].possession == joueurPlaying)
            {
                gotoligcol(45, 90);
                printf("Neptune est déjà possede !");
            }
            else if(tabCartesPlanetes[7].possede == 1 && tabCartesPlanetes[7].possession != joueurPlaying)// LE TERRAIN N'EST PAS AU JOUEUR PLAYING
            {

                player[joueurPlaying].argent -= tabCartesPlanetes[7].loyer; // LE JOUEUR PAYE LE LOYER
                player[tabCartesPlanetes[7].possession].argent += tabCartesPlanetes[7].loyer;

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

                    //////////////// NOUVELES MODIF ACHAT /////////////////////////////
                    tabCartesPlanetes[8].possession = joueurPlaying; //DIT QUE LE TERRAIN EST POSSEDE PAR LE NOM DU JOUEUR EN TRAIN DE JOUER

                    player[joueurPlaying]. argent -= tabCartesPlanetes[8].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Titania");

                    tabCartesPlanetes[8].possede = 1;

                }

            }
            else if(tabCartesPlanetes[8].possede == 1 && tabCartesPlanetes[8].possession == joueurPlaying)
            {
                gotoligcol(45, 90);
                printf("Titanium est déjà possede !");
            }
            else if(tabCartesPlanetes[8].possede == 1 && tabCartesPlanetes[8].possession != joueurPlaying)// LE TERRAIN N'EST PAS AU JOUEUR PLAYING
            {

                player[joueurPlaying].argent -= tabCartesPlanetes[8].loyer; // LE JOUEUR PAYE LE LOYER
                player[tabCartesPlanetes[8].possession].argent += tabCartesPlanetes[8].loyer;

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

                    //////////////// NOUVELES MODIF ACHAT /////////////////////////////
                    tabCartesPlanetes[9].possession = joueurPlaying; //DIT QUE LE TERRAIN EST POSSEDE PAR LE NOM DU JOUEUR EN TRAIN DE JOUER

                    player[joueurPlaying]. argent -= tabCartesPlanetes[9].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Uranus");

                    tabCartesPlanetes[9].possede = 1;

                }

            }
            else if(tabCartesPlanetes[9].possede == 1 && tabCartesPlanetes[9].possession == joueurPlaying)
            {
                gotoligcol(45, 90);
                printf("Uranus est déjà possede !");
            }
            else if(tabCartesPlanetes[9].possede == 1 && tabCartesPlanetes[9].possession != joueurPlaying)// LE TERRAIN N'EST PAS AU JOUEUR PLAYING
            {

                player[joueurPlaying].argent -= tabCartesPlanetes[9].loyer; // LE JOUEUR PAYE LE LOYER
                player[tabCartesPlanetes[9].possession].argent += tabCartesPlanetes[9].loyer;

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

                    //////////////// NOUVELES MODIF ACHAT /////////////////////////////
                    tabCartesPlanetes[10].possession = joueurPlaying; //DIT QUE LE TERRAIN EST POSSEDE PAR LE NOM DU JOUEUR EN TRAIN DE JOUER

                    player[joueurPlaying]. argent -= tabCartesPlanetes[10].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Titan");

                    tabCartesPlanetes[10].possede = 1;

                }

            }
            else if(tabCartesPlanetes[10].possede == 1 && tabCartesPlanetes[10].possession == joueurPlaying)
            {
                gotoligcol(45, 90);
                printf("Titan est déjà possede !");
            }
            else if(tabCartesPlanetes[10].possede == 1 && tabCartesPlanetes[10].possession != joueurPlaying)// LE TERRAIN N'EST PAS AU JOUEUR PLAYING
            {

                player[joueurPlaying].argent -= tabCartesPlanetes[10].loyer; // LE JOUEUR PAYE LE LOYER
                player[tabCartesPlanetes[10].possession].argent += tabCartesPlanetes[10].loyer;

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

                    //////////////// NOUVELES MODIF ACHAT /////////////////////////////
                    tabCartesPlanetes[11].possession = joueurPlaying; //DIT QUE LE TERRAIN EST POSSEDE PAR LE NOM DU JOUEUR EN TRAIN DE JOUER

                    player[joueurPlaying]. argent -= tabCartesPlanetes[11].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Saturne");
                    tabCartesPlanetes[11].possede = 1;

                }

            }
            else if(tabCartesPlanetes[11].possede == 1 && tabCartesPlanetes[11].possession == joueurPlaying)
            {
                gotoligcol(45, 90);
                printf("Saturne est déjà possede !");
            }
            else if(tabCartesPlanetes[11].possede == 1 && tabCartesPlanetes[11].possession != joueurPlaying)// LE TERRAIN N'EST PAS AU JOUEUR PLAYING
            {

                player[joueurPlaying].argent -= tabCartesPlanetes[11].loyer; // LE JOUEUR PAYE LE LOYER
                player[tabCartesPlanetes[11].possession].argent += tabCartesPlanetes[11].loyer;

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

                    //////////////// NOUVELES MODIF ACHAT /////////////////////////////
                    tabCartesPlanetes[12].possession = joueurPlaying;//DIT QUE LE TERRAIN EST POSSEDE PAR LE NOM DU JOUEUR EN TRAIN DE JOUER

                    player[joueurPlaying]. argent -= tabCartesPlanetes[12].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Europe");

                    tabCartesPlanetes[12].possede = 1;

                }

            }
            else if(tabCartesPlanetes[12].possede == 1 && tabCartesPlanetes[12].possession == joueurPlaying)
            {
                gotoligcol(45, 90);
                printf("Europe est déjà possede !");
            }
            else if(tabCartesPlanetes[12].possede == 1 && tabCartesPlanetes[12].possession != joueurPlaying)// LE TERRAIN N'EST PAS AU JOUEUR PLAYING
            {

                player[joueurPlaying].argent -= tabCartesPlanetes[12].loyer; // LE JOUEUR PAYE LE LOYER
                player[tabCartesPlanetes[12].possession].argent += tabCartesPlanetes[12].loyer;

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

                    //////////////// NOUVELES MODIF ACHAT /////////////////////////////
                    tabCartesPlanetes[13].possession = joueurPlaying; //DIT QUE LE TERRAIN EST POSSEDE PAR LE NOM DU JOUEUR EN TRAIN DE JOUER

                    player[joueurPlaying]. argent -= tabCartesPlanetes[13].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Ganymede");

                    tabCartesPlanetes[13].possede = 1;

                }

            }
            else if(tabCartesPlanetes[13].possede == 1 && tabCartesPlanetes[13].possession == joueurPlaying)
            {
                gotoligcol(45, 90);
                printf("Ganymede est déjà possede !");
            }
            else if(tabCartesPlanetes[13].possede == 1 && tabCartesPlanetes[13].possession != joueurPlaying)// LE TERRAIN N'EST PAS AU JOUEUR PLAYING
            {

                player[joueurPlaying].argent -= tabCartesPlanetes[13].loyer; // LE JOUEUR PAYE LE LOYER
                player[tabCartesPlanetes[13].possession].argent += tabCartesPlanetes[13].loyer;

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

                    //////////////// NOUVELES MODIF ACHAT /////////////////////////////
                    tabCartesPlanetes[14].possession = joueurPlaying; //DIT QUE LE TERRAIN EST POSSEDE PAR LE NOM DU JOUEUR EN TRAIN DE JOUER

                    player[joueurPlaying]. argent -= tabCartesPlanetes[14].loyer;

                    gotoligcol(46, 90);
                    printf("Vous venez d'acheter Jupiter");

                    tabCartesPlanetes[14].possede = 1;

                }

            }
            else if(tabCartesPlanetes[14].possede == 1 && tabCartesPlanetes[14].possession == joueurPlaying)
            {
                gotoligcol(45, 90);
                printf("Jupiter est déjà possede !");
            }
            else if(tabCartesPlanetes[14].possede == 1 && tabCartesPlanetes[14].possession != joueurPlaying)// LE TERRAIN N'EST PAS AU JOUEUR PLAYING
            {

                player[joueurPlaying].argent -= tabCartesPlanetes[14].loyer; // LE JOUEUR PAYE LE LOYER
                player[tabCartesPlanetes[14].possession].argent += tabCartesPlanetes[14].loyer;

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
