#include "file.h"

File filenouv(void)
{
	File f;
	f.t = NULL;
	f.q = NULL;

	return f;
}

File adjq(File f, int x)
{
	MaillonFile* m;
	m = (MaillonFile*) malloc(sizeof(MaillonFile));
	if(m == NULL)
	{
		fprintf(stderr, "E : malloc : adjq\n");
		exit(1);
	}
	m->v = x;
	m->suiv = NULL;
	if(videFile(f))
	{
		f.t = m; f.q = m;
		return f;
	}
	f.q->suiv = m;
	f.q = m;
	return f;
}

File suppressionFile(File f)
{
	MaillonFile* m;

	if(videFile(f))
	{
		fprintf(stderr, "E : OP : défilage de file vide:/\n");
		exit(2);
	}

	if(f.q == f.t)
	{
		free(f.t);
		return filenouv();
	}
	
	m = f.t;
	f.t = f.t->suiv;
	free(m);
	return f;
}

int longueurFile(File f)
{
	int i=0;
	if(videFile(f))
	{
		return i;
	}
	while(f.t != f.q)
	{
		++i;
		f.t = f.t->suiv;
	}
	return i;
}

Bool videFile(File f)
{
	if(f.t == NULL && f.q == NULL)
		return TRUE;
	if(f.t == NULL || f.q == NULL)
	{
		fprintf(stderr, "Erreur interne:/\n");
		exit(3);
	}
	return FALSE;
}
