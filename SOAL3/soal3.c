#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>
#include <dirent.h>
#include<string.h>
#include <stdio.h>
int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}
int main()
{
    pid_t child_id;
    char *p = getenv("USER");

    if (p == NULL) exit (EXIT_FAILURE);
    child_id = fork();

    if (child_id == 0)
    {
        child_id = fork();
        if (child_id < 0 ) exit(EXIT_FAILURE);
        if (child_id == 0)
        {
            char *argv[] = {"mkdir", "-p", "indomie", NULL};
            execv("/bin/mkdir", argv);
        } else {
            sleep(5);
            char *argv[] = {"mkdir", "-p", "sedaap", NULL};
            execv("/bin/mkdir", argv);
        }
    }
    wait(NULL);
    child_id = fork();
    if (child_id < 0 ) exit(EXIT_FAILURE);
    if (child_id == 0)
    {
        char *argv[3] = {"unzip", "jpg.zip", NULL};
        execv("/usr/bin/unzip", argv);
    }
    wait(NULL);
    DIR *d;
    struct dirent *dir;
    d = opendir("/home/yodhan/modul2/jpg");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            char asal[100] ="/home/yodhan/modul2/jpg/";
            char target1[100] ="/home/yodhan/modul2/indomie/";
            char target2[100] ="/home/yodhan/modul2/sedaap/";
            printf("%s\n", dir->d_name);
            strcat(asal,dir->d_name);
            if(dir->d_name[0]!='.'){
                if(is_regular_file(asal)==1){
                    child_id = fork();
                    if (child_id < 0 ) exit(EXIT_FAILURE);
                    if (child_id == 0)
                    {
                        char *argv[] = {"mv",asal,target2,NULL};
                        execv("/bin/mv", argv);
                    }

                    wait(NULL);
                }else{
                    child_id = fork();
                    if (child_id < 0 ) exit(EXIT_FAILURE);
                    if (child_id == 0)
                    {
                        char *argv[] = {"mv",asal,target1,NULL};
                        execv("/bin/mv", argv);
                    }
                    strcat(target1,dir->d_name);
                    wait(NULL);
                    child_id = fork();
                    if (child_id < 0 ) exit(EXIT_FAILURE);
                    if (child_id == 0)
                    {
                        strcat(target1,"/coba1.txt");
                        char *argv[] = {"touch",target1,NULL};
                        execv("/usr/bin/touch", argv);
                    }
                    wait(NULL);
                    child_id = fork();
                    if (child_id < 0 ) exit(EXIT_FAILURE);
                    if (child_id == 0)
                    {
                        sleep(3);
                        strcat(target1,"/coba2.txt");
                        char *argv[] = {"touch",target1,NULL};
                        execv("/usr/bin/touch", argv);
                    }
                }
            }
        }
        closedir(d);
    }
}
