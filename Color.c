#include "Color.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void Color_init(Color * clr, char * color, char * mode)
{
    clr -> color = malloc(sizeof(char *) * 3);
    clr -> mode = malloc(sizeof(char *) * 2);
    assert(clr -> color); assert(clr -> mode);
    strcpy(clr -> color, color);
    strcpy(clr -> mode, mode);
}

char * Color_toString(Color * color)
{
    assert(color);
    char * tmp = malloc(sizeof(char *) * 16);
    strcpy(tmp, START_COLOR);
    strcat(tmp, color -> mode);
    strcat(tmp, color -> color);
    return tmp;
}

void Color_test(Color * color)
{
    String strColor, testText;
    String_init(&strColor, Color_toString(color));
    String_init(&testText, "########");
    String_print(&strColor);
    String_println(&testText);
    // Back to normal stdout:
    printf(NORMAL_STDOUT);
}
