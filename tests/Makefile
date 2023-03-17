# Variables de compilación
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Werror
INCLUDE_DIR = include/

# Variables de archivos de prueba
TEST1_SRCS = src/Object.c src/String.c tests/test1.c
TEST2_SRCS = src/Object.c src/Color.c tests/test2.c
TEST3_SRCS = src/Object.c src/WString.c tests/test3.c

TEST1_BIN = /tmp/test1
TEST2_BIN = /tmp/test2
TEST3_BIN = /tmp/test3

# Reglas de compilación
all: test1 test2 test3

test1: $(TEST1_SRCS)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) $^ -o $(TEST1_BIN)

test2: $(TEST2_SRCS)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) $^ -o $(TEST2_BIN)

test3: $(TEST3_SRCS)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) $^ -o $(TEST3_BIN)

# Reglas de ejecución de pruebas
check: check_test1 check_test2 check_test3

check_test1:
	$(TEST1_BIN)

check_test2:
	$(TEST2_BIN)

check_test3:
	$(TEST3_BIN)

# Reglas de limpieza
clean_tests:
	rm -f $(TEST1_BIN) $(TEST2_BIN) $(TEST3_BIN)
