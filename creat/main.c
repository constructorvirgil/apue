#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main() {
    umask(0);
    if(creat("foo",RWRWRW) == -1){
        perror("cannot creat file!\n");
        return -1;
    }

    umask(RWRWRW);

    if(creat("bar",RWRWRW) == -1){
        perror("cannot creat file!\n");
        return -2;
    }

    printf("create file 'foo' 'bar'\n");
    return 0;
}
