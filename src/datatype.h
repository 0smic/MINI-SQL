#ifndef DATATYPE_H
#define DATATYPE_H
typedef enum {
    MYSQL_TYPE_TINY,        // TINYINT
    MYSQL_TYPE_SHORT,       // SMALLINT
    MYSQL_TYPE_LONG,        // INT or INTEGER
    MYSQL_TYPE_FLOAT,       // FLOAT
    MYSQL_TYPE_DOUBLE,      // DOUBLE or REAL
    MYSQL_TYPE_NULL,        // NULL-type column

} DataType;
#endif // DATATYPE_H
