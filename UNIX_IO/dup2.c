#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{int file=open("myfile.txt",O_APPEND|O_WRONLY|O_CREAT);

if(file<0)
{
perror("failed to open file");
return 1;
}
if(dup2(file,1)<0)
{
return 1;
}
printf("This will print file in myfile.txt\n");
close(file);
return 0;


}
