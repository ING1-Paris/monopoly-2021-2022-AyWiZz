#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define tailleCarre 6
#define taille 20

typedef struct Joueur
{
    char nom[taille];
    int argent;
    int lastposition;
    int position;
    int couleur;
    int choix;
    int haveToPlay;
    int t1Possede;
    int t2Possede;
    int t3Possede;
    int t4Possede;
    int t5Possede;
    char terrain1[taille];
    char terrain2[taille];
    char terrain3[taille];
    char terrain4[taille];
    char terrain5[taille];
}Joueur;

typedef struct
{
    char nom[30];

    char couleur[15];

    int loyer;

    int loyer1;

    int loyer2;

    int loyer3;

    int loyer4;

    int loyer5;

    int hypo;
    int possede;
    int possession;

} CartePlanete;

void affichageCartesVilles(int aleatoire, CartePlanete tabCartesPlanetes[]);

void creationCartesPlanetes(CartePlanete tabCartesPlanetes[]);
void creationContourCarteVille();



typedef struct Chance{
    char nom[100];
}CarteChance;

void gotoligcol( int lig, int col );

void setConsoleSize(short width, short height);

void Color(int couleurDuTexte,int couleurDeFond);

void setConsoleFullscreen();

void clearScreen();



void creationPlateau();

void des(int nbDe,int *pnbDe);

int positionCurseur();
int checkPartie();
void affichPion(Joueur j[],int joueurJ);
int choixDepart();
void remplir(Joueur j[]);
int remplissageJoueur(Joueur j[]);
void affichageCarteCommunautes(int aleatoire, CarteChance tabCartes[]);

void affichInfo(Joueur j[], int joueurPlaying);

void creationCartesChance(CarteChance tabCartes[]);
void creationCartesCommunautes(CarteChance tabCartes[]);

void creationContourCarte();
void affichageCarteChance(int aleatoire, CarteChance tabCartes[]);
int generationAleatoireChance();
int generationAleatoireCommu();


#endif // HEADER_H_INCLUDED
