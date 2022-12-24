#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED
typedef struct Char4s{
    char(*ptr)[4];
    int count;
    }
Char4s;
int string_length(char* string);
int count_space_in_string(char* string);
Char4s parse_num_string(char* string);
char* string_trim_10(char* string);

#endif