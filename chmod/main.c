#include <stdio.h>
#include <sys/stat.h>

char test_file_path[] = "../test";

int main() {

    struct stat buf = {0};

    if(stat(test_file_path,&buf) == -1){
        perror("stat file failed!");
        return -1;
    }

    printf("%o\n",buf.st_mode);

    chmod(test_file_path,0777);

    if(stat(test_file_path,&buf) == -1){
        perror("stat file failed!");
        return -1;
    }

    printf("%o\n",buf.st_mode);

    printf("the upper bit may mean the file type or something else\n");
    return 0;
}
