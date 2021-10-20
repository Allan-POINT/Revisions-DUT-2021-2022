#include "pile.h"

Pile pilenouv(void){return NULL;}

Pile empiler(Pile p, int x)
{
	MaillonPile* m;
	m = (MaillonPile*) malloc(sizeof(MaillonPile));

	if(m == NULL)
	{
		fprintf(stderr, "E : malloc\n");
		exit(1);
	}

	m->v = x;
	m->suiv = p;

	return m;
}

Pile depiler(Pile p)
{
	MaillonPile* m;
	if(videPile(p))
	{
		return p;
	}

	m = p->suiv;
	free(p);

	return m;
}

Bool videPile(Pile p)
{
	if(p == NULL)
		return TRUE;
	return FALSE;
}

int hauteur(Pile p)
{
	int i = 0;
	while(!videPile(p))
	{
		++i;
		p = p->suiv;
	}

	return i;
}

void afficherPile(Pile p)
{
	while(!videPile(p))
	{
		printf("%d ", p->v);
		p = p->suiv;
	}
	printf("\n");
}
