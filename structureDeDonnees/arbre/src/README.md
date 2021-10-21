# Explication des fonctions

## Arbrenouv

Cette fonction permer de créer un nouvel arbre, ce qui corespond à `NULL`.

```C
Arbre arbrenouv(void){return NULL;}
```

## Enracinement

Cette fonction permet de créer un arbre à partir de 2 autre avec une nouvelle racine x.

```C
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
```

## ArbreDroit/Gauche

Retourne simplement la parite droite/gauche d'un arbre ^^

```C
Arbre arbreDroit(Arbre a)
{
	if(videArbre(a))
	{
		fprintf(stderr, "E : OP : extraction d'un arbre vide:/\n");
		exit(2);
	}
	return a->arbreDroit;
}
```

```C
Arbre arbreGauche(Arbre a)
{
	if(videArbre(a))
	{
		fprintf(stderr, "E : OP : extraction d'un arbre vide:/\n");
		exit(2);
	}
	return a->arbreGauche;
}
```

## Racine

Retourne la racine d'un arbre

```C
int racine(Arbre a)
{
	if(videArbre(a))
	{
		fprintf(stderr, "E : OP : extraction d'un arbre vide :/\n");
		exit(2);
	}
	return a->v;
}
```

## videArbre (Test de vacuité)

```C
Bool videArbre(Arbre a)
{
	if(a == NULL)
		return TRUE;
	return FALSE;
}
```

## Max

Maximum entre 2 entier

```C
int max(int a, int b)
{
	return a>b?a:b;
}
```

## Hauteur

```C
int hauteur(Arbre a)
{
	if(videArbre(a))
		return -1;
	return max(hauteur(arbreGauche(a)), hauteur(arbreDroit(a))) + 1;
}
```

```C
max(hauteur(arbreGauche(a)), hauteur(arbreDroit(a))) + 1;
```

Prend la hauteur maximum entre les 2 arbres (droit et gauche) (la hauteur de l'arbre le plus long constitu par définition (vu qu'en fait ils appartiène au meme arbre à la base) la hauteur de l'arbre en entier -1(la racine)) et ajoute 1, ce qui corespond au sommet courant.

## NombreDeNœud

```C
int nombreNoeud(Arbre a)
{
	if(videArbre(a))
		return 0;
	return nombreNoeud(arbreGauche(a)) + nombreNoeud(arbreDroit(a)) + 1;
}
```

## EstUneFeuille

Un arbre une feuille si il est placé au plus bas de la structure. C'est à dire, si il n'a auccun successeurs (ni à droite, ni à gauche).

```C
Bool estUneFeuille(Arbre a)
{
	if(videArbre(a))
		return FALSE;
	return videArbre(arbreGauche(a)) && videArbre(arbreDroit(a));
}
```

## NombreDeFeuille

```C
int nombreFeuille(Arbre a)
{
	if(videArbre(a))
		return 0;
	if(estUneFeuille(a))
		return 1;
	return nombreFeuille(arbreGauche(a)) + nombreFeuille(arbreDroit(a));
}
```

## ExtremitéGauche/Droite

```C
Arbre extremiteGauche(Arbre a)
{
	if(videArbre(a))
		return a;
	if(videArbre(arbreGauche(a)))
		return enracinement(arbrenouv(), racine(a), arbrenouv());
	return extremiteGauche(arbreGauche(a));
}
```

vice-versa

```C
Arbre extremiteDroite(Arbre a)
{
	if(videArbre(a))
		return a;
	if(videArbre(arbreDroit(a)))
		return enracinement(arbrenouv(), racine(a), arbrenouv());
	return extremiteDroite(arbreGauche(a));
}
```

## test d'égalité

```C
Bool egaliteArbre(Arbre a, Arbre b)
{
	if(videArbre(a) && videArbre(b))
		return TRUE;
	if(videArbre(a) || videArbre(b))
		return FALSE;
	return racine(a) == racine(b) && egaliteArbre(arbreGauche(a), arbreGauche(b)) && egaliteArbre(arbreDroit(a), arbreDroit(b));
}
```

Si un des deux arbre est vide, c'est forcement qu'ils sont differrents car on test avant si les 2 arbres sont vide ensemble.

```C
if(videArbre(a) || videArbre(b))
	return TRUE;
```

## Inserssion

**ATTENTION!!!** C'est l'arbre gauche/droit qui est égal à la nouvelle insertion et **pas l'arbre en entier !!! :c**.

```C
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
```
## Suppression 

```C
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
```

Supprimer un element de l'arbre, c'est faire remonter l'arbre de gauche. On fait donc un nouvel arbre avec pour arbre de gauche, le même que l'arbre gauche original, à la différence prés quel'element le plus grand de l'arbre gauche est placé à la racine du nouvel arbre (l'arbre de droite reste le même).

```C
enracinement(oterMax(arbreGauche(a)), racine(extremiteDroite(arbreGauche(a))), arbreDroit(a));
```

**ATTENTION!!!** c'est **a->arbreGauche/Droite** qui est égale à l'arbre sans `x` et **pas l'arbre en entier !!! :/**

```C
if(x < racine(a))
{
	a->arbreGauche = suppressionArbre(arbreGauche(a), x);
	return a;
}
a->arbreDroit = suppressionArbre(arbreDroit(a), x);
return a;
```

### Fonction auxilière

```C
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
```

## Test de trie

* b1 : Est ce que la partie qui est sensé être la plus *petite* de l'arbre *gauche* est bien plus *petite* que la racine ?
* b2 : Est ce que la partie qui est sensé être la plus *grande* de l'arbre *droite* est bien plus *grande* que la racine ?
* b3 : Est ce que les sous arbres de `a` sont aussi triés ?

Si on respecte ces 3 conditions, ça veut dire que l'arbre est bien trié \\(^u^)/

```C
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
```
