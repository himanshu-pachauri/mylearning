#include<stdio.h>
#include<unistd.h>
#include<errno.h>
int main()
{
char *buf;
ssize_t bytesread;
bytesread=read(STDIN_FILENO,buf,100);

printf("%s",buf);
return 0;






}
