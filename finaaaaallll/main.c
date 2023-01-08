#include "biblio.h"

//detecteur de tresor et compteur de point
int detectionTresors(int *nbjoueur, char mains[4][24], char *tp, char *tp2, char *tp3, char *tp4, int *etp, int *etp2,
                     int *etp3, int *etp4, int *cptp, int *cptp2, int *cptp3, int *cptp4, int *parti) {
    //procédure pr le joueur 1 qui affiche le nombre de trésors restant a trouver
    if (*nbjoueur >= 1) {
        for (int i = 0;
             i < NOM_CARTES / (*nbjoueur); i++) { //on compare la main du joueur avec la case sur laquelle il se trouve
            if (*tp == mains[0][i]) {                       //si le pion se trouve sur un trésors qui lui appartient
                *cptp = *cptp -
                        1;                            //compteur de trésors diminue (*cptp-- n'a pas l'air de marcher)
                *tp = '_';                                  // remplace l emplacement du trésors par un chemin normal
                mains[0][i] = 'X';                          // retire le tresors a recupérer de la main
                printf("Il reste %d tresors a trouver pour le joueur 1\n", *cptp);
                *etp = 1;                                     //signal que le joueur vient de récupérer un trésors
            }
        }
        printf("\n");
    }
    //procédure pr le joueur 2 qui affiche le nombre de trésors restant a trouver
    if (*nbjoueur >= 2) {
        for (int i = 0; i < NOM_CARTES / (*nbjoueur); i++) {
            if (*tp2 == mains[1][i]) {
                *cptp2 = *cptp2 - 1;
                *tp2 = '_';
                mains[1][i] = 'X';
                printf("Il reste %d tresors a trouver pour le joueur 2\n", *cptp2);
                *etp2 = 1;
            }
        }
        printf("\n");
    }
    //procédure pr le joueur 3 qui affiche le nombre de trésors restant a trouver
    if (*nbjoueur >= 3) {
        for (int i = 0; i < NOM_CARTES / (*nbjoueur); i++) {
            if (*tp3 == mains[2][i]) {
                *cptp3 = *cptp3 - 1;
                *tp3 = '_';
                mains[2][i] = 'X';
                printf("Il reste %d tresors a trouver pour le joueur 3\n", *cptp3);
                *etp3 = 1;
            }
        }
        printf("\n");
    }
    //procédure pr le joueur 4 qui affiche le nombre de trésors restant a trouver
    if (*nbjoueur >= 4) {
        for (int i = 0; i < NOM_CARTES / (*nbjoueur); i++) {
            if (*tp4 == mains[3][i]) {
                *cptp4 = *cptp4;
                *tp4 = '_';
                mains[3][i] = 'X';
                printf("Il reste %d tresors a trouver pour le joueur 4\n", *cptp4);
                *etp4 = 1;
            }
        }
        printf("\n");
    }
    //si le compteur de trésors arrive à 0 cela signifie que le joueur à récupérer tout ses trésors
    if (*cptp == 0) {
        printf("Le joueur 1 a gagner!!! :D\n");// message de victoire
        *parti = 0;
        return 0;
    }
    if (*cptp2 == 0) {
        printf("Le joueur 2 a gagner!!! :D\n");
        *parti = 0;
        return 0;
    }
    if (*cptp3 == 0) {
        printf("Le joueur 3 a gagner!!! :D\n");
        *parti = 0;
        return 0;
    }
    if (*cptp4 == 0) {
        printf("Le joueur 4 a gagner!!! :D\n");
        *parti = 0;
        return 0;
    }
}

//deplacement des pions
int menudeplacements(int *choix, int *x, int *y, int *erreur /*int* tab[27][27]*/) {
    int direction;
    if (*choix == 1) {// signifie que le joueur à décidé d'aller à droite
        printf("de combien voulez vous avancer?\n");// demande au joueur
        scanf("%d", &direction);//récupération du nombre de cases dont le joueur veut se déplacer
        *x = *x + (direction *
                   4);// déplacement dans le tableau vers la droite mutlplication par 4 car cela permet de mettre le pions au milieu des cases
    }

    if (*choix == 2) {
        printf("de combien voulez vous avancer?\n");
        scanf("%d", &direction);
        direction = direction *
                    (-4);// déplacement dans le tableau vers la gauche mutlplication par 4 car cela permet de mettre le pions au milieu des cases
        *x = *x + direction;
    }
    if (*choix == 3) {
        printf("de combien voulez vous avancer?\n");
        scanf("%d", &direction);
        direction = direction *
                    (-3);// déplacement vers le haut multplication par -3 car cela permet de mettre le piont au milieu de la case
        *y = *y + direction;
    }
    if (*choix == 4) {
        printf("de combien voulez vous avancer?\n");
        scanf("%d", &direction);
        *y = *y + (direction *
                   3);// déplacement vers le bas multplication par 3 car cela permet de mettre le piont au milieu de la case

    }

    if (*x > 27) {
        *x = 25;
        *erreur = 1;
    }
    if (*x < 0) {
        *x = 1;
        *erreur = 1;
    }
    if (*y > 20) {
        *y = 19;
        *erreur = 1;
    }
    if (*y < 0) {
        *y = 1;
        *erreur = 1;
    }
}

int menuprincipal(int *nbjoueurs, int *parti, int *parti2) {
    int choix;


    printf("1: nouvelle partie \n2: sauvegarder\n3: charger une partie\n"
           "4: afficher les regles et credits\n5: quitter\n");

    scanf("%d", &choix);

    while (choix < 1 || choix > 5) {
        printf("veuillez entrer un choix existant\n");
        scanf("%d", &choix);
    }
    if (choix == 1) {
        printf("nouvelle partie\n");
        printf("veuillez entrer le nombre de joueurs\n");
        scanf("%d", nbjoueurs);
        while (*nbjoueurs < 1 || *nbjoueurs > 4) {
            printf("veuillez entrer le nombre de joueurs\n");
            scanf("%d", nbjoueurs);
        }

        *parti = 1;


    }
    if (choix == 2) {
        printf("sauvegarder");

    }
    if (choix == 3) {
        printf("charger partie");


    }
    if (choix == 4) {
        printf("Pour jouer au Labyrinthe, il vous faut :\n"
               "1 a 4 joueurs.\n"
               "Le plateau de jeu.\n"
               "Les 24 cartes «tresor».\n"
               "Les 34 cartons carres «labyrinthe».\n"
               "Les 4 pions de couleurs differentes.\n"
               "Comment jouer au Labyrinthe :\n"
               "Dans un premier temps, il faut mettre en place le plateau de jeu.\n"
               "Pour ce faire, il vous faut melanger les cartons «labyrinthe» qui represente les couloirs du labyrinthe vu du dessus.\n"
               "Ensuite, il faut les placer sur les emplacements libres du plateau de jeu de manière à créer un labyrinthe aléatoire. \n"
               "Une fois le labyrinthe cree il doit vous rester une carte «labyrinthe». Cette carte servira a deplacer les couloirs en les faisant coulisser.\n"
               "Avant de commencer la partie, les joueurs doivent se distribuer toutes les cartes «tresor», face cachee, de façon à ce qu ils aient tous le meme \n"
               "nombre de cartes. Chaque joueur doit empiler ses cartes devant lui sans les regarder.  Chaque joueur choisit son pion et le place sur la case \n"
               "correspondante a la couleur de celui-ci (dans les 4 coins du plateau de jeu).\n"
               "C est le joueur le plus jeune qui commence a jouer et la partie se poursuit dans le sens des aiguilles d une montre. Chaque joueur regarde la carte «tresor»\n"
               "situee en haut de sa pile sans la devoiler aux autres. Il faut savoir que le tour d un joueur se deroule toujours de la meme maniere.\n"
               "En effet, le joueur doit toujours deplacer une rangee ou une colonne en premier, en introduisant la carte «Labyrinthe» supplementaire. Ensuite il peut \n"
               "deplacer son pion pour essayer d atteindre son objectif «tresor». Notez qu un joueur est toujours oblige de modifier le labyrinthe avant de pouvoir deplacer \n"
               "son pion et ce meme si  son «tresor» est accessible directement.\n"
               "Le tour d un joueur au Labyrinthe :\n"
               "1 – La modification des couloirs du Labyrinthe :\n"
               "Il y a 12 fleches sur les bordures du plateau de jeu. Elles indiquent les colonnes et les rangees qui peuvent être modifiees en inserant \n"
               "la carte «labyrinthe»\n"
               "supplementaire. C est le joueur qui choisit la colonne ou la rangee qu il souhaite modifier lorsque vient son tour. Il suffit de pousser \n"
               "la colonne ou la rangee à l aide de la carte supplementaire vers l interieur du plateau.  Une nouvelle carte est donc expulsee de l autre cote du plateau.\n"
               "Cette nouvelle carte «labyrinthe» reste sur le cote du plateau jusqu a temps qu’elle soit reintroduite par le joueur suivant.\n"
               "ATTENTION : si un pion est expulse hors du plateau lors d un mouvement d une colonne ou d’une rangee il est replace à l oppose de celle-ci.\n"
               " Cependant, ceci ne constitue pas un mouvement du pion.\n"
               "2 – Le deplacement du joueur :\n"
               "\n"
               "Une fois que le joueur a modifie le labyrinthe, il peut se deplacer. Le joueur peut deplacer son pion librement aussi loin qu il le souhaite mais il \n"
               "ne peut pas, bien sur, traverser les murs. Il est possible de s arreter sur une case occupee par un autre joueur. S il le veut,  il n’est pas oblige\n"
               "d avancer et peut rester sur place.\n"
               "\n"
               "Si le joueur n a pas son tresor (dessin de la carte «tresor») il peut placer son pion de maniere a se rapprocher au plus pres de son objectif \n"
               "pour le prochain tour. Si le joueur atteint son tresor il se defausse de sa carte et peut directement regarder son prochain objectif en prenant la \n"
               "carte suivante de sa pile cartes «tresor»\n"
               "\n"
               "C est alors au joueur de suivant de jouer. Il procedera de la meme maniere en modifiant le labyrinthe puis en deplaçant son pion vers son objectif «tresor».\n"
               "\n"
               "Comment gagner au Labyrinthe :\n"
               "Pour remporter une partie au Labyrinthe, le joueur doit avoir decouvert tous ses tresors et doit revenir a son point de depart. Une fois de retour\n"
               "a son point de depart il est declare vainqueur et la partie est terminee.\n"
               "\n"
               "Credits \n"
               "https://www.regles-de-jeux.com/regle-du-labyrinthe/\n"
               "Elias Douady \n"
               "Kimi Ho\n"
               "Pierre Tailhades\n"
               "Mathieu Bouche");
        menuprincipal(nbjoueurs, parti, parti2);


    }
    if (choix == 5) {
        *parti2 = 0;
    }

}

void plateau(int *nbjoueurs, int *parti) {
    char mains[4][NOM_CARTES];// cartes à jouer
    int a;
    int i;
    int xt = 25, yt = 19, xt1 = 1, yt1 = 1, xt2 = 25, yt2 = 1, xt3 = 1, yt3 = 19; //coordonnées qui remplacent ce sur quoi les pions ont marché
    int *choix = &a;
    //coordonnées des pions (a la base ici)
    int x = 1;
    int y = 1;
    int x2 = 25;
    int y2 = 1;
    int x3 = 1;
    int y3 = 19;
    int x4 = 25;
    int y4 = 19;
    int p;
    int *pt = &p;
    //pointeur coordonnées des pions
    int *xp = &x;
    int *yp = &y;
    int *xp2 = &x2;
    int *yp2 = &y2;
    int *xp3 = &x3;
    int *yp3 = &y3;
    int *xp4 = &x4;
    int *yp4 = &y4;

    int cpt, cpt2, cpt3, cpt4;
    int *cptp = &cpt;
    int *cptp2 = &cpt2;
    int *cptp3 = &cpt3;
    int *cptp4 = &cpt4;
    //initialisation du nombre de carte a trouver
    *cptp = -10;
    *cptp2 = -10;
    *cptp3 = -10;
    *cptp4 = -10;

    //initialisation du nombre exact de carte a trouver en fonction du nombre de joueur
    if (*nbjoueurs == 1)
        cpt = 24;
    if (*nbjoueurs == 2) {
        *cptp = 12;
        *cptp2 = 12;
    }
    if (*nbjoueurs == 3) {
        *cptp = 8;
        *cptp2 = 8;
        *cptp3 = 8;
    }
    if (*nbjoueurs == 4) {
        *cptp = 6;
        *cptp2 = 6;
        *cptp3 = 6;
        *cptp4 = 6;
    }

    if (*nbjoueurs < 4) {
        *yp4 = 0;
        *xp4 = 0;
    }
    if (*nbjoueurs < 3) {
        *yp3 = 0;
        *xp3 = 0;
    }
    if (*nbjoueurs < 2) {
        *yp2 = 0;
        *xp2 = 0;
    }


    int flag = 1;
    int etattour = 1;
    int erreur = 0, erreur2 = 0, erreur3 = 0, erreur4 = 0;
    int *erreurp2 = &erreur2;
    int *erreurp3 = &erreur3;
    int *erreurp4 = &erreur4;
    int *erreurp = &erreur;
    *erreurp = 0;
    *erreurp2 = 0;
    *erreurp3 = 0;
    *erreurp4 = 0;

    char t;
    char tt, t2, tt2, t3, tt3, t4, tt4;
    char *tp1 = &t;
    char *tp2 = &t2;
    char *tp3 = &t3;
    char *tp4 = &t4;
    *tp1 = '_', *tp2 = '_', *tp3 = '_', *tp4 = '_';
    int et, et2, et3, et4;
    int *etp = &et;
    int *etp2 = &et2;
    int *etp3 = &et3;
    int *etp4 = &et4;
    *etp = 0;
    *etp2 = 0;
    *etp3 = 0;
    *etp4 = 0;


    printf(" C est parti pour %d joueurs !\n", *nbjoueurs);
    char plato[21][27] =//initialisation tableau
            {{'#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#'},// ligne 1
             {'#', '_', '_', ' ', '_', '_', '_', ' ', '_', '&', '_', ' ', '_', '?', '_', ' ', '_', '|', '_', ' ', '_', '_', '_', ' ', '_', '_', '#'},
             {'#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#'},

             {'#', '#', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#'},//ligne 2
             {'_', '_', '_', ' ', '_', '}', '#', ' ', '#', '/', '_', ' ', '_', '_', '_', ' ', '_', '_', '#', ' ', '_', '_', '#', ' ', '#', '_', '#'},
             {'#', '#', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '_', '#'},

             {'#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '_', '#'},//ligne 3
             {'#', '[', '_', ' ', '_', '[', '#', ' ', '#', ']', '_', ' ', '_', '.', '#', ' ', '_', ':', '_', ' ', '_', '$', '#', ' ', '_', '@', '#'},
             {'#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#'},

             {'#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#'},//ligne 4
             {'#', '_', '#', ' ', '_', '_', '#', ' ', '#', ']', '_', ' ', '_', '_', '#', ' ', '#', '_', '_', ' ', '_', '_', '#', ' ', '#', '_', '#'},
             {'#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '_', '#'},

             {'#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#'},//ligne 5
             {'#', '}', '_', ' ', '_', '_', '_', ' ', '_', ';', '_', ' ', '_', ';', '_', ' ', '_', '/', '#', ' ', '_', '<', '#', ' ', '_', '(', '#'},
             {'#', '_', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#'},

             {'#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#'},//ligne 6
             {'#', '_', '#', ' ', '_', '^', '#', ' ', '#', '_', '_', ' ', '_', '_', '#', ' ', '#', ':', '_', ' ', '_', '_', '#', ' ', '#', '_', '#'},
             {'#', '_', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#'},

             {'#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '#', '#', ' ', '#', '_', '#', ' ', '#', '_', '#', ' ', '#', '_', '#'},//ligne 7
             {'#', '_', '_', ' ', '_', '_', '_', ' ', '_', '{', '_', ' ', '_', '_', '_', ' ', '_', ')', '_', ' ', '_', '>', '#', ' ', '_', '_', '#'},
             {'#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#'}};


    char tuileEnPlus[3][3] = {{'#', '#', '#'},//tuile suplémentaire
                              {'_', '>', '_'},
                              {'#', '_', '#'}};


    creaPlato(plato);
    distributionCartes(nbjoueurs, mains);
    plato[*yp][*xp] = 'A';
    plato[*yp2][*xp2] = 'B';
    plato[*yp3][*xp3] = 'C';
    plato[*yp4][*xp4] = 'D';


    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 27; j++) {
            printf("%3c", plato[i][j]);

        }
        printf("\n");
        if (i % 3 == 2)printf("\n");//2 5 8 11 13 15
    }

    while (*parti == 1) {
        if (etattour == 1) {
            *erreurp = 0;
            printf("tour joueur 1\n");
            printf("Main du joueur 1: "); // soit on enleve le print des cartes soit on ne l'enleve pas
            for (int j = 0; j < NOM_CARTES / (*nbjoueurs); j++) {
                printf("%c ", mains[0][j]);
            }
            printf("\n");
            if (flag == 1) {
                modiplato(plato, tuileEnPlus, xp, yp, xp2, yp2, xp3, yp3, xp4, yp4);
                tp(tuileEnPlus, xp, yp, xp2, yp2, xp3, yp3, xp4, yp4, erreurp, erreurp2, erreurp3, erreurp4, tp1, tp2,
                   tp3, tp4, plato);
                detectionTresors(nbjoueurs, mains, tp1, tp2, tp3, tp4, etp, etp2, etp3, etp4, cptp, cptp2, cptp3, cptp4,
                                 parti);
                plato[*yp][*xp] = 'A';
                plato[*yp2][*xp2] = 'B';
                plato[*yp3][*xp3] = 'C';
                plato[*yp4][*xp4] = 'D';
                // erreur=1;

                for (int i = 0; i < 21; i++) {
                    for (int j = 0; j < 27; j++) {
                        printf("%3c", plato[i][j]);

                    }
                    printf("\n");
                    if (i % 3 == 2)printf("\n");//2 5 8 11 13 15
                }
                flag = 0;
            }
            printf("Deplacez-vous :\n 1: Droite\n 2: Gauche\n 3: Haut\n 4: Bas\n 5: Tour suivant\n 6: Retour au menu\n");
            scanf("%d", choix);
            while (*choix <= 0 || *choix > 6) {
                printf("Deplacez-vous :\n 1: Droite\n 2: Gauche\n 3: Haut\n 4: Bas\n 5: Tour suivant\n 6: Retour au menu\n");
                scanf("%d", choix);
            }
            xt1 = *xp;
            yt1 = *yp;
            menudeplacements(choix, xp, yp, erreurp);


            if (*choix == 2) {
                for (i = xt1; i > *xp; i--) {
                    if (plato[yt1][i] == '#') {
                        printf("ca va pas\n");
                        *xp = xt1;
                        *erreurp = 1;
                    }
                }
            }
            if (*choix == 1) {
                for (i = xt1; i < *xp; i++) {
                    if (plato[yt1][i] == '#') {
                        printf("ca va pas\n");
                        *xp = xt1;
                        *erreurp = 1;
                    }
                }
            }
            if (*choix == 3) {
                for (i = yt1; i > *yp; i--) {
                    if (plato[i][xt1] == '#') {
                        printf("ca va pas\n");
                        *yp = yt1;
                        *erreurp = 1;
                    }
                }
            }
            if (*choix == 4) {
                for (i = yt1; i < *yp; i++) {
                    if (plato[i][xt1] == '#') {
                        printf("ca va pas\n");
                        *yp = yt1;
                        *erreurp = 1;
                    }
                }
            }
            if (*yp == *yp2 && *xp == *xp2 || *yp == *yp3 && *xp == *xp3 || *yp == *yp4 && *xp == *xp4) {
                printf("ca ne va pas\n");
                *yp = yt1;
                *xp = xt1;
                *erreurp = 1;
            }


            if (*choix == 5) {
                printf("Tour suivant\n");
                etattour++;
                flag = 1;
                *erreurp = 1;
            }
            if (*choix == 6) {
                printf("Retour au menu\n");
                *parti = 0;
            }
            if (*nbjoueurs == 1 && etattour > 1) {

                etattour = 1;

            }


        }
        if (etattour == 2) {
            printf("tour joueur 2\n");
            printf("Main du joueur 2: "); // soit on enleve le print des cartes soit on ne l'enleve pas
            for (int j = 0; j < NOM_CARTES / (*nbjoueurs); j++) {
                printf("%c ", mains[1][j]);
            }
            printf("\n");
            *erreurp2 = 0;
            if (flag == 1) {
                modiplato(plato, tuileEnPlus, xp, yp, xp2, yp2, xp3, yp3, xp4, yp4);
                tp(tuileEnPlus, xp, yp, xp2, yp2, xp3, yp3, xp4, yp4, erreurp, erreurp2, erreurp3, erreurp4, tp1, tp2,
                   tp3, tp4, plato);
                detectionTresors(nbjoueurs, mains, tp1, tp2, tp3, tp4, etp, etp2, etp3, etp4, cptp, cptp2, cptp3, cptp4,
                                 parti);
                plato[*yp][*xp] = 'A';
                plato[*yp2][*xp2] = 'B';
                plato[*yp3][*xp3] = 'C';
                plato[*yp4][*xp4] = 'D';
                for (int i = 0; i < 21; i++) {
                    for (int j = 0; j < 27; j++) {
                        printf("%3c", plato[i][j]);

                    }
                    printf("\n");
                    if (i % 3 == 2)printf("\n");//2 5 8 11 13 15
                }

                flag = 0;
            }
            printf("Deplacez-vous :\n 1: Droite\n 2: Gauche\n 3: Haut\n 4: Bas\n 5: Tour suivant\n 6: Retour au menu\n");
            scanf("%d", choix);
            while (*choix <= 0 || *choix > 6) {
                printf("Deplacez-vous :\n 1: Droite\n 2: Gauche\n 3: Haut\n 4: Bas\n 5: Tour suivant\n 6: Retour au menu\n");
                scanf("%d", choix);
            }
            // deplacementTresors()
            xt2 = *xp2;
            yt2 = *yp2;
            menudeplacements(choix, xp2, yp2, erreurp2);
            if (*choix == 2) {
                for (i = xt2; i > *xp2; i--) {
                    if (plato[yt2][i] == '#') {
                        printf("ca va pas\n");
                        *xp2 = xt2;
                        *erreurp2 = 1;
                    }
                }
            }
            if (*choix == 1) {
                for (i = xt2; i < *xp2; i++) {
                    if (plato[yt2][i] == '#') {
                        printf("ca va pas\n");
                        *xp2 = xt2;
                        *erreurp2 = 1;
                    }
                }
            }
            if (*choix == 3) {
                for (i = yt2; i > *yp2; i--) {
                    if (plato[i][xt2] == '#') {
                        printf("ca va pas\n");
                        *yp2 = yt2;
                        *erreurp2 = 1;
                    }
                }
            }
            if (*choix == 4) {
                for (i = yt2; i < *yp2; i++) {
                    if (plato[i][xt2] == '#') {
                        printf("ca va pas\n");
                        *yp2 = yt2;
                        *erreurp2 = 1;
                    }
                }
            }
            if (*yp2 == *yp && *xp2 == *xp || *yp2 == *yp3 && *xp2 == *xp3 || *yp2 == *yp4 && *xp2 == *xp4) {
                printf("ca ne va pas\n");
                *yp2 = yt2;
                *xp2 = xt2;
                *erreurp2 = 1;
            }
            if (*choix == 5) {
                printf("Tour suivant\n");
                etattour++;
                flag = 1;
                *erreurp2 = 1;
            }
            if (*choix == 6) {
                printf("Retour au menu");
                *parti = 0;
            }


        }
        if (*nbjoueurs == 2 && etattour > 2) {

            etattour = 1;

        }

        if (etattour == 3) {
            printf("tour joueur 3\n");
            printf("Main du joueur 3: "); // soit on enleve le print des cartes soit on ne l'enleve pas
            for (int j = 0; j < NOM_CARTES / (*nbjoueurs); j++) {
                printf("%c ", mains[2][j]);
            }
            printf("\n ");
            *erreurp3 = 0;
            if (flag == 1) {
                modiplato(plato, tuileEnPlus, xp, yp, xp2, yp2, xp3, yp3, xp4, yp4);
                tp(tuileEnPlus, xp, yp, xp2, yp2, xp3, yp3, xp4, yp4, erreurp, erreurp2, erreurp3, erreurp4, tp1, tp2,
                   tp3, tp4, plato);
                detectionTresors(nbjoueurs, mains, tp1, tp2, tp3, tp4, etp, etp2, etp3, etp4, cptp, cptp2, cptp3, cptp4,
                                 parti);
                plato[*yp][*xp] = 'A';
                plato[*yp2][*xp2] = 'B';
                plato[*yp3][*xp3] = 'C';
                plato[*yp4][*xp4] = 'D';
                for (int i = 0; i < 21; i++) {
                    for (int j = 0; j < 27; j++) {
                        printf("%3c", plato[i][j]);

                    }
                    printf("\n");
                    if (i % 3 == 2)printf("\n");//2 5 8 11 13 15
                }
                flag = 0;
            }
            printf("Deplacez-vous :\n 1: Droite\n 2: Gauche\n 3: Haut\n 4: Bas\n 5: Tour suivant\n 6: Retour au menu\n");
            scanf("%d", choix);
            while (*choix <= 0 || *choix > 6) {
                printf("Deplacez-vous :\n 1: Droite\n 2: Gauche\n 3: Haut\n 4: Bas\n 5: Tour suivant\n 6: Retour au menu\n");
                scanf("%d", choix);
            }
            xt3 = *xp3;
            yt3 = *yp3;
            menudeplacements(choix, xp3, yp3, erreurp3);

            if (*choix == 2) {
                for (i = xt3; i > *xp3; i--) {
                    if (plato[yt3][i] == '#') {
                        printf("ca va pas\n");
                        *xp3 = xt3;
                        *erreurp3 = 1;
                    }
                }
            }
            if (*choix == 1) {
                for (i = xt3; i < *xp3; i++) {
                    if (plato[yt3][i] == '#') {
                        printf("ca va pas\n");
                        *xp3 = xt3;
                        *erreurp3 = 1;
                    }
                }
            }
            if (*choix == 3) {
                for (i = yt3; i > *yp3; i--) {
                    if (plato[i][xt3] == '#') {
                        printf("ca va pas\n");
                        *yp3 = yt3;
                        *erreurp3 = 1;
                    }
                }
            }
            if (*choix == 4) {
                for (i = yt3; i < *yp3; i++) {
                    if (plato[i][xt3] == '#') {
                        printf("ca va pas\n");
                        *yp3 = yt3;
                        *erreurp3 = 1;
                    }
                }
            }

            if (*yp3 == *yp && *xp3 == *xp || *yp3 == *yp2 && *xp3 == *xp2 || *yp3 == *yp4 && *xp3 == *xp4) {
                printf("ca ne va pas\n");
                *yp3 = yt3;
                *xp3 = xt3;
                *erreurp3 = 1;
            }
            if (*choix == 5) {
                printf("Tour suivant\n");
                etattour++;
                flag = 1;
                *erreurp3 = 1;
            }
            if (*choix == 6) {
                printf("Retour au menu\n");
                *parti = 0;
            }

            if (*nbjoueurs == 3 && etattour > 3) {

                etattour = 1;

            }

        }
        if (etattour == 4) {
            printf("tour joueur 4\n");
            printf("Main du joueur 4: "); // soit on enleve le print des cartes soit on ne l'enleve pas
            for (int j = 0; j < NOM_CARTES / (*nbjoueurs); j++) {
                printf("%c ", mains[3][j]);
            }
            printf("\n ");
            *erreurp4 = 0;
            if (flag == 1) {
                modiplato(plato, tuileEnPlus, xp, yp, xp2, yp2, xp3, yp3, xp4, yp4);
                tp(tuileEnPlus, xp, yp, xp2, yp2, xp3, yp3, xp4, yp4, erreurp, erreurp2, erreurp3, erreurp4, tp1, tp2,
                   tp3, tp4, plato);
                detectionTresors(nbjoueurs, mains, tp1, tp2, tp3, tp4, etp, etp2, etp3, etp4, cptp, cptp2, cptp3, cptp4,
                                 parti);
                plato[*yp][*xp] = 'A';
                plato[*yp2][*xp2] = 'B';
                plato[*yp3][*xp3] = 'C';
                plato[*yp4][*xp4] = 'D';
                for (int i = 0; i < 21; i++) {
                    for (int j = 0; j < 27; j++) {
                        printf("%3c", plato[i][j]);
                    }
                    printf("\n");
                    if (i % 3 == 2)printf("\n");//2 5 8 11 13 15
                }
                flag = 0;
            }
            printf("Deplacez-vous :\n 1: Droite\n 2: Gauche\n 3: Haut\n 4: Bas\n 5: Tour suivant\n 6: Retour au menu\n");
            scanf("%d", choix);
            while (*choix <= 0 || *choix > 6) {
                printf("Deplacez-vous :\n 1: Droite\n 2: Gauche\n 3: Haut\n 4: Bas\n 5: Tour suivant\n 6: Retour au menu\n");
                scanf("%d", choix);
            }
            xt = *xp4;
            yt = *yp4;
            menudeplacements(choix, xp4, yp4, erreurp4);
            if (*choix == 2) {
                for (i = xt; i > *xp4; i--) {
                    if (plato[yt][i] == '#') {
                        printf("ca va pas\n");
                        *xp4 = xt;
                        *erreurp4 = 1;
                    }
                }
            }
            if (*choix == 1) {
                for (i = xt; i < *xp4; i++) {
                    if (plato[yt][i] == '#') {
                        printf("ca va pas\n");
                        *xp4 = xt;
                        *erreurp4 = 1;
                    }
                }
            }
            if (*choix == 3) {
                for (i = yt; i > *yp4; i--) {
                    if (plato[i][xt] == '#') {
                        printf("ca va pas\n");
                        *yp4 = yt;
                        *erreurp4 = 1;
                    }
                }
            }
            if (*choix == 4) {
                for (i = yt; i < *yp4; i++) {
                    if (plato[i][xt] == '#') {
                        printf("ca va pas\n");
                        *yp4 = yt;
                        *erreurp4 = 1;
                    }
                }
            }
            if (*yp4 == *yp && *xp4 == *xp || *yp4 == *yp2 && *xp4 == *xp2 || *yp4 == *yp3 && *xp4 == *xp3) {
                printf("ca ne va pas\n");
                *yp4 = yt;
                *xp4 = xt;
                *erreurp4 = 1;
            }
            if (*choix == 5) {
                printf("Tour suivant\n");
                etattour++;
                flag = 1;
                *erreurp4 = 1;
            }
            if (*choix == 6) {
                printf("Retour au menu\n");
                *parti = 0;
            }
        }


        if (*nbjoueurs == 4 && etattour > 4) {

            etattour = 1;

        }
        tt = *tp1;

        if (*erreurp == 0) {
            *tp1 = plato[*yp][*xp];
            if (*tp1 == 'A') {
                *tp1 = tt;

            }
            detectionTresors(nbjoueurs, mains, tp1, tp2, tp3, tp4, etp, etp2, etp3, etp4, cptp, cptp2, cptp3, cptp4,
                             parti);
            if (*etp == 1) {
                tt = '_';
                *etp = 0;
            }
            plato[yt1][xt1] = tt;
            printf("pas d erreur\n");
        }

        if (*erreurp == 1) {// t=tt;
            printf("erreur\n");
            // *erreurp = 0;
        }
        plato[*yp][*xp] = 'A';

        if (*nbjoueurs >= 2) {
            tt2 = *tp2;
            if (*erreurp2 == 0) {
                *tp2 = plato[*yp2][*xp2];
                if (*tp2 == 'B') {
                    *tp2 = tt2;

                }
                detectionTresors(nbjoueurs, mains, tp1, tp2, tp3, tp4, etp, etp2, etp3, etp4, cptp, cptp2, cptp3, cptp4,
                                 parti);
                if (*etp == 1) {
                    tt2 = '_';
                    *etp2 = 0;
                }
                plato[yt2][xt2] = tt2;
            }


            if (*erreurp2 == 1) {
                //*erreurp2 = 0;
            }
            plato[*yp2][*xp2] = 'B';
        }
        if (*nbjoueurs >= 3) {
            tt3 = *tp3;
            if (*erreurp3 == 0) {
                *tp3 = plato[*yp3][*xp3];
                if (*tp3 == 'C') {
                    *tp3 = tt3;

                }
                detectionTresors(nbjoueurs, mains, tp1, tp2, tp3, tp4, etp, etp2, etp3, etp4, cptp, cptp2, cptp3, cptp4,
                                 parti);
                if (*etp == 1) {
                    tt3 = '_';
                    *etp3 = 0;
                }
                plato[yt3][xt3] = tt3;
            }

            if (*erreurp3 == 1) {
                // *erreurp3 = 0;
            }

            plato[*yp3][*xp3] = 'C';
        }
        if (*nbjoueurs >= 4) {

            tt4 = *tp4;
            if (*erreurp4 == 0) {
                *tp4 = plato[*yp4][*xp4];
                if (*tp4 == 'D') {
                    *tp4 = tt4;

                }
                detectionTresors(nbjoueurs, mains, tp1, tp2, tp3, tp4, etp, etp2, etp3, etp4, cptp, cptp2, cptp3, cptp4,
                                 parti);
                if (*etp == 1) {
                    tt4 = '_';
                    *etp4 = 0;
                }
                plato[yt][xt] = tt4;
            }
            if (*erreurp4 == 1) { //*erreurp4 = 0;
            }
            plato[*yp4][*xp4] = 'D';
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

int main() {
    int nbjoueurs1;
    int *nbjoueurs2 = &nbjoueurs1;
    int parti;
    int *parti1 = &parti;
    int parti2 = 1;
    int *parti2p = &parti2;
    while (*parti2p == 1) {
        menuprincipal(nbjoueurs2, parti1, parti2);
        plateau(nbjoueurs2, parti1);
    }
    return 0;
}
