#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
int main() {
    chdir("..");
    if(creat("upper_level_file",S_IRWXG|S_IRWXU|S_IRWXO) ==-1){
        perror("cannot creat file!\n");
        return -1;
    }

    //I give 777 to this file,but it actually only have 755
    //which means that default umask is 022
    //so I set umask 000
    umask(0);
    if(creat("upper_level_file_777",S_IRWXG|S_IRWXU|S_IRWXO) ==-1){
        perror("cannot creat file!\n");
        return -1;
    }

    printf("created files in upper level\n");
    return 0;
}
