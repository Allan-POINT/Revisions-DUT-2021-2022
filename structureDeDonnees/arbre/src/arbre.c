#include "arbre.h"

Arbre arbrenouv(void){return NULL;}

Arbre enracinement(Arbre g, int x, Arbre d)
{
	MaillonArbre* m = (MaillonArbre*) malloc(sizeof(MaillonArbre));
	if(m == NULL)
	{
		fprintf(stderr, "E : malloc : enracinement\n");
		exit(1);
	}
	m->arbreGauche = g;
	m->v = x;
	m->arbreDroit = d;

	return m;
}

Arbre arbreDroit(Arbre a)
{
	if(videArbre(a))
	{
		fprintf(stderr, "E : OP : extraction d'un arbre vide:/\n");
		exit(2);
	}
	return a->arbreDroit;
}

Arbre arbreGauche(Arbre a)
{
	if(videArbre(a))
	{
		fprintf(stderr, "E : OP : extraction d'un arbre vide:/\n");
		exit(2);
	}
	return a->arbreGauche;
}

int racine(Arbre a)
{
	if(videArbre(a))
	{
		fprintf(stderr, "E : OP : extraction d'un arbre vide :/\n");
		exit(2);
	}
	return a->v;
}

Bool videArbre(Arbre a)
{
	if(a == NULL)
		return TRUE;
	return FALSE;
}

int max(int a, int b)
{
	return a>b?a:b;
}
int hauteur(Arbre a)
{
	if(videArbre(a))
		return -1;
	return max(hauteur(arbreGauche(a)), hauteur(arbreDroit(a))) + 1;
}

int nombreNoeud(Arbre a)
{
	if(videArbre(a))
		return 0;
	return nombreNoeud(arbreGauche(a)) + nombreNoeud(arbreDroit(a)) + 1;
}

Bool estUneFeuille(Arbre a)
{
	if(videArbre(a))
		return FALSE;
	return videArbre(arbreGauche(a)) && videArbre(arbreDroit(a));
}

int nombreFeuille(Arbre a)
{
	if(videArbre(a))
		return 0;
	if(estUneFeuille(a))
		return 1;
	return nombreFeuille(arbreGauche(a)) + nombreFeuille(arbreDroit(a));
}

Arbre extremiteGauche(Arbre a)
{
	if(videArbre(a))
		return a;
	if(videArbre(arbreGauche(a)))
		return enracinement(arbrenouv(), racine(a), arbrenouv());
	return extremiteGauche(arbreGauche(a));
}

Arbre extremiteDroite(Arbre a)
{
	if(videArbre(a))
		return a;
	if(videArbre(arbreDroit(a)))
		return enracinement(arbrenouv(), racine(a), arbrenouv());
	return extremiteDroite(arbreGauche(a));
}

Bool egaliteArbre(Arbre a, Arbre b)
{
	if(videArbre(a) && videArbre(b))
		return TRUE;
	if(videArbre(a) || videArbre(b))
		return FALSE;
	return racine(a) == racine(b) && egaliteArbre(arbreGauche(a), arbreGauche(b)) && egaliteArbre(arbreDroit(a), arbreDroit(b));
}

Arbre insererFeuille(Arbre a, int x)
{
	if(videArbre(a))
		return enracinement(arbrenouv(), x, arbrenouv());
	if(x == racine(a))
		return a; // Pour interdire les doublons ^^
	if(x < racine(a))
	{
		a->arbreGauche = insererFeuille(arbreGauche(a), x);
		return a;
	}
	a->arbreDroit = insererFeuille(arbreDroit(a), x);
	return a;

}

Arbre oterMax(Arbre a)
{
	if(videArbre(a))
		return a;
	if(videArbre(arbreDroit(a)))
	{
		return arbreGauche(a);
	}
	a->arbreDroit = oterMax(arbreDroit(a));
	return a;
}

Arbre suppressionArbre(Arbre a, int x)
{
	Arbre aux;
	if(videArbre(a))
		return a;
	if(x == racine(a))
	{
		if(videArbre(arbreGauche(a)))
			return arbreDroit(a);
		if(videArbre(arbreDroit(a)))
			return arbreGauche(a);
		aux = enracinement(oterMax(arbreGauche(a)), racine(extremiteDroite(arbreGauche(a))), arbreDroit(a));
		free(a);
		return aux;
	}
	if(x < racine(a))
	{
		a->arbreGauche = suppressionArbre(arbreGauche(a), x);
		return a;
	}
	a->arbreDroit = suppressionArbre(arbreDroit(a), x);
	return a;
}

Bool estTrie(Arbre a)
{
	Bool b1, b2, b3;
	if(videArbre(a))
	{
		return TRUE;
	}
	
	if(videArbre(arbreGauche(a)))
	{
		b1 = TRUE;
	}
	else
	{
		b1 = racine(extremiteDroite(arbreGauche(a))) < racine(a);
	}

	if(videArbre(arbreDroit(a)))
	{
		b2 = TRUE;
	}
	else
	{
		b2 = racine(extremiteGauche(arbreDroit(a))) > racine(a);
	}
	b3 = estTrie(arbreDroit(a)) && estTrie(arbreGauche(a));
	return b1 && b2 && b3;
}
