#include "structures.h"
extern int current_dir;
int mkdirf(char *pathname,char *mode)
{
  int inodeno,i,temp,ind;
  char *curr_time;
  time_t t;
  t=time(NULL);
  curr_time=ctime(&t);

  // get inode by ialloc

  inodeno=ialloc();
  if(inodeno==-1)
    return -1;

  // initialize inode

  inode[inodeno].uid=34;
  inode[inodeno].gid=50;
  strcpy(inode[inodeno].file_type,"directory");
  strcpy(inode[inodeno].file_permissions,"rrwxrwx---");
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
 
  ind=namei(pathname);
  current_dir=ind;
  for(i=1;i<MAXFILES;i++)
    {
      if(dir[i].filecount==0)
	break;
    }

  dir[i].index[0]=i;
  dir[i].index[1]=ind;
  dir[i].inode_number[0]=inodeno;
  dir[i].inode_number[1]=dir[ind].inode_number[0];
  dir[i].filecount=2;
  strcpy(dir[i].filename[0],".");
  strcpy(dir[i].filename[1],"..");
  
  dir[ind].index[dir[ind].filecount]=i;
  dir[ind].inode_number[dir[ind].filecount]=inodeno;
  dir[ind].filecount++;
  return 0;
  
}
  
  
