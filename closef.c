#include "structures.h"

int closef(int fd)
{
  int t1,t2,t3;

  //update UFDT

  t1=UFDT[fd].ft_address;
  UFDT[fd].ft_address=-1;

  //update ft

  t2=ft[t1].iit_address;
  ft[t1].iit_address=-1;
  strcpy(ft[t1].file_open_mode,"\0");
  
  //update iit
  
  if(iit[t2].reference_count==1)
    {
      iit[t2].inode_number=-1;
      strcpy(iit[t2].file_open_mode,"\0");
      iit[t2].reference_count--;
    }
  else
    iit[t2].reference_count--;
  return 0;
}
  
  
