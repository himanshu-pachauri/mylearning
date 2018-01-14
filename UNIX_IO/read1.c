//gcc  file.c -o file
#include<stdio.h>
#include<unistd.h>
int main()
{
ssize_t byte;
char buf[100];
byte=read(STDIN_FILENO,buf,10);
if(byte<0)
{

printf("error in reading from console.\n");
}
else if(byte>0)
{
buf[byte+1]=0;

printf(" %d  bytes successfully read\n",byte);
write(STDOUT_FILENO,buf,byte);
write(STDOUT_FILENO,"\n",byte);


}

return 0;




}
