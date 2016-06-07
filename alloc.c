#include "structures.h"

int alloc()
{
  int fb,i;
  if(sb.free_disk_block_cnt!=0)
    {
      fb=sb.free_disk_blocks[0];
      sb.free_disk_block_cnt--;
      for(i=0;i<sb.free_disk_block_cnt;i++)
	sb.free_disk_blocks[i]=sb.free_disk_blocks[i+1];
      return fb;
    }
  else
    return -1;
}
