//gcc restart.h simplecopy1.c -o simplecopy1
//gcc restart.h copyfile.c simplecopy1.c -o simplecopy1
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
int main()
{
int bytes;
bytes=copyfile(STDIN_FILENO,STDOUT_FILENO);
fprintf(stderr,"%d bytes written ",bytes);
return 0;




}
