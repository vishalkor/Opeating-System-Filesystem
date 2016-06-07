#include "structures.h"
extern int current_dir;
int chdirf(char *pathname)
{
  int i;
  //char *tokens[PATHLENGTH];
  //tokenize pathname
  
  /* tokens[0]=strtok(pathname,"/"); */
  /* for(i=1;i<PATHLENGTH;i++) */
  /*   tokens[i]=strtok(NULL,"/"); */
  // printf("\n %d",curr_dir);
  if(strcmp(pathname,"/")==0)
    return 0;
  else if(strcmp(pathname,".")==0)
    return current_dir;
  else if(strcmp(pathname,"..")==0)
    {
      if(current_dir==0)
	return current_dir;
      return (dir[current_dir].index[1]);
    }
  else
    return (namei(pathname));
}
