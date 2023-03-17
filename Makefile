# Incluye los Makefiles de los subdirectorios
include tests/Makefile
include libs/Makefile
include examples/Makefile

# Variables para la compilación
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE_DIR = include/

# Regla para compilar todo el proyecto
all: lib tests examples

# Reglas para limpiar los objetos y ejecutables
clean:
	$(MAKE) -C tests clean_tests
	$(MAKE) -C examples clean_examples
	rm -f $(wildcard libs/*.o)
	rm -f $(wildcard libs/*.a)

.PHONY: all clean distclean
