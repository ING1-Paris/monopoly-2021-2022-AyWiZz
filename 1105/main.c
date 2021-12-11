#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ici ca bz

int remplitTab(char tab[10])
{
    printf("Veuillez entrer 10 caractères \n");

    for(int i = 0; i < 10; i++)
    {
        fflush(stdin);
        printf("Veuillez entrer le %d caractères : \n", i+1);
        scanf("%c", &tab[i]);
    }
    printf("%s", tab);
}

int chercherTab(char tab[10], char motFind[10])
{
    for(int i = 0; i < strlen(tab); i++)
    {
        if(tab[i] == motFind)
        {
            printf("Le mot est present \n");

        }
        else
        {
            printf("Il n'est pas present \n");
        }

    }
}


int main()
{
    char tab[10];
    char motFind[10] = "a";
    remplitTab(tab);
    chercherTab(tab, motFind);

    return 0;
}
