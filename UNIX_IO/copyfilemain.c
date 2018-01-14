//gcc  restart.h copyfile.c copyfilemain.c -o copyfilemain
//copyfilemain file.in file.out
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
//#include"restart.h"

#define READ_FLAG O_RDONLY
#define WRITE_FLAG (O_WRONLY | O_CREAT | O_EXCL)
#define WRITE_PERMS (S_IRUSR| S_IWUSR)
int main(int argc,char *argv[])
{int bytes;
int fromfd,tofd;
if(argc!=3)
{
fprintf(stderr,"Usage:%s from_file to_file\n",argv[0]);
}
if((fromfd=open(argv[1],READ_FLAG))==-1)
{
perror("Failed to open input file\n");
return 1;
}
if((tofd=open(argv[2],WRITE_FLAG,WRITE_PERMS))==-1)
{
perror("Failed to open output file\n");
return 1;
}
bytes=copyfile(fromfd,tofd);
close(fromfd);
close(tofd);


printf("%d bytes copied from %s to %s \n" ,bytes,argv[1],argv[2]);
return 0;






}
