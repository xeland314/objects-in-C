#include "Color.h"
#include "Object.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    void * blue = new(Color, NORMAL, BLUE, WHITE);
    void * blue2 = clone(blue);
    void * red = new(Color, NORMAL, RED, YELLOW);
    
    printf("sizeOf(a) == %lu\n", sizeOf(blue));
    
    if (differ(blue, red))
        puts("ok");
    
    if (differ(blue, blue2))
        puts("differ?");
    
    if (blue == blue2)
        puts("clone?");

    printf("%sTexto en azul%s\n", toString(blue), NORMAL_STDOUT);
    printf("%sTexto en rojo%s\n", toString(red), NORMAL_STDOUT);
    puts("Texto normal");

    delete(blue), delete(blue2), delete(red);
    return 0;
}
