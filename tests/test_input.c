#include <stdio.h>
#include "input.h"

static int check_amount(const char *text, int should_be_valid, double expected) {
    double value = 0.0;
    int valid = parse_amount(text, &value);

    if (valid != should_be_valid) {
        printf("FAIL: \"%s\" validity\n", text);
        return 1;
    }
    if (valid && value != expected) {
        printf("FAIL: \"%s\" value\n", text);
        return 1;
    }
    printf("PASS: \"%s\"\n", text);
    return 0;
}

int main(void) {
    int failures = 0;

    failures += check_amount("150", 1, 150.0);
    failures += check_amount("25.50", 1, 25.50);
    failures += check_amount("0.01", 1, 0.01);
    failures += check_amount(" 7", 1, 7.0);
    failures += check_amount("1e3", 1, 1000.0);
    failures += check_amount("abc", 0, 0.0);
    failures += check_amount("", 0, 0.0);
    failures += check_amount("12abc", 0, 0.0);
    failures += check_amount("-5", 0, 0.0);
    failures += check_amount("0", 0, 0.0);
    failures += check_amount("nan", 0, 0.0);
    failures += check_amount("inf", 0, 0.0);

    printf("--- read_line, buffer size 8 ---\n");
    char buffer[8];
    for (int i = 1; i <= 7; i++) {
        InputStatus status = read_line(buffer, sizeof(buffer));
        if (status == INPUT_OK) {
            printf("line %d: OK [%s]\n", i, buffer);
        } else if (status == INPUT_TOO_LONG) {
            printf("line %d: TOO_LONG\n", i);
        } else {
            printf("line %d: EIF\n", i);
        }
    }

    return failures;
}
