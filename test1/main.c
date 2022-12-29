#include "biblio.h"

int choixOrientation() {
    int choix;
    do {
        printf("Dans quel sens voulez vous tourner la tuile:\n1: base(la facon dont elle est sortie)\n2: 90 degres sens horaire\n3: 180 degres\n4: 90 degres sens anti horaire\n");
        scanf("%d", &choix);
    } while (!(choix == 1 || choix == 2 || choix == 3 || choix == 4));
    return choix;
}

int choixColonne() {
    int choixcolonne;
    do {
        printf("Quelle colonne souhaitez vous decaler?\n2, 4 ou 6\n0: aucune\n");
        scanf("%d", &choixcolonne);
    } while (!(choixcolonne == 0 || choixcolonne == 2 || choixcolonne == 4 || choixcolonne == 6));
    return choixcolonne;
}

int choixLigne() {
    int choixligne;
    do {
        printf("Quelle ligne souhaitez vous decaler?\n2, 4 ou 6\n0: aucune\n");
        scanf("%d", &choixligne);
    } while (!(choixligne == 0 || choixligne == 2 || choixligne == 4 || choixligne == 6));
    return choixligne;
}

int choixHB() {
    int choixsens;
    printf("Par ou voulez vous inserer la tuile?\n1:haut\n2:bas\n");
    scanf("%d", &choixsens);
    return choixsens;
}

int choixGD() {
    int choixsens2;
    printf("Par ou voulez vous inserer la tuile?\n1:gauche\n2:droite\n");
    scanf("%d", &choixsens2);
    return choixsens2;
}

int main() {

    char plato[21][27] =
            {{'#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#'},// ligne 1
             {'#', '_', '_', ' ', '_', '_', '_', ' ', '_', '_', '_', ' ', '_', '_', '_', ' ', '_', '_', '_', ' ', '_', '_', '_', ' ', '_', '_', '#'},
             {'#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#'},

             {'#', '#', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#'},//ligne 2
             {'_', '_', '_', ' ', '_', '_', '#', ' ', '#', '_', '_', ' ', '_', '_', '_', ' ', '_', '_', '#', ' ', '_', '_', '#', ' ', '#', '_', '#'},
             {'#', '#', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '_', '#'},

             {'#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '_', '#'},//ligne 3
             {'#', '_', '_', ' ', '_', '_', '#', ' ', '#', '_', '_', ' ', '_', '_', '#', ' ', '_', '_', '_', ' ', '_', '_', '#', ' ', '_', '_', '#'},
             {'#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#'},

             {'#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#'},//ligne 4
             {'#', '_', '#', ' ', '_', '_', '#', ' ', '#', '_', '_', ' ', '_', '_', '#', ' ', '#', '_', '_', ' ', '_', '_', '#', ' ', '#', '_', '#'},
             {'#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '_', '#'},

             {'#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#'},//ligne 5
             {'#', '_', '_', ' ', '_', '_', '_', ' ', '_', '_', '_', ' ', '_', '_', '_', ' ', '_', '_', '#', ' ', '_', '_', '#', ' ', '_', '_', '#'},
             {'#', '_', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#'},

             {'#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#'},//ligne 6
             {'#', '_', '#', ' ', '_', '_', '#', ' ', '#', '_', '_', ' ', '_', '_', '#', ' ', '#', '_', '_', ' ', '_', '_', '#', ' ', '#', '_', '#'},
             {'#', '_', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#'},

             {'#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#'},//ligne 7
             {'#', '_', '_', ' ', '_', '_', '_', ' ', '_', '_', '_', ' ', '_', '_', '_', ' ', '_', '_', '_', ' ', '_', '_', '#', ' ', '_', '_', '#'},
             {'#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#'}};


    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 27; j++) {
            printf("%3c", plato[i][j]);
        }
        printf("\n");
        if (i % 3 == 2)printf("\n");//2 5 8 11 13 15
    }

    char tuileEnPlus1[3][3] = {{'#', '#', '#',},
                               {'_', '_', '#',},
                               {'#', '_', '#',}};

    int orientation, ligne, colonne, sens, sens2;
    int flag=1, temp;
    char tuileEnPlus2[3][3];
    char a,z,e,r,t,y,u,o;
    while(flag==1) {
        orientation = choixOrientation();
        if(orientation==2){
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    temp = tuileEnPlus1[i][j];
                    tuileEnPlus1[i][j] = tuileEnPlus1[3 - j - 1][i];
                    tuileEnPlus1[3 - j - 1][i] = temp;
                }
            }
        }
        else if(orientation==3){
            for (int i = 0; i < 3 / 2; i++) {
                for (int j = 0; j < 3; j++) {
                    temp = tuileEnPlus1[i][j];
                    tuileEnPlus1[i][j] = tuileEnPlus1[3 - i - 1][3 - j - 1];
                    tuileEnPlus1[3 - i - 1][3 - j - 1] = temp;
                }
            }
        }
        else if(orientation==4){
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3 / 2; j++) {
                    temp = tuileEnPlus1[i][j];
                    tuileEnPlus1[i][j] = tuileEnPlus1[i][3 - j - 1];
                    tuileEnPlus1[i][3 - j - 1] = temp;
                }
            }

            for (int i = 0; i < 3; i++) {
                for (int j = i + 1; j < 3; j++) {
                    temp = tuileEnPlus1[i][j];
                    tuileEnPlus1[i][j] = tuileEnPlus1[j][i];
                    tuileEnPlus1[j][i] = temp;
                }
            }
        }
        colonne = choixColonne();

        if (colonne == 0) {
            ligne = choixLigne();
            sens = choixGD();
            if (sens == 1) {
                if (ligne == 2) {

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus2[i][j] = plato[i + 3][j + 24];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j + 24] = plato[i + 3][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j + 20] = plato[i + 3][j + 16];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j + 16] = plato[i + 3][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j + 12] = plato[i + 3][j + 8];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j + 8] = plato[i + 3][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j + 4] = plato[i + 3][j];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j] = tuileEnPlus1[i][j];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus1[i][j] = tuileEnPlus2[i][j];
                        }
                    }

                    for (int i = 0; i < 21; i++) {
                        for (int j = 0; j < 27; j++) {
                            printf("%3c", plato[i][j]);
                        }
                        printf("\n");
                        if (i % 3 == 2)printf("\n");//2 5 8 11 13 15
                    }
                }
                else if (ligne == 4) {

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus2[i][j] = plato[i + 9][j + 24];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j + 24] = plato[i + 9][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j + 20] = plato[i + 9][j + 16];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j + 16] = plato[i + 9][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j + 12] = plato[i + 9][j + 8];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j + 8] = plato[i + 9][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j + 4] = plato[i + 9][j];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j] = tuileEnPlus1[i][j];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus1[i][j] = tuileEnPlus2[i][j];
                        }
                    }

                    for (int i = 0; i < 21; i++) {
                        for (int j = 0; j < 27; j++) {
                            printf("%3c", plato[i][j]);
                        }
                        printf("\n");
                        if (i % 3 == 2)printf("\n");//2 5 8 11 13 15
                    }
                }
                else if (ligne == 6) {

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus2[i][j] = plato[i + 15][j + 24];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j + 24] = plato[i + 15][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j + 20] = plato[i + 15][j + 16];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j + 16] = plato[i + 15][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j + 12] = plato[i + 15][j + 8];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j + 8] = plato[i + 15][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j + 4] = plato[i + 15][j];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j] = tuileEnPlus1[i][j];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus1[i][j] = tuileEnPlus2[i][j];
                        }
                    }

                    for (int i = 0; i < 21; i++) {
                        for (int j = 0; j < 27; j++) {
                            printf("%3c", plato[i][j]);
                        }
                        printf("\n");
                        if (i % 3 == 2)printf("\n");//2 5 8 11 13 15
                    }
                }
            } else if (sens == 2) {
                if (ligne == 2) {

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus2[i][j] = plato[i + 3][j];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j] = plato[i + 3][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j + 4] = plato[i + 3][j + 8];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j + 8] = plato[i + 3][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j + 12] = plato[i + 3][j + 16];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j + 16] = plato[i + 3][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j + 20] = plato[i + 3][j + 24];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j + 24] = tuileEnPlus1[i][j];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus1[i][j] = tuileEnPlus2[i][j];
                        }
                    }

                    for (int i = 0; i < 21; i++) {
                        for (int j = 0; j < 27; j++) {
                            printf("%3c", plato[i][j]);
                        }
                        printf("\n");
                        if (i % 3 == 2) printf("\n"); // 2 5 8 11 13 15
                    }
                }
                else if (ligne == 4) {


                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus2[i][j] = plato[i + 9][j];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j] = plato[i + 9][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j + 4] = plato[i + 9][j + 8];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j + 8] = plato[i + 9][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j + 12] = plato[i + 9][j + 16];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j + 16] = plato[i + 9][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j + 20] = plato[i + 9][j + 24];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j + 24] = tuileEnPlus1[i][j];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus1[i][j] = tuileEnPlus2[i][j];
                        }
                    }

                    for (int i = 0; i < 21; i++) {
                        for (int j = 0; j < 27; j++) {
                            printf("%3c", plato[i][j]);
                        }
                        printf("\n");
                        if (i % 3 == 2) printf("\n"); // 2 5 8 11 13 15
                    }
                }
                if (ligne == 6) {

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus2[i][j] = plato[i + 15][j];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j] = plato[i + 15][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j + 4] = plato[i + 15][j + 8];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j + 8] = plato[i + 15][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j + 12] = plato[i + 15][j + 16];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j + 16] = plato[i + 15][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j + 20] = plato[i + 15][j + 24];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j + 24] = tuileEnPlus1[i][j];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus1[i][j] = tuileEnPlus2[i][j];
                        }
                    }

                    for (int i = 0; i < 21; i++) {
                        for (int j = 0; j < 27; j++) {
                            printf("%3c", plato[i][j]);
                        }
                        printf("\n");
                        if (i % 3 == 2) printf("\n"); // 2 5 8 11 13 15
                    }
                }
            }
        }
        else {
            sens2 = choixHB();
            if (sens2 == 2) {
                if (colonne == 2) {

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus2[i][j] = plato[i][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i][j + 4] = plato[i + 3][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j + 4] = plato[i + 6][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 6][j + 4] = plato[i + 9][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j + 4] = plato[i + 12][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 12][j + 4] = plato[i + 15][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j + 4] = plato[i + 18][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 18][j + 4] = tuileEnPlus1[i][j];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus1[i][j] = tuileEnPlus2[i][j];
                        }
                    }

                    for (int i = 0; i < 21; i++) {
                        for (int j = 0; j < 27; j++) {
                            printf("%3c", plato[i][j]);
                        }
                        printf("\n");
                        if (i % 3 == 2)printf("\n");//2 5 8 11 13 15
                    }
                }
                else if (colonne == 4) {

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus2[i][j] = plato[i][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i][j + 12] = plato[i + 3][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j + 12] = plato[i + 6][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 6][j + 12] = plato[i + 9][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j + 12] = plato[i + 12][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 12][j + 12] = plato[i + 15][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j + 12] = plato[i + 18][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 18][j + 12] = tuileEnPlus1[i][j];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus1[i][j] = tuileEnPlus2[i][j];
                        }
                    }

                    for (int i = 0; i < 21; i++) {
                        for (int j = 0; j < 27; j++) {
                            printf("%3c", plato[i][j]);
                        }
                        printf("\n");
                        if (i % 3 == 2)printf("\n");//2 5 8 11 13 15
                    }

                }
                else if (colonne == 6) {

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus2[i][j] = plato[i][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i][j + 20] = plato[i + 3][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j + 20] = plato[i + 6][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 6][j + 20] = plato[i + 9][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j + 20] = plato[i + 12][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 12][j + 20] = plato[i + 15][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j + 20] = plato[i + 18][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 18][j + 20] = tuileEnPlus1[i][j];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus1[i][j] = tuileEnPlus2[i][j];
                        }
                    }

                    for (int i = 0; i < 21; i++) {
                        for (int j = 0; j < 27; j++) {
                            printf("%3c", plato[i][j]);
                        }
                        printf("\n");
                        if (i % 3 == 2)printf("\n");//2 5 8 11 13 15
                    }
                }
            }
            else if(sens2==1){
                if (colonne == 2) {

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus2[i][j] = plato[i+18][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i+18][j + 4] = plato[i + 15][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j + 4] = plato[i + 12][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 12][j + 4] = plato[i + 9][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j + 4] = plato[i + 6][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 6][j + 4] = plato[i + 3][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j + 4] = plato[i][j + 4];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i][j + 4] = tuileEnPlus1[i][j];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus1[i][j] = tuileEnPlus2[i][j];
                        }
                    }

                    for (int i = 0; i < 21; i++) {
                        for (int j = 0; j < 27; j++) {
                            printf("%3c", plato[i][j]);
                        }
                        printf("\n");
                        if (i % 3 == 2)printf("\n");//2 5 8 11 13 15
                    }


                } else if (colonne == 4) {

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus2[i][j] = plato[i+18][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i+18][j + 12] = plato[i + 15][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j + 12] = plato[i + 12][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 12][j + 12] = plato[i + 9][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j + 12] = plato[i + 6][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 6][j + 12] = plato[i + 3][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j + 12] = plato[i][j + 12];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i][j + 12] = tuileEnPlus1[i][j];
                        }
                    }
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus1[i][j] = tuileEnPlus2[i][j];
                        }
                    }

                    for (int i = 0; i < 21; i++) {
                        for (int j = 0; j < 27; j++) {
                            printf("%3c", plato[i][j]);
                        }
                        printf("\n");
                        if (i % 3 == 2)printf("\n");//2 5 8 11 13 15
                    }


                } else if (colonne == 6) {

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus2[i][j] = plato[i+18][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i+18][j + 20] = plato[i + 15][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 15][j + 20] = plato[i + 12][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 12][j + 20] = plato[i + 9][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 9][j + 20] = plato[i + 6][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 6][j + 20] = plato[i + 3][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i + 3][j + 20] = plato[i][j + 20];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            plato[i][j + 20] = tuileEnPlus1[i][j];
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tuileEnPlus1[i][j] = tuileEnPlus2[i][j];
                        }
                    }

                    for (int i = 0; i < 21; i++) {
                        for (int j = 0; j < 27; j++) {
                            printf("%3c", plato[i][j]);
                        }
                        printf("\n");
                        if (i % 3 == 2)printf("\n");//2 5 8 11 13 15
                    }
                }
            }
        }
        printf("continuer?\n1:oui\n2:nah\n");
        scanf("%d",&flag);
    }
    return 0;
}
