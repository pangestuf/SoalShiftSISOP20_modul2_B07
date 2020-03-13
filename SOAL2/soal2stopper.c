#include <stdio.h>
#include <unistd.h>

int main () {
  char *argv[4] = {"pkill", "Soal3", NULL};
  
  execv("/usr/bin/pkill", argv);
  return 0;

}
