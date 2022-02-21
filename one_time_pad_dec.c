#include <stdio.h>
#define len 12

int main() {
  FILE *key_file, *another_plain_text_file , *enc_file;
  int i;
  unsigned char char1;
  char char2;

  key_file = fopen("./key.txt", "r");
  enc_file = fopen("./enc_file.txt", "r");
  another_plain_text_file = fopen("./another_plain_text.txt", "w");

  if (key_file == NULL || another_plain_text_file == NULL || enc_file == NULL) {
    printf("File error \n");
    return 1;
  }

  for(i=0; i<len; i++) {
    fscanf(key_file, "%02hhX", &char1);
    fscanf(enc_file, "%02hhX", &char2);
    fprintf(another_plain_text_file, "%c", char1^char2);
  }

  fclose(key_file);
  fclose(another_plain_text_file);
  fclose(enc_file);

  return 0;
}
