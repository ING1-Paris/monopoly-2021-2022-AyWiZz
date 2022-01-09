#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define tailleCarre 6
#define taille 20


typedef struct Joueur //CETTE STRUCTURE CORRESPOND À UN JOUEUR
{
    char nom[taille]; //CELA CORRESPOND AU NOM DU JOUEUR
    unsigned int argent; //CELA CORRESPOND À L'ARGENT DU JOUEUR
    unsigned int lastposition; //CELA CORRESPOND À LA DERNIÈRE POSITION DU JOUEUR
    unsigned int position; //CELA CORRESPOND À LA POSITION ACTUELLE DU JOUEUR
    unsigned int couleur; //CELA CORRESPOND À LA COULEUR DU PION DU JOUEUR
    unsigned int choix; //CELA CORRESPOND AU CHOIX DU JOUEUR (SI IL LANCE LES DES OU NON PAR EXEMPLE)
    unsigned int haveToPlay; //PERMET DE SAVOIR SI LE JOEUR DOIT JOUER OU NON
    unsigned int prison; //PERMET DE SAVOIR SI LE JOUEUR EST EN PRISON OU NON
    unsigned int tempsPrison; //CORRESPOND AU TEMPS RESTÉ EN PRISON
    unsigned int t1Possede; //EST CE QUE LE JOUEUR POSSÈDE 1 TERRAIN ?
    unsigned int t2Possede; //EST CE QUE LE JOUEUR POSSÈDE 2 TERRAINS ?
    unsigned int t3Possede; //EST CE QUE LE JOUEUR POSSÈDE 3 TERRAINS ?
    unsigned int t4Possede; //EST CE QUE LE JOUEUR POSSÈDE 4 TERRAINS ?
    unsigned int t5Possede; //EST CE QUE LE JOUEUR POSSÈDE 5 TERRAINS ?
    unsigned int t6Possede; //EST CE QUE LE JOUEUR POSSÈDE 6 TERRAINS ?
    unsigned int t7Possede; //EST CE QUE LE JOUEUR POSSÈDE 7 TERRAINS ?
    unsigned int t8Possede; //EST CE QUE LE JOUEUR POSSÈDE 8 TERRAINS ?
    unsigned int t9Possede; //EST CE QUE LE JOUEUR POSSÈDE 9 TERRAINS ?
    unsigned int t10Possede; //EST CE QUE LE JOUEUR POSSÈDE 10 TERRAINS ?
    unsigned int nbTerrain; //CORRESPOND AU NOMBRE DE TERRAIN POSSÉDÉ PAR LE JOUEUR 
    unsigned int doubleDee; //PERMET DE SAVOIR SI LE JOUEUR A FAIT UN DOUBLE AVEC LES DÉS
    char terrain1[taille]; //COORESPOND AU PREMIER TERRAIN ACHETÉ PAR LE JOUEUR
    char terrain2[taille]; //COORESPOND AU DEUXIÈME TERRAIN ACHETÉ PAR LE JOUEUR
    char terrain3[taille]; //COORESPOND AU TROISIÈME TERRAIN ACHETÉ PAR LE JOUEUR
    char terrain4[taille]; //COORESPOND AU QUATRIÈME TERRAIN ACHETÉ PAR LE JOUEUR
    char terrain5[taille]; //COORESPOND AU CINQUIÈME TERRAIN ACHETÉ PAR LE JOUEUR
    char terrain6[taille]; //COORESPOND AU SIXIÈME TERRAIN ACHETÉ PAR LE JOUEUR
    char terrain7[taille]; //COORESPOND AU SEPTIÈME TERRAIN ACHETÉ PAR LE JOUEUR
    char terrain8[taille]; //COORESPOND AU HUITIÈME TERRAIN ACHETÉ PAR LE JOUEUR
    char terrain9[taille]; //COORESPOND AU NEUVIÈME TERRAIN ACHETÉ PAR LE JOUEUR
    char terrain10[taille]; //COORESPOND AU DIXIÈME TERRAIN ACHETÉ PAR LE JOUEUR
    unsigned int nbSat; //CORRESPOND AUX NOMBRES DE SATELLITES POSSÉDÉS PAR LE JOUEUR
    unsigned int cartePrison; //EST CE QUE LE JOUEUR POSSÈDE UNE CARTE PRISON ?
} Joueur;

typedef struct //CETTE STRUCTURE CORRESPOND À CHAQUE PLANÈTE
{
    char nom[30]; //CORESSPOND AU NOM DE LA PLANÈTE
    char couleur[15]; //CORRESPOND A LA COULEUR DE LA PLANÈTE
    unsigned int loyer; //POUR SAVOIR LE PRIX D'UN LOYER AVEC 0 MAISON
    unsigned int loyer1; //POUR SAVOIR LE PRIX D'UN LOYER AVEC 1 MAISONS
    unsigned int loyer2; //POUR SAVOIR LE PRIX D'UN LOYER AVEC 2 MAISONS
    unsigned int loyer3;  //POUR SAVOIR LE PRIX D'UN LOYER AVEC 3 MAISONS
    unsigned int loyer4; //POUR SAVOIR LE PRIX D'UN LOYER AVEC 4 MAISONS
    unsigned int loyer5; //POUR SAVOIR LE PRIX D'UN LOYER AVEC 1 HOTEL
    int hypo; //POUR SAVOIR LE PRIX D'UNE HYPOTHÈQUE
    int hypoValid; //POUR SAVOIR SI LE TERRAIN EST HYPOTHÉQUÉ
    int possede; //POUR SAVOIR SI CE TERRAIN EST POSSÉDÉ
    int possession; //POUR SAVOIR QUEL JOUEUR POSSÈDE CE TERRAIN
    int nbMaisons; //CORRESPOND AUX NOMBRES DE MAISONS SUR CETTE PLANÈTE
    int nbHotels; //CORRESPOND AUX NOMBRES D'HOTELS SUR CETTE PLANÈTE

} CartePlanete;

typedef struct //CORRESPOND À LA STRUCTURE D'UN SATELLITE
{
    char nom[30]; //PERMET DE CONNAITRE LE NOM DU SATELLITE
    int loyer; //PERMET DE SAVOIR LE LOYER QUAND UN JOUEUR POSSÈDE LES 1 SATELLITE EN MÊME TEMPS
    int loyer2; //PERMET DE SAVOIR LE LOYER QUAND UN JOUEUR POSSÈDE LES 2 SATELLITES EN MÊME TEMPS
    int loyer3; //PERMET DE SAVOIR LE LOYER QUAND UN JOUEUR POSSÈDE LES 3 SATELLITES EN MÊME TEMPS
    int loyer4; //PERMET DE SAVOIR LE LOYER QUAND UN JOUEUR POSSÈDE LES 4 SATELLITES EN MÊME TEMPS
    int possede; //PERMET DE SAVOIR SI LE SATELLITE EST POSSÉDÉ PAR QUELQU'UN
    int possession; //PERMET DE SAVOIR À QUI APPARTIENT CE SATELLITE 
    int hypoValid; //PERMET DE SAVOIR SI LE SATELLITE EST HYPOTHÉQUÉ
    int hypo; //PRIX DE L'HYPOTHÈQUE DU SATELLITE
    int nbPossession; //NOMBRE DE SATELLITES QUE LE JOUEUR POSSÈDE
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
void appelSauvegarde(int * pnbJoueurs, Joueur player[6]);


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
