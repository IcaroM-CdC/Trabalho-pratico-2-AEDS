compile: main.c functions/functions.c
	 gcc main.c functions/functions.c -o main -lm

run:
	./main

both:
	make compile && make run