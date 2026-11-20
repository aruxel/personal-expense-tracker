#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

void display_main_menu(void) {
    printf("========================================\n");
    printf("       PERSONAL EXPENSE TRACKER\n");
    printf("========================================\n");
    printf("\n");
    printf("[1] Add Expense\n");
    printf("[2] View All Expenses\n");
    printf("[3] Edit Expense\n");
    printf("[4] Delete Expense\n");
    printf("\n");
    printf("----------------------------------------\n");
    printf("\n");
    printf("[5] Financial Summary\n");
    printf("\n");
    printf("----------------------------------------\n");
    printf("\n");
    printf("[6] Search Expenses\n");
    printf("[7] Filter Expenses\n");
    printf("\n");
    printf("----------------------------------------\n");
    printf("\n");
    printf("[0] Exit\n");
    printf("\n");
    printf("========================================\n");
    printf("Enter your choice: ");
}

int get_menu_choice(void) {
    char buffer[64];
    char *end;

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 0;
    }

    size_t length = strcspn(buffer, "\n");

    if (buffer[length] == '\0' && length == sizeof(buffer) - 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            /* discard the rest of an over-long line */
        }
        return -1;
    }

    buffer[length] = '\0';

    long value = strtol(buffer, &end, 10);

    if (end == buffer || *end != '\0') {
        return -1;
    }

    if (value < INT_MIN || value > INT_MAX) {
        return -1;
    }

    return (int)value;
}

void handle_menu_choice(int choice) {
    switch (choice) {
        case 1:
            printf("Add Expense functionality is not available yet.\n");
            break;
        case 2:
            printf("View All Expense functionality is not available yet.\n");
            break;
        case 3:
            printf("Edit Expense functionality is not available yet.\n");
            break;
        case 4:
            printf("Delete Expense functionality is not available yet.\n");
            break;
        case 5:
            printf("Financial Summary functionality is not available yet.\n");
            break;
        case 6:
            printf("Search Expenses functionality is not available yet.\n");
            break;
        case 7:
            printf("Filter Expenses functionality is not available yet.\n");
            break;
        case 0:
            printf("Thank you for using Personal Expense Tracker.\n");
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid selection. Please try again.\n");
            break;
    }
}
