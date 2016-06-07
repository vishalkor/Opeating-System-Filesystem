#include "structures.h"

void unmount(char *fsname)
{
  FILE *fp;
  int fd,i,j,n,cnt=0,inodeno;
  //  fd=creat("filedisk.txt",S_IRWXU);
  fp=fopen(fsname,"w");
  if(fp==NULL)
    {
      perror("file does not exits");
    }
  else
    {
      //store super block

      fprintf(fp,"%d",sb.file_size);
      fprintf(fp,"%c",',');
      fprintf(fp,"%d",sb.maximum_files);
      fprintf(fp,"%c",',');
      fprintf(fp,"%d",sb.free_inode_cnt);
      fprintf(fp,"%c",',');
      for(i=1;i<sb.free_inode_cnt;i++)
	{
	  fprintf(fp,"%d",sb.free_inodes[i]);
	  fprintf(fp,"%c",' ');
	}
      fprintf(fp,"%c",',');
      
      fprintf(fp,"%d",sb.free_disk_block_cnt);
      fprintf(fp,"%c",',');
      for(i=0;i<sb.free_disk_block_cnt;i++)
	{
	  fprintf(fp,"%d",sb.free_disk_blocks[i]);
	  fprintf(fp,"%c",' ');
	}
      fprintf(fp,"%c",',');
      
      fprintf(fp,"%d",sb.inode_alloc_count);
      fprintf(fp,"%c",',');
      for(i=0;i<sb.inode_alloc_count;i++)
	{
	  fprintf(fp,"%d",sb.allocated_inodes[i]);
	  fprintf(fp,"%c",' ');
	}
      
      fprintf(fp,"%c%c%c",'*','*','*');

      //store inode block
      printf("\ninode alloc count=%d",sb.inode_alloc_count);
      for(i=0;i<sb.inode_alloc_count;i++)
	{
	  inodeno=sb.allocated_inodes[i];
	  fprintf(fp,"%d",inodeno);
	  fprintf(fp,"%c",'-');
	  fprintf(fp,"%d",inode[inodeno].uid);
	  fprintf(fp,"%c",' ');
	  fprintf(fp,"%d",inode[inodeno].gid);
	  fprintf(fp,"%c",' ');
	  fprintf(fp,"%s",inode[inodeno].file_type);
	  fprintf(fp,"%c",' ');
	  fprintf(fp,"%s",inode[inodeno].file_permissions);
	  fprintf(fp,"%c",' ');
	  fprintf(fp,"%s",inode[inodeno].access_time);
	  fprintf(fp,"%c",' ');
	  fprintf(fp,"%s",inode[inodeno].modified_time);
	  fprintf(fp,"%c",' ');
	  fprintf(fp,"%s",inode[inodeno].inode_mod_time);
	  fprintf(fp,"%c",' ');
	  fprintf(fp,"%s",inode[inodeno].status);
	  fprintf(fp,"%c",' ');
	  fprintf(fp,"%d",inode[inodeno].links);
	  fprintf(fp,"%c",' ');
	  fprintf(fp,"%d",inode[inodeno].size);
	  fprintf(fp,"%c",' ');
	  fprintf(fp,"%d", inode[inodeno].actual_file_size);
	  fprintf(fp,"%c",' ');
	  fprintf(fp,"%d",inode[inodeno].number_of_blocks_allocated);
	  fprintf(fp,"%c",' ');
	  for(j=0;j<5;j++)
	    {
	      fprintf(fp,"%d",inode[inodeno].disk_address[i]);
	      fprintf(fp,"%c",' ');
	    }
	  fprintf(fp,"%c",'#');
	}//for
      
      fprintf(fp,"%c%c%c",'*','*','*');
      //store datablock
      
      for(i=0;i<MAXFILES;i++)
	{
	  if(strlen(DB[i].data)==0)
	    {
	      fprintf(fp,"%c",'0');
	      fprintf(fp,"%c",'|');
	    }
	  else
	    {
	      fprintf(fp,"%s",DB[i].data);
	      fprintf(fp,"%c",'|');
	    }
	}
      fprintf(fp,"%c%c%c",'*','*','*');

      //store directory

      for(i=0;i<MAXFILES;i++)
	{
	  if(dir[i].filecount==0)
	    {
	      fprintf(fp,"%c",'0');
	      fprintf(fp,"%c",'|');
	    }
	  else
	    {
	      fprintf(fp,"%c%d%c%d%c",'(',i,',',dir[i].filecount,')');
	      fprintf(fp,"%c",'-');
	      for(j=0;j<dir[i].filecount;j++)
		{
		  fprintf(fp,"%d%c",dir[i].index[j],',');
		  fprintf(fp,"%d%c",dir[i].inode_number[j],',');
		  fprintf(fp,"%d%c",dir[i].index[j],',');
		  fprintf(fp,"%s%c",dir[i].filename[j],'|');
		}
	    }
	}
      fclose(fp);
    }//else
}//unmount

