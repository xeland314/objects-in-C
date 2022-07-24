#include "../include/String.h"
#include "../include/Object.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

static void * String_init(void * _self, va_list * app)
{
    String * self = _self;
    const char * text = va_arg(* app, const char *);
    self -> text = malloc(sizeof(char *) * (strlen(text) + 1));
    assert(self -> text);
    strcpy(self -> text, text);
    return self;
}

static void * String_delete(void * _self)
{
    String * self = _self;
    free(self -> text), self -> text = 0;
    return self;
}

static void * String_clone(const void * _self)
{
    const String * self = _self;
    return new(str, self -> text);
}

static size_t String_sizeOf(const void * _self)
{
    const String * self = _self;
    return strlen(self -> text);
}

static int String_differ(const void * _self, const void * _other)
{
    const String * self = _self;
    const String * other = _other;

    if(self == other)
        return 0;

    if(!other || (other -> class) != str)
        return 1;

    return strcmp(self -> text, other -> text);
}

static const Class _String = {
    sizeof(String),
    String_init, String_delete,
    String_clone, String_sizeOf, 
    String_differ
};

const void * str = & _String;

/*
void String_setText(String * str, const char * text)
{
    assert(str); strcpy(str -> text, text); 
}

void String_print(String * str)
{
    printf("%s", str -> text);
}

void String_println(String * str)
{
    printf("%s\n", str -> text);
}

void String_appendString(String * str, String * otherstr)
{
    assert(str);
    strcat(str -> text, otherstr -> text);
}

void String_appendChar(String * str, const char * text)
{
    assert(str);
    strcat(str -> text, text);
}

void String_capitalize(String * str)
{
    for(int i = 0; i < String_size(str); i++)
    {
        char tmp = (str -> text)[i];
        (str -> text)[i] = toupper(tmp);
    }
}

void String_casefold(String * str)
{
    for(int i = 0; i < String_size(str); i++)
    {
        char tmp = (str -> text)[i];
        (str -> text)[i] = tolower(tmp);
    }
}

void String_reverse(String * str) {

    int left; char temp;
    int right = String_size(str) - 1;

    for (left = 0; left < right; left++, right--) {
        temp = (str -> text)[left];
        (str -> text)[left] = (str -> text)[right];
        (str -> text)[right] = temp;
    }
}
*/
