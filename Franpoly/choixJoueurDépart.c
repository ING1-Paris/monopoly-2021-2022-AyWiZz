#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int choixDepart(nbJoueurs)
{
    int selection = 0;
    srand(time(NULL));
    selection = (rand() % (nbJoueurs - 1 + 1)) + 1;
    return selection;

}
