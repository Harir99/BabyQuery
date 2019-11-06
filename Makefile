all: babyQuery babiesQuery

babyQuery: babyQuery.c
	gcc -ansi -Wall babyQuery.c -o babyQuery

babiesQuery: babiesQuery.c
	gcc -ansi -Wall babiesQuery.c babiesQuery

clean:
	rm babyQuery babiesQuery
