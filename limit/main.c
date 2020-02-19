#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit rlim;
    if(getrlimit(RLIMIT_NPROC,&rlim) == -1){
        perror("cannot get limit!");
        return -1;
    }

    printf("nproc: cur: %d max: %d\n",rlim.rlim_cur,rlim.rlim_max);

    if(getrlimit(RLIMIT_NOFILE,&rlim) == -1){
        perror("cannot get limit!");
        return -2;
    }
    printf("nfile: cur: %d max: %d\n",rlim.rlim_cur,rlim.rlim_max);

    return 0;
}
