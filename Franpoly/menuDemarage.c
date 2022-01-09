#define COLONNE 0
#include <unistd.h>
#define tailleCarre 6
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"
#include <conio.h>
#define taillemax 30

int positionCurseur()
{
    int toucheUtilisateur = 0;
    int curseur = 1;
    int choix = 0;
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
    printf("\n");
    printf("\n");            //rang 5
    Color(15, 0);
    printf("%c Afficher les regles:",0x08);
    printf("\n");
    printf("\n");            //rang 5
    Color(15, 0);
    printf("%c Afficher les membres du projet:",0x08);


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
            curseur = 4;//Retourner en bas
        }
        if(curseur == 5) //Si le curseur est trop en bas
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
            Color(15, 0);
            gotoligcol(9, COLONNE);
            printf("%c Afficher les regles:",0x08);
            Color(15, 0);
            gotoligcol(11, COLONNE);
            printf("%c Afficher les membres du projet:",0x08);

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
            Color(15, 0);
            gotoligcol(9, COLONNE);
            printf("%c Afficher les regles:",0x08);
            Color(15, 0);
            gotoligcol(11, COLONNE);
            printf("%c Afficher les membres du projet:",0x08);

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
        if(curseur == 3)
        {

            Color(15,0);
            gotoligcol(0,COLONNE);
            printf("SPACE FRANPOLY :\n");
            Color(15,0);
            gotoligcol(5,COLONNE);
            printf("%c Nouvelle Partie:",0x08);
            Color(15,0);
            gotoligcol(7,COLONNE);
            printf("%c Charger la Partie:",0x08);
            Color(9, 0);
            gotoligcol(9, COLONNE);
            printf("%c Afficher les regles:",0x08);
            Color(15, 0);
            gotoligcol(11, COLONNE);
            printf("%c Afficher les membres du projet:",0x08);

            if(toucheUtilisateur == 0x0D)
            {
                FILE * fp;

                fp = fopen("regles.txt", "r");

                if(fp == NULL)
                {
                    printf("erreur fopen \n");
                    return 1;
                }

                char str[1000];
                while(fgets(str, 1000, fp) != NULL)
                {
                    printf("%s", str);
                }
                fclose(fp);
//                char c = fgetc(fp);
//                system("cls");
//                while(c != EOF)
//                {
//                    printf("%c", c);
//                    c = fgetc(fp);
//                }


                Color(9, 0);
                do
                {
                    printf("\n \n \n Taper 1 pour retourner au menu");
                    fflush(stdin);
                    scanf("%d", &choix);
                    Color(9, 0);
                }
                while(choix < 1 || choix > 2);

                if(choix == 1)
                {
                    system("cls");
                    positionCurseur();
                    Color(9, 0);
                }


                Color(9,0);


            }


        }
        if(curseur == 4)
        {
            Color(15,0);
            gotoligcol(0,COLONNE);
            printf("SPACE FRANPOLY :\n");
            Color(15,0);
            gotoligcol(5,COLONNE);
            printf("%c Nouvelle Partie:",0x08);
            Color(15,0);
            gotoligcol(7,COLONNE);
            printf("%c Charger la Partie:",0x08);
            Color(15, 0);
            gotoligcol(9, COLONNE);
            printf("%c Afficher les regles:",0x08);
            Color(9, 0);
            gotoligcol(11, COLONNE);
            printf("%c Afficher les membres du projet:",0x08);

            if(toucheUtilisateur == 0x0D)
            {
                FILE * fp;

                fp = fopen("membres.txt", "r");

                if(fp == NULL)
                {
                    printf("erreur fopen \n");
                    return 1;
                }
                char c = fgetc(fp);
                system("cls");
                Color(9, 0);
                while(c != EOF)
                {
                    printf("%c", c);
                    c = fgetc(fp);
                }


                do
                {
                    gotoligcol(57, 0);
                    printf("\n \n \n Taper 1 pour retourner au menu \n");
                    fflush(stdin);
                    scanf("%d", &choix);
                }
                while(choix < 1 || choix > 2);

                if(choix == 1)
                {
                    system("cls");
                    positionCurseur();
                    Color(9, 0);
                }



                Color(5, 0);

            }

        }





    }
    while(toucheUtilisateur != 0x0D); //Tant que l'utilisateur n'a pas appuyé sur entrer
    return curseur;
}

void appelSauvegarde(int * pnbJoueurs, Joueur player[6])
{
    int curseur = 1;
    int nombreJoueurs=0;

    gotoligcol(0, COLONNE);


    FILE * sauvegarde;

    sauvegarde = fopen("Sauvegarde.txt", "r");

    if(sauvegarde == NULL)
    {
        printf("erreur fopen \n");
        return 1;
    }

    fscanf(sauvegarde, "%d", &nombreJoueurs);


    for (int j=1; j< nombreJoueurs+1; j++)
    {
        fgets(player[j].nom, taillemax, sauvegarde);
        fscanf(sauvegarde, "%d", &player[j].argent);
        fscanf(sauvegarde, "%d", &player[j].position);
        fgets(player[j].terrain1, taillemax, sauvegarde);
        fgets(player[j].terrain2, taillemax, sauvegarde);
        fgets(player[j].terrain3, taillemax, sauvegarde);
        fgets(player[j].terrain4, taillemax, sauvegarde);
        fgets(player[j].terrain5, taillemax, sauvegarde);
        fgets(player[j].terrain6, taillemax, sauvegarde);
        fgets(player[j].terrain7, taillemax, sauvegarde);
        fgets(player[j].terrain8, taillemax, sauvegarde);
        fgets(player[j].terrain9, taillemax, sauvegarde);
        fgets(player[j].terrain10, taillemax, sauvegarde);
    }
    fclose(sauvegarde);
    *pnbJoueurs=nombreJoueurs;
}
