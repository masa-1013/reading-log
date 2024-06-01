#include <stdio.h>
#include <stdlib.h>

static void do_cat(FILE *f);

int
main(int argc, char *argv[])
{
  if (argc == 1) {
    do_cat(stdin);
  } else {
    int i;

    for (i = 1; i < argc; i++) {
      FILE *f = fopen(argv[i], "r");
      if (!f) {
        perror(argv[i]);
        exit(1);
      }
      do_cat(f);
      fclose(f);
    }
  }
  exit(0);
}

static void
do_cat(FILE *f)
{
  char buffer[1024];
  size_t byteRead;

  while ((byteRead = fread(buffer, 1, sizeof buffer, f)) > 0) {
    if (fwrite(buffer, 1, byteRead, stdout) < byteRead) exit(1);
  }
}