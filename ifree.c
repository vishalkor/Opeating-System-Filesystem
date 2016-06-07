#include "structures.h"

void ifree(int inodeno)
{
  int i;
  //update super block

  sb.free_inodes[sb.free_inode_cnt]=inodeno;
  sb.free_inode_cnt++;

  for(i=0;i<sb.inode_alloc_count;i++)
    {
      if(inodeno==sb.allocated_inodes[i])
	{
	  while(i<sb.inode_alloc_count)
	    {
	      sb.allocated_inodes[i]=sb.allocated_inodes[i+1];
	      i++;
	    }
	  break;
	}
    }
  sb.inode_alloc_count++;

  //free inode
  
  inode[inodeno].uid=34;
  inode[inodeno].gid=50;
  strcpy(inode[inodeno].file_type,"\0");
  strcpy(inode[inodeno].file_permissions,"\0");
  strcpy(inode[inodeno].access_time,"\0");
  strcpy(inode[inodeno].modified_time,"\0");
  strcpy(inode[inodeno].inode_mod_time,"\0");
  for(i=0;i<5;i++)
    inode[inodeno].disk_address[i]=-1;
  strcpy(inode[inodeno].status,"\0");
  inode[inodeno].links=0;
  inode[inodeno].size=0;
  inode[inodeno].actual_file_size=0;
  inode[inodeno].number_of_blocks_allocated=0;

}
