#include "structures.h"

int rmf(char * pathname)
{
  char *p=pathname;
  int delfile,delinode,i,j,flag=0;
  char *tokens[PATHLENGTH];
  //tokenize pathname
  
  tokens[0]=strtok(p,"/");
  for(i=1;i<PATHLENGTH;i++)
    tokens[i]=strtok(NULL,"/");
  
  for(j=0;tokens[j]!=NULL;j++);
 

  //get index of corresp. dir

  delfile=namei(pathname);
  // printf("\nDelfile=%d",delfile);
 
  //remove entry from corresp. dir.
  
  for(i=2;i<dir[delfile].filecount;i++)
    {
      if(strcmp(tokens[j-1],dir[delfile].filename[i])==0)
	{
	  delinode=dir[delfile].inode_number[i];
	  dir[delfile].index[i]=0;
	  dir[delfile].inode_number[i]=0;
	  strcpy(dir[delfile].filename[i],"\0");
	  dir[delfile].filecount--;
	  flag=1;
	  break;
	}
    }
  if(flag!=1)
    return -1;

  //free inode 

  // printinode(delinode);
  freef(delinode);
  
  return 0;
}
