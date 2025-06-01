# MINI-SQL

**lightweight SQL engine built from scratch using C**

Started with my extraordinary curiosity and stuck in the void, debugging segmentation fault using only intuition and mirror

As a said it's light as feather it contain only parser and thinking Abt engine? maybe we need v20 twin engine with hyper-tuned, realism-enhanced, quantum powdered execution layer.( it complex that's what I'm saying atleast you get it)

although i managed to implement table creation and give the user to choose the datatype dynamically for columns.

for rows I'm confused wheather void ** or unions might be better even tho I implemented void **

## Features

- **SQL Query Parsing**: Interprets basic SQL commands such as `SELECT`, `INSERT`, `UPDATE`, and `DELETE`.
- **Data Storage**: Use flat files for storing table data.
- **Command-Line Interface**: Operates through a terminal interface for executing SQL queries.

## Installation

To build and run MINI-SQL:

   ```bash
   git clone https://github.com/0smic/MINI-SQL.git
   cd MINI-SQL/src
   gcc main.c parser.c engine.c
   ./a.out
```

## Disclaimer 

Work in progress 