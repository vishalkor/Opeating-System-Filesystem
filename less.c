#include "structures.h"

void less(char *filename)
{
  int fd,temp,inodeno,size;
  char *buff=(char *)malloc(sizeof(char));
  fd=openf(filename,"O_RDONLY");
  
  if(fd==-1)
    perror("\nFile not found");
  else
    {
      //get actual file size from its inode
      
      temp=UFDT[fd].ft_address;
      temp=ft[temp].iit_address;
      inodeno=iit[temp].inode_number;
      size=inode[inodeno].actual_file_size;
      readf(fd,buff,size);
    }
  printf("\n%s",buff);
}
  
