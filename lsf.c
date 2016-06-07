#include "structures.h"
extern int current_dir;
void lsf()
{
  int i;
  for(i=0;i<dir[current_dir].filecount;i++)
    printf("%s\n",dir[current_dir].filename[i]);
}
