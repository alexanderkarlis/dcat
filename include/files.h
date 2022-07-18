#ifndef FILES_H
#define FILES_H

#include <stdint.h>
#include <stdio.h>

#include "delimited_files.h"

typedef struct {
  int index;
  char *name;
  FILE *file_data;

  delimited_files_info_t *csv_info; // Get an allocated csv info type
} File_info_t;

/**
 * Allocates a new file info type
 *  @param[in] name of file
 *  @param[in] index in the list of passed in files
 *  @param[out] new file info t
 */
File_info_t *New_file_info(char *, int);

/**
 * Opens the passed in file location
 *  @param[in] string to file location
 *  @param[out] file object
 */
size_t open_file(File_info_t *ft, const char *fname);

/**
 * Close file object
 *  @param[in] string to file location
 *  @param[out] file object
 */
void close_file(FILE *);

#endif
