#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>
#include<malloc.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#define MAXFILES 3072
#define MAXOPENINODE 20
#define PATHLENGTH 10
struct inode_
{
  int uid;
  int gid;
  char file_type[10];
  char file_permissions[15];
  char access_time[30];
  char modified_time[30];
  char inode_mod_time[30];
  int disk_address[5];
  int number_of_blocks_allocated;
  char status[8];
  int links;
  int size;
  int actual_file_size;
}inode[MAXFILES];

struct superblock_
{
  int file_size;
  int maximum_files;
  int free_inodes[MAXFILES];
  int free_inode_cnt;
  int free_disk_blocks[MAXFILES];
  int free_disk_block_cnt;
  int allocated_inodes[MAXFILES];
  int inode_alloc_count;
}sb;

struct datablock_
{
  char data[1024];
}DB[MAXFILES];

struct UFDT_
{
  int ft_address;
}UFDT[MAXOPENINODE];

struct IIT_
{
  int inode_number;
  char file_open_mode[10];
  int reference_count;
}iit[MAXOPENINODE];

struct FileTable_
{
  int iit_address;
  char file_open_mode[10];
}ft[MAXOPENINODE];

struct directory_
{
  int index[MAXFILES];
  int inode_number[MAXFILES];
  char filename[MAXFILES][20];
  int filecount;
}dir[MAXFILES];

