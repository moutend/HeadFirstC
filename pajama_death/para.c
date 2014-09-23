#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main () {
  int i;
  char* str[] = {"./hoge", "./foo", "./bar", "./piyo"};
  for(i = 0; i < 4; i++) {
    printf ("calling %s\n", str[i]);
    pid_t pid;
    pid = fork ();
    if (pid == -1)
      fprintf(stderr, "fork() FAIL\n");
    if (!pid)
      if ( execl (str[i], str[i], NULL) == -1)
        fprintf(stderr, "FAIL\n");
  }
  printf ("done\n");
  return 0;
}
