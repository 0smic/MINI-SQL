#ifndef PARSER_H
#define PARSER_H
  #define MAX_COLUMNS 10
  #define MAX_ROWS 100
  void parser_command(const char *input);
  void create_parser(const char *input);
  void select_parser(const char *input);
  void delete_parser(const char *input);
  void insert_into_parser(const char *input);
  void update_parser(const char *input);
  void drop_parser(const char *input);
  int sep_column_datatype(char ***column_name, char ***column_datatype, char *column);
#endif
