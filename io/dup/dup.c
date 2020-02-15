#include <stdio.h>

#include <unistd.h>
#include <fcntl.h>
#include <error.h>

int main()
{
    int fd;
    if((fd = open("test",O_RDWR|O_CREAT)) == -1){
        perror("open file failed!\n");
        return -1;
    }

    dup2(fd,0);
    dup2(fd,1);
    dup2(fd,2);

    while(1);
    
    return 0;
}