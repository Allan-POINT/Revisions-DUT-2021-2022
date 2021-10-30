#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

typedef struct maillonl
{
	int value;
	struct maillonl* next;
}Maillonl, *List;

List listNouv(void);
List ajoutTeteList(List l, int x);

List ajouterList(List l, int x);
List suppressionTeteList(List l);
List suppressionQueueList(List l);
List suppressionList(List l, int x);
int teteList(List l);
int getList(List l, int index);
int longueurList(List l);
void afficherList(List l);
Bool listVide(List l);
Bool estDansLaListe(List l, int x);
List copierListe(List l);

#endif
