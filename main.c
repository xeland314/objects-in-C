#include "String.h"
#include "Color.h"
#include "ColoredString.h"
#include <stdio.h>

int main()
{
    String myString;
    String_init(&myString, "Hola mundo");
    String_println(&myString);
    String_setText(&myString, "AquÍ voy de nuevo");
    String_print(&myString);
    printf("\nSize: %d\n", String_size(&myString));
    String newStr;
    String_init(&newStr, "");
    String_setText(&newStr, "¿¿Hola :3!!");
    String_println(&newStr);

    Color myColor;
    Color_init(&myColor, CYAN, BLINKING);
    Color_test(&myColor);

    ColoredString colorStr;
    ColoredString_init(&colorStr, "¿Texto final!", GREEN, NORMAL);
    ColoredString_println(&colorStr);
    printf("Size: %d\n", ColoredString_size(&colorStr));

    String cpStr = String_clone(&newStr);
    printf("%d\n", String_compare(&cpStr, &myString));
    printf("%d\n", String_compare(&cpStr, &newStr));
    String_println(&cpStr);

    String_capitalize(&newStr);
    String_println(&newStr);
    String_casefold(&myString);
    String_println(&myString);

    String_delete(&myString);
    String_delete(&cpStr);
    String_delete(&newStr);

    return 0;
}
