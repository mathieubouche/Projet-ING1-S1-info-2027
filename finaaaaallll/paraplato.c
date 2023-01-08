#include "biblio.h"

void creaPlato(char plato[21][27]) {
    //initialisation de toutes les tuiles coulissantes
    char tuiletreL1[3][3] = {{'#', '_', '#'},//1
                             {'#', '!', '_'},
                             {'#', '#', '#'}};

    char tuiletreL2[3][3] = {{'#', '#', '#'},//2
                             {'#', '%', '_'},
                             {'#', '_', '#'}};

    char tuiletreL3[3][3] = {{'#', '#', '#'},//3
                             {'_', '*', '#'},
                             {'#', '_', '#'}};

    char tuiletreL4[3][3] = {{'#', '_', '#'},//4
                             {'_', '~', '#'},
                             {'#', '#', '#'}};

    char tuiletreL5[3][3] = {{'#', '#', '#'},//5
                             {'_', '=', '#'},
                             {'#', '_', '#'}};

    char tuiletreL6[3][3] = {{'#', '_', '#'},//6
                             {'_', '+', '#'},
                             {'#', '#', '#'}};

    char tuileL1[3][3] = {{'#', '_', '#'},//7
                          {'#', '_', '_'},
                          {'#', '#', '#'}};

    char tuileL2[3][3] = {{'#', '#', '#'},//a
                          {'#', '_', '_'},
                          {'#', '_', '#'}};

    char tuileL3[3][3] = {{'#', '#', '#'},//z
                          {'_', '_', '#'},
                          {'#', '_', '#'}};

    char tuileL4[3][3] = {{'#', '_', '#'},//e
                          {'_', '_', '#'},
                          {'#', '#', '#'}};

    char tuileL5[3][3] = {{'#', '_', '#'},//r
                          {'#', '_', '_'},
                          {'#', '#', '#'}};

    char tuileL6[3][3] = {{'#', '_', '#'},//t
                          {'_', '_', '#'},
                          {'#', '#', '#'}};

    char tuileL7[3][3] = {{'#', '#', '#'},//y
                          {'#', '_', '_'},
                          {'#', '_', '#'}};

    char tuileL8[3][3] = {{'#', '#', '#'},//u
                          {'_', '_', '#'},
                          {'#', '_', '#'}};

    char tuileL9[3][3] = {{'#', '_', '#'},//i
                          {'_', '_', '#'},
                          {'#', '#', '#'}};

    char tuileL10[3][3] = {{'#', '#', '#'},//o
                           {'_', '_', '#'},
                           {'#', '_', '#'}};


    char tuileI1[3][3] = {{'#', '_', '#'},//p
                          {'#', '_', '#'},
                          {'#', '_', '#'}};

    char tuileI2[3][3] = {{'#', '#', '#'},//q
                          {'_', '_', '_'},
                          {'#', '#', '#'}};

    char tuileI3[3][3] = {{'#', '_', '#'},//s
                          {'#', '_', '#'},
                          {'#', '_', '#'}};

    char tuileI4[3][3] = {{'#', '#', '#'},//d
                          {'_', '_', '_'},
                          {'#', '#', '#'}};

    char tuileI5[3][3] = {{'#', '_', '#'},//f
                          {'#', '_', '#'},
                          {'#', '_', '#'}};

    char tuileI6[3][3] = {{'#', '#', '#'},//g
                          {'_', '_', '_'},
                          {'#', '#', '#'}};

    char tuileI7[3][3] = {{'#', '_', '#'},//h
                          {'#', '_', '#'},
                          {'#', '_', '#'}};

    char tuileI8[3][3] = {{'#', '#', '#'},//j
                          {'_', '_', '_'},
                          {'#', '#', '#'}};

    char tuileI9[3][3] = {{'#', '_', '#'},//k
                          {'#', '_', '#'},
                          {'#', '_', '#'}};

    char tuileI10[3][3] = {{'#', '#', '#'},//l
                           {'_', '_', '_'},
                           {'#', '#', '#'}};

    char tuileI11[3][3] = {{'#', '_', '#'},//m
                           {'#', '_', '#'},
                           {'#', '_', '#'}};

    char tuileI12[3][3] = {{'#', '#', '#'},//w
                           {'_', '_', '_'},
                           {'#', '#', '#'}};


    char tuileT1[3][3] = {{'#', '_', '#'},//x
                          {'#', '.', '_'},
                          {'#', '_', '#'}};

    char tuileT2[3][3] = {{'#', '_', '#'},//c
                          {'_', '?', '#'},
                          {'#', '_', '#'}};

    char tuileT3[3][3] = {{'#', '_', '#'},//v
                          {'_', '^', '_'},
                          {'#', '#', '#'}};

    char tuileT4[3][3] = {{'#', '#', '#'},//b
                          {'_', '$', '_'},
                          {'#', '_', '#'}};

    char tuileT5[3][3] = {{'#', '_', '#'},//n
                          {'_', '<', '_'},
                          {'#', '#', '#'}};

    char tuileT6[3][3] = {{'#', '#', '#'},// tuileEnPlus
                          {'_', '>', '_'},
                          {'#', '_', '#'}};


    srand(time(NULL));

    char tab[33] = {'a', 'z', 'e', 'r', 't', 'y', 'u', 'i', 'o',
                    'p', 'q', 's', 'd', 'f', 'g', 'h',
                    'j', 'k', 'l', 'm', '5', '6', '7',
                    'w', 'x', 'c', 'v', 'b', 'n', '1', '2', '3', '4'};

    for (int i = 32; i > 0; i--) {  //randomization des tuiles
        int j = rand() % (i + 1);
        int temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
    }

    plato[1][5] = tab[0];
    plato[1][13] = tab[1];
    plato[1][21] = tab[2];

    plato[4][1] = tab[3];
    plato[4][5] = tab[4];
    plato[4][9] = tab[5];
    plato[4][13] = tab[6];
    plato[4][17] = tab[7];
    plato[4][21] = tab[8];
    plato[4][25] = tab[9];

    plato[7][5] = tab[10];
    plato[7][13] = tab[11];
    plato[7][21] = tab[12];

    plato[10][1] = tab[13];
    plato[10][5] = tab[14];
    plato[10][9] = tab[15];
    plato[10][13] = tab[16];
    plato[10][17] = tab[17];
    plato[10][21] = tab[18];
    plato[10][25] = tab[19];

    plato[13][5] = tab[20];
    plato[13][13] = tab[21];
    plato[13][21] = tab[22];

    plato[16][1] = tab[23];
    plato[16][5] = tab[24];
    plato[16][9] = tab[25];
    plato[16][13] = tab[26];
    plato[16][17] = tab[27];
    plato[16][21] = tab[28];
    plato[16][25] = tab[29];

    plato[19][5] = tab[30];
    plato[19][13] = tab[31];
    plato[19][21] = tab[32];

    //assignation des tuiles glissantes du plateau en fonction du charactère présent sur le plateau primitif.
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 27; j++) {
            if (plato[i][j] == 'a') {
                plato[i - 1][j - 1] = tuileL1[0][0];
                plato[i][j - 1] = tuileL1[1][0];
                plato[i + 1][j - 1] = tuileL1[2][0];

                plato[i - 1][j] = tuileL1[0][1];
                plato[i][j] = tuileL1[1][1];
                plato[i + 1][j] = tuileL1[2][1];

                plato[i - 1][j + 1] = tuileL1[0][2];
                plato[i][j + 1] = tuileL1[1][2];
                plato[i + 1][j + 1] = tuileL1[2][2];

            }
            if (plato[i][j] == 'z') {
                plato[i - 1][j - 1] = tuileL2[0][0];
                plato[i][j - 1] = tuileL2[1][0];
                plato[i + 1][j - 1] = tuileL2[2][0];

                plato[i - 1][j] = tuileL2[0][1];
                plato[i][j] = tuileL2[1][1];
                plato[i + 1][j] = tuileL2[2][1];

                plato[i - 1][j + 1] = tuileL2[0][2];
                plato[i][j + 1] = tuileL2[1][2];
                plato[i + 1][j + 1] = tuileL2[2][2];

            }
            if (plato[i][j] == 'e') {
                plato[i - 1][j - 1] = tuileL3[0][0];
                plato[i][j - 1] = tuileL3[1][0];
                plato[i + 1][j - 1] = tuileL3[2][0];

                plato[i - 1][j] = tuileL3[0][1];
                plato[i][j] = tuileL3[1][1];
                plato[i + 1][j] = tuileL3[2][1];

                plato[i - 1][j + 1] = tuileL3[0][2];
                plato[i][j + 1] = tuileL3[1][2];
                plato[i + 1][j + 1] = tuileL3[2][2];

            }
            if (plato[i][j] == 'r') {
                plato[i - 1][j - 1] = tuileL4[0][0];
                plato[i][j - 1] = tuileL4[1][0];
                plato[i + 1][j - 1] = tuileL4[2][0];

                plato[i - 1][j] = tuileL4[0][1];
                plato[i][j] = tuileL4[1][1];
                plato[i + 1][j] = tuileL4[2][1];

                plato[i - 1][j + 1] = tuileL4[0][2];
                plato[i][j + 1] = tuileL4[1][2];
                plato[i + 1][j + 1] = tuileL4[2][2];

            }
            if (plato[i][j] == 't') {
                plato[i - 1][j - 1] = tuileL5[0][0];
                plato[i][j - 1] = tuileL5[1][0];
                plato[i + 1][j - 1] = tuileL5[2][0];

                plato[i - 1][j] = tuileL5[0][1];
                plato[i][j] = tuileL5[1][1];
                plato[i + 1][j] = tuileL5[2][1];

                plato[i - 1][j + 1] = tuileL5[0][2];
                plato[i][j + 1] = tuileL5[1][2];
                plato[i + 1][j + 1] = tuileL5[2][2];

            }
            if (plato[i][j] == 'y') {
                plato[i - 1][j - 1] = tuileL6[0][0];
                plato[i][j - 1] = tuileL6[1][0];
                plato[i + 1][j - 1] = tuileL6[2][0];

                plato[i - 1][j] = tuileL6[0][1];
                plato[i][j] = tuileL6[1][1];
                plato[i + 1][j] = tuileL6[2][1];

                plato[i - 1][j + 1] = tuileL6[0][2];
                plato[i][j + 1] = tuileL6[1][2];
                plato[i + 1][j + 1] = tuileL6[2][2];

            }
            if (plato[i][j] == 'u') {
                plato[i - 1][j - 1] = tuileL7[0][0];
                plato[i][j - 1] = tuileL7[1][0];
                plato[i + 1][j - 1] = tuileL7[2][0];

                plato[i - 1][j] = tuileL7[0][1];
                plato[i][j] = tuileL7[1][1];
                plato[i + 1][j] = tuileL7[2][1];

                plato[i - 1][j + 1] = tuileL7[0][2];
                plato[i][j + 1] = tuileL7[1][2];
                plato[i + 1][j + 1] = tuileL7[2][2];

            }
            if (plato[i][j] == 'i') {
                plato[i - 1][j - 1] = tuileL8[0][0];
                plato[i][j - 1] = tuileL8[1][0];
                plato[i + 1][j - 1] = tuileL8[2][0];

                plato[i - 1][j] = tuileL8[0][1];
                plato[i][j] = tuileL8[1][1];
                plato[i + 1][j] = tuileL8[2][1];

                plato[i - 1][j + 1] = tuileL8[0][2];
                plato[i][j + 1] = tuileL8[1][2];
                plato[i + 1][j + 1] = tuileL8[2][2];

            }
            if (plato[i][j] == 'o') {
                plato[i - 1][j - 1] = tuileL9[0][0];
                plato[i][j - 1] = tuileL9[1][0];
                plato[i + 1][j - 1] = tuileL9[2][0];

                plato[i - 1][j] = tuileL9[0][1];
                plato[i][j] = tuileL9[1][1];
                plato[i + 1][j] = tuileL9[2][1];

                plato[i - 1][j + 1] = tuileL9[0][2];
                plato[i][j + 1] = tuileL9[1][2];
                plato[i + 1][j + 1] = tuileL9[2][2];

            }
            if (plato[i][j] == 'p') {
                plato[i - 1][j - 1] = tuileL10[0][0];
                plato[i][j - 1] = tuileL10[1][0];
                plato[i + 1][j - 1] = tuileL10[2][0];

                plato[i - 1][j] = tuileL10[0][1];
                plato[i][j] = tuileL10[1][1];
                plato[i + 1][j] = tuileL10[2][1];

                plato[i - 1][j + 1] = tuileL10[0][2];
                plato[i][j + 1] = tuileL10[1][2];
                plato[i + 1][j + 1] = tuileL10[2][2];

            }
            if (plato[i][j] == 'q') {
                plato[i - 1][j - 1] = tuiletreL1[0][0];
                plato[i][j - 1] = tuiletreL1[1][0];
                plato[i + 1][j - 1] = tuiletreL1[2][0];

                plato[i - 1][j] = tuiletreL1[0][1];
                plato[i][j] = tuiletreL1[1][1];
                plato[i + 1][j] = tuiletreL1[2][1];

                plato[i - 1][j + 1] = tuiletreL1[0][2];
                plato[i][j + 1] = tuiletreL1[1][2];
                plato[i + 1][j + 1] = tuiletreL1[2][2];

            }
            if (plato[i][j] == 's') {
                plato[i - 1][j - 1] = tuiletreL2[0][0];
                plato[i][j - 1] = tuiletreL2[1][0];
                plato[i + 1][j - 1] = tuiletreL2[2][0];

                plato[i - 1][j] = tuiletreL2[0][1];
                plato[i][j] = tuiletreL2[1][1];
                plato[i + 1][j] = tuiletreL2[2][1];

                plato[i - 1][j + 1] = tuiletreL2[0][2];
                plato[i][j + 1] = tuiletreL2[1][2];
                plato[i + 1][j + 1] = tuiletreL2[2][2];

            }
            if (plato[i][j] == 'd') {
                plato[i - 1][j - 1] = tuiletreL3[0][0];
                plato[i][j - 1] = tuiletreL3[1][0];
                plato[i + 1][j - 1] = tuiletreL3[2][0];

                plato[i - 1][j] = tuiletreL3[0][1];
                plato[i][j] = tuiletreL3[1][1];
                plato[i + 1][j] = tuiletreL3[2][1];

                plato[i - 1][j + 1] = tuiletreL3[0][2];
                plato[i][j + 1] = tuiletreL3[1][2];
                plato[i + 1][j + 1] = tuiletreL3[2][2];

            }
            if (plato[i][j] == 'f') {
                plato[i - 1][j - 1] = tuiletreL4[0][0];
                plato[i][j - 1] = tuiletreL4[1][0];
                plato[i + 1][j - 1] = tuiletreL4[2][0];

                plato[i - 1][j] = tuiletreL4[0][1];
                plato[i][j] = tuiletreL4[1][1];
                plato[i + 1][j] = tuiletreL4[2][1];

                plato[i - 1][j + 1] = tuiletreL4[0][2];
                plato[i][j + 1] = tuiletreL4[1][2];
                plato[i + 1][j + 1] = tuiletreL4[2][2];

            }
            if (plato[i][j] == 'g') {
                plato[i - 1][j - 1] = tuiletreL5[0][0];
                plato[i][j - 1] = tuiletreL5[1][0];
                plato[i + 1][j - 1] = tuiletreL5[2][0];

                plato[i - 1][j] = tuiletreL5[0][1];
                plato[i][j] = tuiletreL5[1][1];
                plato[i + 1][j] = tuiletreL5[2][1];

                plato[i - 1][j + 1] = tuiletreL5[0][2];
                plato[i][j + 1] = tuiletreL5[1][2];
                plato[i + 1][j + 1] = tuiletreL5[2][2];

            }
            if (plato[i][j] == 'h') {
                plato[i - 1][j - 1] = tuiletreL6[0][0];
                plato[i][j - 1] = tuiletreL6[1][0];
                plato[i + 1][j - 1] = tuiletreL6[2][0];

                plato[i - 1][j] = tuiletreL6[0][1];
                plato[i][j] = tuiletreL6[1][1];
                plato[i + 1][j] = tuiletreL6[2][1];

                plato[i - 1][j + 1] = tuiletreL6[0][2];
                plato[i][j + 1] = tuiletreL6[1][2];
                plato[i + 1][j + 1] = tuiletreL6[2][2];

            }

            if (plato[i][j] == 'j') {
                plato[i - 1][j - 1] = tuileI1[0][0];
                plato[i][j - 1] = tuileI1[1][0];
                plato[i + 1][j - 1] = tuileI1[2][0];

                plato[i - 1][j] = tuileI1[0][1];
                plato[i][j] = tuileI1[1][1];
                plato[i + 1][j] = tuileI1[2][1];

                plato[i - 1][j + 1] = tuileI1[0][2];
                plato[i][j + 1] = tuileI1[1][2];
                plato[i + 1][j + 1] = tuileI1[2][2];

            }
            if (plato[i][j] == 'k') {
                plato[i - 1][j - 1] = tuileI2[0][0];
                plato[i][j - 1] = tuileI2[1][0];
                plato[i + 1][j - 1] = tuileI2[2][0];

                plato[i - 1][j] = tuileI2[0][1];
                plato[i][j] = tuileI2[1][1];
                plato[i + 1][j] = tuileI2[2][1];

                plato[i - 1][j + 1] = tuileI2[0][2];
                plato[i][j + 1] = tuileI2[1][2];
                plato[i + 1][j + 1] = tuileI2[2][2];

            }
            if (plato[i][j] == 'l') {
                plato[i - 1][j - 1] = tuileI3[0][0];
                plato[i][j - 1] = tuileI3[1][0];
                plato[i + 1][j - 1] = tuileI3[2][0];

                plato[i - 1][j] = tuileI3[0][1];
                plato[i][j] = tuileI3[1][1];
                plato[i + 1][j] = tuileI3[2][1];

                plato[i - 1][j + 1] = tuileI3[0][2];
                plato[i][j + 1] = tuileI3[1][2];
                plato[i + 1][j + 1] = tuileI3[2][2];

            }
            if (plato[i][j] == 'm') {
                plato[i - 1][j - 1] = tuileI4[0][0];
                plato[i][j - 1] = tuileI4[1][0];
                plato[i + 1][j - 1] = tuileI4[2][0];

                plato[i - 1][j] = tuileI4[0][1];
                plato[i][j] = tuileI4[1][1];
                plato[i + 1][j] = tuileI4[2][1];

                plato[i - 1][j + 1] = tuileI4[0][2];
                plato[i][j + 1] = tuileI4[1][2];
                plato[i + 1][j + 1] = tuileI4[2][2];

            }
            if (plato[i][j] == 'w') {
                plato[i - 1][j - 1] = tuileI5[0][0];
                plato[i][j - 1] = tuileI5[1][0];
                plato[i + 1][j - 1] = tuileI5[2][0];

                plato[i - 1][j] = tuileI5[0][1];
                plato[i][j] = tuileI5[1][1];
                plato[i + 1][j] = tuileI5[2][1];

                plato[i - 1][j + 1] = tuileI5[0][2];
                plato[i][j + 1] = tuileI5[1][2];
                plato[i + 1][j + 1] = tuileI5[2][2];

            }
            if (plato[i][j] == 'x') {
                plato[i - 1][j - 1] = tuileI6[0][0];
                plato[i][j - 1] = tuileI6[1][0];
                plato[i + 1][j - 1] = tuileI6[2][0];

                plato[i - 1][j] = tuileI6[0][1];
                plato[i][j] = tuileI6[1][1];
                plato[i + 1][j] = tuileI6[2][1];

                plato[i - 1][j + 1] = tuileI6[0][2];
                plato[i][j + 1] = tuileI6[1][2];
                plato[i + 1][j + 1] = tuileI6[2][2];

            }
            if (plato[i][j] == 'c') {
                plato[i - 1][j - 1] = tuileI7[0][0];
                plato[i][j - 1] = tuileI7[1][0];
                plato[i + 1][j - 1] = tuileI7[2][0];

                plato[i - 1][j] = tuileI7[0][1];
                plato[i][j] = tuileI7[1][1];
                plato[i + 1][j] = tuileI7[2][1];

                plato[i - 1][j + 1] = tuileI7[0][2];
                plato[i][j + 1] = tuileI7[1][2];
                plato[i + 1][j + 1] = tuileI7[2][2];

            }
            if (plato[i][j] == 'v') {
                plato[i - 1][j - 1] = tuileI8[0][0];
                plato[i][j - 1] = tuileI8[1][0];
                plato[i + 1][j - 1] = tuileI8[2][0];

                plato[i - 1][j] = tuileI8[0][1];
                plato[i][j] = tuileI8[1][1];
                plato[i + 1][j] = tuileI8[2][1];

                plato[i - 1][j + 1] = tuileI8[0][2];
                plato[i][j + 1] = tuileI8[1][2];
                plato[i + 1][j + 1] = tuileI8[2][2];

            }
            if (plato[i][j] == 'b') {
                plato[i - 1][j - 1] = tuileI9[0][0];
                plato[i][j - 1] = tuileI9[1][0];
                plato[i + 1][j - 1] = tuileI9[2][0];

                plato[i - 1][j] = tuileI9[0][1];
                plato[i][j] = tuileI9[1][1];
                plato[i + 1][j] = tuileI9[2][1];

                plato[i - 1][j + 1] = tuileI9[0][2];
                plato[i][j + 1] = tuileI9[1][2];
                plato[i + 1][j + 1] = tuileI9[2][2];

            }
            if (plato[i][j] == 'n') {
                plato[i - 1][j - 1] = tuileI10[0][0];
                plato[i][j - 1] = tuileI10[1][0];
                plato[i + 1][j - 1] = tuileI10[2][0];

                plato[i - 1][j] = tuileI10[0][1];
                plato[i][j] = tuileI10[1][1];
                plato[i + 1][j] = tuileI10[2][1];

                plato[i - 1][j + 1] = tuileI10[0][2];
                plato[i][j + 1] = tuileI10[1][2];
                plato[i + 1][j + 1] = tuileI10[2][2];

            }
            if (plato[i][j] == '1') {
                plato[i - 1][j - 1] = tuileI11[0][0];
                plato[i][j - 1] = tuileI11[1][0];
                plato[i + 1][j - 1] = tuileI11[2][0];

                plato[i - 1][j] = tuileI11[0][1];
                plato[i][j] = tuileI11[1][1];
                plato[i + 1][j] = tuileI11[2][1];

                plato[i - 1][j + 1] = tuileI11[0][2];
                plato[i][j + 1] = tuileI11[1][2];
                plato[i + 1][j + 1] = tuileI11[2][2];

            }
            if (plato[i][j] == '2') {
                plato[i - 1][j - 1] = tuileI12[0][0];
                plato[i][j - 1] = tuileI12[1][0];
                plato[i + 1][j - 1] = tuileI12[2][0];

                plato[i - 1][j] = tuileI12[0][1];
                plato[i][j] = tuileI12[1][1];
                plato[i + 1][j] = tuileI12[2][1];

                plato[i - 1][j + 1] = tuileI12[0][2];
                plato[i][j + 1] = tuileI12[1][2];
                plato[i + 1][j + 1] = tuileI12[2][2];

            }

            if (plato[i][j] == '3') {
                plato[i - 1][j - 1] = tuileT1[0][0];
                plato[i][j - 1] = tuileT1[1][0];
                plato[i + 1][j - 1] = tuileT1[2][0];

                plato[i - 1][j] = tuileT1[0][1];
                plato[i][j] = tuileT1[1][1];
                plato[i + 1][j] = tuileT1[2][1];

                plato[i - 1][j + 1] = tuileT1[0][2];
                plato[i][j + 1] = tuileT1[1][2];
                plato[i + 1][j + 1] = tuileT1[2][2];

            }
            if (plato[i][j] == '4') {
                plato[i - 1][j - 1] = tuileT2[0][0];
                plato[i][j - 1] = tuileT2[1][0];
                plato[i + 1][j - 1] = tuileT2[2][0];

                plato[i - 1][j] = tuileT2[0][1];
                plato[i][j] = tuileT2[1][1];
                plato[i + 1][j] = tuileT2[2][1];

                plato[i - 1][j + 1] = tuileT2[0][2];
                plato[i][j + 1] = tuileT2[1][2];
                plato[i + 1][j + 1] = tuileT2[2][2];

            }
            if (plato[i][j] == '5') {
                plato[i - 1][j - 1] = tuileT3[0][0];
                plato[i][j - 1] = tuileT3[1][0];
                plato[i + 1][j - 1] = tuileT3[2][0];

                plato[i - 1][j] = tuileT3[0][1];
                plato[i][j] = tuileT3[1][1];
                plato[i + 1][j] = tuileT3[2][1];

                plato[i - 1][j + 1] = tuileT3[0][2];
                plato[i][j + 1] = tuileT3[1][2];
                plato[i + 1][j + 1] = tuileT3[2][2];

            }
            if (plato[i][j] == '6') {
                plato[i - 1][j - 1] = tuileT4[0][0];
                plato[i][j - 1] = tuileT4[1][0];
                plato[i + 1][j - 1] = tuileT4[2][0];

                plato[i - 1][j] = tuileT4[0][1];
                plato[i][j] = tuileT4[1][1];
                plato[i + 1][j] = tuileT4[2][1];

                plato[i - 1][j + 1] = tuileT4[0][2];
                plato[i][j + 1] = tuileT4[1][2];
                plato[i + 1][j + 1] = tuileT4[2][2];

            }
            if (plato[i][j] == '7') {
                plato[i - 1][j - 1] = tuileT5[0][0];
                plato[i][j - 1] = tuileT5[1][0];
                plato[i + 1][j - 1] = tuileT5[2][0];

                plato[i - 1][j] = tuileT5[0][1];
                plato[i][j] = tuileT5[1][1];
                plato[i + 1][j] = tuileT5[2][1];

                plato[i - 1][j + 1] = tuileT5[0][2];
                plato[i][j + 1] = tuileT5[1][2];
                plato[i + 1][j + 1] = tuileT5[2][2];

            }


        }
    }
};
void modiplato(char plato[21][27], char tuileEntrante[3][3], int *x, int *yp, int *x2, int *y2, int *x3, int *y3, int *x4,
               int *y4) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%3c", tuileEntrante[i][j]);
        }
        printf("\n");
    }

    int orientation, ligne, colonne, sens, sens2;
    int temp;
    char tuileSortante[3][3];
    char a, z, e, r, t, y, u, o;

    orientation = choixOrientation();
    //orientation 90° dans le sens horaire
    if (orientation == 2) {
        a = tuileEntrante[0][0];
        z = tuileEntrante[0][1];
        e = tuileEntrante[0][2];
        r = tuileEntrante[1][2];
        t = tuileEntrante[2][2];
        y = tuileEntrante[2][1];
        u = tuileEntrante[2][0];
        o = tuileEntrante[1][0];

        tuileEntrante[0][0] = u;
        tuileEntrante[0][1] = o;
        tuileEntrante[0][2] = a;
        tuileEntrante[1][2] = z;
        tuileEntrante[2][2] = e;
        tuileEntrante[2][1] = r;
        tuileEntrante[2][0] = t;
        tuileEntrante[1][0] = y;
    }
        //orientation 180°
    else if (orientation == 3) {
        a = tuileEntrante[0][0];
        z = tuileEntrante[0][1];
        e = tuileEntrante[0][2];
        r = tuileEntrante[1][2];
        t = tuileEntrante[2][2];
        y = tuileEntrante[2][1];
        u = tuileEntrante[2][0];
        o = tuileEntrante[1][0];

        tuileEntrante[0][0] = t;
        tuileEntrante[0][1] = y;
        tuileEntrante[0][2] = u;
        tuileEntrante[1][2] = o;
        tuileEntrante[2][2] = a;
        tuileEntrante[2][1] = z;
        tuileEntrante[2][0] = e;
        tuileEntrante[1][0] = r;

    }
        //orientation 90° dans le sens anti horaire
    else if (orientation == 4) {
        a = tuileEntrante[0][0];
        z = tuileEntrante[0][1];
        e = tuileEntrante[0][2];
        r = tuileEntrante[1][2];
        t = tuileEntrante[2][2];
        y = tuileEntrante[2][1];
        u = tuileEntrante[2][0];
        o = tuileEntrante[1][0];

        tuileEntrante[0][0] = e;
        tuileEntrante[0][1] = r;
        tuileEntrante[0][2] = t;
        tuileEntrante[1][2] = y;
        tuileEntrante[2][2] = u;
        tuileEntrante[2][1] = o;
        tuileEntrante[2][0] = a;
        tuileEntrante[1][0] = z;
    }
    colonne = choixColonne();
    //deplacement des lignes
    if (colonne == 0) {
        ligne = choixLigne();
        sens = choixGD();
        if (sens == 1) {
            //deplacement de la ligne 2
            if (ligne == 2) {

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileSortante[i][j] = plato[i + 3][j + 24];
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
                        plato[i + 3][j] = tuileEntrante[i][j];
                    }
                }

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileEntrante[i][j] = tuileSortante[i][j];
                    }
                }
            }
                //deplacement de la ligne 4
            else if (ligne == 4) {

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileSortante[i][j] = plato[i + 9][j + 24];
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
                        plato[i + 9][j] = tuileEntrante[i][j];
                    }
                }

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileEntrante[i][j] = tuileSortante[i][j];
                    }
                }
            }
                //deplacement ligne 6
            else if (ligne == 6) {

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileSortante[i][j] = plato[i + 15][j + 24];
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
                        plato[i + 15][j] = tuileEntrante[i][j];
                    }
                }

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileEntrante[i][j] = tuileSortante[i][j];
                    }
                }
            }
        } else if (sens == 2) {
            if (ligne == 2) {

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileSortante[i][j] = plato[i + 3][j];
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
                        plato[i + 3][j + 24] = tuileEntrante[i][j];
                    }
                }

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileEntrante[i][j] = tuileSortante[i][j];
                    }
                }


            } else if (ligne == 4) {


                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileSortante[i][j] = plato[i + 9][j];
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
                        plato[i + 9][j + 24] = tuileEntrante[i][j];
                    }
                }

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileEntrante[i][j] = tuileSortante[i][j];
                    }
                }
            } else if (ligne == 6) {

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileSortante[i][j] = plato[i + 15][j];
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
                        plato[i + 15][j + 24] = tuileEntrante[i][j];
                    }
                }

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileEntrante[i][j] = tuileSortante[i][j];
                    }
                }
            }
        }
    } else {
        sens2 = choixHB();
        if (sens2 == 2) {
            if (colonne == 2) {

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileSortante[i][j] = plato[i][j + 4];
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
                        plato[i + 18][j + 4] = tuileEntrante[i][j];
                    }
                }

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileEntrante[i][j] = tuileSortante[i][j];
                    }
                }
            } else if (colonne == 4) {

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileSortante[i][j] = plato[i][j + 12];
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
                        plato[i + 18][j + 12] = tuileEntrante[i][j];
                    }
                }

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileEntrante[i][j] = tuileSortante[i][j];
                    }
                }
            } else if (colonne == 6) {

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileSortante[i][j] = plato[i][j + 20];
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
                        plato[i + 18][j + 20] = tuileEntrante[i][j];
                    }
                }

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileEntrante[i][j] = tuileSortante[i][j];
                    }
                }


            }
        } else if (sens2 == 1) {
            if (colonne == 2) {

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileSortante[i][j] = plato[i + 18][j + 4];
                    }
                }

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        plato[i + 18][j + 4] = plato[i + 15][j + 4];
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
                        plato[i][j + 4] = tuileEntrante[i][j];
                    }
                }

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileEntrante[i][j] = tuileSortante[i][j];
                    }
                }
            } else if (colonne == 4) {

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileSortante[i][j] = plato[i + 18][j + 12];
                    }
                }

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        plato[i + 18][j + 12] = plato[i + 15][j + 12];
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
                        plato[i][j + 12] = tuileEntrante[i][j];
                    }
                }
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileEntrante[i][j] = tuileSortante[i][j];
                    }
                }
            } else if (colonne == 6) {

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileSortante[i][j] = plato[i + 18][j + 20];
                    }
                }

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        plato[i + 18][j + 20] = plato[i + 15][j + 20];
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
                        plato[i][j + 20] = tuileEntrante[i][j];
                    }
                }

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tuileEntrante[i][j] = tuileSortante[i][j];
                    }
                }
            }
        }
    }
    //changement des coordonnées de A B C et D si ils sont poussés par un coulissement du plateau
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 27; j++) {
            if (plato[i][j] == 'A') {
                *yp = i;
                *x = j;
            } else if (plato[i][j] == 'B') {
                *y2 = i;
                *x2 = j;
            } else if (plato[i][j] == 'C') {
                *y3 = i;
                *x3 = j;
            } else if (plato[i][j] == 'D') {
                *y4 = i;
                *x4 = j;
            }
        }
    }
};
//permet de changer les coordonnées de A,B,C,D lorsqu'ils sortent du plateau
void changcoo(int *x, int *y) {


    if (*x == 1) {
        *x = 25;
    } else if (*x == 25) {
        *x = 1;
    }
    if (*y == 19) {
        *y = 1;
    } else if (*y == 1) {
        *y = 19;

    }
};

//detecter que le pion a été éjecté du plateau
void tp(char tuile[3][3], int *x, int *y, int *x2, int *y2, int *x3, int *y3, int *x4, int *y4, int *erreur, int *erreur2,
        int *erreur3, int *erreur4, char *tp, char *tp2, char *tp3, char *tp4, char plato[21][27]) {
    int a = *x, b = *y;
    char pion;
    if (tuile[1][1] == 'A') {
        changcoo(x, y);
        tuile[1][1] = *tp;
        *tp = plato[*y][*x];
        *erreur = 1;
    }

    if (tuile[1][1] == 'B') {
        changcoo(x2, y2);
        tuile[1][1] = *tp2;
        *tp2 = plato[*y2][*x2];
        *erreur2 = 1;
    }
    if (tuile[1][1] == 'C') {
        changcoo(x3, y3);
        tuile[1][1] = *tp3;
        *tp3 = plato[*y3][*x3];
        *erreur3 = 1;
    }
    if (tuile[1][1] == 'D') {
        changcoo(x4, y4);
        tuile[1][1] = *tp4;
        *tp4 = plato[*y4][*x4];
        *erreur4 = 1;
    }
};