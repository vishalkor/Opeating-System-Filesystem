#include<stdio.h>
#include<string.h>

main()
{
  int i;
  char s1[20]="vish";
  char *s2[10];
  // for(i=0;i<10;i++)
  s2[0]=strtok(s1,"/");
  printf("s2===%s\n",s2[0]);
  /*
  s3=strtok(NULL,"/");
  printf("s3===%s\n",s3);
  s4=strtok(NULL,"/");
  printf("s4===%s\n",s4);
  s5=strtok(NULL,"/");
  printf("s5===%s\n",s5);
  */
  for(i=1;i<10;i++)
    {
      s2[i]=strtok(NULL,"/");
      printf("s2=%s\n",s2[i]);
    }
}
