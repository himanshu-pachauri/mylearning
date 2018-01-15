#include<stdio.h>
#include<unistd.h>
int main(int argc ,char *argv[])
{int l;
if(argc!=3)
{
fprintf(stderr,"USAGE:%s source destination ",argv[0]);
return 1;
}
if((link(argv[1],argv[2]))==0)
{
perror("failed to create link");
return 1;
}
else 
printf("Link createad Successfully\n");
return 0;




}
