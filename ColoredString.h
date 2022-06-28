#ifndef _COLOREDSTRING_H_
#define _COLOREDSTRING_H_

#include "String.h"
#include "Color.h"

typedef struct {
    String str;
    Color clr;
} ColoredString;

void ColoredString_init(
    ColoredString * cstr,
    const char * text,
    char * color, char * mode
);
int ColoredString_size(ColoredString * cstr);
void ColoredString_setText(ColoredString * cstr, const char * text);
void ColoredString_setColor(ColoredString * cstr, char * color, char * mode);
void ColoredString_print(ColoredString * cstr);
void ColoredString_println(ColoredString * cstr);
void ColoredString_delete(ColoredString * cstr);

#endif // !_COLOREDSTRING_H_
