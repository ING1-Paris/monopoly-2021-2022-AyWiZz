#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

struct joueur{
    char nom;
    int argent;
    int position;
    char terrain1;
    char terrain2;
    char terrain3;
    char terrain4;

}joueur;


float banque(struct joueur j1);

#endif // HEADER_H_INCLUDED
