#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


void des(int x,int *px)
{

    int nbr = 0;
    const int max = 6, min = 1;
    srand(time(NULL));
    for (int i=0; i<2; i++){

        nbr = (rand() % (max - min + 1)) + min;
        x+=nbr;

        printf("%c", 0xDA);
        for (int j=0; j<7; j++){
            printf("%c", 0xC4);
        }
        printf("%c\n", 0xBF);
        printf("%c       %c\n", 0xB3, 0xB3);
        printf("%c   %d   %c\n", 0xB3, nbr, 0xB3);
        printf("%c       %c\n", 0xB3, 0xB3);
        printf("%c", 0xC0);
        for (int j=0; j<7; j++){
            printf("%c", 0xC4);
        }
        printf("%c\n", 0xD9);
    }

    *px=x;

}

void des();

#endif // HEADER_H_INCLUDED
