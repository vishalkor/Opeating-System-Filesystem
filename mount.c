#include "structures.h"

void mount(char *fsname)
{
  FILE *fp;
  int sz,sz1,i;
  char ch;
  fp=fopen(fsname,"r");
  if(fp==NULL)
    {
      perror("file does not exits");
    }
  else
    {
       //store super block

      fscanf(fp,"%d",&(sb.file_size));
      fscanf(fp,"%c%d",&ch,&(sb.maximum_files));
      fscanf(fp,"%c%d",&ch,&(sb.free_inode_cnt));
      for(i=1;i<sb.free_inode_cnt;i++)
	{
	  fprintf(fp,"%d",sb.free_inodes[i]);
	  fprintf(fp,"%c",' ');
	}
    }
  fclose(fp);
}
      /*fprintf(fp,"%c",',');
     
      fprintf(fp,"%c",',');
      
      fprintf(fp,"%c",',');
      
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
      */
