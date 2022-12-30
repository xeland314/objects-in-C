#ifndef _WSTRING_H_
#define _WSTRING_H_

#include <stdarg.h>
#include <stddef.h>
#include "Object.h"
#include <wchar.h>

typedef struct {
    const void * class;
    wchar_t * text;
} WStringType;

extern const void * WString;

wchar_t * toWchar(const void * _wstring);

#endif // _WSTRING_H_
