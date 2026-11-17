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
