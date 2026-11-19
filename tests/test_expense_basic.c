/* test_expense_basic.c - manual checks for create_expense and display_expense
*
* Compile and run from the project root:
*    clang -std=c23 -Wall -Wextra -Wpedantic -I include \
*       tests/test_expense_basic.c src/expense.c -o /tmp/test_expense_basic
*    /tmp/test_expense_basic
*/

#include <stdio.h>
#include <string.h>
#include "expense.h"

int main(void) {
    printf("--- Test 1: normal values ---\n");
    Expense a = create_expense(2, "Jeepney fare", 25.50, "Transportation", "2026-11-17");
    display_expense(&a);

    printf("\n--- Test 2: empty description ---\n");
    Expense b = create_expense(3, "", 0.00, "Others", "2026-11-17");
    display_expense(&b);
    printf("strlen(description) = %zu\n", strlen(b.description));

    printf("\n--- Test 3: large amount with extra decimals ---\n");
    Expense c = create_expense(4, "Concert tickets", 12345.678, "Entertainment", "2026-12-01");
    display_expense(&c);

    printf("\n--- Test 4: over-long description and category ---\n");
    Expense d = create_expense(
        5,
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        1.00,
        "Miscellaneous household and personal expenses",
        "2026-11-17"
    );
display_expense(&d);
printf("strlen(description) = %zu\n", strlen(d.description));
printf("strlen(category)    = %zu\n", strlen(d.category));

printf("\n--- Test 5: bad data (no validation yet) ---\n");
Expense e = create_expense(6, "Bad data", -50.00, "Utilities", "not-a-date");
display_expense(&e);

return 0;
}
