#include <stdio.h>
#include <stdlib.h>

static int count_row(FILE *f);

int
main(int argc, char *argv[])
{
  int i;

  for (i = 1; i < argc; i++) {
    FILE *f = fopen(argv[i], "r");
    if (!f) {
      perror(argv[i]);
      exit(1);
    }
    printf("%d", count_row(f));
  }
}

static int
count_row(FILE *f)
{
  int c;
  int count = 0;
  int row = 1;

  while ((c = fgetc(f)) != EOF) {
    if (c == '\n') {
      row++;
    } else {
      count++;
    }
  }

  if (count == 0) {
    row = 0;
  }

  return row;
}