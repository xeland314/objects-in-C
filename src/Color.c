#include "../include/Color.h"
#include "../include/String.h"
#include "../include/Object.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static void * Color_init(void * _self, va_list * app)
{
    ColorType * self = _self;
    const char * color = va_arg(* app, const char *);
    const char * mode = va_arg(* app, const char *);
    self -> color = malloc(sizeof(char *) * 3);
    self -> mode = malloc(sizeof(char *) * 2);
    assert(self -> color); assert(self -> mode);
    strcpy(self -> color, color);
    strcpy(self -> mode, mode);
    return self;
}

static void * Color_delete(void * _self)
{
    ColorType * self = _self;
    free(self -> color), self -> color = 0;
    free(self -> mode), self -> mode = 0;
    return self;
}

static void * Color_clone(const void * _self)
{
    const ColorType * self = _self;
    return new(Color, self -> color, self -> mode);
}

static size_t Color_sizeOf(const void * _self)
{
    const ColorType * self = _self;
    size_t lenColor = strlen(self -> color);
    size_t lenMode = strlen(self -> mode);
    return lenColor + lenMode;
}

static int Color_differ(const void * _self, const void * _other)
{
    const ColorType * self = _self;
    const ColorType * other = _other;

    if(self == other)
        return 0;

    if(!other || (other -> class) != Color)
        return 1;
    
    size_t cmpColor = strcmp(self -> color, other -> color);
    size_t cmpMode = strcmp(self -> mode, other -> mode);

    return cmpColor + cmpMode;    
}

static char * Color_toString(const void * _self)
{
    const ColorType * self = _self;
    char * color = malloc(sizeof(char *) * 16);
    strcpy(color, START_COLOR);
    strcat(color, self -> mode);
    strcat(color, self -> color);
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
