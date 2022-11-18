#ifndef _STRING_H_
#define _STRING_H_

#include <stdarg.h>
#include <stddef.h>
#include "Object.h"

typedef struct {
    const void * class;
    char * text;
} StringType;

extern const void * String;

/*
void String_setText(String * str, const char * text);
void String_println(String * str);
void String_print(String * str);

void String_appendString(String * str, String * otherstr);
void String_appendChar(String * str, const char * text);

void String_capitalize(String * str);
void String_casefold(String * str);
void String_reverse(String * str);
*/ 

#endif // _STRING_H_
