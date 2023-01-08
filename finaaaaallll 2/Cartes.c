#include "biblio.h"

//melange des cartes
void melangeCartes(char *cartes) {
    for (int i = 0; i < NOM_CARTES; i++) {
        int j = rand() % NOM_CARTES;//valeur du tableau que l'on echangera a chaque iteration
        char temp = cartes[i];//temp sert a stocker la variable
        cartes[i] = cartes[j];//pour pouvoir echanger les valeurs
        cartes[j] = temp;
    }
}
//distribue les cartes
void distribution(char *cartes, int *nbJoueurs, char mains[4][NOM_CARTES]) {
    int cartesParJoueurs = NOM_CARTES / (*nbJoueurs);
    for (int i = 0; i < *nbJoueurs; i++) {
        for (int j = 0; j < cartesParJoueurs; j++) {
            mains[i][j] = cartes[i * cartesParJoueurs + j]; //forme de la main [Numero joueur][numero de la carte]
        }
    }
}
//fusion du melange et de la distribution
void distributionCartes(int *nbJoueurs, char mains[4][NOM_CARTES]) {
    char cartes[NOM_CARTES] = {'!', '%', '*', '~', '=', '+', '&', '|', '@', '(', ')', '{', '}', '[', ']', ':', '/', ';','.', '?', '^', '$', '<', '>'}; //les cartes trésors

    srand(time(NULL)); //randomization de rand()

    melangeCartes(cartes); //appel du melange des cartes

    distribution(cartes, nbJoueurs, mains); //appel de la distribution des cartes

    //Print les mains de tous les joueurs
    for (int i = 0; i < (*nbJoueurs); i++) {
        printf("Main du joueur %d: ", i + 1);
        for (int j = 0; j < NOM_CARTES / (*nbJoueurs); j++) {
            printf("%c ", mains[i][j]);
        }
        printf("\n");
    }
}