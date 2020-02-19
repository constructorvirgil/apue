#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

//filename's attentions:
//1. please do not begin with space
//2. it can be a abs_path or rel_path
const char file_path_name[] = "../main.c";
const char file_path_name_abs[] = "/home/virgil/apue/stat/main.c";
const char link_path_name[] = "../test_link_to_main.c";


void pr_file_info(char* file_name,struct stat* buf)
{
    char* ptr;

    if(S_ISREG(buf->st_mode))
        ptr = "a regular file";
    else if(S_ISDIR(buf->st_mode))
        ptr = "directory";
    else if(S_ISLNK(buf->st_mode))
        ptr = "symbolic link";
    else
        ptr = "unknow file type";

    printf("%s is %s\n",file_name,ptr);
    printf("uid:%d\n",buf->st_uid);
    printf("gid:%d\n",buf->st_gid);
    printf("last accessed file:%d\n",buf->st_atim.tv_sec);
    printf("last modified content:%d\n",buf->st_mtim.tv_sec);
    printf("last changed status:%d\n",buf->st_ctim.tv_sec);
    printf("\n");
}

int main(int argc,char* argv[]) {
    struct stat buf = {0};

    //stat test
    if(stat(file_path_name,&buf) == -1){
        perror("stat file failed!\n");
        return -1;
    }

    pr_file_info(file_path_name,&buf);

    //stat link test
    if(stat(link_path_name,&buf) == -1){
        perror("stat file failed!\n");
        return -1;
    }

    pr_file_info(link_path_name,&buf);

    //fstat
    int fd;
    if((fd = open(file_path_name,O_RDONLY)) == -1){
        perror("open file failed!\n");
        return -2;
    }

    if(fstat(fd,&buf) == -1){
        perror("fstat file failed!\n");
        return -3;
    }

    pr_file_info(file_path_name,&buf);

    //lstat
    if(lstat(link_path_name,&buf) == -1){
        perror("stat file failed!\n");
        return -1;
    }

    //will not follow link
    pr_file_info(link_path_name,&buf);

    //fstatat test
    //fd should open with a directory
    if((fd = open("../",O_RDONLY)) == -1){
        perror("open file failed!\n");
        return -2;
    }
/*
 *  The fstatat() system call operates in exactly the same way as stat(), except
       for the differences described here.

       If the pathname given in pathname is relative, then it is interpreted  rela‐
       tive  to the directory referred to by the file descriptor dirfd (rather than
       relative to the current working directory of the calling process, as is done
       by stat() for a relative pathname).

       If  pathname is relative and dirfd is the special value AT_FDCWD, then path‐
       name is interpreted relative to the current working directory of the calling
       process (like stat()).

       If pathname is absolute, then dirfd is ignored.

 * */
    char tn[] = "test_link_to_main.c";
    if(fstatat(fd,tn,&buf,AT_SYMLINK_NOFOLLOW) == -1){
        perror("fstatat file failed!\n");
        return -3;
    }

    pr_file_info(tn,&buf);

    return 0;
}
