#include "list.h"

List listNouv(void){ return NULL;}

List ajoutTeteList(List l, int x)
{
	Maillonl *m;
	m = (Maillonl*) malloc(sizeof(Maillonl));

	if(m == NULL)
	{
		fprintf(stderr, "E: Allocation dynamique pour ajouter maillon dans la tete impossible\n");
		exit(1);
	}
	m->value= x;
	m->next = l;
	return m;
}

List ajouterList(List l, int x)
{
	if(listVide(l))
	{
		return ajoutTeteList(l, x);
	}
	if(l->value > x)
	{
		l = ajoutTeteList(l, x);
	}
	if(l->value < x)
	{
		l->next = ajouterList(l->next, x);
	}
	return l;

}

List suppressionTeteList(List l)
{
	if(listVide(l))
	{
		fprintf(stderr, "E:Operation interdite:suppression list vide\n");
		exit(2);
	}

	Maillonl* m;
	m = l;
	l = l->next;
	free(m);
	return l;
}

List suppressionQueueList(List l)
{
	Maillonl* m;

	if(listVide(l))
	{
		fprintf(stderr, "E:Operation interdite:suppression list vide\n");
		exit(2);
	}

	if(longueurList(l) == 1)
	{
		free(l);
		return listNouv();
	}
	m = l;
	while(m->next != NULL)
	{
		m = m->next;	
	}
	free(m);
	return l;
}

List suppressionList(List l, int x)
{
	if(listVide(l))
	{
		fprintf(stderr, "E:Operation interdite:suppression list vide\n");
		exit(2);
	}

	if(longueurList(l) == 1)
	{
		return suppressionTeteList(l);
	}
	if(l->value == x)
	{
		l = suppressionTeteList(l);
	}
	if(l->value <= x)
	{
		l->next = suppressionList(l->next, x);
	}
	return l;
}

int teteList(List l)
{
	if(listVide(l))
	{
		fprintf(stderr, "E:Operation interdite:acceder list vide\n");
		exit(2);
	}
	return l->value;
}

int longueurList(List l)
{
	if(listVide(l))
	{
		return 0;
	}
	return 1 + longueurList(l->next);
}

void afficherList(List l)
{
	while(!listVide(l))
	{
		printf("%d ", l->value);
		l = l->next;
	}
	printf("\n");
}

Bool listVide(List l)
{
	if(l == NULL)
		return TRUE;
	return FALSE;
}

int getList(List l, int index)
{
	for(int i=0; i<index; ++i)
	{
		l = l->next;
	}
	return l->value;
}

Bool estDansLaListe(List l, int x)
{
	while(!listVide(l))
	{
		if(l->value == x)
			return TRUE;
		l = l->next;
	}
	return FALSE;
}

List copierListe(List l)
{
	List cpy = listNouv();

	while(!listVide(l))
	{
		cpy = ajouterList(cpy, l->value);
		l = l->next;
	}
	return cpy;
}
