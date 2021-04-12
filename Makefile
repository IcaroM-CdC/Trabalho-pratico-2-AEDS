compile: main.c FNC_3_SAT/FNC_3_SAT.c
	 gcc main.c FNC_3_SAT/FNC_3_SAT.c -o main -lm

run:
	./main

both:
	make compile && make run