#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"header.h"

void hypotheque(Joueur j[], CartePlanete tabCartes[], int joueurPlaying, int planete,int nbMaisonTotal, int nbHotelTotal,int *pnbMaisonTotal, int *pnbHotelTotal)
{
    int v=0;
    int repVmaison=0;
    gotoligcol(47,90);
    printf("Voulez-vous hypothequer ? ");
    scanf("%d", &v);

    if(v==1)
    {
        if(tabCartes[planete].nbMaisons>0) ///si le joueur possède une ou plusieurs maisons
        {
            gotoligcol(48,90);
            printf("Pour hypothequer vous devez vendre toutes vos maisons a moitie prix");
            gotoligcol(49,90);
            printf("Souhaitez-vous vendre vos maisons ?");
            scanf("%d", &repVmaison);
            if(repVmaison == 1)
            {

                while(tabCartes[planete].nbMaisons > 0)
                {
                    *pnbMaisonTotal++;
                    j[joueurPlaying].argent += 35;
                    tabCartes[planete].nbMaisons --;
                }
                tabCartes[planete].hypoValid = 1;
                j[joueurPlaying].argent += tabCartes[planete].hypo;

            }

        }
        else if(tabCartes[joueurPlaying].nbMaisons==0) ///si le joueur ne possède aucune maison
        {
            j[joueurPlaying].argent += tabCartes[planete].hypo;
            tabCartes[planete].hypoValid = 1;
        }
        else
        {
            gotoligcol(49,90);
            printf("erreur");
        }
    }
}
void rachatHypo(Joueur j[], CartePlanete tabCartes[], int joueurPlaying, int planete,int nbMaisonTotal, int nbHotelTotal,int *pnbMaisonTotal, int *pnbHotelTotal)
{
    int repAchatHypo=0;
    gotoligcol(46,90);
    printf("Voulez-vous acheter votre hypotheque ? ");
    scanf("%d",&repAchatHypo);

    if(repAchatHypo == 1 && j[joueurPlaying].argent >= (tabCartes[planete].loyer+(tabCartes[planete].loyer*0.1)))
    {
        j[joueurPlaying].argent-= (tabCartes[planete].loyer + (tabCartes[planete].loyer*(0.1)));
        tabCartes[planete].hypoValid = 0;
        gotoligcol(47,90);
        printf("Vous avez bien racheter votre hypotheque");
    }

    else if(repAchatHypo == 1 && j[joueurPlaying].argent <= (tabCartes[planete].loyer+(tabCartes[planete].loyer*0.1)))
    {
        gotoligcol(47,90);
        printf("Vous n'avez pas assez d'argent !");
    }
    else if(repAchatHypo == 0)
    {
        gotoligcol(47,90);
        printf("D'accord vous n'allez pas racheter votre hypotheque.");
    }
}


void hypoSat(Joueur j[], Satellite sat[],int joueurPlaying, int satellite)
{

    int v = 0;
    gotoligcol(47,90);
    printf("Voulez vous hypothequer ce satellite ? ");
    scanf("%d",&v);
    if(v==1)
    {
        if(sat[satellite].hypoValid == 1)
        {
            gotoligcol(48,90);
            printf("vous ne pouvez pas hypothequer ce satellite car il l'est deja");

        }
        else if(sat[satellite].hypoValid == 0)
        {
            sat[satellite].hypoValid = 1;
            j[joueurPlaying].argent += sat[satellite].hypo;
            gotoligcol(48,90);
            printf("Le satellire a bien ete hypotheque.");
        }
    }else{
    gotoligcol(48,90);
    printf("Vous n'hypothequez pas ce satellite.");
    }

}



void rachatHypoSat(Joueur j[], Satellite sat[],int joueurPlaying, int satellite)
{

    int repAchatHypo = 0;
    gotoligcol(47,90);
    printf("Voulez-vous racheter votre hypothèque ?");
    scanf("%d", &repAchatHypo);

    if(repAchatHypo == 1 && j[joueurPlaying].argent >=(sat[satellite].loyer+(sat[satellite].loyer*0.1)))
    {
        sat[satellite].hypoValid = 0;
        j[joueurPlaying].argent-=(sat[satellite].loyer+(sat[satellite].loyer*0.1));
        gotoligcol(48,90);
        printf("Vous avez bien racheter votre hypotheque");
    }

    else if(repAchatHypo == 1 && j[joueurPlaying].argent <=(sat[satellite].loyer+(sat[satellite].loyer*0.1)))
    {
        gotoligcol(48,90);
        printf("Vous n'avez pas assez d'argent !");
    }
    else if(repAchatHypo == 0)
    {
        gotoligcol(48,90);
        printf("Vous ne rachetez pas votre hypotheque.");
    }
}


