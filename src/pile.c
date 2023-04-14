/* 
 * Module associé au TAD pile
 ** Fichier Source
 */

#include "pile.h"

// Initialise une pile
// Ecrite par AKIL Mourtaza, AZEDINE Amirouche, BAYAZID Hany
int initialiser(pile p) {
    int i;
    for (i = 0; i < TAILLE_MAX_PILE; i++)
        p[i] = -1;
    p[0] = 0;
    return 0;
}

// Empile un élément dans la pile
// Ecrite par AKIL Mourtaza, AZEDINE Amirouche, BAYAZID Hany
int empiler(int elem, pile p) {
    int taille_pile = p[0];
    if (taille_pile < TAILLE_MAX_PILE) {
        p[taille_pile + 1] = elem;
        p[0]++;
    }
    return 0;
}

// Vérifie si la pile est vide
// Ecrite par AKIL Mourtaza, AZEDINE Amirouche, BAYAZID Hany
int pile_estvide(pile p) {
    return p[0] == 0;
}

// Dépile la pile
// Ecrite par AKIL Mourtaza, AZEDINE Amirouche, BAYAZID Hany
int depiler(pile p) {
    int taille_pile = p[0],
        elem = -1;
    if (!pile_estvide(p)) {
        elem = p[taille_pile];
        p[0] = --taille_pile;
    }
    return  elem;
}

// Renvoie le sommet de la pile
// Ecrite par AKIL Mourtaza, AZEDINE Amirouche, BAYAZID Hany
int sommet(pile p) {
    int taille_pile = p[0],
        elem = -1;
    if (!pile_estvide(p))
        elem = p[taille_pile];;
    return elem;
}

// Affiche la pile
// Ecrite par AKIL Mourtaza, AZEDINE Amirouche, BAYAZID Hany
int afficher(pile p) {
    for (int i = 0; i < p[0]; i++)
        printf("%d ", p[i]);
    return 0;
}
  