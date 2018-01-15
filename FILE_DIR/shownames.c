#define _POSIX_SOURCE
#include<unistd.h>
#include<dirent.h>
#include<errno.h>
#include<dirent.h>

#undef _POSIX_SOURCE
#include<stdio.h>
int main(int argc,char *argv[])
{
DIR *dir;
struct dirent *entry;
if(argc!=2)
{
fprintf(stderr,"USAGE:%s  directory_name\n",argv[0]);
return 1;
}
if((dir=opendir(argv[1]))==NULL)
{
perror("Failed to open directory");
return 1;
}
else {

fprintf(stdout,"Content of %s\n",argv[1]);
while((entry=readdir(dir))!=NULL)
{
printf("%s ",entry->d_name);
}
while((entry=readdir(dir))!=NULL)
{ 
printf("%s  ",entry->d_name);
}
while((closedir(dir)==-1)&&(errno==EINTR));
puts("");



}
return 0;
}
