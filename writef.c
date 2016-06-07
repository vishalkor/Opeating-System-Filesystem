#include "structures.h"

int writef(int fd,char *buffer,int count)
{
  int inodeno,temp,i,blockno;
  char *curr_time;
  time_t t;
  t=time(NULL);
  curr_time=ctime(&t);
  
  temp=UFDT[fd].ft_address;
  temp=ft[temp].iit_address;
  inodeno=iit[temp].inode_number;

  if(strcmp(iit[temp].file_open_mode,"O_WRONLY")==0 || (strcmp(iit[temp].file_open_mode,"O_RDWR")==0))
    {
      //get block number
      
      blockno=alloc();
      if(blockno==-1)
	return -1;
      
      //save data in datablock
      
      strcpy(DB[blockno].data,buffer);
      
      //update inode fields
      
      strcpy(inode[inodeno].inode_mod_time,curr_time);
      inode[inodeno].size=1024;
      inode[inodeno].actual_file_size=count;
      inode[inodeno].disk_address[0]=blockno;
      inode[inodeno].number_of_blocks_allocated++;
      strcpy(inode[inodeno].status,"unlock");
    }
  else
    return -1;
  //printinode(inodeno);
  return count;
}
