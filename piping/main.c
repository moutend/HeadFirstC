#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void error(char *msg) {
  fprintf(stderr, "%s:\n", msg);
  exit(1);
}

int main(int argc, char *argv[]) {
  char *phrase = argv[1];
  char *vars[] = {"RSS_FEED=http://www.cnn.com/rss/celebs.xml", NULL};
  int fd[2];
  if (pipe (fd) == -1) {
    error ("パイプを作成できません。");
  }
  pid_t pid = fork();
  if (pid == -1) {
    error ("パイプを作成できません。");
  }
  if (!pid) {
    dup2 (fd[1], 1);
    close (fd[0]);
    if (execl ("/usr/bin/python", "/usr/bin/python", "foo.py", NULL)) {
      error ("スクリプトを実行できません。");
    }
  }
  dup2 (fd[0], 0);
  close (fd[1]);
  char line[256];
  while (fgets (line, 255, stdin /* fd[0] == stdin*/)) {
    printf ("%s", line);
  }
  return 0;
}
