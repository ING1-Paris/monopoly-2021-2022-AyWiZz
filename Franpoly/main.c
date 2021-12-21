#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

#define tailleCarre 6



int main()
{
    int i = 0;
    FILE* pf = fopen("./savegames/sauvegarde1.txt", "w");
    if (pf == NULL) {
        printf("Erreur d'ouverture de fichier.");
        return 1;
    }
    for (i = 0; i < 5; i++) {
        fprintf(pf, "%d ", i*i);
    }
 fclose(pf);
 pf = NULL;


     creationPlateau();
     gotoligcol(57,0);//Pour décaler le message d'erreur
    // printf("\n");
    return 0;
}
