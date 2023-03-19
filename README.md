<!-- markdownlint-disable MD033 -->
# Objectos en C

<div align="center">

Basado en el [libro](https://www.freetechbooks.com/object-oriented-programming-with-ansi-c-t551.html#:~:text=Object%2Doriented%20Programming%20with%20Ansi%2DC&text=Uses%20ANSI%2DC%20to%20discover,program%20to%20catch%20mistakes%20earlier.) *Object-oriented Programming with Ansi-C* de Axel-Tobias Schreiner.

</div>

## Encapsulamiento

Se define un *struct* base llamado Class. A partir de este se pueden crear más objetos que hereden los mismos atributos y métodos.

```C
typedef struct {
    size_t size;
    void * (* ctor) (void * self, va_list * app);
    void * (* dtor) (void * self);
    void * (* clone) (const void * self);
    size_t (* sizeOf) (const void * self);
    int (* differ) (const void * self, const void * other);
    char * (* toString) (const void * self);
} Class;
/* Métodos sobrecargados: */
void * new(const void * _class, ...);
void delete(void * self);
void * clone(const void * self);
int differ(const void * self, const void * other);
size_t sizeOf(const void * self);
char * toString(const void * self);
```

## ¿Cómo utilizar este repositorio?

### String

Primero consideremos la forma habitual de inicializar una cadena:

```C
#include <stdlib.h>

int main() {
    char * text = malloc(sizeof(char *) * 16);
    // char text[16];
    strcpy(text, "Hola mundo");
    printf("%s", text);
    return 0;
}
```

Aquí es necesario manejar la memoria de la cadena que vamos a utilizar. En caso de varias, el proceso sería más largo y su mantenimiento sería más difícil en caso de que el programa se haga más grande.

Mientras que utilizando la clase ```String```:

```cpp
#include "String.h"
#include <stdlib.h>

int main() {
    void * text = new(String, "Hola mundo");
    printf("%s", toString(text));
    return 0;
}
```

Ocultando el manejo de memoria en segundo plano.

### Funciones principales de la clase String

<details>
    <summary><b>Constructor</b></summary>

Para evitar esto último, se ha sobrecargado el método ```new()``` para inicializar cualquier objeto. En el caso de un String o cadena:

```C
void * text = new(String, "Hello, world");
```

Esto no da paso a que el código adopte muchas formas distintas para crear una cadena/string. Además que hace más legible y agradable a la vista del programador. Sin embargo, es cierto que detrás de bambalinas es dónde opera la lógica y la gestión de memoria.

</details>

<details>
    <summary><b>Clonador</b></summary>

En caso de necesitar una cadena con el mismo contenido de una pero sin apuntar a la misma dirección de memoria, se utliza:

```C
void * textCopy = clone(text);
```

</details>

<details>
    <summary><b>Destructor</b></summary>

En caso de ya no utilizar el String hacemos uso de la función ```delete()```, que también hemos sobrecargado previamente:

```cpp
delete(text);
```

</details>

<details>
    <summary><b>toString</b></summary>

La función ```toString()``` retorna ```char *``` lo cual nos permite imprimir el contenido del objeto creado sin tener que acceder directamente a ese atributo del*struct*.

```C
printf("text = %s\n", toString(text));
```

</details>

## Ejemplos de uso

Para compilar los ejemplos de uso y ver por consola el resultado, se puede utilizar el comando:

```bash
make examples && make run_examples
```

Todo el código figura en la carpeta ```examples```.

## Tests

Del mismo modo, para verificar la integridad de las funciones implementadas para cada clase,
se puede utilizar el comando:

```bash
make tests && make check
```

Esto ejecutará un conjunto de tests escritos en C con la librería de [acutest.h](https://github.com/mity/acutest).
De esta forma, también se pueden agregar más funcionalidades y testearlas.

### Limpieza

Puedes eliminar todos los archivos compilados con el comando:

```bash
make clean
```
