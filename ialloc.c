#include "structures.h"

int ialloc()
{
  int in,i;
  if(sb.free_inode_cnt!=0)
    {
      in=sb.free_inodes[1];
      sb.free_inode_cnt--;
      sb.allocated_inodes[sb.inode_alloc_count]=in;
      sb.inode_alloc_count++;
      for(i=1;i<sb.free_inode_cnt;i++)
	sb.free_inodes[i]=sb.free_inodes[i+1];
      return in;
    }
  else
    return -1;
}
