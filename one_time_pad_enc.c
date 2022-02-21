#include <stdio.h>
#define len 12

int main() {
  FILE *key_file, *plain_text_file , *enc_file;
  int i;
  unsigned char char1;
  char char2;

  key_file = fopen("./key.txt", "r");
  plain_text_file = fopen("./plain_text.txt", "r");
  enc_file = fopen("./enc_file.txt", "w");

  if (key_file == NULL || plain_text_file == NULL || enc_file == NULL) {
    printf("File error \n");
    return 1;
  }

  for(i=0; i<len; i++) {
    fscanf(key_file, "%02hhX", &char1);
    fscanf(plain_text_file, "%c", &char2);
    fprintf(enc_file, "%02X", char1^char2);
  }

  fclose(key_file);
  fclose(plain_text_file);
  fclose(enc_file);

  return 0;
}
