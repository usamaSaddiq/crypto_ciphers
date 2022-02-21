#include <stdio.h>
#define len 12

int main() {
  FILE *randfile, *outfile;
  int i;
  unsigned char next;

  randfile = fopen("/dev/random", "r");
  outfile = fopen("./key.txt", "w");

  if (randfile == NULL || outfile == NULL) {
    printf("File error \n");
    return 1;
  }

  for(i=0; i<len; i++) {
    fscanf(randfile, "%c", &next);
    fprintf(outfile, "%02X", next);
  }

  fclose(randfile);
  fclose(outfile);

  return 0;
}
