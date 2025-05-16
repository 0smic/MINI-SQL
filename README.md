# MINI-SQL

**lightweight SQL engine built from scratch using C**

MINI-SQL is a minimalistic SQL engine developed in C, designed to execute a subset of SQL queries. 
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
