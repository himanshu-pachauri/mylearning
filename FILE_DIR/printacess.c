#include<stdio.h>
#include<time.h>
#include<sys/stat.h>
void printacess(char *path)
{
struct stat statbuf;
if((stat(path,&statbuf))==-1)
{
perror("failed to get file status");
return ;

}
else 
printf("%s last accessed at %s\n",path,ctime(&statbuf.st_atime));


}
