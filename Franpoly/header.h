#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define tailleCarre 6
#define taille 20

typedef struct Joueur
{
    char nom[taille];
    int argent;
    int position;
    int choix;
    int haveToPlay;
    char terrain1[taille];
    char terrain2[taille];
    char terrain3[taille];
    char terrain4[taille];
    char terrain5[taille];
}Joueur;

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

void creationCartesChance(CarteChance tabCartes[]);
void creationCartesCommunautes(CarteChance tabCartes[]);

void creationContourCarte();
void affichageCarteChance(int aleatoire, CarteChance tabCartes[]);
int generationAleatoire();


#endif // HEADER_H_INCLUDED
