exe = test
SOURCES = $(wildcard *.c)

flags =  

$(exe): $(SOURCES)
	gcc $(SOURCES) $(flags) -o $(exe)

again:
	rm $(exe)
	gcc $(SOURCES) $(flags) -o $(exe)

clear:
	rm $(exe)

