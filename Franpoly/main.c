#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int main()
{

    int c;
    FILE *file;
    file = fopen("./sauvegarde/sauvegarde1.txt", "r");
    if (file == NULL)
    {
        printf("Erreur d'ouverture de fichier.");
        return 1;
    }
    if (file)
    {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }

    return 0;
}
