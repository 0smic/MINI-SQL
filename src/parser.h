#ifndef PARSER_H
#define PARSER_H
  #include "datatype.h"
  void parser_command(const char *input);
  void create_parser(const char *input);
  void select_parser(const char *input);
  void delete_parser(const char *input);
  void insert_into_parser(const char *input);
  void update_parser(const char *input);
  void drop_parser(const char *input);
  int sep_column_datatype(char ***column_name, char ***column_datatype, char *column);
  int sep_column_values(char *columns, char *values, char **column_name, char **column_values);
  DataType get_data_type_from_string(const char *type_str);
#endif
