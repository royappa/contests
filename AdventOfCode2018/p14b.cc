#include <stdio.h>
#include <cstring>
#include <cstdlib>

main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: bad\n");
    exit(1);
  }
  char *num = argv[1];
  char *scores = (char *) malloc(300000000);
  scores[0] = '3';
  scores[1] = '7';
  int e0 = 0;
  int e1 = 1;
  int len = 2;
  int m = strlen(num);
  while (len < m+1 || (strncmp(num, scores+(len-m), m) && strncmp(num, scores+(len-m-1), m)) ) {
    int s = (scores[e0] - '0') + (scores[e1] - '0');
    int d1 = s / 10, d0 = s % 10;
    if (d1) {
      scores[len++] = '0' + d1;
    }
    scores[len++] = '0' + d0;
    e0 = (e0 + (scores[e0] - '0') + 1) % len;
    e1 = (e1 + (scores[e1] - '0') + 1) % len;
  }
  printf("%d\n", len - m - !strncmp(num, scores+(len-m-1), m));
}
