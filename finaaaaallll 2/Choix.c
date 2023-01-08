#include "biblio.h"
//choix de l'orientation de la tuile
int choixOrientation() {
    int choix;
    do {
        printf("Dans quel sens voulez vous tourner la tuile:\n1: Base(la facon dont elle est sortie)\n2: 90 degres sens horaire\n3: 180 degres\n4: 90 degres sens anti horaire\n");
        scanf("%d", &choix);
    } while (!(choix == 1 || choix == 2 || choix == 3 || choix == 4));
    return choix;
}
//choix de la colonne par laquelle on insere la tuile
int choixColonne() {
    int choixcolonne;
    do {
        printf("Quelle colonne souhaitez vous decaler?\n2, 4 ou 6\n0: Ligne\n");
        scanf("%d", &choixcolonne);
    } while (!(choixcolonne == 0 || choixcolonne == 2 || choixcolonne == 4 || choixcolonne == 6));
    return choixcolonne;
}
//choix de la ligne par laquelle on insere la tuile
int choixLigne() {
    int choixligne;
    do {
        printf("Quelle ligne souhaitez vous decaler?\n2, 4 ou 6\n");
        scanf("%d", &choixligne);
    } while (!(choixligne == 2 || choixligne == 4 || choixligne == 6)); // blindage saisie
    return choixligne;
}
//choix de par ou on insere la tuile (haut ou bas)
int choixHB() {
    int choixsens;
    do {
        printf("Par ou voulez vous inserer la tuile?\n1:Haut\n2:Bas\n");
        scanf("%d", &choixsens);
    } while (!(choixsens == 1 || choixsens == 2)); // blindage saisie
    return choixsens;
}
//choix de par ou on insere la tuile (droite ou gauche)
int choixGD() {
    int choixsens2;
    do {
        printf("Par ou voulez vous inserer la tuile?\n1:Gauche\n2:Droite\n");
        scanf("%d", &choixsens2);
    } while(!(choixsens2==1 || choixsens2==2)); // blindage saisie
    return choixsens2;
}