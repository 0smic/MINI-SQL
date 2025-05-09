#ifndef PARSER_H
#define PARSER_H
  void parser_command(const char *input);
  void create_table(const char *input);
  void select_func(const char *input);
  void delete_func(const char *input);
  void insert_into(const char *input);
  void update_func(const char *input);
  void drop_table(const char *input);
#endif
