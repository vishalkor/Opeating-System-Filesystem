#include "structures.h"

void freef(int inodeno)
{
  int datarr[5],i,blk;
  
  //copy data block addresses into datarr array

  for(i=0;i<5;i++)
    datarr[i]=inode[inodeno].disk_address[i];

  blk=inode[inodeno].number_of_blocks_allocated;

  //free inode
 
  inode[inodeno].uid=0;
  inode[inodeno].gid=0;
  strcpy(inode[inodeno].file_type,"\0");
  strcpy(inode[inodeno].file_permissions,"\0");
  strcpy(inode[inodeno].access_time,"\0");
  strcpy(inode[inodeno].modified_time,"\0");
  strcpy(inode[inodeno].inode_mod_time,"\0");
  for(i=0;i<5;i++)
    inode[inodeno].disk_address[i]=-1;
  strcpy(inode[inodeno].status,"unlock");
  inode[inodeno].links=0;
  inode[inodeno].size=0;
  inode[inodeno].actual_file_size=0;
  inode[inodeno].number_of_blocks_allocated=0;
  
  //free datablocks of corresp. inode

  for(i=0;i<blk;i++)
    strcpy(DB[datarr[i]].data,"\0");

  //update super block
  
  sb.free_inodes[sb.free_inode_cnt]=inodeno;
  sb.free_inode_cnt++;
  for(i=0;i<blk;i++)
    {
      sb.free_disk_blocks[sb.free_disk_block_cnt]=datarr[i];
      sb.free_disk_block_cnt++;
    }
}

