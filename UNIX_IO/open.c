#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
int main()
{
int fd;
mode_t fdmode=(S_IRWXU| S_IRWXG| S_IRWXO);
fd=open("info.dat",O_RDWR|O_CREAT,fdmode);
if(fd==-1)
{
perror("Error in opening info.dat");

}

else 
fprintf(stdout,"Opened Successfully..\n");





}
