//
// Created by ptail on 08/01/2023.
//

#ifndef FINAAAAALLLL_BIBLIO_H
#define FINAAAAALLLL_BIBLIO_H


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
//Nombre de cartes dans le jeu
#define NOM_CARTES 24


void melangeCartes(char *cartes);
void distribution(char *cartes, int *nbJoueurs, char mains[4][NOM_CARTES]);
void distributionCartes(int *nbJoueurs, char mains[4][NOM_CARTES]);
int choixOrientation();
int choixColonne();
int choixLigne();
int choixHB();
int choixGD();
void creaPlato(char plato[21][27]);
void modiplato(char plato[21][27], char tuileEntrante[3][3], int *x, int *yp, int *x2, int *y2, int *x3, int *y3, int *x4,
               int *y4);
void changcoo(int *x, int *y);
void tp(char tuile[3][3], int *x, int *y, int *x2, int *y2, int *x3, int *y3, int *x4, int *y4, int *erreur, int *erreur2,
        int *erreur3, int *erreur4, char *tp, char *tp2, char *tp3, char *tp4, char plato[21][27]);


#endif //FINAAAAALLLL_BIBLIO_H
