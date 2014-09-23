#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
int c = 0;
int beers = 2000000;

void error (char *msg) {
  fprintf (stderr, "%s: %s\n", msg, strerror(errno));
  exit (1);
}

void* drink_lots (void *a) {
  int i;
  printf ("%i\n", c++);
  for (i = 0; i < 100000; i++) {
    beers = beers - 1;
  }
  return NULL;
}

int main() {
  pthread_t threads[20];
  int t;
  printf ("壁にはビールが%i本\n%i本のビール\n", beers, beers);
  for (t = 0; t < 20; t++) {
    pthread_create (&threads[t], NULL, drink_lots, NULL);
  }
  void *result;
  for (t = 0; t < 20; t++) {
    pthread_join (threads[t], &result);
  }
  printf ("壁にはビールが%i本!!!!!!\n", beers);
  return 0;
}
