# Tipos de datos / Objetos

## StringType

En lugar de utilizar ```char *``` para manejar las cadenas de texto,
se define un ```struct``` para una sintaxis más amigable:

```C
typedef struct {
    const void * class; /* must be first */
    char * text;        /* dynamic string */
} StringType;
```

Además, es más fácil retornar variables de tipo *struct* al programar C en lugar de punteros.

## ColorType

```C
typedef struct {
    const void * class; /* must be first */
    unsigned int attr;  // mode
    unsigned int fg;    // foreground, text color
    unsigned int bg;    // background color
} ColorType;
```

Todo esto se hace con la finalidad de imprimir por consola textos en diferentes colores.

## WString

En lugar de utilizar ```wchar_t *``` (de la librería ```<wchar.h>```) para manejar las cadenas de texto especiales,
se define un ```struct``` para una sintaxis más amigable:

```C
typedef struct {
    const void * class;
    wchar_t * text;
} WStringType;
```
