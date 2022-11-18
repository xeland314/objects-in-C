test01 = /tmp/test01
test02 = /tmp/test02
test03 = /tmp/test03
currTest := /test01

src1 = src/Object.c src/String.c
src2 = src/Object.c src/Color.c

SOURCES = $(wildcard src/*.c)

test1:
	gcc $(src1) tests/test01.c -o $(test01)

test2:
	gcc $(src2) tests/test02.c -o $(test02)

check_test1:
	cd /tmp/ && ./test01

check_test2:
	cd /tmp/ && ./test02
