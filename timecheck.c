#include "structures.h"

void current_time()
{
  int ct;
  char *curtime;
  time_t t;
  t=time(NULL);
  curtime=ctime(&t);
  printf("cur time=%s",ctime(&t));
  printf("cur time=%s",curtime);
}
