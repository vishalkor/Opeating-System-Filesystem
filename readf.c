#include "structures.h"

int readf(int fd,char *buffer,int count)
{
  int inodeno,temp,i,k=0,blockno[5],cnt,no_of_blocks;
  char *curr_time,ch;
  time_t t;
  t=time(NULL);
  curr_time=ctime(&t);
  
  //get inode from iit

  temp=UFDT[fd].ft_address;
  temp=ft[temp].iit_address;
  inodeno=iit[temp].inode_number;
  
  if(strcmp(iit[temp].file_open_mode,"O_WRONLY")!=0)
    {
      if(strcmp(inode[inodeno].file_permissions,"rrw-rw----")==0)
	{
	  //modify inode
	  
	  strcpy(inode[inodeno].access_time,curr_time);
	  strcpy(inode[inodeno].inode_mod_time,curr_time);
	  
	  // access disk blocks from inode

	  for(i=0;i<inode[inodeno].number_of_blocks_allocated;i++)
	    blockno[i]=inode[inodeno].disk_address[i];
	  no_of_blocks=inode[inodeno].number_of_blocks_allocated;

	  //access data from data block
	  
	  while(k<no_of_blocks)
	    {
	      for(i=0,cnt=count; cnt>0 && i<1024 ;cnt--,i++)
		  buffer[i]=DB[blockno[k]].data[i];
	      if(i==1024 || cnt==0)
		k++;
	      else 
		break;
	    }//while 
	  

	  /* for(i=0;i<11;i++)
	    buffer[i]=DB[blockno[0]].data[i];
	    buffer[i]='\0';*/
	}//if
      else
	return -1;
    }//if
  else
    return -1;
  return count;
}//readf

	  

	    
  
