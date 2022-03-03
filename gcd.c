#include <stdint.h>
#include "gcd.h"

uint64_t gcd64(uint64_t u, uint64_t v)
{
    if (!u || !v) return u | v;
    int shift;
    for (shift = 0; !((u | v) & 1); shift++) {
        u /= 2, v /= 2;
    }

    while (!(u & 1))
        u /= 2;
    do {
        while (!(v & 1))
            v /= 2;
        if (u < v) {
            v -= u;
        } else {
            uint64_t t = u - v;
            u = v;
            v = t;
        }
    } while (v);
    return u << shift;
}

int min(int a, int b) {
    return a ^ ((a ^ b) & -(a > b));
}

uint64_t gcd64_use_builtin_ctz(uint64_t u, uint64_t v)
{
    if (!u || !v) return u | v;
    int shift, u_tz, v_tz;
    u_tz = __builtin_ctzll(u);    
    v_tz = __builtin_ctzll(v);    
    shift = min(u_tz, v_tz);

    u >>= u_tz;
    v >>= v_tz;

    do {
        v >>= __builtin_ctzll(v);
        if (u < v) {
            v -= u;
        } else {
            uint64_t t = u - v;
            u = v;
            v = t;
        }
    } while (v);
    return u << shift;
}
