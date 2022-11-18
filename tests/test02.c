#include "../include/Color.h"
#include "../include/Object.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    void * blue = new(Color, BLUE, DARK), * blue2 = clone(blue);
    void * red = new(Color, RED, HIGHLIGHTED);
    
    printf("sizeOf(a) == %lu\n", sizeOf(blue));
    
    if (differ(blue, red))
        puts("ok");
    
    if (differ(blue, blue2))
        puts("differ?");
    
    if (blue == blue2)
        puts("clone?");

    setColor(blue);
    puts("Texto en azul");
    setColor(red);
    puts("Texto en rojo");
    resetColor();
    puts("Texto normal");

    delete(blue), delete(blue2), delete(red);
    return 0;
}
