#ifndef __FILE_2_H__
#define __FILE_2_H__

#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

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

File filenouv(void);
File adjq(File f, int x);
File suppresionFile(File f);
int longueurFile(File f);
Bool videFile(File f);

#endif
