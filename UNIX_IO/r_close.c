#include<unistd.h>
#include<errno.h>
int r_close(int fd)
{
int retval;
while((retval=close(fd),retval==-1 && errno==EINTR));
return retval;
}

