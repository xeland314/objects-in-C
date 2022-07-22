#include "../include/String.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    // Create some Strings:
    String str1, str2, str3, str4;
    String_init(&str1, "Hola, mundo");
    String_init(&str2, "Hello, world.");
    String_init(&str3, "1234567890");
    String_init(&str4, "abcdeFGHIJ");

    // Print Strings:
    String_println(&str1);
    String_println(&str2);
    String_print(&str3);
    String_println(&str4);

    // String sizes:
    printf("Size 1: %d\n", String_size(&str1));
    printf("Size 2: %d\n", String_size(&str2));
    printf("Size 3: %d\n", String_size(&str3));
    printf("Size 4: %d\n", String_size(&str4));

    // String compare:
    String_setText(&str1, "Hello, world.");
    
    if(String_compare(&str1, &str2) == 0)
        printf("%s == %s\n", str1.text, str2.text);
    else
        printf("Strings not equals.\n");

    if(String_compare(&str3, &str4) != 0)
        printf("%s != %s\n", str3.text, str4.text);
    else
        printf("Strings equals.\n");

    // Capitalize and casefold strings:
    String_capitalize(&str4);
    String_println(&str4);
    String_casefold(&str4);
    String_println(&str4);

    // Append strings ans chars:
    String_appendString(&str3, &str4);
    String_appendChar(&str2, "What's your name?");
    String_println(&str3);
    String_println(&str2);

    // Reverse string:
    String_reverse(&str1);
    String_println(&str1);

    // Delete strings:
    String_delete(&str1);
    String_delete(&str2);
    String_delete(&str3);
    String_delete(&str4);

    return 0;
}
