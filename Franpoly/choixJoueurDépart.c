#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int choixDepart()
{
    int selection = 0;
    srand(time(NULL));
    selection = (rand() % (6 - 1 + 1)) + 1;
    return selection;

}
