#include "WString.h"
#include "Object.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    void * a = new(WString, L"Hello, world"), * aa = clone(a);
    void * b = new(WString, L"b");
    
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
    
    // Test toWchar()
    printf("wchar_t: %ls\n", toWchar(a));

    delete(a), delete(aa), delete(b);
    return 0;
}
