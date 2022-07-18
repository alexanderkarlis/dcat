#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "delimited_files.h"

#define MAX_LINE_LENGTH 256

void append(char *s, char c) {
  size_t len = strlen(s);
  s[len] = c;
  s[len + 1] = '\0';
}

char *get_delimited_files_contents(FILE *file) {
  int c;
  char *s;
  size_t i = 1;

  s = malloc(i * sizeof(char));

  if (s == NULL) {
    printf("memory allocation failure\n");
    free(s);
    s = NULL;
    return NULL;
  }

  *s = '\0';
  while ((c = getc(file)) != EOF) {
    i++;
    s = realloc(s, i * sizeof(char));
    if (s == NULL) {
      printf("memory allocation failure\n");
      free(s);
      s = NULL;
      return NULL;
    }
    append(s, c);
  }
  return s;
}

int count_cols(char *cols) {
  char *dupe;
  dupe = strdup(cols);

  size_t count = 0;
  char *token;
  const char s[1] = ",";

  token = strtok(dupe, s);
  while (token != NULL) {
    count++;
    token = strtok(NULL, s);
  }

  free(dupe);
  return count;
}

char *get_headers(FILE *file) {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  // only get first line
  while ((read = getline(&line, &len, file)) != EOF) {
    for (int i = 0; i < strlen(line); i++) {
    }
    break;
  }
  // TODO: handle the case if the first line is empty
  if (line == NULL) {
    perror("Error: read line is empty!");
  }
  return line;
}

int get_rows_len(FILE *file) {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  // only get first line
  int count = 0;
  while ((read = getline(&line, &len, file)) != EOF && count != 0) {
    count++;
  }

  if (line == NULL) {
    perror("Error: read line is empty!");
  }
  free(line);
  return count;
}

Delimiter get_file_delimiter(char *headers) {
  for (int i = 0; i < strlen(headers); i++) {
    switch (headers[i]) {
    case ',':
      return COMMA;
    case '|':
      return PIPE;
    case '\t':
      return TAB;
    }
  }
  // return default as comma
  return COMMA;
}

delimited_files_info_t *New_delimited_files_object(FILE *file) {
  delimited_files_info_t *c_info;

  c_info = (delimited_files_info_t *)malloc(sizeof(delimited_files_info_t));

  c_info->headers = get_headers(file);
  c_info->col_len = count_cols(c_info->headers);
  c_info->rows_len = get_rows_len(file);
  c_info->delimiter = get_file_delimiter(c_info->headers);

  char *a = get_delimited_files_contents(file);
  c_info->row_data = a;
  return c_info;
}
