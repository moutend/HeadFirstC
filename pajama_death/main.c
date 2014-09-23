#include <stdio.h>
int main (int argc, char *argv[]) {
  char *feeds[] = {"http://www.cnn.com/rss/celebs.xml",
                   "http://www.rollingstone.com/rock.xml",
                   "http://eonline.com/gossip.xml"};
  int times = 3;
  char *phrase = argv[1];
  int i;
  for (i = 0; i < times; i++) {
    char var[255];
    sprintf(var, "RSS_FEED=%s", feeds[i]);
    char *vars[] = {var, NULL};
    if ( execle ("/usr/bin/python", "/usr/bin/python", "./hoge.py", NULL) == -1) {
      fprintf (stderr, "スクリプトを実行できません:\n");
      return 1;
    }
  }
  return 0;
}
