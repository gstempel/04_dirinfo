dirTest: dir.c main.c
	gcc -o dirTest main.c dir.c

run: dirTest
	./dirTest

clean:
	rm *~
