#include "String.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

void String_init(String * str, const char * text)
{
    str -> text = malloc(sizeof(char *) * (strlen(text) + 1));
    assert(str -> text);
    strcpy(str -> text, text);
}

int String_size(String * str)
{
    assert(str);
    return strlen(str -> text);
}

int String_compare(String* str, String* otherStr)
{
    if(str == otherStr)
        return 0;

    if(!otherStr)
        return 1;

    return strcmp(str -> text, otherStr -> text);
}

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

void String_delete(String * str)
{
    assert(str); free(str -> text);
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

String String_clone(String * str)
{
    String newStr;
    String_init(&newStr, str -> text);
    return newStr;
}
