#include<errno.h>
#include<unistd.h>
#define BLKSIZE 1023
int copyfile(int fromfd,int tofd)
{
char *bp;
char buf[BLKSIZE];
int bytesread,byteswritten;
int totalbytes=0;

for(;;)
{
while(((bytesread=read(fromfd,buf,BLKSIZE))==-1) &&(errno==EINTR));
if(bytesread<0)
{
break;
}
bp=buf;
while(bytesread>0)
{
while((byteswritten=write(tofd,buf,BLKSIZE)==-1) &&(errno==EINTR));
if(byteswritten<=0)
{
break;
}
totalbytes+=byteswritten;
bytesread=byteswritten;
bp+=byteswritten;
}
if(byteswritten=-1)
{
break;
}
return totalbytes;



}








}
