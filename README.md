# Personal Expense Tracker

A command-line personal expense tracker built with C23, featuring expense management, financial summaries, search, filtering, and CSV data persistence.

> **Status:** Early development. The expense data model, basic expense functions, and a menu interface are implemented. The menu options are placeholders, and everything under "Planned Features" is **not implemented yet**.

## Planned Features

- [ ] Add, view, edit, and delete expenses
- [ ] Categories: Food, Transportation, Education, Entertainment, Utilities, Others
- [ ] Financial summaries: total, by category, highest expense, average spending
- [ ] Search by description, and filter by category or date
- [ ] CSV data persistence with automatic saving
- [ ] Input validation for amounts and dates

## Data Model

Each expense is stored in an `Expense` structure, defined in `include/expense.h`.

| Member | Type | Purpose |
|---|---|---|
| `id` | `unsigned int` | Unique expense identifier |
| `description` | `char[100]` | Expense description (up to 99 characters) |
| `amount` | `double` | Expense amount |
| `category` | `char[30]` | Category name (up to 29 characters) |
| `date` | `char[11]` | Date as `YYYY-MM-DD` |

An `ExpenseCategory` enumeration (`FOOD`, `TRANSPORTATION`, `EDUCATION`, `ENTERTAINMENT`, `UTILITIES`, `OTHERS`) is defined but is not used by the `Expense` structure yet.

Implemented functions:

- `create_expense()` builds an `Expense`. Text longer than a field is truncated.
- `display_expense()` prints one `Expense`.

Input validation is **not implemented yet**, so invalid amounts and dates are currently accepted.

## Technologies Used

- C23
- Clang
- Make
- Git and GitHub
- CSV for data storage

## Project Structure

```text
personal-expense-tracker/
|-- src/        # Source files (.c)
|-- include/    # Header files (.h)
|-- data/       # CSV data files
|-- tests/      # Test files
|-- Makefile
|-- README.md
|-- .gitignore
|-- LICENSE
```

## Installation Requirements

- macOS (developed on Apple Silicon)
- Clang with C23 support (included with Xcode Command Line Tools)
- Make
- Git

## Compilation

```bash
git clone https://github.com/aruxel/personal-expense-tracker.git
cd personal-expense-tracker
make
```

## Execution

```bash
make run
```
To remove build files:
```bash
make clean
```

## Menu

Running the program shows a main menu. Enter a number and press Enter.

| Option | Action | Status |
|---|---|---|
| 1 | Add Expense | Placeholder |
| 2 | View All Expenses | Placeholder |
| 3 | Edit Expense | Placeholder |
| 4 | Delete Expense | Placeholder |
| 5 | Financial Summary | Placeholder |
| 6 | Search Expenses | Placeholder |
| 7 | Filter Expenses | Placeholder |
| 0 | Exit | Working |

Invalid input (letters, empty lines, extra characters, or numbers that are not menu options) shows an error message and returns to the menu. The menu code is in `src/menu.c` and `include/menu.h`.

To run the menu checks (build first with `make`):

```bash
sh tests/test_menu.sh
```

## Development Status

- [x] Project setup and repository
- [x] Makefile build system
- [x] Expense data structure and category enumeration
- [x] Basic expense creation and display
- [x] Menu navigation (options are placeholders)
- [ ] Expense management (add, edit, delete)
- [ ] Summaries, search, and filtering
- [ ] CSV persistence

## LICENSE

MIT License. See [LICENSE](LICENSE)
