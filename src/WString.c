#include "../include/WString.h"
#include "../include/Object.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <assert.h>
#include <locale.h>
#include <ctype.h>

static void * WString_init(void * _self, va_list * app)
{
    WStringType * self = _self;
    setlocale(LC_ALL, "C.UTF-8");
    const wchar_t * text = va_arg(* app, const wchar_t *);
    self -> text = malloc(sizeof(wchar_t *) * (wcslen(text) + 1));
    assert(self -> text);
    wcscpy(self -> text, text);
    return self;
}

static void * WString_delete(void * _self)
{
    WStringType * self = _self;
    free(self -> text), self -> text = 0;
    return self;
}

static void * WString_clone(const void * _self)
{
    const WStringType * self = _self;
    return new(WString, self -> text);
}

static size_t WString_sizeOf(const void * _self)
{
    const WStringType * self = _self;
    return wcslen(self -> text);
}

static int WString_differ(const void * _self, const void * _other)
{
    const WStringType * self = _self;
    const WStringType * other = _other;

    if(self == other)
        return 0;

    if(!other || (other -> class) != WString)
        return 1;

    return wcscmp(self -> text, other -> text);
}

static char * WString_toString(const void * _self)
{
    const WStringType * self = _self;
    char * text = malloc(sizeof(char *) * (wcslen(self -> text) + 1));
    sprintf(text, "%ls", self -> text);
    return text;
}

static const Class _WString = {
    sizeof(WStringType),
    WString_init,
    WString_delete,
    WString_clone,
    WString_sizeOf, 
    WString_differ,
    WString_toString
};

const void * WString = & _WString;

wchar_t * toWchar(const void * _wstring)
{
    const WStringType * wstring = _wstring;
    wchar_t * text = malloc(sizeof(wchar_t *) * (wcslen(wstring -> text) + 1));
    wcscpy(text, wstring -> text);
    return text;
}

