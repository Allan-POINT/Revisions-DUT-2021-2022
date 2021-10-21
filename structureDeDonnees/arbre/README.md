# LES ARBRES BINAIRES

## Principe

Un arbre binaire est une structure de données qui permet d'organiser les données de manière à ce que leurs accès soit simple et efficace.

### Représentation

```
	50
       /  \
      /    \
     /      \
    /	     \
   25        75
  /  \      /  \
 /    \    /    \
10    30  85    100
```

## Structure

```C
typedef struct maillonArbre
{
	struct maillonArbre* arbreGauche;
	int v;
	struct maillonArbre* arbreDroit;
}MaillonArbre, *Arbre;
```
### Représentation en memoire

```
	       +---+---+---+
	 NULL<-|-^ |85 | --|->NULL
	       +---+---+---+
		 |
+---+---+---+  +---+---+---+  +---+----+---+
| | |50 | --|->| | +75 + --|->| | |100 | --|->NULL
+---+---+---+  +---+---+---+  +---+----+---+
  |                             |
  |                             V
  |                            NULL
+---+---+---+  +---+---+---+  
| V |25 | --|->| | +30 + --|->NULL
+---+---+---+  +---+---+---+
  |              |
  |		 V
  |             NULL
+---+---+---+
| V |10 | --|->NULL
+---+---+---+
  |
  V
 NULL

```
## Fonctions de bases

### Constructeur

```C
Arbre arbrenouv(void);
Arbre enracinement(Arbre g, int x, Arbre d);
```

### Sélecteurs

```C
Arbre arbreGauche(Arbre a);
Arbre arbreDroit(Arbre a);
int racine(Arbre a);
Arbre extremiteGauche(Arbre a);
Arbre extremiteDroite(Arbre a);
Arbre insererFeuille(Arbre a, int x);
Arbre suppressionArbre(Arbre a, int x);
```

### Autres

```C
Arbre oterMax(Arbre a);
Bool estTrie(Arbre a);
int max(int a, int b);
int hauteur(Arbre a);
Bool videArbre(Arbre a);
int nombreNoeud(Arbre a);
int nombreFeuille(Arbre a);
Bool estUneFeuille(Arbre a);
Bool egaliteArbre(Arbre a, Arbre b);
```
