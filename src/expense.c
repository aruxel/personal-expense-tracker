#include <stdio.h>
#include "expense.h"

Expense create_expense(
    unsigned int id,
    const char *description,
    double amount,
    const char *category,
    const char *date
) {
    Expense expense = {0};

    expense.id = id;
    snprintf(expense.description, sizeof(expense.description), "%s", description);
    expense.amount = amount;
    snprintf(expense.category, sizeof(expense.category), "%s", category);
    snprintf(expense.date, sizeof(expense.date), "%s", date);

    return expense;
}

void display_expense(const Expense *expense) {
    printf("ID: %u\n", expense->id);
    printf("Description: %s\n", expense->description);
    printf("Amount: %.2f\n", expense->amount);
    printf("Category: %s\n", expense->category);
    printf("Date: %s\n", expense->date);
}
