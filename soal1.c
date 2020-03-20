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

int main(int argc,char* argv[]) {
    if(argc != 5){
        printf("input aja gak becus\n");
        return 0;
    }
    int Sjam,Smenit,Sdetik;
    if(argv[1][0] == '*'){
        if(strlen(argv[1])>1){
            printf("input aja gak becus\n");
            return 0;
        }
        Sdetik = 60;
    }else{
        if(argv[1][0] >= '0' && argv[1][0] <= '9'){
            Sdetik = argv[1][0] -'0';
            if(strlen(argv[1])==2){
                if(argv[1][1] >= '0' && argv[1][1] <= '9' && Sdetik < 6){
                    Sdetik = Sdetik*10 + argv[1][1] -'0';
                }else{
                    printf("input aja gak becus\n");
        return 0;
                }
            }else if (strlen(argv[1])>2 ){
                printf("input aja gak becus\n");
        return 0;
            }
        }else{
            printf("input aja gak becus\n");
        return 0;
        }
    }
    //----------------------------------------------------
    if(argv[2][0] == '*'){
        if(strlen(argv[2])>1){
            printf("input aja gak becus\n");
        return 0;
        }
        Smenit = 60;
    }else{
        if(argv[2][0] >= '0' && argv[2][0] <= '9'){
            Smenit = argv[2][0] -'0';
            if(strlen(argv[2])==2){
                if(argv[2][1] >= '0' && argv[2][1] <= '9' && Smenit < 6){
                    Smenit = Smenit*10 + argv[2][1] -'0';
                }else{
                    printf("input aja gak becus\n");
        return 0;
                }
            }else if (strlen(argv[2])>2 ){
                printf("input aja gak becus\n");
        return 0;
            }
        }else{
            printf("input aja gak becus\n");
        return 0;
        }
    }
    //------------------------------------------------------------------
    if(argv[3][0] == '*'){
        if(strlen(argv[3])>1){
            printf("input aja gak becus\n");
        return 0;
        }
        Sjam = 60;
    }else{
        if(argv[3][0] >= '0' && argv[3][0] <= '9'){
            Sjam = argv[3][0] -'0';
            if(strlen(argv[3])==2){
                if(argv[3][1] >= '0' && argv[3][1] <= '3' && Sjam < 3){
                    Sjam = Sjam*10 + argv[3][1] -'0';
                }else{
                    printf("input aja gak becus\n");
        return 0;
                }
            }else if (strlen(argv[3])>2 ){
                printf("input aja gak becus\n");
        return 0;
            }
        }else{
            printf("input aja gak becus\n");
        return 0;
        }
    }
    //----------------------------------------------------------
    if ((argv[4][strlen(argv[4])-3] !='.' )||( argv[4][strlen(argv[4])-2] !='s' )||(argv[4][strlen(argv[4])-1]!='h')){
        printf("input aja gak becus\n");
        return 0;
    }
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int jam = tm.tm_hour, menit = tm.tm_min,detik = tm.tm_sec; 
    int sleepsleep=0;
    if(Sjam==60){
        sleepsleep=0;
    }else if (tm.tm_hour>=Sjam){
        
        sleepsleep=(tm.tm_hour-Sjam)*3600;
    }else{
        sleepsleep=(23+tm.tm_hour-Sjam)*3600;
    }
    if(Smenit==60){
        sleepsleep+=0;
    }else if (tm.tm_min>=Smenit){
        sleepsleep+=(tm.tm_min-Smenit)*60;
    }else{
        sleepsleep+=(59+tm.tm_min-Smenit)*60;
    }
    if(Sdetik==60){
        sleepsleep+=0;
    }else if(tm.tm_sec>=Sdetik){
        sleepsleep+=(tm.tm_sec-Sdetik);
    }else{
        sleepsleep+=(59+tm.tm_sec-Sdetik);
    }
    pid_t pid, sid;        // Variabel untuk menyimpan PID
    pid = fork();     // Menyimpan PID dari Child Process
    /* Keluar saat fork gagal
    * (nilai variabel pid < 0) */

    if (pid < 0) exit(EXIT_FAILURE);
    /* Keluar saat fork berhasil
    * (nilai variabel pid adalah PID dari child process) */
    if (pid > 0) exit(EXIT_SUCCESS);
    umask(0);

    sid = setsid();
    if (sid < 0) exit(EXIT_FAILURE);

    if ((chdir("/")) < 0) {
        exit(EXIT_FAILURE);
    }
char aku[100]="";
strcat(aku,argv[4]);
    char *Bashing[] ={"bash",aku,NULL};
                        execv("/bin/bash",Bashing);
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    sleep(sleepsleep);
 	
    while (1) {
        if(Sjam == 60){
            if(Smenit == 60){
            for(int j=0;j<60;j++){
                sleep(60);
                if(Sdetik == 60){
                for(int i=0;i<60;i++){
                    sleep(1);
                    pid = fork();
                    if (pid == 0){
                        char *Bashing[] ={"bash",aku,NULL};
                        execv("/bin/bash",Bashing);
                    }    
                }  
                }else{
                    sleep(Sdetik);
                    pid = fork();
                    if (pid == 0){
                        char *Bashing[] ={"bash",aku,NULL};
                        execv("/bin/bash",Bashing);
                    }    
                    sleep(60-Sdetik);
                }   
            } 
        }else{
            sleep(Smenit*60);
            if(Sdetik == 60){
            for(int i=0;i<60;i++){
                sleep(1);
                pid = fork();
                if (pid == 0){
                    char *Bashing[] ={"bash",aku,NULL};
                    execv("/bin/bash",Bashing);
                }    
            }  
            }else{
                sleep(Sdetik);
                pid = fork();
                if (pid == 0){
                    char *Bashing[] ={"bash",aku,NULL};
                    execv("/bin/bash",Bashing);
                }    
                sleep(60-Sdetik);
            }
            sleep((59-Smenit)*60);
        }
        }else{
            sleep(3600*23);
            if(Smenit == 60){
            for(int j=0;j<60;j++){
                sleep(60);
                if(Sdetik == 60){
                for(int i=0;i<60;i++){
                    sleep(1);
                    pid = fork();
                    if (pid == 0){
                        char *Bashing[] ={"bash",aku,NULL};
                        execv("/bin/bash",Bashing);
                    }    
                }  
                }else{
                    sleep(Sdetik);
                    pid = fork();
                    if (pid == 0){
                        char *Bashing[] ={"bash",aku,NULL};
                        execv("/bin/bash",Bashing);
                    }    
                    sleep(60-Sdetik);
                }   
            } 
        }else{
            sleep(Smenit*60);
            if(Sdetik == 60){
            for(int i=0;i<60;i++){
                sleep(1);
                pid = fork();
                if (pid == 0){
                    char *Bashing[] ={"bash",aku,NULL};
                    execv("/bin/bash",Bashing);
                }    
            }  
            }else{
                sleep(Sdetik);
                pid = fork();
                if (pid == 0){
                    char *Bashing[] ={"bash",aku,NULL};
                    execv("/bin/bash",Bashing);
                }    
                sleep(60-Sdetik);
            }
            sleep((59-Smenit)*60);
        }
        }
        
        
    }
}
