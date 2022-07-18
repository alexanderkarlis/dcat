#include <stdio.h>
#include <stdlib.h>

#include "errors.h"
#include "files.h"

size_t open_file(File_info_t *ft, const char *fname) {
  FILE *file = fopen(fname, "r");

  if (file == NULL) {
    return CSVCAT_error_file_not_found;
  }

  ft->file_data = file;

  return 0;
}

File_info_t *New_file_info(char *filename, int idx) {
  File_info_t *myf;
  myf = (File_info_t *)malloc(sizeof(File_info_t));

  size_t open_ok = open_file(myf, filename);
  if (Is_error(open_ok)) {
    error_msg_exit(open_ok);
  }
  myf->name = filename;
  myf->index = idx;

  myf->csv_info = New_delimited_files_object(myf->file_data);
  return myf;
}

void close_file(FILE *fp) { fclose(fp); }
