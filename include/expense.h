#ifndef EXPENSE_H
#define EXPENSE_H

/* expense.h - data model for a single expense record */

typedef enum {
    FOOD =1,
    TRANSPORTATION,
    EDUCATION,
    ENTERTAINMENT,
    UTILITIES,
    OTHERS
} ExpenseCategory;

typedef struct {
    unsigned int id;
    char description[100];
    double amount;
    char category[30];
    char date[11];
} Expense;

Expense create_expense(
    unsigned int id,
    const char *description,
    double amount,
    const char *category,
    const char *date
);

void display_expense(const Expense *expense);

#endif
