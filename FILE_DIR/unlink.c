#include<stdio.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
int u;
if(argc!=2)
{

fprintf(stderr,"USAGE: %s filename  \n",argv[0]);
return 1;
}
u=unlink(argv[1]);

if(u!=0)
{
perror("Failed to unlink");
return 1;
}
else {
fprintf(stdout,"successfully unlink %s\n",argv[1]);
}

}
