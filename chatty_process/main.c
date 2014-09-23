#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void error(char *msg) {
  //fprintf(stderr, "%s:%s\n", msg, strerror(errno));
  fprintf(stderr, "%s:\n", msg);
  exit(1);
}

//int main (int argc, char *argv[]) {
int main () {
  // char *phrase = argv[1];
  // char *vars[] = {"RSS_FEED=http://www.cnn.com/rss/celebs.xml", NULL};
  FILE *f = fopen("stories.txt", "w");
  if (!f) {
    error("stories.txt を開けません "); }
  pid_t pid = fork();
  if (pid == -1) {
    error(" プロセスをフォークできません "); }
  if (!pid) {
    if (dup2(fileno(f), 1) == -1) {
      error(" 標準出力をリダイレクトできません ");
    }
    if (execl ("/usr/bin/python", "/usr/bin/python", "./hoge.py", NULL) == -1) {
      error(" スクリプトを実行できません ");
    }
  }
  int pid_status;
  printf("%d\n", pid);
  if (waitpid(pid, &pid_status, 0) == -1) {
    error(" プロセスをフォークできません "); }

  return 0;
}
