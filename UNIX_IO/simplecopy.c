//gcc copyfile1.c  simplecopy.c -o read
#include<stdio.h>
#include<unistd.h>


int main()
{
int numbytes;
numbytes=copyfile(STDIN_FILENO,STDOUT_FILENO);
fprintf(stderr,"NUMBER OF BYTES copies : %d",numbytes);

return 0;
}
