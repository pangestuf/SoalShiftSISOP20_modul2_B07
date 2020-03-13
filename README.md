# SoalShiftSISOP20_modul2_B07
Modul 2 sisop
##Soal1.c
```
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

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    
    sleep(sleepsleep);
 
    pid = fork();
    if (pid == 0){
        char *ash[] ={"bash",argv[4],NULL};
        execv("/bin/bash",ash);
    }    

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
                        char *Bashing[] ={"bash",argv[4],NULL};
                        execv("/bin/bash",Bashing);
                    }    
                }  
                }else{
                    sleep(Sdetik);
                    pid = fork();
                    if (pid == 0){
                        char *Bashing[] ={"bash",argv[4],NULL};
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
                    char *Bashing[] ={"bash",argv[4],NULL};
                    execv("/bin/bash",Bashing);
                }    
            }  
            }else{
                sleep(Sdetik);
                pid = fork();
                if (pid == 0){
                    char *Bashing[] ={"bash",argv[4],NULL};
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
                        char *Bashing[] ={"bash",argv[4],NULL};
                        execv("/bin/bash",Bashing);
                    }    
                }  
                }else{
                    sleep(Sdetik);
                    pid = fork();
                    if (pid == 0){
                        char *Bashing[] ={"bash",argv[4],NULL};
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
                    char *Bashing[] ={"bash",argv[4],NULL};
                    execv("/bin/bash",Bashing);
                }    
            }  
            }else{
                sleep(Sdetik);
                pid = fork();
                if (pid == 0){
                    char *Bashing[] ={"bash",argv[4],NULL};
                    execv("/bin/bash",Bashing);
                }    
                sleep(60-Sdetik);
            }
            sleep((59-Smenit)*60);
        }
        }
        
        
    }
}
program mengecek apakah inputan yang diberikan sudah sesuai dengan ketentuan yang diberikan.
dari pengecekan waktu detik, menit, dan jam
jika diberikan * maka program mengangapnya berupa bilangan yang akan mengulang berulang ulang 
kemudian program akan bekerja menjadi deamon dan menunggu sejumlah waktu sampai waktu yang ditentukan
setelah itu kodingan baru berjalan dan menjalankan kodingan bash yang akan dijalankan
kodingan akan tidur sesuai dengan waktu yang ditentukan sehingga berjalan sesuai dengan yang akan dijalankan
```
##Soal2
###Soal2.c
```
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
    char Ziper[128];
    pid_t pid, sid,child_id;        // Variabel untuk menyimpan PID

    pid = fork();     // Menyimpan PID dari Child Process

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
        if(arc == 2&&argv[1][1]=='b'){
            argv[0][2]='K';
        }
        t = time(NULL);
        tm = *localtime(&t);
        snprintf(Timing,sizeof(Timing),"/home/yodhan/workspace/modul2/%d-%02d-%02d_%02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
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
            strcat(Ziper, Timing);
            strcat(Ziper,".zip");
            char *arc[] = {"zip",Ziper,Timing,NULL};
            execv("/usr/bin/zip",arc);
        }
        wait(NULL);
        sleep(25);
        char *arc[] = {"rm","-rf",Timing,NULL};
        execv("/bin/rm",arc);
    }
    sleep(30);
    
}
```
kodingan menerima inputan argumen -a atau -b yang akan membuat apakah anaknya akan mati jika dibuat pkill nantinya
kodingan akan menjalankannya sesuai dengan apa yang diberikan
mendonload file sebanyak 20x di folder yang dibuat dan mengzip dan mengdelete file tersebut
jika file -a maka child akan memiliki nama yang sama dengan paretntnya sedangkan jika -b child akan diganti namanya menjadi yang lain supaya tidak mati ketika di pkill
###Soal2stopper.c
```
#include <stdio.h>
#include <unistd.h>

int main () {
  char *argv[4] = {"pkill", "Soal3", NULL};
  
  execv("/usr/bin/pkill", argv);
  return 0;

}
kodingan akan membunuh file yang mempunyai nama Soal3 dengan begitu parent dan child yang tidak diganti namanya akan terbunuh
```
##Soal3.c
```
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
}##Soal1.c
```
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

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    
    sleep(sleepsleep);
 
    pid = fork();
    if (pid == 0){
        char *ash[] ={"bash",argv[4],NULL};
        execv("/bin/bash",ash);
    }    

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
                        char *Bashing[] ={"bash",argv[4],NULL};
                        execv("/bin/bash",Bashing);
                    }    
                }  
                }else{
                    sleep(Sdetik);
                    pid = fork();
                    if (pid == 0){
                        char *Bashing[] ={"bash",argv[4],NULL};
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
                    char *Bashing[] ={"bash",argv[4],NULL};
                    execv("/bin/bash",Bashing);
                }    
            }  
            }else{
                sleep(Sdetik);
                pid = fork();
                if (pid == 0){
                    char *Bashing[] ={"bash",argv[4],NULL};
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
                        char *Bashing[] ={"bash",argv[4],NULL};
                        execv("/bin/bash",Bashing);
                    }    
                }  
                }else{
                    sleep(Sdetik);
                    pid = fork();
                    if (pid == 0){
                        char *Bashing[] ={"bash",argv[4],NULL};
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
                    char *Bashing[] ={"bash",argv[4],NULL};
                    execv("/bin/bash",Bashing);
                }    
            }  
            }else{
                sleep(Sdetik);
                pid = fork();
                if (pid == 0){
                    char *Bashing[] ={"bash",argv[4],NULL};
                    execv("/bin/bash",Bashing);
                }    
                sleep(60-Sdetik);
            }
            sleep((59-Smenit)*60);
        }
        }
        
        
    }
}
program mengecek apakah inputan yang diberikan sudah sesuai dengan ketentuan yang diberikan.
dari pengecekan waktu detik, menit, dan jam
jika diberikan * maka program mengangapnya berupa bilangan yang akan mengulang berulang ulang 
kemudian program akan bekerja menjadi deamon dan menunggu sejumlah waktu sampai waktu yang ditentukan
setelah itu kodingan baru berjalan dan menjalankan kodingan bash yang akan dijalankan
kodingan akan tidur sesuai dengan waktu yang ditentukan sehingga berjalan sesuai dengan yang akan dijalankan
```
##Soal2
###Soal2.c
```
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
    char Ziper[128];
    pid_t pid, sid,child_id;        // Variabel untuk menyimpan PID

    pid = fork();     // Menyimpan PID dari Child Process

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
        if(arc == 2&&argv[1][1]=='b'){
            argv[0][2]='K';
        }
        t = time(NULL);
        tm = *localtime(&t);
        snprintf(Timing,sizeof(Timing),"/home/yodhan/workspace/modul2/%d-%02d-%02d_%02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
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
            strcat(Ziper, Timing);
            strcat(Ziper,".zip");
            char *arc[] = {"zip",Ziper,Timing,NULL};
            execv("/usr/bin/zip",arc);
        }
        wait(NULL);
        sleep(25);
        char *arc[] = {"rm","-rf",Timing,NULL};
        execv("/bin/rm",arc);
    }
    sleep(30);
    
}
```
kodingan menerima inputan argumen -a atau -b yang akan membuat apakah anaknya akan mati jika dibuat pkill nantinya
kodingan akan menjalankannya sesuai dengan apa yang diberikan
mendonload file sebanyak 20x di folder yang dibuat dan mengzip dan mengdelete file tersebut
jika file -a maka child akan memiliki nama yang sama dengan paretntnya sedangkan jika -b child akan diganti namanya menjadi yang lain supaya tidak mati ketika di pkill
###Soal2stopper.c
```
#include <stdio.h>
#include <unistd.h>

int main () {
  char *argv[4] = {"pkill", "Soal3", NULL};
  
  execv("/usr/bin/pkill", argv);
  return 0;

}
kodingan akan membunuh file yang mempunyai nama Soal3 dengan begitu parent dan child yang tidak diganti namanya akan terbunuh
```
##Soal3.c
```
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
```

```
kodingan mengunzip file dan mengecek apakah directory atau file kemudian di sortir setelah itu tiap directory diberikan file coba1.txt dan coba2.txt
