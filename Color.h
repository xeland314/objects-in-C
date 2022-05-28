#ifndef _COLOR_H_
#define _COLOR_H_

#include "String.h"

typedef struct _color {
    char * color;
    char * mode;
} Color;

void Color_init(Color * clr, char * color, char * mode);
char * Color_toString(Color * color);
void Color_test(Color * color);

/* Color definitions: */
#define START_COLOR     "\033["
#define NORMAL_STDOUT   "\033[0m"

// Option colors:
#define NONE    "0m" 
#define BLACK   "30m"
#define RED     "31m"
#define GREEN   "32m"
#define YELLOW  "33m"
#define BLUE    "34m"
#define MAGENT  "35m"
#define CYAN    "36m"
#define WHITE   "37m"

// Mode colors:
#define NO_MODE     ""
#define NORMAL      "0;"
#define BOLD        "1;"
#define DARK        "2;"
#define ITALIC      "3;"
#define UNDERLINE   "4;"
#define BLINKING    "5;"
#define HIGHLIGHTED "7;"
#define CROSSED_OUT "9;"

#endif // !_COLOR_H_
