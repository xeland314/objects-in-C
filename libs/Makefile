libname = libs/libstring.a

LIBSOURCES = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c, libs/%.o, $(LIBSOURCES))

AR = ar
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = rcs
INCLUDE_DIR = include/

$(OBJS): libs/%.o : src/%.c
	$(CC) -I $(INCLUDE_DIR) -c $(CFLAGS) $< -o $@

lib: $(OBJS)
	$(AR) $(LDFLAGS) $(libname) $(OBJS)

clean_lib:
	rm -f $(OBJS)
