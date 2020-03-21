# SoalShiftSISOP20_modul2_B07
Modul 2 sisop
##Soal1.c
```
    if(argc != 5){
```
mengecek apakah jumlah inputan benar
```
    if(argv[1][0] == '*'){
        if(strlen(argv[1])>1){
```
mengecek apakah bintang dan tidak lebih dari 1 panjangnya
```
        if(argv[1][0] >= '0' && argv[1][0] <= '9'){
            Sdetik = argv[1][0] -'0';
            if(strlen(argv[1])==2){
                if(argv[1][1] >= '0' && argv[1][1] <= '9' && Sdetik < 6){
                    Sdetik = Sdetik*10 + argv[1][1] -'0';
```
mengecek apakah terdapat di dalam format waktu yang benar
  ```
    if ((argv[4][strlen(argv[4])-3] !='.' )||( argv[4][strlen(argv[4])-2] !='s' )||(argv[4][strlen(argv[4])-1]!='h')){
```
mengecek bagian dari input apakah bash atau bukan
```
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
        sleep(sleepsleep);
```
membuat program tidur selama waktu yang ditentukan


 ```	
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
                pm/AZakyH/Modul-Pelatihan-Linux-2018id = fork();
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
```
membuat program berjalan terus dan tidur salam waktu yang ditentukan

##Soal2
###Soal2.c

```
	FILE *filePointer ;
	filePointer = fopen("KILLER.sh","w");
	fprintf(filePointer,"%s","pkill Soal2");
	fclose(filePointer);
```
membuat file killer
```
        if(argc == 2&&argv[1][1]=='b'){
            argv[0][2]='K';
        }
```
mengubah path file untuk tidak dapat dibunuh oleh pkill
```
        snprintf(Timing,sizeof(Timing),"/home/yodhan/workspace/modul2/%d-%02d-%02d_%02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, 		tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
```
memasukan format time ke timing
```
    	strcpy(Ziper, Timing);
    	strcat(Ziper,".zip");
```
memasukan ziper untuk dizip nantinya

```
   	char *arc[] = {"mkdir", "-p", Timing, NULL};
	execv("/bin/mkdir", arc);
```
membuat file dengan format waktu
```
   	snprintf(Download,sizeof(Download),"https://picsum.photos/seed/picsum/%d", (int)time(NULL)%1000+100);
   	snprintf(Timingv2,sizeof(Timingv2),"%s/%d-%02d-%02d_%02d:%02d:%02d", Timing ,tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, 		tm.tm_hour, tm.tm_min, tm.tm_sec);
```
membuat download path yang akan didownload 
```
	char *arc[] = {"wget","-O",Timingv2,Download,NULL};
	execv("/usr/bin/wget",arc);
```
menguduh foto
```
    char *arc[] = {"zip","-rq",Ziper," ",Timing,NULL};
    execv("/usr/bin/zip",arc);
```
mengzip file
```

	char *arc[] = {"rm","-rf",Timing,NULL};
	execv("/bin/rm",arc);
```
mengdelete file
 
##Soal3.c
```
	int is_regular_file(const char *path)
	{
	struct stat path_stat;
	stat(path, &path_stat);
	return S_ISREG(path_stat.st_mode);
	}
```
mengecek apakah file atau directory
```
    char *argv[] = {"mkdir", "-p", "indomie", NULL};
    execv("/bin/mkdir", argv);
```
membuat directory indomie
```
    char *argv[] = {"mkdir", "-p", "sedaap", NULL};
    execv("/bin/mkdir", argv);
```
membuat directory sedaap
```
	char *argv[3] = {"unzip", "jpg.zip", NULL};
	execv("/usr/bin/unzip", argv);
```
mengunzip file jpg.zip
```
    DIR *d;
    struct dirent *dir;
    d = opendir("/home/yodhan/modul2/jpg");
```
membuka file dir jpg
```
     while ((dir = readdir(d)) != NULL)
```
membaca dir sampai habis
```
    char asal[100] ="/home/yodhan/modul2/jpg/";
    char target1[100] ="/home/yodhan/modul2/indomie/";
    char target2[100] ="/home/yodhan/modul2/sedaap/";
```
membuat target dan asal file
```
    strcat(asal,dir->d_name);
```
memasukan path file
```
    if(dir->d_name[0]!='.'){
```
selama bukan directory sebelumnya maka dijalankan
```
	char *argv[] = {"mv",asal,target2,NULL};
	execv("/bin/mv", argv);
```
bila file maka dipindahkan ke sedaap saja
```
	char *argv[] = {"mv",asal,target1,NULL};
	execv("/bin/mv", argv);
```
bila bukan file dipindahkan ke indomie
```
	    strcat(target1,dir->d_name);
```
mengcopy nama dari file
```
	strcat(target1,"/coba1.txt");
	char *argv[] = {"touch",target1,NULL};
	execv("/usr/bin/touch", argv);
	strcat(target1,"/coba2.txt");
	char *argv[] = {"touch",target1,NULL};
	execv("/usr/bin/touch", argv);
```
membuat text coba1 dan coba 2
