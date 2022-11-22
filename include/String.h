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

// STRING METHODS
void String_appendString(const void * str, const void * other);
void String_appendChar(const void * str, const char * text);
void String_print(const void * str);
void String_println(const void * str);
void String_reverse(const void * str);
void String_toupper(const void * str);
void String_tolower(const void * str);

#endif // _STRING_H_
