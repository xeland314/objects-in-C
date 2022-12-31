#ifndef _STRING_H_
#define _STRING_H_

#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include "Object.h"

typedef struct {
    const void * class;
    char * text;
} StringType;

extern const void * String;

/* 
 * STRING METHODS
 * The (void *) methods return another String
 */

void String_appendString(const void * str, const void * other);
void String_appendChar(const void * str, const char * text);
void * String_capitalize(const void * str);
void * String_casefold(const void * str);
void * String_center(const void * str, int length);
void * String_centerWithChar(const void * str, int length, const char * characterToFill);
void String_print(const void * str);
void String_println(const void * str);
void * String_reverse(const void * str);
void * String_swapcase(const void * str);
void * String_toupper(const void * str);

// TODO: implement the following methods:
unsigned int String_count(const void * str, const char * value);
unsigned int String_countBetweenLimits(const void * str, const char * value, int start, int end);
bool String_endswith(const void * str, const char * value);
bool String_endswithBetweenLimits(const void * str, const char * value, int start, int end);
bool String_startswith(const void * str, const char * value);
bool String_startswithBetweenLimits(const void * str, const char * value, int start, int end);
unsigned int String_find(const void * str, const char * value);
unsigned int String_findBetweenLimits(const void * str, const char * value, int start, int end);
unsigned int String_rfind(const void * str, const char * value);
unsigned int String_rfindBetweenLimits(const void * str, const char * value, int start, int end);
void * String_rstrip(const void * str);
void * String_lstrip(const void * str);
void * String_strip(const void * str);
void * String_rjust(const void * str);
void * String_ljust(const void * str);
void * String_just(const void * str);
void * String_title(const void * str);
void * String_zfill(const void * str);
void ** String_split(const void * str, const char * separator);

#endif // _STRING_H_
