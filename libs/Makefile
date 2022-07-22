libname = libs/libstring.a

LIBSOURCES = $(wildcard src/*.c)
OBJS = $(wildcard libs/*.o)

libflags = -c -Wall -Werror -Wextra

objs:
	gcc $(libflags) $(LIBSOURCES)
	mv *.o libs

rmobjs:
	rm $(OBJS)

lib:
	ar -rc $(libname) $(OBJS)

rmlib:
	rm $(libname)

