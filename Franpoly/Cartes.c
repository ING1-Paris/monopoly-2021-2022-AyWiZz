#include <windows.h>
#define tailleCarre 6
#include <time.h>
#include"header.h"
#include <stdio.h>


/*
    ENTREE : TABLEAU DE STRUCTURES CARTECHANCE
    SORTIE : AUCUNE
    BUT DU SOUS PROGRAMME : CREATION DE TOUTES LES CARTES CHANCES
*/
void creationCartesChance(CarteChance tabCartes[])
{
    //////////////////// MEME PROCESSUS POUR TOUTES LES CARTES ///////
    //////////////////// JE COMMMENTE DONC QUE LE PREMIER ////////////

    char var0et1[100] = "Vous recevez 100 euros de la part de tout les joueurs."; //CETTE VARIABLE PREMETTRA DE
    strcpy(tabCartes[0].nom, var0et1); // LE VAR 0 ET 1 SERA AFFECTE DANS tabCartes[0].nom
    strcpy(tabCartes[1].nom, var0et1); // // LE VAR 0 ET 1 SERA AFFECTE DANS tabCartes[1].nom
    // LA CARTE CHANCE 0 ET 1 EST INITIALISE AVEC VAR 0 ET 1

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



/*  ENTREE : AUCUNE
    SORTIE : AUCUNE
    BUT DE LA FONCTION : CREER LE CONTOUR DES CARTES CHANCES ET COMMUNAUTES
*/
void creationContourCarteChanceCommunaute()
{
    gotoligcol(39, 65);
    printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE

    gotoligcol(39, 145);
    printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE
//////////////// INITIALISATION DES VARIABLES ///////
    int i = 0;
    int j = 0;
    int k = 9;
    int l = 9;
    int m = 24;
////////////////////////////////////////////////////
    gotoligcol(10,65);
    ///// PERMET DE CREER LA GRANDE BARRE HORIZONTALE EN HAUT /////
    for(i = 0; i < 80; i++)
    {
        printf("%c", 0xC4); //AFFICHE DES BARRES HORIZONTALES
    }
    gotoligcol(10,65);
    printf("%c", 0xDA); //AFFICHE L'ANGLE EN HAUT A GAUCHE
    gotoligcol(10,145);
    printf("%c", 0xBF); //AFFICHE L'ANGLE EN HAUT A DROITE
    gotoligcol(20,65);
////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////// AFFICHE LA GRANDE BARRE VERTICALE A GAUCHE //////
    for(j = 0; j <4; j++)
    {
        for(i = 0; i < 7; i++)
        {
            gotoligcol((2+k),65); //A CHAQUE TOUR DE BOUCLE ON VA A LA LIGNE EN DESSOUS
            printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE
            k = k+1; //k EST INCREMENTE DE 1
        }

    }
    for(i = 0; i < 5; i++)
    {
        gotoligcol((2+m),65);  //A CHAQUE TOUR DE BOUCLE ON VA A LA LIGNE EN DESSOUS
        printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE
        m = m+1; //m EST INCREMENTE DE 1
    }

    gotoligcol(40, 65);
    printf("%c", 0xC0); //AFFICHE L'ANGLE EN BAS A GAUCHE
////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////// AFFICHE LA GRANDE BARRE HORIZONTALE EN BAS /////////////
    for(i = 0; i < 80; i++)
    {
        printf("%c", 0xC4); //AFFICHE UNE BARRE HORIZONTALE
    }
    gotoligcol(40, 145);
    printf("%c", 0xD9); //AFFICHE L'ANGLE EN BAS A DROITE
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
////////// AFFICHE LA GRANDE BARRE VERTICALE A DROITE ////////
    gotoligcol(11, 145);
    for(j = 0; j < 4; j++)
    {
        for(i = 0; i < tailleCarre; i++)
        {
            gotoligcol((2+l),145);//A CHAQUE TOUR DE BOUCLE ON VA A LA LIGNE EN DESSOUS
            printf("%c", 0xB3); //AFFICHE UNE BARRE VERTICALE
            l = l+1; //l EST INCREMENTE DE 1
        }

    }
    for(i = 0; i < 4; i++)
    {
        gotoligcol((2+l),145);//A CHAQUE TOUR DE BOUCLE ON VA A LA LIGNE EN DESSOUS
        printf("%c", 0xB3);//AFFICHE UNE BARRE VERTICALE
        l = l+1; //l EST INCREMENTE DE 1
    }
/////////////////////////////////////////////////////////////


}



/*  ENTREE : INT ALEATOIRE ET TABLEAUX DE STRUCTURES CARTECHANCE
    SORTIE : AUCUNE
    BUT DE LA FONCTION : AFFICHER A L'ECRAN LE CONTENU D'UNE CARTE CHANCE
*/
void affichageCarteChance(int aleatoire, CarteChance tabCartes[])
{
    Color(9,0); //BLEU
    gotoligcol(12,100);
    printf("CARTE CHANCE");
    // ON REGLE L4AFFICHAGE SELON LA LONGUEUR DE LA CARTE CHANCE ////
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
    //////////////////////////////////////////////////////////////
    printf("%s", tabCartes[aleatoire].nom); //ON AFFICHE LE CONTENU DE LA CARTE CHANCE
    gotoligcol(37, 103);
    printf("%d/16", aleatoire+1); //ON AFFICHE LE NOMBRE DE LA CARTE ALEATOIRE
}

/*  ENTREE : TABLEAUX DE STRUCTURE CARTECHANCE
    SORTIE : AUCUNE
    BUT DE LA FONCTION : CREER TOUTES LES CARTES COMMUNAUTES
*/
void creationCartesCommunautes(CarteChance tabCartes[])
{
    //////////////////// MEME PROCESSUS POUR TOUTES LES CARTES ///////
    //////////////////// JE COMMMENTE DONC QUE LE PREMIER ////////////

    char com1[] = "Allez en prison sans passer par la case de départ."; //ON CREER CETTE VARIABLE POUR POUVOIR FAIRE UN STRCPY
    strcpy(tabCartes[16].nom, com1); //COPIE COM1 DANS tabCartes[16].nom

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
/*  ENTREES : INT ALEATOIRE, LE TABLEAUX DE STRUCTURES CARTECHANCE
    SORTIE : AUCUNE
    BUT DE LA FONCTION : AFFICHE LE CONTENU D'UNE CARTE COMMUNAUTES
*/
void affichageCarteCommunautes(int aleatoire, CarteChance tabCartes[])
{
    Color(9,0); //BLEU
    gotoligcol(12,100);
    printf("CARTE COMMUNAUTES");
    // ON REGLE L'AFFICHAGE SELON LA LONGUEUR DE LA CARTE COMMUNAUTES ////
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
    //////////////////////////////////////////////////////////////////////
    printf("%s", tabCartes[aleatoire].nom); //AFFICHE LE CONTENU DE LA CARTE COMMUNAUTES
    gotoligcol(39, 103);
    printf("%d/16", aleatoire); //AFFICHE LE NOMBRE DE LA CARTE COMMUNAUTES
}

/*  ENTREE : AUCUNE
    SORTIE : INT ALEATOIRE COMPRIS ENTRE 0 ET 15
    BUT DE LA FONCTION : GENERATION D'UN NOMBRE ALEATOIRE ENTRE 0 ET 15
*/
int generationAleatoireChance()
{
    srand(time(NULL));
    int aleatoire = 0;
    aleatoire = (rand() % (15-0) + 0); // generation aleatoire entre 0 et 15
    return (aleatoire);
}
/*  ENTREE : AUCUNE
    SORTIE : INT ALEATOIRE COMPRIS ENTRE 16 ET 31
    BUT DE LA FONCTION : GENERATION D'UN NOMBRE ALEATOIRE ENTRE 16 ET 31
*/
int generationAleatoireCommu()
{
    srand(time(NULL)); //PERMET D'EVITER D'AVOIR LE MEME NOMBRE ALEATOIRE
    int aleatoire = 0;
    aleatoire = (rand() % (31 - 16) + 16); //GENERATION ALEATOIRE ENTRE 16 ET 31
    return (aleatoire);
}
