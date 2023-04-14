/* 
 * Module associé à la table de représentation des types et des entêtes de sous-programmes
 ** Fichier En-tête
 */

#include "table_representation.h"

extern FILE *yyout;

int case_vide = 0;
int table_representation[TAILLE_MAX_TABLE_REPRESENTATION];      // Table de représentation
dimensions_tab tab_dim[TAILLE_MAX_TABLEAU_DIMENSIONS];          // Tableau de structures dimensions_tab pour gérer les bornes des tableaux
params_tab tab_param[TAILLE_MAX_TABLEAU_PARAMS];                // Tableau de structures params_tab pour gérer les paramètres des fonctions/procédures
champs_tab tab_champ[TAILLE_MAX_TABLEAU_CHAMPS];                // Tableau de structures champs_tab pour gérer les champs des structures

/****************************************************************************************************************/
                            /*FONCTION D'INITIALISATION DE LA TABLE DE REPRESENTATION*/
/****************************************************************************************************************/

// Initialise la table de représentation
// Ecrite par AKIL Mourtaza, AZEDINE Amirouche, BAYAZID Hany
void init_table_representation() {
    // Initialisation
    for (int i = 0; i < TAILLE_MAX_TABLE_REPRESENTATION; i++)
        table_representation[i] = -1;
}

/****************************************************************************************************************/
                                    /*FONCTION D'INSERTION POUR LES STRUCTURES*/
/****************************************************************************************************************/

// Insère la représentation d'une structure dans la table
// Ecrite par AKIL Mourtaza, AZEDINE Amirouche, BAYAZID Hany
void inserer_representation_structure(int nombre_champs) {
    table_representation[case_vide++] = nombre_champs;
    for (int i = 0; i < nombre_champs; i++) {
        table_representation[case_vide++] = tab_champ[i].num_lexico;
        table_representation[case_vide++] = tab_champ[i].type;
        table_representation[case_vide++] = tab_champ[i].execution;
    }
}

/****************************************************************************************************************/
                                    /*FONCTION D'INSERTION POUR LES TABLEAUX*/
/****************************************************************************************************************/

// Insère la représentation du tableau dans la table
// Ecrite par AKIL Mourtaza, AZEDINE Amirouche, BAYAZID Hany
void inserer_representation_tableau(int type_elements, int nombre_dimensions) {
    table_representation[case_vide++] = type_elements;
    table_representation[case_vide++] = nombre_dimensions;
    for (int i = 0; i < nombre_dimensions; i++) {
        table_representation[case_vide++] = tab_dim[i].borne_inf;
        table_representation[case_vide++] = tab_dim[i].borne_sup;
    }
}

/****************************************************************************************************************/
                                    /*FONCTION D'INSERTION POUR LES PROCEDURES*/
/****************************************************************************************************************/

// Insère la représentation d'une procédure dans la table
// Ecrite par AKIL Mourtaza, AZEDINE Amirouche, BAYAZID Hany
void inserer_representation_procedure(int nombre_parametres) {
    table_representation[case_vide++] = nombre_parametres;
    for (int i = 0; i < nombre_parametres; i++) {
        table_representation[case_vide++] = tab_param[i].num_lexico;
        table_representation[case_vide++] = tab_param[i].type;
    }
}

/****************************************************************************************************************/
                                    /*FONCTION  D'INSERTION POUR LES FONCTIONS*/
/****************************************************************************************************************/

// Insère la représentation d'une fonction dans la table
// Ecrite par AKIL Mourtaza, AZEDINE Amirouche, BAYAZID Hany
void inserer_representation_fonction(int type_retour, int nombre_parametres) {
    table_representation[case_vide++] = type_retour;
    table_representation[case_vide++] = nombre_parametres;
    for (int i = 0; i < nombre_parametres; i++) {
        table_representation[case_vide++] = tab_param[i].num_lexico;
        table_representation[case_vide++] = tab_param[i].type;
    }
}

/****************************************************************************************************************/
                            /*FONCTION D'AFFICHAGE DE LA TABLE DE REPRESENTAION*/
/****************************************************************************************************************/

// Affiche la table de représentation
// Ecrite par AKIL Mourtaza, AZEDINE Amirouche, BAYAZID Hany
void affichage_table_representation() {
    fprintf(yyout, "Affichage de la table de réprésentation :\n\n");
    fprintf(yyout, "|");
    for(int i = 0; i < case_vide; i++) {
        if (i != 0 && i % 10 == 0) fprintf(yyout, "|\n|");
        fprintf(yyout, "|\t%d\t|", table_representation[i]);
    }
    if ((case_vide - 1) % 10 != 0) fprintf(yyout, "|\n");
    fprintf(yyout, "\n\n");
}