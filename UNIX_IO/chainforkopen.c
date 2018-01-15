#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#define BUFSIZE 1023
#define CREATE_FLAGS (O_WRONLY|O_CREAT|O_TRUNC)
#define CREATE_PERMS (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)
int main(int argc ,char *argv[])
{
char buf[BUFSIZE];
pid_t childpid=0;
int fd;
int i,n;
if(argc!=3)
{
fprintf(stderr,"USAGE: %s processes filename\n",argv[0]);
}
n=atoi(argv[1]);
for(i=1;i<n;i++)
if(childpid=fork())
break;
if(childpid==-1){
perror("Failed to fork");
return 1;
}

fd=open(argv[2],CREATE_FLAGS,CREATE_PERMS);
if(fd<0)
{
perror("failed to open file");
}

sprintf(buf,"i:%d process:%ld\n ",i,getpid());

write(fd,buf,strlen(buf));
sleep(1);
sprintf(buf,"parent:%ld process:%ld\n",(long)getppid(),(long)childpid);
write(fd,buf,strlen(buf));
close(fd);
return 0;

}
