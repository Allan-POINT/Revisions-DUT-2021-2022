# MÉTHODE 1

## Structure

```C
typedef MaillonFile* File;
```

```C
typedefStruct maillonFile
{
	struct maillonFile* suiv;
	int v;
}MaillonFile;
```

### Fonctions

```C
File filenouv(void);
File adjq(File f, int x);
File suppressionEnTete(File f);
int longueurFile(File f);
Bool videFile(File f);
```
