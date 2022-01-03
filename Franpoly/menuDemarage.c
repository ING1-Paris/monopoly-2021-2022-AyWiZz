#define COLONNE 0
#include <unistd.h>
#define tailleCarre 6
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int positionCurseur()
{
    int toucheUtilisateur = 0;
    int curseur = 1;
    //rang 0
    //printf("\n");//rang 1
    //gotoligcol(0,COLONNE);
    printf("SPACE MONOPOLY:\n");
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
            if(toucheUtilisateur == 0x0D)
            {
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
            if(toucheUtilisateur == 0x0D)
            {
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

int checkPartie()
{
    int curseur = 2;
    int sauvegarde = 0;
    int toucheUtilisateur = _getch();

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
        if(curseur == 0) //Si le curseur est trop en haut
        {
            curseur = 4;//Retourner en bas
            system("cls");
        }
        system("cls");
        gotoligcol(0, COLONNE);
        printf("SPACE FRANPOLY SAUVEGARDES:\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        Color(9,0);
        //gotoligcol(5, COLONNE);
        printf("%c Sauvegarde 1",0x08);//rang 2
        printf("\n");//rang 3
        printf("\n");
        Color(15,0);
        //gotoligcol(7,COLONNE);
        printf("%c Sauvegarde 2",0x08);//rang 4
        printf("\n");//rang 5
        printf("\n");
        printf("%c Sauvegarde 3",0x08);//rang 4
        printf("\n");//rang 5
        printf("\n");
        printf("%c Sauvegarde 4",0x08);//rang 4
        printf("\n");//rang 5
        printf("\n");
        if(curseur == 1)
        {
            system("cls");
            gotoligcol(0, COLONNE);
            printf("SPACE FRANPOLY SAUVEGARDES:\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            Color(9,0);
            //gotoligcol(5, COLONNE);
            printf("%c Sauvegarde 1",0x08);//rang 2
            printf("\n");//rang 3
            printf("\n");
            Color(15,0);
            //gotoligcol(7,COLONNE);
            printf("%c Sauvegarde 2",0x08);//rang 4
            printf("\n");//rang 5
            printf("\n");
            printf("%c Sauvegarde 3",0x08);//rang 4
            printf("\n");//rang 5
            printf("\n");
            printf("%c Sauvegarde 4",0x08);//rang 4
            printf("\n");//rang 5
            printf("\n");
        }
        if(curseur == 2)
        {
            system("cls");
            gotoligcol(0, COLONNE);
            printf("SPACE FRANPOLY SAUVEGARDES:\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            Color(15,0);
            //gotoligcol(5, COLONNE);
            printf("%c Sauvegarde 1",0x08);//rang 2
            printf("\n");//rang 3
            printf("\n");
            Color(9,0);
            //gotoligcol(7,COLONNE);
            printf("%c Sauvegarde 2",0x08);//rang 4
            printf("\n");//rang 5
            printf("\n");
            Color(15, 0);
            printf("%c Sauvegarde 3",0x08);//rang 4
            printf("\n");//rang 5
            printf("\n");
            Color(15, 0);
            printf("%c Sauvegarde 4",0x08);//rang 4
            printf("\n");//rang 5
            printf("\n");
            Color(15, 0);
        }
        if(curseur == 3)
        {
            system("cls");
            gotoligcol(0, COLONNE);
            printf("SPACE FRANPOLY SAUVEGARDES:\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            Color(15,0);
            //gotoligcol(5, COLONNE);
            printf("%c Sauvegarde 1",0x08);//rang 2
            printf("\n");//rang 3
            printf("\n");
            Color(15,0);
            //gotoligcol(7,COLONNE);
            printf("%c Sauvegarde 2",0x08);//rang 4
            printf("\n");//rang 5
            printf("\n");
            Color(9, 0);
            printf("%c Sauvegarde 3",0x08);//rang 4
            printf("\n");//rang 5
            printf("\n");
            Color(15, 0);
            printf("%c Sauvegarde 4",0x08);//rang 4
            printf("\n");//rang 5
            printf("\n");
            Color(15, 0);
        }
        if(curseur == 4)
        {
            system("cls");
            gotoligcol(0, COLONNE);
            printf("SPACE FRANPOLY SAUVEGARDES:\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            Color(15,0);
            //gotoligcol(5, COLONNE);
            printf("%c Sauvegarde 1",0x08);//rang 2
            printf("\n");//rang 3
            printf("\n");
            Color(15,0);
            //gotoligcol(7,COLONNE);
            printf("%c Sauvegarde 2",0x08);//rang 4
            printf("\n");//rang 5
            printf("\n");
            Color(15, 0);
            printf("%c Sauvegarde 3",0x08);//rang 4
            printf("\n");//rang 5
            printf("\n");
            Color(9, 0);
            printf("%c Sauvegarde 4",0x08);//rang 4
            printf("\n");//rang 5
            printf("\n");
            Color(15, 0);
        }
        if(curseur == 5)
        {
            curseur = 1;
        }
    }
    while(toucheUtilisateur != 0x0D);

    gotoligcol(5,17);//Car il y a 16 lettres dans "Nouvelle Partie :"

    gotoligcol(57,0);
    return sauvegarde;
}
