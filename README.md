<div align="center">

# Strings en C

</div>

## Encapsulamiento

En lugar de utilizar ```char *``` para manejar las cadenas de texto,
se define un struct para una sintaxis más amigable:

``` C
typedef struct {
    char * text;
} String;
```

Además, es más fácil retornar variables de tipo struct al programar C en lugar de punteros.

Por otro lado, también definimos:

<details>
<summary> Color.h </summary>

``` C
typedef struct {
    char *color;
char* mode;
} Color;
```

</details>

<details>
<summary>ColoredString.h</summary>

``` C
typedef struct {
    String str;
    Color clr;
} ColoredString;
```

</details>

Todo esto se hace con la finalidad de imprimir por consola textos en diferentes colores.

## Funciones en *String.h*

``` C
void String_init(String * str, const char * text);
void String_setText(String * str, const char * text);
void String_println(String * str);
void String_print(String * str);
void String_delete(String * str);
void String_appendString(String * str, String * otherstr);
void String_appendChar(String * str, const char * text);
void String_capitalize(String * str);
void String_casefold(String * str);
void String_reverse(String * str);
int String_size(String * str);
int String_compare(String* str, String * otherStr);
String String_clone(String * str);
```

Al pasar los strings como punteros no es necesario retornar
algún valor.
