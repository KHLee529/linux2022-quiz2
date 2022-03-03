#include <stdint.h>

uint32_t average_v1(uint32_t a, uint32_t b) { 
    return (a + b) / 2; 
}

uint32_t average_v2(uint32_t low, uint32_t high) { 
    return low + (high - low) / 2;
}

uint32_t average_v3(uint32_t a, uint32_t b) { 
    return (a >> 1) + (b >> 1) + (a & b & 1);
}

uint32_t average_v4(uint32_t a, uint32_t b) { 
    return (a & b) + ((a ^ b) >> 1);
}

