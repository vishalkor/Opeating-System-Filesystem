#include "structures.h"

void initialize()
{
  int i;

  //initialize super block

  sb.file_size=5120;
  sb.maximum_files=MAXFILES;
  for(i=1;i<MAXFILES;i++)
    sb.free_inodes[i]=i;
  sb.free_inode_cnt=MAXFILES-1;
  for(i=0;i<MAXFILES;i++)
    sb.free_disk_blocks[i]=i;
  sb.free_disk_block_cnt=MAXFILES;
  sb.inode_alloc_count=0;
  //initialize IIT

  for(i=0;i<MAXOPENINODE;i++)
    {
      iit[i].inode_number=-1;
      iit[i].reference_count=0;
    }

  //initialize UFDT

  for(i=3;i<MAXOPENINODE;i++)
    UFDT[i].ft_address=-1;

  //initialize FT

  for(i=0;i<MAXOPENINODE;i++)
    ft[i].iit_address=-1;
  
  //initialize Directory

  //initialize root at dir[0] position
  
  dir[0].index[0]=0;
  dir[0].index[1]=-1;
  dir[0].inode_number[0]=0;
  dir[0].inode_number[1]=-1;
  dir[0].filecount=2;
  strcpy(dir[0].filename[0],".");
  strcpy(dir[0].filename[1],"..");
	  
  for(i=1;i<MAXFILES;i++)
    dir[i].filecount=0;

}


void printinit()
{
  int i,j;
  printf("\nmaximum files=%d",sb.maximum_files);
  printf("\nmaximum file size=%d",sb.file_size);
  printf("\nfree inode count=%d",sb.free_inode_cnt);
  printf("\nfree disk block count=%d",sb.free_disk_block_cnt);
  for(i=0;i<MAXOPENINODE;i++)
    printf("[%d-->%s-->%d] ",iit[i].inode_number,iit[i].file_open_mode,iit[i].reference_count);
  printf("\n\n");
  for(i=0;i<MAXOPENINODE;i++)
    printf("|%d| ",UFDT[i].ft_address);
  printf("\n\n");
  for(i=0;i<MAXOPENINODE;i++)
    printf("|%d-->%s| ",ft[i].iit_address,ft[i].file_open_mode);
  printf("\n\n");
  for(i=0;i<10;i++)
    {
      for(j=0;j<10;j++)
	printf("|%d-->%d-->%s-->%d| ",dir[i].index[j],dir[i].inode_number[j],dir[i].filename[j],dir[i].filecount);
      printf("\n");
    }
  printf("\n\n");
}

printinode(int in)
{						
  printf("\nuid=%d",inode[in].uid);
  printf("\ngid=%d",inode[in].gid);
  printf("\nfile_type=%s",inode[in].file_type);     
  printf("\nfile_permissions=%s",inode[in].file_permissions);     
  printf("\naccess_time=%s",inode[in].access_time);
  printf("\nmodified_time=%s",inode[in].modified_time);
  printf("\ninode_mod_time=%s",inode[in].inode_mod_time);
  printf("\ndisk_address=%d",inode[in].disk_address[0]);
  printf("\nstatus=%s",inode[in].status);
  printf("\nlinks=%d",inode[in].links);
  printf("\nsize=%d bytes",inode[in].size);
  printf("\nactual_file_size=%d bytes",inode[in].actual_file_size);
  printf("\nnumber_of_blocks_allocated=%d\n",inode[in].number_of_blocks_allocated);
  printf("\ndata=%s",DB[inode[in].disk_address[0]].data);
}
