#include "structures.h"
int current_dir=0;
main()
{
  char ch,cmd[30],t1[20],t2[20],t3[20],t4[20],t5[20],myfs[30];
  int fd,retval,inodeno,size,temp,n,choice;
  char *buff3=(char *)malloc(sizeof(char));
  char *readbuff1=(char *)malloc(sizeof(char));
  char *buff2=malloc(sizeof(char));
  
  while(1)
    {
      printf("\nMYSHELL:~/$ ");
      gets(cmd);

      //tokenize string

      n= sscanf(cmd,"%s%s%s%s",t1,t2,t3,t4);
      
      
      //check commands

      // exit

      if(n==1)
	{
	  if(strcmp(t1,"exit")==0)
	    kill(getpid(),9);
	  else if(strcmp(t1,"ls")==0)
	    lsf();
	  else if(strcmp(t1,"unmount")==0)
	    {
	      printf("\nDo you want to save this filesystem (y/n):");
	      scanf("%c",&ch);
	      if(ch=='y')
		{
		  printf("\nGive name for this file system:\n");
		  scanf("%s",myfs);
		  unmount(myfs);
		  kill(getpid(),9);
		}
	      else
		kill(getpid(),9);
	    }
	  else if(strcmp(t1,"mount")==0)
	    {
	      printf("\n1:create new filesystem\n2:load existing filesystem\n");
	      scanf("%d",&choice);
	      if(choice==2)
		{
		  printf("\nEnter name of filesystem which u want to load:\n");
		  scanf("%s",myfs);
		  mount(myfs);
		  // printinit();
		}
	      else if(choice==1)
		{
		  initialize();
		  //printinit();
		  printf("\ncontinue on current shell.....");
		}
	      else
		printf("\nInvalid input,please enter appropriate entry.");
	    }
	  else
	    perror("\nCommand Not Found:");
	}

      //less,cat
      
      else if(n==2)
	{
	  if(strcmp(t1,"less")==0)
	    {
	      fd=openf(t2,"O_RDWR");
	      
	      if(fd==-1)
	  	perror("failed to open file:\n");
	      else
	  	{
	  	  temp=UFDT[fd].ft_address;
	  	  temp=ft[temp].iit_address;
	  	  inodeno=iit[temp].inode_number;
		  
	  	  size=inode[inodeno].actual_file_size;
		  
	  	  retval=readf(fd,buff3,size);
	  	  printf("\n%s\n",buff3);
	  	}
	      closef(fd);
	    }// inner if
	  else if(strcmp(t1,"cat")==0)
	    {
	      
	      fd=openf(t2,"O_RDWR");
	      
	      if(fd==-1)
	  	perror("failed to open file:\n");
	      else
	  	{
	  	  temp=UFDT[fd].ft_address;
	  	  temp=ft[temp].iit_address;
	  	  inodeno=iit[temp].inode_number;
		  
	  	  size=inode[inodeno].actual_file_size;
		  
	  	  retval=readf(fd,buff3,size);
	  	  printf("\n%s\n",buff3);
	  	}
	      closef(fd);
	    }
	  
	  else if(strcmp(t1,"mkdir")==0)
	    {
	      fd=mkdirf(t2,"0777");
	      if(fd==0)
		printf("\nCreated Successfully..\n");
	      else
		perror("\nUnable to Create..\n");
	    }

	  else if(strcmp(t1,"rmdir")==0)
	    {
	      fd=rmdirf(t2);
	      if(fd==0)
		printf("\nDeleted Successfully..\n");
	      else
		perror("\nUnable to delete..\n");
	    }
	  
	  else if(strcmp(t1,"rm")==0)
	    {
	      fd=rmf(t2);
	      if(fd==0)
		printf("\nDeleted Successfully..\n");
	      else
		perror("\nUnable to delete..\n");
	    }
	  
	  else if(strcmp(t1,"cd")==0)
	    {
	      //printf("\n %d",current_dir);
	      current_dir=chdirf(t2);
	      // printf("\n curr_dir=%d",current_dir);
	    }

	  else
	    perror("\nCommand Not Found:");
	  // printinit();
	}//outer if
      else if(n==3)
      	{
	  
      	  if(strcmp(t1,"cat")==0)
      	    {
      	      if(strcmp(t2,">")==0)
      		{
		  strcpy(t5,t3);
      		  fd=createf(t3,"S_IRWXU");
      		  if(fd==-1)
      		    perror("file can't be created");
		  
      		  fd=openf(t5,"O_RDWR");
      		  if(fd==-1)
      		    printf("failed to open file :\n");
      		  else
      		    gets(buff3);
		  
      		  retval=writef(fd,buff3,strlen(buff3));
      		  close(fd);
      		}
      	    }
      	}
      else
	perror("\ncommand not found..");
      //printinit();
    }//while
}//main 


  
  

