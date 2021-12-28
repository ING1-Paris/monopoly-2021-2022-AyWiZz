#include <windows.h>
#define tailleCarre 6
#include <time.h>

typedef struct Chance{
    char nom[100];
}CarteChance;

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




void creationContourCarte()
{
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 24;
    gotoligcol(1,65);
    for(i = 0; i < 80; i++)
    {
        printf("%c", 0xC4);
    }
    gotoligcol(1,65);
    printf("%c", 0xDA);
    gotoligcol(1,145);
    printf("%c", 0xBF);
    gotoligcol(2,65);

    for(j = 0; j <4; j++)
    {
        for(i = 0; i < tailleCarre; i++)
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

    gotoligcol(30, 65);
    printf("%c", 0xC0);
    for(i = 0; i < 80; i++)
    {
        printf("%c", 0xC4);
    }
    gotoligcol(30, 145);
    printf("%c", 0xD9);

    gotoligcol(1, 145);
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
    gotoligcol(2,100);
    printf("CARTE CHANCE");
    if(aleatoire == 6 || aleatoire == 7 || aleatoire == 8 || aleatoire == 9 || aleatoire == 10 || aleatoire == 11){
        gotoligcol(14, 75);
    }
    else if(aleatoire == 4 || aleatoire == 5  || aleatoire == 14 || aleatoire == 15){
        gotoligcol(14, 95);
    }
    else{
        gotoligcol(14,85);
    }
    printf("%s", tabCartes[aleatoire]);
    gotoligcol(29, 103);
    printf("%d/16", aleatoire);
}






int generationAleatoire(){
    srand(time(NULL));
    int aleatoire = 0;
    aleatoire = rand() % 16;
    return (aleatoire);
}