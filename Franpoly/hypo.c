#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"header.h"

/*  ENTREE : TABLEAU DE STRUCTURE JOUEUR, TABLEAU DE STRUCTURE CARTEPLANETE, JOUEURPLAYING, LE NUMÉRO DE LA PLANÈTE, NOMBRE DE MAISON TOTAL AINSI QUE SON POINTEUR, NOMBRE DE MAISON TOTAL AINSI QUE SON POINTEUR
    SORTIE : AUCUNE
    BUT DE LA FONCTION : PERMET DE SAVOIR SI LE JOUEUR VEUT HYPOTHEQUER ET PERMET DE LE FAIRE
*/
void hypotheque(Joueur j[], CartePlanete tabCartes[], int joueurPlaying, int planete,int nbMaisonTotal, int nbHotelTotal,int *pnbMaisonTotal, int *pnbHotelTotal)
{
    ////////////////////////////////// INITIALISATION DES VARIABLES //////////////////////
    int v=0;
    int repVmaison=0;
    /////////////////////////////////////////////////////////////////////////////////////
    gotoligcol(47,90);
    printf("Voulez-vous hypothequer ? ");
    scanf("%d", &v);

    if(v==1) //SI LE JOUEUR VEUT HYPOTHÉQUER
    {
        if(tabCartes[planete].nbMaisons>0) ///SI LE JOUEUR POSSÈDE UNE OU PLUSIEURS MAISONS
        {
            gotoligcol(48,90);
            printf("Pour hypothequer vous devez vendre toutes vos maisons a moitie prix");
            gotoligcol(49,90);
            printf("Souhaitez-vous vendre vos maisons ?");
            scanf("%d", &repVmaison);
            if(repVmaison == 1) //SI LE JOUEUR VEUT VENDRE TOUTES CES MAISONS
            {

                while(tabCartes[planete].nbMaisons > 0) //TANT QUE LE NOMBRE DE MAISONS N'EST PAS ÉGAL À 0
                {
                    *pnbMaisonTotal++; //LE NOMBRE DE MAISON ENCORE DISPONIBLE À L'ACHAT AUGMENTE DE 1 À CHAQUE TOUR DE BOUCLE
                    j[joueurPlaying].argent += 35; //L'ARGENT DU JOUEUR AUGMENTE DE 35 (MOITIÉ DU PRIX D'UNE MAISON)
                    tabCartes[planete].nbMaisons --; //LE NOMBRE DE MAISON SUR LA PLANÈTE À DIMINUÉ DE 1 À CHAQUE TOUR DE BOUCLE
                }
                tabCartes[planete].hypoValid = 1; //LA PLANÈTE EST BIEN HYPOTHÉQUÉ
                j[joueurPlaying].argent += tabCartes[planete].hypo; //LE JOUEUR RÉCUPÈRE LE PRIX DE L'HYPOTHÈQUE

            }

        }
        else if(tabCartes[joueurPlaying].nbMaisons==0) ///SI LE JOUEUR NE POSSÈDE AUCUNE MAISON
        {
            j[joueurPlaying].argent += tabCartes[planete].hypo; //LE JOUEUR RÉCUPÈRE LE PRIX DE L'HYPOTHÈQUE
            tabCartes[planete].hypoValid = 1; //LA PLANÈTE EST BIEN HYPOTHÉQUÉ
        }
        else
        {
            gotoligcol(49,90);
            printf("erreur"); //AFFICHE UNE ERREUR
        }
    }
}
/*  ENTREE : TABLEAU DE STRUCTURE JOUEUR, TABLEAU DE STRUCTURE CARTEPLANETE, JOUEURPLAYING, LE NUMÉRO DE LA PLANÈTE, NOMBRE DE MAISON TOTAL AINSI QUE SON POINTEUR, NOMBRE DE MAISON TOTAL AINSI QUE SON POINTEUR
    SORTIE : AUCUNE
    BUT DE LA FONCTION : PERMET DE SAVOIR SI LE JOUEUR VEUT RACHETER SON HYPOTHÈQUE ET PERMET DE LE FAIRE
*/
void rachatHypo(Joueur j[], CartePlanete tabCartes[], int joueurPlaying, int planete,int nbMaisonTotal, int nbHotelTotal,int *pnbMaisonTotal, int *pnbHotelTotal)
{
    ////////////////////////// INITIALISATION DE LA VARIABLE /////////////////////
    int repAchatHypo=0;
    /////////////////////////////////////////////////////////////////////////////
    gotoligcol(46,90);
    printf("Voulez-vous acheter votre hypotheque ? ");
    scanf("%d",&repAchatHypo);

    if(repAchatHypo == 1 && j[joueurPlaying].argent >= (tabCartes[planete].loyer+(tabCartes[planete].loyer*0.1))) //SI LE JOEUR VEUT RACHETER SON HYPOTHÈQUE ET QU'IL A ASSEZ D'ARGENT POUUR LE FAIRE
    {
        j[joueurPlaying].argent-= (tabCartes[planete].loyer + (tabCartes[planete].loyer*(0.1))); //LE JOUEUR PAYE LE PRIX DU LOYER AVEC DES INTÉRETS DE 10 %
        tabCartes[planete].hypoValid = 0; //DIT QUE LA PLANÈTE N'EST PLUS HYPOTHÉQUÉ
        gotoligcol(47,90);
        printf("Vous avez bien racheter votre hypotheque");
    }

    else if(repAchatHypo == 1 && j[joueurPlaying].argent <= (tabCartes[planete].loyer+(tabCartes[planete].loyer*0.1))) //SI LE JOUEUR VEUT RACHETER SON HYPOTHÈQUE MAIS QU'IL N'A PAS ASSEZ D'ARGENT
    {
        gotoligcol(47,90);
        printf("Vous n'avez pas assez d'argent !");
    }
    else if(repAchatHypo == 0) //SI LE JOUEUR NE VEUT PAS RACHETER SON HYPOTHÈQUE
    {
        gotoligcol(47,90);
        printf("D'accord vous n'allez pas racheter votre hypotheque.");
    }
}

/*  ENTREE : TABLEAU DE STRUCTURE JOUEUR, TABLEAU DE STRUCTURE SAT, JOUEUR PLAYING, LE NUMERO DU SATELITE CORRESPONDANT
    SORTIE : AUCUNE
    BUT DE LA FONCTION : HYPOTHÉQUER UN SATELLITE
*/
void hypoSat(Joueur j[], Satellite sat[],int joueurPlaying, int satellite)
{

    int v = 0;
    gotoligcol(47,90);
    printf("Voulez vous hypothequer ce satellite ? ");
    scanf("%d",&v);
    if(v==1) //SI LE JOUEUR VEUT HYPOTHÉQUER LE SATELLITE
    {
        if(sat[satellite].hypoValid == 1) //SI LE SATELLITE EST DÉJÀ HYPOTHÉQUER
        {
            gotoligcol(48,90);
            printf("vous ne pouvez pas hypothequer ce satellite car il l'est deja");

        }
        else if(sat[satellite].hypoValid == 0) //SI LE SATELLITE N'EST PAS ENCORE HYPOTHÉQUER
        {
            sat[satellite].hypoValid = 1; //LE SATELLITE EST HYPOTHÉQUER
            j[joueurPlaying].argent += sat[satellite].hypo; //LE JOUEUR RÉCUPÈRE LE MONTANT DE L'HYPOTHÈQUE
            gotoligcol(48,90);
            printf("Le satellire a bien ete hypotheque.");
        }
    }else{ //SINON
    gotoligcol(48,90);
    printf("Vous n'hypothequez pas ce satellite.");
    }

}


/*  ENTREE : TABLEAU DE STRUCTURE JOUEUR, TABLEAU DE STRUCTURE SATELLITES, JOUEURPLAYING, LE NUMÉRO DU SATELLITE
    SORTIE : AUCUNE
    BUT DE LA FONCTION : RACHETER L'HYPOTHÈQUE DU SATELLITE
*/
void rachatHypoSat(Joueur j[], Satellite sat[],int joueurPlaying, int satellite)
{

    int repAchatHypo = 0;
    gotoligcol(47,90);
    printf("Voulez-vous racheter votre hypotheque ?");
    scanf("%d", &repAchatHypo);

    if(repAchatHypo == 1 && j[joueurPlaying].argent >=(sat[satellite].loyer+(sat[satellite].loyer*0.1))) //SI LE JOEUR VEUT RACHETER SON HYPOTHÈQUE ET QU'IL ASSEZ D'ARGENT POUR LE FAIRE
    {
        sat[satellite].hypoValid = 0; //ON RETIRE L'HYPOTHÈQUE
        j[joueurPlaying].argent-=(sat[satellite].loyer+(sat[satellite].loyer*0.1)); //LE JOUEUR PAYE LE PRIX DU LOYER AINSI QUE DES INTÉRÊTS DE 10%
        gotoligcol(48,90);
        printf("Vous avez bien racheter votre hypotheque");
    }

    else if(repAchatHypo == 1 && j[joueurPlaying].argent <=(sat[satellite].loyer+(sat[satellite].loyer*0.1))) //SI LE JOUEUR VEUT RACHETER SON HYPOTHÈQUE MAIS QU'IL N'A PAS ASSEZ D'ARGENT POUR LE FAIRE
    {
        gotoligcol(48,90);
        printf("Vous n'avez pas assez d'argent !");
    }
    else if(repAchatHypo == 0) //SI LE JOUEUR NE VEUT PAS RACHETER SON HYPOTHÈQUE
    {
        gotoligcol(48,90);
        printf("Vous ne rachetez pas votre hypotheque.");
    }
}


