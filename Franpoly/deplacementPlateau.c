#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "header.h"

///fonction permettant de tirer les dées et de renvoyer le résultat des deux dées ainsi que la valeur de chaque dé.
///entrées : variables auxquelles ont assigne le résultat de chaque dé et la somme des dées et les pointeurs qui pointent sur ces variables.
///sortie : les pointeurs des variables pointant sur les valeurs des dées

void des(int x1, int x2, int x, int *px1, int * px2, int *px)
{

    int nbr = 0, a = 23;
    const int max = 6, min = 1; //initialisation des variables maximale et minimale des dés
    srand(time(NULL));///on inclue le temps afin d'avoir une génération réellement aléatoire
        nbr = (rand() % (max - min)) + min; //nombre aléatoire pour le premier dé
        x1=nbr; //affectation du premier dé
        gotoligcol(a,47);
        printf("%c", 0xDA); 
        //affichage du premier dé
        for (int j=0; j<7; j++)
        {
            printf("%c", 0xC4);
        }
        printf("%c", 0xBF);
        a+=1;
        gotoligcol(a, 47);
        printf("%c       %c", 0xB3, 0xB3);
        a+=1;
        gotoligcol(a, 47);
        printf("%c   %d   %c", 0xB3, nbr, 0xB3);
        a+=1;
        gotoligcol(a, 47);
        printf("%c       %c", 0xB3, 0xB3);
        a+=1;
        gotoligcol(a, 47);
        printf("%c", 0xC0);
        for (int j=0; j<7; j++)
        {
            printf("%c", 0xC4);
        }
        printf("%c\n", 0xD9);
        a+=1;

           
        //On fait la même chose pour le deuxième dé//

        nbr = (rand() % (max - min)) + min;
        x2=nbr;
        gotoligcol(a,47);
        printf("%c", 0xDA);
        for (int j=0; j<7; j++)
        {
            printf("%c", 0xC4);
        }
        printf("%c", 0xBF);
        a+=1;
        gotoligcol(a, 47);
        printf("%c       %c", 0xB3, 0xB3);
        a+=1;
        gotoligcol(a, 47);
        printf("%c   %d   %c", 0xB3, nbr, 0xB3);
        a+=1;
        gotoligcol(a, 47);
        printf("%c       %c", 0xB3, 0xB3);
        a+=1;
        gotoligcol(a, 47);
        printf("%c", 0xC0);
        for (int j=0; j<7; j++)
        {
            printf("%c", 0xC4);
        }
        printf("%c\n", 0xD9);
        a+=1;

        x=x1+x2;
    
    
    //on récupère les 3 valeurs par passage par adresse

    *px1=x1;
    *px2=x2;
    *px=x;

}

///fonction permettant d'afficher les pions des joueurs à tout moment.
///entrées : la structure du joueur et le joueur jouant
///sorties : aucune mais affiche le pion de la bonne couleur correspondant au joueur dans la case demandée.
void affichPion(Joueur j[], int joueurJ)
{
    gotoligcol(4,195); 
    //création d'un tableau qui regroupe le centre de chaque case
    int caze[29][2]= {{0,0},{4,26},{4,48},{4,70},{4,92},{4,114},{4,136},{4,158},{4,180},
        {11,180},{18,180},{25,180},{32,180},{39,180},{46,180},{53,180},
        {53,158},{53,136},{53,114},{53,92},{53,70},{53,48},{53,26},
        {46,26},{39,26},{32,26},{25,26},{18,26},{11,26}
    };

    int nbDe = 0;
    int *pnbDe = &nbDe;///on récupère le nombre des dés
    int pos = 0;

    pos = j[joueurJ].position;
    
    //Cas où la position du joueur dépasse 27 (s'il a fait un tour de plateau)//
    if(pos>27)
    {
        j[joueurJ].argent+=200; //Le joueur gagne 200 $
        pos = pos-27; //Sa position revient à 0
    }
    j[joueurJ].position = pos;
    pos = 1 + pos + *pnbDe; //on ajoute le nombre renvoyé par les dés à sa position

    //DIFFERENTES POSITION DE CHAQUE PION (PAR COULEUR) EN FONCTION DU NUMERO DE LA CASE SUR LAQUELLE IL EST//
    if (pos==1 || pos==2 || pos==3 || pos==4 || pos==5 || pos==6 || pos==7 || pos==9 ||pos==10 || pos==11 || pos==12 || pos==13 || pos==14 || pos==18 || pos==19 || pos==23 || pos==24 || pos==25 || pos==26 || pos==27 || pos==28)
    {
        if(joueurJ == 1)
        {
            Color(10, 0);
            gotoligcol(caze[pos][0]-2,caze[pos][1]-4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-2+1,caze[pos][1]-4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 2)
        {
            Color(11, 0);
            gotoligcol(caze[pos][0]-2,caze[pos][1]);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-2+1,caze[pos][1]);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 3)
        {
            Color(12, 0);
            gotoligcol(caze[pos][0]-2,caze[pos][1]+4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-2+1,caze[pos][1]+4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 4)
        {
            Color(13, 0);
            gotoligcol(caze[pos][0]+1,caze[pos][1]-4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+1+1,caze[pos][1]-4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 5)
        {
            Color(14, 0);
            gotoligcol(caze[pos][0]+1,caze[pos][1]);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+1+1,caze[pos][1]);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 6)
        {
            Color(15, 0);
            gotoligcol(caze[pos][0]+1,caze[pos][1]+4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+1+1,caze[pos][1]+4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
    }

    //ON DEPLACE UN PEU LES PIONS POUR LES CASES ALLER EN PRISON ET PARC GRATUIT//
    else if (pos==15 || pos==22)
    {
        if(joueurJ == 1)
        {
            Color(10, 0);
            gotoligcol(caze[pos][0]-2,caze[pos][1]-4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-2+1,caze[pos][1]-4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 2)
        {
            Color(11, 0);
            gotoligcol(caze[pos][0]-2,caze[pos][1]);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-2+1,caze[pos][1]);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 3)
        {
            Color(12, 0);
            gotoligcol(caze[pos][0]-2,caze[pos][1]+4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-2+1,caze[pos][1]+4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 4)
        {
            Color(13, 0);
            gotoligcol(caze[pos][0]+2,caze[pos][1]-4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+2+1,caze[pos][1]-4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 5)
        {
            Color(14, 0);
            gotoligcol(caze[pos][0]+2,caze[pos][1]);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+2+1,caze[pos][1]);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 6)
        {
            Color(15, 0);
            gotoligcol(caze[pos][0]+2,caze[pos][1]+4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+2+1,caze[pos][1]+4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
    }

    //MÊME CHOSE POUR LES CASES DU DESSOUS//
    else if (pos==16 || pos==17 || pos==20 || pos==21)
    {
        if(joueurJ == 1)
        {
            Color(10, 0);
            gotoligcol(caze[pos][0]-1,caze[pos][1]-4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-1+1,caze[pos][1]-4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 2)
        {
            Color(11, 0);
            gotoligcol(caze[pos][0]-1,caze[pos][1]);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-1+1,caze[pos][1]);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 3)
        {
            Color(12, 0);
            gotoligcol(caze[pos][0]-1,caze[pos][1]+4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-1+1,caze[pos][1]+4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 4)
        {
            Color(13, 0);
            gotoligcol(caze[pos][0]+2,caze[pos][1]-4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+2+1,caze[pos][1]-4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 5)
        {
            Color(14, 0);
            gotoligcol(caze[pos][0]+2,caze[pos][1]);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+2+1,caze[pos][1]);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 6)
        {
            Color(15, 0);
            gotoligcol(caze[pos][0]+2,caze[pos][1]+4);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+2+1,caze[pos][1]+4);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
    }

    //MEME CHOSE POUR LA PRISON//
    else if (pos==8)
    {
        if(joueurJ == 1)
        {
            Color(10, 0);
            gotoligcol(caze[pos][0]-2,caze[pos][1]-10);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-2+1,caze[pos][1]-10);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 2)
        {
            Color(11, 0);
            gotoligcol(caze[pos][0]-2,caze[pos][1]+8);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]-2+1,caze[pos][1]+8);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 3)
        {
            Color(12, 0);
            gotoligcol(caze[pos][0],caze[pos][1]-10);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+1,caze[pos][1]-10);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 4)
        {
            Color(13, 0);
            gotoligcol(caze[pos][0],caze[pos][1]+8);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+1,caze[pos][1]+8);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 5)
        {
            Color(14, 0);
            gotoligcol(caze[pos][0]+2,caze[pos][1]-10);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+2+1,caze[pos][1]-10);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
        else if(joueurJ == 6)
        {
            Color(15, 0);
            gotoligcol(caze[pos][0]+2,caze[pos][1]+8);
            printf("%c%c%c", 0xC9, 0xCD, 0xBB);
            gotoligcol(caze[pos][0]+2+1,caze[pos][1]+8);
            printf("%c%c%c", 0xC8, 0xCD, 0xBC);
            Color(9, 0);
        }
    }



}



