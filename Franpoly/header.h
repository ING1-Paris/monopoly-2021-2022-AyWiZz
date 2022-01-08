#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define tailleCarre 6
#define taille 20

typedef struct Joueur
{
    char nom[taille];
    unsigned int argent;
    int lastposition;
    int position;
    int couleur;
    int choix;
    int haveToPlay;
    int prison;
    int tempsPrison;
    int t1Possede;
    int t2Possede;
    int t3Possede;
    int t4Possede;
    int t5Possede;
    int t6Possede;
    int t7Possede;
    int t8Possede;
    int t9Possede;
    int t10Possede;
    int nbTerrain;
    int doubleDee;
    char terrain1[taille];
    char terrain2[taille];
    char terrain3[taille];
    char terrain4[taille];
    char terrain5[taille];
    char terrain6[taille];
    char terrain7[taille];
    char terrain8[taille];
    char terrain9[taille];
    char terrain10[taille];
} Joueur;

typedef struct
{
    char nom[30];

    char couleur[15];

    unsigned int loyer;

    int loyer1;

    int loyer2;

    int loyer3;

    int loyer4;

    int loyer5;

    int hypo;

    int possede;

    int possession;
    int nbMaisons;
    int nbHotels;

} CartePlanete;

typedef struct
{
    char nom[30];
    int loyer;
    int loyer2;
    int loyer3;
    int loyer4;
    int possede;
} Satellite;


void affichageCartesVilles(int aleatoire, CartePlanete tabCartesPlanetes[]);

void creationCartesPlanetes(CartePlanete tabCartesPlanetes[]);
void creationContourCarteVille();



typedef struct Chance
{
    char nom[100];
} CarteChance;

void gotoligcol( int lig, int col );

void setConsoleSize(short width, short height);

void Color(int couleurDuTexte,int couleurDeFond);

void setConsoleFullscreen();

void clearScreen();


void creationPlateau();
void couleursPlateau();

void des(int nbDe1, int nbDe2, int nbDe, int *pnbDe1, int *pnbDe2, int *pnbDe);

int positionCurseur();
int checkPartie();

void affichPion(Joueur j[],int joueurJ);
int choixDepart();
void remplir(Joueur j[]);
int remplissageJoueur(Joueur j[]);
void affichageCarteCommunautes(int aleatoire, CarteChance tabCartes[]);

void affichInfo(Joueur j[], int joueurPlaying, int nbJoueurs);

void creationCartesChance(CarteChance tabCartes[]);
void creationCartesCommunautes(CarteChance tabCartes[]);

void creationContourCarteChanceCommunaute();
void affichageCarteChance(int aleatoire, CarteChance tabCartes[]);

void creationContourCarteSatellite();
void bandeauCartes();

int generationAleatoireChance();
int generationAleatoireCommu();
int generationAleatoireSatellite();

void creationSatellites(Satellite tabSatellites[4]);
void ecritureSatellite(Satellite tabSatellites[4], int aleatoire);

int prison(Joueur player[],int joueurPlaying, int nbJoueurs);

#endif // HEADER_H_INCLUDED
