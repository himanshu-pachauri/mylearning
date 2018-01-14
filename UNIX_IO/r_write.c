#include<unistd.h>
#include<errno.h>
ssize_t r_write(int fd,void * buf,size_t size)
{
char *bufp;
size_t bytestowrite=size;
size_t byteswritten;
size_t totalbytes=0;
for(bufp=buf;bytestowrite>0;bufp+=byteswritten,bytestowrite-=byteswritten)
{
byteswritten=write(fd,buf,bytestowrite);
if((byteswritten==-1) && (errno!=EINTR))
{
return -1;
}

if(byteswritten==-1)
{
byteswritten=0;

}
totalbytes+=byteswritten;
}
return totalbytes;
}

