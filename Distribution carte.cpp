#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 24
#define MAX_PLAYERS 4

char cartes[NUM_CARDS] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x'};
char mains[MAX_PLAYERS][NUM_CARDS / 2];

void melangeCartes(char *cartes) {
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        char temp = cartes[i];
        cartes[i] = cartes[j];
        cartes[j] = temp;
    }
}

void distributionCartes(char *cartes, int nbJoueur, char mains[][NUM_CARDS / 2]) {
    int cartesPerPlayer = NUM_CARDS / nbJoueur;
    for (int i = 0; i < nbJoueur; i++) {
        for (int j = 0; j < cartesPerPlayer; j++) {
            mains[i][j] = cartes[i * cartesPerPlayer + j];
        }
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the number of players
    int nbJoueur;
    printf("Nombre de joueurs (2-4): ");
    scanf("%d", &nbJoueur);

    // Shuffle the deck
    melangeCartes(cartes);

    // Deal the cartes to the players
    distributionCartes(cartes, nbJoueur, mains);

    // Print the mains
    for (int i = 0; i < nbJoueur; i++) {
        printf("Main du joueur %d: ", i + 1);
        for (int j = 0; j < NUM_CARDS / nbJoueur; j++) {
            printf("%c ", mains[i][j]);
        }
        printf("\n");
    }
    return 0;
}
