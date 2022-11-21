<div align="center">

# Strings en C

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


### Tipos de datos

#### StringType

En lugar de utilizar ```char *``` para manejar las cadenas de texto,
se define un *struct* para una sintaxis más amigable:

```C
typedef struct {
    const void * class; /* must be first */
    char * text;        /* dynamic string */
} StringType;
```

Además, es más fácil retornar variables de tipo *struct* al programar C en lugar de punteros.

Por otro lado, también definimos:

#### ColorType

```C
typedef struct {
    const void * class; /* must be first */
    unsigned int attr;  // mode
    unsigned int fg; 	// foreground, text color
    unsigned int bg;    // background color
} ColorType;
```

Todo esto se hace con la finalidad de imprimir por consola textos en diferentes colores.

## Uso

### String

Primero consideremos la forma habitual de inicializar una cadena:

```C
char * text = malloc(sizeof(char *) * 16);
char text[16];
strcpy(text, "Hola mundo");
```

Aquí es necesario manejar la memoria de la cadena que vamos a utilizar. En caso de varias, el proceso sería más largo y su mantenimiento sería más difícil en caso de que el programa se haga más grande. 

#### Constructor

Para evitar esto último, se ha sobrecargado el método ```new()``` para inicializar cualquier objeto. En el caso de un String o cadena:

```C
void * text = new(String, "Hello, world");
```

Esto no da paso a que el código adopte muchas formas distintas para crear una cadena/string. Además que hace más legible y agradable a la vista del programador. Sin embargo, es cierto que detrás de bambalinas es dónde opera la lógica y la gestión de memoria.

#### Clonador

En caso de necesitar una cadena con el mismo contenido de una pero sin apuntar a la misma dirección de memoria, se utliza:

```C
void * textCopy = clone(text);
```

#### Destructor

En caso de ya no utilizar el String hacemos uso de la función ```delete()```, que también hemos sobrecargado previamente:

```C
delete(text);
```

#### toString

La función ```toString()``` retorna ```char *``` lo cual nos permite imprimir el contenido del objeto creado sin tener que acceder directamente a ese atributo del*struct*.

```C
printf("text = %s\n", toString(text));
```
