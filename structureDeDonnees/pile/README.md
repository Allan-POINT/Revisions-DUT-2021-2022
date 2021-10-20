# LES PILES

## Principes

Les piles sont des structures de données.
Elles sont chaînées.
Le principe est de travailler uniquement avec la dérnière valeur empliée. En suite il sufit de dépiler pour acceder à la valeur précédament enregistrée jusqu'à ce que la pile soit vide.

## structure

```C
typedef struct maillonPile
{
	struct maillonPile* suiv;
	int valeur;
}MaillonPile, *Pile;
```

## Fonctions de bases

### Constructeurs

```C
Pile creerPile(void);
Pile empliler(Pile p, int x);
```
À partir de ces 2 fonctions, il est possible de créer n'importe quelle pile.

### Sélecteurs

```C
int sommet(Pile p); // retoune l'élément en haut de la pile
int hauteur(Pile p); //retourne le nombre d'élément de la pile
Bool pileVide(Pile p); // retourne un booléen qui permet de dire si une pile contient des élements
```
