#include "../include/String.h"
#include "../include/Object.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

static void * String_init(void * _self, va_list * app)
{
    StringType * self = _self;
    const char * text = va_arg(* app, const char *);
    self -> text = malloc(sizeof(char *) * (strlen(text) + 1));
    assert(self -> text);
    strcpy(self -> text, text);
    return self;
}

static void * String_delete(void * _self)
{
    StringType * self = _self;
    free(self -> text), self -> text = 0;
    return self;
}

static void * String_clone(const void * _self)
{
    const StringType * self = _self;
    return new(String, self -> text);
}

static size_t String_sizeOf(const void * _self)
{
    const StringType * self = _self;
    return strlen(self -> text);
}

static int String_differ(const void * _self, const void * _other)
{
    const StringType * self = _self;
    const StringType * other = _other;

    if(self == other)
        return 0;

    if(!other || (other -> class) != String)
        return 1;

    return strcmp(self -> text, other -> text);
}

static char * String_toString(const void * _self)
{
    const StringType * self = _self;
    return self -> text;
}

static const Class _String = {
    sizeof(StringType),
    String_init,
    String_delete,
    String_clone,
    String_sizeOf, 
    String_differ,
    String_toString
};

const void * String = & _String;

/* STRING METHODS
 */

void String_reverse(const void * str) 
{
    const StringType * self = str;
    int left; char temp;
    int right = strlen(self -> text) - 1;
    for (left = 0; left < right; left++, right--) {
        temp = (self -> text)[left];
        (self -> text)[left] = (self -> text)[right];
        (self -> text)[right] = temp;
    }
}

void String_print(const void * str)
{
    const StringType * self = str;
    printf("%s", self -> text);
}

void String_println(const void * str)
{
    const StringType * self = str;
    printf("%s\n", self -> text);
}

void String_appendString(const void * str, const void * other)
{
    const StringType * self = str;
    const StringType * self2 = other;
    strcat(self -> text, self2 -> text);
}

void String_appendChar(const void * str, const char * text)
{
    const StringType * self = str;
    strcat(self -> text, text);
}

void String_toupper(const void * str)
{
    const StringType * self = str;
    for(int i = 0; i < (int)strlen(self -> text); i++)
    {
        char tmp = (self -> text)[i];
        (self -> text)[i] = toupper(tmp);
    }
}

void String_tolower(const void * str)
{
    const StringType * self = str;
    for(int i = 0; i < (int)strlen(self -> text); i++)
    {
        char tmp = (self -> text)[i];
        (self -> text)[i] = tolower(tmp);
    }
}

