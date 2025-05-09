# MINI-SQL

**A lightweight SQL engine built from scratch in C**

MINI-SQL is a minimalistic SQL engine developed in C, designed to execute a subset of SQL queries. It serves as an educational tool for understanding the core components of a database management system (DBMS), including parsing, query execution, and data storage.

## Features

- **SQL Query Parsing**: Interprets basic SQL commands such as `SELECT`, `INSERT`, `UPDATE`, and `DELETE`.
- **Data Storage**: Utilizes flat files for storing table data.
- **Command-Line Interface**: Operates through a terminal interface for executing SQL queries.
- **Educational Tool**: Ideal for learning the inner workings of SQL engines and DBMS concepts.

## Installation

To build and run MINI-SQL:

   ```bash
   git clone https://github.com/0smic/MINI-SQL.git
   cd MINI-SQL/src
   gcc main.c parser.c
   ./a.out
