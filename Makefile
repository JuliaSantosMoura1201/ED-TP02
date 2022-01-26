all: printy

printy: obj/main.o obj/files.o obj/entity.o obj/quicksort.o
	gcc -o bin/printy obj/main.o obj/files.o obj/entity.o obj/quicksort.o

obj/main.o: src/main.c include/files.h include/entity.h
	gcc -W -Wall -c -I include -o obj/main.o src/main.c

obj/files.o: src/files.c include/files.h include/entity.h
	gcc -W -Wall -c -I include -o obj/files.o src/files.c

obj/entity.o: src/entity.c include/entity.h
	gcc -W -Wall -c -I include -o obj/entity.o src/entity.c

obj/quicksort.o: src/quicksort.c include/quicksort.h
	gcc -W -Wall -c -I include -o obj/quicksort.o src/quicksort.c
