#include "file.h"

File filenouv(void){return NULL;}

File adjq(File f, int x)
{
	MaillonFile* m = (MaillonFile*) malloc(sizeof(MaillonFile));
	if(m == NULL)
	{
		fprintf(stderr, "E : malloc : adjq\n");
		exit(1);
	}

	m->v = x;
	if(videFile(f))
	{
		m->suiv = m;
		return m;
	}

	m->suiv = f->suiv;
	f->suiv = m;
	return m;
}

File suppressionFile(File f)
{
	MaillonFile* m;
	if(videFile(f))
	{
		fprintf(stderr, "E : OP interdite : défilage d'une file vide\n");
		exit(2);
	}

	if(f == f->suiv)
	{
		free(f);
		return filenouv();
	}
	m = f->suiv;
	f->suiv = m->suiv;
	free(m);
	return f;
}

int longueurFile(File f)
{
	MaillonFile* m;
	int l = 0;
	if(videFile(f))
	{
		return 0;
	}
	m = f->suiv;
	while(m != f)
	{
		++l;
		m = m->suiv;
	}

	return l;

}

Bool videFile(File f)
{
	if(f == NULL)
		return TRUE;
	return FALSE;
}
