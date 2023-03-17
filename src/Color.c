#include "Color.h"
#include "String.h"
#include "Object.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void * Color_init(void * _self, va_list * app)
{
    ColorType * self = _self;
    self -> attr = va_arg(* app, unsigned int);
    self -> fg = va_arg(* app, unsigned int);
    self -> bg = va_arg(* app, unsigned int);
    return self;
}

static void * Color_delete(void * _self)
{
    ColorType * self = _self;
    self -> attr = 0;
    self -> fg = 0;
    self -> bg = 0;
    return self;
}

static void * Color_clone(const void * _self)
{
    const ColorType * self = _self;
    return new(Color, self -> attr, self -> fg, self -> bg);
}

static size_t Color_sizeOf(const void * _self)
{
    const ColorType * self = _self;
    return sizeof(self);
}

static int Color_differ(const void * _self, const void * _other)
{
    const ColorType * self = _self;
    const ColorType * other = _other;

    if(self == other)
        return 0;

    if(!other || (other -> class) != Color)
        return 1;
    
    int diffAttr = self -> attr - other -> attr;
    int diffFg = self -> fg - other -> fg;
    int diffBg = self -> bg - other -> bg;
    return diffAttr + diffFg + diffBg;    
}

static char * Color_toString(const void * _self)
{
    const ColorType * self = _self;
    char * color = malloc(sizeof(char *) * 13);
	sprintf(
        color, "\033[%d;%d;%dm",
        self -> attr + 0,
        self -> fg + 30, 
        self -> bg + 40
    );
    return color;
}

static const Class _Color = {
    sizeof(ColorType),
    Color_init,
    Color_delete,
    Color_clone,
    Color_sizeOf,
    Color_differ,
    Color_toString
};

const void * Color = & _Color;

void resetColor()
{
    printf(NORMAL_STDOUT);
}

void setColor(const void * _self)
{
    const ColorType * self = _self;
    printf("%s", toString(self));
}
