#include<errno.h>
#include<unistd.h>
#include"restart.h"
void docommand(char * ,int );
void dosomething(void);
void process_or_do_work(int fd1,int fd2)
{
char buf[1023];
ssize_t bytesread;
for(;;)
{
bytesread=r_read(fd1,buf,sizeof(buf));
if((bytesread==-1)&&(errno!=EAGAIN))
return ;
else if(bytesread>0)
{
docommand(buf,bytesread);
continue;
}
bytesread=r_read(fd2,buf,sizeof(buf));
if((bytesread==-1)&&(errno!=EAGAIN))
return ;
else if(bytesread>0)
docommand(buf,bytesread);
else 
dosomething();
}


}
