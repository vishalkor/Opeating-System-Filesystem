#include "structures.h"

int rmdirf(char * pathname)
{
  int deldir,delinode,i,j,pardir,flag=0;
  char *p=pathname;

  /*
  char *tokens[PATHLENGTH];
  //tokenize pathname
  
  tokens[0]=strtok(p,"/");
  for(i=1;i<PATHLENGTH;i++)
    tokens[i]=strtok(NULL,"/");
  
  for(j=0;tokens[j]!=NULL;j++);
  
  printf("\ndeldir=%d",deldir);
  printf("\n%s",tokens[j-1]);
  
  for(i=0;i<dir[deldir].filecount;i++)
    {
      if(strcmp(tokens[j-1],dir[deldir].filename[i])==0)
	{
       	  flag=1;
	  break;
	}
    }
  if(flag!=1)
    return -1;
  */

  deldir=namei(pathname);
  delinode=dir[deldir].inode_number[0];

  ifree(delinode);

  //get parent dir

  pardir=dir[deldir].index[1];
  
  //remove corresp. dir

  for(i=0;i<dir[deldir].filecount;i++)
    {
      dir[deldir].index[i]=0;
      dir[deldir].inode_number[i]=0;
      strcpy(dir[deldir].filename[i],"\0");
    }
  dir[deldir].filecount=0;

  //remove dir entry from its parent

  for(i=0;i<dir[pardir].filecount;i++)
    {
      if(delinode==dir[pardir].inode_number[i])
	{
	  dir[pardir].index[i]=0;
	  dir[pardir].inode_number[i]=0;
	  strcpy(dir[pardir].filename[i],"\0");
	}
    }
    dir[pardir].filecount--;
  
  return 0;
}
