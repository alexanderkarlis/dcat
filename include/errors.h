#ifndef CSVCAT_ERRORS_H
#define CSVCAT_ERRORS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  CSVCAT_error_no_error = 0,
  CSVCAT_error_GENERIC = 1,
  CSVCAT_error_file_not_found = 10,
} CSVCAT_ErrorCode;

bool Is_error(CSVCAT_ErrorCode code) { return code != CSVCAT_error_no_error; }

void error_msg_exit(CSVCAT_ErrorCode code) {
  switch (code) {
  case CSVCAT_error_GENERIC:
    printf("error: an error has occured!\n");
    exit(1);
  case CSVCAT_error_file_not_found:
    printf("error: file not found!\n");
    exit(1);
  default:
    printf("error: file not found!\n");
    break;
  }
}

#endif
