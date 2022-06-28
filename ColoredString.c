#include "ColoredString.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ColoredString_init(ColoredString * cstr, const char * text, char * color, char * mode)
{
    String tmpStr; Color tmpClr;
    String_init(&tmpStr, text);
    Color_init(&tmpClr, color, mode);
    cstr -> str = tmpStr;
    cstr -> clr = tmpClr;
}
int ColoredString_size(ColoredString * cstr)
{
    return String_size(&cstr->str);
}
void ColoredString_setText(ColoredString * cstr, const char * text)
{
    String_setText(&cstr -> str, text);
}
void ColoredString_setColor(ColoredString * cstr, char * color, char * mode)
{
    strcpy((&cstr -> clr) -> color, color);
    strcpy((&cstr -> clr) -> mode, mode);
}
void ColoredString_print(ColoredString * cstr)
{
    printf("%s%s%s", 
        Color_toString(&cstr -> clr),
        (&cstr -> str) -> text,
        NORMAL_STDOUT
    );
}
void ColoredString_println(ColoredString * cstr)
{
    ColoredString_print(cstr); printf("\n");
}
void ColoredString_delete(ColoredString * cstr)
{
    String_delete(&cstr->str);
    Color_delete(&cstr->clr);
}
