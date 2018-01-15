#define _POSIX_SOURCE
#include<unistd.h>
#include<dirent.h>
#include<errno.h>
#include<dirent.h>

#undef _POSIX_SOURCE
#include<stdio.h>
int main()
{
DIR *dir;
struct dirent *entry;
if((dir=opendir("/"))==NULL)
{
perror("Failed to open directory");
return 1;
}
else {

puts("Content of root:");
while((entry=readdir(dir))!=NULL)
{
printf("%s ",entry->d_name);
}
rewinddir(dir);
puts("");
while((entry=readdir(dir))!=NULL)
{ 
printf("%s  ",entry->d_name);
}
closedir(dir);
puts("");



}

}
