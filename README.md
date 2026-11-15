# Personal Expense Tracker

A command-line personal expense tracker built with C23, featuring expense management, financial summaries, search, filtering, and CSV data persistence.

> **Status:** Early development. Only the project setup and a welcome message are implemented. Everything under "Planned Features" is **not implemented yet**.

## Planned Features

- [ ] Add, view, edit, and delete expenses
- [ ] Categories: Food, Transportation, Education, Entertainment, Utilities, Others
- [ ] Financial summaries: total, by category, highest expense, average spending
- [ ] Search by description, and filter by category or date
- [ ] CSV data persistence with automatic saving
- [ ] Input validation for amounts and dates

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
- [x] Welcome message entry point
- [ ] Expense management
- [ ] Summaries, search, and filtering
- [ ] CSV persistence

## LICENSE

MIT License. See [LICENSE](LICENSE)
