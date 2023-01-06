#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOM_CARTES 24
#define MAX_JOUEURS 4

char cartes[NOM_CARTES] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x'};
char mains[MAX_JOUEURS][NOM_CARTES / 2];

void melangeCartes(char *cartes) {
    for (int i = 0; i < NOM_CARTES; i++) {
        int j = rand() % NOM_CARTES;
        char temp = cartes[i];
        cartes[i] = cartes[j];
        cartes[j] = temp;
    }
}

void distributionCartes(char *cartes, int nbJoueur, char mains[][NOM_CARTES / 2]) {
    int cartesParJoueurs = NOM_CARTES / nbJoueur;
    for (int i = 0; i < nbJoueur; i++) {
        for (int j = 0; j < cartesParJoueurs; j++) {
            mains[i][j] = cartes[i * cartesParJoueurs + j];
        }
    }
}

int main() {
    srand(time(NULL));
    
    int nbJoueur;
    printf("Nombre de joueurs (2-4): ");
    scanf("%d", &nbJoueur);

    melangeCartes(cartes);

    distributionCartes(cartes, nbJoueur, mains);

    // Print les mains
    for (int i = 0; i < nbJoueur; i++) {
        printf("Main du joueur %d: ", i + 1);
        for (int j = 0; j < NOM_CARTES / nbJoueur; j++) {
            printf("%c ", mains[i][j]);
        }
        printf("\n");
    }
    return 0;
}
