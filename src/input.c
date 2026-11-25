#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

InputStatus read_line(char *buffer, size_t size) {
    if (fgets(buffer, (int)size, stdin) == NULL) {
        return INPUT_EOF;
    }

    size_t length = strcspn(buffer, "\n");

    if (buffer[length] == '\n') {
        buffer[length] = '\0';
        return INPUT_OK;
    }

    int ch = getchar();
    if (ch == EOF || ch == '\n') {
        return INPUT_OK;
    }

    while (ch != '\n' && ch != EOF) {
        ch = getchar();
    }
    return INPUT_TOO_LONG;
}

int parse_amount(const char *text, double *amount) {
    char *end;
    double value = strtod(text, &end);

    if (end == text || *end != '\0') {
        return 0;
    }

    if (!isfinite(value) || value <= 0.0) {
        return 0;
    }

    *amount = value;
    return 1;
}
