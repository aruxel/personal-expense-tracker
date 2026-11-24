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
void init_expense_list(ExpenseList *list) {
    list->count = 0;
    list->next_id = 1;
}

int add_expense(
    ExpenseList *list,
    const char *description,
    double amount,
    const char *category,
    const char *date
) {
    if (list->count >= MAX_EXPENSES) {
        return 0;
    }

    list->items[list->count] = create_expense(
        list->next_id, description, amount, category, date
    );
    list->count++;
    list->next_id++;

    return 1;
}
