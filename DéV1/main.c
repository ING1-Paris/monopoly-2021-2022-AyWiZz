#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"


int main ()
{
    int x = 0;
    int *px = &x;
    des(x,px);
    printf("%d", *px);
}

