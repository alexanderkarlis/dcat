#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "files.h"

int main(int argc, char *argv[]) {
  char *first_file;
  char *second_file;

  first_file = argv[1];
  second_file = argv[2];

  File_info_t *first_info = New_file_info(first_file, 0);
  puts(first_info->csv_info->headers);
  puts(first_info->csv_info->row_data);
  printf("%d\n", first_info->csv_info->delimiter);
  free(first_info);
  first_info = NULL;

  return 1;
}
