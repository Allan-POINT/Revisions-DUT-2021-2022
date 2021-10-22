#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include <stdlib.h>
#include "bool.h"
#include "list.h"

typedef struct maillonGraph
{
	struct maillonGraph* suiv;
	List successeurs;
	int v;
}MaillonGraph, *Graph;

Graph graphnouv(void);
Graph adjonctionSommetEnTete(Graph g, int x);
Graph adjonctionSommet(Graph g, int x);
Graph adjonctionArc(Graph g, int a, int b);

Bool videGraph(Graph g);
Bool existArc(Graph g, int a, int b);
Bool existSommet(Graph g, int x);

Graph suppressionSommet(Graph g, int x);
Graph suppressionArc(Graph g, int a, int b);

void afficherGraph(Graph g);


#endif
