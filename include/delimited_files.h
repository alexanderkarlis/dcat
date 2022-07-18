#ifndef DELIMITED_FILES_H
#define DELIMITED_FILES_H

#include <stdio.h>

typedef enum {
  // ','
  COMMA,
  // '\t'
  TAB,
  // '|'
  PIPE
} Delimiter;

typedef struct {
  char *headers;
  int rows_len, col_len;
  char *row_data;
  Delimiter delimiter;
} delimited_files_info_t;

/**
 * Allocates a new file info type
 *  @param[in] File pointer
 *  @param[out] new delimited_files info type
 */
delimited_files_info_t *New_delimited_files_object(FILE *);

/**
 * Returns a string of delimited_files headers
 *  @param[in] File pointer
 *  @param[out] delimited_files headers only
 */
char *get_headers(FILE *);

/**
 * Returns a string of all the file contents, W/O headers
 *  @param[in] File pointer
 *  @param[out] file contents, minus headers
 */
char *get_file_contents(FILE *fp);

/**
 * Count the number of rows in a file
 *  @param[in] File pointer
 *  @param[out] number of non-header rows
 */
int get_rows_len(FILE *file);

/**
 * Returns the first delimiter detected in the header row
 *  @param[in] char *header row
 *  @param[out]
 */
Delimiter get_file_delimiter(char *headers);

#endif
