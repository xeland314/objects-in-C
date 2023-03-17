# Variables para los ejecutables
EXAMPLES = /tmp

# Variables para las fuentes de cada ejemplo
SRC_EXAMPLE1 = src/Object.c src/String.c
SRC_EXAMPLE2 = src/Object.c src/Color.c
SRC_EXAMPLE3 = src/Object.c src/WString.c

# Variable para las fuentes en general
SOURCES = $(wildcard src/*.c)

# Variables para la carpeta de inclusiones
INCLUDE_DIR = include/

# Reglas de compilación
examples: example1 example2 example3

# Reglas para construir los ejecutables
example1: $(SRC_EXAMPLE1) examples/example1.c
	gcc -I $(INCLUDE_DIR) $^ -o $(EXAMPLES)/example01

example2: $(SRC_EXAMPLE2) examples/example2.c
	gcc -I $(INCLUDE_DIR) $^ -o $(EXAMPLES)/example02

example3: $(SRC_EXAMPLE3) examples/example3.c
	gcc -I $(INCLUDE_DIR) $^ -o $(EXAMPLES)/example03

run_examples: run_example1 run_example2 run_example3

# Reglas para ejecutar los ejemplos
run_example1:
	cd $(EXAMPLES) && ./example01

run_example2:
	cd $(EXAMPLES) && ./example02

run_example3:
	cd $(EXAMPLES) && ./example03
	
# Reglas de limpieza
clean_examples:
	rm -f $(EXAMPLES)/example01 $(EXAMPLES)/example02 $(EXAMPLES)/example03
