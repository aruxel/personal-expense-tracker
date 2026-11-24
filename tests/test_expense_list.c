#include <stdio.h>
#include <string.h>
#include "expense.h"

static int check(const char *name, int condition) {
    if (condition) {
        printf("PASS: %s\n", name);
        return 0;
    }
    printf("FAIL: %s\n", name);
    return 1;
}

int main(void) {
    int failures = 0;
    ExpenseList list = {0};
    init_expense_list(&list);

    failures += check("new list is empty", list.count == 0);
    failures += check("first id will be 1", list.next_id == 1);

    int added = add_expense(&list, "Lunch", 150.00, "Food", "2026-11-24");
    failures += check("first add succeeds", added == 1);
    failures += check("count is 1", list.count == 1);
    failures += check("first expense has id 1", list.items[0].id == 1);
    failures += check("description stored", strcmp(list.items[0].description, "Lunch") == 0);
    failures += check("next id is 2", list.next_id == 2);

    add_expense(&list, "Fare", 25.50, "Transportation", "2026-11-24");
    failures += check("second expense has id 2", list.items[1].id == 2);
    failures += check("count is 2", list.count == 2);

    while (list.count < MAX_EXPENSES) {
        add_expense(&list, "Filler", 1.00, "Others", "2026-11-24");
    }
    failures += check("list fills to capacity", list.count == MAX_EXPENSES);

    unsigned int id_before = list.next_id;
    int refused = add_expense(&list, "Overflow", 1.00, "Others", "2026-11-24");
    failures += check("add is refused when full", refused == 0);
    failures += check("count unchanged when full", list.count == MAX_EXPENSES);
    failures += check("next id unchanged when full", list.next_id == id_before);

    if (failures == 0) {
        printf("All tests passed.\n");
        return 0;
    }
    return 1;
}
