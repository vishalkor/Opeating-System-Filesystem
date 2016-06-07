#include "structures.h"

int openf(char *pathname,char *flags)
{
  int inodeno,i,j,temp,ind;
  char *curr_time;
  char *tokens[PATHLENGTH];
  time_t t;
  t=time(NULL);
  curr_time=ctime(&t);

  //tokenize pathname
  
  tokens[0]=strtok(pathname,"/");
  for(i=1;i<PATHLENGTH;i++)
    tokens[i]=strtok(NULL,"/");

  for(i=0;tokens[i]!=NULL;i++);
  i--;
    
  ind=namei(pathname);
  for(j=0;j<dir[ind].filecount;j++)
    {
      if(strcmp(tokens[i],dir[ind].filename[j])==0)
	{
	  inodeno=dir[ind].inode_number[j];
	  break;
	}
    }
  
  
  if(inodeno==-1)
    return -1;
 
  //update inode fields

  if(strcmp(flags,"O_WRONLY")==0)
    strcpy(inode[inodeno].status,"lock");
  
  strcpy(inode[inodeno].access_time,curr_time);
  strcpy(inode[inodeno].inode_mod_time,curr_time);

  //update IIT

  for(i=0;i<MAXOPENINODE;i++)
    {
      if(iit[i].inode_number==-1)
	{
	  iit[i].inode_number=inodeno;
	  strcpy(iit[i].file_open_mode,flags);
	  iit[i].reference_count++;
	  break;
	}
    }
  temp=i;

  // update FT

  for(i=0;i<MAXOPENINODE;i++)
    {
      if(ft[i].iit_address==-1)
	{
	  ft[i].iit_address=temp;
	  strcpy(ft[i].file_open_mode,flags);
	  break;
	}
    }
  temp=i;

  //update UFDT

  for(i=0;i<MAXOPENINODE;i++)
    {
      if(UFDT[i].ft_address==-1)
	{
	  UFDT[i].ft_address=temp;
	  break;
	}
    }
  return i;
}
