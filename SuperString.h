#ifndef _SUPERSTRING_H_
#define _SUPERSTRING_H_

#include <wchar.h>

typedef struct {
    wchar_t * text;
} SuperStr;

void SuperStr_init(SuperStr * str, const wchar_t * text);
void SuperStr_println(SuperStr * str);

#endif // _SUPERSTRING_H_
