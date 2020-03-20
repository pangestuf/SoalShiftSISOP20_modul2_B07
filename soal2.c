#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
//#include <syslog.h>
#include <string.h>
#include <time.h>
#include <wait.h>
int main(int argc,char *argv[]) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char Timing[128];
    char Timingv2[256];
    char Download[128];
    char Ziper[128]="";
    pid_t pid, sid,child_id;        // Variabel untuk menyimpan PID

    pid = fork();     // Menyimpan PID dari Child Process
	FILE *filePointer ;
	filePointer = fopen("KILLER.sh","w");
	fprintf(filePointer,"%s","pkill Soal2");

fclose(filePointer);

    /* Keluar saat fork gagal
    * (nilai variabel pid < 0) */
    if (pid < 0) {
    exit(EXIT_FAILURE);
    }

    /* Keluar saat fork berhasil
    * (nilai variabel pid adalah PID dari child process) */
    if (pid > 0) {
    exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();
    if (sid < 0) {
    exit(EXIT_FAILURE);
    }

    if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    child_id = fork();
    if (child_id < 0 ) exit(EXIT_FAILURE);
    if (child_id == 0)
    {
        if(argc == 2&&argv[1][1]=='b'){
            argv[0][2]='K';
        }
        t = time(NULL);
        tm = *localtime(&t);
        snprintf(Timing,sizeof(Timing),"/home/yodhan/workspace/modul2/%d-%02d-%02d_%02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
            strcpy(Ziper, Timing);
            strcat(Ziper,".zip");
        child_id = fork();
        if (child_id < 0 ) exit(EXIT_FAILURE);
        if (child_id == 0)
        {
            char *arc[] = {"mkdir", "-p", Timing, NULL};
            execv("/bin/mkdir", arc);
        }
        wait(NULL);
        for(int i=0;i<20;i++)
        {
            t = time(NULL);
            tm = *localtime(&t);
            snprintf(Download,sizeof(Download),"https://picsum.photos/seed/picsum/%d", (int)time(NULL)%1000+100);
            snprintf(Timingv2,sizeof(Timingv2),"%s/%d-%02d-%02d_%02d:%02d:%02d", Timing ,tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
            child_id = fork();
            if (child_id < 0 ) exit(EXIT_FAILURE);
            if (child_id == 0)
            {
                char *arc[] = {"wget","-O",Timingv2,Download,NULL};
                execv("/usr/bin/wget",arc);
            }
sleep(5);
        }
        wait(NULL);
        sleep(10);
        child_id = fork();
        if (child_id < 0 ) exit(EXIT_FAILURE);
        if (child_id == 0)
        {
            char *arc[] = {"zip","-rq",Ziper," ",Timing,NULL};
            execv("/usr/bin/zip",arc);
        }
        wait(NULL);
        sleep(10);
        char *arc[] = {"rm","-rf",Timing,NULL};
        execv("/bin/rm",arc);
    }
    sleep(30);
    
}
