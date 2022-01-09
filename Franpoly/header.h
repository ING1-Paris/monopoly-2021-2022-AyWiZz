#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define tailleCarre 6
#define taille 20

typedef struct Joueur
{
    char nom[taille];
    unsigned int argent;
    unsigned int lastposition;
    unsigned int position;
    unsigned int couleur;
    unsigned int choix;
    unsigned int haveToPlay;
    unsigned int prison;
    unsigned int tempsPrison;
    unsigned int t1Possede;
    unsigned int t2Possede;
    unsigned int t3Possede;
    unsigned int t4Possede;
    unsigned int t5Possede;
    unsigned int t6Possede;
    unsigned int t7Possede;
    unsigned int t8Possede;
    unsigned int t9Possede;
    unsigned int t10Possede;
    unsigned int nbTerrain;
    unsigned int doubleDee;
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
    unsigned int nbSat;
    unsigned int cartePrison;
} Joueur;

typedef struct
{
    char nom[30];
    char couleur[15];
    unsigned int loyer;
    unsigned int loyer1;
    unsigned int loyer2;
    unsigned int loyer3;
    unsigned int loyer4;
    unsigned int loyer5;
    int hypo;
    int hypoValid;
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
    int possession;
    int hypoValid;
    int hypo;
    int nbPossession;
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

void hypotheque(Joueur j[], CartePlanete tabCartes[], int joueurPlaying, int planete,int nbMaisonTotal, int nbHotelTotal,int *pnbMaisonTotal, int *pnbHotelTotal);
void rachatHypo(Joueur j[], CartePlanete tabCartes[], int joueurPlaying, int planete,int nbMaisonTotal, int nbHotelTotal,int *pnbMaisonTotal, int *pnbHotelTotal);
void passMaison(Joueur j[], CartePlanete tabCartes[], int joueurPlaying, int planete);

void hypoSat(Joueur j[], Satellite sat[],int joueurPlaying, int satellite);
void rachatHypoSat(Joueur j[], Satellite sat[],int joueurPlaying, int satellite);
void passSat(Joueur j[], Satellite sat[], int joueurPlaying, int satellite);

#endif // HEADER_H_INCLUDED
