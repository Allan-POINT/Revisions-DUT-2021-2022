# MÉTHODE 2

## Structure

```C
typedef struct maillonFile
{
	struct maillonFile* suiv;
	int v;
}MaillonFile;

typedef struct
{
	MaillonFile* t;
	MaillonFile* q;
}File;
```

## Fonctions

```C
File filenouv(void);
File adjq(File f, int x);
File suppresionFile(File f);
int longueurFile(File f);
Bool videFile(File f);
```
