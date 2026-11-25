#ifndef INPUT_H
#define INPUT_H

#include <stddef.h>

typedef enum {
    INPUT_OK,
    INPUT_EOF,
    INPUT_TOO_LONG
} InputStatus;

InputStatus read_line(char *buffer, size_t size);
int parse_amount(const char *text, double *amount);

#endif
