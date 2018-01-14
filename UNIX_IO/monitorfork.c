//gcc  restart.h copyfile.c monitorfork.c -o monitorfork

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
//#include"restart.h"
int main(int argc,char *argv[])
{
int bytesread;
int childpid;
int fd ,fd1,fd2;
if(argc!=3)
{
fprintf(stderr,"Usage:%s file1 file2",argv[0]);
return 1;
}
if((fd1=open(argv[1],O_RDONLY))==-1)
{
fprintf(stderr,"failed to open %s :%s",argv[1],strerror(errno));
return 1;
}
if((fd2=open(argv[2],O_RDONLY))==-1)
{
fprintf(stderr,"failed to open %s :%s",argv[2],strerror(errno));
return 1;
}

if((childpid=fork())==-1)
{
perror("failed to create a child process");
return 1;
}
if(childpid>0)
{
fd=fd1;
}
else
fd =fd2;
bytesread=copyfile(fd,STDOUT_FILENO);
fprintf(stdout,"Bytes read %d" ,bytesread);
return 0;
}
