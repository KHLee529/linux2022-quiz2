.PHONY: average, gcd

all: average gcd

average: average.c
	gcc -O0 -c average.c -o average_O0.o
	gcc -O1 -c average.c -o average_O1.o
	gcc -O2 -c average.c -o average_O2.o
	gcc -O3 -c average.c -o average_O3.o

gcd: gcd.c gcd_test.c
	gcc -O3 $^ -o gcd.out
	./gcd.out
	gnuplot ./scripts/gcd.gp

clean:
	rm -rf *.o *.out *.png *.txt
