#include <fcntl.h>
#include <errno.h>
#include <error.h>
#include <stdio.h>
#include <unistd.h>

char buf1[10] = "abcdefghij";
char buf2[10] = "1234567890";

int main()
{
    int fd;

    if((fd = open("file_nohole",O_CREAT|O_RDWR)) == -1){
        perror("open file failed!\n");
        return -1;
    }

    if(write(fd,buf1,sizeof(buf1))==-1){
        perror("write file failed!\n");
        return -2;
    }

    if(write(fd,buf2,sizeof(buf2))==-1){
        perror("write file failed!\n");
        return -4;
    }
    return 0;


}