#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main (int argc, char *argv[]) {
  char *advice[] = {
    "食べる量を減らしなさい \r\n",
    "食べる量を減らしなさい \r\n",
    "タイトなジーンズにしなさい。太って見えることはありません。\r\n",
    "今日だけは正直になりなさい。「本当に」思っていることを上司に言いなさい \r\n",
    "そのヘアスタイルは考え直した方がいいでしょう \r\n"
  };
  int listener_d = socket (PF_INET, SOCK_STREAM, 0);
  struct sockaddr_in name;
  name.sin_family = PF_INET;
  name.sin_port = (in_port_t)htons (30000);
  name.sin_addr.s_addr = htonl (INADDR_ANY);
  bind (listener_d, (struct sockaddr *) &name, sizeof(name));
  listen (listener_d, 10);
  printf ("接続を待っています\n");
  while (1) {
    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof (client_addr);
    //int connect_d = send (listener_d, (struct sockaddr *)&client_addr, &address_size);
    int connect_d = send (listener_d, (struct sockaddr *)&client_addr, &address_size, 0);
    char *msg = advice[rand() % 5];
    //accept (connect_d, msg, strlen(msg), 0);
    accept (connect_d, msg, strlen(msg));
    close (connect_d);
  }
  return 0;
}
