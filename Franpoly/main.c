#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define COLONNE 0
//////////////////// CES FONCTION VIENT DE LA SECTION PROJET INFORMATIQUE///////////////////////
void gotoligcol( int lig, int col )
{

// ressources

    COORD mycoord;

    mycoord.X = col;

    mycoord.Y = lig;

    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

}
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
///////////////////////////////////////////////////////////////////////////////////////////////
int positionCurseur()
{
    int toucheUtilisateur = 0;
    int curseur = 1;
    //rang 0
    //printf("\n");//rang 1
    //gotoligcol(0,COLONNE);
    printf("SPACE FRANPOLY:\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    Color(9,0);
    //gotoligcol(5, COLONNE);
    printf("%c Nouvelle Partie:",0x08);//rang 2
    printf("\n");//rang 3
    printf("\n");
    Color(15,0);
    //gotoligcol(7,COLONNE);
    printf("%c Charger la Partie:",0x08);//rang 4
    printf("\n");//rang 5
    gotoligcol(5,17);//Car il y a 16 lettres dans "Nouvelle Partie :"


    do
    {
        toucheUtilisateur = _getch();//récupère la touche tapé par l'utilisateur
        if(toucheUtilisateur == 0x48) //Si c'est la fleche du haut
        {
            curseur -= 1;//Va à la proposition au dessus
        }
        if(toucheUtilisateur == 0x50) //Si la touche est la fleche du bas
        {
            curseur += 1;//Va à la proposition en dessous
        }
        if(curseur == -1 || curseur == 0) //Si le curseur est trop en haut
        {
            curseur = 2;//Retourner en bas
        }
        if(curseur == 3) //Si le curseur est trop en bas
        {
            curseur = 1;//Retourner en haut
        }
        //pas top car si on fait ça il faudra remettre à chaque fois le curseur au bon endroit
        if(curseur == 1)
        {
            //Il faut clear la console !
            //system("cls");
            Color(15,0);
            gotoligcol(0,COLONNE);
            printf("SPACE FRANPOLY :\n");
            Color(15,0);
            gotoligcol(7,COLONNE);
            printf("%c Charger la Partie:",0x08);
            Color(9,0);
            gotoligcol(5,COLONNE);
            printf("%c Nouvelle Partie:",0x08);
            if(toucheUtilisateur == 0x0D){
                system("cls");
                Color(15,0);
                printf("Lancement d'une nouvelle partie.....");
                printf("\n");
                printf("\n");
                printf("\n");
            }

        }
        if(curseur == 2)
        {
            //system("cls");
            Color(15,0);
            gotoligcol(0,COLONNE);
            printf("SPACE FRANPOLY :\n");
            Color(15,0);
            gotoligcol(5,COLONNE);
            printf("%c Nouvelle Partie:",0x08);
            Color(9,0);
            gotoligcol(7,COLONNE);
            printf("%c Charger la Partie:",0x08);
            if(toucheUtilisateur == 0x0D){
                system("cls");
                Color(15,0);
                printf("Choisissez la partie que vous voulez lancer :");
                printf("\n");
                printf("\n");
                printf("\n");
            }

        }




    }
    while(toucheUtilisateur != 0x0D); //Tant que l'utilisateur n'a pas appuyé sur entrer
    return curseur;
}

int main()
{
    int curseur = 1;
    curseur = positionCurseur();
    printf("\n%d", curseur);
    return 0;
}
