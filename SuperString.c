#include "SuperString.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <assert.h>
#include <locale.h>

void SuperStr_init(SuperStr * str, const wchar_t * text)
{
    setlocale(LC_ALL, "C.UTF-8");
    str -> text = malloc(sizeof(wchar_t *) * (wcslen(text) + 1));
    assert(str -> text);
    wcscpy(str -> text, text);
}

void SuperStr_println(SuperStr * str)
{
    printf("%ls\n", str -> text);
}
