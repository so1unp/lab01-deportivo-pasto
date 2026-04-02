#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  srand(time(NULL));
  unsigned char letra;

  if (argc > 1) {
    for (int j = 0; argv[1][j] != '\0'; j++) {
      letra = (unsigned char)argv[1][j];
      for (int i = 0; i < 7; i++) {
        unsigned char basura = (unsigned char)rand();
        if (write(1, &basura, 1) == -1) {
          perror("Error");
          return 1;
        }
      }
      if (write(1, &letra, 1) == -1) {
        perror("Error");
        return 1;
      }
    }
  } else {
    while (read(0, &letra, 1) > 0) {
      for (int i = 0; i < 7; i++) {
        unsigned char basura = (unsigned char)rand();
        if (write(1, &basura, 1) == -1) {
          perror("Error");
          return 1;
        }
      }
      if (write(1, &letra, 1) == -1) {
        perror("Error");
        return 1;
      }
    }
  }
  return 0;
}
