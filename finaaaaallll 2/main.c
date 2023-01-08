#include "biblio.h"

//detecteur de tresor et compteur de point
int detectionTresors(int *nbjoueur, char mains[4][24], char *tp, char *tp2, char *tp3, char *tp4, int *etp, int *etp2,
                     int *etp3, int *etp4, int *cptp, int *cptp2, int *cptp3, int *cptp4, int *parti) {
    //procédure pr le joueur 1 qui affiche le nombre de trésors restant a trouver
    if (*nbjoueur >= 1) {
        for (int i = 0;
             i < NOM_CARTES / (*nbjoueur); i++) {           //on compare la main du joueur avec la case sur laquelle il se trouve
            if (*tp == mains[0][i]) {                       //si le pion se trouve sur un trésor qui lui appartient
                *cptp = *cptp -
                        1;                                  //compteur de trésors diminue ('*cptp--' n'a pas l'air de marcher)
                *tp = '_';                                  // remplace l emplacement du trésors par un chemin normal
                mains[0][i] = 'X';                          // retire le tresor a recupérer de la main
                printf("Il reste %d tresors a trouver pour le joueur 1\n", *cptp);
                *etp = 1;                                   //signal que le joueur vient de récupérer un trésors
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
                *tp4 = '_'; //Remplacement du tresor trouvé sur laquelle le pion se trouvait
                mains[3][i] = 'X';//remplacement de la carte trouver par un 'X'
                //affichage du nombre de tresors restant a trouver
                printf("Il reste %d tresors a trouver pour le joueur 4\n", *cptp4);
                *etp4 = 1;
            }
        }
        printf("\n");
    }
    //si le compteur de trésors arrive à 0 cela signifie que le joueur à récupérer tout ses trésors
    if (*cptp == 0) {
        printf("Le joueur 1 a gagner!!! :D\n"); // message de victoire
        *parti = 0;
        return 0;
    }
    if (*cptp2 == 0) {
        printf("Le joueur 2 a gagner!!! :D\n"); // message de victoire
        *parti = 0;
        return 0;
    }
    if (*cptp3 == 0) {
        printf("Le joueur 3 a gagner!!! :D\n"); // message de victoire
        *parti = 0;
        return 0;
    }
    if (*cptp4 == 0) {
        printf("Le joueur 4 a gagner!!! :D\n"); // message de victoire
        *parti = 0;
        return 0;
    }
}

//deplacement des pions
int menudeplacements(int *choix, int *x, int *y, int *erreur) {
    int direction;
    if (*choix == 1) {// signifie que le joueur à décidé d'aller à droite
        printf("De combien voulez vous avancer?\n");// demande au joueur
        scanf("%d", &direction);//récupération du nombre de cases dont le joueur veut se déplacer
        *x = *x + (direction * 4);// déplacement dans le tableau vers la droite mutlplication par 4 car cela permet de mettre le pions au milieu des cases
    }

    if (*choix == 2) {
        printf("De combien voulez vous avancer?\n");
        scanf("%d", &direction);
        direction = direction * (-4);// déplacement dans le tableau vers la gauche mutlplication par 4 car cela permet de mettre le pion au milieu des cases
        *x = *x + direction;
    }
    if (*choix == 3) {
        printf("De combien voulez vous avancer?\n");
        scanf("%d", &direction);
        direction = direction * (-3);// déplacement vers le haut multplication par -3 car cela permet de mettre le pion au milieu de la case
        *y = *y + direction;
    }
    if (*choix == 4) {
        printf("De combien voulez vous avancer?\n");
        scanf("%d", &direction);
        *y = *y + (direction * 3);// déplacement vers le bas multplication par 3 car cela permet de mettre le pion au milieu de la case

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
    //afficher les choix possibles
    printf("1: Nouvelle partie \n2: Sauvegarder\n3: Charger une partie\n"
           "4: Afficher les regles et credits\n5: Quitter\n");

    scanf("%d", &choix);
    //tant que le choix n'est pas valable, continuer a demander
    while (choix < 1 || choix > 5) {
        printf("Veuillez entrer un choix existant\n");
        scanf("%d", &choix);
    }
    //Creation d'une nouvelle partie
    if (choix == 1) {
        printf("Nouvelle partie\n");
        printf("Veuillez entrer le nombre de joueurs\n");
        scanf("%d", nbjoueurs);
        while (*nbjoueurs < 1 || *nbjoueurs > 4) {
            printf("Veuillez entrer le nombre de joueurs\n");
            scanf("%d", nbjoueurs);
        }

        *parti = 1;


    }
    //Sauvegarde de la partie (pas implémenter)
    if (choix == 2) {
        printf("Sauvegarder");

    }
    //chargement d'une sauvegarde
    if (choix == 3) {
        printf("Charger partie");


    }
    //affichage des regles
    if (choix == 4) {
        printf("Pour jouer au Labyrinthe, il vous faut :\n"
               "1 a 4 joueurs.\n"
               "Le plateau de jeu.\n"
               "Les 24 cartes tresor.\n"
               "Les 34 cartons carres labyrinthe.\n"
               "Les 4 pions de couleurs differentes.\n"
               "Comment jouer au Labyrinthe :\n"
               "Dans un premier temps, il faut mettre en place le plateau de jeu.\n"
               "Pour ce faire, il vous faut melanger les cartons labyrinthe qui represente les couloirs du labyrinthe vu du dessus.\n"
               "Ensuite, il faut les placer sur les emplacements libres du plateau de jeu de manière à créer un labyrinthe aléatoire. \n"
               "Une fois le labyrinthe cree il doit vous rester une carte labyrinthe. Cette carte servira a deplacer les couloirs en les faisant coulisser.\n"
               "Avant de commencer la partie, les joueurs doivent se distribuer toutes les cartes tresor, face cachee, de façon à ce qu ils aient tous le meme \n"
               "nombre de cartes. Chaque joueur doit empiler ses cartes devant lui sans les regarder.  Chaque joueur choisit son pion et le place sur la case \n"
               "correspondante a la couleur de celui-ci (dans les 4 coins du plateau de jeu).\n"
               "C est le joueur le plus jeune qui commence a jouer et la partie se poursuit dans le sens des aiguilles d une montre. Chaque joueur regarde la carte tresor\n"
               "situee en haut de sa pile sans la devoiler aux autres. Il faut savoir que le tour d un joueur se deroule toujours de la meme maniere.\n"
               "En effet, le joueur doit toujours deplacer une rangee ou une colonne en premier, en introduisant la carte Labyrinthe supplementaire. Ensuite il peut \n"
               "deplacer son pion pour essayer d atteindre son objectif tresor. Notez qu un joueur est toujours oblige de modifier le labyrinthe avant de pouvoir deplacer \n"
               "son pion et ce meme si  son tresor est accessible directement.\n"
               "Le tour d un joueur au Labyrinthe :\n"
               "1 – La modification des couloirs du Labyrinthe :\n"
               "Il y a 12 fleches sur les bordures du plateau de jeu. Elles indiquent les colonnes et les rangees qui peuvent être modifiees en inserant \n"
               "la carte labyrinthe\n"
               "supplementaire. C est le joueur qui choisit la colonne ou la rangee qu il souhaite modifier lorsque vient son tour. Il suffit de pousser \n"
               "la colonne ou la rangee à l aide de la carte supplementaire vers l interieur du plateau.  Une nouvelle carte est donc expulsee de l autre cote du plateau.\n"
               "Cette nouvelle carte «labyrinthe» reste sur le cote du plateau jusqu a temps qu’elle soit reintroduite par le joueur suivant.\n"
               "ATTENTION : si un pion est expulse hors du plateau lors d un mouvement d une colonne ou d’une rangee il est replace à l oppose de celle-ci.\n"
               " Cependant, ceci ne constitue pas un mouvement du pion.\n"
               "2 – Le deplacement du joueur :\n"
               "\n"
               "Une fois que le joueur a modifie le labyrinthe, il peut se deplacer. Le joueur peut deplacer son pion librement aussi loin qu il le souhaite mais il \n"
               "ne peut pas, bien sur, traverser les murs. Il n'est pas possible de s arreter sur une case occupee par un autre joueur. S il le veut,  il n’est pas oblige\n"
               "d avancer et peut rester sur place.\n"
               "\n"
               "Si le joueur n a pas son tresor (dessin de la carte tresor) il peut placer son pion de maniere a se rapprocher au plus pres de son objectif \n"
               "pour le prochain tour. Si le joueur atteint son tresor il se defausse de sa carte et peut directement regarder son prochain objectif en prenant la \n"
               "carte suivante de sa pile cartes tresor\n"
               "\n"
               "C est alors au joueur de suivant de jouer. Il procedera de la meme maniere en modifiant le labyrinthe puis en deplaçant son pion vers son objectif tresor.\n"
               "\n"
               "Comment gagner au Labyrinthe :\n"
               "Pour remporter une partie au Labyrinthe, le joueur doit avoir decouvert tous ses tresors.\n"
               "\n"
               "Credits \n"
               "https://www.regles-de-jeux.com/regle-du-labyrinthe/\n"
               "Elias Douady \n"
               "Kimi Ho\n"
               "Pierre Tailhades\n"
               "Mathieu Bouche\n");
        menuprincipal(nbjoueurs, parti, parti2);


    }
    //stoppe le programme
    if (choix == 5) {
        *parti2 = 0;
    }

}

void plateau(int *nbjoueurs, int *parti) {
    char mains[4][NOM_CARTES];// mains des joueurs
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
    //compteur de point
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

    //initialisation du nombre exact de carte a trouver en fonction du nombre de joueurs
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
    //Enlever les pions inexistants du plateau
    if (*nbjoueurs < 4) {
        *yp4 = -10;
        *xp4 = -10;
    }
    if (*nbjoueurs < 3) {
        *yp3 = -10;
        *xp3 = -10;
    }
    if (*nbjoueurs < 2) {
        *yp2 = -10;
        *xp2 = -10;
    }


    int flag = 1;
    int etattour = 1;
    int erreur = 0, erreur2 = 0, erreur3 = 0, erreur4 = 0;// erreur permet de savoir si il faut mettre a jour ou non les coordonnées des pions
    int *erreurp2 = &erreur2;//pointeurs car ils sont utilsés dans la fonction tp
    int *erreurp3 = &erreur3;
    int *erreurp4 = &erreur4;
    int *erreurp = &erreur;
    *erreurp = 0;// initialisation à 0 autrement dit pas d'erreur
    *erreurp2 = 0;
    *erreurp3 = 0;
    *erreurp4 = 0;

    char t; // ces variables vont permettre de réafficher ce sur quoi était les pions
    char tt, t2, tt2, t3, tt3, t4, tt4;
    char *tp1 = &t;// initialisation des pointeurs
    char *tp2 = &t2;
    char *tp3 = &t3;
    char *tp4 = &t4;
    *tp1 = '_', *tp2 = '_', *tp3 = '_', *tp4 = '_';//première chose sur lesquelles étaient les pions
    int et, et2, et3, et4;
    int *etp = &et;// pointeur ces variables vont permettre de savoir si les pions était sur un trésor qui leur appartenaient ou non
    int *etp2 = &et2;
    int *etp3 = &et3;
    int *etp4 = &et4;
    *etp = 0; // au premier tour les pions sur sur leur case de départ qui ne comprend pas de trésors donc aucun risque qu'ils puissent être sur un trésors qui leur appartient
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


    creaPlato(plato);// création aléatoire du plateau
    distributionCartes(nbjoueurs, mains);// on distribue les trésors aux joueurs
    plato[*yp][*xp] = 'A';// on affiche les pions pour la première fois
    plato[*yp2][*xp2] = 'B';
    plato[*yp3][*xp3] = 'C';
    plato[*yp4][*xp4] = 'D';


    for (int i = 0; i < 21; i++) {// affichage du plateau
        for (int j = 0; j < 27; j++) {
            printf("%3c", plato[i][j]);

        }
        printf("\n");
        if (i % 3 == 2)printf("\n");//2 5 8 11 13 15 // permet de sauter les lignes au bon moment
    }

    while (*parti == 1) {// lancement de la boucle de jeu
        if (etattour == 1) {// tour du premier joueur
            *erreurp = 0;// pas d'erreur jusqu'à présent
            printf("Tour joueur 1\n");
            printf("Main du joueur 1: "); // soit on enleve le print des cartes soit on ne l'enleve pas
            //print la main du joueur 1
            for (int j = 0; j < NOM_CARTES / (*nbjoueurs); j++) {
                printf("%c ", mains[0][j]);
            }
            printf("\n");
            if (flag == 1) {// on fait en sorte que le joueur ne puisse déplacer qu'une tuile pendant son tour
                modiplato(plato, tuileEnPlus, xp, yp, xp2, yp2, xp3, yp3, xp4, yp4);// on met la tuile en plus
                tp(tuileEnPlus, xp, yp, xp2, yp2, xp3, yp3, xp4, yp4, erreurp, erreurp2, erreurp3, erreurp4, tp1, tp2,
                   tp3, tp4, plato);//cette fonction s'occupe de la tuile qui a été sortie
                detectionTresors(nbjoueurs, mains, tp1, tp2, tp3, tp4, etp, etp2, etp3, etp4, cptp, cptp2, cptp3, cptp4,
                                 parti);// on vérifie que si un pions a été déplacé pendant le déplacement des tuiles, il a été déplacé sur un trésors ou non
                plato[*yp][*xp] = 'A';// on replace les pions
                plato[*yp2][*xp2] = 'B';
                plato[*yp3][*xp3] = 'C';
                plato[*yp4][*xp4] = 'D';
                // erreur=1;

                for (int i = 0; i < 21; i++) {// on affiche le plateau de jeu
                    for (int j = 0; j < 27; j++) {
                        printf("%3c", plato[i][j]);

                    }
                    printf("\n");
                    if (i % 3 == 2)printf("\n");//2 5 8 11 13 15
                }
                flag = 0;// mise à 0 pour que le joueur ne puisse plus utiliser cette fonction jusqu'à son prochain tour
            }
            printf("Deplacez-vous :\n 1: Droite\n 2: Gauche\n 3: Haut\n 4: Bas\n 5: Tour suivant\n 6: Retour au menu\n");
            scanf("%d", choix);
            while (*choix <= 0 || *choix > 6) {//blindage
                printf("Deplacez-vous :\n 1: Droite\n 2: Gauche\n 3: Haut\n 4: Bas\n 5: Tour suivant\n 6: Retour au menu\n");
                scanf("%d", choix);
            }
            xt1 = *xp;// on prend les coordonnées du pion avant qu'il se déplace
            yt1 = *yp;// on prend les coordonnées du pion avant qu'il se déplace
            menudeplacements(choix, xp, yp, erreurp);// mise à jour des coordonnées du pions


            if (*choix == 2) {// on vérifie que le joueur peut bien aller à la case ou il veut aller
                for (i = xt1; i > *xp; i--) {
                    if (plato[yt1][i] == '#') {
                        printf("Ca va pas\n");
                        *xp = xt1;
                        *erreurp = 1;// s'il ne peut pas déplacer là où il a essayé d'aller cela signifie qu'il y a une erreur et qu'il ne faut pas mettre ses anciennes coordonnées à jour
                    }
                }
            }
            if (*choix == 1) {// on vérifie que le joueur peut bien aller à la case ou il veut aller
                for (i = xt1; i < *xp; i++) {
                    if (plato[yt1][i] == '#') {
                        printf("Ca va pas\n");
                        *xp = xt1;
                        *erreurp = 1;// s'il ne peut pas déplacer là où il a essayé d'aller cela signifie qu'il y a une erreur et qu'il ne faut pas mettre ses anciennes coordonnées à jour
                    }
                }
            }
            if (*choix == 3) {// on vérifie que le joueur peut bien aller à la case ou il veut aller
                for (i = yt1; i > *yp; i--) {
                    if (plato[i][xt1] == '#') {
                        printf("Ca va pas\n");
                        *yp = yt1;
                        *erreurp = 1;// s'il ne peut pas déplacer là où il a essayé d'aller cela signifie qu'il y a une erreur et qu'il ne faut pas mettre ses anciennes coordonnées à jour
                    }
                }
            }
            if (*choix == 4) {// on vérifie que le joueur peut bien aller à la case ou il veut aller
                for (i = yt1; i < *yp; i++) {
                    if (plato[i][xt1] == '#') {
                        printf("Ca va pas\n");
                        *yp = yt1;
                        *erreurp = 1;// s'il ne peut pas déplacer là où il a essayé d'aller cela signifie qu'il y a une erreur et qu'il ne faut pas mettre ses anciennes coordonnées à jour
                    }
                }
            }
            if (*yp == *yp2 && *xp == *xp2 || *yp == *yp3 && *xp == *xp3 || *yp == *yp4 && *xp == *xp4) {
                printf("Ca ne va pas\n");
                *yp = yt1;
                *xp = xt1;
                *erreurp = 1;
            }//on vérifie que le pion ne se positionne pas sur l'emplacemnt d'un autre pion


            if (*choix == 5) { //Fin du tour
                printf("Tour suivant\n");
                etattour++;
                flag = 1;// fait en sorte qu'au prochain tour le joueur pourra reposer une tuile
                *erreurp = 1;// vu qu'il y a une fin de tour il ne faut mettre les anciennes coordonnées du joueur à jour
            }

            if (*choix == 6) {//Retour au menu principal
                printf("Retour au menu\n");
                *parti = 0;//on coupe la boucle du jeu pour revenir au menu
            }
            if (*nbjoueurs == 1 && etattour > 1) {

                etattour = 1;// fin du tour du joueur

            }


        }
        if (etattour == 2) {
            printf("Tour joueur 2\n");
            printf("Main du joueur 2: "); // soit on enleve le print des cartes soit on ne l'enleve pas
            //print la main du joueur 2
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
                        printf("Ca va pas\n");
                        *xp2 = xt2;
                        *erreurp2 = 1;
                    }
                }
            }
            if (*choix == 1) {
                for (i = xt2; i < *xp2; i++) {
                    if (plato[yt2][i] == '#') {
                        printf("Ca va pas\n");
                        *xp2 = xt2;
                        *erreurp2 = 1;
                    }
                }
            }
            if (*choix == 3) {
                for (i = yt2; i > *yp2; i--) {
                    if (plato[i][xt2] == '#') {
                        printf("Ca va pas\n");
                        *yp2 = yt2;
                        *erreurp2 = 1;
                    }
                }
            }
            if (*choix == 4) {
                for (i = yt2; i < *yp2; i++) {
                    if (plato[i][xt2] == '#') {
                        printf("Ca va pas\n");
                        *yp2 = yt2;
                        *erreurp2 = 1;
                    }
                }
            }
            if (*yp2 == *yp && *xp2 == *xp || *yp2 == *yp3 && *xp2 == *xp3 || *yp2 == *yp4 && *xp2 == *xp4) {
                printf("Ca ne va pas\n");
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
            printf("Tour joueur 3\n");
            printf("Main du joueur 3: "); // soit on enleve le print des cartes soit on ne l'enleve pas
            //print la main du joueur 3
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
                        printf("Ca va pas\n");
                        *xp3 = xt3;
                        *erreurp3 = 1;
                    }
                }
            }
            if (*choix == 1) {
                for (i = xt3; i < *xp3; i++) {
                    if (plato[yt3][i] == '#') {
                        printf("Ca va pas\n");
                        *xp3 = xt3;
                        *erreurp3 = 1;
                    }
                }
            }
            if (*choix == 3) {
                for (i = yt3; i > *yp3; i--) {
                    if (plato[i][xt3] == '#') {
                        printf("Ca va pas\n");
                        *yp3 = yt3;
                        *erreurp3 = 1;
                    }
                }
            }
            if (*choix == 4) {
                for (i = yt3; i < *yp3; i++) {
                    if (plato[i][xt3] == '#') {
                        printf("Ca va pas\n");
                        *yp3 = yt3;
                        *erreurp3 = 1;
                    }
                }
            }

            if (*yp3 == *yp && *xp3 == *xp || *yp3 == *yp2 && *xp3 == *xp2 || *yp3 == *yp4 && *xp3 == *xp4) {
                printf("Ca ne va pas\n");
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
            printf("Tour joueur 4\n");
            printf("Main du joueur 4: "); // soit on enleve le print des cartes soit on ne l'enleve pas
           //print la main du joueur 4
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
                        printf("Ca va pas\n");
                        *xp4 = xt;
                        *erreurp4 = 1;
                    }
                }
            }
            if (*choix == 1) {
                for (i = xt; i < *xp4; i++) {
                    if (plato[yt][i] == '#') {
                        printf("Ca va pas\n");
                        *xp4 = xt;
                        *erreurp4 = 1;
                    }
                }
            }
            if (*choix == 3) {
                for (i = yt; i > *yp4; i--) {
                    if (plato[i][xt] == '#') {
                        printf("Ca va pas\n");
                        *yp4 = yt;
                        *erreurp4 = 1;
                    }
                }
            }
            if (*choix == 4) {
                for (i = yt; i < *yp4; i++) {
                    if (plato[i][xt] == '#') {
                        printf("Ca va pas\n");
                        *yp4 = yt;
                        *erreurp4 = 1;
                    }
                }
            }
            if (*yp4 == *yp && *xp4 == *xp || *yp4 == *yp2 && *xp4 == *xp2 || *yp4 == *yp3 && *xp4 == *xp3) {
                printf("Ca ne va pas\n");
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
        tt = *tp1; //mise a jour du caractère tt qui va permettre de réafficher ce sur quoi le pion été posé

        if (*erreurp == 0) {//pas d'"erreur"
            *tp1 = plato[*yp][*xp];// on prend le caractère sur lequel le pion va être posé
            if (*tp1 == 'A') {// si le caratère est le pion lui même on reprend l'ancienne sauvegarde ce sur quoi A était posé
                *tp1 = tt;

            }
            detectionTresors(nbjoueurs, mains, tp1, tp2, tp3, tp4, etp, etp2, etp3, etp4, cptp, cptp2, cptp3, cptp4,
                             parti);// on vérifie que le pion n'est pas sur un trésor qui lui appartient
            if (*etp == 1) {// si le joueur est sur un trésor qui lui appartient
                tt = '_';// enlève le trésor
                *etp = 0;//remise à 0 de la variable trésor
            }
            plato[yt1][xt1] = tt;// on met le caractère sur lequel était posé le pion sur ses anciennes coordonnées
            printf("Pas d erreur\n");
        }

        if (*erreurp == 1) {// pas de mise à jour du caractère sur lequel se trouve le pion s'il n'a pas fait de déplacement
            printf("Erreur\n");
            // *erreurp = 0;
        }
        plato[*yp][*xp] = 'A';//on positionne le pion à ses coordonnées

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


            if (*erreurp2 == 1) {// pas de mise à jour du caractère sur lequel se trouve le pion s'il n'a pas fait de déplacement
                //*erreurp2 = 0;
            }
            plato[*yp2][*xp2] = 'B';//on positionne le pion à ses coordonnées
        }
        if (*nbjoueurs >= 3) {
            tt3 = *tp3;
            if (*erreurp3 == 0) {
                *tp3 = plato[*yp3][*xp3];
                if (*tp3 == 'C') {
                    *tp3 = tt3;

                }
                detectionTresors(nbjoueurs, mains, tp1, tp2, tp3, tp4, etp, etp2, etp3, etp4, cptp, cptp2, cptp3, cptp4, parti);
                if (*etp == 1) {
                    tt3 = '_';
                    *etp3 = 0;
                }
                plato[yt3][xt3] = tt3;
            }

            if (*erreurp3 == 1) {// pas de mise à jour du caractère sur lequel se trouve le pion s'il n'a pas fait de déplacement
                // *erreurp3 = 0;
            }

            plato[*yp3][*xp3] = 'C';//on positionne le pion à ses coordonnées
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
            if (*erreurp4 == 1) { // pas de mise à jour du caractère sur lequel se trouve le pion s'il n'a pas fait de déplacement
            }
            plato[*yp4][*xp4] = 'D';//on positionne le pion à ses coordonnées
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
    //initialisation de variables et pointeurs
    int nbjoueurs1;
    int *nbjoueurs2 = &nbjoueurs1;
    int parti;
    int *parti1 = &parti;
    int parti2 = 1;
    int *parti2p = &parti2;
    //tant que "Quitter" n'est pas appuyé, le jeu tourne
    while (*parti2p == 1) {
        menuprincipal(nbjoueurs2, parti1, parti2);
        plateau(nbjoueurs2, parti1);
    }
    return 0;
}
