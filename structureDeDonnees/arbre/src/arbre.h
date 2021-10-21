#ifndef __ARBRE_H__
#define __ARBRE_H__

#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

typedef struct maillonArbre
{
	struct maillonArbre* arbreGauche;
	int v;
	struct maillonArbre* arbreDroit;
}MaillonArbre, *Arbre;

Arbre arbrenouv(void);
Arbre enracinement(Arbre g, int x, Arbre d);
Arbre arbreGauche(Arbre a);
Arbre arbreDroit(Arbre a);
int racine(Arbre a);
Bool videArbre(Arbre a);
int nombreNoeud(Arbre a);
int nombreFeuille(Arbre a);
Bool estUneFeuille(Arbre a);
int hauteur(Arbre a);
int max(int a, int b);
Arbre extremiteGauche(Arbre a);
Arbre extremiteDroite(Arbre a);
Bool egaliteArbre(Arbre a, Arbre b);
Arbre insererFeuille(Arbre a, int x);
Arbre suppressionArbre(Arbre a, int x);
Bool estTrie(Arbre a);
Arbre oterMax(Arbre a);

#endif
