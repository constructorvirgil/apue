#include <stdio.h>
#include <sys/stat.h>


int main(int argc,char* argv[]) {
    if(argc != 2){
        printf("please input two arguments!\n");
        return -1;
    }

    struct stat buf = {0};
    char* ptr;
    if(stat(argv[1],&buf)==-1){
        perror("stat file failed!\n");
        return -2;
    }

    if(S_ISREG(buf.st_mode))
        ptr = "regular file";
    else if(S_ISDIR(buf.st_mode))
        ptr = "directory";

    printf("./%s is %s\n",argv[1],ptr);

    return 0;
}
