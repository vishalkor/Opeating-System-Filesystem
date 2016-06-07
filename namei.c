#include "structures.h"
extern int current_dir;
int namei(char *pathname)
{
  int i,j,search=current_dir,tempsearch;
  char *tokens[PATHLENGTH];
  //tokenize pathname
  
  tokens[0]=strtok(pathname,"/");
  for(i=1;i<PATHLENGTH;i++)
    tokens[i]=strtok(NULL,"/");
  
  for(i=0;tokens[i]!=NULL;i++)
    {
      for(j=0;j<dir[search].filecount;j++)
	{
	  if(strcmp(dir[search].filename[j],tokens[i])==0)
	    {
	      if(dir[search].index[j]==-1)
		return search;
	      else
		{
		  tempsearch=dir[search].index[j];
		  break;
		}
	    }//if
	}//inner for
      if(j==dir[search].filecount)
	{
	  strcpy(dir[search].filename[dir[search].filecount],tokens[i]);
	  return search; 
	}
      search=tempsearch;
    }//outer for
  return search;
}
