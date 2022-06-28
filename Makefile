exe = /tmp/testString
libstr = libstring.a

SOURCES = $(wildcard *.c)
LIBSOURCES = Color.c ColoredString.c String.c
OBJS = $(wildcard *.o)

flags =  
libflags = -c -Wall -Werror -Wextra

$(exe): $(SOURCES)
	gcc $(SOURCES) $(flags) -o $(exe)

again:
	rm $(exe)
	gcc $(SOURCES) $(flags) -o $(exe)

clear:
	rm $(exe)

execute:
	cd /tmp/ && ./testString

rmobjs:
	rm $(OBJS)

rmlib:
	rm $(libstr)

lib:
	gcc $(libflags) $(LIBSOURCES)
	ar -rc $(libstr) $(OBJS)
	rm $(OBJS)

test_with_lib:
	gcc main.c -L. $(libstr) -o testlib
