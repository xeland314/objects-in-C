#include "../include/String.h"
#include "../include/Object.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    void * a = new(String, "Hello, world"), * aa = clone(a);
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

    delete(a), delete(aa), delete(b);
    return 0;
}
