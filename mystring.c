#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mystring.h"
#ifndef ENOUGH20
#define ENOUGH20 10
#endif
int string_length(char* string){
int i=0;
while(string[i]!='\0'){
    i++;
}
return i;
}
int count_space_in_string(char* string){
    
    int count=0;
    int i=0;
    while(string[i]!='\0'){
    if(string[i]<'0'||string[i]>'9'){
        count++;
    }
    i++;
    }
    return count;
};
Char4s parse_num_string(char* string){
    int i=0;
    int j=0;
    Char4s char4s;
  
char(*ptr)[4]=(char(*)[4])malloc(sizeof(char)*ENOUGH20*4);
char4s.ptr=ptr;
char string_buffer[ENOUGH20];
int digit_counter=0;
int char_counter=0;
int number_counter=0;
while(string[i]!='\0'){
    if(string[i]>='0'&&string[i]<='9'){
        digit_counter++;
        if(string[i+1]=='\0'){
            strncpy(string_buffer,string+char_counter,digit_counter);string_buffer[digit_counter]='\0';
            memcpy(ptr[number_counter],string_buffer,digit_counter);ptr[number_counter][digit_counter]='\0';
            number_counter++;
        }
    }else{
    strncpy(string_buffer,string+char_counter,digit_counter);string_buffer[digit_counter]='\0';
    memcpy(ptr[number_counter],string_buffer,digit_counter);ptr[number_counter][digit_counter]='\0';
    char_counter+=digit_counter+1;
    digit_counter=0;
    number_counter++;
    }

i++;
}
char4s.count=number_counter;
return char4s;
};
char* string_trim_10(char* string){
    int i=0;
char* string2=(char*)malloc(sizeof(char)*ENOUGH20);
memcpy(string2,string,string_length(string));
for(i=string_length(string);i<ENOUGH20;i++){
string2[i] = ' ';
}

string2[ENOUGH20-1]='$';
string2[ENOUGH20]='\0';

return string2;
};

