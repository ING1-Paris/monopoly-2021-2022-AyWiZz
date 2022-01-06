#include <windows.h>
#define tailleCarre 6
#include <time.h>
#include"header.h"



void creationCartesChance(CarteChance tabCartes[])
{
    //CarteChance tabCartes[16];

    char var0et1[100] = "Vous recevez 100 euros de la part de tout les joueurs.";
    strcpy(tabCartes[0].nom, var0et1);
    strcpy(tabCartes[1].nom, var0et1);

    char var2et3[] = "Vous donnez 100 euros a tout les joueurs.";
    strcpy(tabCartes[2].nom, var2et3);
    strcpy(tabCartes[3].nom, var2et3);

    char var4et5[] = "Direction Prison !";
    strcpy(tabCartes[4].nom, var4et5);
    strcpy(tabCartes[5].nom, var4et5);

    char var6et7[] = "Votre vaisseau est en maintenance, veuillez payer 300 euros.";
    strcpy(tabCartes[6].nom, var6et7);
    strcpy(tabCartes[7].nom, var6et7);

    char var8et9[] = "Vous avez remporte le prix du plus beau vaisseau. Vous remportez 300 euros.";
    strcpy(tabCartes[8].nom, var8et9);
    strcpy(tabCartes[9].nom, var8et9);

    char var10et11[] = "Un signe de vie a ete decouvert sur Venus. Veuillez vous y rendre.";
    strcpy(tabCartes[10].nom, var10et11);
    strcpy(tabCartes[11].nom, var10et11);

    char var12et13[] = "Veuillez vous rendre a la case depart.";
    strcpy(tabCartes[12].nom, var12et13);
    strcpy(tabCartes[13].nom, var12et13);

    char var14et15[] = "Avancez de 6 cases.";
    strcpy(tabCartes[14].nom, var14et15);
    strcpy(tabCartes[15].nom, var14et15);
}




void creationContourCarteChanceCommunaute()
{
    gotoligcol(39, 65);
    printf("%c", 0xB3);

    gotoligcol(39, 145);
    printf("%c", 0xB3);

    int i = 0;
    int j = 0;
    int k = 9;
    int l = 9;
    int m = 24;
    gotoligcol(10,65);
    for(i = 0; i < 80; i++)
    {
        printf("%c", 0xC4);
    }
    gotoligcol(10,65);
    printf("%c", 0xDA);
    gotoligcol(10,145);
    printf("%c", 0xBF);
    gotoligcol(20,65);

    for(j = 0; j <4; j++)
    {
        for(i = 0; i < 7; i++)
        {
            gotoligcol((2+k),65);
            printf("%c", 0xB3);
            k = k+1;
        }

    }
    for(i = 0; i < 5; i++)
    {
        gotoligcol((2+m),65);
        printf("%c", 0xB3);
        m = m+1;
    }

    gotoligcol(40, 65);
    printf("%c", 0xC0);
    for(i = 0; i < 80; i++)
    {
        printf("%c", 0xC4);
    }
    gotoligcol(40, 145);
    printf("%c", 0xD9);

    gotoligcol(11, 145);
    for(j = 0; j < 4; j++)
    {
        for(i = 0; i < tailleCarre; i++)
        {
            gotoligcol((2+l),145);
            printf("%c", 0xB3);
            l = l+1;
        }

    }
    for(i = 0; i < 4; i++)
    {
        gotoligcol((2+l),145);
        printf("%c", 0xB3);
        l = l+1;
    }



}




void affichageCarteChance(int aleatoire, CarteChance tabCartes[])
{
    Color(9,0);
    gotoligcol(12,100);
    printf("CARTE CHANCE");
    if(aleatoire == 6 || aleatoire == 7 || aleatoire == 8 || aleatoire == 9 || aleatoire == 10 || aleatoire == 11)
    {
        gotoligcol(24, 75);
    }
    else if(aleatoire == 4 || aleatoire == 5  || aleatoire == 14 || aleatoire == 15)
    {
        gotoligcol(24, 95);
    }
    else
    {
        gotoligcol(24,85);
    }
    printf("%s", tabCartes[aleatoire]);
    gotoligcol(37, 103);
    printf("%d/16", aleatoire+1);
}


void creationCartesCommunautes(CarteChance tabCartes[])
{

    char com1[] = "Allez en prison sans passer par la case de départ.";
    strcpy(tabCartes[16].nom, com1);

    char com2[] = "Payer une amende de 30 euros ou tirer une carte chance.";
    strcpy(tabCartes[17].nom, com2);

    char com3[] = "Payer 40 euros par maison et 115 euros par hotel.";
    strcpy(tabCartes[18].nom, com3);

    char com4[] = "Rendez vous a ...";
    strcpy(tabCartes[19].nom, com4);

    char com5[] = "C'est votre anniversaire chaque joueur vous doit 10 euros.";
    strcpy(tabCartes[20].nom, com5);

    char com6[] = "Rendez vous a ...";
    strcpy(tabCartes[21].nom, com6);

    char com7[] = "Vous avez oublie de payer vos impots. Payez 100 euros.";
    strcpy(tabCartes[22].nom, com7);

    char com8[] = "Votre vaisseau est en maintenance, veuillez payer 300 euros.";
    strcpy(tabCartes[23].nom, com8);

    char com9[] = "Un signe de vie a ete decouvert sur Venus. Veuillez vous y rendre.";
    strcpy(tabCartes[24].nom, com9);

    char com10[] = "Veuillez vous rendre a la case depart.";
    strcpy(tabCartes[25].nom, com10);

    char com11[] = "Reculer de cinq cases.";
    strcpy(tabCartes[26].nom, com11);

    char com12[] = "Vous etes elu astronaute de l'annee. Vous recevez 50 euros.";
    strcpy(tabCartes[27].nom, com12);

    char com13[] = "Allez en prison sans passer par la case de départ";
    strcpy(tabCartes[28].nom, com13);

    char com14[] = "Vous avez ete capture. Payez 150 euros de rancon.";
    strcpy(tabCartes[29].nom, com14);

    char com15[] = "Sortie de Prison.";
    strcpy(tabCartes[30].nom, com15);

    char com16[] = "Vous donnez 30 euros a tout les joueurs.";
    strcpy(tabCartes[31].nom, com16);

}

void affichageCarteCommunautes(int aleatoire, CarteChance tabCartes[])
{
    Color(9,0);
    gotoligcol(12,100);
    printf("CARTE COMMUNAUTES");
    if(aleatoire == 21 || aleatoire == 25)
    {
        gotoligcol(24, 70);
    }
    else if(aleatoire == 31)
    {
        gotoligcol(24, 95);
    }
    else
    {
        gotoligcol(24,75);
    }
    printf("%s", tabCartes[aleatoire].nom);
    gotoligcol(39, 103);
    printf("%d/16", aleatoire);
}


int generationAleatoireChance()
{
    srand(time(NULL));
    int aleatoire = 0;
    aleatoire = rand() % 16;
    return (aleatoire);
}

int generationAleatoireCommu()
{
    srand(time(NULL));
    int aleatoire = 0;
    aleatoire = (rand() % (32 - 16 + 1)) + 16;
    return (aleatoire);
}
