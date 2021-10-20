#ifndef __PILE_H__
#define __PILE_H__

#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

typedef struct maillonPile
{
	struct maillonPile* suiv;
	int v;
}MaillonPile, *Pile;

Pile pilenouv(void);
Pile empiler(Pile p, int x);
Pile depiler(Pile p);
int sommet(Pile p);
int hauteur(Pile p);
Bool videPile(Pile);
void afficherPile(Pile p);
#endif
