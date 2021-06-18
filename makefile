all: compile run run2 run3 log log2 log3

compile:
	gcc -Wall -Werror main.c -o main -O3 -lm -fopenmp
run:
	./main <input.in
run2:
	./main <input2.in
run3:
	./main <input3.in
log:
	./main <input.in >output.out
log2:
	./main <input2.in >output2.out
log3:
	./main <input3.in >output3.out
