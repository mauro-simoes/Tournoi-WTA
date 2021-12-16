/*
    Tournoi-WTA
    Auteur: DA CONCEICAO SIMOES Mauro 
    Date de création: 07/10/2021
*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#pragma warning(disable:4996)

#define maxTournois 10
#define nbMatchsTournoi 127
#define nbJoueusesTournoi 128
#define lgMot 30


/*
    Structure contenant une joueuse
    nom: nom de la joueuse
    points: points de la joueuse
*/
typedef struct {
    char nom[lgMot + 1];
    unsigned int points;
} Joueuse;


/*
    Structure contenant un match
    idxGagnante: index de la gagnante dans dataJoueuses
    idxperdante: index de la perdante dans dataJoueuses
*/
typedef struct {
    unsigned int idxGagnante;
    unsigned int idxPerdante;
} Match;


/*
    Structure contenant un tournoi
    nomTournoi: nom du tournoi
    dateTournoi[5]:l'année du déroulement du tournoi
    dataMatch: tableau des matchs du tournoi
*/
typedef struct {
    char nomTournoi[lgMot + 1];
    char dateTournoi[5];
    Match dataMatch[nbMatchsTournoi];
} Tournoi;


/*
    Structure contenant un l'ensemble des tournois et des joueuses
    dataTournoi: tableau de tous les tournois (maximum de 10 tournois)
    dataJoueuses: tableau de toutes les joueuses
    nbTournois: nombre de tournois
    idxT: index suivant l'index du dernier tournoi enregistré
    idxJ: index suivant l'index de la derniere joueuse enregistrée
*/
typedef struct {
    Tournoi dataTournoi[maxTournois];
    Joueuse dataJoueuses[maxTournois * nbJoueusesTournoi];
    int nbTournois;
    int idxT;
    int idxJ;
} TournoiWTA;


// DEBUT SPRINT 1

/* 
    Vérifie que le nombre de tournois est entre 1 et 10 et affecte ce nombre à la variable nbTournois de la structure
    [in-out] TournoiWTA ins
*/
void definir_nombre_tournois(TournoiWTA* ins) {
    int nb;
    scanf("%d", &nb);
    assert(nb >= 1 && nb <= maxTournois);
    ins->nbTournois = nb;
}

/*
    regarde si la joueuse est deja dans dataJoueuse
    [in-out] TournoiWTA ins
    [in] char[lgMot+1] nom_joueuse
    [out] return 1 si l& joueuse est deja dans dataJoueuses 0 sinon
*/
int dansJoueuses(TournoiWTA* ins, const char nom_joueuse[lgMot + 1]) {
    int i;
    for (i = 0; i < ins->idxJ; i++) {
        if (strcmp(nom_joueuse, ins->dataJoueuses[i].nom) == 0) {
            return 1;
        }
    }
    return 0;
}

/*  
    trouve l'index de la joueuse dans dataJoueuses
    [in-out] TournoiWTA ins
    [in] char[lgMot+1] nom_joueuse, correspond au nom de la joueuse
    [out] return i l'index de la joueuse dans dataJoueuses ou -1 si la joueuse n'est pas enregistrée
*/
int indexJoueuse(TournoiWTA* ins, const char nom_joueuse[lgMot + 1]) {
    int i;
    for (i = 0; i < ins->nbTournois * nbJoueusesTournoi; i++) {
        if (strcmp(nom_joueuse, ins->dataJoueuses[i].nom) == 0) {
            return i;
        }
    }
    return -1;
}

/*
    Attribue les points aux joueuses
    [in-out] TournoiWTA ins
    [in] int idxT, l'indice du tournoi
*/
void points_joueuse(TournoiWTA* ins, const int idxT) {
    int i;
    for (i = 126; i >= 0; i--) {
        if (i == 126) {
            ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[i].idxGagnante].points += 2000;
            ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[i].idxPerdante].points += 1200;
        }
        else if (i >= 124 && i < 126) {
            ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[i].idxPerdante].points += 720;
        }
        else if (i >= 120 && i < 124) {
            ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[i].idxPerdante].points += 360;
        }
        else if (i >= 112 && i < 120) {
            ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[i].idxPerdante].points += 180;
        }
        else if (i >= 96 && i < 112) {
            ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[i].idxPerdante].points += 90;
        }
        else if (i >= 64 && i < 96) {
            ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[i].idxPerdante].points += 45;
        }
        else {
            ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[i].idxPerdante].points += 10;
        }
    }
}

/*
    trouve l'index du tournoi dans dataTournoi
    [in-out] TournoiWTA ins
    [in] char[lgMot+1] nomTournoi
    [in] char[lgMot+1] anneeTournoi
    [out] return i l'index du tournoi ou -1 si le tournoi n'est pas enregistré
*/
int indexTournoi(TournoiWTA* ins, const char nomTournoi[lgMot + 1], const char anneeTournoi[lgMot + 1]) {
    for (int i = 0; i < ins->nbTournois; i++) {
        if (strcmp(ins->dataTournoi[i].nomTournoi, nomTournoi) == 0 && strcmp(ins->dataTournoi[i].dateTournoi, anneeTournoi) == 0) {
            return i;
        }
    }
    return -1;
}


/*
    enregistre le tournoi dans dataTournoi
    [in-out] TournoiWTA ins
*/
void enregistrement_tournoi(TournoiWTA* ins) {
    /*on initialise j à ins->idxJ et numeroT à ins->idxt car ils correspondent respectivement aux index qui suivent le dernier enregistrement s'il existe*/
    int i,j = ins->idxJ, numeroT = ins->idxT;
    char gagnante[lgMot + 1], perdante[lgMot + 1];
    scanf("%s %s", ins->dataTournoi[numeroT].nomTournoi, ins->dataTournoi[numeroT].dateTournoi);
    for (i = 0; i < nbMatchsTournoi; i++) {
        scanf("%s %s", gagnante, perdante);
        if ((dansJoueuses(ins, gagnante) == 1) && (dansJoueuses(ins, perdante) == 1)) {
            /*pour chaque match si la gagnante et la perdante sont déja enregistrées on affecte leurs indexes respectivement à idxGagnante et idxperdante*/
            ins->dataTournoi[numeroT].dataMatch[i].idxGagnante = indexJoueuse(ins, gagnante);
            ins->dataTournoi[numeroT].dataMatch[i].idxPerdante = indexJoueuse(ins, perdante);
        }
        else if (dansJoueuses(ins, gagnante) == 0){
            strcpy(ins->dataJoueuses[j].nom, gagnante);
            ins->dataJoueuses[j].points = 0;
            ins->dataTournoi[numeroT].dataMatch[i].idxGagnante = j;
            if (dansJoueuses(ins, perdante) == 0) {
                strcpy(ins->dataJoueuses[j + 1].nom, perdante);
                ins->dataJoueuses[j + 1].points = 0;
                ins->dataTournoi[numeroT].dataMatch[i].idxPerdante = j + 1;
                j += 2;
                ins->idxJ = j;
                /*pour chaque match si la gagnante et la perdante ne sont pas déja enregistrées, on les enregistre puis on affecte leurs indexes respectivement à idxGagnante et idxperdante et on ajoute 2 à j et idxJ car nous avons ajouté 2 joueuses*/
            }
            else {
                ins->dataTournoi[numeroT].dataMatch[i].idxPerdante = indexJoueuse(ins, perdante);
                j++;
                ins->idxJ = j;
            }
        }
        else {
            ins->dataTournoi[numeroT].dataMatch[i].idxGagnante = indexJoueuse(ins, gagnante);
            strcpy(ins->dataJoueuses[j].nom, perdante);
            ins->dataJoueuses[j].points = 0;
            ins->dataTournoi[numeroT].dataMatch[i].idxPerdante = j;
            j ++;
            ins->idxJ = j;
        }
    }
    points_joueuse(ins,numeroT);
    ins->idxT++;
}

/*
    affiche tous les matchs du tournoi selectionné
    [in-out] TournoiWTA ins
*/
void affichage_matchs_tournoi(TournoiWTA* ins) {
    int i, indexT;
    Joueuse gagnante, perdante;
    char nomTournoi[lgMot + 1], dateTournoi[lgMot + 1];
    scanf("%s %s", nomTournoi,dateTournoi);
    indexT = indexTournoi(ins, nomTournoi, dateTournoi);
    if (indexT == -1) {
        printf("tournoi inconnu");
    }
    else {
        printf("%s %s\n", nomTournoi, dateTournoi);
        printf("64emes de finale\n");
        for (i = 0; i < nbMatchsTournoi; ++i) {
            if (i == 64) {
                printf("32emes de finale\n");
            }
            else if (i == 96) {
                printf("16emes de finale\n");
            }
            else if (i == 112) {
                printf("8emes de finale\n");
            }
            else if (i == 120) {
                printf("quarts de finale\n");
            }
            else if (i == 124) {
                printf("demi-finales\n");
            }
            else if (i == 126) {
                printf("finale\n");
            }
            gagnante = ins->dataJoueuses[(ins->dataTournoi[indexT].dataMatch[i].idxGagnante)];
            perdante = ins->dataJoueuses[(ins->dataTournoi[indexT].dataMatch[i].idxPerdante)];
            printf("%s %s\n", gagnante.nom, perdante.nom);
        }
    }
}

// FIN SPRINT 1

// DEBUT SPRINT 2


/*
    affiche tous les matchs d'une seule joueuese dans un seul tournoi
    [in-out] TournoiWTA ins
*/
void affichage_matchs_joueuse(TournoiWTA* ins) {
    char nomTournoi[lgMot + 1], dateTournoi[lgMot + 1], nomJoueuse[lgMot + 1];
    scanf("%s %s %s", nomTournoi, dateTournoi, nomJoueuse);
    int idxj = indexJoueuse(ins, nomJoueuse);
    if (idxj == -1) {
        printf("joueuse inconnue");
    }
    else {
        int idxT = indexTournoi(ins, nomTournoi, dateTournoi);
        Joueuse gagnante, perdante;
        for (int m = 0; m < nbMatchsTournoi; m++) {
            Match match = ins->dataTournoi[idxT].dataMatch[m];
            gagnante = ins->dataJoueuses[match.idxGagnante];
            perdante = ins->dataJoueuses[match.idxPerdante];
            if (match.idxGagnante == idxj || match.idxPerdante == idxj) {
                printf("%s %s\n", gagnante.nom, perdante.nom);
            }
        }
    }
}

// FIN SPRINT 2


// DEBUT SPRINT 3


/*
    tri les joueueses par ordre alphabétique
    [in-out] Joueuse[]nbJoueusesTournoi joueuses, une liste de toutes les joueuses d'un tournoi donné
*/
void tri_joueuses_nom(Joueuse joueuses[nbJoueusesTournoi]) {
    int i, j;
    Joueuse temporaire;
    for (i = 0; i < nbJoueusesTournoi; i++) {
        for (j = 0; j < nbJoueusesTournoi; j++) {
            if (strcmp(joueuses[i].nom, joueuses[j].nom) < 0) {
                temporaire=joueuses[i];
                joueuses[i]= joueuses[j];
                joueuses[j]= temporaire;
            }
        }
    }
}

/*
    affiche toutes les joueuses (nom et points) d'un tournoi donné par ordre alphabétique
    [in-out] TournoiWTA ins
*/
void affichage_joueuses_tournoi(TournoiWTA* ins) {
    int i=0,m=0;
    char nomTournoi[lgMot + 1], dateTournoi[lgMot + 1];
    Joueuse joueuses[nbJoueusesTournoi];
    scanf("%s %s", nomTournoi, dateTournoi);
    int idxT = indexTournoi(ins, nomTournoi, dateTournoi);
    if (idxT == -1) {
        printf("tournoi inconnu");
    }
    else {
        /*ci-dessous on rempli la liste des joueuses du tournoi*/
        while (m < 64) {
            joueuses[i] = ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[m].idxGagnante];
            joueuses[++i] = ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[m].idxPerdante];
            i++;
            m++;
        }
        tri_joueuses_nom(joueuses);
        printf("%s %s\n", nomTournoi, dateTournoi);
        for (i = 0; i < nbJoueusesTournoi; ++i) {
            printf("%s %d\n",joueuses[i].nom, joueuses[i].points);
        }
    }
}


// FIN SPRINT 3

// DEBUT SPRINT 5

/*
    tri les joueuses en fonction des points par ordre croissant
    [in-out] TournoiWTA ins
    [in] Joueuse[nbJoueusesTournoi * maxTournois] listeJ, liste de toutes les joueuses
*/
void tri_joueuses_points(TournoiWTA* ins, Joueuse listeJ[nbJoueusesTournoi * maxTournois]) {
    int i, j;
    Joueuse tmp;
    /*on n'utilise pas dataJoueuses pour trier les joueuses car cela implique un changement d'index donc on crée une copie de dataJoueuses*/
    for (i = 0; i < ins->idxJ; i++) {
        listeJ[i] = ins->dataJoueuses[i];
    }
    for (i = 1; i < ins->idxJ; i++) {
        Joueuse joueuse = listeJ[i];
        j = i;
        while (j > 0 && (listeJ[j - 1].points > joueuse.points)) {
            tmp = listeJ[j];
            listeJ[j] = listeJ[j - 1];
            listeJ[j - 1] = tmp;
            j--;
        }
        listeJ[j] = joueuse;
        while (listeJ[j - 1].points == joueuse.points) {
            if (strcmp(listeJ[j - 1].nom, joueuse.nom) < 0) {
                tmp = listeJ[j];
                listeJ[j] = listeJ[j - 1];
                listeJ[j - 1] = tmp;
            }
            j--;
        }
    }
}

/*
    soustrait aux joueueses les points obtenues lors d'un tournoi donné
    [in-out] TournoiWTA ins
    [in] int idxT, index du tournoi
*/
void soustraction_points_joueuse(TournoiWTA* ins, int idxT) {
    int i;
    Joueuse perdante,gagnante;
    /*pour toutes les joueuses du tournoi, si le nombre points à soustraire est inférieur au nombre de points que possède la joueuse 
    alors on soustrait les points qu'elles ont obtenu lors du tournoi sinon on lui affecte 0 points */
    for (i = 126; i >= 0; i--) {
        perdante = ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[i].idxPerdante];
        if (i == 126) {
            gagnante = ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[i].idxGagnante];
            gagnante.points = (gagnante.points >= 1200) ? gagnante.points-= 2000 : 0;
            ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[i].idxGagnante].points = gagnante.points;
            perdante.points = (perdante.points>=1200) ? perdante.points-= 1200 : 0;
            ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[i].idxPerdante].points = perdante.points;
        }
        else if (i >= 124 && i < 126) {
            perdante.points = (perdante.points >= 720) ? perdante.points-= 720 : 0;
            ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[i].idxPerdante].points = perdante.points;
        }
        else if (i >= 120 && i < 124) {
            perdante.points = (perdante.points >= 360) ? perdante.points-= 360 : 0;
            ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[i].idxPerdante].points = perdante.points;
        }
        else if (i >= 112 && i < 120) {
            perdante.points = (perdante.points >= 180) ? perdante.points-= 180 : 0;
            ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[i].idxPerdante].points = perdante.points;
        }
        else if (i >= 96 && i < 112) {
            perdante.points = (perdante.points >= 90) ? perdante.points-= 90 : 0;
            ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[i].idxPerdante].points = perdante.points;
        }
        else if (i >= 64 && i < 96) {
            perdante.points = (perdante.points >= 45) ? perdante.points-= 45 : 0;
            ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[i].idxPerdante].points = perdante.points;
        }
        else{
            perdante.points = (perdante.points >= 10) ? perdante.points-= 10 : 0;
            ins->dataJoueuses[ins->dataTournoi[idxT].dataMatch[i].idxPerdante].points = perdante.points;
        }
    }
}


/*
    affiche le classement des joueuses pour un nombre de tournois entre 1 et 10
    [in-out] TournoiWTA ins
*/
void afficher_classement(TournoiWTA* ins) {
    int i,j;
    Joueuse listeJ[nbJoueusesTournoi * maxTournois];
    /*on soustrait au total des points de chaque joueuse les points obtenus lors des tournois se situant avant les 4 tournois choisis pour le classement */
    for (i = 0; i < (ins->idxT) - 4; i++) {
        soustraction_points_joueuse(ins, i);
    }
    tri_joueuses_points(ins, listeJ);
    for (j = ins->idxJ - 1; j >=0; j--) {
        if (listeJ[j].points >= 10) {
            printf("%s %d\n", listeJ[j].nom, listeJ[j].points);
        }
    }
    /*apres avoir affiché le classement on rajoute les points qu'avaient été soustraits afin d'obtenir à nouveau le total sur tous les tournois*/
    for (i = 0; i <(ins->idxT) - 4; i++) {
        points_joueuse(ins, i);
    }
}

// FIN SPRINT 5

int main() {
    TournoiWTA tableTournois;
    char mot[lgMot + 1];
    /*on initialise idxJ et idxT a zéro afin d'enregistrer le premier élément*/
    tableTournois.idxJ = 0;
    tableTournois.idxT = 0;
    while (1) {
        scanf("%s", mot);
        if (strcmp(mot, "definir_nombre_tournois") == 0) {
            definir_nombre_tournois(&tableTournois);
        }
        else if (strcmp(mot, "enregistrement_tournoi") == 0) {
            enregistrement_tournoi(&tableTournois);
        }
        else if (strcmp(mot, "affichage_matchs_tournoi") == 0) {
            affichage_matchs_tournoi(&tableTournois);
        }
        else if (strcmp(mot, "afficher_matchs_joueuse") == 0) {
            affichage_matchs_joueuse(&tableTournois);
        }
        else if (strcmp(mot, "affichage_joueuses_tournoi") == 0) {
            affichage_joueuses_tournoi(&tableTournois);
        } 
        else if (strcmp(mot, "afficher_classement") == 0) {
            afficher_classement(&tableTournois);
        }
        else if (strcmp(mot, "exit") == 0) {
            exit(0);
        }
    }
    system("pause");
    return 0;
}