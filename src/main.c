#include <stdio.h>
#include "menu.h"

int main(void) {
    printf("Welcome to the Personal Expense Tracker!\n\n");

    int choice;
    do {
        display_main_menu();
        choice = get_menu_choice();
        printf("\n");
        handle_menu_choice(choice);
        printf("\n");
    } while (choice != 0);

    return 0;
}
