# Personal Expense Tracker

A command-line personal expense tracker built with C23, featuring expense management, financial summaries, search, filtering, and CSV data persistence.

> **Status:** Early development. The expense data model and basic expense functions are implemented. Everything under "Planned Features" is **not implemented yet**.

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

## Development Status

- [x] Project setup and repository
- [x] Makefile build system
- [x] Expense data structure and category enumeration
- [x] Basic expense creation and display
- [ ] Expense management (add, edit, delete)
- [ ] Summaries, search, and filtering
- [ ] CSV persistence

## LICENSE

MIT License. See [LICENSE](LICENSE)
