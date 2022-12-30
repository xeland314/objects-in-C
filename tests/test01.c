#include "../include/String.h"
#include "../include/Object.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    void * a = new(String, "Hello, world!!"), * aa = clone(a);
    void * b = new(String, "b");
    
    printf("sizeOf(a) == %lu\n", sizeOf(a));
    
    if (differ(a, b))
        puts("ok");
    
    if (differ(a, aa))
        puts("differ?");
    
    if (a == aa)
        puts("clone?");
    
    printf("a = %s\n", toString(a));
    printf("aa = %s\n", toString(aa));
    printf("b = %s\n", toString(b));
    
    String_reverse(a);
    printf("a reversed = %s\n", toString(a));

    String_reverse(a);
    String_println(a);

    String_tolower(a);
    String_println(a);

    String_toupper(a);
    String_println(a);

    String_appendString(a, b);
    String_println(a);

    String_appendChar(b, "arco");
    String_println(b);

    printf("%s\n", String_center(b, 20));
    printf("%s\n", String_center(b, 19));
    printf("%s\n", String_centerWithChar(b, 20, "-"));
    printf("%s\n", String_centerWithChar(b, 19, "-"));
    printf("%s\n", String_centerWithChar(b, 20, ""));

    // This line raises an exception:
    // printf("%s\n", String_center_with_char(b, 20, "-+"));

    delete(a), delete(aa), delete(b);
    return 0;
}
