compile: main.c 3-SAT/3-SAT.c
	 gcc main.c 3-SAT/3-SAT.c -o main -lm

run:
	./main

both:
	make compile && make run