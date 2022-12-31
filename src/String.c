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

void String_appendChar(const void * str, const char * text) {
    const StringType * self = str;
    strcat(self -> text, text);
}

void String_appendString(const void * str, const void * other) {
    const StringType * self = str;
    const StringType * self2 = other;
    strcat(self -> text, self2 -> text);
}

void * String_capitalize(const void * str) {
    void * capitalizedString = clone(str);
    const StringType * self = capitalizedString;
    char tmp = (self -> text)[0];
    (self -> text)[0] = toupper(tmp);
    for (int i = 1; i < (int)strlen(self -> text); ++i) {
        tmp = (self -> text)[i];
        (self -> text)[i] = tolower(tmp);
    }
    return capitalizedString;
}

void * String_casefold(const void * str) {
    void * casefoldedString = clone(str);
    const StringType * self = casefoldedString;
    for(int i = 0; i < (int)strlen(self -> text); i++) {
        char tmp = (self -> text)[i];
        (self -> text)[i] = tolower(tmp);
    }
    return casefoldedString;
}

void * String_centerWithChar(
    const void * str,
    int length,
    const char * characterToFill
){
    if(strlen(characterToFill) > 1) {
        puts("StringException:");
        puts("\tMethod: String_center_with_char");
        puts("\tThe fill character must be exactly one character long.");
        exit(1);
    }

    const StringType * self = str;
    int strLength = strlen(self -> text);
    
    if(length <= strLength) {
        return clone(str);
    }
    
    if(strlen(characterToFill) == 0) {
        characterToFill = " ";
    }

    int spaces = length - strLength;
    char * centeredText = malloc(sizeof(char *) * (length));

    if(spaces % 2 == 0) {
        // If the number of spaces is even
        // add spaces/2 characters to the original
        // string to center it.
        int n = spaces / 2;
        for (int i = 0; i < n; i++) {
            strcat(centeredText, characterToFill);
        }
        strcat(centeredText, self -> text);
        for (int i = 0; i < n; i++) {
            strcat(centeredText, characterToFill);
        }
    } else {
        // Else add spaces/2 + 1 at the begin 
        // of the string and the rest of spaces
        // at the end.
        int n = spaces / 2 + 1;
        for (int i = 0; i < n; i++) {
            strcat(centeredText, characterToFill);
        }
        strcat(centeredText, self -> text);
        for (int i = 0; i < n - 1; i++) {
            strcat(centeredText, characterToFill);
        }
    }
    void * centeredString = new(String, centeredText);
    return centeredString;
}

void * String_center(const void * str, int length) {
    return String_centerWithChar(str, length, " ");
}

void String_print(const void * str) {
    const StringType * self = str;
    printf("%s", self -> text);
}

void String_println(const void * str) {
    const StringType * self = str;
    printf("%s\n", self -> text);
}

void * String_reverse(const void * str) {
    void * reversedString = clone(str);
    const StringType * self = reversedString;
    
    int left; char temp;
    int right = strlen(self -> text) - 1;
    for (left = 0; left < right; left++, right--) {
        temp = (self -> text)[left];
        (self -> text)[left] = (self -> text)[right];
        (self -> text)[right] = temp;
    }
    return reversedString;
}

void * String_swapcase(const void * str) {
    void * swapcasedString = clone(str);
    const StringType * self = swapcasedString;
    for (int i = 0; i < (int)strlen(self -> text); i++) {
        char tmp = (self -> text)[i];
        if(isupper(tmp)) {
            (self -> text)[i] = tolower(tmp);
        } else if(islower(tmp)) {
            (self -> text)[i] = toupper(tmp);
        } else {
            continue;
        }
    }
    return swapcasedString;
}

void * String_toupper(const void * str) {
    void * upperedString = clone(str);
    const StringType * self = upperedString;
    for(int i = 0; i < (int)strlen(self -> text); i++) {
        char tmp = (self -> text)[i];
        (self -> text)[i] = toupper(tmp);
    }
    return upperedString;
}

