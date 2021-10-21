#ifndef __FILE_1_H__
#define __FILE_1_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct maillonFile
{
	struct maillonFile* suiv;
	int v;
}MaillonFile;

typedef struct MaillonFile *File;

File filenouv(void);
File adjq(File f, int x);
File suppressionEnTete(File f);
int longueurFile(File f);

#endif
