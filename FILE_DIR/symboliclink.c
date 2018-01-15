#include<stdio.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
int s;
if(argc!=3)
{
perror("USAGE:%s filename1 filename2");
return 0;
}
s=symlink(argv[1],argv[2]);

if(s==0)
{
fprintf(stdout,"Successfully created symbolic link\n");
}
else {
fprintf(stderr,"failed to create sysmbolic link\n");
}

}
