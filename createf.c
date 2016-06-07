#include "structures.h"

int createf(char *pathname,char *mode)
{
  int inodeno,temp,i,ind;
  char *curr_time;
  time_t t;
  t=time(NULL);
  curr_time=ctime(&t);
  // get inode by ialloc

  inodeno=ialloc();
  if(inodeno==-1)
    return -1;

  ind=namei(pathname);
  
  dir[ind].index[dir[ind].filecount]=-1;
  dir[ind].inode_number[dir[ind].filecount]=inodeno;
  dir[ind].filecount++;

  // initialize inode

  inode[inodeno].uid=34;
  inode[inodeno].gid=50;
  strcpy(inode[inodeno].file_type,"regular");
  strcpy(inode[inodeno].file_permissions,"rrw-rw----");
  strcpy(inode[inodeno].access_time,curr_time);
  strcpy(inode[inodeno].modified_time,curr_time);
  strcpy(inode[inodeno].inode_mod_time,curr_time);
  for(i=0;i<5;i++)
    inode[inodeno].disk_address[i]=-1;
  strcpy(inode[inodeno].status,"unlock");
  inode[inodeno].links=1;
  inode[inodeno].size=0;
  inode[inodeno].actual_file_size=0;
  inode[inodeno].number_of_blocks_allocated=0;
  
  
  //update IIT
  
  for(i=0;i<MAXOPENINODE;i++)
    {
      if(iit[i].inode_number==-1)
	{
	  iit[i].inode_number=inodeno;
	  strcpy(iit[i].file_open_mode,mode);
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
	  strcpy(ft[i].file_open_mode,mode);
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
  temp=i;
  
  return temp;
}

