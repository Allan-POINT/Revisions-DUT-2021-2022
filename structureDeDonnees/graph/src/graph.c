#include "graph.h"

Graph graphnouv(void){return NULL;}
Graph adjonctionSommetEnTete(Graph g, int x)
{
	MaillonGraph* m = malloc(sizeof(MaillonGraph));
	if(m == NULL)
	{
		fprintf(stderr, "E : malloc : adjs\n");
		exit(1);
	}
	m->v = x;
	m->successeurs = listNouv();
	m->suiv = g;
	return m;
}
Graph adjonctionSommet(Graph g, int x)
{
	if(videGraph(g))
		return adjonctionSommetEnTete(g, x);
	if(g->v == x)
		return g;
	if(g->v < x)
		return adjonctionSommetEnTete(g, x);
	g->suiv = adjonctionSommet(g->suiv, x);
	return g;
}

Graph adjonctionArc(Graph g, int a, int b)
{
	Graph aux;
	if(!existSommet(g, a) || !existSommet(g, b))
		return g;
	if(existArc(g, a, b))
		return g;
	aux = g;
	while(g->v != a)
	{
		g = g->suiv;
	}
	g->successeurs = ajouterList(g->successeurs, b);
	return aux;
}

Bool existArc(Graph g, int a, int b)
{
	if(!existSommet(g, a) || !existSommet(g, a))
		return FALSE;
	while(g->v != a)
	{
		g = g->suiv;
	}
	return estDansLaListe(g->successeurs, b);
}

Bool existSommet(Graph g, int x)
{
	if(videGraph(g))
		return FALSE;
	while(!videGraph(g))
	{
		if(g->v == x)
			return TRUE;
		g = g->suiv;
	}
	return FALSE;
}

Graph suppressionSommet(Graph g, int x)
{
	Graph save = g, aux;
	if(!existSommet(g, x))
		return g;
	while(g->v != x)
	{
		aux = g;
		g = g->suiv;
	}
	if(!listVide(g->successeurs))
	{
		fprintf(stderr, "E : OP : suppression d'un sommet avec des succèsseurs :/\n");
		exit(2);
	}
	aux->suiv = g->suiv;
	free(g);
	return save;
}

Graph suppressionArc(Graph g, int a, int b)
{
	Graph save = g;
	if(!existArc(g, a, b))
		return g;
	while(g->v != a)
	{
		g = g->suiv;
	}
	g->successeurs = suppressionList(g->successeurs, b);
	return save;
}

Bool videGraph(Graph g)
{
	if(g == NULL)
		return TRUE;
	return FALSE;
}

void afficherGraph(Graph g)
{
	FILE* flot;
	Graph aux = g;
	List l;

	flot = fopen("graph.txt", "w");
	if(flot == NULL)
	{
		fprintf(stderr, "E : fopen\n");
		exit(4);
	}

	fprintf(flot, "digraph family\n{\n");
	while(!videGraph(g))
	{
		fprintf(flot, "%d [label=\"%d\"]\n", g->v, g->v);
		g = g->suiv;
	}
	while(!videGraph(aux))
	{
		l = aux->successeurs;
		while(listVide(l))
		{
			fprintf(flot, "%d->%d\n", aux->v, l->value);
			l = l->next;
		}
		aux = aux->suiv;
	}
	fprintf(flot, "}\n");
	fclose(flot);
	system("dotty graph.txt");
}

List ensembleSuccesseurs(Graph g, int x)
{
	if(!existSommet(g, x))
		return listNouv();
	while(g->v != x)
	{
		g = g->suiv;
	}
	return g->successeurs;
}

List parcoursEnProfondeur(Graph g, List e, List l)
{
	int z;
	List l1;
	if(listVide(e))
		return l;
	z = teteList(e);
	if(estDansLaListe(l, z))
		l1 = l;
	else
		l1 = parcoursEnProfondeur(g, ensembleSuccesseurs(g, z), ajouterList(l, z));
	return parcoursEnProfondeur(g, suppressionList(e, z), l1);
}
