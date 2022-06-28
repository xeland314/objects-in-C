#include "String.h"
#include "Color.h"
#include "ColoredString.h"
#include <stdio.h>

int main()
{
    // Inicializar variables:
    String myString, newStr, cpStr;
    String_init(&myString, "Hola mundo");
    String_init(&newStr, "");
    // Test string functions:
    String_println(&myString);
    String_setText(&myString, "AquÍ voy de nuevo");
    String_print(&myString);
    printf("\nSize: %d\n", String_size(&myString));
    String_setText(&newStr, "Hola");
    String_println(&newStr);
    // String clone:
    cpStr = String_clone(&newStr);
    printf("%d\n", String_compare(&cpStr, &myString));
    printf("%d\n", String_compare(&cpStr, &newStr));
    String_println(&cpStr);
    // Capitalize, casefold and reverse strings:
    String_capitalize(&newStr);
    String_println(&newStr);
    String_casefold(&myString);
    String_println(&myString);
    String_reverse(&newStr);
    String_println(&newStr);
    // Append string to other string:
    String_appendString(&newStr, &myString);
    String_println(&newStr);
    String_appendChar(&newStr, "Chris");
    String_println(&newStr);
    // Free variables from memory:
    String_delete(&myString);
    String_delete(&cpStr);
    String_delete(&newStr);

    Color myColor;
    Color_init(&myColor, CYAN, BLINKING);
    Color_test(&myColor);

    ColoredString colorStr;
    ColoredString_init(&colorStr, "¿Texto final!", GREEN, NORMAL);
    ColoredString_println(&colorStr);
    printf("Size: %d\n", ColoredString_size(&colorStr));

    ColoredString_delete(&colorStr);
    Color_delete(&myColor);

    return 0;
}
