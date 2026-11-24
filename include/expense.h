#ifndef EXPENSE_H
#define EXPENSE_H

#include <stddef.h>

/* expense.h - data model for a single expense record */

#define MAX_EXPENSES 100

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

typedef struct {
    Expense items[MAX_EXPENSES];
    size_t count;
    unsigned int next_id;
} ExpenseList;

Expense create_expense(
    unsigned int id,
    const char *description,
    double amount,
    const char *category,
    const char *date
);

void display_expense(const Expense *expense);

void init_expense_list(ExpenseList *list);

int add_expense(
    ExpenseList *list,
    const char *description,
    double amount,
    const char *category,
    const char *date
);

#endif
