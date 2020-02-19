#include <stdio.h>
#include <stdlib.h>


int main() {
    char* path = getenv("PATH");
    char* shell = getenv("SHELL");
    char* user = getenv("USER");

    if(putenv("MYENV") == -1){
        perror("putenv failed!");
        return -1;
    }

    char* myenv = getenv("MYENV");

    printf("path: %s\n",path);
    printf("shell: %s\n",shell);
    printf("user: %s\n",user);
    printf("myenv: %s\n",myenv);

    if(setenv("MYENV","virgilsenv",1) == -1){
        perror("setenv failed!\n");
        return -2;
    }

    myenv = getenv("MYENV");
    printf("myenv: %s\n",myenv);

    return 0;
}
