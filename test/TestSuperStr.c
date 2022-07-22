#include "../SuperString.h"

int main() 
{
    SuperStr superString;
    SuperStr_init(&superString, L"Hola, mundo. Ño?");
    SuperStr_println(&superString);
    return 0;
}
