#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"

int func(unsigned int a){
    int shift;
    for (shift = 0; !(a & 1); shift++)
        a >>= 1;

    return shift;
}

int func1(unsigned int a){
    return __builtin_ctz(a);
}

typedef int (func_f)(unsigned int);

void test(unsigned int (*a_gen)(void), const char *out_fn) {
    unsigned int a;

    const int epochs = 1000;
    int interval = epochs / 10;

    struct timespec start, end;
    func_f *funcs[] = {
        func,
        func1,
    };

    const int sort_len = sizeof(funcs) / sizeof(func_f *);
    time_t measures[epochs][sort_len];

    for (int i = 0; i < epochs; i++)
    {
        a = a_gen();
        for (size_t j = 0; j < sort_len; j++)
        {
            clock_gettime(CLOCK_MONOTONIC, &start);
            funcs[j](a);
            clock_gettime(CLOCK_MONOTONIC, &end);
            measures[i][j] = diff(start, end);
        }

        if ((i + 1) % interval == 0)
            printf("Benchmark %-3d%%\n", 100 * (i + 1) / epochs);
    }

    FILE *file = fopen(out_fn, "w+");
    for (size_t i = 0; i < epochs; i++)
    {
        for (size_t j = 0; j < sort_len; j++)
        {
            char *token = j == sort_len - 1 ? j == epochs - 1 ? "" : "\n" : "\t";
            fprintf(file, "%ld%s", measures[i][j], token);
        }
    }
}

unsigned int r1() {
    return (unsigned int) 1;
}
unsigned int rmax() {
    return (unsigned int) 1 << 31;
}
unsigned int rrand(){
    return (unsigned int) rand();
}

int main(void) {
    srand(time(0));
    printf("RAND_MAX = %d\n", RAND_MAX);
    test(r1, "./txt/1.txt");
    test(rmax, "./txt/0x80000000.txt");
    test(rrand, "./txt/rand.txt");
    return 0;
}
