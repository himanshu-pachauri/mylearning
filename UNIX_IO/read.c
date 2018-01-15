

//gcc read.c -o read 
#include<stdio.h>
#include<unistd.h>

int main()
{
char buf[1024];
ssize_t byteread;
byteread=read(STDIN_FILENO,buf,100);

if(byteread<100)
{
printf("Error in opening");
return 0;
}
else 
printf(" you have entered %s",buf);
return 0;





}
