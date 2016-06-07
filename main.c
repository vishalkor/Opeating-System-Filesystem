#include "structures.h"

main()
{
  int fd,retval;
  char buff[20]="first write";
  char *readbuff=(char *)malloc(sizeof(char));
  initialize();
  printinit();
  fd=createf("vish.txt","S_IRWXU");
  if(fd==-1)
    perror("file can't be created");
  printf("\n\nfd=%d\n",fd);
  fd=openf("vish.txt","O_RDWR");
  if(fd==-1)
    perror("file can't be open");
  else
    {
      printf("\n\nfd=%d\n",fd);
      printinit();
      retval=writef(fd,buff,11);
      printf("\n\nretval=%d\n",retval);
      retval=readf(fd,readbuff,11);
      printf("\n\nretval=%d\n",retval);
      printf("\n%s\n",readbuff);
    }
  closef(fd);
  printinit();
}
