#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "util.h"
#include "gcd.h"

int main() {
    srand(time(0));
    uint64_t u, v;

    const int epochs = 1000;
    int interval = epochs / 10;

    struct timespec start, end;
    gcd_f *gcds[] = {
        gcd64,
        gcd64_use_builtin_ctz,
    };

    const int sort_len = sizeof(gcds) / sizeof(gcd_f *);
    time_t measures[epochs][sort_len];

    for (int i = 0; i < epochs; i++)
    {
        u = ((uint64_t) rand() << 32) | rand();
        v = ((uint64_t) rand() << 32) | rand();
        for (size_t j = 0; j < sort_len; j++)
        {
            clock_gettime(CLOCK_MONOTONIC, &start);
            gcds[j](u, v);
            clock_gettime(CLOCK_MONOTONIC, &end);
            measures[i][j] = diff(start, end);
        }

        if ((i + 1) % interval == 0)
            printf("Benchmark %-3d%%\n", 100 * (i + 1) / epochs);
    }

    FILE *file = fopen("./benchmark.txt", "w+");
    for (size_t i = 0; i < epochs; i++)
    {
        for (size_t j = 0; j < sort_len; j++)
        {
            char *token = j == sort_len - 1 ? j == epochs - 1 ? "" : "\n" : "\t";
            fprintf(file, "%ld%s", measures[i][j], token);
        }
    }
    return 0;
}
