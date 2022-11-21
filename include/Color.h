#ifndef _COLOR_H_
#define _COLOR_H_

typedef struct {
    const void * class;
    unsigned int attr;  // mode
    unsigned int fg; 	// foreground, text color
    unsigned int bg;    // background color
} ColorType;  

extern const void * Color;

void setColor(const void * _self);
void resetColor();

/* Color definitions: */
#define NORMAL_STDOUT   "\033[0m"

// Option colors {fg} and {bg}:
#define BLACK   0
#define RED     1
#define GREEN   2
#define YELLOW  3
#define BLUE    4
#define MAGENTA 5
#define CYAN    6
#define WHITE   7

// Mode colors {attr}
#define NORMAL      0
#define BOLD        1
#define BRIGHT      1
#define DARK        2
#define DIM         2
#define ITALIC      3
#define UNDERLINE   4
#define BLINK       5
#define HIGHLIGHTED 7
#define REVERSED    7
#define HIDDEN 	    8
#define CROSSED_OUT 9

#endif // !_COLOR_H_
