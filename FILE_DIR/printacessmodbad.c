#include<stdio.h>
#include<time.h>
#include<sys/stat.h>
void printacessmodebad(char *path)
{
struct stat statbuf;
if((stat(path,&statbuf))==-1)
perror("Failed to get status");

else 
printf("%s acessed :%s modified %s",path,ctime(&statbuf.st_atime),ctime(&statbuf.st_mtime));
return ;

}
