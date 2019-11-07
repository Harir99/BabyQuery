
all: babiesQuery.o babiesQuery babyQuery.o babyQuery

babiesQuery.o: babiesQuery.c
	gcc -Wall -ansi -c babiesQuery.c

babiesQuery: babiesQuery.o removeCommas.o
	gcc -Wall -ansi babiesQuery.o removeCommas.o -o babiesQuery

babyQuery.o: babyQuery.c
	gcc -Wall -ansi -c babyQuery.c

babyQuery: babyQuery.o removeCommas.o
	gcc -Wall -ansi babyQuery.o removeCommas.o -o babyQuery

removeCommas.o:
	gcc -Wall -ansi -removeCommas removeCommas.c
clean:
	rm babiesQuery.o babyQuery.o
