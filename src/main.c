#include <stdio.h>
#include "expense.h"

int main(void) {
    printf("Welcome to the Personal Expense Tracker!\n\n");

    Expense lunch = create_expense(1, "Lunch", 150.00, "Food", "2026-11-16");

    display_expense(&lunch);

    printf("\nAccessing members directly:\n");
    printf("  ID: %u\n", lunch.id);
    printf("  Amount: %.2f\n", lunch.amount);
    printf("  First character of description: %c\n", lunch.description[0]);

    printf("\nsizeof(Expense) = %zu bytes\n", sizeof(Expense));
    
    return 0;
}
