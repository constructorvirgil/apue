#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char needroot[] = "../needroot";
char needuser[] = "../needuser";


int main() {

    if(open(needroot,O_RDONLY) == -1){
        perror("open file failed!\n");
        return -1;
    }else{
        printf("can open file!\n");
    }

    if(access(needroot,R_OK)!=0){
        perror("cannot access or some errors occur!\n");
        return -2;
    }else{
        printf("file can be access by ruid\n");
    }

    return 0;
}
